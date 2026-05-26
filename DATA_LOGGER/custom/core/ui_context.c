#include "ui_context.h"

#include <string.h>
#include "custom.h"
#include "events_init.h"
#include "gui_guider.h"

struct ui_context {
    lv_ui *generated;
};

typedef struct {
    lv_obj_t *base_screen;
    lv_obj_t *booting_screen;
    lv_obj_t *keyboard;
    lv_obj_t *logs_container;
    lv_obj_t *critical_logs_label;
    lv_obj_t *clear_history_button;
    lv_obj_t *btn_dashboard;
    lv_obj_t *btn_analysis;
    lv_obj_t *btn_event_logs;
    lv_obj_t *btn_settings;
    lv_obj_t *btn_restart;
    lv_obj_t *btn_restart_cancel;
    lv_obj_t *btn_restart_confirm;
    lv_obj_t *btn_restore_confirm;
    lv_obj_t *btn_restore_cancel;
    lv_obj_t *btn_net;
    lv_obj_t *btn_mqtt;
    lv_obj_t *btn_modbus;
    lv_obj_t *btn_sys_admin;
    lv_obj_t *btn_net_back;
    lv_obj_t *btn_mqtt_back;
    lv_obj_t *btn_modbus_back;
    lv_obj_t *btn_sys_back;
    lv_obj_t *btn_restart_system;
    lv_obj_t *btn_factory_reset;
    lv_obj_t *btn_master_adddevice;
    lv_obj_t *btn_master_viewlist;
    lv_obj_t *btn_master_device_apply;
    lv_obj_t *btn_deviceconfig_back;
    lv_obj_t *btn_devicelist_back;
    lv_obj_t *btn_generate_report;
    lv_obj_t *btn_wifi_apply;
    lv_obj_t *btn_ethernet_apply;
    lv_obj_t *btn_lte_apply;
    lv_obj_t *cont_dashboard;
    lv_obj_t *cont_analysis;
    lv_obj_t *cont_event_logs;
    lv_obj_t *cont_hw;
    lv_obj_t *cont_menu;
    lv_obj_t *cont_network_config;
    lv_obj_t *cont_mqtt_config;
    lv_obj_t *cont_modbus_config;
    lv_obj_t *cont_system_admin;
    lv_obj_t *cont_wifi;
    lv_obj_t *cont_ethernet;
    lv_obj_t *cont_lte;
    lv_obj_t *cont_restart;
    lv_obj_t *cont_restore;
    lv_obj_t *cont_master;
    lv_obj_t *cont_slave;
    lv_obj_t *cont_device_config;
    lv_obj_t *cont_device_viewlist;
    lv_obj_t *cont_mqtt_form;
    lv_obj_t *cont_master_device_form;
    lv_obj_t *ddlist_net_option;
    lv_obj_t *ddlist_wifi_mode;
    lv_obj_t *ddlist_ethernet_mode;
    lv_obj_t *ddlist_modbus_mode;
    lv_obj_t *ta[UI_TEXTAREA_COUNT];
    lv_obj_t *label_wifi_ip;
    lv_obj_t *label_wifi_status;
    lv_obj_t *label_ethernet_ip;
    lv_obj_t *label_ethernet_subnet;
    lv_obj_t *label_ethernet_gateway;
} ui_widget_refs_t;

extern lv_ui guider_ui;

static ui_context_t s_ui_context = {
    .generated = &guider_ui
};

static void base_screen_loaded_cb(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_ui *g = s_ui_context.generated;

    if (code != LV_EVENT_SCREEN_LOADED) return;
    if (!g) return;

    custom_init(g);
}

static void booting_screen_loaded_cb(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_ui *g = s_ui_context.generated;

    if (code != LV_EVENT_SCREEN_LOADED) return;
    if (!g) return;
    if (!g->scr_base || !lv_obj_is_valid(g->scr_base)) return;

    lv_obj_remove_event_cb(g->scr_base, base_screen_loaded_cb);
    lv_obj_add_event_cb(g->scr_base, base_screen_loaded_cb, LV_EVENT_ALL, g);
}

static void bind_booting_lifecycle(lv_ui *g)
{
    if (!g || !g->scr_booting || !lv_obj_is_valid(g->scr_booting)) return;

    lv_obj_remove_event_cb(g->scr_booting, booting_screen_loaded_cb);
    lv_obj_add_event_cb(g->scr_booting, booting_screen_loaded_cb, LV_EVENT_ALL, g);
}

