#include "ctrl_screen.h"

#include "ctrl_navigation.h"
#include "ctrl_input.h"
#include "ui_pub.h"
#include "ui_runtime_guard.h"
#include "cmp_modbus_list.h"
#include "cmp_dashboard.h"
#include "modbus_config_service.h"
#include "ui_form_read.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "cJSON.h"

#define UI_KEYBOARD_MARGIN 12
#define UI_TOP_SAFE_MARGIN 72

/**
 * @struct ui_screen_controller_ctx_t
 * @brief Context lưu trữ trạng thái hoạt động của toàn bộ Controller
 */
typedef struct {
    view_factory_t *ui;                 /**< Con trỏ tới nhà máy chứa các Widget LVGL */
    lv_obj_t *bound_scr_base;           /**< Màn hình Base hiện tại đang gắn Controller */
    ui_runtime_state_t state;           /**< Bộ State Machine của toàn ứng dụng */
    uint32_t generation;                /**< Biến đếm số lần Controller khởi động */
} ui_screen_controller_ctx_t;

static ui_screen_controller_ctx_t s_ctx;

static bool is_valid_obj(lv_obj_t *obj)
{
    return obj && lv_obj_is_valid(obj);
}


static void bind_cb(lv_obj_t *obj, lv_event_cb_t cb, lv_event_code_t code, void *user_data)
{
    if (!obj || !lv_obj_is_valid(obj)) return;
    lv_obj_remove_event_cb_with_user_data(obj, cb, user_data);
    lv_obj_add_event_cb(obj, cb, code, user_data);
}

static lv_timer_t *s_login_timer = NULL;
static lv_timer_t *s_secure_timer = NULL;

static void login_success_timer_cb(lv_timer_t * t)
{
    view_factory_t *ui = s_ctx.ui;
    if (!ui) {
        s_login_timer = NULL;
        lv_timer_del(t);
        return;
    }
    ui_login_refs_t login_refs;

    lv_textarea_set_text(view_factory_get_textarea(ui, UI_TEXTAREA_LOGIN_USER), "");
    lv_textarea_set_text(view_factory_get_textarea(ui, UI_TEXTAREA_LOGIN_PASS), "");
    view_factory_get_login_refs(ui, &login_refs);
    lv_label_set_text(login_refs.lbl_login_booting_status, "Enter password to access settings.");
    lv_obj_set_style_text_color(login_refs.lbl_login_booting_status, lv_color_hex(0xABABAB), 0);
    
    ui_screen_controller_dispatch(ui, UI_ACTION_SHOW_DASHBOARD, 0);
    s_login_timer = NULL;
    lv_timer_del(t);
}

static void secure_settings_success_timer_cb(lv_timer_t * t)
{
    view_factory_t *ui = s_ctx.ui;
    if (!ui) {
        s_secure_timer = NULL;
        lv_timer_del(t);
        return;
    }

    lv_textarea_set_text(view_factory_get_textarea(ui, UI_TEXTAREA_SECURE_SETTINGS_PASS), "");
    
    ui_screen_controller_dispatch(ui, UI_ACTION_SHOW_SETTINGS_MENU, 0);
    s_secure_timer = NULL;
    lv_timer_del(t);
}

static void handle_action_effect(view_factory_t *ui, const ui_runtime_state_t *state, ui_action_effect_t effect)
{
    (void)state; /* accessed via s_ctx.state */
    if (effect == UI_ACTION_EFFECT_REQUEST_RESTART) {
        ui_pub_submit_json(PUB_TOPIC_SYS_CTRL, "{\"cmd\": \"restart\"}");
    } else if (effect == UI_ACTION_EFFECT_REQUEST_FACTORY_RESET) {
        ui_pub_submit_json(PUB_TOPIC_SYS_CTRL, "{\"cmd\": \"factory_reset\"}");
    } else if (effect == UI_ACTION_EFFECT_SUBMIT_GENERATE_REPORT) {
        ui_pub_submit_json(PUB_TOPIC_SYS_CTRL, "{\"cmd\": \"generate_report\"}");
    } else if (effect == UI_ACTION_EFFECT_LOGIN_SUCCESS) {
        if (!s_login_timer) s_login_timer = lv_timer_create(login_success_timer_cb, 1000, ui);
    } else if (effect == UI_ACTION_EFFECT_SECURE_SETTINGS_SUCCESS) {
        if (!s_secure_timer) s_secure_timer = lv_timer_create(secure_settings_success_timer_cb, 1000, ui);
    } else if (effect == UI_ACTION_EFFECT_SUBMIT_MODBUS_DEVICE) {
        modbus_config_sync_to_firmware();
    } else if (effect == UI_ACTION_EFFECT_SUBMIT_MQTT_CONFIG) {
        char *json = ui_form_read_mqtt(ui);
        if (json) {
            // Validation Pass
            s_ctx.state.live.mqtt_status = UI_CONNECTION_STATUS_CONNECTING;
            ui_pub_submit_json(PUB_TOPIC_MQTT, json);
            cJSON_free(json);
        } else {
            // Validation Fail -> Đổi status thành Lỗi (Màu Đỏ)
            s_ctx.state.live.mqtt_status = UI_CONNECTION_STATUS_ERROR;
        }
        // Kích hoạt render lại nhãn lbl_status
        ui_state_render(ui, &s_ctx.state);
    } else if (effect == UI_ACTION_EFFECT_SUBMIT_WIFI_CONFIG) {
        char *json = ui_form_read_wifi(ui);
        if (json) {
            s_ctx.state.live.wifi_status = UI_CONNECTION_STATUS_CONNECTING;
            ui_pub_submit_json(PUB_TOPIC_WIFI, json);
            cJSON_free(json);
        } else {
            s_ctx.state.live.wifi_status = UI_CONNECTION_STATUS_ERROR;
        }
        ui_state_render(ui, &s_ctx.state);
    } else if (effect == UI_ACTION_EFFECT_SUBMIT_ETHERNET_CONFIG) {
        char *json = ui_form_read_ethernet(ui);
        if (json) {
            s_ctx.state.live.ethernet_status = UI_CONNECTION_STATUS_CONNECTING;
            ui_pub_submit_json(PUB_TOPIC_ETHERNET, json);
            cJSON_free(json);
        } else {
            s_ctx.state.live.ethernet_status = UI_CONNECTION_STATUS_ERROR;
        }
        ui_state_render(ui, &s_ctx.state);
    } else if (effect == UI_ACTION_EFFECT_SUBMIT_LTE_CONFIG) {
        char *json = ui_form_read_lte(ui);
        if (json) {
            s_ctx.state.live.lte_status = UI_CONNECTION_STATUS_CONNECTING;
            ui_pub_submit_json(PUB_TOPIC_LTE, json);
            cJSON_free(json);
        } else {
            s_ctx.state.live.lte_status = UI_CONNECTION_STATUS_ERROR;
        }
        ui_state_render(ui, &s_ctx.state);
    } else if (effect == UI_ACTION_EFFECT_SUBMIT_MODBUS_CONFIG) {
        modbus_config_sync_to_firmware();
    }
}

