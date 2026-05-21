#include "ui_events_navigation.h"

#include "ui_screen_controller.h"

static void bind_cb(lv_obj_t *obj, lv_event_cb_t cb, lv_event_code_t code, void *user_data)
{
    if (!obj || !lv_obj_is_valid(obj)) return;
    lv_obj_remove_event_cb_with_user_data(obj, cb, user_data);
    lv_obj_add_event_cb(obj, cb, code, user_data);
}

static void dispatch_simple(lv_event_t *e, ui_action_t action)
{
    lv_ui *ui = lv_event_get_user_data(e);
    ui_screen_controller_dispatch(ui, action, 0U);
}

static void btn_dashboard_clicked_cb(lv_event_t *e) { dispatch_simple(e, UI_ACTION_SHOW_DASHBOARD); }
static void btn_analysis_clicked_cb(lv_event_t *e) { dispatch_simple(e, UI_ACTION_SHOW_ANALYSIS); }
static void btn_event_logs_clicked_cb(lv_event_t *e) { dispatch_simple(e, UI_ACTION_SHOW_EVENT_LOGS); }
static void btn_settings_clicked_cb(lv_event_t *e) { dispatch_simple(e, UI_ACTION_SHOW_SETTINGS_MENU); }
static void btn_restart_clicked_cb(lv_event_t *e) { dispatch_simple(e, UI_ACTION_SHOW_RESTART_DIALOG); }
static void btn_restart_cancel_clicked_cb(lv_event_t *e) { dispatch_simple(e, UI_ACTION_CANCEL_DIALOG); }
static void btn_restart_confirm_clicked_cb(lv_event_t *e) { dispatch_simple(e, UI_ACTION_CONFIRM_RESTART); }
static void btn_restore_confirm_clicked_cb(lv_event_t *e) { dispatch_simple(e, UI_ACTION_CONFIRM_RESTORE); }
static void btn_restore_cancel_clicked_cb(lv_event_t *e) { dispatch_simple(e, UI_ACTION_CANCEL_DIALOG); }
static void btn_net_clicked_cb(lv_event_t *e) { dispatch_simple(e, UI_ACTION_SHOW_SETTINGS_NET); }
static void btn_mqtt_clicked_cb(lv_event_t *e) { dispatch_simple(e, UI_ACTION_SHOW_SETTINGS_MQTT); }
static void btn_modbus_clicked_cb(lv_event_t *e) { dispatch_simple(e, UI_ACTION_SHOW_SETTINGS_MODBUS); }
static void btn_sys_admin_clicked_cb(lv_event_t *e) { dispatch_simple(e, UI_ACTION_SHOW_SETTINGS_SYS_ADMIN); }
static void btn_hw_back_clicked_cb(lv_event_t *e) { dispatch_simple(e, UI_ACTION_BACK_TO_SETTINGS_MENU); }
static void btn_restart_system_clicked_cb(lv_event_t *e) { dispatch_simple(e, UI_ACTION_SHOW_RESTART_DIALOG); }
static void btn_factory_reset_clicked_cb(lv_event_t *e) { dispatch_simple(e, UI_ACTION_SHOW_RESTORE_DIALOG); }
static void btn_master_adddevice_clicked_cb(lv_event_t *e) { dispatch_simple(e, UI_ACTION_SHOW_MODBUS_DEVICE_CONFIG); }
static void btn_master_viewlist_clicked_cb(lv_event_t *e) { dispatch_simple(e, UI_ACTION_SHOW_MODBUS_DEVICE_VIEWLIST); }
static void btn_master_device_apply_clicked_cb(lv_event_t *e) { dispatch_simple(e, UI_ACTION_APPLY_MODBUS_DEVICE); }
static void btn_device_overlay_back_to_modbus_cb(lv_event_t *e) { dispatch_simple(e, UI_ACTION_BACK_TO_MODBUS); }
static void btn_noop_clicked_cb(lv_event_t *e) { dispatch_simple(e, UI_ACTION_NOOP); }