static void load_booting_screen(lv_ui *g, uint32_t time, uint32_t delay)
{
    if (!g) return;

    setup_scr_scr_booting(g);
    bind_booting_lifecycle(g);
    g->scr_base_del = true;
    lv_screen_load_anim(g->scr_booting, LV_SCR_LOAD_ANIM_NONE, time, delay, true);
}

/*
static void ui_context_load_screen_animation(ui_context_t *ui, lv_obj_t **new_scr, bool new_scr_del,
                                             bool *old_scr_del, ui_setup_scr_t setup_scr,
                                             lv_screen_load_anim_t anim_type, uint32_t time,
                                             uint32_t delay, bool is_clean, bool auto_del)
{
    if (!ui || !ui->generated) return;

    ui_load_scr_animation(ui->generated, new_scr, new_scr_del, old_scr_del, setup_scr,
                          anim_type, time, delay, is_clean, auto_del);
}
*/

ui_context_t *ui_context_get(void)
{
    return &s_ui_context;
}

void ui_context_bootstrap(void)
{
    lv_ui *g = s_ui_context.generated;

    if (!g) return;

    setup_bottom_layer();
    init_scr_del_flag(g);
    init_keyboard(g);
    events_init(g);
    load_booting_screen(g, 0, 0);
}

void ui_context_show_booting(ui_context_t *ui)
{
    lv_ui *g;

    if (!ui || !ui->generated) return;

    g = ui->generated;
    load_booting_screen(g, 0, 0);
}

