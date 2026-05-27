#ifndef __UI_STATE_H_
#define __UI_STATE_H_

#include <stdbool.h>
#include <stdint.h>
#include "ui_context.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    UI_MAIN_VIEW_LOGIN = 0,
    UI_MAIN_VIEW_DASHBOARD,
    UI_MAIN_VIEW_ANALYSIS,
    UI_MAIN_VIEW_EVENT_LOGS,
    UI_MAIN_VIEW_SETTINGS
} ui_main_view_t;

typedef enum {
    UI_SETTINGS_VIEW_MENU = 0,
    UI_SETTINGS_VIEW_NET,
    UI_SETTINGS_VIEW_MQTT,
    UI_SETTINGS_VIEW_MODBUS,
    UI_SETTINGS_VIEW_SYS_ADMIN
} ui_settings_view_t;

typedef enum {
    UI_DIALOG_NONE = 0,
    UI_DIALOG_RESTART,
    UI_DIALOG_RESTORE,
    UI_DIALOG_SECURE_SETTINGS,
    UI_DIALOG_GENERATE_REPORT
} ui_dialog_t;

typedef enum {
    UI_NET_TRANSPORT_ETHERNET = 0,
    UI_NET_TRANSPORT_WIFI,
    UI_NET_TRANSPORT_LTE
} ui_net_transport_t;

typedef enum {
    UI_IP_MODE_DHCP = 0,
    UI_IP_MODE_STATIC
} ui_ip_mode_t;

typedef enum {
    UI_MODBUS_ROLE_MASTER = 0,
    UI_MODBUS_ROLE_SLAVE
} ui_modbus_role_t;

typedef enum {
    UI_MODBUS_OVERLAY_NONE = 0,
    UI_MODBUS_OVERLAY_DEVICE_CONFIG,
    UI_MODBUS_OVERLAY_DEVICE_VIEWLIST
} ui_modbus_overlay_t;

typedef enum {
    UI_CONNECTION_STATUS_DISCONNECTED = 0,
    UI_CONNECTION_STATUS_CONNECTING,
    UI_CONNECTION_STATUS_CONNECTED,
    UI_CONNECTION_STATUS_ERROR
} ui_connection_status_t;

typedef struct {
    char wifi_live_ip[32];
    bool wifi_connected;
    ui_connection_status_t wifi_status;
} ui_live_state_t;

typedef struct {
    ui_main_view_t main_view;
    ui_settings_view_t settings_view;
    ui_dialog_t dialog;
    ui_net_transport_t net_transport;
    ui_ip_mode_t wifi_mode;
    ui_ip_mode_t ethernet_mode;
    ui_modbus_role_t modbus_role;
    ui_modbus_overlay_t modbus_overlay;
    ui_main_view_t dialog_return_main_view;
    ui_settings_view_t dialog_return_settings_view;
    ui_live_state_t live;
} ui_runtime_state_t;

typedef enum {
    UI_ACTION_SHOW_DASHBOARD = 0,
    UI_ACTION_SHOW_ANALYSIS,
    UI_ACTION_SHOW_EVENT_LOGS,
    UI_ACTION_SHOW_SETTINGS_MENU,
    UI_ACTION_SHOW_SETTINGS_NET,
    UI_ACTION_SHOW_SETTINGS_MQTT,
    UI_ACTION_SHOW_SETTINGS_MODBUS,
    UI_ACTION_SHOW_SETTINGS_SYS_ADMIN,
    UI_ACTION_BACK_TO_SETTINGS_MENU,
    UI_ACTION_SHOW_RESTART_DIALOG,
    UI_ACTION_SHOW_RESTORE_DIALOG,
    UI_ACTION_CANCEL_DIALOG,
    UI_ACTION_CONFIRM_RESTART,
    UI_ACTION_CONFIRM_RESTORE,
    UI_ACTION_SET_NET_TRANSPORT,
    UI_ACTION_SET_WIFI_MODE,
    UI_ACTION_SET_ETHERNET_MODE,
    UI_ACTION_SET_MODBUS_ROLE,
    UI_ACTION_SHOW_MODBUS_DEVICE_CONFIG,
    UI_ACTION_SHOW_MODBUS_DEVICE_VIEWLIST,
    UI_ACTION_APPLY_MODBUS_DEVICE,
    UI_ACTION_BACK_TO_MODBUS,
    UI_ACTION_SUBMIT_GENERATE_REPORT,
    UI_ACTION_CANCEL_GENERATE_REPORT,
    UI_ACTION_SHOW_GENERATE_REPORT,
    UI_ACTION_SUBMIT_WIFI_CONFIG,
    UI_ACTION_SUBMIT_ETHERNET_CONFIG,
    UI_ACTION_SUBMIT_LTE_CONFIG,
    UI_ACTION_SHOW_SECURE_SETTINGS,
    UI_ACTION_SUBMIT_SECURE_SETTINGS,
    UI_ACTION_CANCEL_SECURE_SETTINGS,
    UI_ACTION_SUBMIT_LOGIN,
    UI_ACTION_CANCEL_LOGIN
} ui_action_t;

typedef enum {
    UI_ACTION_EFFECT_NONE = 0,
    UI_ACTION_EFFECT_SUBMIT_GENERATE_REPORT,
    UI_ACTION_EFFECT_SUBMIT_WIFI_CONFIG,
    UI_ACTION_EFFECT_SUBMIT_ETHERNET_CONFIG,
    UI_ACTION_EFFECT_SUBMIT_LTE_CONFIG,
    UI_ACTION_EFFECT_SUBMIT_MODBUS_DEVICE,
    UI_ACTION_EFFECT_LOGIN_SUCCESS,
    UI_ACTION_EFFECT_SECURE_SETTINGS_SUCCESS,
    UI_ACTION_EFFECT_REQUEST_RESTART,
    UI_ACTION_EFFECT_REQUEST_FACTORY_RESET
} ui_action_effect_t;

void ui_state_init_defaults(ui_runtime_state_t *state);
void ui_state_apply_controls(ui_context_t *ui, const ui_runtime_state_t *state);
ui_action_effect_t ui_state_dispatch(ui_runtime_state_t *state, ui_action_t action, uint16_t value);
void ui_state_render(ui_context_t *ui, const ui_runtime_state_t *state);

#ifdef __cplusplus
}
#endif

#endif
