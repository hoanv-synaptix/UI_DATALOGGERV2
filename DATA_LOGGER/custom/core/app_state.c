#include "app_state.h"
#include "lvgl.h"
#include "cmp_dashboard.h"
#include "cmp_modbus_list.h"
#include "ui_auth.h"
#include "modbus_config_service.h"

/**
 * @brief Hàm trợ giúp: Ẩn một đối tượng giao diện LVGL
 */
static void hide_obj(lv_obj_t *obj)
{
    if (obj) lv_obj_add_flag(obj, LV_OBJ_FLAG_HIDDEN);
}

/**
 * @brief Hàm trợ giúp: Hiển thị một đối tượng giao diện LVGL
 */
static void show_obj(lv_obj_t *obj)
{
    if (obj) lv_obj_clear_flag(obj, LV_OBJ_FLAG_HIDDEN);
}

/**
 * @brief Thay đổi màu sắc/hình dáng của nút Menu (Sidebar) để thể hiện nó đang được chọn (Active)
 */
static void set_sidebar_button_active(lv_obj_t *button, bool active)
{
    if (!button) return;

    if (active) {
        // Nút đang được chọn: Nền xanh lá, bo góc lớn
        lv_obj_set_style_bg_opa(button, 39, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_color(button, lv_color_hex(0x10B981), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_grad_dir(button, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_radius(button, 14, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_color(button, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    } else {
        // Nút không được chọn: Nền trong suốt
        lv_obj_set_style_bg_opa(button, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_radius(button, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_color(button, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    }
}

static void set_sidebar_active(view_factory_t *ui, ui_main_view_t active)
{
    ui_shell_refs_t refs;

    view_factory_get_shell_refs(ui, &refs);
    if (!refs.btn_dashboard) return;

    set_sidebar_button_active(refs.btn_dashboard, active == UI_MAIN_VIEW_DASHBOARD);
    set_sidebar_button_active(refs.btn_analysis, active == UI_MAIN_VIEW_ANALYSIS);
    set_sidebar_button_active(refs.btn_event_logs, active == UI_MAIN_VIEW_EVENT_LOGS);
    set_sidebar_button_active(refs.btn_settings, active == UI_MAIN_VIEW_SETTINGS);
}

/**
 * @brief Đóng/Ẩn toàn bộ các màn hình chính để chuẩn bị mở 1 màn hình mới.
 * Đây là triết lý thiết kế Declarative UI: "Đóng tất cả, mở cái cần mở".
 */
static void hide_all_main(view_factory_t *ui)
{
    ui_main_view_refs_t refs;
    ui_login_refs_t login_refs;

    view_factory_get_main_view_refs(ui, &refs);
    view_factory_get_login_refs(ui, &login_refs);
    
    hide_obj(refs.cont_dashboard);
    hide_obj(refs.cont_analysis);
    hide_obj(refs.cont_event_logs);
    hide_obj(refs.cont_hw); // HW là container chứa toàn bộ Settings
    hide_obj(login_refs.cont_booting_login);
}

static void hide_all_settings(view_factory_t *ui)
{
    ui_settings_nav_refs_t refs;

    view_factory_get_settings_nav_refs(ui, &refs);
    hide_obj(refs.cont_menu);
    hide_obj(refs.cont_network_config);
    hide_obj(refs.cont_mqtt_config);
    hide_obj(refs.cont_modbus_config);
    hide_obj(refs.cont_system_admin);
}

static void hide_all_net_transports(view_factory_t *ui)
{
    ui_network_refs_t refs;

    view_factory_get_network_refs(ui, &refs);
    hide_obj(refs.cont_wifi);
    hide_obj(refs.cont_ethernet);
    hide_obj(refs.cont_lte);
}

static void hide_all_dialogs(view_factory_t *ui)
{
    ui_system_refs_t refs;
    ui_login_refs_t login_refs;
    ui_report_refs_t report_refs;

    view_factory_get_system_refs(ui, &refs);
    view_factory_get_login_refs(ui, &login_refs);
    view_factory_get_report_refs(ui, &report_refs);
    hide_obj(refs.cont_restart);
    hide_obj(refs.cont_restore);
    hide_obj(login_refs.cont_login_settings);
    hide_obj(report_refs.cont_generate_report);
}

static void hide_all_modbus_overlays(view_factory_t *ui)
{
    ui_modbus_refs_t refs;

    view_factory_get_modbus_refs(ui, &refs);
    hide_obj(refs.cont_device_config);
    hide_obj(refs.cont_device_viewlist);
}

static const char *connection_status_text(ui_connection_status_t status)
{
    switch (status) {
    case UI_CONNECTION_STATUS_CONNECTING:
        return "Connecting...";
    case UI_CONNECTION_STATUS_CONNECTED:
        return "Connected";
    case UI_CONNECTION_STATUS_ERROR:
        return "Error";
    case UI_CONNECTION_STATUS_DISCONNECTED:
        return "Disconnected";
    default:
        return "";
    }
}

static lv_color_t connection_status_color(ui_connection_status_t status)
{
    switch (status) {
    case UI_CONNECTION_STATUS_CONNECTING:
        return lv_color_hex(0xFBBF24); // Yellow/Amber
    case UI_CONNECTION_STATUS_CONNECTED:
        return lv_color_hex(0x10B981); // Green
    case UI_CONNECTION_STATUS_ERROR:
        return lv_color_hex(0xEF4444); // Red
    case UI_CONNECTION_STATUS_DISCONNECTED:
        return lv_color_hex(0x9CA3AF); // Gray
    default:
        return lv_color_hex(0xFFFFFF); // White
    }
}

static void render_settings_content(view_factory_t *ui, const ui_runtime_state_t *state)
{
    ui_main_view_refs_t main_refs;
    ui_settings_nav_refs_t settings_refs;
    ui_network_refs_t network_refs;
    ui_modbus_refs_t modbus_refs;
    ui_system_refs_t system_refs;

    view_factory_get_main_view_refs(ui, &main_refs);
    view_factory_get_settings_nav_refs(ui, &settings_refs);
    view_factory_get_network_refs(ui, &network_refs);
    view_factory_get_modbus_refs(ui, &modbus_refs);
    view_factory_get_system_refs(ui, &system_refs);
    show_obj(main_refs.cont_hw);

    switch (state->settings_view) {
    case UI_SETTINGS_VIEW_MENU:
        show_obj(settings_refs.cont_menu);
        break;
    case UI_SETTINGS_VIEW_NET:
        show_obj(settings_refs.cont_network_config);
        switch (state->net_transport) {
        case UI_NET_TRANSPORT_WIFI:
            show_obj(network_refs.cont_wifi);
            break;
        case UI_NET_TRANSPORT_LTE:
            show_obj(network_refs.cont_lte);
            break;
        case UI_NET_TRANSPORT_ETHERNET:
        default:
            show_obj(network_refs.cont_ethernet);
            break;
        }
        break;
    case UI_SETTINGS_VIEW_MQTT:
        show_obj(settings_refs.cont_mqtt_config);
        break;
    case UI_SETTINGS_VIEW_MODBUS:
        show_obj(settings_refs.cont_modbus_config);
        if (state->modbus_role == UI_MODBUS_ROLE_MASTER) {
            show_obj(modbus_refs.cont_master);
            hide_obj(modbus_refs.cont_slave);
        } else {
            hide_obj(modbus_refs.cont_master);
            show_obj(modbus_refs.cont_slave);
        }

        if (state->modbus_overlay == UI_MODBUS_OVERLAY_DEVICE_CONFIG) {
            show_obj(modbus_refs.cont_device_config);
        } else if (state->modbus_overlay == UI_MODBUS_OVERLAY_DEVICE_VIEWLIST) {
            show_obj(modbus_refs.cont_device_viewlist);
        }
        break;
    case UI_SETTINGS_VIEW_SYS_ADMIN:
        show_obj(system_refs.cont_system_admin);
        break;
    default:
        show_obj(settings_refs.cont_menu);
        break;
    }
}

void ui_state_init_defaults(ui_runtime_state_t *state)
{
    if (!state) return;
    state->main_view = UI_MAIN_VIEW_LOGIN;
    state->settings_view = UI_SETTINGS_VIEW_MENU;
    state->dialog = UI_DIALOG_NONE;
    state->net_transport = UI_NET_TRANSPORT_ETHERNET;
    state->wifi_mode = UI_IP_MODE_DHCP;
    state->ethernet_mode = UI_IP_MODE_DHCP;
    state->modbus_role = UI_MODBUS_ROLE_MASTER;
    state->modbus_overlay = UI_MODBUS_OVERLAY_NONE;
    state->dialog_return_main_view = UI_MAIN_VIEW_DASHBOARD;
    state->dialog_return_settings_view = UI_SETTINGS_VIEW_MENU;
    state->live.wifi_live_ip[0] = '\0';
    state->live.wifi_connected = false;
    state->live.wifi_status = UI_CONNECTION_STATUS_IDLE;
    state->live.ethernet_status = UI_CONNECTION_STATUS_IDLE;
    state->live.lte_status = UI_CONNECTION_STATUS_IDLE;
    state->live.mqtt_status = UI_CONNECTION_STATUS_IDLE;
    state->live.modbus_status = UI_CONNECTION_STATUS_IDLE;
    cmp_dashboard_init();
    cmp_modbus_list_init();
}

void ui_state_apply_controls(view_factory_t *ui, const ui_runtime_state_t *state)
{
    ui_network_refs_t network_refs;
    ui_modbus_refs_t modbus_refs;

    if (!state || !ui) return;
    view_factory_get_network_refs(ui, &network_refs);
    view_factory_get_modbus_refs(ui, &modbus_refs);

    if (network_refs.ddlist_net_option) {
        uint16_t sel = 0U;
        if (state->net_transport == UI_NET_TRANSPORT_WIFI) sel = 1U;
        else if (state->net_transport == UI_NET_TRANSPORT_LTE) sel = 2U;
        lv_dropdown_set_selected(network_refs.ddlist_net_option, sel);
    }
    if (network_refs.ddlist_wifi_mode) {
        lv_dropdown_set_selected(network_refs.ddlist_wifi_mode, state->wifi_mode == UI_IP_MODE_DHCP ? 0U : 1U);
    }
    if (network_refs.ddlist_ethernet_mode) {
        lv_dropdown_set_selected(network_refs.ddlist_ethernet_mode, state->ethernet_mode == UI_IP_MODE_DHCP ? 0U : 1U);
    }
    if (modbus_refs.ddlist_modbus_mode) {
        lv_dropdown_set_selected(modbus_refs.ddlist_modbus_mode, state->modbus_role == UI_MODBUS_ROLE_MASTER ? 0U : 1U);
    }
}

/**
 * @brief Hàm lưu lại đường lui (Return Target) trước khi mở một Dialog Popup (như Restart, Confirm).
 * Nhờ đó khi bấm Hủy (Cancel), hệ thống biết cần quay về đâu.
 */
static void save_dialog_return_target(ui_runtime_state_t *state)
{
    state->dialog_return_main_view = state->main_view;
    state->dialog_return_settings_view = state->settings_view;
}

ui_action_effect_t ui_state_dispatch(ui_runtime_state_t *state, ui_action_t action, uint16_t value)
{
    if (!state) return UI_ACTION_EFFECT_NONE;

    // Phân tích loại sự kiện từ UI và chuyển đổi State tương ứng.
    // Lưu ý: Hàm này KHÔNG vẽ màn hình, nó chỉ tính toán dữ liệu Logic (State Machine).
    switch (action) {
    case UI_ACTION_SHOW_DASHBOARD:
        state->dialog = UI_DIALOG_NONE;
        state->modbus_overlay = UI_MODBUS_OVERLAY_NONE;
        state->main_view = UI_MAIN_VIEW_DASHBOARD;
        break;
    case UI_ACTION_SHOW_ANALYSIS:
        state->dialog = UI_DIALOG_NONE;
        state->modbus_overlay = UI_MODBUS_OVERLAY_NONE;
        state->main_view = UI_MAIN_VIEW_ANALYSIS;
        break;
    case UI_ACTION_SHOW_EVENT_LOGS:
        state->dialog = UI_DIALOG_NONE;
        state->modbus_overlay = UI_MODBUS_OVERLAY_NONE;
        state->main_view = UI_MAIN_VIEW_EVENT_LOGS;
        break;
    case UI_ACTION_SHOW_SETTINGS_MENU:
    case UI_ACTION_BACK_TO_SETTINGS_MENU:
        state->dialog = UI_DIALOG_NONE;
        state->modbus_overlay = UI_MODBUS_OVERLAY_NONE;
        state->main_view = UI_MAIN_VIEW_SETTINGS;
        state->settings_view = UI_SETTINGS_VIEW_MENU;
        break;
    case UI_ACTION_SHOW_SETTINGS_NET:
        state->dialog = UI_DIALOG_NONE;
        state->modbus_overlay = UI_MODBUS_OVERLAY_NONE;
        state->main_view = UI_MAIN_VIEW_SETTINGS;
        state->settings_view = UI_SETTINGS_VIEW_NET;
        break;
    case UI_ACTION_SHOW_SETTINGS_MQTT:
        state->dialog = UI_DIALOG_NONE;
        state->modbus_overlay = UI_MODBUS_OVERLAY_NONE;
        state->main_view = UI_MAIN_VIEW_SETTINGS;
        state->settings_view = UI_SETTINGS_VIEW_MQTT;
        break;
    case UI_ACTION_SHOW_SETTINGS_MODBUS:
        state->dialog = UI_DIALOG_NONE;
        state->main_view = UI_MAIN_VIEW_SETTINGS;
        state->settings_view = UI_SETTINGS_VIEW_MODBUS;
        break;
    case UI_ACTION_SHOW_SETTINGS_SYS_ADMIN:
        state->dialog = UI_DIALOG_NONE;
        state->modbus_overlay = UI_MODBUS_OVERLAY_NONE;
        state->main_view = UI_MAIN_VIEW_SETTINGS;
        state->settings_view = UI_SETTINGS_VIEW_SYS_ADMIN;
        break;
    case UI_ACTION_SHOW_RESTART_DIALOG:
        save_dialog_return_target(state);
        state->dialog = UI_DIALOG_RESTART;
        state->modbus_overlay = UI_MODBUS_OVERLAY_NONE;
        break;
    case UI_ACTION_SHOW_RESTORE_DIALOG:
        save_dialog_return_target(state);
        state->dialog = UI_DIALOG_RESTORE;
        state->modbus_overlay = UI_MODBUS_OVERLAY_NONE;
        break;
    case UI_ACTION_CANCEL_DIALOG:
        state->dialog = UI_DIALOG_NONE;
        state->main_view = state->dialog_return_main_view;
        state->settings_view = state->dialog_return_settings_view;
        break;
    case UI_ACTION_CONFIRM_RESTART:
        state->dialog = UI_DIALOG_NONE;
        state->main_view = state->dialog_return_main_view;
        state->settings_view = state->dialog_return_settings_view;
        return UI_ACTION_EFFECT_REQUEST_RESTART; // Yêu cầu gửi xuống Firmware
    case UI_ACTION_CONFIRM_RESTORE:
        state->dialog = UI_DIALOG_NONE;
        state->main_view = state->dialog_return_main_view;
        state->settings_view = state->dialog_return_settings_view;
        return UI_ACTION_EFFECT_REQUEST_FACTORY_RESET; // Yêu cầu Factory Reset
    case UI_ACTION_SHOW_GENERATE_REPORT:
        save_dialog_return_target(state);
        state->dialog = UI_DIALOG_GENERATE_REPORT;
        state->modbus_overlay = UI_MODBUS_OVERLAY_NONE;
        break;
    case UI_ACTION_SHOW_SECURE_SETTINGS:
        save_dialog_return_target(state);
        state->dialog = UI_DIALOG_SECURE_SETTINGS;
        state->modbus_overlay = UI_MODBUS_OVERLAY_NONE;
        break;
    case UI_ACTION_CANCEL_SECURE_SETTINGS:
    case UI_ACTION_CANCEL_GENERATE_REPORT:
        state->dialog = UI_DIALOG_NONE;
        state->main_view = state->dialog_return_main_view;
        state->settings_view = state->dialog_return_settings_view;
        break;
    case UI_ACTION_SUBMIT_SECURE_SETTINGS:
        {
            // Xác thực mật khẩu System Admin
            const char *pass = lv_textarea_get_text(view_factory_get_textarea(view_factory_get(), UI_TEXTAREA_SECURE_SETTINGS_PASS));
            if (ui_auth_verify_secure_settings(pass)) {
                state->dialog = UI_DIALOG_NONE;
                state->main_view = UI_MAIN_VIEW_SETTINGS;
                state->settings_view = UI_SETTINGS_VIEW_MENU;
                lv_textarea_set_text(view_factory_get_textarea(view_factory_get(), UI_TEXTAREA_SECURE_SETTINGS_PASS), "");
            }
        }
        break;
    case UI_ACTION_SUBMIT_LOGIN:
        {
            // Xác thực màn hình đăng nhập chính
            const char *user = lv_textarea_get_text(view_factory_get_textarea(view_factory_get(), UI_TEXTAREA_LOGIN_USER));
            const char *pass = lv_textarea_get_text(view_factory_get_textarea(view_factory_get(), UI_TEXTAREA_LOGIN_PASS));
            if (ui_auth_verify_login(user, pass)) {
                state->main_view = UI_MAIN_VIEW_DASHBOARD;
                lv_textarea_set_text(view_factory_get_textarea(view_factory_get(), UI_TEXTAREA_LOGIN_USER), "");
                lv_textarea_set_text(view_factory_get_textarea(view_factory_get(), UI_TEXTAREA_LOGIN_PASS), "");
            }
        }
        break;
    case UI_ACTION_CANCEL_LOGIN:
        break;
    case UI_ACTION_SET_NET_TRANSPORT:
        state->net_transport = value == 1U ? UI_NET_TRANSPORT_WIFI : (value == 2U ? UI_NET_TRANSPORT_LTE : UI_NET_TRANSPORT_ETHERNET);
        state->main_view = UI_MAIN_VIEW_SETTINGS;
        state->settings_view = UI_SETTINGS_VIEW_NET;
        state->dialog = UI_DIALOG_NONE;
        break;
    case UI_ACTION_SET_WIFI_MODE:
        state->wifi_mode = value == 0U ? UI_IP_MODE_DHCP : UI_IP_MODE_STATIC;
        state->main_view = UI_MAIN_VIEW_SETTINGS;
        state->settings_view = UI_SETTINGS_VIEW_NET;
        break;
    case UI_ACTION_SET_ETHERNET_MODE:
        state->ethernet_mode = value == 0U ? UI_IP_MODE_DHCP : UI_IP_MODE_STATIC;
        state->main_view = UI_MAIN_VIEW_SETTINGS;
        state->settings_view = UI_SETTINGS_VIEW_NET;
        break;
    case UI_ACTION_SET_MODBUS_ROLE:
        state->modbus_role = value == 0U ? UI_MODBUS_ROLE_MASTER : UI_MODBUS_ROLE_SLAVE;
        state->main_view = UI_MAIN_VIEW_SETTINGS;
        state->settings_view = UI_SETTINGS_VIEW_MODBUS;
        break;
    case UI_ACTION_SHOW_MODBUS_DEVICE_CONFIG:
        state->modbus_overlay = UI_MODBUS_OVERLAY_DEVICE_CONFIG;
        break;
    case UI_ACTION_SHOW_MODBUS_DEVICE_VIEWLIST:
        state->modbus_overlay = UI_MODBUS_OVERLAY_DEVICE_VIEWLIST;
        break;
    case UI_ACTION_APPLY_MODBUS_DEVICE:
        state->modbus_overlay = UI_MODBUS_OVERLAY_DEVICE_VIEWLIST;
        return UI_ACTION_EFFECT_SUBMIT_MODBUS_DEVICE;
    case UI_ACTION_EDIT_MODBUS_DEVICE:
        modbus_config_remove_cmd(value);
        state->modbus_overlay = UI_MODBUS_OVERLAY_DEVICE_CONFIG;
        break;
    case UI_ACTION_DELETE_MODBUS_DEVICE:
        modbus_config_remove_cmd(value);
        return UI_ACTION_EFFECT_SUBMIT_MODBUS_DEVICE;
    case UI_ACTION_BACK_TO_MODBUS:
        state->main_view = UI_MAIN_VIEW_SETTINGS;
        state->settings_view = UI_SETTINGS_VIEW_MODBUS;
        state->dialog = UI_DIALOG_NONE;
        state->modbus_overlay = UI_MODBUS_OVERLAY_NONE;
        break;
    case UI_ACTION_SUBMIT_GENERATE_REPORT:
        state->dialog = UI_DIALOG_NONE;
        state->main_view = state->dialog_return_main_view;
        state->settings_view = state->dialog_return_settings_view;
        return UI_ACTION_EFFECT_SUBMIT_GENERATE_REPORT;
    case UI_ACTION_SUBMIT_WIFI_CONFIG:
        state->main_view = UI_MAIN_VIEW_SETTINGS;
        state->settings_view = UI_SETTINGS_VIEW_NET;
        state->dialog = UI_DIALOG_NONE;
        state->net_transport = UI_NET_TRANSPORT_WIFI;
        state->live.wifi_connected = false;
        state->live.wifi_status = UI_CONNECTION_STATUS_CONNECTING;
        return UI_ACTION_EFFECT_SUBMIT_WIFI_CONFIG;
    case UI_ACTION_SUBMIT_ETHERNET_CONFIG:
        state->main_view = UI_MAIN_VIEW_SETTINGS;
        state->settings_view = UI_SETTINGS_VIEW_NET;
        state->dialog = UI_DIALOG_NONE;
        state->net_transport = UI_NET_TRANSPORT_ETHERNET;
        state->live.ethernet_status = UI_CONNECTION_STATUS_CONNECTING;
        return UI_ACTION_EFFECT_SUBMIT_ETHERNET_CONFIG;
    case UI_ACTION_SUBMIT_LTE_CONFIG:
        state->main_view = UI_MAIN_VIEW_SETTINGS;
        state->settings_view = UI_SETTINGS_VIEW_NET;
        state->dialog = UI_DIALOG_NONE;
        state->net_transport = UI_NET_TRANSPORT_LTE;
        state->live.lte_status = UI_CONNECTION_STATUS_CONNECTING;
        return UI_ACTION_EFFECT_SUBMIT_LTE_CONFIG;
    case UI_ACTION_SUBMIT_MQTT_CONFIG:
        state->main_view = UI_MAIN_VIEW_SETTINGS;
        state->settings_view = UI_SETTINGS_VIEW_MQTT;
        state->dialog = UI_DIALOG_NONE;
        // Tạm thời để ở trạng thái IDLE, nó sẽ tự thành CONNECTING nếu validate JSON pass bên ctrl_screen
        return UI_ACTION_EFFECT_SUBMIT_MQTT_CONFIG;
    case UI_ACTION_SUBMIT_MODBUS_CONFIG:
        state->main_view = UI_MAIN_VIEW_SETTINGS;
        state->settings_view = UI_SETTINGS_VIEW_MODBUS;
        state->dialog = UI_DIALOG_NONE;
        return UI_ACTION_EFFECT_SUBMIT_MODBUS_CONFIG;
    default:
        break;
    }

    return UI_ACTION_EFFECT_NONE; // Không có yêu cầu nào đẩy xuống Firmware
}

void ui_state_render(view_factory_t *ui, const ui_runtime_state_t *state)
{
    ui_main_view_refs_t main_refs;
    ui_network_refs_t network_refs;
    ui_modbus_refs_t modbus_refs;
    ui_system_refs_t system_refs;
    ui_mqtt_refs_t mqtt_refs;

    if (!ui || !state) return;
    
    // Thu thập tham chiếu (References) đến các Object (Widget) sinh tự động
    view_factory_get_main_view_refs(ui, &main_refs);
    view_factory_get_network_refs(ui, &network_refs);
    view_factory_get_modbus_refs(ui, &modbus_refs);
    view_factory_get_system_refs(ui, &system_refs);
    view_factory_get_mqtt_refs(ui, &mqtt_refs);

    // Bước 1: Ẩn tất cả mọi thứ trước khi Render
    hide_all_dialogs(ui);
    hide_all_modbus_overlays(ui);
    hide_all_net_transports(ui);
    hide_all_settings(ui);
    hide_all_main(ui);
    hide_obj(modbus_refs.cont_master);
    hide_obj(modbus_refs.cont_slave);

    // Bước 2: Hiển thị giao diện dựa vào Logic của biến State
    // Nếu có Dialog đang mở, hệ thống sẽ chặn không mở các màn hình chính
    if (state->dialog == UI_DIALOG_RESTART) {
        show_obj(system_refs.cont_restart);
    } else if (state->dialog == UI_DIALOG_RESTORE) {
        show_obj(system_refs.cont_restore);
    } else if (state->dialog == UI_DIALOG_SECURE_SETTINGS) {
        ui_login_refs_t login_refs;
        view_factory_get_login_refs(ui, &login_refs);
        show_obj(login_refs.cont_login_settings);
    } else if (state->dialog == UI_DIALOG_GENERATE_REPORT) {
        ui_report_refs_t report_refs;
        view_factory_get_report_refs(ui, &report_refs);
        show_obj(report_refs.cont_generate_report);
    } else {
        // Nếu không có Dialog, ta tiến hành Render màn hình chính
        switch (state->main_view) {
        case UI_MAIN_VIEW_LOGIN:
            {
                ui_login_refs_t login_refs;
                view_factory_get_login_refs(ui, &login_refs);
                show_obj(login_refs.cont_booting_login);
            }
            break;
        case UI_MAIN_VIEW_ANALYSIS:
            show_obj(main_refs.cont_analysis);
            break;
        case UI_MAIN_VIEW_EVENT_LOGS:
            show_obj(main_refs.cont_event_logs);
            break;
        case UI_MAIN_VIEW_SETTINGS:
            render_settings_content(ui, state);
            break;
        case UI_MAIN_VIEW_DASHBOARD:
        default:
            show_obj(main_refs.cont_dashboard);
            break;
        }
    }

    // Bước 3: Cập nhật các Dữ liệu thời gian thực (Trạng thái mạng, mây)
    if (state->live.wifi_status != UI_CONNECTION_STATUS_IDLE && network_refs.label_wifi_status) {
        lv_label_set_text(network_refs.label_wifi_status, connection_status_text(state->live.wifi_status));
        lv_obj_set_style_text_color(network_refs.label_wifi_status, connection_status_color(state->live.wifi_status), LV_PART_MAIN | LV_STATE_DEFAULT);
    }
    if (state->live.ethernet_status != UI_CONNECTION_STATUS_IDLE && network_refs.label_ethernet_status) {
        lv_label_set_text(network_refs.label_ethernet_status, connection_status_text(state->live.ethernet_status));
        lv_obj_set_style_text_color(network_refs.label_ethernet_status, connection_status_color(state->live.ethernet_status), LV_PART_MAIN | LV_STATE_DEFAULT);
    }
    if (state->live.lte_status != UI_CONNECTION_STATUS_IDLE && network_refs.label_lte_status) {
        lv_label_set_text(network_refs.label_lte_status, connection_status_text(state->live.lte_status));
        lv_obj_set_style_text_color(network_refs.label_lte_status, connection_status_color(state->live.lte_status), LV_PART_MAIN | LV_STATE_DEFAULT);
    }
    if (state->live.mqtt_status != UI_CONNECTION_STATUS_IDLE && mqtt_refs.label_mqtt_status) {
        lv_label_set_text(mqtt_refs.label_mqtt_status, connection_status_text(state->live.mqtt_status));
        lv_obj_set_style_text_color(mqtt_refs.label_mqtt_status, connection_status_color(state->live.mqtt_status), LV_PART_MAIN | LV_STATE_DEFAULT);
    }
    if (state->live.modbus_status != UI_CONNECTION_STATUS_IDLE && modbus_refs.label_modbus_status) {
        lv_label_set_text(modbus_refs.label_modbus_status, connection_status_text(state->live.modbus_status));
        lv_obj_set_style_text_color(modbus_refs.label_modbus_status, connection_status_color(state->live.modbus_status), LV_PART_MAIN | LV_STATE_DEFAULT);
    }

    // Bước 4: Tô sáng menu bên trái
    set_sidebar_active(ui, state->main_view);
    
    // Bước 5: Gọi hàm Render của các Component độc lập
    // Điều này để Dashboard dừng chạy Timer khi đang không mở màn hình Dashboard, tiết kiệm CPU
    cmp_dashboard_render(state->main_view == UI_MAIN_VIEW_DASHBOARD);

    /* Render modbus device list khi ViewList được bật */
    if (state->main_view == UI_MAIN_VIEW_SETTINGS &&
        state->settings_view == UI_SETTINGS_VIEW_MODBUS &&
        state->modbus_overlay == UI_MODBUS_OVERLAY_DEVICE_VIEWLIST) {
        cmp_modbus_list_render();
    }
}
