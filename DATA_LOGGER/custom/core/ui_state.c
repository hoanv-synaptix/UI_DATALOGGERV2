#include "ui_state.h"
#include "lvgl.h"
#include "ui_dashboard.h"
#include "ui_modbus_list.h"

static void hide_obj(lv_obj_t *obj)
{
    if (obj) lv_obj_add_flag(obj, LV_OBJ_FLAG_HIDDEN);
}

static void show_obj(lv_obj_t *obj)
{
    if (obj) lv_obj_clear_flag(obj, LV_OBJ_FLAG_HIDDEN);
}

static void set_sidebar_button_active(lv_obj_t *button, bool active)
{
    if (!button) return;

    if (active) {
        lv_obj_set_style_bg_opa(button, 39, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_color(button, lv_color_hex(0x10B981), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_grad_dir(button, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_radius(button, 14, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_color(button, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    } else {
        lv_obj_set_style_bg_opa(button, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_radius(button, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_color(button, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    }
}

static void set_sidebar_active(ui_context_t *ui, ui_main_view_t active)
{
    ui_shell_refs_t refs;
    lv_obj_t *buttons[] = {
        NULL, NULL, NULL, NULL
    };
    uint32_t i;

    ui_context_get_shell_refs(ui, &refs);
    buttons[0] = refs.btn_dashboard;
    buttons[1] = refs.btn_analysis;
    buttons[2] = refs.btn_event_logs;
    buttons[3] = refs.btn_settings;

    for (i = 0U; i < 4U; ++i) {
        if (!buttons[i]) continue;
        set_sidebar_button_active(buttons[i], (uint32_t)active == i);
    }
}

static void hide_all_main(ui_context_t *ui)
{
    ui_main_view_refs_t refs;

    ui_context_get_main_view_refs(ui, &refs);
    hide_obj(refs.cont_dashboard);
    hide_obj(refs.cont_analysis);
    hide_obj(refs.cont_event_logs);
    hide_obj(refs.cont_hw);
}

static void hide_all_settings(ui_context_t *ui)
{
    ui_settings_nav_refs_t refs;

    ui_context_get_settings_nav_refs(ui, &refs);
    hide_obj(refs.cont_menu);
    hide_obj(refs.cont_network_config);
    hide_obj(refs.cont_mqtt_config);
    hide_obj(refs.cont_modbus_config);
    hide_obj(refs.cont_system_admin);
}

static void hide_all_net_transports(ui_context_t *ui)
{
    ui_network_refs_t refs;

    ui_context_get_network_refs(ui, &refs);
    hide_obj(refs.cont_wifi);
    hide_obj(refs.cont_ethernet);
    hide_obj(refs.cont_lte);
}

static void hide_all_dialogs(ui_context_t *ui)
{
    ui_system_refs_t refs;

    ui_context_get_system_refs(ui, &refs);
    hide_obj(refs.cont_restart);
    hide_obj(refs.cont_restore);
}

static void hide_all_modbus_overlays(ui_context_t *ui)
{
    ui_modbus_refs_t refs;

    ui_context_get_modbus_refs(ui, &refs);
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
    default:
        return "Disconnected";
    }
}

static void render_settings_content(ui_context_t *ui, const ui_runtime_state_t *state)
{
    ui_main_view_refs_t main_refs;
    ui_settings_nav_refs_t settings_refs;
    ui_network_refs_t network_refs;
    ui_modbus_refs_t modbus_refs;
    ui_system_refs_t system_refs;

    ui_context_get_main_view_refs(ui, &main_refs);
    ui_context_get_settings_nav_refs(ui, &settings_refs);
    ui_context_get_network_refs(ui, &network_refs);
    ui_context_get_modbus_refs(ui, &modbus_refs);
    ui_context_get_system_refs(ui, &system_refs);
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
    state->main_view = UI_MAIN_VIEW_DASHBOARD;
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
    state->live.wifi_status = UI_CONNECTION_STATUS_DISCONNECTED;
    ui_dashboard_init();
    ui_modbus_list_init();
}

void ui_state_apply_controls(ui_context_t *ui, const ui_runtime_state_t *state)
{
    ui_network_refs_t network_refs;
    ui_modbus_refs_t modbus_refs;

    if (!state || !ui) return;
    ui_context_get_network_refs(ui, &network_refs);
    ui_context_get_modbus_refs(ui, &modbus_refs);

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

static void save_dialog_return_target(ui_runtime_state_t *state)
{
    state->dialog_return_main_view = state->main_view;
    state->dialog_return_settings_view = state->settings_view;
}

ui_action_effect_t ui_state_dispatch(ui_runtime_state_t *state, ui_action_t action, uint16_t value)
{
    if (!state) return UI_ACTION_EFFECT_NONE;

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
        return UI_ACTION_EFFECT_REQUEST_RESTART;
    case UI_ACTION_CONFIRM_RESTORE:
        state->dialog = UI_DIALOG_NONE;
        state->main_view = state->dialog_return_main_view;
        state->settings_view = state->dialog_return_settings_view;
        return UI_ACTION_EFFECT_REQUEST_FACTORY_RESET;
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
        state->dialog = UI_DIALOG_NONE;
        state->modbus_overlay = UI_MODBUS_OVERLAY_NONE;
        break;
    case UI_ACTION_SHOW_MODBUS_DEVICE_CONFIG:
        state->main_view = UI_MAIN_VIEW_SETTINGS;
        state->settings_view = UI_SETTINGS_VIEW_MODBUS;
        state->dialog = UI_DIALOG_NONE;
        state->modbus_overlay = UI_MODBUS_OVERLAY_DEVICE_CONFIG;
        break;
    case UI_ACTION_SHOW_MODBUS_DEVICE_VIEWLIST:
    case UI_ACTION_APPLY_MODBUS_DEVICE:
        state->main_view = UI_MAIN_VIEW_SETTINGS;
        state->settings_view = UI_SETTINGS_VIEW_MODBUS;
        state->dialog = UI_DIALOG_NONE;
        state->modbus_overlay = UI_MODBUS_OVERLAY_DEVICE_VIEWLIST;
        if (action == UI_ACTION_APPLY_MODBUS_DEVICE) {
            return UI_ACTION_EFFECT_SUBMIT_MODBUS_DEVICE;
        }
        break;
    case UI_ACTION_BACK_TO_MODBUS:
        state->main_view = UI_MAIN_VIEW_SETTINGS;
        state->settings_view = UI_SETTINGS_VIEW_MODBUS;
        state->dialog = UI_DIALOG_NONE;
        state->modbus_overlay = UI_MODBUS_OVERLAY_NONE;
        break;
    case UI_ACTION_SUBMIT_GENERATE_REPORT:
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
        return UI_ACTION_EFFECT_SUBMIT_ETHERNET_CONFIG;
    case UI_ACTION_SUBMIT_LTE_CONFIG:
        state->main_view = UI_MAIN_VIEW_SETTINGS;
        state->settings_view = UI_SETTINGS_VIEW_NET;
        state->dialog = UI_DIALOG_NONE;
        state->net_transport = UI_NET_TRANSPORT_LTE;
        return UI_ACTION_EFFECT_SUBMIT_LTE_CONFIG;
    default:
        break;
    }

    return UI_ACTION_EFFECT_NONE;
}

void ui_state_render(ui_context_t *ui, const ui_runtime_state_t *state)
{
    ui_main_view_refs_t main_refs;
    ui_network_refs_t network_refs;
    ui_modbus_refs_t modbus_refs;
    ui_system_refs_t system_refs;

    if (!ui || !state) return;
    ui_context_get_main_view_refs(ui, &main_refs);
    ui_context_get_network_refs(ui, &network_refs);
    ui_context_get_modbus_refs(ui, &modbus_refs);
    ui_context_get_system_refs(ui, &system_refs);

    hide_all_dialogs(ui);
    hide_all_modbus_overlays(ui);
    hide_all_net_transports(ui);
    hide_all_settings(ui);
    hide_all_main(ui);
    hide_obj(modbus_refs.cont_master);
    hide_obj(modbus_refs.cont_slave);

    if (state->dialog == UI_DIALOG_RESTART) {
        show_obj(system_refs.cont_restart);
    } else if (state->dialog == UI_DIALOG_RESTORE) {
        show_obj(system_refs.cont_restore);
    } else {
        switch (state->main_view) {
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

    if (network_refs.label_wifi_status) {
        lv_label_set_text(network_refs.label_wifi_status, connection_status_text(state->live.wifi_status));
    }

    set_sidebar_active(ui, state->main_view);
    
    ui_dashboard_render(state->main_view == UI_MAIN_VIEW_DASHBOARD);

    /* Render modbus device list when the viewlist overlay is active */
    if (state->main_view == UI_MAIN_VIEW_SETTINGS &&
        state->settings_view == UI_SETTINGS_VIEW_MODBUS &&
        state->modbus_overlay == UI_MODBUS_OVERLAY_DEVICE_VIEWLIST) {
        ui_modbus_list_render();
    }
}
