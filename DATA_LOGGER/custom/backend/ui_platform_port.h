#ifndef __UI_PLATFORM_PORT_H_
#define __UI_PLATFORM_PORT_H_

#include <stdbool.h>
#include <stddef.h>
#include "ui_state.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Platform seam for UI runtime services.
 * Keep chip / BSP specific integrations behind this header so
 * handwritten UI logic stays portable across ESP32-P4, STM32H7, etc.
 */

typedef enum {
    UI_PLATFORM_TOPIC_WIFI_CONFIG,
    UI_PLATFORM_TOPIC_ETHERNET_CONFIG,
    UI_PLATFORM_TOPIC_LTE_CONFIG,
    UI_PLATFORM_TOPIC_MODBUS_CONFIG,
    UI_PLATFORM_TOPIC_SYSTEM_CONTROL
} ui_platform_topic_t;

typedef bool (*ui_platform_state_loader_t)(ui_runtime_state_t *state, void *user_ctx);
typedef bool (*ui_platform_json_handler_t)(ui_platform_topic_t topic, const char *json_payload, void *user_ctx);

void ui_platform_port_init(void);
void ui_platform_port_set_state_loader(ui_platform_state_loader_t loader, void *user_ctx);
bool ui_platform_port_load_initial_state(ui_runtime_state_t *state);
void ui_platform_port_set_json_handler(ui_platform_json_handler_t handler, void *user_ctx);
bool ui_platform_port_submit_json(ui_platform_topic_t topic, const char *json_payload);

#ifdef __cplusplus
}
#endif

#endif
