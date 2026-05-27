#ifndef __UI_CONTEXT_H_
#define __UI_CONTEXT_H_

#include <stdbool.h>
#include <stddef.h>
#include "lvgl.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct ui_context ui_context_t;

typedef enum {
    UI_TEXTAREA_WIFI_SSID = 0,
    UI_TEXTAREA_WIFI_PASS,
    UI_TEXTAREA_WIFI_IP,
    UI_TEXTAREA_WIFI_SUBNET,
    UI_TEXTAREA_WIFI_GATEWAY,
    UI_TEXTAREA_ETHERNET_IP,
    UI_TEXTAREA_ETHERNET_SUBNET,
    UI_TEXTAREA_ETHERNET_GATEWAY,
    UI_TEXTAREA_LTE_APN,
    UI_TEXTAREA_LTE_USERNAME,
    UI_TEXTAREA_LTE_PASS,
    UI_TEXTAREA_LTE_PIN_CODE,
    UI_TEXTAREA_MQTT_HOST,
    UI_TEXTAREA_MQTT_PORT,
    UI_TEXTAREA_MQTT_USER,
    UI_TEXTAREA_MQTT_PASS,
    UI_TEXTAREA_SLAVE_ID,
    UI_TEXTAREA_MASTER_DEVICE_NAME,
    UI_TEXTAREA_MASTER_DEVICE_SLAVEID,
    UI_TEXTAREA_MASTER_DEVICE_ADDRESS,
    UI_TEXTAREA_MASTER_DEVICE_QUANTITY,
    UI_TEXTAREA_MASTER_DEVICE_REMAP,
    UI_TEXTAREA_LOGIN_USER,
    UI_TEXTAREA_LOGIN_PASS,
    UI_TEXTAREA_SECURE_SETTINGS_PASS,
    UI_TEXTAREA_COUNT
} ui_textarea_id_t;

typedef enum {
    UI_INPUT_GROUP_DEFAULT = 0,
    UI_INPUT_GROUP_WIFI_STATIC,
    UI_INPUT_GROUP_ETHERNET_STATIC
} ui_input_group_t;

typedef struct {
    lv_obj_t *base_screen;
    lv_obj_t *booting_screen;
    lv_obj_t *keyboard;
    lv_obj_t *btn_dashboard;
    lv_obj_t *btn_analysis;
    lv_obj_t *btn_event_logs;
    lv_obj_t *btn_settings;
} ui_shell_refs_t;

typedef struct {
    lv_obj_t *cont_dashboard;
    lv_obj_t *cont_analysis;
    lv_obj_t *cont_event_logs;
    lv_obj_t *cont_hw;
} ui_main_view_refs_t;

typedef struct {
    lv_obj_t *logs_container;
    lv_obj_t *critical_logs_label;
    lv_obj_t *clear_history_button;
} ui_logs_refs_t;

typedef struct {
    lv_obj_t *cont_menu;
    lv_obj_t *cont_network_config;
    lv_obj_t *cont_mqtt_config;
    lv_obj_t *cont_modbus_config;
    lv_obj_t *cont_system_admin;
    lv_obj_t *btn_net;
    lv_obj_t *btn_mqtt;
    lv_obj_t *btn_modbus;
    lv_obj_t *btn_sys_admin;
    lv_obj_t *btn_net_back;
    lv_obj_t *btn_mqtt_back;
    lv_obj_t *btn_modbus_back;
    lv_obj_t *btn_sys_back;
} ui_settings_nav_refs_t;

typedef struct {
    lv_obj_t *cont_wifi;
    lv_obj_t *cont_ethernet;
    lv_obj_t *cont_lte;
    lv_obj_t *btn_wifi_apply;
    lv_obj_t *btn_ethernet_apply;
    lv_obj_t *btn_lte_apply;
    lv_obj_t *ddlist_net_option;
    lv_obj_t *ddlist_wifi_mode;
    lv_obj_t *ddlist_ethernet_mode;
    lv_obj_t *label_wifi_ip;
    lv_obj_t *label_wifi_status;
    lv_obj_t *label_ethernet_ip;
    lv_obj_t *label_ethernet_subnet;
    lv_obj_t *label_ethernet_gateway;
    lv_obj_t *label_ethernet_status;
} ui_network_refs_t;