static void ui_context_get_widgets(ui_context_t *ui, ui_widget_refs_t *out)
{
    lv_ui *g;

    if (!out) return;

    memset(out, 0, sizeof(*out));
    if (!ui || !ui->generated) return;

    g = ui->generated;
    out->base_screen = g->scr_base;
    out->booting_screen = g->scr_booting;
    out->keyboard = g->g_kb_top_layer;
    out->logs_container = g->scr_base_cont_logs;
    out->critical_logs_label = g->scr_base_lbl_critical_logs;
    out->clear_history_button = g->scr_base_btn_clear_history;

    out->btn_dashboard = g->scr_base_btn_dashboard;
    out->btn_analysis = g->scr_base_btn_analystis;
    out->btn_event_logs = g->scr_base_btn_event_logs;
    out->btn_settings = g->scr_base_btn_settings;
    out->btn_restart = g->scr_base_btn_restart;
    out->btn_restart_cancel = g->scr_base_btn_restart_cancel;
    out->btn_restart_confirm = g->scr_base_btn_restart_confirm;
    out->btn_restore_confirm = g->scr_base_btn_restore_confirm;
    out->btn_restore_cancel = g->scr_base_btn_restore_cancel;
    out->btn_net = g->scr_base_btn_net;
    out->btn_mqtt = g->scr_base_btn_mqtt;
    out->btn_modbus = g->scr_base_btn_modbus;
    out->btn_sys_admin = g->scr_base_btn_sys_admin;
    out->btn_net_back = g->scr_base_btn_net_back;
    out->btn_mqtt_back = g->scr_base_btn_mqtt_back;
    out->btn_modbus_back = g->scr_base_btn_modbus_back;
    out->btn_sys_back = g->scr_base_btn_sys_back;
    out->btn_restart_system = g->scr_base_btn_restart_system;
    out->btn_factory_reset = g->scr_base_btn_factory_reset;
    out->btn_master_adddevice = g->scr_base_btn_master_adddeivce;
    out->btn_master_viewlist = g->scr_base_btn_masterviewlist;
    out->btn_master_device_apply = g->scr_base_btn_master_device_apply;
    out->btn_deviceconfig_back = g->scr_base_btn_deviceconfig_back;
    out->btn_devicelist_back = g->scr_base_btn_devicelist_back;
    out->btn_generate_report = g->scr_base_btn_generate_report;
    out->btn_wifi_apply = g->scr_base_btn_wifi_apply;
    out->btn_ethernet_apply = g->scr_base_btn_ethernet_apply;
    out->btn_lte_apply = g->scr_base_btn_lte_apply;

    out->cont_dashboard = g->scr_base_cont_dashboard;
    out->cont_analysis = g->scr_base_cont_data_analysis;
    out->cont_event_logs = g->scr_base_cont_event_logs;
    out->cont_hw = g->scr_base_cont_hw;
    out->cont_menu = g->scr_base_cont_menu;
    out->cont_network_config = g->scr_base_cont_networkconfig;
    out->cont_mqtt_config = g->scr_base_cont_mqtt_config;
    out->cont_modbus_config = g->scr_base_cont_modbus_config;
    out->cont_system_admin = g->scr_base_cont_system_admin;
    out->cont_wifi = g->scr_base_cont_wifi;
    out->cont_ethernet = g->scr_base_cont_ethernet;
    out->cont_lte = g->scr_base_cont_lte;
    out->cont_restart = g->scr_base_cont_restart;
    out->cont_restore = g->scr_base_cont_restore;
    out->cont_master = g->scr_base_cont_master;
    out->cont_slave = g->scr_base_cont_slave;
    out->cont_device_config = g->scr_base_cont_device_config;
    out->cont_device_viewlist = g->scr_base_cont_device_viewlist;
    out->cont_mqtt_form = g->scr_base_cont_48;
    out->cont_master_device_form = g->scr_base_cont_63;

    out->ddlist_net_option = g->scr_base_ddlist_net_option;
    out->ddlist_wifi_mode = g->scr_base_ddlist_wifi_mode;
    out->ddlist_ethernet_mode = g->scr_base_ddlist_ethernet_mode;
    out->ddlist_modbus_mode = g->scr_base_ddlist_modbus_mode;

    out->ta[UI_TEXTAREA_WIFI_SSID] = g->scr_base_ta_wifi_ssid;
    out->ta[UI_TEXTAREA_WIFI_PASS] = g->scr_base_ta_wifi_pass;
    out->ta[UI_TEXTAREA_WIFI_IP] = g->scr_base_ta_wifi_ip;
    out->ta[UI_TEXTAREA_ETHERNET_IP] = g->scr_base_ta_ethernet_ip;
    out->ta[UI_TEXTAREA_ETHERNET_SUBNET] = g->scr_base_ta_ethernet_subnet;
    out->ta[UI_TEXTAREA_ETHERNET_GATEWAY] = g->scr_base_ta_ethernet_gateway;
    out->ta[UI_TEXTAREA_LTE_APN] = g->scr_base_ta_lte_apn;
    out->ta[UI_TEXTAREA_LTE_USERNAME] = g->scr_base_ta_lte_username;
    out->ta[UI_TEXTAREA_LTE_PASS] = g->scr_base_ta_lte_pass;
    out->ta[UI_TEXTAREA_LTE_PIN_CODE] = g->scr_base_ta_lte_pin_code;
    out->ta[UI_TEXTAREA_MQTT_HOST] = g->scr_base_ta_mqtt_host;
    out->ta[UI_TEXTAREA_MQTT_PORT] = g->scr_base_ta_mqtt_port;
    out->ta[UI_TEXTAREA_MQTT_USER] = g->scr_base_ta_mqtt_user;
    out->ta[UI_TEXTAREA_MQTT_PASS] = g->scr_base_ta_mqtt_pass;
    out->ta[UI_TEXTAREA_SLAVE_ID] = g->scr_base_ta_slave_id;
    out->ta[UI_TEXTAREA_MASTER_DEVICE_NAME] = NULL;
    out->ta[UI_TEXTAREA_MASTER_DEVICE_SLAVE_ID] = g->scr_base_ta_master_device_slaveid;
    out->ta[UI_TEXTAREA_MASTER_DEVICE_ADDRESS] = g->scr_base_ta_master_device_address;
    out->ta[UI_TEXTAREA_MASTER_DEVICE_LENGTH] = g->scr_base_ta_master_device_quantity;

    out->label_wifi_ip = g->scr_base_label_111;
    out->label_wifi_status = g->scr_base_lbl_wifi_status;
    out->label_ethernet_ip = g->scr_base_label_114;
    out->label_ethernet_subnet = g->scr_base_label_115;
    out->label_ethernet_gateway = g->scr_base_label_116;
}

void ui_context_get_shell_refs(ui_context_t *ui, ui_shell_refs_t *out)
{
    ui_widget_refs_t refs;

    if (!out) return;
    memset(out, 0, sizeof(*out));
    ui_context_get_widgets(ui, &refs);
    out->base_screen = refs.base_screen;
    out->booting_screen = refs.booting_screen;
    out->keyboard = refs.keyboard;
    out->btn_dashboard = refs.btn_dashboard;
    out->btn_analysis = refs.btn_analysis;
    out->btn_event_logs = refs.btn_event_logs;
    out->btn_settings = refs.btn_settings;
}

void ui_context_get_main_view_refs(ui_context_t *ui, ui_main_view_refs_t *out)
{
    ui_widget_refs_t refs;

    if (!out) return;
    memset(out, 0, sizeof(*out));
    ui_context_get_widgets(ui, &refs);
    out->cont_dashboard = refs.cont_dashboard;
    out->cont_analysis = refs.cont_analysis;
    out->cont_event_logs = refs.cont_event_logs;
    out->cont_hw = refs.cont_hw;
}

