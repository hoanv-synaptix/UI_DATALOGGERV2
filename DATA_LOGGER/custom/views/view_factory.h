/**
 * @file view_factory.h
 * @brief Tầng View Factory (Cung cấp các đối tượng giao diện).
 *
 * Nhiệm vụ: Đóng gói toàn bộ các widget LVGL do GUI Guider sinh ra.
 * Tầng Logic (State/Controller) chỉ cần gọi View Factory để lấy các nút bấm, ô nhập liệu
 * mà không cần phải gọi trực tiếp vào guider_ui (Tránh phụ thuộc cứng).
 */
#ifndef __VIEW_FACTORY_H_
#define __VIEW_FACTORY_H_

#include <stdbool.h>
#include <stddef.h>
#include "lvgl.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct ui_context view_factory_t;

/**
 * @brief Danh sách ID định danh cho tất cả các Ô nhập liệu (Text Area) có trên ứng dụng
 */
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
    lv_obj_t *label_lte_status;
} ui_network_refs_t;

typedef struct {
    lv_obj_t *cont_mqtt_config;
    lv_obj_t *cont_mqtt_form;
    lv_obj_t *btn_mqtt_apply;
    lv_obj_t *label_mqtt_status;
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
    lv_obj_t *btn_modbus_apply;
    lv_obj_t *btn_deviceconfig_back;
    lv_obj_t *btn_devicelist_back;
    lv_obj_t *label_modbus_status;
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

/**
 * @brief Lấy đối tượng View Factory (Singleton pattern)
 */
view_factory_t *view_factory_get(void);

/**
 * @brief Khởi tạo lần đầu cho toàn bộ View
 */
void view_factory_bootstrap(void);

/**
 * @brief Hiện màn hình Booting (Khởi động)
 */
void view_factory_show_booting(view_factory_t *ui);

// --- Các hàm trích xuất nhóm tham chiếu UI (References) ---
void view_factory_get_shell_refs(view_factory_t *ui, ui_shell_refs_t *out);
void view_factory_get_main_view_refs(view_factory_t *ui, ui_main_view_refs_t *out);
void view_factory_get_logs_refs(view_factory_t *ui, ui_logs_refs_t *out);
void view_factory_get_settings_nav_refs(view_factory_t *ui, ui_settings_nav_refs_t *out);
void view_factory_get_network_refs(view_factory_t *ui, ui_network_refs_t *out);
void view_factory_get_mqtt_refs(view_factory_t *ui, ui_mqtt_refs_t *out);
void view_factory_get_modbus_refs(view_factory_t *ui, ui_modbus_refs_t *out);
void view_factory_get_system_refs(view_factory_t *ui, ui_system_refs_t *out);
void view_factory_get_login_refs(view_factory_t *ui, ui_login_refs_t *out);
void view_factory_get_report_refs(view_factory_t *ui, ui_report_refs_t *out);

// --- Trích xuất tài nguyên dùng chung ---
lv_obj_t *view_factory_get_base_screen(view_factory_t *ui);
lv_obj_t *view_factory_get_keyboard(view_factory_t *ui);

// --- Quản lý các ô nhập liệu (Text Area) ---
lv_obj_t *view_factory_get_textarea(view_factory_t *ui, ui_textarea_id_t id);
size_t view_factory_textarea_count(void);
lv_obj_t *view_factory_resolve_textarea_container(view_factory_t *ui, lv_obj_t *ta);
ui_input_group_t view_factory_classify_input(view_factory_t *ui, lv_obj_t *obj);

#ifdef __cplusplus
}
#endif

#endif
