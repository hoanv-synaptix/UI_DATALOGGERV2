/**
 * @file app_state.h
 * @brief Định nghĩa toàn bộ trạng thái (State Machine) của ứng dụng UI.
 * 
 * Mô hình được thiết kế theo kiến trúc Flux/Redux một chiều:
 * 1. UI phát ra sự kiện (Action)
 * 2. Hàm `ui_state_dispatch` thay đổi State
 * 3. Hàm `ui_state_render` vẽ lại toàn bộ giao diện dựa trên State mới.
 */
#ifndef __APP_STATE_H_
#define __APP_STATE_H_

#include <stdbool.h>
#include <stdint.h>
#include "view_factory.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @enum ui_main_view_t
 * @brief Các tab chính của ứng dụng ở thanh điều hướng bên trái (Sidebar)
 */
typedef enum {
    UI_MAIN_VIEW_LOGIN = 0,    /**< Màn hình đăng nhập */
    UI_MAIN_VIEW_DASHBOARD,    /**< Tab Tổng quan (Dashboard) */
    UI_MAIN_VIEW_ANALYSIS,     /**< Tab Phân tích dữ liệu (Biểu đồ) */
    UI_MAIN_VIEW_EVENT_LOGS,   /**< Tab Lịch sử sự kiện (Event Logs) */
    UI_MAIN_VIEW_SETTINGS      /**< Tab Cài đặt (Settings) */
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
    UI_CONNECTION_STATUS_IDLE = 0,
    UI_CONNECTION_STATUS_DISCONNECTED,
    UI_CONNECTION_STATUS_CONNECTING,
    UI_CONNECTION_STATUS_CONNECTED,
    UI_CONNECTION_STATUS_ERROR
} ui_connection_status_t;

typedef struct {
    char wifi_live_ip[32];
    bool wifi_connected;
    ui_connection_status_t wifi_status;
    ui_connection_status_t ethernet_status;
    ui_connection_status_t lte_status;
    ui_connection_status_t mqtt_status;
    ui_connection_status_t modbus_status;
} ui_live_state_t;

/**
 * @struct ui_runtime_state_t
 * @brief Cấu trúc lưu trữ toàn vẹn trạng thái tĩnh và động của UI tại một thời điểm
 */
typedef struct {
    ui_main_view_t main_view;           /**< Tab chính đang mở */
    ui_settings_view_t settings_view;   /**< Màn hình con trong Settings đang mở */
    ui_dialog_t dialog;                 /**< Popup đang hiển thị (nếu có) */
    
    ui_net_transport_t net_transport;   /**< Loại mạng đang được cấu hình (Wifi/LTE/Eth) */
    ui_ip_mode_t wifi_mode;             /**< Chế độ IP của WiFi (DHCP/Static) */
    ui_ip_mode_t ethernet_mode;         /**< Chế độ IP của Ethernet (DHCP/Static) */
    
    ui_modbus_role_t modbus_role;       /**< Vai trò Modbus (Master/Slave) */
    ui_modbus_overlay_t modbus_overlay; /**< Popup Modbus đang mở (Thêm thiết bị/Xem danh sách) */
    
    // Lưu vết đường lùi (Back stack) để khi tắt Popup biết đường quay về
    ui_main_view_t dialog_return_main_view;
    ui_settings_view_t dialog_return_settings_view;
    
    ui_live_state_t live;               /**< Các trạng thái Runtime theo thời gian thực (Trạng thái mạng, Cảm biến,...) */
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
    UI_ACTION_EDIT_MODBUS_DEVICE,
    UI_ACTION_DELETE_MODBUS_DEVICE,
    UI_ACTION_BACK_TO_MODBUS,
    UI_ACTION_SUBMIT_GENERATE_REPORT,
    UI_ACTION_CANCEL_GENERATE_REPORT,
    UI_ACTION_SHOW_GENERATE_REPORT,
    UI_ACTION_SUBMIT_WIFI_CONFIG,
    UI_ACTION_SUBMIT_ETHERNET_CONFIG,
    UI_ACTION_SUBMIT_LTE_CONFIG,
    UI_ACTION_SUBMIT_MQTT_CONFIG,
    UI_ACTION_SUBMIT_MODBUS_CONFIG,
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
    UI_ACTION_EFFECT_SUBMIT_MQTT_CONFIG,
    UI_ACTION_EFFECT_SUBMIT_MODBUS_CONFIG,
    UI_ACTION_EFFECT_SUBMIT_MODBUS_DEVICE,
    UI_ACTION_EFFECT_LOGIN_SUCCESS,
    UI_ACTION_EFFECT_SECURE_SETTINGS_SUCCESS,
    UI_ACTION_EFFECT_REQUEST_RESTART,
    UI_ACTION_EFFECT_REQUEST_FACTORY_RESET
} ui_action_effect_t;

/**
 * @brief Khởi tạo giá trị mặc định cho State khi mới bật máy.
 */
void ui_state_init_defaults(ui_runtime_state_t *state);

/**
 * @brief Đồng bộ các nút gạt/dropdown trên màn hình sao cho khớp với State hiện tại.
 */
void ui_state_apply_controls(view_factory_t *ui, const ui_runtime_state_t *state);

/**
 * @brief Hàm State Machine chính. Xử lý Action và trả về Side-Effect cần thiết (như Lưu bộ nhớ, Khởi động lại).
 * @param state Con trỏ tới bộ State hiện tại
 * @param action Hành động phát ra từ màn hình (Nút bấm,...)
 * @param value Dữ liệu đính kèm của hành động
 * @return Hiệu ứng phụ cần thực thi (Lưu WiFi, Gọi khởi động lại)
 */
ui_action_effect_t ui_state_dispatch(ui_runtime_state_t *state, ui_action_t action, uint16_t value);

/**
 * @brief Quét qua toàn bộ UI để ẩn/hiện các khung nhìn (View) sao cho phản ánh đúng bộ State hiện tại.
 */
void ui_state_render(view_factory_t *ui, const ui_runtime_state_t *state);

#ifdef __cplusplus
}
#endif

#endif // __APP_STATE_H_
