#include "ui_screen_controller.h"

#include "ui_events_navigation.h"
#include "ui_input_policy.h"
#include "ui_platform_port.h"
#include "ui_runtime_guard.h"
#include "ui_modbus_list.h"
#include "ui_dashboard.h"
#include "cJSON.h"
#include <string.h>
#include <stdio.h>

#define UI_KEYBOARD_MARGIN 12
#define UI_TOP_SAFE_MARGIN 72

typedef struct {
    ui_context_t *ui;
    lv_obj_t *bound_scr_base;
    ui_runtime_state_t state;
    uint32_t generation;
    lv_obj_t *active_textarea;
    bool keyboard_adjust_pending;
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

static lv_obj_t *get_keyboard(ui_context_t *ui)
{
    lv_obj_t *kb = ui_context_get_keyboard(ui);

    if (!kb || !lv_obj_is_valid(kb)) return NULL;
    return kb;
}

static lv_obj_t *resolve_form_container(ui_context_t *ui, lv_obj_t *ta)
{
    if (!ui || !ta) return NULL;
    return ui_context_resolve_textarea_container(ui, ta);
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
        lv_indev_reset(NULL, s_ctx.active_textarea);
    }

    s_ctx.active_textarea = NULL;
    s_ctx.keyboard_adjust_pending = false;
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

    s_ctx.keyboard_adjust_pending = false;

    if (!is_current_base_object(ta) || !kb) return;
    if (s_ctx.active_textarea != ta) return;
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
    if (s_ctx.keyboard_adjust_pending && s_ctx.active_textarea == ta) return;
    s_ctx.keyboard_adjust_pending = true;
    lv_async_call(adjust_for_keyboard_async, ta);
}