static void btn_clear_history_clicked_cb(lv_event_t *e)
{
    lv_ui *ui = lv_event_get_user_data(e);
    uint32_t cnt;

    if (!ui || !ui->scr_base_cont_logs || !lv_obj_is_valid(ui->scr_base_cont_logs)) return;

    cnt = lv_obj_get_child_count(ui->scr_base_cont_logs);
    while (cnt > 0U) {
        lv_obj_t *child;
        cnt--;
        child = lv_obj_get_child(ui->scr_base_cont_logs, cnt);
        if (!child) continue;
        if (child == ui->scr_base_lbl_critical_logs) continue;
        if (child == ui->scr_base_btn_clear_history) continue;
        lv_obj_delete(child);
    }
}

static void ddlist_net_option_changed_cb(lv_event_t *e)
{
    lv_ui *ui = lv_event_get_user_data(e);
    lv_obj_t *dd = lv_event_get_target(e);
    if (!ui || !dd) return;
    ui_screen_controller_dispatch(ui, UI_ACTION_SET_NET_TRANSPORT, (uint16_t)lv_dropdown_get_selected(dd));
}

static void ddlist_wifi_mode_changed_cb(lv_event_t *e)
{
    lv_ui *ui = lv_event_get_user_data(e);
    lv_obj_t *dd = lv_event_get_target(e);
    if (!ui || !dd) return;
    ui_screen_controller_dispatch(ui, UI_ACTION_SET_WIFI_MODE, (uint16_t)lv_dropdown_get_selected(dd));
}

static void ddlist_ethernet_mode_changed_cb(lv_event_t *e)
{
    lv_ui *ui = lv_event_get_user_data(e);
    lv_obj_t *dd = lv_event_get_target(e);
    if (!ui || !dd) return;
    ui_screen_controller_dispatch(ui, UI_ACTION_SET_ETHERNET_MODE, (uint16_t)lv_dropdown_get_selected(dd));
}

static void ddlist_modbus_mode_changed_cb(lv_event_t *e)
{
    lv_ui *ui = lv_event_get_user_data(e);
    lv_obj_t *dd = lv_event_get_target(e);
    if (!ui || !dd) return;
    ui_screen_controller_dispatch(ui, UI_ACTION_SET_MODBUS_ROLE, (uint16_t)lv_dropdown_get_selected(dd));
}

