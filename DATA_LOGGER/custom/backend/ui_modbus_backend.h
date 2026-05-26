#ifndef UI_MODBUS_BACKEND_H
#define UI_MODBUS_BACKEND_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>

#define MBS_MAX_COMMANDS 32
#define MBS_REMAP_START_ADDRESS 0

typedef enum {
    MB_FUNC_READ_COILS              = 1,
    MB_FUNC_READ_DISCRETE_INPUTS    = 2,
    MB_FUNC_READ_HOLDING_REGS       = 3,
    MB_FUNC_READ_INPUT_REGS         = 4,
    MB_FUNC_WRITE_SINGLE_COIL       = 5,
    MB_FUNC_WRITE_SINGLE_REG        = 6,
    MB_FUNC_WRITE_MULTI_COILS       = 15,
    MB_FUNC_WRITE_MULTI_REGS        = 16
} mbs_function_t;

typedef struct {
    uint8_t         id;
    uint8_t         func;
    uint16_t        reg_addr;
    uint16_t        reg_quantity;
    uint16_t        reg_addr_remap;
} mbs_command_t;

/* Initialize the backend (clears command list) */
void ui_modbus_backend_init(void);

/* Add a new command. Returns true on success, false if full. */
bool ui_modbus_backend_add_cmd(uint8_t slave_id, uint8_t func,
                               uint16_t reg_addr, uint16_t reg_quantity);

/* Remove a command by index. Returns true on success. */
bool ui_modbus_backend_remove_cmd(uint16_t index);

/* Get the current command list and count */
const mbs_command_t *ui_modbus_backend_get_list(uint16_t *out_count);

/* Get the function name string from function code */
const char *ui_modbus_backend_func_name(uint8_t func);

/* Serialize the current command list to a JSON string (caller must free with cJSON_free) */
char *ui_modbus_backend_to_json(void);

/* Convert dropdown selection index to Modbus function code */
uint8_t ui_modbus_backend_dd_index_to_func(uint16_t dd_index);

#ifdef __cplusplus
}
#endif

#endif /* UI_MODBUS_BACKEND_H */