static void textarea_event_cb(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t *ta = lv_event_get_target(e);
    lv_obj_t *kb = get_keyboard(s_ctx.ui);

    if (!is_current_base_object(ta)) return;

    if (code == LV_EVENT_FOCUSED || code == LV_EVENT_CLICKED) {
        if (!ui_input_policy_is_enabled(s_ctx.ui, ta)) {
            dismiss_keyboard();
            return;
        }
        if (kb && lv_indev_active() && lv_indev_get_type(lv_indev_active()) != LV_INDEV_TYPE_KEYPAD) {
            lv_keyboard_set_textarea(kb, ta);
            lv_obj_remove_flag(kb, LV_OBJ_FLAG_HIDDEN);
        }
        s_ctx.active_textarea = ta;
        schedule_keyboard_adjust(ta);
    } else if (code == LV_EVENT_DEFOCUSED || code == LV_EVENT_READY || code == LV_EVENT_CANCEL) {
        reset_input_session(false);
        if (kb) {
            lv_keyboard_set_textarea(kb, NULL);
            lv_obj_add_flag(kb, LV_OBJ_FLAG_HIDDEN);
        }
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
    lv_obj_remove_event_cb(ta, textarea_event_cb);
    bind_cb(ta, textarea_event_cb, LV_EVENT_FOCUSED, NULL);
    bind_cb(ta, textarea_event_cb, LV_EVENT_CLICKED, NULL);
    bind_cb(ta, textarea_event_cb, LV_EVENT_DEFOCUSED, NULL);
    bind_cb(ta, textarea_event_cb, LV_EVENT_READY, NULL);
    bind_cb(ta, textarea_event_cb, LV_EVENT_CANCEL, NULL);
}

static void bind_textareas(ui_context_t *ui)
{
    size_t i;

    for (i = 0; i < ui_context_textarea_count(); ++i) {
        bind_textarea(ui_context_get_textarea(ui, (ui_textarea_id_t)i));
    }
}

static void handle_action_effect(ui_context_t *ui, const ui_runtime_state_t *state, ui_action_effect_t effect)
{
    (void)ui;
    (void)state;
    
    // Todo: Implement JSON packing for other configs (Wifi, LTE, etc.) if needed in the future.
    if (effect == UI_ACTION_EFFECT_REQUEST_RESTART) {
        ui_platform_port_submit_json(UI_PLATFORM_TOPIC_SYSTEM_CONTROL, "{\"cmd\": \"restart\"}");
    } else if (effect == UI_ACTION_EFFECT_REQUEST_FACTORY_RESET) {
        ui_platform_port_submit_json(UI_PLATFORM_TOPIC_SYSTEM_CONTROL, "{\"cmd\": \"factory_reset\"}");
    }
}

static void base_delete_event_cb(lv_event_t *e)
{
    lv_obj_t *obj = lv_event_get_target(e);
    if (obj != s_ctx.bound_scr_base) return;
    ui_screen_controller_exit();
}

static void render_and_reconcile(ui_context_t *ui)
{
    ui_state_apply_controls(ui, &s_ctx.state);
    ui_state_render(ui, &s_ctx.state);
    ui_input_policy_apply(ui, &s_ctx.state);

    if (s_ctx.active_textarea && !ui_input_policy_is_enabled(ui, s_ctx.active_textarea)) {
        reset_input_session(true);
    }
}

void ui_screen_controller_enter(ui_context_t *ui)
{
    ui_shell_refs_t refs;
    lv_obj_t *kb;

    if (!ui) return;
    ui_context_get_shell_refs(ui, &refs);
    if (!is_valid_obj(refs.base_screen)) return;
    if (s_ctx.bound_scr_base == refs.base_screen) return;

    ui_screen_controller_exit();

    s_ctx.ui = ui;
    s_ctx.bound_scr_base = refs.base_screen;
    s_ctx.generation++;

    ui_state_init_defaults(&s_ctx.state);
    (void)ui_platform_port_load_initial_state(&s_ctx.state);
    ui_input_policy_bind(ui);
    ui_events_navigation_init(ui);
    bind_textareas(ui);

    kb = get_keyboard(ui);
    if (kb) {
        lv_obj_remove_event_cb(kb, keyboard_event_cb);
        bind_cb(kb, keyboard_event_cb, LV_EVENT_ALL, NULL);
    }
    bind_cb(refs.base_screen, base_delete_event_cb, LV_EVENT_DELETE, NULL);

    render_and_reconcile(ui);
    ui_runtime_guard_mark_bound(refs.base_screen);
}

void ui_screen_controller_exit(void)
{
    reset_input_session(true);
    ui_input_policy_unbind();
    s_ctx.bound_scr_base = NULL;
    s_ctx.ui = NULL;
}

void ui_screen_controller_dispatch(ui_context_t *ui, ui_action_t action, uint16_t value)
{
    lv_obj_t *base_screen;
    ui_action_effect_t effect;

    if (!ui) return;

    base_screen = ui_context_get_base_screen(ui);
    if (!is_valid_obj(base_screen)) return;
    if (s_ctx.bound_scr_base != base_screen) ui_screen_controller_enter(ui);

    reset_input_session(true);

    /* Intercept Apply Modbus Device to read form fields before state dispatch */
    if (action == UI_ACTION_APPLY_MODBUS_DEVICE) {
        ui_modbus_list_handle_apply(ui);
    }

    effect = ui_state_dispatch(&s_ctx.state, action, value);
    render_and_reconcile(ui);
    handle_action_effect(ui, &s_ctx.state, effect);
}

void ui_screen_controller_restore_input(void)
{
    reset_input_session(true);
}

void ui_screen_controller_apply_json(ui_frontend_topic_t topic, const char *json_payload)
{
    if (!json_payload) return;

    cJSON *root = cJSON_Parse(json_payload);
    if (!root) return;

    switch (topic) {
        case UI_FRONTEND_TOPIC_SENSOR_DATA:
            ui_dashboard_apply_json(root);
            break;
        case UI_FRONTEND_TOPIC_SYSTEM_STATUS:
            // Placeholder for parsing status JSON if needed
            break;
        default:
            break;
    }

    cJSON_Delete(root);
    
    if (s_ctx.ui) {
        render_and_reconcile(s_ctx.ui);
    }
}
