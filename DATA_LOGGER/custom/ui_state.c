#include "ui_state.h"
#include "lvgl.h"

static void hide_obj(lv_obj_t *obj)
{
    if (obj) lv_obj_add_flag(obj, LV_OBJ_FLAG_HIDDEN);
}

static void show_obj(lv_obj_t *obj)
{
    if (obj) lv_obj_clear_flag(obj, LV_OBJ_FLAG_HIDDEN);
}

static void set_sidebar_active(lv_ui *ui, ui_main_view_t active)
{
    lv_obj_t *buttons[] = {
        ui ? ui->scr_base_btn_dashboard : NULL,
        ui ? ui->scr_base_btn_analystis : NULL,
        ui ? ui->scr_base_btn_event_logs : NULL,
        ui ? ui->scr_base_btn_settings : NULL
    };
    uint32_t i;

    for (i = 0U; i < 4U; ++i) {
        if (!buttons[i]) continue;
        if ((uint32_t)active == i) lv_obj_add_state(buttons[i], LV_STATE_CHECKED);
        else lv_obj_clear_state(buttons[i], LV_STATE_CHECKED);
    }
}

static void hide_all_main(lv_ui *ui)
{
    hide_obj(ui->scr_base_cont_dashboard);
    hide_obj(ui->scr_base_cont_data_analysis);
    hide_obj(ui->scr_base_cont_event_logs);
    hide_obj(ui->scr_base_cont_hw);
}

static void hide_all_settings(lv_ui *ui)
{
    hide_obj(ui->scr_base_cont_menu);
    hide_obj(ui->scr_base_cont_networkconfig);
    hide_obj(ui->scr_base_cont_mqtt_config);
    hide_obj(ui->scr_base_cont_modbus_config);
    hide_obj(ui->scr_base_cont_system_admin);
}

static void hide_all_net_transports(lv_ui *ui)
{
    hide_obj(ui->scr_base_cont_wifi);
    hide_obj(ui->scr_base_cont_ethernet);
    hide_obj(ui->scr_base_cont_lte);
}

static void hide_all_dialogs(lv_ui *ui)
{
    hide_obj(ui->scr_base_cont_restart);
    hide_obj(ui->scr_base_cont_restore);
}

static void hide_all_modbus_overlays(lv_ui *ui)
{
    hide_obj(ui->scr_base_cont_device_config);
    hide_obj(ui->scr_base_cont_device_viewlist);
}

static void render_settings_content(lv_ui *ui, const ui_runtime_state_t *state)
{
    show_obj(ui->scr_base_cont_hw);

    switch (state->settings_view) {
    case UI_SETTINGS_VIEW_MENU:
        show_obj(ui->scr_base_cont_menu);
        break;
    case UI_SETTINGS_VIEW_NET:
        show_obj(ui->scr_base_cont_networkconfig);
        switch (state->net_transport) {
        case UI_NET_TRANSPORT_WIFI:
            show_obj(ui->scr_base_cont_wifi);
            break;
        case UI_NET_TRANSPORT_LTE:
            show_obj(ui->scr_base_cont_lte);
            break;
        case UI_NET_TRANSPORT_ETHERNET:
        default:
            show_obj(ui->scr_base_cont_ethernet);
            break;
        }
        break;
    case UI_SETTINGS_VIEW_MQTT:
        show_obj(ui->scr_base_cont_mqtt_config);
        break;
    case UI_SETTINGS_VIEW_MODBUS:
        show_obj(ui->scr_base_cont_modbus_config);
        if (state->modbus_role == UI_MODBUS_ROLE_MASTER) {
            show_obj(ui->scr_base_cont_master);
            hide_obj(ui->scr_base_cont_slave);
        } else {
            hide_obj(ui->scr_base_cont_master);
            show_obj(ui->scr_base_cont_slave);
        }

        if (state->modbus_overlay == UI_MODBUS_OVERLAY_DEVICE_CONFIG) {
            show_obj(ui->scr_base_cont_device_config);
        } else if (state->modbus_overlay == UI_MODBUS_OVERLAY_DEVICE_VIEWLIST) {
            show_obj(ui->scr_base_cont_device_viewlist);
        }
        break;
    case UI_SETTINGS_VIEW_SYS_ADMIN:
        show_obj(ui->scr_base_cont_system_admin);
        break;
    default:
        show_obj(ui->scr_base_cont_menu);
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
}

void ui_state_sync_from_widgets(ui_runtime_state_t *state, lv_ui *ui)
{
    if (!state || !ui) return;
    if (ui->scr_base_ddlist_net_option) {
        uint32_t sel = lv_dropdown_get_selected(ui->scr_base_ddlist_net_option);
        if (sel == 1U) state->net_transport = UI_NET_TRANSPORT_WIFI;
        else if (sel == 2U) state->net_transport = UI_NET_TRANSPORT_LTE;
        else state->net_transport = UI_NET_TRANSPORT_ETHERNET;
    }
    if (ui->scr_base_ddlist_wifi_mode) {
        state->wifi_mode = lv_dropdown_get_selected(ui->scr_base_ddlist_wifi_mode) == 0U ? UI_IP_MODE_DHCP : UI_IP_MODE_STATIC;
    }
    if (ui->scr_base_ddlist_ethernet_mode) {
        state->ethernet_mode = lv_dropdown_get_selected(ui->scr_base_ddlist_ethernet_mode) == 0U ? UI_IP_MODE_DHCP : UI_IP_MODE_STATIC;
    }
    if (ui->scr_base_ddlist_modbus_mode) {
        state->modbus_role = lv_dropdown_get_selected(ui->scr_base_ddlist_modbus_mode) == 0U ? UI_MODBUS_ROLE_MASTER : UI_MODBUS_ROLE_SLAVE;
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
    case UI_ACTION_CONFIRM_RESTORE:
        ui_state_init_defaults(state);
        return UI_ACTION_EFFECT_REBOOT;
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
        break;
    case UI_ACTION_BACK_TO_MODBUS:
        state->main_view = UI_MAIN_VIEW_SETTINGS;
        state->settings_view = UI_SETTINGS_VIEW_MODBUS;
        state->dialog = UI_DIALOG_NONE;
        state->modbus_overlay = UI_MODBUS_OVERLAY_NONE;
        break;
    case UI_ACTION_NOOP:
    default:
        break;
    }

    return UI_ACTION_EFFECT_NONE;
}

void ui_state_render(lv_ui *ui, const ui_runtime_state_t *state)
{
    if (!ui || !state) return;

    hide_all_dialogs(ui);
    hide_all_modbus_overlays(ui);
    hide_all_net_transports(ui);
    hide_all_settings(ui);
    hide_all_main(ui);
    hide_obj(ui->scr_base_cont_master);
    hide_obj(ui->scr_base_cont_slave);

    if (state->dialog == UI_DIALOG_RESTART) {
        show_obj(ui->scr_base_cont_restart);
    } else if (state->dialog == UI_DIALOG_RESTORE) {
        show_obj(ui->scr_base_cont_restore);
    } else {
        switch (state->main_view) {
        case UI_MAIN_VIEW_ANALYSIS:
            show_obj(ui->scr_base_cont_data_analysis);
            break;
        case UI_MAIN_VIEW_EVENT_LOGS:
            show_obj(ui->scr_base_cont_event_logs);
            break;
        case UI_MAIN_VIEW_SETTINGS:
            render_settings_content(ui, state);
            break;
        case UI_MAIN_VIEW_DASHBOARD:
        default:
            show_obj(ui->scr_base_cont_dashboard);
            break;
        }
    }

    set_sidebar_active(ui, state->main_view);
}
