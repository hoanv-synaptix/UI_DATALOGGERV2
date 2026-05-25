#ifndef __UI_PLATFORM_PORT_H_
#define __UI_PLATFORM_PORT_H_

#include <stdbool.h>
#include <stddef.h>
#include "ui_register_types.h"
#include "ui_state.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Platform seam for UI runtime services.
 * Keep chip / BSP specific integrations behind this header so
 * handwritten UI logic stays portable across ESP32-P4, STM32H7, etc.
 */

#define UI_PLATFORM_FIELD_SMALL_MAX 32U
#define UI_PLATFORM_FIELD_MEDIUM_MAX 64U
#define UI_PLATFORM_FIELD_LARGE_MAX 96U

typedef enum {
    UI_PLATFORM_CMD_NONE = 0,
    UI_PLATFORM_CMD_GENERATE_REPORT,
    UI_PLATFORM_CMD_SAVE_WIFI_CONFIG,
    UI_PLATFORM_CMD_SAVE_ETHERNET_CONFIG,
    UI_PLATFORM_CMD_SAVE_LTE_CONFIG,
    UI_PLATFORM_CMD_SAVE_MODBUS_DEVICE,
    UI_PLATFORM_CMD_REQUEST_RESTART,
    UI_PLATFORM_CMD_REQUEST_FACTORY_RESET
} ui_platform_command_id_t;

typedef struct {
    ui_ip_mode_t ip_mode;
    char ssid[UI_PLATFORM_FIELD_MEDIUM_MAX];
    char password[UI_PLATFORM_FIELD_MEDIUM_MAX];
    char ip[UI_PLATFORM_FIELD_SMALL_MAX];
} ui_platform_wifi_config_t;

typedef struct {
    ui_ip_mode_t ip_mode;
    char ip[UI_PLATFORM_FIELD_SMALL_MAX];
    char subnet[UI_PLATFORM_FIELD_SMALL_MAX];
    char gateway[UI_PLATFORM_FIELD_SMALL_MAX];
} ui_platform_ethernet_config_t;

typedef struct {
    char apn[UI_PLATFORM_FIELD_MEDIUM_MAX];
    char username[UI_PLATFORM_FIELD_MEDIUM_MAX];
    char password[UI_PLATFORM_FIELD_MEDIUM_MAX];
    char pin_code[UI_PLATFORM_FIELD_SMALL_MAX];
} ui_platform_lte_config_t;

typedef struct {
    ui_modbus_role_t role;
    char slave_id[UI_PLATFORM_FIELD_SMALL_MAX];
    char device_name[UI_PLATFORM_FIELD_MEDIUM_MAX];
    char device_slave_id[UI_PLATFORM_FIELD_SMALL_MAX];
    char device_address[UI_PLATFORM_FIELD_SMALL_MAX];
    char device_length[UI_PLATFORM_FIELD_SMALL_MAX];
} ui_platform_modbus_device_t;

typedef struct {
    ui_platform_command_id_t id;
    union {
        ui_platform_wifi_config_t wifi;
        ui_platform_ethernet_config_t ethernet;
        ui_platform_lte_config_t lte;
        ui_platform_modbus_device_t modbus_device;
    } data;
} ui_platform_command_t;

typedef bool (*ui_platform_state_loader_t)(ui_runtime_state_t *state, void *user_ctx);
typedef bool (*ui_platform_command_handler_t)(const ui_platform_command_t *cmd, void *user_ctx);
typedef bool (*ui_platform_register_writer_t)(const ui_register_write_t *writes,
                                              size_t count,
                                              void *user_ctx);

void ui_platform_port_init(void);
void ui_platform_port_set_state_loader(ui_platform_state_loader_t loader, void *user_ctx);
bool ui_platform_port_load_initial_state(ui_runtime_state_t *state);
void ui_platform_port_set_command_handler(ui_platform_command_handler_t handler, void *user_ctx);
bool ui_platform_port_submit_command(const ui_platform_command_t *cmd);
void ui_platform_port_set_register_writer(ui_platform_register_writer_t writer, void *user_ctx);
bool ui_platform_port_submit_register_writes(const ui_register_write_t *writes, size_t count);

#ifdef __cplusplus
}
#endif

#endif