typedef struct {
    lv_obj_t *cont_mqtt_config;
    lv_obj_t *cont_mqtt_form;
} ui_mqtt_refs_t;

typedef struct {
    lv_obj_t *cont_modbus_config;
    lv_obj_t *cont_master;
    lv_obj_t *cont_slave;
    lv_obj_t *cont_device_config;
    lv_obj_t *cont_device_viewlist;
    lv_obj_t *cont_master_device_form;
    lv_obj_t *ddlist_modbus_mode;
    lv_obj_t *btn_master_adddevice;
    lv_obj_t *btn_master_viewlist;
    lv_obj_t *btn_master_device_apply;
    lv_obj_t *btn_deviceconfig_back;
    lv_obj_t *btn_devicelist_back;
} ui_modbus_refs_t;

typedef struct {
    lv_obj_t *cont_system_admin;
    lv_obj_t *cont_restart;
    lv_obj_t *cont_restore;
    lv_obj_t *btn_restart;
    lv_obj_t *btn_restart_cancel;
    lv_obj_t *btn_restart_confirm;
    lv_obj_t *btn_restore_confirm;
    lv_obj_t *btn_restore_cancel;
    lv_obj_t *btn_restart_system;
    lv_obj_t *btn_factory_reset;
    lv_obj_t *btn_generate_report;
} ui_system_refs_t;

typedef struct {
    lv_obj_t *cont_booting_login;
    lv_obj_t *btn_login_booting_confirm;
    lv_obj_t *btn_login_booting_cancel;
    lv_obj_t *lbl_login_booting_status;
    lv_obj_t *cont_login_settings;
    lv_obj_t *btn_login_settings_confirm;
    lv_obj_t *btn_login_settings_cancel;
    lv_obj_t *lbl_status_login_setting;
} ui_login_refs_t;

typedef struct {
    lv_obj_t *cont_generate_report;
    lv_obj_t *btn_generate_report_confirm;
    lv_obj_t *btn_generate_report_cancel;
} ui_report_refs_t;

ui_context_t *ui_context_get(void);
void ui_context_bootstrap(void);
void ui_context_show_booting(ui_context_t *ui);

void ui_context_get_shell_refs(ui_context_t *ui, ui_shell_refs_t *out);
void ui_context_get_main_view_refs(ui_context_t *ui, ui_main_view_refs_t *out);
void ui_context_get_logs_refs(ui_context_t *ui, ui_logs_refs_t *out);
void ui_context_get_settings_nav_refs(ui_context_t *ui, ui_settings_nav_refs_t *out);
void ui_context_get_network_refs(ui_context_t *ui, ui_network_refs_t *out);
void ui_context_get_mqtt_refs(ui_context_t *ui, ui_mqtt_refs_t *out);
void ui_context_get_modbus_refs(ui_context_t *ui, ui_modbus_refs_t *out);
void ui_context_get_system_refs(ui_context_t *ui, ui_system_refs_t *out);
void ui_context_get_login_refs(ui_context_t *ui, ui_login_refs_t *out);
void ui_context_get_report_refs(ui_context_t *ui, ui_report_refs_t *out);

lv_obj_t *ui_context_get_base_screen(ui_context_t *ui);
lv_obj_t *ui_context_get_keyboard(ui_context_t *ui);
lv_obj_t *ui_context_get_textarea(ui_context_t *ui, ui_textarea_id_t id);
size_t ui_context_textarea_count(void);
lv_obj_t *ui_context_resolve_textarea_container(ui_context_t *ui, lv_obj_t *ta);
ui_input_group_t ui_context_classify_input(ui_context_t *ui, lv_obj_t *obj);

#ifdef __cplusplus
}
#endif

#endif