void ui_events_navigation_init(lv_ui *ui)
{
    if (!ui) return;

    bind_cb(ui->scr_base_btn_dashboard, btn_dashboard_clicked_cb, LV_EVENT_SHORT_CLICKED, ui);
    bind_cb(ui->scr_base_btn_analystis, btn_analysis_clicked_cb, LV_EVENT_SHORT_CLICKED, ui);
    bind_cb(ui->scr_base_btn_event_logs, btn_event_logs_clicked_cb, LV_EVENT_SHORT_CLICKED, ui);
    bind_cb(ui->scr_base_btn_settings, btn_settings_clicked_cb, LV_EVENT_SHORT_CLICKED, ui);
    bind_cb(ui->scr_base_btn_restart, btn_restart_clicked_cb, LV_EVENT_SHORT_CLICKED, ui);
    bind_cb(ui->scr_base_btn_restart_cancel, btn_restart_cancel_clicked_cb, LV_EVENT_SHORT_CLICKED, ui);
    bind_cb(ui->scr_base_btn_restart_confirm, btn_restart_confirm_clicked_cb, LV_EVENT_SHORT_CLICKED, ui);
    bind_cb(ui->scr_base_btn_restore_confirm, btn_restore_confirm_clicked_cb, LV_EVENT_SHORT_CLICKED, ui);
    bind_cb(ui->scr_base_btn_restore_cancel, btn_restore_cancel_clicked_cb, LV_EVENT_SHORT_CLICKED, ui);
    bind_cb(ui->scr_base_btn_net, btn_net_clicked_cb, LV_EVENT_SHORT_CLICKED, ui);
    bind_cb(ui->scr_base_btn_mqtt, btn_mqtt_clicked_cb, LV_EVENT_SHORT_CLICKED, ui);
    bind_cb(ui->scr_base_btn_modbus, btn_modbus_clicked_cb, LV_EVENT_SHORT_CLICKED, ui);
    bind_cb(ui->scr_base_btn_sys_admin, btn_sys_admin_clicked_cb, LV_EVENT_SHORT_CLICKED, ui);
    bind_cb(ui->scr_base_btn_net_back, btn_hw_back_clicked_cb, LV_EVENT_SHORT_CLICKED, ui);
    bind_cb(ui->scr_base_btn_mqtt_back, btn_hw_back_clicked_cb, LV_EVENT_SHORT_CLICKED, ui);
    bind_cb(ui->scr_base_btn_modbus_back, btn_hw_back_clicked_cb, LV_EVENT_SHORT_CLICKED, ui);
    bind_cb(ui->scr_base_btn_sys_back, btn_hw_back_clicked_cb, LV_EVENT_SHORT_CLICKED, ui);
    bind_cb(ui->scr_base_btn_clear_history, btn_clear_history_clicked_cb, LV_EVENT_SHORT_CLICKED, ui);
    bind_cb(ui->scr_base_btn_restart_system, btn_restart_system_clicked_cb, LV_EVENT_SHORT_CLICKED, ui);
    bind_cb(ui->scr_base_btn_factory_reset, btn_factory_reset_clicked_cb, LV_EVENT_SHORT_CLICKED, ui);
    bind_cb(ui->scr_base_btn_master_adddeivce, btn_master_adddevice_clicked_cb, LV_EVENT_SHORT_CLICKED, ui);
    bind_cb(ui->scr_base_btn_masterviewlist, btn_master_viewlist_clicked_cb, LV_EVENT_SHORT_CLICKED, ui);
    bind_cb(ui->scr_base_btn_master_device_apply, btn_master_device_apply_clicked_cb, LV_EVENT_SHORT_CLICKED, ui);
    bind_cb(ui->scr_base_btn_deviceconfig_back, btn_device_overlay_back_to_modbus_cb, LV_EVENT_SHORT_CLICKED, ui);
    bind_cb(ui->scr_base_btn_devicelist_back, btn_device_overlay_back_to_modbus_cb, LV_EVENT_SHORT_CLICKED, ui);
    bind_cb(ui->scr_base_btn_generate_report, btn_noop_clicked_cb, LV_EVENT_SHORT_CLICKED, ui);
    bind_cb(ui->scr_base_btn_wifi_apply, btn_noop_clicked_cb, LV_EVENT_SHORT_CLICKED, ui);
    bind_cb(ui->scr_base_btn_ethernet_apply, btn_noop_clicked_cb, LV_EVENT_SHORT_CLICKED, ui);
    bind_cb(ui->scr_base_btn_lte_apply, btn_noop_clicked_cb, LV_EVENT_SHORT_CLICKED, ui);

    bind_cb(ui->scr_base_ddlist_net_option, ddlist_net_option_changed_cb, LV_EVENT_VALUE_CHANGED, ui);
    bind_cb(ui->scr_base_ddlist_wifi_mode, ddlist_wifi_mode_changed_cb, LV_EVENT_VALUE_CHANGED, ui);
    bind_cb(ui->scr_base_ddlist_ethernet_mode, ddlist_ethernet_mode_changed_cb, LV_EVENT_VALUE_CHANGED, ui);
    bind_cb(ui->scr_base_ddlist_modbus_mode, ddlist_modbus_mode_changed_cb, LV_EVENT_VALUE_CHANGED, ui);
}
