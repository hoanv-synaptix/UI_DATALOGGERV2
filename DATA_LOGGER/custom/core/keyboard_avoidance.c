#include "keyboard_avoidance.h"
#include "gui_guider.h"
#include "widgets_init.h"
#include "view_factory.h"
#include <string.h>

extern lv_ui guider_ui;
static lv_obj_t * last_scr_base = NULL;
static bool kb_event_bound = false;

static void custom_kb_event_handler(lv_event_t * e) {
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * kb = lv_event_get_target(e);
    if(code == LV_EVENT_READY || code == LV_EVENT_CANCEL) {
        lv_obj_t * ta = lv_keyboard_get_textarea(kb);
        if(ta && lv_obj_is_valid(ta)) {
            lv_obj_clear_state(ta, LV_STATE_FOCUSED);
        }
    }
}

static lv_keyboard_mode_t get_keyboard_mode_for_ta(ui_textarea_id_t id) {
    switch(id) {
        /* NUMBER: Chỉ hiện phím số và dấu chấm */
        case UI_TEXTAREA_MQTT_PORT:
        case UI_TEXTAREA_SLAVE_ID:
        case UI_TEXTAREA_MASTER_DEVICE_SLAVEID:
        case UI_TEXTAREA_MASTER_DEVICE_ADDRESS:
        case UI_TEXTAREA_MASTER_DEVICE_QUANTITY:
        case UI_TEXTAREA_MASTER_DEVICE_REMAP:
        case UI_TEXTAREA_LTE_PIN_CODE:
        case UI_TEXTAREA_WIFI_IP:
        case UI_TEXTAREA_WIFI_SUBNET:
        case UI_TEXTAREA_WIFI_GATEWAY:
        case UI_TEXTAREA_ETHERNET_IP:
        case UI_TEXTAREA_ETHERNET_SUBNET:
        case UI_TEXTAREA_ETHERNET_GATEWAY:
            return LV_KEYBOARD_MODE_NUMBER;

        /* QWERTY: Chữ thường, chữ hoa, ký tự */
        case UI_TEXTAREA_MASTER_DEVICE_NAME:
        case UI_TEXTAREA_WIFI_SSID:
        case UI_TEXTAREA_WIFI_PASS:
        case UI_TEXTAREA_LTE_APN:
        case UI_TEXTAREA_LTE_USERNAME:
        case UI_TEXTAREA_LTE_PASS:
        case UI_TEXTAREA_MQTT_HOST:
        case UI_TEXTAREA_MQTT_USER:
        case UI_TEXTAREA_MQTT_PASS:
        case UI_TEXTAREA_LOGIN_USER:
        case UI_TEXTAREA_LOGIN_PASS:
        case UI_TEXTAREA_SECURE_SETTINGS_PASS:
        default:
            return LV_KEYBOARD_MODE_TEXT_LOWER;
    }
}

static void custom_ta_event_handler(lv_event_t * e) {
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
    lv_obj_t * kb = guider_ui.g_kb_top_layer;
    ui_textarea_id_t * id_ptr = (ui_textarea_id_t *)lv_event_get_user_data(e);

    if(!kb) return;

    if(code == LV_EVENT_FOCUSED) {
        if(id_ptr) {
            lv_keyboard_set_mode(kb, get_keyboard_mode_for_ta(*id_ptr));
        } else {
            lv_keyboard_set_mode(kb, LV_KEYBOARD_MODE_TEXT_LOWER);
        }
        
        lv_keyboard_set_textarea(kb, ta);
        lv_obj_remove_flag(kb, LV_OBJ_FLAG_HIDDEN);

        lv_coord_t kb_h = lv_obj_get_height(kb);
        if(kb_h <= 0) kb_h = 240;

        lv_obj_t * scr = lv_scr_act();
        lv_obj_add_flag(scr, LV_OBJ_FLAG_SCROLLABLE);
        lv_obj_set_style_pad_bottom(scr, kb_h + 20, 0);
        lv_obj_update_layout(scr);
        
        lv_obj_scroll_to_view_recursive(ta, LV_ANIM_ON);

    } else if(code == LV_EVENT_DEFOCUSED || code == LV_EVENT_CANCEL || code == LV_EVENT_READY) {
        lv_keyboard_set_textarea(kb, NULL);
        lv_obj_add_flag(kb, LV_OBJ_FLAG_HIDDEN);

        lv_obj_t * scr = lv_scr_act();
        // Trượt về toạ độ gốc ngay lập tức (không dùng animation) để tránh lòi nền trắng
        lv_obj_scroll_to(scr, 0, 0, LV_ANIM_OFF);
        // Xoá khoảng đệm
        lv_obj_set_style_pad_bottom(scr, 0, 0);
        // Khoá không cho cuộn nữa
        lv_obj_clear_flag(scr, LV_OBJ_FLAG_SCROLLABLE);
        // Cập nhật lại layout
        lv_obj_update_layout(scr);
    }
}

// Lưu trữ ID để gán vào event user_data (vì con trỏ cần bộ nhớ tĩnh/heap)
static ui_textarea_id_t ta_ids[UI_TEXTAREA_COUNT];

static void apply_keyboard_avoidance(void) {
    if (!kb_event_bound && guider_ui.g_kb_top_layer) {
        lv_obj_add_event_cb(guider_ui.g_kb_top_layer, custom_kb_event_handler, LV_EVENT_READY, NULL);
        lv_obj_add_event_cb(guider_ui.g_kb_top_layer, custom_kb_event_handler, LV_EVENT_CANCEL, NULL);
        kb_event_bound = true;
    }

    view_factory_t * ui = view_factory_get();
    size_t count = view_factory_textarea_count();

    for (size_t i = 0; i < count; i++) {
        lv_obj_t * ta = view_factory_get_textarea(ui, (ui_textarea_id_t)i);
        if(ta && lv_obj_is_valid(ta)) {
            ta_ids[i] = (ui_textarea_id_t)i;
            
            // Xóa triệt để sự kiện của GUI Guider để chống "chồng lấn phím"
            lv_obj_remove_event_cb(ta, ta_event_cb);
            
            // Xóa sự kiện custom cũ (nếu có) để không bị lặp
            lv_obj_remove_event_cb(ta, custom_ta_event_handler);

            lv_obj_add_event_cb(ta, custom_ta_event_handler, LV_EVENT_FOCUSED, &ta_ids[i]);
            lv_obj_add_event_cb(ta, custom_ta_event_handler, LV_EVENT_DEFOCUSED, &ta_ids[i]);
            lv_obj_add_event_cb(ta, custom_ta_event_handler, LV_EVENT_CANCEL, &ta_ids[i]);
            lv_obj_add_event_cb(ta, custom_ta_event_handler, LV_EVENT_READY, &ta_ids[i]);
        }
    }
}

static void kb_poll_timer_cb(lv_timer_t * t) {
    if (guider_ui.scr_base && lv_obj_is_valid(guider_ui.scr_base)) {
        if (guider_ui.scr_base != last_scr_base) {
            last_scr_base = guider_ui.scr_base;
            apply_keyboard_avoidance();
        }
    } else {
        last_scr_base = NULL;
    }
}

void keyboard_avoidance_init(void) {
    lv_timer_create(kb_poll_timer_cb, 500, NULL);
}
