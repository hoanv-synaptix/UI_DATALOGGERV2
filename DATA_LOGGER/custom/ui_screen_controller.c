#include "ui_screen_controller.h"

#include "ui_events_navigation.h"
#include "ui_input_policy.h"
#include "ui_runtime_guard.h"

#define UI_KEYBOARD_MARGIN 12
#define UI_TOP_SAFE_MARGIN 72

typedef struct {
    lv_ui *ui;
    lv_obj_t *bound_scr_base;
    ui_runtime_state_t state;
    uint32_t generation;
    lv_obj_t *active_textarea;
    lv_obj_t *shifted_container;
    lv_coord_t shifted_original_y;
} ui_screen_controller_ctx_t;

static ui_screen_controller_ctx_t s_ctx;

static bool is_valid_obj(lv_obj_t *obj)
{
    return obj && lv_obj_is_valid(obj);
}

static bool is_current_base_object(lv_obj_t *obj)
{
    if (!is_valid_obj(obj) || !is_valid_obj(s_ctx.bound_scr_base)) return false;
    return lv_obj_get_screen(obj) == s_ctx.bound_scr_base;
}

static lv_obj_t *get_keyboard(lv_ui *ui)
{
    if (!ui || !ui->g_kb_top_layer || !lv_obj_is_valid(ui->g_kb_top_layer)) return NULL;
    return ui->g_kb_top_layer;
}

static lv_obj_t *resolve_form_container(lv_ui *ui, lv_obj_t *ta)
{
    if (!ui || !ta) return NULL;

    if (ta == ui->scr_base_ta_wifi_ssid || ta == ui->scr_base_ta_wifi_pass || ta == ui->scr_base_ta_wifi_ip) {
        return ui->scr_base_cont_wifi;
    }
    if (ta == ui->scr_base_ta_ethernet_ip || ta == ui->scr_base_ta_ethernet_subnet || ta == ui->scr_base_ta_ethernet_gateway) {
        return ui->scr_base_cont_ethernet;
    }
    if (ta == ui->scr_base_ta_lte_apn || ta == ui->scr_base_ta_lte_username || ta == ui->scr_base_ta_lte_pass || ta == ui->scr_base_ta_lte_pin_code) {
        return ui->scr_base_cont_lte;
    }
    if (ta == ui->scr_base_ta_mqtt_host || ta == ui->scr_base_ta_mqtt_port || ta == ui->scr_base_ta_mqtt_user || ta == ui->scr_base_ta_mqtt_pass) {
        return ui->scr_base_cont_48;
    }
    if (ta == ui->scr_base_ta_slave_id) {
        return ui->scr_base_cont_slave;
    }
    if (ta == ui->scr_base_ta_master_device_name || ta == ui->scr_base_ta_master_device_slaveid ||
        ta == ui->scr_base_ta_master_device_address || ta == ui->scr_base_ta_master_device_length) {
        return ui->scr_base_cont_63;
    }

    return lv_obj_get_parent(ta);
}

static void restore_shifted_container(void)
{
    if (!is_valid_obj(s_ctx.shifted_container)) {
        s_ctx.shifted_container = NULL;
        return;
    }

    lv_obj_set_y(s_ctx.shifted_container, s_ctx.shifted_original_y);
    s_ctx.shifted_container = NULL;
}

static void dismiss_keyboard(void)
{
    lv_obj_t *kb = get_keyboard(s_ctx.ui);

    if (kb) {
        lv_keyboard_set_textarea(kb, NULL);
        lv_obj_add_flag(kb, LV_OBJ_FLAG_HIDDEN);
    }

    if (is_valid_obj(s_ctx.active_textarea)) {
        lv_obj_remove_state(s_ctx.active_textarea, LV_STATE_FOCUSED);
        lv_indev_reset(NULL, s_ctx.active_textarea);
    }

    s_ctx.active_textarea = NULL;
}

static void reset_input_session(bool dismiss)
{
    restore_shifted_container();
    if (dismiss) dismiss_keyboard();
}

