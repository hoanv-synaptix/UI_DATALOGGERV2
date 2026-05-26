#include "ui_modbus_backend.h"
#include "cJSON.h"
#include <string.h>
#include <stdio.h>

static mbs_command_t s_cmd_list[MBS_MAX_COMMANDS];
static uint16_t s_cmd_count = 0;

/* Dropdown index to Modbus function code mapping.
 * Order MUST match the dropdown in GUI Guider:
 * 0: READ COILS          (FC 1)
 * 1: READ DISCRETE INPUTS(FC 2)
 * 2: READ HOLDING REGS   (FC 3)
 * 3: READ INPUT REGS     (FC 4)
 * 4: WRITE SINGLE COIL   (FC 5)
 * 5: WRITE SINGLE REG    (FC 6)
 * 6: WRITE MULTI COILS   (FC 15)
 * 7: WRITE MULTI REGS    (FC 16)
 */
static const uint8_t s_dd_to_func[] = {1, 2, 3, 4, 5, 6, 15, 16};
#define DD_TO_FUNC_COUNT (sizeof(s_dd_to_func) / sizeof(s_dd_to_func[0]))

static uint16_t calc_next_remap(void) {
    if (s_cmd_count == 0) return MBS_REMAP_START_ADDRESS;
    const mbs_command_t *last = &s_cmd_list[s_cmd_count - 1];
    return last->reg_addr_remap + last->reg_quantity;
}

void ui_modbus_backend_init(void) {
    memset(s_cmd_list, 0, sizeof(s_cmd_list));
    s_cmd_count = 0;
}

bool ui_modbus_backend_add_cmd(uint8_t slave_id, uint8_t func,
                               uint16_t reg_addr, uint16_t reg_quantity) {
    if (s_cmd_count >= MBS_MAX_COMMANDS) return false;
    if (reg_quantity == 0) return false;

    mbs_command_t *cmd = &s_cmd_list[s_cmd_count];
    cmd->id = slave_id;
    cmd->func = func;
    cmd->reg_addr = reg_addr;
    cmd->reg_quantity = reg_quantity;
    cmd->reg_addr_remap = calc_next_remap();

    s_cmd_count++;
    return true;
}

bool ui_modbus_backend_remove_cmd(uint16_t index) {
    if (index >= s_cmd_count) return false;

    /* Shift remaining entries down */
    for (uint16_t i = index; i < s_cmd_count - 1; i++) {
        s_cmd_list[i] = s_cmd_list[i + 1];
    }
    s_cmd_count--;

    /* Recalculate remap addresses for all entries after the removal point */
    for (uint16_t i = index; i < s_cmd_count; i++) {
        if (i == 0) {
            s_cmd_list[i].reg_addr_remap = MBS_REMAP_START_ADDRESS;
        } else {
            const mbs_command_t *prev = &s_cmd_list[i - 1];
            s_cmd_list[i].reg_addr_remap = prev->reg_addr_remap + prev->reg_quantity;
        }
    }

    return true;
}

const mbs_command_t *ui_modbus_backend_get_list(uint16_t *out_count) {
    if (out_count) *out_count = s_cmd_count;
    return s_cmd_list;
}

const char *ui_modbus_backend_func_name(uint8_t func) {
    switch (func) {
        case MB_FUNC_READ_COILS:           return "READ COILS";
        case MB_FUNC_READ_DISCRETE_INPUTS: return "READ DISCRETE INPUTS";
        case MB_FUNC_READ_HOLDING_REGS:    return "READ HOLDING REGS";
        case MB_FUNC_READ_INPUT_REGS:      return "READ INPUT REGS";
        case MB_FUNC_WRITE_SINGLE_COIL:    return "WRITE SINGLE COIL";
        case MB_FUNC_WRITE_SINGLE_REG:     return "WRITE SINGLE REG";
        case MB_FUNC_WRITE_MULTI_COILS:    return "WRITE MULTI COILS";
        case MB_FUNC_WRITE_MULTI_REGS:     return "WRITE MULTI REGS";
        default:                           return "UNKNOWN";
    }
}

uint8_t ui_modbus_backend_dd_index_to_func(uint16_t dd_index) {
    if (dd_index < DD_TO_FUNC_COUNT) return s_dd_to_func[dd_index];
    return 0;
}

char *ui_modbus_backend_to_json(void) {
    cJSON *arr = cJSON_CreateArray();
    if (!arr) return NULL;

    for (uint16_t i = 0; i < s_cmd_count; i++) {
        cJSON *item = cJSON_CreateObject();
        if (!item) { cJSON_Delete(arr); return NULL; }

        cJSON_AddNumberToObject(item, "id", s_cmd_list[i].id);
        cJSON_AddNumberToObject(item, "function", s_cmd_list[i].func);
        cJSON_AddNumberToObject(item, "address", s_cmd_list[i].reg_addr);
        cJSON_AddNumberToObject(item, "quantity", s_cmd_list[i].reg_quantity);
        cJSON_AddNumberToObject(item, "address_remap", s_cmd_list[i].reg_addr_remap);
        cJSON_AddItemToArray(arr, item);
    }

    char *json_str = cJSON_PrintUnformatted(arr);
    cJSON_Delete(arr);
    return json_str;
}