void ui_context_get_logs_refs(ui_context_t *ui, ui_logs_refs_t *out)
{
    ui_widget_refs_t refs;

    if (!out) return;
    memset(out, 0, sizeof(*out));
    ui_context_get_widgets(ui, &refs);
    out->logs_container = refs.logs_container;
    out->critical_logs_label = refs.critical_logs_label;
    out->clear_history_button = refs.clear_history_button;
}

void ui_context_get_settings_nav_refs(ui_context_t *ui, ui_settings_nav_refs_t *out)
{
    ui_widget_refs_t refs;

    if (!out) return;
    memset(out, 0, sizeof(*out));
    ui_context_get_widgets(ui, &refs);
    out->cont_menu = refs.cont_menu;
    out->cont_network_config = refs.cont_network_config;
    out->cont_mqtt_config = refs.cont_mqtt_config;
    out->cont_modbus_config = refs.cont_modbus_config;
    out->cont_system_admin = refs.cont_system_admin;
    out->btn_net = refs.btn_net;
    out->btn_mqtt = refs.btn_mqtt;
    out->btn_modbus = refs.btn_modbus;
    out->btn_sys_admin = refs.btn_sys_admin;
    out->btn_net_back = refs.btn_net_back;
    out->btn_mqtt_back = refs.btn_mqtt_back;
    out->btn_modbus_back = refs.btn_modbus_back;
    out->btn_sys_back = refs.btn_sys_back;
}

void ui_context_get_network_refs(ui_context_t *ui, ui_network_refs_t *out)
{
    ui_widget_refs_t refs;

    if (!out) return;
    memset(out, 0, sizeof(*out));
    ui_context_get_widgets(ui, &refs);
    out->cont_wifi = refs.cont_wifi;
    out->cont_ethernet = refs.cont_ethernet;
    out->cont_lte = refs.cont_lte;
    out->btn_wifi_apply = refs.btn_wifi_apply;
    out->btn_ethernet_apply = refs.btn_ethernet_apply;
    out->btn_lte_apply = refs.btn_lte_apply;
    out->ddlist_net_option = refs.ddlist_net_option;
    out->ddlist_wifi_mode = refs.ddlist_wifi_mode;
    out->ddlist_ethernet_mode = refs.ddlist_ethernet_mode;
    out->label_wifi_ip = refs.label_wifi_ip;
    out->label_wifi_status = refs.label_wifi_status;
    out->label_ethernet_ip = refs.label_ethernet_ip;
    out->label_ethernet_subnet = refs.label_ethernet_subnet;
    out->label_ethernet_gateway = refs.label_ethernet_gateway;
}

void ui_context_get_mqtt_refs(ui_context_t *ui, ui_mqtt_refs_t *out)
{
    ui_widget_refs_t refs;

    if (!out) return;
    memset(out, 0, sizeof(*out));
    ui_context_get_widgets(ui, &refs);
    out->cont_mqtt_config = refs.cont_mqtt_config;
    out->cont_mqtt_form = refs.cont_mqtt_form;
}

void ui_context_get_modbus_refs(ui_context_t *ui, ui_modbus_refs_t *out)
{
    ui_widget_refs_t refs;

    if (!out) return;
    memset(out, 0, sizeof(*out));
    ui_context_get_widgets(ui, &refs);
    out->cont_modbus_config = refs.cont_modbus_config;
    out->cont_master = refs.cont_master;
    out->cont_slave = refs.cont_slave;
    out->cont_device_config = refs.cont_device_config;
    out->cont_device_viewlist = refs.cont_device_viewlist;
    out->cont_master_device_form = refs.cont_master_device_form;
    out->ddlist_modbus_mode = refs.ddlist_modbus_mode;
    out->btn_master_adddevice = refs.btn_master_adddevice;
    out->btn_master_viewlist = refs.btn_master_viewlist;
    out->btn_master_device_apply = refs.btn_master_device_apply;
    out->btn_deviceconfig_back = refs.btn_deviceconfig_back;
    out->btn_devicelist_back = refs.btn_devicelist_back;
}

