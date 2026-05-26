#include "keyboard_avoidance.h"
#include "gui_guider.h"

extern lv_ui guider_ui;
static lv_obj_t * last_scr_base = NULL;

static void custom_ta_event_handler(lv_event_t * e) {
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
    lv_obj_t * kb = guider_ui.g_kb_top_layer;

    if(!kb) return;

    if(code == LV_EVENT_FOCUSED) {
        lv_coord_t kb_h = lv_obj_get_height(kb);
        if(kb_h <= 0) kb_h = 240;

        lv_obj_t * scr = lv_scr_act();
        lv_obj_add_flag(scr, LV_OBJ_FLAG_SCROLLABLE);
        lv_obj_set_style_pad_bottom(scr, kb_h + 20, 0);
        lv_obj_update_layout(scr);
        
        lv_obj_scroll_to_view_recursive(ta, LV_ANIM_ON);

    } else if(code == LV_EVENT_DEFOCUSED || code == LV_EVENT_CANCEL || code == LV_EVENT_READY) {
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

static void apply_keyboard_avoidance(void) {
    lv_obj_t * tas[] = {
        guider_ui.scr_base_ta_wifi_ssid,
        guider_ui.scr_base_ta_wifi_pass,
        guider_ui.scr_base_ta_wifi_ip,
        guider_ui.scr_base_ta_ethernet_ip,
        guider_ui.scr_base_ta_ethernet_subnet,
        guider_ui.scr_base_ta_ethernet_gateway,
        guider_ui.scr_base_ta_lte_apn,
        guider_ui.scr_base_ta_lte_username,
        guider_ui.scr_base_ta_lte_pass,
        guider_ui.scr_base_ta_lte_pin_code,
        guider_ui.scr_base_ta_mqtt_host,
        guider_ui.scr_base_ta_mqtt_port,
        guider_ui.scr_base_ta_mqtt_user,
        guider_ui.scr_base_ta_mqtt_pass,
        guider_ui.scr_base_ta_slave_id,
        guider_ui.scr_base_ta_master_device_slaveid,
        guider_ui.scr_base_ta_master_device_address,
        guider_ui.scr_base_ta_master_device_quantity,
    };
    
    for (size_t i = 0; i < sizeof(tas)/sizeof(tas[0]); i++) {
        if(tas[i] && lv_obj_is_valid(tas[i])) {
            lv_obj_add_event_cb(tas[i], custom_ta_event_handler, LV_EVENT_FOCUSED, NULL);
            lv_obj_add_event_cb(tas[i], custom_ta_event_handler, LV_EVENT_DEFOCUSED, NULL);
            lv_obj_add_event_cb(tas[i], custom_ta_event_handler, LV_EVENT_CANCEL, NULL);
            lv_obj_add_event_cb(tas[i], custom_ta_event_handler, LV_EVENT_READY, NULL);
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