static void adjust_for_keyboard_async(void *user_data)
{
    lv_obj_t *ta = (lv_obj_t *)user_data;
    lv_obj_t *kb = get_keyboard(s_ctx.ui);
    lv_obj_t *container;
    lv_area_t ta_area;
    lv_area_t kb_area;
    lv_area_t container_area;
    lv_coord_t overlap;
    lv_coord_t max_up;
    lv_coord_t shift;

    if (!is_current_base_object(ta) || !kb) return;
    if (lv_obj_has_flag(kb, LV_OBJ_FLAG_HIDDEN)) return;
    if (!ui_input_policy_is_enabled(s_ctx.ui, ta)) return;

    container = resolve_form_container(s_ctx.ui, ta);
    if (!is_current_base_object(container)) return;

    if (s_ctx.shifted_container != container) {
        restore_shifted_container();
        s_ctx.shifted_container = container;
        s_ctx.shifted_original_y = lv_obj_get_y(container);
    }

    lv_obj_update_layout(s_ctx.bound_scr_base);
    lv_obj_get_coords(ta, &ta_area);
    lv_obj_get_coords(kb, &kb_area);
    lv_obj_get_coords(container, &container_area);

    overlap = (ta_area.y2 + UI_KEYBOARD_MARGIN) - kb_area.y1;
    if (overlap <= 0) return;

    max_up = container_area.y1 - UI_TOP_SAFE_MARGIN;
    if (max_up < 0) max_up = 0;
    shift = overlap > max_up ? max_up : overlap;
    lv_obj_set_y(container, s_ctx.shifted_original_y - shift);
}

static void schedule_keyboard_adjust(lv_obj_t *ta)
{
    if (!is_current_base_object(ta)) return;
    lv_async_call(adjust_for_keyboard_async, ta);
}

static void textarea_event_cb(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t *ta = lv_event_get_target(e);

    if (!is_current_base_object(ta)) return;

    if (code == LV_EVENT_FOCUSED || code == LV_EVENT_CLICKED) {
        if (!ui_input_policy_is_enabled(s_ctx.ui, ta)) {
            dismiss_keyboard();
            return;
        }
        s_ctx.active_textarea = ta;
        schedule_keyboard_adjust(ta);
    } else if (code == LV_EVENT_DEFOCUSED || code == LV_EVENT_READY || code == LV_EVENT_CANCEL) {
        reset_input_session(false);
        if (s_ctx.active_textarea == ta) s_ctx.active_textarea = NULL;
    }
}

static void keyboard_event_cb(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t *kb = lv_event_get_target(e);
    lv_obj_t *ta;

    if (!kb || !lv_obj_is_valid(kb)) return;

    ta = lv_keyboard_get_textarea(kb);
    if (ta && !is_current_base_object(ta)) {
        dismiss_keyboard();
        return;
    }

    if (code == LV_EVENT_READY || code == LV_EVENT_CANCEL) {
        reset_input_session(false);
        s_ctx.active_textarea = NULL;
    }
}

static void bind_cb(lv_obj_t *obj, lv_event_cb_t cb, lv_event_code_t code, void *user_data)
{
    if (!obj || !lv_obj_is_valid(obj)) return;
    lv_obj_remove_event_cb_with_user_data(obj, cb, user_data);
    lv_obj_add_event_cb(obj, cb, code, user_data);
}

static void bind_textarea(lv_obj_t *ta)
{
    if (!is_valid_obj(ta)) return;
    bind_cb(ta, textarea_event_cb, LV_EVENT_FOCUSED, NULL);
    bind_cb(ta, textarea_event_cb, LV_EVENT_CLICKED, NULL);
    bind_cb(ta, textarea_event_cb, LV_EVENT_DEFOCUSED, NULL);
    bind_cb(ta, textarea_event_cb, LV_EVENT_READY, NULL);
    bind_cb(ta, textarea_event_cb, LV_EVENT_CANCEL, NULL);
}

