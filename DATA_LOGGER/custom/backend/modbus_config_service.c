#include "modbus_config_service.h"
#include "cJSON.h"
#include <string.h>
#include <stdio.h>
#include "ui_pub.h"

static MBS_Command_t s_cmd_list[MBS_MAX_COMMANDS]; /**< Mảng tĩnh lưu trữ danh sách các lệnh Modbus */
static uint16_t s_cmd_count = 0;                   /**< Số lượng lệnh hiện tại đang có trong danh sách */

/**
 * @brief Bản đồ ánh xạ từ vị trí trên giao diện (Dropdown index) sang mã lệnh Modbus chuẩn.
 * Chú ý: Thứ tự này BẮT BUỘC phải khớp chính xác với thứ tự các lựa chọn trong công cụ GUI Guider:
 * 0: READ COILS          (FC 1)
 * 1: READ DISCRETE INPUTS(FC 2)
 * 2: READ HOLDING REGS   (FC 3)
 * 3: READ INPUT REGS     (FC 4)
 * 4: WRITE SINGLE COIL   (FC 5)
 * 5: WRITE SINGLE REG    (FC 6)
 * 6: WRITE MULTI COILS   (FC 15)
 * 7: WRITE MULTI REGS    (FC 16)
 */
static const uint8_t s_dd_to_func[] = {
    READ_COIL_REG,
    READ_DISCRETE_REG,
    READ_MULTI_HODING_REG,
    READ_INPUT_REG,
    WRITE_SINGLE_COIL_REG,
    WRITE_SINGLE_REG,
    WRITE_MULTI_COIL_REG,
    WRITE_MULTI_REG
};
#define DD_TO_FUNC_COUNT (sizeof(s_dd_to_func) / sizeof(s_dd_to_func[0]))

void modbus_config_init(void) {
    // Xóa sạch bộ nhớ danh sách lệnh cũ khi khởi tạo lại dịch vụ
    memset(s_cmd_list, 0, sizeof(s_cmd_list));
    s_cmd_count = 0;
}

bool modbus_config_add_cmd(uint8_t slave_id, uint8_t func,
                               uint16_t reg_addr, uint16_t reg_quantity, uint16_t reg_addr_remap) {
    // Kiểm tra giới hạn mảng để chống tràn bộ đệm (Buffer Overflow)
    if (s_cmd_count >= MBS_MAX_COMMANDS) return false;
    
    // Một lệnh Modbus không thể có số lượng thanh ghi = 0
    if (reg_quantity == 0) return false;

    // Ghi lệnh mới vào phần tử cuối cùng của mảng
    MBS_Command_t *cmd = &s_cmd_list[s_cmd_count];
    cmd->id = slave_id;
    cmd->func = func;
    cmd->reg_addr = reg_addr;
    cmd->reg_quantity = reg_quantity;
    cmd->reg_addr_remap = reg_addr_remap;

    s_cmd_count++;
    return true;
}

bool modbus_config_remove_cmd(uint16_t index) {
    // Bảo vệ logic: không cho phép xóa ngoài phạm vi mảng hiện hành
    if (index >= s_cmd_count) return false;

    /* Dịch chuyển tất cả các phần tử phía sau lên trước 1 vị trí để lấp chỗ trống.
     * Cách làm này giữ nguyên thứ tự các lệnh đã được cấu hình trước đó.
     */
    for (uint16_t i = index; i < s_cmd_count - 1; i++) {
        s_cmd_list[i] = s_cmd_list[i + 1];
    }
    s_cmd_count--;

    return true;
}

const MBS_Command_t *modbus_config_get_list(uint16_t *out_count) {
    if (out_count) *out_count = s_cmd_count;
    return s_cmd_list;
}

const char *modbus_config_func_name(uint8_t func) {
    switch (func) {
        case READ_COIL_REG:           return "READ COILS";
        case READ_DISCRETE_REG:       return "READ DISCRETE INPUTS";
        case READ_MULTI_HODING_REG:   return "READ HOLDING REGS";
        case READ_INPUT_REG:          return "READ INPUT REGS";
        case WRITE_SINGLE_COIL_REG:   return "WRITE SINGLE COIL";
        case WRITE_SINGLE_REG:        return "WRITE SINGLE REG";
        case WRITE_MULTI_COIL_REG:    return "WRITE MULTI COILS";
        case WRITE_MULTI_REG:         return "WRITE MULTI REGS";
        default:                      return "UNKNOWN";
    }
}

uint8_t modbus_config_dd_index_to_func(uint16_t dd_index) {
    if (dd_index < DD_TO_FUNC_COUNT) return s_dd_to_func[dd_index];
    return 0;
}

char *modbus_config_to_json(void) {
    // Tạo cấu trúc mảng JSON rỗng
    cJSON *arr = cJSON_CreateArray();
    if (!arr) return NULL;

    // Duyệt qua toàn bộ danh sách lệnh và đóng gói từng lệnh thành 1 Object JSON
    for (uint16_t i = 0; i < s_cmd_count; i++) {
        cJSON *item = cJSON_CreateObject();
        if (!item) { 
            cJSON_Delete(arr); // Dọn dẹp bộ nhớ nếu cấp phát thất bại
            return NULL; 
        }

        // Định nghĩa format dữ liệu chuẩn: id, function, address, quantity, address_remap
        cJSON_AddNumberToObject(item, "id", s_cmd_list[i].id);
        cJSON_AddNumberToObject(item, "function", s_cmd_list[i].func);
        cJSON_AddNumberToObject(item, "address", s_cmd_list[i].reg_addr);
        cJSON_AddNumberToObject(item, "quantity", s_cmd_list[i].reg_quantity);
        cJSON_AddNumberToObject(item, "address_remap", s_cmd_list[i].reg_addr_remap);
        
        cJSON_AddItemToArray(arr, item);
    }

    // Kết xuất mảng cJSON ra chuỗi string không chứa ký tự xuống dòng (Unformatted) để tiết kiệm băng thông
    char *json_str = cJSON_PrintUnformatted(arr);
    
    // Xóa object cJSON khỏi RAM, chuỗi json_str lúc này là độc lập và sẽ được giải phóng bởi người gọi hàm
    cJSON_Delete(arr);
    return json_str;
}

bool modbus_config_sync_to_firmware(void) {
    bool ret = false;
    char *json = modbus_config_to_json();
    if (json) {
        ret = ui_pub_submit_json(PUB_TOPIC_MODBUS, json);
        cJSON_free(json);
    }
    return ret;
}
