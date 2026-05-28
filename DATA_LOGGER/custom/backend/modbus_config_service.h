/**
 * @file modbus_config_service.h
 * @brief Dịch vụ quản lý cấu hình danh sách thiết bị Modbus RTU/TCP.
 * 
 * Cung cấp các cấu trúc và hàm để thêm, xóa, quản lý danh sách lệnh Modbus
 * (Polling list) từ giao diện người dùng. Hỗ trợ xuất danh sách này ra chuỗi JSON
 * để gửi xuống phần cứng (Firmware) thực thi.
 */
#ifndef modbus_config_H
#define modbus_config_H
#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>

#include "mbs_command.h"

#define MBS_MAX_COMMANDS 32
#define MBS_REMAP_START_ADDRESS 0

/**
 * @brief Khởi tạo dịch vụ cấu hình Modbus (Xóa sạch danh sách lệnh cũ).
 */
void modbus_config_init(void);

/**
 * @brief Thêm một lệnh Modbus mới vào danh sách.
 * 
 * @param slave_id Địa chỉ Slave thiết bị
 * @param func Mã chức năng Modbus
 * @param reg_addr Địa chỉ thanh ghi bắt đầu
 * @param reg_quantity Số lượng thanh ghi
 * @param reg_addr_remap Địa chỉ lưu trữ cục bộ sau khi đọc về
 * @return true nếu thêm thành công, false nếu danh sách đã đầy (>= MBS_MAX_COMMANDS)
 */
bool modbus_config_add_cmd(uint8_t slave_id, uint8_t func,
                               uint16_t reg_addr, uint16_t reg_quantity, uint16_t reg_addr_remap);

/**
 * @brief Xóa một lệnh Modbus khỏi danh sách dựa vào vị trí Index.
 * 
 * @param index Vị trí của lệnh trong mảng lưu trữ
 * @return true nếu xóa thành công
 */
bool modbus_config_remove_cmd(uint16_t index);

/**
 * @brief Lấy con trỏ đến mảng chứa danh sách lệnh Modbus hiện tại.
 * 
 * @param out_count Con trỏ chứa số lượng lệnh hiện có (Output parameter)
 * @return Con trỏ đến mảng `MBS_Command_t`
 */
const MBS_Command_t *modbus_config_get_list(uint16_t *out_count);

/**
 * @brief Lấy tên chức năng dạng chuỗi (String) từ mã Function Code.
 * @param func Mã chức năng
 * @return Chuỗi mô tả (VD: "Read Holding Registers")
 */
const char *modbus_config_func_name(uint8_t func);

/**
 * @brief Đóng gói toàn bộ danh sách lệnh thành chuỗi JSON.
 * @note Trách nhiệm giải phóng vùng nhớ bằng `cJSON_free()` thuộc về người gọi hàm này.
 * @return Chuỗi JSON được cấp phát động, hoặc NULL nếu thất bại.
 */
char *modbus_config_to_json(void);

/**
 * @brief Đóng gói danh sách lệnh thành chuỗi JSON và gọi ui_pub đẩy xuống Firmware.
 * @return true nếu gửi thành công.
 */
bool modbus_config_sync_to_firmware(void);

/**
 * @brief Chuyển đổi chỉ số mục được chọn trên UI Dropdown thành mã Modbus Function.
 * @param dd_index Vị trí index trên Dropdown
 * @return Mã Modbus Function tương ứng
 */
uint8_t modbus_config_dd_index_to_func(uint16_t dd_index);

#ifdef __cplusplus
}
#endif

#endif /* modbus_config_H */