static void base_delete_event_cb(lv_event_t *e)
{
    lv_obj_t *obj = lv_event_get_target(e);
    if (obj != s_ctx.bound_scr_base) return;
    ui_screen_controller_exit();
}

/**
 * @brief Vòng lặp Render chính của UI (Single source of truth)
 */
static void render_and_reconcile(view_factory_t *ui)
{
    // Cập nhật giá trị lên các widget (Switch, Dropdown)
    ui_state_apply_controls(ui, &s_ctx.state);
    
    // Ẩn/Hiện các View dựa vào Logic
    ui_state_render(ui, &s_ctx.state);
    
    // Áp dụng các quy định về khóa nhập liệu (Vô hiệu hóa nút bấm nếu không đủ quyền)
    ui_input_policy_apply(ui, &s_ctx.state);
}

void ui_screen_controller_enter(view_factory_t *ui)
{
    ui_shell_refs_t refs;

    if (!ui) return;
    view_factory_get_shell_refs(ui, &refs);
    if (!is_valid_obj(refs.base_screen)) return;
    if (s_ctx.bound_scr_base == refs.base_screen) return; // Đã bind rồi

    ui_screen_controller_exit(); // Dọn dẹp cái cũ (nếu có)

    s_ctx.ui = ui;
    s_ctx.bound_scr_base = refs.base_screen;
    s_ctx.generation++;

    // 1. Khởi tạo State Machine
    ui_state_init_defaults(&s_ctx.state);
    
    // 2. Yêu cầu Firmware cấp State khởi tạo (nếu có lưu cấu hình cũ trong Flash)
    (void)ui_pub_load_initial_state(&s_ctx.state);
    
    // 3. Khởi tạo quyền điều khiển và Navigation (Sự kiện Nút bấm)
    ui_input_policy_init_constraints(ui);
    ui_input_policy_bind(ui);
    ui_events_navigation_init(ui);
    
    bind_cb(refs.base_screen, base_delete_event_cb, LV_EVENT_DELETE, NULL);

    // 5. Tiến hành Render màn hình lần đầu tiên
    render_and_reconcile(ui);
    
    ui_runtime_guard_mark_bound(refs.base_screen);
}

void ui_screen_controller_exit(void)
{
    ui_input_policy_unbind();

    if (s_login_timer) {
        lv_timer_del(s_login_timer);
        s_login_timer = NULL;
    }
    if (s_secure_timer) {
        lv_timer_del(s_secure_timer);
        s_secure_timer = NULL;
    }

    view_factory_invalidate_cache();

    s_ctx.bound_scr_base = NULL;
    s_ctx.ui = NULL;
}

void ui_screen_controller_dispatch(view_factory_t *ui, ui_action_t action, uint16_t value)
{
    lv_obj_t *base_screen;
    ui_action_effect_t effect;

    if (!ui) return;

    base_screen = view_factory_get_base_screen(ui);
    if (!is_valid_obj(base_screen)) return;
    if (s_ctx.bound_scr_base != base_screen) ui_screen_controller_enter(ui);

    /* Chặn sự kiện Apply Modbus để lấy dữ liệu Text Input trước khi State Machine chuyển màn hình */
    if (action == UI_ACTION_APPLY_MODBUS_DEVICE) {
        cmp_modbus_list_handle_apply(ui);
    }

    // 1. Chuyển cho State Machine tính toán Logical State
    effect = ui_state_dispatch(&s_ctx.state, action, value);
    
    // 2. Render lại toàn bộ UI dựa trên State mới
    render_and_reconcile(ui);
    
    // 3. Thực thi các tác vụ (Side-Effect) như gọi hàm Restart, Cập nhật WiFi
    handle_action_effect(ui, &s_ctx.state, effect);
}

void ui_screen_controller_restore_input(void)
{
}

void ui_screen_controller_apply_sensor_data(const struct ui_sensor_data_t *data)
{
    if (!data) return;
    cmp_dashboard_apply_data(data);
    /* Chỉ vẽ lại phần Dashboard — tránh full re-render navigation/layout */
    cmp_dashboard_render(s_ctx.state.main_view == UI_MAIN_VIEW_DASHBOARD);
}