static void bind_textareas(lv_ui *ui)
{
    bind_textarea(ui->scr_base_ta_wifi_ssid);
    bind_textarea(ui->scr_base_ta_wifi_pass);
    bind_textarea(ui->scr_base_ta_wifi_ip);
    bind_textarea(ui->scr_base_ta_ethernet_ip);
    bind_textarea(ui->scr_base_ta_ethernet_subnet);
    bind_textarea(ui->scr_base_ta_ethernet_gateway);
    bind_textarea(ui->scr_base_ta_lte_apn);
    bind_textarea(ui->scr_base_ta_lte_username);
    bind_textarea(ui->scr_base_ta_lte_pass);
    bind_textarea(ui->scr_base_ta_lte_pin_code);
    bind_textarea(ui->scr_base_ta_mqtt_host);
    bind_textarea(ui->scr_base_ta_mqtt_port);
    bind_textarea(ui->scr_base_ta_mqtt_user);
    bind_textarea(ui->scr_base_ta_mqtt_pass);
    bind_textarea(ui->scr_base_ta_slave_id);
    bind_textarea(ui->scr_base_ta_master_device_name);
    bind_textarea(ui->scr_base_ta_master_device_slaveid);
    bind_textarea(ui->scr_base_ta_master_device_address);
    bind_textarea(ui->scr_base_ta_master_device_length);
}

static void base_delete_event_cb(lv_event_t *e)
{
    lv_obj_t *obj = lv_event_get_target(e);
    if (obj != s_ctx.bound_scr_base) return;
    ui_screen_controller_exit();
}

static void render_and_reconcile(lv_ui *ui)
{
    ui_state_render(ui, &s_ctx.state);
    ui_input_policy_apply(ui, &s_ctx.state);

    if (s_ctx.active_textarea && !ui_input_policy_is_enabled(ui, s_ctx.active_textarea)) {
        reset_input_session(true);
    }
}

void ui_screen_controller_enter(lv_ui *ui)
{
    lv_obj_t *kb;

    if (!ui || !is_valid_obj(ui->scr_base)) return;
    if (s_ctx.bound_scr_base == ui->scr_base) return;

    ui_screen_controller_exit();

    s_ctx.ui = ui;
    s_ctx.bound_scr_base = ui->scr_base;
    s_ctx.generation++;

    ui_state_init_defaults(&s_ctx.state);
    ui_state_sync_from_widgets(&s_ctx.state, ui);
    ui_input_policy_bind(ui);
    ui_events_navigation_init(ui);
    bind_textareas(ui);

    kb = get_keyboard(ui);
    if (kb) bind_cb(kb, keyboard_event_cb, LV_EVENT_ALL, NULL);
    bind_cb(ui->scr_base, base_delete_event_cb, LV_EVENT_DELETE, NULL);

    render_and_reconcile(ui);
    ui_runtime_guard_mark_bound(ui->scr_base);
}

void ui_screen_controller_exit(void)
{
    reset_input_session(true);
    ui_input_policy_unbind();
    s_ctx.bound_scr_base = NULL;
    s_ctx.ui = NULL;
}

void ui_screen_controller_dispatch(lv_ui *ui, ui_action_t action, uint16_t value)
{
    ui_action_effect_t effect;

    if (!ui || !is_valid_obj(ui->scr_base)) return;
    if (s_ctx.bound_scr_base != ui->scr_base) ui_screen_controller_enter(ui);

    reset_input_session(true);
    effect = ui_state_dispatch(&s_ctx.state, action, value);
    render_and_reconcile(ui);

    if (effect == UI_ACTION_EFFECT_REBOOT) {
        ui_screen_controller_exit();
        ui_load_scr_animation(ui, &ui->scr_booting, ui->scr_booting_del, &ui->scr_base_del,
                              setup_scr_scr_booting, LV_SCR_LOAD_ANIM_NONE, 0, 0, false, true);
    }
}

void ui_screen_controller_restore_input(void)
{
    reset_input_session(true);
}