void ui_context_get_system_refs(ui_context_t *ui, ui_system_refs_t *out)
{
    ui_widget_refs_t refs;

    if (!out) return;
    memset(out, 0, sizeof(*out));
    ui_context_get_widgets(ui, &refs);
    out->cont_system_admin = refs.cont_system_admin;
    out->cont_restart = refs.cont_restart;
    out->cont_restore = refs.cont_restore;
    out->btn_restart = refs.btn_restart;
    out->btn_restart_cancel = refs.btn_restart_cancel;
    out->btn_restart_confirm = refs.btn_restart_confirm;
    out->btn_restore_confirm = refs.btn_restore_confirm;
    out->btn_restore_cancel = refs.btn_restore_cancel;
    out->btn_restart_system = refs.btn_restart_system;
    out->btn_factory_reset = refs.btn_factory_reset;
    out->btn_generate_report = refs.btn_generate_report;
}

lv_obj_t *ui_context_get_base_screen(ui_context_t *ui)
{
    ui_shell_refs_t refs;

    ui_context_get_shell_refs(ui, &refs);
    return refs.base_screen;
}

lv_obj_t *ui_context_get_keyboard(ui_context_t *ui)
{
    ui_shell_refs_t refs;

    ui_context_get_shell_refs(ui, &refs);
    return refs.keyboard;
}

lv_obj_t *ui_context_get_textarea(ui_context_t *ui, ui_textarea_id_t id)
{
    ui_widget_refs_t refs;

    if ((size_t)id >= ui_context_textarea_count()) return NULL;

    ui_context_get_widgets(ui, &refs);
    return refs.ta[id];
}

size_t ui_context_textarea_count(void)
{
    return (size_t)UI_TEXTAREA_COUNT;
}

lv_obj_t *ui_context_resolve_textarea_container(ui_context_t *ui, lv_obj_t *ta)
{
    ui_widget_refs_t refs;

    if (!ta) return NULL;

    ui_context_get_widgets(ui, &refs);
    if (ta == refs.ta[UI_TEXTAREA_WIFI_SSID] ||
        ta == refs.ta[UI_TEXTAREA_WIFI_PASS] ||
        ta == refs.ta[UI_TEXTAREA_WIFI_IP]) {
        return refs.cont_wifi;
    }
    if (ta == refs.ta[UI_TEXTAREA_ETHERNET_IP] ||
        ta == refs.ta[UI_TEXTAREA_ETHERNET_SUBNET] ||
        ta == refs.ta[UI_TEXTAREA_ETHERNET_GATEWAY]) {
        return refs.cont_ethernet;
    }
    if (ta == refs.ta[UI_TEXTAREA_LTE_APN] ||
        ta == refs.ta[UI_TEXTAREA_LTE_USERNAME] ||
        ta == refs.ta[UI_TEXTAREA_LTE_PASS] ||
        ta == refs.ta[UI_TEXTAREA_LTE_PIN_CODE]) {
        return refs.cont_lte;
    }
    if (ta == refs.ta[UI_TEXTAREA_MQTT_HOST] ||
        ta == refs.ta[UI_TEXTAREA_MQTT_PORT] ||
        ta == refs.ta[UI_TEXTAREA_MQTT_USER] ||
        ta == refs.ta[UI_TEXTAREA_MQTT_PASS]) {
        return refs.cont_mqtt_form;
    }
    if (ta == refs.ta[UI_TEXTAREA_SLAVE_ID]) {
        return refs.cont_slave;
    }
    if (ta == refs.ta[UI_TEXTAREA_MASTER_DEVICE_NAME] ||
        ta == refs.ta[UI_TEXTAREA_MASTER_DEVICE_SLAVE_ID] ||
        ta == refs.ta[UI_TEXTAREA_MASTER_DEVICE_ADDRESS] ||
        ta == refs.ta[UI_TEXTAREA_MASTER_DEVICE_LENGTH]) {
        return refs.cont_master_device_form;
    }

    return lv_obj_get_parent(ta);
}

ui_input_group_t ui_context_classify_input(ui_context_t *ui, lv_obj_t *obj)
{
    ui_widget_refs_t refs;

    if (!obj) return UI_INPUT_GROUP_DEFAULT;

    ui_context_get_widgets(ui, &refs);
    if (obj == refs.ta[UI_TEXTAREA_WIFI_IP]) {
        return UI_INPUT_GROUP_WIFI_STATIC;
    }
    if (obj == refs.ta[UI_TEXTAREA_ETHERNET_IP] ||
        obj == refs.ta[UI_TEXTAREA_ETHERNET_SUBNET] ||
        obj == refs.ta[UI_TEXTAREA_ETHERNET_GATEWAY]) {
        return UI_INPUT_GROUP_ETHERNET_STATIC;
    }

    return UI_INPUT_GROUP_DEFAULT;
}
