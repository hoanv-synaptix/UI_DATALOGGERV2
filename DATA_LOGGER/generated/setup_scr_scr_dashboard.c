/*
* Copyright 2026 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#include "lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"
#include "widgets_init.h"
#include "custom.h"



int scr_dashboard_time_val_min_value = 25;
int scr_dashboard_time_val_hour_value = 11;
int scr_dashboard_time_val_sec_value = 50;
void setup_scr_scr_dashboard(lv_ui *ui)
{
    //Write codes scr_dashboard
    ui->scr_dashboard = lv_obj_create(NULL);
    lv_obj_set_size(ui->scr_dashboard, 800, 480);
    lv_obj_set_scrollbar_mode(ui->scr_dashboard, LV_SCROLLBAR_MODE_OFF);

    //Write style for scr_dashboard, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->scr_dashboard, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_dashboard_img_bg
    ui->scr_dashboard_img_bg = lv_image_create(ui->scr_dashboard);
    lv_obj_set_pos(ui->scr_dashboard_img_bg, 0, 0);
    lv_obj_set_size(ui->scr_dashboard_img_bg, 800, 480);
    lv_obj_add_flag(ui->scr_dashboard_img_bg, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->scr_dashboard_img_bg, &_bg_settings_base_RGB565A8_800x480);
    lv_image_set_pivot(ui->scr_dashboard_img_bg, 50,50);
    lv_image_set_rotation(ui->scr_dashboard_img_bg, 0);

    //Write style for scr_dashboard_img_bg, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->scr_dashboard_img_bg, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->scr_dashboard_img_bg, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_dashboard_date_val
    ui->scr_dashboard_date_val = lv_label_create(ui->scr_dashboard);
    lv_obj_set_pos(ui->scr_dashboard_date_val, 600, 30);
    lv_obj_set_size(ui->scr_dashboard_date_val, 78, 19);
    lv_label_set_text(ui->scr_dashboard_date_val, "2025/05/15");
    lv_obj_set_style_text_align(ui->scr_dashboard_date_val, LV_TEXT_ALIGN_CENTER, 0);
    lv_obj_add_flag(ui->scr_dashboard_date_val, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_add_event_cb(ui->scr_dashboard_date_val, scr_dashboard_date_val_event_handler, LV_EVENT_ALL, NULL);

    //Write style for scr_dashboard_date_val, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_radius(ui->scr_dashboard_date_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_dashboard_date_val, lv_color_hex(0x64748B), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_dashboard_date_val, &lv_font_Roboto_Bold_10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_dashboard_date_val, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_dashboard_date_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_dashboard_date_val, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_dashboard_date_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_dashboard_date_val, 7, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_dashboard_date_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_dashboard_date_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_date_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->scr_dashboard_date_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for scr_dashboard_date_val, Part: LV_PART_MAIN, State: LV_STATE_DISABLED.
    lv_obj_set_style_radius(ui->scr_dashboard_date_val, 0, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_color(ui->scr_dashboard_date_val, lv_color_hex(0x64748B), LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_font(ui->scr_dashboard_date_val, &lv_font_Roboto_Bold_9, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_opa(ui->scr_dashboard_date_val, 255, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_letter_space(ui->scr_dashboard_date_val, 2, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_align(ui->scr_dashboard_date_val, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_bg_opa(ui->scr_dashboard_date_val, 0, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_pad_top(ui->scr_dashboard_date_val, 7, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_pad_right(ui->scr_dashboard_date_val, 0, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_pad_left(ui->scr_dashboard_date_val, 0, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_date_val, 0, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_border_width(ui->scr_dashboard_date_val, 0, LV_PART_MAIN|LV_STATE_DISABLED);

    //Write codes scr_dashboard_time_val
    static bool scr_dashboard_time_val_timer_enabled = false;
    ui->scr_dashboard_time_val = lv_label_create(ui->scr_dashboard);
    lv_obj_set_pos(ui->scr_dashboard_time_val, 695, 30);
    lv_obj_set_size(ui->scr_dashboard_time_val, 74, 19);
    lv_label_set_text(ui->scr_dashboard_time_val, "11:25:50");
    if (!scr_dashboard_time_val_timer_enabled) {
        lv_timer_create(scr_dashboard_time_val_timer, 1000, NULL);
        scr_dashboard_time_val_timer_enabled = true;
    }

    //Write style for scr_dashboard_time_val, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_radius(ui->scr_dashboard_time_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_dashboard_time_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_dashboard_time_val, 7, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_dashboard_time_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_dashboard_time_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_dashboard_time_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_time_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_dashboard_time_val, lv_color_hex(0x64748B), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_dashboard_time_val, &lv_font_Roboto_Bold_10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_dashboard_time_val, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_dashboard_time_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_dashboard_time_val, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for scr_dashboard_time_val, Part: LV_PART_MAIN, State: LV_STATE_DISABLED.
    lv_obj_set_style_radius(ui->scr_dashboard_time_val, 0, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_color(ui->scr_dashboard_time_val, lv_color_hex(0x64748B), LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_font(ui->scr_dashboard_time_val, &lv_font_Roboto_Bold_10, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_opa(ui->scr_dashboard_time_val, 255, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_letter_space(ui->scr_dashboard_time_val, 0, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_align(ui->scr_dashboard_time_val, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_bg_opa(ui->scr_dashboard_time_val, 0, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_pad_top(ui->scr_dashboard_time_val, 7, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_pad_right(ui->scr_dashboard_time_val, 0, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_pad_bottom(ui->scr_dashboard_time_val, 0, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_pad_left(ui->scr_dashboard_time_val, 0, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_time_val, 0, LV_PART_MAIN|LV_STATE_DISABLED);

    //Write codes scr_dashboard_img_net_on
    ui->scr_dashboard_img_net_on = lv_image_create(ui->scr_dashboard);
    lv_obj_set_pos(ui->scr_dashboard_img_net_on, 476, 32);
    lv_obj_set_size(ui->scr_dashboard_img_net_on, 16, 16);
    lv_obj_add_flag(ui->scr_dashboard_img_net_on, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->scr_dashboard_img_net_on, &_wifi_on_RGB565A8_16x16);
    lv_image_set_pivot(ui->scr_dashboard_img_net_on, 50,50);
    lv_image_set_rotation(ui->scr_dashboard_img_net_on, 0);

    //Write style for scr_dashboard_img_net_on, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->scr_dashboard_img_net_on, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_recolor(ui->scr_dashboard_img_net_on, lv_color_hex(0xababab), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->scr_dashboard_img_net_on, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_dashboard_img_net_off
    ui->scr_dashboard_img_net_off = lv_image_create(ui->scr_dashboard);
    lv_obj_set_pos(ui->scr_dashboard_img_net_off, 476, 32);
    lv_obj_set_size(ui->scr_dashboard_img_net_off, 16, 16);
    lv_obj_add_flag(ui->scr_dashboard_img_net_off, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(ui->scr_dashboard_img_net_off, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->scr_dashboard_img_net_off, &_wifi_off_RGB565A8_16x16);
    lv_image_set_pivot(ui->scr_dashboard_img_net_off, 50,50);
    lv_image_set_rotation(ui->scr_dashboard_img_net_off, 0);

    //Write style for scr_dashboard_img_net_off, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->scr_dashboard_img_net_off, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_recolor(ui->scr_dashboard_img_net_off, lv_color_hex(0xababba), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->scr_dashboard_img_net_off, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_dashboard_img_mqtt_off
    ui->scr_dashboard_img_mqtt_off = lv_image_create(ui->scr_dashboard);
    lv_obj_set_pos(ui->scr_dashboard_img_mqtt_off, 546, 32);
    lv_obj_set_size(ui->scr_dashboard_img_mqtt_off, 16, 16);
    lv_obj_add_flag(ui->scr_dashboard_img_mqtt_off, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(ui->scr_dashboard_img_mqtt_off, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->scr_dashboard_img_mqtt_off, &_mqtt_off_RGB565A8_16x16);
    lv_image_set_pivot(ui->scr_dashboard_img_mqtt_off, 50,50);
    lv_image_set_rotation(ui->scr_dashboard_img_mqtt_off, 0);

    //Write style for scr_dashboard_img_mqtt_off, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->scr_dashboard_img_mqtt_off, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_recolor(ui->scr_dashboard_img_mqtt_off, lv_color_hex(0xababba), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->scr_dashboard_img_mqtt_off, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_dashboard_img_mqtt_on
    ui->scr_dashboard_img_mqtt_on = lv_image_create(ui->scr_dashboard);
    lv_obj_set_pos(ui->scr_dashboard_img_mqtt_on, 546, 32);
    lv_obj_set_size(ui->scr_dashboard_img_mqtt_on, 16, 16);
    lv_obj_add_flag(ui->scr_dashboard_img_mqtt_on, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->scr_dashboard_img_mqtt_on, &_mqtt_on_RGB565A8_16x16);
    lv_image_set_pivot(ui->scr_dashboard_img_mqtt_on, 50,50);
    lv_image_set_rotation(ui->scr_dashboard_img_mqtt_on, 0);

    //Write style for scr_dashboard_img_mqtt_on, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->scr_dashboard_img_mqtt_on, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_recolor(ui->scr_dashboard_img_mqtt_on, lv_color_hex(0xababba), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->scr_dashboard_img_mqtt_on, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_dashboard_btn_dashboard
    ui->scr_dashboard_btn_dashboard = lv_button_create(ui->scr_dashboard);
    lv_obj_set_pos(ui->scr_dashboard_btn_dashboard, 9, 109);
    lv_obj_set_size(ui->scr_dashboard_btn_dashboard, 64, 64);
    ui->scr_dashboard_btn_dashboard_label = lv_label_create(ui->scr_dashboard_btn_dashboard);
    lv_label_set_text(ui->scr_dashboard_btn_dashboard_label, "");
    lv_label_set_long_mode(ui->scr_dashboard_btn_dashboard_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->scr_dashboard_btn_dashboard_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->scr_dashboard_btn_dashboard, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->scr_dashboard_btn_dashboard_label, LV_PCT(100));

    //Write style for scr_dashboard_btn_dashboard, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->scr_dashboard_btn_dashboard, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->scr_dashboard_btn_dashboard, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_dashboard_btn_dashboard, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_btn_dashboard, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_dashboard_btn_dashboard, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_dashboard_btn_dashboard, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_dashboard_btn_dashboard, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_dashboard_btn_dashboard, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for scr_dashboard_btn_dashboard, Part: LV_PART_MAIN, State: LV_STATE_FOCUSED.
    lv_obj_set_style_bg_opa(ui->scr_dashboard_btn_dashboard, 39, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_color(ui->scr_dashboard_btn_dashboard, lv_color_hex(0x10B981), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_grad_dir(ui->scr_dashboard_btn_dashboard, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_width(ui->scr_dashboard_btn_dashboard, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_radius(ui->scr_dashboard_btn_dashboard, 14, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_btn_dashboard, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_color(ui->scr_dashboard_btn_dashboard, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_font(ui->scr_dashboard_btn_dashboard, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_opa(ui->scr_dashboard_btn_dashboard, 255, LV_PART_MAIN|LV_STATE_FOCUSED);

    //Write style for scr_dashboard_btn_dashboard, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_bg_opa(ui->scr_dashboard_btn_dashboard, 40, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_bg_color(ui->scr_dashboard_btn_dashboard, lv_color_hex(0x10B981), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_bg_grad_dir(ui->scr_dashboard_btn_dashboard, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui->scr_dashboard_btn_dashboard, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_radius(ui->scr_dashboard_btn_dashboard, 14, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_btn_dashboard, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->scr_dashboard_btn_dashboard, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->scr_dashboard_btn_dashboard, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->scr_dashboard_btn_dashboard, 255, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for scr_dashboard_btn_dashboard, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_bg_opa(ui->scr_dashboard_btn_dashboard, 39, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui->scr_dashboard_btn_dashboard, lv_color_hex(0x10B981), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_grad_dir(ui->scr_dashboard_btn_dashboard, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_border_width(ui->scr_dashboard_btn_dashboard, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_radius(ui->scr_dashboard_btn_dashboard, 14, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_btn_dashboard, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->scr_dashboard_btn_dashboard, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->scr_dashboard_btn_dashboard, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->scr_dashboard_btn_dashboard, 255, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write codes scr_dashboard_btn_analystis
    ui->scr_dashboard_btn_analystis = lv_button_create(ui->scr_dashboard);
    lv_obj_set_pos(ui->scr_dashboard_btn_analystis, 9, 181);
    lv_obj_set_size(ui->scr_dashboard_btn_analystis, 64, 64);
    ui->scr_dashboard_btn_analystis_label = lv_label_create(ui->scr_dashboard_btn_analystis);
    lv_label_set_text(ui->scr_dashboard_btn_analystis_label, "");
    lv_label_set_long_mode(ui->scr_dashboard_btn_analystis_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->scr_dashboard_btn_analystis_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->scr_dashboard_btn_analystis, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->scr_dashboard_btn_analystis_label, LV_PCT(100));

    //Write style for scr_dashboard_btn_analystis, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->scr_dashboard_btn_analystis, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->scr_dashboard_btn_analystis, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_dashboard_btn_analystis, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_btn_analystis, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_dashboard_btn_analystis, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_dashboard_btn_analystis, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_dashboard_btn_analystis, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_dashboard_btn_analystis, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for scr_dashboard_btn_analystis, Part: LV_PART_MAIN, State: LV_STATE_FOCUSED.
    lv_obj_set_style_bg_opa(ui->scr_dashboard_btn_analystis, 39, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_color(ui->scr_dashboard_btn_analystis, lv_color_hex(0x10B981), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_grad_dir(ui->scr_dashboard_btn_analystis, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_width(ui->scr_dashboard_btn_analystis, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_radius(ui->scr_dashboard_btn_analystis, 14, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_btn_analystis, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_color(ui->scr_dashboard_btn_analystis, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_font(ui->scr_dashboard_btn_analystis, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_opa(ui->scr_dashboard_btn_analystis, 255, LV_PART_MAIN|LV_STATE_FOCUSED);

    //Write style for scr_dashboard_btn_analystis, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_bg_opa(ui->scr_dashboard_btn_analystis, 40, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_bg_color(ui->scr_dashboard_btn_analystis, lv_color_hex(0x10B981), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_bg_grad_dir(ui->scr_dashboard_btn_analystis, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui->scr_dashboard_btn_analystis, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_radius(ui->scr_dashboard_btn_analystis, 14, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_btn_analystis, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->scr_dashboard_btn_analystis, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->scr_dashboard_btn_analystis, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->scr_dashboard_btn_analystis, 255, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for scr_dashboard_btn_analystis, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_bg_opa(ui->scr_dashboard_btn_analystis, 39, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui->scr_dashboard_btn_analystis, lv_color_hex(0x10B981), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_grad_dir(ui->scr_dashboard_btn_analystis, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_border_width(ui->scr_dashboard_btn_analystis, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_radius(ui->scr_dashboard_btn_analystis, 14, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_btn_analystis, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->scr_dashboard_btn_analystis, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->scr_dashboard_btn_analystis, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->scr_dashboard_btn_analystis, 255, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write codes scr_dashboard_btn_event_logs
    ui->scr_dashboard_btn_event_logs = lv_button_create(ui->scr_dashboard);
    lv_obj_set_pos(ui->scr_dashboard_btn_event_logs, 9, 255);
    lv_obj_set_size(ui->scr_dashboard_btn_event_logs, 64, 64);
    ui->scr_dashboard_btn_event_logs_label = lv_label_create(ui->scr_dashboard_btn_event_logs);
    lv_label_set_text(ui->scr_dashboard_btn_event_logs_label, "");
    lv_label_set_long_mode(ui->scr_dashboard_btn_event_logs_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->scr_dashboard_btn_event_logs_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->scr_dashboard_btn_event_logs, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->scr_dashboard_btn_event_logs_label, LV_PCT(100));

    //Write style for scr_dashboard_btn_event_logs, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->scr_dashboard_btn_event_logs, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->scr_dashboard_btn_event_logs, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_dashboard_btn_event_logs, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_btn_event_logs, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_dashboard_btn_event_logs, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_dashboard_btn_event_logs, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_dashboard_btn_event_logs, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_dashboard_btn_event_logs, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for scr_dashboard_btn_event_logs, Part: LV_PART_MAIN, State: LV_STATE_FOCUSED.
    lv_obj_set_style_bg_opa(ui->scr_dashboard_btn_event_logs, 39, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_color(ui->scr_dashboard_btn_event_logs, lv_color_hex(0x10B981), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_grad_dir(ui->scr_dashboard_btn_event_logs, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_width(ui->scr_dashboard_btn_event_logs, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_radius(ui->scr_dashboard_btn_event_logs, 14, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_btn_event_logs, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_color(ui->scr_dashboard_btn_event_logs, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_font(ui->scr_dashboard_btn_event_logs, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_opa(ui->scr_dashboard_btn_event_logs, 255, LV_PART_MAIN|LV_STATE_FOCUSED);

    //Write style for scr_dashboard_btn_event_logs, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_bg_opa(ui->scr_dashboard_btn_event_logs, 40, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_bg_color(ui->scr_dashboard_btn_event_logs, lv_color_hex(0x10B981), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_bg_grad_dir(ui->scr_dashboard_btn_event_logs, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui->scr_dashboard_btn_event_logs, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_radius(ui->scr_dashboard_btn_event_logs, 14, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_btn_event_logs, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->scr_dashboard_btn_event_logs, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->scr_dashboard_btn_event_logs, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->scr_dashboard_btn_event_logs, 255, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for scr_dashboard_btn_event_logs, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_bg_opa(ui->scr_dashboard_btn_event_logs, 39, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui->scr_dashboard_btn_event_logs, lv_color_hex(0x10B981), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_grad_dir(ui->scr_dashboard_btn_event_logs, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_border_width(ui->scr_dashboard_btn_event_logs, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_radius(ui->scr_dashboard_btn_event_logs, 14, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_btn_event_logs, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->scr_dashboard_btn_event_logs, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->scr_dashboard_btn_event_logs, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->scr_dashboard_btn_event_logs, 255, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write codes scr_dashboard_btn_settings
    ui->scr_dashboard_btn_settings = lv_button_create(ui->scr_dashboard);
    lv_obj_set_pos(ui->scr_dashboard_btn_settings, 9, 325);
    lv_obj_set_size(ui->scr_dashboard_btn_settings, 64, 64);
    ui->scr_dashboard_btn_settings_label = lv_label_create(ui->scr_dashboard_btn_settings);
    lv_label_set_text(ui->scr_dashboard_btn_settings_label, "");
    lv_label_set_long_mode(ui->scr_dashboard_btn_settings_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->scr_dashboard_btn_settings_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->scr_dashboard_btn_settings, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->scr_dashboard_btn_settings_label, LV_PCT(100));

    //Write style for scr_dashboard_btn_settings, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->scr_dashboard_btn_settings, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->scr_dashboard_btn_settings, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_dashboard_btn_settings, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_btn_settings, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_dashboard_btn_settings, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_dashboard_btn_settings, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_dashboard_btn_settings, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_dashboard_btn_settings, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for scr_dashboard_btn_settings, Part: LV_PART_MAIN, State: LV_STATE_FOCUSED.
    lv_obj_set_style_bg_opa(ui->scr_dashboard_btn_settings, 39, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_color(ui->scr_dashboard_btn_settings, lv_color_hex(0x10B981), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_grad_dir(ui->scr_dashboard_btn_settings, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_width(ui->scr_dashboard_btn_settings, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_radius(ui->scr_dashboard_btn_settings, 14, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_btn_settings, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_color(ui->scr_dashboard_btn_settings, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_font(ui->scr_dashboard_btn_settings, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_opa(ui->scr_dashboard_btn_settings, 255, LV_PART_MAIN|LV_STATE_FOCUSED);

    //Write style for scr_dashboard_btn_settings, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_bg_opa(ui->scr_dashboard_btn_settings, 40, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_bg_color(ui->scr_dashboard_btn_settings, lv_color_hex(0x10B981), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_bg_grad_dir(ui->scr_dashboard_btn_settings, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui->scr_dashboard_btn_settings, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_radius(ui->scr_dashboard_btn_settings, 14, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_btn_settings, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->scr_dashboard_btn_settings, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->scr_dashboard_btn_settings, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->scr_dashboard_btn_settings, 255, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for scr_dashboard_btn_settings, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_bg_opa(ui->scr_dashboard_btn_settings, 39, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui->scr_dashboard_btn_settings, lv_color_hex(0x10B981), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_grad_dir(ui->scr_dashboard_btn_settings, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_border_width(ui->scr_dashboard_btn_settings, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_radius(ui->scr_dashboard_btn_settings, 14, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_btn_settings, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->scr_dashboard_btn_settings, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->scr_dashboard_btn_settings, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->scr_dashboard_btn_settings, 255, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write codes scr_dashboard_btn_restart
    ui->scr_dashboard_btn_restart = lv_button_create(ui->scr_dashboard);
    lv_obj_set_pos(ui->scr_dashboard_btn_restart, 9, 393);
    lv_obj_set_size(ui->scr_dashboard_btn_restart, 64, 64);
    ui->scr_dashboard_btn_restart_label = lv_label_create(ui->scr_dashboard_btn_restart);
    lv_label_set_text(ui->scr_dashboard_btn_restart_label, "");
    lv_label_set_long_mode(ui->scr_dashboard_btn_restart_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->scr_dashboard_btn_restart_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->scr_dashboard_btn_restart, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->scr_dashboard_btn_restart_label, LV_PCT(100));

    //Write style for scr_dashboard_btn_restart, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->scr_dashboard_btn_restart, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->scr_dashboard_btn_restart, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_dashboard_btn_restart, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_btn_restart, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_dashboard_btn_restart, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_dashboard_btn_restart, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_dashboard_btn_restart, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_dashboard_btn_restart, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for scr_dashboard_btn_restart, Part: LV_PART_MAIN, State: LV_STATE_FOCUSED.
    lv_obj_set_style_bg_opa(ui->scr_dashboard_btn_restart, 39, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_color(ui->scr_dashboard_btn_restart, lv_color_hex(0x10B981), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_grad_dir(ui->scr_dashboard_btn_restart, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_width(ui->scr_dashboard_btn_restart, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_radius(ui->scr_dashboard_btn_restart, 14, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_btn_restart, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_color(ui->scr_dashboard_btn_restart, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_font(ui->scr_dashboard_btn_restart, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_opa(ui->scr_dashboard_btn_restart, 255, LV_PART_MAIN|LV_STATE_FOCUSED);

    //Write style for scr_dashboard_btn_restart, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_bg_opa(ui->scr_dashboard_btn_restart, 40, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_bg_color(ui->scr_dashboard_btn_restart, lv_color_hex(0x10B981), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_bg_grad_dir(ui->scr_dashboard_btn_restart, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui->scr_dashboard_btn_restart, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_radius(ui->scr_dashboard_btn_restart, 14, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_btn_restart, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->scr_dashboard_btn_restart, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->scr_dashboard_btn_restart, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->scr_dashboard_btn_restart, 255, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for scr_dashboard_btn_restart, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_bg_opa(ui->scr_dashboard_btn_restart, 39, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui->scr_dashboard_btn_restart, lv_color_hex(0x10B981), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_grad_dir(ui->scr_dashboard_btn_restart, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_border_width(ui->scr_dashboard_btn_restart, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_radius(ui->scr_dashboard_btn_restart, 14, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_btn_restart, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->scr_dashboard_btn_restart, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->scr_dashboard_btn_restart, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->scr_dashboard_btn_restart, 255, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write codes scr_dashboard_cont_dashboard
    ui->scr_dashboard_cont_dashboard = lv_obj_create(ui->scr_dashboard);
    lv_obj_set_pos(ui->scr_dashboard_cont_dashboard, 101, 49);
    lv_obj_set_size(ui->scr_dashboard_cont_dashboard, 680, 420);
    lv_obj_set_scrollbar_mode(ui->scr_dashboard_cont_dashboard, LV_SCROLLBAR_MODE_OFF);
    lv_obj_add_flag(ui->scr_dashboard_cont_dashboard, LV_OBJ_FLAG_HIDDEN);

    //Write style for scr_dashboard_cont_dashboard, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_dashboard_cont_dashboard, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_dashboard_cont_dashboard, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_dashboard_cont_dashboard, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_dashboard_cont_dashboard, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_dashboard_cont_dashboard, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_dashboard_cont_dashboard, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_dashboard_cont_dashboard, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_cont_dashboard, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_dashboard_lbl_dashboard
    ui->scr_dashboard_lbl_dashboard = lv_label_create(ui->scr_dashboard_cont_dashboard);
    lv_obj_set_pos(ui->scr_dashboard_lbl_dashboard, 0, 5);
    lv_obj_set_size(ui->scr_dashboard_lbl_dashboard, 172, 11);
    lv_label_set_text(ui->scr_dashboard_lbl_dashboard, "REAL-TIME MONITORING");
    lv_label_set_long_mode(ui->scr_dashboard_lbl_dashboard, LV_LABEL_LONG_WRAP);

    //Write style for scr_dashboard_lbl_dashboard, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_dashboard_lbl_dashboard, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_dashboard_lbl_dashboard, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_dashboard_lbl_dashboard, lv_color_hex(0x64748B), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_dashboard_lbl_dashboard, &lv_font_Roboto_Black_10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_dashboard_lbl_dashboard, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_dashboard_lbl_dashboard, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_dashboard_lbl_dashboard, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_dashboard_lbl_dashboard, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_dashboard_lbl_dashboard, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_dashboard_lbl_dashboard, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_dashboard_lbl_dashboard, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_dashboard_lbl_dashboard, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_dashboard_lbl_dashboard, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_lbl_dashboard, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_dashboard_cont_aqi
    ui->scr_dashboard_cont_aqi = lv_obj_create(ui->scr_dashboard_cont_dashboard);
    lv_obj_set_pos(ui->scr_dashboard_cont_aqi, 0, 33);
    lv_obj_set_size(ui->scr_dashboard_cont_aqi, 230, 372);
    lv_obj_set_scrollbar_mode(ui->scr_dashboard_cont_aqi, LV_SCROLLBAR_MODE_OFF);

    //Write style for scr_dashboard_cont_aqi, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_dashboard_cont_aqi, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scr_dashboard_cont_aqi, 25, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scr_dashboard_cont_aqi, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scr_dashboard_cont_aqi, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_dashboard_cont_aqi, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_dashboard_cont_aqi, 244, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_dashboard_cont_aqi, lv_color_hex(0x0F172A), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_dashboard_cont_aqi, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_dashboard_cont_aqi, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_dashboard_cont_aqi, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_dashboard_cont_aqi, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_dashboard_cont_aqi, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_cont_aqi, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_dashboard_lbl_aqi
    ui->scr_dashboard_lbl_aqi = lv_label_create(ui->scr_dashboard_cont_aqi);
    lv_obj_set_pos(ui->scr_dashboard_lbl_aqi, 23, 21);
    lv_obj_set_size(ui->scr_dashboard_lbl_aqi, 172, 11);
    lv_label_set_text(ui->scr_dashboard_lbl_aqi, "AQI INDEX");
    lv_label_set_long_mode(ui->scr_dashboard_lbl_aqi, LV_LABEL_LONG_WRAP);

    //Write style for scr_dashboard_lbl_aqi, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_dashboard_lbl_aqi, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_dashboard_lbl_aqi, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_dashboard_lbl_aqi, lv_color_hex(0x64748B), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_dashboard_lbl_aqi, &lv_font_Roboto_Black_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_dashboard_lbl_aqi, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_dashboard_lbl_aqi, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_dashboard_lbl_aqi, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_dashboard_lbl_aqi, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_dashboard_lbl_aqi, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_dashboard_lbl_aqi, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_dashboard_lbl_aqi, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_dashboard_lbl_aqi, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_dashboard_lbl_aqi, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_lbl_aqi, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_dashboard_lbl_aqi_val
    ui->scr_dashboard_lbl_aqi_val = lv_label_create(ui->scr_dashboard_cont_aqi);
    lv_obj_set_pos(ui->scr_dashboard_lbl_aqi_val, 4, 140);
    lv_obj_set_size(ui->scr_dashboard_lbl_aqi_val, 221, 79);
    lv_label_set_text(ui->scr_dashboard_lbl_aqi_val, "45");
    lv_label_set_long_mode(ui->scr_dashboard_lbl_aqi_val, LV_LABEL_LONG_WRAP);

    //Write style for scr_dashboard_lbl_aqi_val, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_dashboard_lbl_aqi_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_dashboard_lbl_aqi_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_dashboard_lbl_aqi_val, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_dashboard_lbl_aqi_val, &lv_font_Roboto_Black_72, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_dashboard_lbl_aqi_val, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_dashboard_lbl_aqi_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_dashboard_lbl_aqi_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_dashboard_lbl_aqi_val, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_dashboard_lbl_aqi_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_dashboard_lbl_aqi_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_dashboard_lbl_aqi_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_dashboard_lbl_aqi_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_dashboard_lbl_aqi_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_lbl_aqi_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_dashboard_arc_aqi
    ui->scr_dashboard_arc_aqi = lv_arc_create(ui->scr_dashboard_cont_aqi);
    lv_obj_set_pos(ui->scr_dashboard_arc_aqi, 4, 62);
    lv_obj_set_size(ui->scr_dashboard_arc_aqi, 220, 220);
    lv_arc_set_mode(ui->scr_dashboard_arc_aqi, LV_ARC_MODE_NORMAL);
    lv_arc_set_range(ui->scr_dashboard_arc_aqi, 0, 500);
    lv_arc_set_bg_angles(ui->scr_dashboard_arc_aqi, 0, 359);
    lv_arc_set_value(ui->scr_dashboard_arc_aqi, 45);
    lv_arc_set_rotation(ui->scr_dashboard_arc_aqi, 270);

    //Write style for scr_dashboard_arc_aqi, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->scr_dashboard_arc_aqi, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->scr_dashboard_arc_aqi, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_width(ui->scr_dashboard_arc_aqi, 12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui->scr_dashboard_arc_aqi, 40, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_color(ui->scr_dashboard_arc_aqi, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_rounded(ui->scr_dashboard_arc_aqi, true, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_dashboard_arc_aqi, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_dashboard_arc_aqi, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_dashboard_arc_aqi, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_dashboard_arc_aqi, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_dashboard_arc_aqi, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_arc_aqi, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for scr_dashboard_arc_aqi, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_arc_width(ui->scr_dashboard_arc_aqi, 12, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui->scr_dashboard_arc_aqi, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_color(ui->scr_dashboard_arc_aqi, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_rounded(ui->scr_dashboard_arc_aqi, true, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write style for scr_dashboard_arc_aqi, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->scr_dashboard_arc_aqi, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_dashboard_arc_aqi, lv_color_hex(0x2195f6), LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_dashboard_arc_aqi, LV_GRAD_DIR_NONE, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui->scr_dashboard_arc_aqi, 0, LV_PART_KNOB|LV_STATE_DEFAULT);

    //Write codes scr_dashboard_cont_aqi_status
    ui->scr_dashboard_cont_aqi_status = lv_obj_create(ui->scr_dashboard_cont_aqi);
    lv_obj_set_pos(ui->scr_dashboard_cont_aqi_status, 23, 303);
    lv_obj_set_size(ui->scr_dashboard_cont_aqi_status, 180, 55);
    lv_obj_set_scrollbar_mode(ui->scr_dashboard_cont_aqi_status, LV_SCROLLBAR_MODE_OFF);

    //Write style for scr_dashboard_cont_aqi_status, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_dashboard_cont_aqi_status, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scr_dashboard_cont_aqi_status, 25, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scr_dashboard_cont_aqi_status, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scr_dashboard_cont_aqi_status, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_dashboard_cont_aqi_status, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_dashboard_cont_aqi_status, 244, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_dashboard_cont_aqi_status, lv_color_hex(0x0F172A), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_dashboard_cont_aqi_status, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_dashboard_cont_aqi_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_dashboard_cont_aqi_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_dashboard_cont_aqi_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_dashboard_cont_aqi_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_cont_aqi_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_dashboard_lbl_Aqi_status
    ui->scr_dashboard_lbl_Aqi_status = lv_label_create(ui->scr_dashboard_cont_aqi_status);
    lv_obj_set_pos(ui->scr_dashboard_lbl_Aqi_status, 23, 11);
    lv_obj_set_size(ui->scr_dashboard_lbl_Aqi_status, 139, 33);
    lv_label_set_text(ui->scr_dashboard_lbl_Aqi_status, "GOOD");
    lv_label_set_long_mode(ui->scr_dashboard_lbl_Aqi_status, LV_LABEL_LONG_WRAP);

    //Write style for scr_dashboard_lbl_Aqi_status, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_dashboard_lbl_Aqi_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_dashboard_lbl_Aqi_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_dashboard_lbl_Aqi_status, lv_color_hex(0x34D399), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_dashboard_lbl_Aqi_status, &lv_font_Roboto_Black_30, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_dashboard_lbl_Aqi_status, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_dashboard_lbl_Aqi_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_dashboard_lbl_Aqi_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_dashboard_lbl_Aqi_status, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_dashboard_lbl_Aqi_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_dashboard_lbl_Aqi_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_dashboard_lbl_Aqi_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_dashboard_lbl_Aqi_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_dashboard_lbl_Aqi_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_lbl_Aqi_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_dashboard_cont_pm10
    ui->scr_dashboard_cont_pm10 = lv_obj_create(ui->scr_dashboard_cont_dashboard);
    lv_obj_set_pos(ui->scr_dashboard_cont_pm10, 243, 33);
    lv_obj_set_size(ui->scr_dashboard_cont_pm10, 211, 116);
    lv_obj_set_scrollbar_mode(ui->scr_dashboard_cont_pm10, LV_SCROLLBAR_MODE_OFF);

    //Write style for scr_dashboard_cont_pm10, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_dashboard_cont_pm10, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scr_dashboard_cont_pm10, 25, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scr_dashboard_cont_pm10, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scr_dashboard_cont_pm10, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_dashboard_cont_pm10, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_dashboard_cont_pm10, 244, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_dashboard_cont_pm10, lv_color_hex(0x0F172A), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_dashboard_cont_pm10, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_dashboard_cont_pm10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_dashboard_cont_pm10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_dashboard_cont_pm10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_dashboard_cont_pm10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_cont_pm10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_dashboard_lbl_pm10
    ui->scr_dashboard_lbl_pm10 = lv_label_create(ui->scr_dashboard_cont_pm10);
    lv_obj_set_pos(ui->scr_dashboard_lbl_pm10, 15, 13);
    lv_obj_set_size(ui->scr_dashboard_lbl_pm10, 81, 24);
    lv_label_set_text(ui->scr_dashboard_lbl_pm10, "PM 10");
    lv_label_set_long_mode(ui->scr_dashboard_lbl_pm10, LV_LABEL_LONG_WRAP);

    //Write style for scr_dashboard_lbl_pm10, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_dashboard_lbl_pm10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_dashboard_lbl_pm10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_dashboard_lbl_pm10, lv_color_hex(0xCBD5E1), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_dashboard_lbl_pm10, &lv_font_Roboto_Black_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_dashboard_lbl_pm10, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_dashboard_lbl_pm10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_dashboard_lbl_pm10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_dashboard_lbl_pm10, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_dashboard_lbl_pm10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_dashboard_lbl_pm10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_dashboard_lbl_pm10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_dashboard_lbl_pm10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_dashboard_lbl_pm10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_lbl_pm10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_dashboard_lbl_pm10_val
    ui->scr_dashboard_lbl_pm10_val = lv_label_create(ui->scr_dashboard_cont_pm10);
    lv_obj_set_pos(ui->scr_dashboard_lbl_pm10_val, 19, 52);
    lv_obj_set_size(ui->scr_dashboard_lbl_pm10_val, 121, 44);
    lv_label_set_text(ui->scr_dashboard_lbl_pm10_val, "12.4");
    lv_label_set_long_mode(ui->scr_dashboard_lbl_pm10_val, LV_LABEL_LONG_WRAP);

    //Write style for scr_dashboard_lbl_pm10_val, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_dashboard_lbl_pm10_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_dashboard_lbl_pm10_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_dashboard_lbl_pm10_val, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_dashboard_lbl_pm10_val, &lv_font_Roboto_Black_48, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_dashboard_lbl_pm10_val, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_dashboard_lbl_pm10_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_dashboard_lbl_pm10_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_dashboard_lbl_pm10_val, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_dashboard_lbl_pm10_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_dashboard_lbl_pm10_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_dashboard_lbl_pm10_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_dashboard_lbl_pm10_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_dashboard_lbl_pm10_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_lbl_pm10_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_dashboard_lbl_pm10_unit
    ui->scr_dashboard_lbl_pm10_unit = lv_label_create(ui->scr_dashboard_cont_pm10);
    lv_obj_set_pos(ui->scr_dashboard_lbl_pm10_unit, 148, 72);
    lv_obj_set_size(ui->scr_dashboard_lbl_pm10_unit, 60, 24);
    lv_label_set_text(ui->scr_dashboard_lbl_pm10_unit, "µg/m³");
    lv_label_set_long_mode(ui->scr_dashboard_lbl_pm10_unit, LV_LABEL_LONG_WRAP);

    //Write style for scr_dashboard_lbl_pm10_unit, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_dashboard_lbl_pm10_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_dashboard_lbl_pm10_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_dashboard_lbl_pm10_unit, lv_color_hex(0xCBD5E1), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_dashboard_lbl_pm10_unit, &lv_font_Roboto_Black_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_dashboard_lbl_pm10_unit, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_dashboard_lbl_pm10_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_dashboard_lbl_pm10_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_dashboard_lbl_pm10_unit, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_dashboard_lbl_pm10_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_dashboard_lbl_pm10_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_dashboard_lbl_pm10_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_dashboard_lbl_pm10_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_dashboard_lbl_pm10_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_lbl_pm10_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_dashboard_cont_pm10_status
    ui->scr_dashboard_cont_pm10_status = lv_obj_create(ui->scr_dashboard_cont_pm10);
    lv_obj_set_pos(ui->scr_dashboard_cont_pm10_status, 120, 13);
    lv_obj_set_size(ui->scr_dashboard_cont_pm10_status, 70, 23);
    lv_obj_set_scrollbar_mode(ui->scr_dashboard_cont_pm10_status, LV_SCROLLBAR_MODE_OFF);

    //Write style for scr_dashboard_cont_pm10_status, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_dashboard_cont_pm10_status, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scr_dashboard_cont_pm10_status, 25, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scr_dashboard_cont_pm10_status, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scr_dashboard_cont_pm10_status, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_dashboard_cont_pm10_status, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_dashboard_cont_pm10_status, 244, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_dashboard_cont_pm10_status, lv_color_hex(0x0F172A), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_dashboard_cont_pm10_status, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_dashboard_cont_pm10_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_dashboard_cont_pm10_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_dashboard_cont_pm10_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_dashboard_cont_pm10_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_cont_pm10_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_dashboard_lbl_pm10_status
    ui->scr_dashboard_lbl_pm10_status = lv_label_create(ui->scr_dashboard_cont_pm10_status);
    lv_obj_set_pos(ui->scr_dashboard_lbl_pm10_status, 8, 4);
    lv_obj_set_size(ui->scr_dashboard_lbl_pm10_status, 52, 15);
    lv_label_set_text(ui->scr_dashboard_lbl_pm10_status, "GOOD");
    lv_label_set_long_mode(ui->scr_dashboard_lbl_pm10_status, LV_LABEL_LONG_WRAP);

    //Write style for scr_dashboard_lbl_pm10_status, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_dashboard_lbl_pm10_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_dashboard_lbl_pm10_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_dashboard_lbl_pm10_status, lv_color_hex(0x34D399), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_dashboard_lbl_pm10_status, &lv_font_Roboto_Black_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_dashboard_lbl_pm10_status, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_dashboard_lbl_pm10_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_dashboard_lbl_pm10_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_dashboard_lbl_pm10_status, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_dashboard_lbl_pm10_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_dashboard_lbl_pm10_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_dashboard_lbl_pm10_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_dashboard_lbl_pm10_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_dashboard_lbl_pm10_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_lbl_pm10_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_dashboard_cont_pm25
    ui->scr_dashboard_cont_pm25 = lv_obj_create(ui->scr_dashboard_cont_dashboard);
    lv_obj_set_pos(ui->scr_dashboard_cont_pm25, 467, 33);
    lv_obj_set_size(ui->scr_dashboard_cont_pm25, 211, 116);
    lv_obj_set_scrollbar_mode(ui->scr_dashboard_cont_pm25, LV_SCROLLBAR_MODE_OFF);

    //Write style for scr_dashboard_cont_pm25, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_dashboard_cont_pm25, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scr_dashboard_cont_pm25, 25, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scr_dashboard_cont_pm25, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scr_dashboard_cont_pm25, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_dashboard_cont_pm25, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_dashboard_cont_pm25, 244, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_dashboard_cont_pm25, lv_color_hex(0x0F172A), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_dashboard_cont_pm25, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_dashboard_cont_pm25, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_dashboard_cont_pm25, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_dashboard_cont_pm25, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_dashboard_cont_pm25, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_cont_pm25, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_dashboard_lbl_pm25
    ui->scr_dashboard_lbl_pm25 = lv_label_create(ui->scr_dashboard_cont_pm25);
    lv_obj_set_pos(ui->scr_dashboard_lbl_pm25, 15, 13);
    lv_obj_set_size(ui->scr_dashboard_lbl_pm25, 81, 24);
    lv_label_set_text(ui->scr_dashboard_lbl_pm25, "PM 2.5");
    lv_label_set_long_mode(ui->scr_dashboard_lbl_pm25, LV_LABEL_LONG_WRAP);

    //Write style for scr_dashboard_lbl_pm25, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_dashboard_lbl_pm25, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_dashboard_lbl_pm25, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_dashboard_lbl_pm25, lv_color_hex(0xCBD5E1), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_dashboard_lbl_pm25, &lv_font_Roboto_Black_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_dashboard_lbl_pm25, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_dashboard_lbl_pm25, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_dashboard_lbl_pm25, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_dashboard_lbl_pm25, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_dashboard_lbl_pm25, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_dashboard_lbl_pm25, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_dashboard_lbl_pm25, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_dashboard_lbl_pm25, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_dashboard_lbl_pm25, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_lbl_pm25, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_dashboard_lbl_pm25_val
    ui->scr_dashboard_lbl_pm25_val = lv_label_create(ui->scr_dashboard_cont_pm25);
    lv_obj_set_pos(ui->scr_dashboard_lbl_pm25_val, 19, 52);
    lv_obj_set_size(ui->scr_dashboard_lbl_pm25_val, 121, 44);
    lv_label_set_text(ui->scr_dashboard_lbl_pm25_val, "12.4");
    lv_label_set_long_mode(ui->scr_dashboard_lbl_pm25_val, LV_LABEL_LONG_WRAP);

    //Write style for scr_dashboard_lbl_pm25_val, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_dashboard_lbl_pm25_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_dashboard_lbl_pm25_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_dashboard_lbl_pm25_val, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_dashboard_lbl_pm25_val, &lv_font_Roboto_Black_48, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_dashboard_lbl_pm25_val, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_dashboard_lbl_pm25_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_dashboard_lbl_pm25_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_dashboard_lbl_pm25_val, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_dashboard_lbl_pm25_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_dashboard_lbl_pm25_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_dashboard_lbl_pm25_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_dashboard_lbl_pm25_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_dashboard_lbl_pm25_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_lbl_pm25_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_dashboard_lbl_pm25_uint
    ui->scr_dashboard_lbl_pm25_uint = lv_label_create(ui->scr_dashboard_cont_pm25);
    lv_obj_set_pos(ui->scr_dashboard_lbl_pm25_uint, 148, 72);
    lv_obj_set_size(ui->scr_dashboard_lbl_pm25_uint, 60, 24);
    lv_label_set_text(ui->scr_dashboard_lbl_pm25_uint, "µg/m³");
    lv_label_set_long_mode(ui->scr_dashboard_lbl_pm25_uint, LV_LABEL_LONG_WRAP);

    //Write style for scr_dashboard_lbl_pm25_uint, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_dashboard_lbl_pm25_uint, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_dashboard_lbl_pm25_uint, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_dashboard_lbl_pm25_uint, lv_color_hex(0xCBD5E1), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_dashboard_lbl_pm25_uint, &lv_font_Roboto_Black_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_dashboard_lbl_pm25_uint, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_dashboard_lbl_pm25_uint, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_dashboard_lbl_pm25_uint, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_dashboard_lbl_pm25_uint, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_dashboard_lbl_pm25_uint, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_dashboard_lbl_pm25_uint, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_dashboard_lbl_pm25_uint, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_dashboard_lbl_pm25_uint, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_dashboard_lbl_pm25_uint, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_lbl_pm25_uint, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_dashboard_cont_status
    ui->scr_dashboard_cont_status = lv_obj_create(ui->scr_dashboard_cont_pm25);
    lv_obj_set_pos(ui->scr_dashboard_cont_status, 120, 13);
    lv_obj_set_size(ui->scr_dashboard_cont_status, 70, 23);
    lv_obj_set_scrollbar_mode(ui->scr_dashboard_cont_status, LV_SCROLLBAR_MODE_OFF);

    //Write style for scr_dashboard_cont_status, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_dashboard_cont_status, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scr_dashboard_cont_status, 25, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scr_dashboard_cont_status, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scr_dashboard_cont_status, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_dashboard_cont_status, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_dashboard_cont_status, 244, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_dashboard_cont_status, lv_color_hex(0x0F172A), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_dashboard_cont_status, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_dashboard_cont_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_dashboard_cont_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_dashboard_cont_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_dashboard_cont_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_cont_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_dashboard_lbl_status
    ui->scr_dashboard_lbl_status = lv_label_create(ui->scr_dashboard_cont_status);
    lv_obj_set_pos(ui->scr_dashboard_lbl_status, 8, 4);
    lv_obj_set_size(ui->scr_dashboard_lbl_status, 52, 15);
    lv_label_set_text(ui->scr_dashboard_lbl_status, "GOOD");
    lv_label_set_long_mode(ui->scr_dashboard_lbl_status, LV_LABEL_LONG_WRAP);

    //Write style for scr_dashboard_lbl_status, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_dashboard_lbl_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_dashboard_lbl_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_dashboard_lbl_status, lv_color_hex(0x34D399), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_dashboard_lbl_status, &lv_font_Roboto_Black_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_dashboard_lbl_status, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_dashboard_lbl_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_dashboard_lbl_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_dashboard_lbl_status, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_dashboard_lbl_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_dashboard_lbl_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_dashboard_lbl_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_dashboard_lbl_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_dashboard_lbl_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_lbl_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_dashboard_cont_21
    ui->scr_dashboard_cont_21 = lv_obj_create(ui->scr_dashboard_cont_dashboard);
    lv_obj_set_pos(ui->scr_dashboard_cont_21, 243, 289);
    lv_obj_set_size(ui->scr_dashboard_cont_21, 211, 116);
    lv_obj_set_scrollbar_mode(ui->scr_dashboard_cont_21, LV_SCROLLBAR_MODE_OFF);

    //Write style for scr_dashboard_cont_21, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_dashboard_cont_21, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scr_dashboard_cont_21, 25, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scr_dashboard_cont_21, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scr_dashboard_cont_21, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_dashboard_cont_21, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_dashboard_cont_21, 244, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_dashboard_cont_21, lv_color_hex(0x0F172A), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_dashboard_cont_21, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_dashboard_cont_21, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_dashboard_cont_21, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_dashboard_cont_21, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_dashboard_cont_21, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_cont_21, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_dashboard_lbl_temp
    ui->scr_dashboard_lbl_temp = lv_label_create(ui->scr_dashboard_cont_21);
    lv_obj_set_pos(ui->scr_dashboard_lbl_temp, 15, 13);
    lv_obj_set_size(ui->scr_dashboard_lbl_temp, 81, 24);
    lv_label_set_text(ui->scr_dashboard_lbl_temp, "TEMP");
    lv_label_set_long_mode(ui->scr_dashboard_lbl_temp, LV_LABEL_LONG_WRAP);

    //Write style for scr_dashboard_lbl_temp, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_dashboard_lbl_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_dashboard_lbl_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_dashboard_lbl_temp, lv_color_hex(0xCBD5E1), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_dashboard_lbl_temp, &lv_font_Roboto_Black_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_dashboard_lbl_temp, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_dashboard_lbl_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_dashboard_lbl_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_dashboard_lbl_temp, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_dashboard_lbl_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_dashboard_lbl_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_dashboard_lbl_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_dashboard_lbl_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_dashboard_lbl_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_lbl_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_dashboard_lbl_temp_val
    ui->scr_dashboard_lbl_temp_val = lv_label_create(ui->scr_dashboard_cont_21);
    lv_obj_set_pos(ui->scr_dashboard_lbl_temp_val, 19, 51);
    lv_obj_set_size(ui->scr_dashboard_lbl_temp_val, 121, 44);
    lv_label_set_text(ui->scr_dashboard_lbl_temp_val, "30.0");
    lv_label_set_long_mode(ui->scr_dashboard_lbl_temp_val, LV_LABEL_LONG_WRAP);

    //Write style for scr_dashboard_lbl_temp_val, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_dashboard_lbl_temp_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_dashboard_lbl_temp_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_dashboard_lbl_temp_val, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_dashboard_lbl_temp_val, &lv_font_Roboto_Black_48, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_dashboard_lbl_temp_val, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_dashboard_lbl_temp_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_dashboard_lbl_temp_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_dashboard_lbl_temp_val, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_dashboard_lbl_temp_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_dashboard_lbl_temp_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_dashboard_lbl_temp_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_dashboard_lbl_temp_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_dashboard_lbl_temp_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_lbl_temp_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_dashboard_lbl_temp_unit
    ui->scr_dashboard_lbl_temp_unit = lv_label_create(ui->scr_dashboard_cont_21);
    lv_obj_set_pos(ui->scr_dashboard_lbl_temp_unit, 147, 72);
    lv_obj_set_size(ui->scr_dashboard_lbl_temp_unit, 60, 24);
    lv_label_set_text(ui->scr_dashboard_lbl_temp_unit, "°C");
    lv_label_set_long_mode(ui->scr_dashboard_lbl_temp_unit, LV_LABEL_LONG_WRAP);

    //Write style for scr_dashboard_lbl_temp_unit, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_dashboard_lbl_temp_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_dashboard_lbl_temp_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_dashboard_lbl_temp_unit, lv_color_hex(0xCBD5E1), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_dashboard_lbl_temp_unit, &lv_font_Roboto_Black_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_dashboard_lbl_temp_unit, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_dashboard_lbl_temp_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_dashboard_lbl_temp_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_dashboard_lbl_temp_unit, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_dashboard_lbl_temp_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_dashboard_lbl_temp_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_dashboard_lbl_temp_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_dashboard_lbl_temp_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_dashboard_lbl_temp_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_lbl_temp_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_dashboard_img_temp
    ui->scr_dashboard_img_temp = lv_image_create(ui->scr_dashboard_cont_21);
    lv_obj_set_pos(ui->scr_dashboard_img_temp, 150, 15);
    lv_obj_set_size(ui->scr_dashboard_img_temp, 32, 32);
    lv_obj_add_flag(ui->scr_dashboard_img_temp, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->scr_dashboard_img_temp, &_weather_RGB565A8_32x32);
    lv_image_set_pivot(ui->scr_dashboard_img_temp, 50,50);
    lv_image_set_rotation(ui->scr_dashboard_img_temp, 0);

    //Write style for scr_dashboard_img_temp, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->scr_dashboard_img_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->scr_dashboard_img_temp, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_dashboard_cont_humi
    ui->scr_dashboard_cont_humi = lv_obj_create(ui->scr_dashboard_cont_dashboard);
    lv_obj_set_pos(ui->scr_dashboard_cont_humi, 467, 289);
    lv_obj_set_size(ui->scr_dashboard_cont_humi, 211, 116);
    lv_obj_set_scrollbar_mode(ui->scr_dashboard_cont_humi, LV_SCROLLBAR_MODE_OFF);

    //Write style for scr_dashboard_cont_humi, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_dashboard_cont_humi, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scr_dashboard_cont_humi, 25, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scr_dashboard_cont_humi, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scr_dashboard_cont_humi, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_dashboard_cont_humi, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_dashboard_cont_humi, 244, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_dashboard_cont_humi, lv_color_hex(0x0F172A), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_dashboard_cont_humi, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_dashboard_cont_humi, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_dashboard_cont_humi, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_dashboard_cont_humi, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_dashboard_cont_humi, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_cont_humi, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_dashboard_lbl_humi
    ui->scr_dashboard_lbl_humi = lv_label_create(ui->scr_dashboard_cont_humi);
    lv_obj_set_pos(ui->scr_dashboard_lbl_humi, 15, 13);
    lv_obj_set_size(ui->scr_dashboard_lbl_humi, 81, 24);
    lv_label_set_text(ui->scr_dashboard_lbl_humi, "HUMI");
    lv_label_set_long_mode(ui->scr_dashboard_lbl_humi, LV_LABEL_LONG_WRAP);

    //Write style for scr_dashboard_lbl_humi, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_dashboard_lbl_humi, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_dashboard_lbl_humi, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_dashboard_lbl_humi, lv_color_hex(0xCBD5E1), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_dashboard_lbl_humi, &lv_font_Roboto_Black_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_dashboard_lbl_humi, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_dashboard_lbl_humi, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_dashboard_lbl_humi, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_dashboard_lbl_humi, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_dashboard_lbl_humi, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_dashboard_lbl_humi, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_dashboard_lbl_humi, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_dashboard_lbl_humi, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_dashboard_lbl_humi, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_lbl_humi, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_dashboard_lbl_humi_val
    ui->scr_dashboard_lbl_humi_val = lv_label_create(ui->scr_dashboard_cont_humi);
    lv_obj_set_pos(ui->scr_dashboard_lbl_humi_val, 19, 52);
    lv_obj_set_size(ui->scr_dashboard_lbl_humi_val, 121, 44);
    lv_label_set_text(ui->scr_dashboard_lbl_humi_val, "70.0");
    lv_label_set_long_mode(ui->scr_dashboard_lbl_humi_val, LV_LABEL_LONG_WRAP);

    //Write style for scr_dashboard_lbl_humi_val, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_dashboard_lbl_humi_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_dashboard_lbl_humi_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_dashboard_lbl_humi_val, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_dashboard_lbl_humi_val, &lv_font_Roboto_Black_48, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_dashboard_lbl_humi_val, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_dashboard_lbl_humi_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_dashboard_lbl_humi_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_dashboard_lbl_humi_val, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_dashboard_lbl_humi_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_dashboard_lbl_humi_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_dashboard_lbl_humi_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_dashboard_lbl_humi_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_dashboard_lbl_humi_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_lbl_humi_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_dashboard_lbl_humi_unit
    ui->scr_dashboard_lbl_humi_unit = lv_label_create(ui->scr_dashboard_cont_humi);
    lv_obj_set_pos(ui->scr_dashboard_lbl_humi_unit, 148, 72);
    lv_obj_set_size(ui->scr_dashboard_lbl_humi_unit, 60, 24);
    lv_label_set_text(ui->scr_dashboard_lbl_humi_unit, "%");
    lv_label_set_long_mode(ui->scr_dashboard_lbl_humi_unit, LV_LABEL_LONG_WRAP);

    //Write style for scr_dashboard_lbl_humi_unit, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_dashboard_lbl_humi_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_dashboard_lbl_humi_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_dashboard_lbl_humi_unit, lv_color_hex(0xCBD5E1), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_dashboard_lbl_humi_unit, &lv_font_Roboto_Black_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_dashboard_lbl_humi_unit, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_dashboard_lbl_humi_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_dashboard_lbl_humi_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_dashboard_lbl_humi_unit, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_dashboard_lbl_humi_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_dashboard_lbl_humi_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_dashboard_lbl_humi_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_dashboard_lbl_humi_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_dashboard_lbl_humi_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_lbl_humi_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_dashboard_img_humi
    ui->scr_dashboard_img_humi = lv_image_create(ui->scr_dashboard_cont_humi);
    lv_obj_set_pos(ui->scr_dashboard_img_humi, 150, 15);
    lv_obj_set_size(ui->scr_dashboard_img_humi, 32, 32);
    lv_obj_add_flag(ui->scr_dashboard_img_humi, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->scr_dashboard_img_humi, &_humidity_RGB565A8_32x32);
    lv_image_set_pivot(ui->scr_dashboard_img_humi, 50,50);
    lv_image_set_rotation(ui->scr_dashboard_img_humi, 0);

    //Write style for scr_dashboard_img_humi, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->scr_dashboard_img_humi, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->scr_dashboard_img_humi, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_dashboard_cont_no2
    ui->scr_dashboard_cont_no2 = lv_obj_create(ui->scr_dashboard_cont_dashboard);
    lv_obj_set_pos(ui->scr_dashboard_cont_no2, 243, 161);
    lv_obj_set_size(ui->scr_dashboard_cont_no2, 99, 116);
    lv_obj_set_scrollbar_mode(ui->scr_dashboard_cont_no2, LV_SCROLLBAR_MODE_OFF);

    //Write style for scr_dashboard_cont_no2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_dashboard_cont_no2, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scr_dashboard_cont_no2, 25, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scr_dashboard_cont_no2, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scr_dashboard_cont_no2, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_dashboard_cont_no2, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_dashboard_cont_no2, 244, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_dashboard_cont_no2, lv_color_hex(0x0F172A), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_dashboard_cont_no2, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_dashboard_cont_no2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_dashboard_cont_no2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_dashboard_cont_no2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_dashboard_cont_no2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_cont_no2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_dashboard_lbl_no2
    ui->scr_dashboard_lbl_no2 = lv_label_create(ui->scr_dashboard_cont_no2);
    lv_obj_set_pos(ui->scr_dashboard_lbl_no2, 15, 13);
    lv_obj_set_size(ui->scr_dashboard_lbl_no2, 81, 11);
    lv_label_set_text(ui->scr_dashboard_lbl_no2, "NO2");
    lv_label_set_long_mode(ui->scr_dashboard_lbl_no2, LV_LABEL_LONG_WRAP);

    //Write style for scr_dashboard_lbl_no2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_dashboard_lbl_no2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_dashboard_lbl_no2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_dashboard_lbl_no2, lv_color_hex(0xCBD5E1), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_dashboard_lbl_no2, &lv_font_Roboto_Black_11, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_dashboard_lbl_no2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_dashboard_lbl_no2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_dashboard_lbl_no2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_dashboard_lbl_no2, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_dashboard_lbl_no2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_dashboard_lbl_no2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_dashboard_lbl_no2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_dashboard_lbl_no2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_dashboard_lbl_no2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_lbl_no2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_dashboard_lbl_no2_val
    ui->scr_dashboard_lbl_no2_val = lv_label_create(ui->scr_dashboard_cont_no2);
    lv_obj_set_pos(ui->scr_dashboard_lbl_no2_val, 8, 45);
    lv_obj_set_size(ui->scr_dashboard_lbl_no2_val, 66, 27);
    lv_label_set_text(ui->scr_dashboard_lbl_no2_val, "12.4");
    lv_label_set_long_mode(ui->scr_dashboard_lbl_no2_val, LV_LABEL_LONG_WRAP);

    //Write style for scr_dashboard_lbl_no2_val, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_dashboard_lbl_no2_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_dashboard_lbl_no2_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_dashboard_lbl_no2_val, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_dashboard_lbl_no2_val, &lv_font_Roboto_Black_24, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_dashboard_lbl_no2_val, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_dashboard_lbl_no2_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_dashboard_lbl_no2_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_dashboard_lbl_no2_val, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_dashboard_lbl_no2_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_dashboard_lbl_no2_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_dashboard_lbl_no2_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_dashboard_lbl_no2_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_dashboard_lbl_no2_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_lbl_no2_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_dashboard_lbl_no2_unit
    ui->scr_dashboard_lbl_no2_unit = lv_label_create(ui->scr_dashboard_cont_no2);
    lv_obj_set_pos(ui->scr_dashboard_lbl_no2_unit, 62, 88);
    lv_obj_set_size(ui->scr_dashboard_lbl_no2_unit, 25, 12);
    lv_label_set_text(ui->scr_dashboard_lbl_no2_unit, "PPM");
    lv_label_set_long_mode(ui->scr_dashboard_lbl_no2_unit, LV_LABEL_LONG_WRAP);

    //Write style for scr_dashboard_lbl_no2_unit, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_dashboard_lbl_no2_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_dashboard_lbl_no2_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_dashboard_lbl_no2_unit, lv_color_hex(0xCBD5E1), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_dashboard_lbl_no2_unit, &lv_font_Roboto_Black_9, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_dashboard_lbl_no2_unit, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_dashboard_lbl_no2_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_dashboard_lbl_no2_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_dashboard_lbl_no2_unit, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_dashboard_lbl_no2_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_dashboard_lbl_no2_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_dashboard_lbl_no2_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_dashboard_lbl_no2_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_dashboard_lbl_no2_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_lbl_no2_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_dashboard_cont_o3
    ui->scr_dashboard_cont_o3 = lv_obj_create(ui->scr_dashboard_cont_dashboard);
    lv_obj_set_pos(ui->scr_dashboard_cont_o3, 355, 161);
    lv_obj_set_size(ui->scr_dashboard_cont_o3, 99, 116);
    lv_obj_set_scrollbar_mode(ui->scr_dashboard_cont_o3, LV_SCROLLBAR_MODE_OFF);

    //Write style for scr_dashboard_cont_o3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_dashboard_cont_o3, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scr_dashboard_cont_o3, 25, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scr_dashboard_cont_o3, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scr_dashboard_cont_o3, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_dashboard_cont_o3, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_dashboard_cont_o3, 244, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_dashboard_cont_o3, lv_color_hex(0x0F172A), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_dashboard_cont_o3, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_dashboard_cont_o3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_dashboard_cont_o3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_dashboard_cont_o3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_dashboard_cont_o3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_cont_o3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_dashboard_lbl_03
    ui->scr_dashboard_lbl_03 = lv_label_create(ui->scr_dashboard_cont_o3);
    lv_obj_set_pos(ui->scr_dashboard_lbl_03, 15, 13);
    lv_obj_set_size(ui->scr_dashboard_lbl_03, 81, 11);
    lv_label_set_text(ui->scr_dashboard_lbl_03, "O3");
    lv_label_set_long_mode(ui->scr_dashboard_lbl_03, LV_LABEL_LONG_WRAP);

    //Write style for scr_dashboard_lbl_03, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_dashboard_lbl_03, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_dashboard_lbl_03, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_dashboard_lbl_03, lv_color_hex(0xCBD5E1), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_dashboard_lbl_03, &lv_font_Roboto_Black_11, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_dashboard_lbl_03, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_dashboard_lbl_03, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_dashboard_lbl_03, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_dashboard_lbl_03, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_dashboard_lbl_03, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_dashboard_lbl_03, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_dashboard_lbl_03, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_dashboard_lbl_03, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_dashboard_lbl_03, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_lbl_03, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_dashboard_lbl_03_val
    ui->scr_dashboard_lbl_03_val = lv_label_create(ui->scr_dashboard_cont_o3);
    lv_obj_set_pos(ui->scr_dashboard_lbl_03_val, 8, 45);
    lv_obj_set_size(ui->scr_dashboard_lbl_03_val, 66, 27);
    lv_label_set_text(ui->scr_dashboard_lbl_03_val, "12.4");
    lv_label_set_long_mode(ui->scr_dashboard_lbl_03_val, LV_LABEL_LONG_WRAP);

    //Write style for scr_dashboard_lbl_03_val, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_dashboard_lbl_03_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_dashboard_lbl_03_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_dashboard_lbl_03_val, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_dashboard_lbl_03_val, &lv_font_Roboto_Black_24, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_dashboard_lbl_03_val, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_dashboard_lbl_03_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_dashboard_lbl_03_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_dashboard_lbl_03_val, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_dashboard_lbl_03_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_dashboard_lbl_03_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_dashboard_lbl_03_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_dashboard_lbl_03_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_dashboard_lbl_03_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_lbl_03_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_dashboard_lbl_o3_unit
    ui->scr_dashboard_lbl_o3_unit = lv_label_create(ui->scr_dashboard_cont_o3);
    lv_obj_set_pos(ui->scr_dashboard_lbl_o3_unit, 62, 88);
    lv_obj_set_size(ui->scr_dashboard_lbl_o3_unit, 25, 12);
    lv_label_set_text(ui->scr_dashboard_lbl_o3_unit, "PPM");
    lv_label_set_long_mode(ui->scr_dashboard_lbl_o3_unit, LV_LABEL_LONG_WRAP);

    //Write style for scr_dashboard_lbl_o3_unit, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_dashboard_lbl_o3_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_dashboard_lbl_o3_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_dashboard_lbl_o3_unit, lv_color_hex(0xCBD5E1), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_dashboard_lbl_o3_unit, &lv_font_Roboto_Black_9, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_dashboard_lbl_o3_unit, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_dashboard_lbl_o3_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_dashboard_lbl_o3_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_dashboard_lbl_o3_unit, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_dashboard_lbl_o3_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_dashboard_lbl_o3_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_dashboard_lbl_o3_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_dashboard_lbl_o3_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_dashboard_lbl_o3_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_lbl_o3_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_dashboard_cont_co2
    ui->scr_dashboard_cont_co2 = lv_obj_create(ui->scr_dashboard_cont_dashboard);
    lv_obj_set_pos(ui->scr_dashboard_cont_co2, 467, 161);
    lv_obj_set_size(ui->scr_dashboard_cont_co2, 99, 116);
    lv_obj_set_scrollbar_mode(ui->scr_dashboard_cont_co2, LV_SCROLLBAR_MODE_OFF);

    //Write style for scr_dashboard_cont_co2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_dashboard_cont_co2, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scr_dashboard_cont_co2, 25, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scr_dashboard_cont_co2, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scr_dashboard_cont_co2, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_dashboard_cont_co2, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_dashboard_cont_co2, 244, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_dashboard_cont_co2, lv_color_hex(0x0F172A), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_dashboard_cont_co2, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_dashboard_cont_co2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_dashboard_cont_co2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_dashboard_cont_co2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_dashboard_cont_co2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_cont_co2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_dashboard_lbl_co2
    ui->scr_dashboard_lbl_co2 = lv_label_create(ui->scr_dashboard_cont_co2);
    lv_obj_set_pos(ui->scr_dashboard_lbl_co2, 15, 13);
    lv_obj_set_size(ui->scr_dashboard_lbl_co2, 81, 11);
    lv_label_set_text(ui->scr_dashboard_lbl_co2, "CO2");
    lv_label_set_long_mode(ui->scr_dashboard_lbl_co2, LV_LABEL_LONG_WRAP);

    //Write style for scr_dashboard_lbl_co2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_dashboard_lbl_co2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_dashboard_lbl_co2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_dashboard_lbl_co2, lv_color_hex(0xCBD5E1), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_dashboard_lbl_co2, &lv_font_Roboto_Black_11, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_dashboard_lbl_co2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_dashboard_lbl_co2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_dashboard_lbl_co2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_dashboard_lbl_co2, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_dashboard_lbl_co2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_dashboard_lbl_co2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_dashboard_lbl_co2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_dashboard_lbl_co2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_dashboard_lbl_co2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_lbl_co2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_dashboard_lbl_co2_val
    ui->scr_dashboard_lbl_co2_val = lv_label_create(ui->scr_dashboard_cont_co2);
    lv_obj_set_pos(ui->scr_dashboard_lbl_co2_val, 8, 45);
    lv_obj_set_size(ui->scr_dashboard_lbl_co2_val, 66, 27);
    lv_label_set_text(ui->scr_dashboard_lbl_co2_val, "12.4");
    lv_label_set_long_mode(ui->scr_dashboard_lbl_co2_val, LV_LABEL_LONG_WRAP);

    //Write style for scr_dashboard_lbl_co2_val, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_dashboard_lbl_co2_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_dashboard_lbl_co2_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_dashboard_lbl_co2_val, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_dashboard_lbl_co2_val, &lv_font_Roboto_Black_24, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_dashboard_lbl_co2_val, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_dashboard_lbl_co2_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_dashboard_lbl_co2_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_dashboard_lbl_co2_val, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_dashboard_lbl_co2_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_dashboard_lbl_co2_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_dashboard_lbl_co2_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_dashboard_lbl_co2_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_dashboard_lbl_co2_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_lbl_co2_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_dashboard_lbl_co2_unit
    ui->scr_dashboard_lbl_co2_unit = lv_label_create(ui->scr_dashboard_cont_co2);
    lv_obj_set_pos(ui->scr_dashboard_lbl_co2_unit, 62, 88);
    lv_obj_set_size(ui->scr_dashboard_lbl_co2_unit, 25, 12);
    lv_label_set_text(ui->scr_dashboard_lbl_co2_unit, "PPM");
    lv_label_set_long_mode(ui->scr_dashboard_lbl_co2_unit, LV_LABEL_LONG_WRAP);

    //Write style for scr_dashboard_lbl_co2_unit, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_dashboard_lbl_co2_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_dashboard_lbl_co2_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_dashboard_lbl_co2_unit, lv_color_hex(0xCBD5E1), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_dashboard_lbl_co2_unit, &lv_font_Roboto_Black_9, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_dashboard_lbl_co2_unit, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_dashboard_lbl_co2_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_dashboard_lbl_co2_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_dashboard_lbl_co2_unit, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_dashboard_lbl_co2_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_dashboard_lbl_co2_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_dashboard_lbl_co2_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_dashboard_lbl_co2_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_dashboard_lbl_co2_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_lbl_co2_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_dashboard_cont_so2
    ui->scr_dashboard_cont_so2 = lv_obj_create(ui->scr_dashboard_cont_dashboard);
    lv_obj_set_pos(ui->scr_dashboard_cont_so2, 579, 161);
    lv_obj_set_size(ui->scr_dashboard_cont_so2, 99, 116);
    lv_obj_set_scrollbar_mode(ui->scr_dashboard_cont_so2, LV_SCROLLBAR_MODE_OFF);

    //Write style for scr_dashboard_cont_so2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_dashboard_cont_so2, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scr_dashboard_cont_so2, 25, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scr_dashboard_cont_so2, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scr_dashboard_cont_so2, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_dashboard_cont_so2, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_dashboard_cont_so2, 244, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_dashboard_cont_so2, lv_color_hex(0x0F172A), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_dashboard_cont_so2, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_dashboard_cont_so2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_dashboard_cont_so2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_dashboard_cont_so2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_dashboard_cont_so2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_cont_so2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_dashboard_lbl_so2
    ui->scr_dashboard_lbl_so2 = lv_label_create(ui->scr_dashboard_cont_so2);
    lv_obj_set_pos(ui->scr_dashboard_lbl_so2, 15, 13);
    lv_obj_set_size(ui->scr_dashboard_lbl_so2, 81, 11);
    lv_label_set_text(ui->scr_dashboard_lbl_so2, "SO2");
    lv_label_set_long_mode(ui->scr_dashboard_lbl_so2, LV_LABEL_LONG_WRAP);

    //Write style for scr_dashboard_lbl_so2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_dashboard_lbl_so2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_dashboard_lbl_so2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_dashboard_lbl_so2, lv_color_hex(0xCBD5E1), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_dashboard_lbl_so2, &lv_font_Roboto_Black_11, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_dashboard_lbl_so2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_dashboard_lbl_so2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_dashboard_lbl_so2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_dashboard_lbl_so2, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_dashboard_lbl_so2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_dashboard_lbl_so2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_dashboard_lbl_so2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_dashboard_lbl_so2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_dashboard_lbl_so2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_lbl_so2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_dashboard_lbl_so2_val
    ui->scr_dashboard_lbl_so2_val = lv_label_create(ui->scr_dashboard_cont_so2);
    lv_obj_set_pos(ui->scr_dashboard_lbl_so2_val, 8, 45);
    lv_obj_set_size(ui->scr_dashboard_lbl_so2_val, 66, 27);
    lv_label_set_text(ui->scr_dashboard_lbl_so2_val, "12.4");
    lv_label_set_long_mode(ui->scr_dashboard_lbl_so2_val, LV_LABEL_LONG_WRAP);

    //Write style for scr_dashboard_lbl_so2_val, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_dashboard_lbl_so2_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_dashboard_lbl_so2_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_dashboard_lbl_so2_val, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_dashboard_lbl_so2_val, &lv_font_Roboto_Black_24, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_dashboard_lbl_so2_val, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_dashboard_lbl_so2_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_dashboard_lbl_so2_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_dashboard_lbl_so2_val, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_dashboard_lbl_so2_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_dashboard_lbl_so2_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_dashboard_lbl_so2_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_dashboard_lbl_so2_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_dashboard_lbl_so2_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_lbl_so2_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_dashboard_lbl_so2_unit
    ui->scr_dashboard_lbl_so2_unit = lv_label_create(ui->scr_dashboard_cont_so2);
    lv_obj_set_pos(ui->scr_dashboard_lbl_so2_unit, 62, 88);
    lv_obj_set_size(ui->scr_dashboard_lbl_so2_unit, 25, 12);
    lv_label_set_text(ui->scr_dashboard_lbl_so2_unit, "PPM");
    lv_label_set_long_mode(ui->scr_dashboard_lbl_so2_unit, LV_LABEL_LONG_WRAP);

    //Write style for scr_dashboard_lbl_so2_unit, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_dashboard_lbl_so2_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_dashboard_lbl_so2_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_dashboard_lbl_so2_unit, lv_color_hex(0xCBD5E1), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_dashboard_lbl_so2_unit, &lv_font_Roboto_Black_9, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_dashboard_lbl_so2_unit, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_dashboard_lbl_so2_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_dashboard_lbl_so2_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_dashboard_lbl_so2_unit, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_dashboard_lbl_so2_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_dashboard_lbl_so2_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_dashboard_lbl_so2_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_dashboard_lbl_so2_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_dashboard_lbl_so2_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_lbl_so2_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_dashboard_cont_data_analysis
    ui->scr_dashboard_cont_data_analysis = lv_obj_create(ui->scr_dashboard);
    lv_obj_set_pos(ui->scr_dashboard_cont_data_analysis, 100, 49);
    lv_obj_set_size(ui->scr_dashboard_cont_data_analysis, 680, 420);
    lv_obj_set_scrollbar_mode(ui->scr_dashboard_cont_data_analysis, LV_SCROLLBAR_MODE_OFF);
    lv_obj_add_flag(ui->scr_dashboard_cont_data_analysis, LV_OBJ_FLAG_HIDDEN);

    //Write style for scr_dashboard_cont_data_analysis, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_dashboard_cont_data_analysis, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_dashboard_cont_data_analysis, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_dashboard_cont_data_analysis, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_dashboard_cont_data_analysis, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_dashboard_cont_data_analysis, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_dashboard_cont_data_analysis, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_dashboard_cont_data_analysis, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_cont_data_analysis, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_dashboard_label_analysis
    ui->scr_dashboard_label_analysis = lv_label_create(ui->scr_dashboard_cont_data_analysis);
    lv_obj_set_pos(ui->scr_dashboard_label_analysis, 0, 5);
    lv_obj_set_size(ui->scr_dashboard_label_analysis, 172, 11);
    lv_label_set_text(ui->scr_dashboard_label_analysis, "DATA ANALYSIS TRENDS");
    lv_label_set_long_mode(ui->scr_dashboard_label_analysis, LV_LABEL_LONG_WRAP);

    //Write style for scr_dashboard_label_analysis, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_dashboard_label_analysis, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_dashboard_label_analysis, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_dashboard_label_analysis, lv_color_hex(0x64748B), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_dashboard_label_analysis, &lv_font_Roboto_Black_10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_dashboard_label_analysis, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_dashboard_label_analysis, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_dashboard_label_analysis, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_dashboard_label_analysis, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_dashboard_label_analysis, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_dashboard_label_analysis, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_dashboard_label_analysis, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_dashboard_label_analysis, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_dashboard_label_analysis, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_label_analysis, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_dashboard_cont_trends
    ui->scr_dashboard_cont_trends = lv_obj_create(ui->scr_dashboard_cont_data_analysis);
    lv_obj_set_pos(ui->scr_dashboard_cont_trends, 0, 37);
    lv_obj_set_size(ui->scr_dashboard_cont_trends, 424, 372);
    lv_obj_set_scrollbar_mode(ui->scr_dashboard_cont_trends, LV_SCROLLBAR_MODE_OFF);

    //Write style for scr_dashboard_cont_trends, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_dashboard_cont_trends, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scr_dashboard_cont_trends, 45, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scr_dashboard_cont_trends, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scr_dashboard_cont_trends, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_dashboard_cont_trends, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_dashboard_cont_trends, 243, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_dashboard_cont_trends, lv_color_hex(0x0F172A), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_dashboard_cont_trends, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_dashboard_cont_trends, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_dashboard_cont_trends, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_dashboard_cont_trends, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_dashboard_cont_trends, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_cont_trends, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_dashboard_cont_chart
    ui->scr_dashboard_cont_chart = lv_obj_create(ui->scr_dashboard_cont_trends);
    lv_obj_set_pos(ui->scr_dashboard_cont_chart, 22, 53);
    lv_obj_set_size(ui->scr_dashboard_cont_chart, 380, 300);
    lv_obj_set_scrollbar_mode(ui->scr_dashboard_cont_chart, LV_SCROLLBAR_MODE_OFF);

    //Write style for scr_dashboard_cont_chart, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_dashboard_cont_chart, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scr_dashboard_cont_chart, 45, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scr_dashboard_cont_chart, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scr_dashboard_cont_chart, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_dashboard_cont_chart, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_dashboard_cont_chart, 78, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_dashboard_cont_chart, lv_color_hex(0x08143d), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_dashboard_cont_chart, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_dashboard_cont_chart, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_dashboard_cont_chart, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_dashboard_cont_chart, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_dashboard_cont_chart, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_cont_chart, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_dashboard_chart
    ui->scr_dashboard_chart = lv_chart_create(ui->scr_dashboard_cont_chart);
    lv_obj_set_pos(ui->scr_dashboard_chart, 9, 27);
    lv_obj_set_size(ui->scr_dashboard_chart, 355, 250);
    lv_obj_set_scrollbar_mode(ui->scr_dashboard_chart, LV_SCROLLBAR_MODE_OFF);
    lv_chart_set_type(ui->scr_dashboard_chart, LV_CHART_TYPE_LINE);
    lv_chart_set_div_line_count(ui->scr_dashboard_chart, 3, 5);
    lv_chart_set_point_count(ui->scr_dashboard_chart, 5);
    lv_chart_set_range(ui->scr_dashboard_chart, LV_CHART_AXIS_PRIMARY_Y, 0, 500);
    lv_chart_set_range(ui->scr_dashboard_chart, LV_CHART_AXIS_SECONDARY_Y, 0, 100);
    ui->scr_dashboard_chart_0 = lv_chart_add_series(ui->scr_dashboard_chart, lv_color_hex(0xffffff), LV_CHART_AXIS_PRIMARY_Y);
#if LV_USE_FREEMASTER == 0
    lv_chart_set_next_value(ui->scr_dashboard_chart, ui->scr_dashboard_chart_0, 1);
    lv_chart_set_next_value(ui->scr_dashboard_chart, ui->scr_dashboard_chart_0, 50);
    lv_chart_set_next_value(ui->scr_dashboard_chart, ui->scr_dashboard_chart_0, 100);
    lv_chart_set_next_value(ui->scr_dashboard_chart, ui->scr_dashboard_chart_0, 200);
    lv_chart_set_next_value(ui->scr_dashboard_chart, ui->scr_dashboard_chart_0, 50);
#endif
    ui->scr_dashboard_chart_1 = lv_chart_add_series(ui->scr_dashboard_chart, lv_color_hex(0x000000), LV_CHART_AXIS_PRIMARY_Y);
#if LV_USE_FREEMASTER == 0
    lv_chart_set_next_value(ui->scr_dashboard_chart, ui->scr_dashboard_chart_1, 100);
    lv_chart_set_next_value(ui->scr_dashboard_chart, ui->scr_dashboard_chart_1, 200);
    lv_chart_set_next_value(ui->scr_dashboard_chart, ui->scr_dashboard_chart_1, 40);
    lv_chart_set_next_value(ui->scr_dashboard_chart, ui->scr_dashboard_chart_1, 80);
    lv_chart_set_next_value(ui->scr_dashboard_chart, ui->scr_dashboard_chart_1, 300);
#endif
    ui->scr_dashboard_chart_2 = lv_chart_add_series(ui->scr_dashboard_chart, lv_color_hex(0x098D6B), LV_CHART_AXIS_PRIMARY_Y);
#if LV_USE_FREEMASTER == 0
    lv_chart_set_next_value(ui->scr_dashboard_chart, ui->scr_dashboard_chart_2, 30);
    lv_chart_set_next_value(ui->scr_dashboard_chart, ui->scr_dashboard_chart_2, 200);
    lv_chart_set_next_value(ui->scr_dashboard_chart, ui->scr_dashboard_chart_2, 300);
    lv_chart_set_next_value(ui->scr_dashboard_chart, ui->scr_dashboard_chart_2, 100);
    lv_chart_set_next_value(ui->scr_dashboard_chart, ui->scr_dashboard_chart_2, 50);
#endif

    //Write style for scr_dashboard_chart, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->scr_dashboard_chart, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->scr_dashboard_chart, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scr_dashboard_chart, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scr_dashboard_chart, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scr_dashboard_chart, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_dashboard_chart, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_width(ui->scr_dashboard_chart, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_color(ui->scr_dashboard_chart, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_opa(ui->scr_dashboard_chart, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_chart, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for scr_dashboard_chart, Part: LV_PART_MAIN, State: LV_STATE_FOCUSED.
    lv_obj_set_style_border_width(ui->scr_dashboard_chart, 1, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_opa(ui->scr_dashboard_chart, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_color(ui->scr_dashboard_chart, lv_color_hex(0xe8e8e8), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_side(ui->scr_dashboard_chart, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_opa(ui->scr_dashboard_chart, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_radius(ui->scr_dashboard_chart, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_line_opa(ui->scr_dashboard_chart, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_chart, 0, LV_PART_MAIN|LV_STATE_FOCUSED);

    //Write codes scr_dashboard_label_trends
    ui->scr_dashboard_label_trends = lv_label_create(ui->scr_dashboard_cont_trends);
    lv_obj_set_pos(ui->scr_dashboard_label_trends, 21, 21);
    lv_obj_set_size(ui->scr_dashboard_label_trends, 168, 19);
    lv_label_set_text(ui->scr_dashboard_label_trends, "TRENDS ANALYSIS");
    lv_label_set_long_mode(ui->scr_dashboard_label_trends, LV_LABEL_LONG_WRAP);

    //Write style for scr_dashboard_label_trends, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_dashboard_label_trends, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_dashboard_label_trends, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_dashboard_label_trends, lv_color_hex(0xABABAB), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_dashboard_label_trends, &lv_font_Roboto_Black_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_dashboard_label_trends, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_dashboard_label_trends, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_dashboard_label_trends, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_dashboard_label_trends, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_dashboard_label_trends, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_dashboard_label_trends, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_dashboard_label_trends, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_dashboard_label_trends, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_dashboard_label_trends, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_label_trends, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_dashboard_ddlist_trends
    ui->scr_dashboard_ddlist_trends = lv_dropdown_create(ui->scr_dashboard_cont_trends);
    lv_obj_set_pos(ui->scr_dashboard_ddlist_trends, 301, 7);
    lv_obj_set_size(ui->scr_dashboard_ddlist_trends, 100, 38);
    lv_dropdown_set_options(ui->scr_dashboard_ddlist_trends, "AQI\nPM 2.5\nPM 10");

    //Write style for scr_dashboard_ddlist_trends, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->scr_dashboard_ddlist_trends, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_dashboard_ddlist_trends, &lv_font_Roboto_Bold_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_dashboard_ddlist_trends, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->scr_dashboard_ddlist_trends, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scr_dashboard_ddlist_trends, 48, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scr_dashboard_ddlist_trends, lv_color_hex(0xe1e6ee), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scr_dashboard_ddlist_trends, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_dashboard_ddlist_trends, 12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_dashboard_ddlist_trends, 12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_dashboard_ddlist_trends, 12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_dashboard_ddlist_trends, 12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_dashboard_ddlist_trends, 154, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_dashboard_ddlist_trends, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_dashboard_ddlist_trends, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_ddlist_trends, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for scr_dashboard_ddlist_trends, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_text_color(ui->scr_dashboard_ddlist_trends, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->scr_dashboard_ddlist_trends, &lv_font_Roboto_Black_12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->scr_dashboard_ddlist_trends, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_border_width(ui->scr_dashboard_ddlist_trends, 1, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_border_opa(ui->scr_dashboard_ddlist_trends, 93, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_border_color(ui->scr_dashboard_ddlist_trends, lv_color_hex(0xe1e6ee), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_border_side(ui->scr_dashboard_ddlist_trends, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_pad_top(ui->scr_dashboard_ddlist_trends, 12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_pad_left(ui->scr_dashboard_ddlist_trends, 12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_pad_right(ui->scr_dashboard_ddlist_trends, 12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_radius(ui->scr_dashboard_ddlist_trends, 12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_opa(ui->scr_dashboard_ddlist_trends, 153, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui->scr_dashboard_ddlist_trends, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_grad_dir(ui->scr_dashboard_ddlist_trends, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_ddlist_trends, 0, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write style for scr_dashboard_ddlist_trends, Part: LV_PART_MAIN, State: LV_STATE_FOCUSED.
    lv_obj_set_style_text_color(ui->scr_dashboard_ddlist_trends, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_font(ui->scr_dashboard_ddlist_trends, &lv_font_Roboto_Black_12, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_opa(ui->scr_dashboard_ddlist_trends, 255, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_width(ui->scr_dashboard_ddlist_trends, 1, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_opa(ui->scr_dashboard_ddlist_trends, 57, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_color(ui->scr_dashboard_ddlist_trends, lv_color_hex(0xe1e6ee), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_side(ui->scr_dashboard_ddlist_trends, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_pad_top(ui->scr_dashboard_ddlist_trends, 12, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_pad_left(ui->scr_dashboard_ddlist_trends, 12, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_pad_right(ui->scr_dashboard_ddlist_trends, 12, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_radius(ui->scr_dashboard_ddlist_trends, 12, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_opa(ui->scr_dashboard_ddlist_trends, 154, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_color(ui->scr_dashboard_ddlist_trends, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_grad_dir(ui->scr_dashboard_ddlist_trends, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_ddlist_trends, 0, LV_PART_MAIN|LV_STATE_FOCUSED);

    //Write style for scr_dashboard_ddlist_trends, Part: LV_PART_MAIN, State: LV_STATE_DISABLED.
    lv_obj_set_style_text_color(ui->scr_dashboard_ddlist_trends, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_font(ui->scr_dashboard_ddlist_trends, &lv_font_Roboto_Black_12, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_opa(ui->scr_dashboard_ddlist_trends, 255, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_border_width(ui->scr_dashboard_ddlist_trends, 1, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_border_opa(ui->scr_dashboard_ddlist_trends, 62, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_border_color(ui->scr_dashboard_ddlist_trends, lv_color_hex(0xe1e6ee), LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_border_side(ui->scr_dashboard_ddlist_trends, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_pad_top(ui->scr_dashboard_ddlist_trends, 12, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_pad_left(ui->scr_dashboard_ddlist_trends, 12, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_pad_right(ui->scr_dashboard_ddlist_trends, 12, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_radius(ui->scr_dashboard_ddlist_trends, 12, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_bg_opa(ui->scr_dashboard_ddlist_trends, 154, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_bg_color(ui->scr_dashboard_ddlist_trends, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_bg_grad_dir(ui->scr_dashboard_ddlist_trends, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_ddlist_trends, 0, LV_PART_MAIN|LV_STATE_DISABLED);

    //Write style state: LV_STATE_CHECKED for &style_scr_dashboard_ddlist_trends_extra_list_selected_checked
    static lv_style_t style_scr_dashboard_ddlist_trends_extra_list_selected_checked;
    ui_init_style(&style_scr_dashboard_ddlist_trends_extra_list_selected_checked);

    lv_style_set_border_width(&style_scr_dashboard_ddlist_trends_extra_list_selected_checked, 1);
    lv_style_set_border_opa(&style_scr_dashboard_ddlist_trends_extra_list_selected_checked, 255);
    lv_style_set_border_color(&style_scr_dashboard_ddlist_trends_extra_list_selected_checked, lv_color_hex(0x7a6363));
    lv_style_set_border_side(&style_scr_dashboard_ddlist_trends_extra_list_selected_checked, LV_BORDER_SIDE_FULL);
    lv_style_set_radius(&style_scr_dashboard_ddlist_trends_extra_list_selected_checked, 1);
    lv_style_set_bg_opa(&style_scr_dashboard_ddlist_trends_extra_list_selected_checked, 113);
    lv_style_set_bg_color(&style_scr_dashboard_ddlist_trends_extra_list_selected_checked, lv_color_hex(0x989898));
    lv_style_set_bg_grad_dir(&style_scr_dashboard_ddlist_trends_extra_list_selected_checked, LV_GRAD_DIR_NONE);
    lv_obj_add_style(lv_dropdown_get_list(ui->scr_dashboard_ddlist_trends), &style_scr_dashboard_ddlist_trends_extra_list_selected_checked, LV_PART_SELECTED|LV_STATE_CHECKED);

    //Write style state: LV_STATE_DEFAULT for &style_scr_dashboard_ddlist_trends_extra_list_main_default
    static lv_style_t style_scr_dashboard_ddlist_trends_extra_list_main_default;
    ui_init_style(&style_scr_dashboard_ddlist_trends_extra_list_main_default);

    lv_style_set_max_height(&style_scr_dashboard_ddlist_trends_extra_list_main_default, 90);
    lv_style_set_text_color(&style_scr_dashboard_ddlist_trends_extra_list_main_default, lv_color_hex(0xffffff));
    lv_style_set_text_font(&style_scr_dashboard_ddlist_trends_extra_list_main_default, &lv_font_Roboto_Black_12);
    lv_style_set_text_opa(&style_scr_dashboard_ddlist_trends_extra_list_main_default, 255);
    lv_style_set_border_width(&style_scr_dashboard_ddlist_trends_extra_list_main_default, 0);
    lv_style_set_radius(&style_scr_dashboard_ddlist_trends_extra_list_main_default, 0);
    lv_style_set_bg_opa(&style_scr_dashboard_ddlist_trends_extra_list_main_default, 153);
    lv_style_set_bg_color(&style_scr_dashboard_ddlist_trends_extra_list_main_default, lv_color_hex(0x000000));
    lv_style_set_bg_grad_dir(&style_scr_dashboard_ddlist_trends_extra_list_main_default, LV_GRAD_DIR_NONE);
    lv_obj_add_style(lv_dropdown_get_list(ui->scr_dashboard_ddlist_trends), &style_scr_dashboard_ddlist_trends_extra_list_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_DEFAULT for &style_scr_dashboard_ddlist_trends_extra_list_scrollbar_default
    static lv_style_t style_scr_dashboard_ddlist_trends_extra_list_scrollbar_default;
    ui_init_style(&style_scr_dashboard_ddlist_trends_extra_list_scrollbar_default);

    lv_style_set_radius(&style_scr_dashboard_ddlist_trends_extra_list_scrollbar_default, 4);
    lv_style_set_bg_opa(&style_scr_dashboard_ddlist_trends_extra_list_scrollbar_default, 113);
    lv_style_set_bg_color(&style_scr_dashboard_ddlist_trends_extra_list_scrollbar_default, lv_color_hex(0x000000));
    lv_style_set_bg_grad_dir(&style_scr_dashboard_ddlist_trends_extra_list_scrollbar_default, LV_GRAD_DIR_NONE);
    lv_obj_add_style(lv_dropdown_get_list(ui->scr_dashboard_ddlist_trends), &style_scr_dashboard_ddlist_trends_extra_list_scrollbar_default, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);

    //Write codes scr_dashboard_cont_avg
    ui->scr_dashboard_cont_avg = lv_obj_create(ui->scr_dashboard_cont_data_analysis);
    lv_obj_set_pos(ui->scr_dashboard_cont_avg, 440, 37);
    lv_obj_set_size(ui->scr_dashboard_cont_avg, 235, 117);
    lv_obj_set_scrollbar_mode(ui->scr_dashboard_cont_avg, LV_SCROLLBAR_MODE_OFF);

    //Write style for scr_dashboard_cont_avg, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_dashboard_cont_avg, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scr_dashboard_cont_avg, 45, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scr_dashboard_cont_avg, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scr_dashboard_cont_avg, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_dashboard_cont_avg, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_dashboard_cont_avg, 243, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_dashboard_cont_avg, lv_color_hex(0x0F172A), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_dashboard_cont_avg, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_dashboard_cont_avg, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_dashboard_cont_avg, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_dashboard_cont_avg, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_dashboard_cont_avg, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_cont_avg, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_dashboard_lbl_avg
    ui->scr_dashboard_lbl_avg = lv_label_create(ui->scr_dashboard_cont_avg);
    lv_obj_set_pos(ui->scr_dashboard_lbl_avg, 19, 21);
    lv_obj_set_size(ui->scr_dashboard_lbl_avg, 168, 19);
    lv_label_set_text(ui->scr_dashboard_lbl_avg, "AVERAGE VALUE");
    lv_label_set_long_mode(ui->scr_dashboard_lbl_avg, LV_LABEL_LONG_WRAP);

    //Write style for scr_dashboard_lbl_avg, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_dashboard_lbl_avg, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_dashboard_lbl_avg, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_dashboard_lbl_avg, lv_color_hex(0xABABAB), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_dashboard_lbl_avg, &lv_font_Roboto_Black_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_dashboard_lbl_avg, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_dashboard_lbl_avg, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_dashboard_lbl_avg, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_dashboard_lbl_avg, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_dashboard_lbl_avg, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_dashboard_lbl_avg, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_dashboard_lbl_avg, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_dashboard_lbl_avg, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_dashboard_lbl_avg, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_lbl_avg, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_dashboard_label_avg_val
    ui->scr_dashboard_label_avg_val = lv_label_create(ui->scr_dashboard_cont_avg);
    lv_obj_set_pos(ui->scr_dashboard_label_avg_val, 59, 54);
    lv_obj_set_size(ui->scr_dashboard_label_avg_val, 121, 41);
    lv_label_set_text(ui->scr_dashboard_label_avg_val, "50.0");
    lv_label_set_long_mode(ui->scr_dashboard_label_avg_val, LV_LABEL_LONG_WRAP);

    //Write style for scr_dashboard_label_avg_val, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_dashboard_label_avg_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_dashboard_label_avg_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_dashboard_label_avg_val, lv_color_hex(0x00ff70), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_dashboard_label_avg_val, &lv_font_Roboto_Bold_40, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_dashboard_label_avg_val, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_dashboard_label_avg_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_dashboard_label_avg_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_dashboard_label_avg_val, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_dashboard_label_avg_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_dashboard_label_avg_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_dashboard_label_avg_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_dashboard_label_avg_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_dashboard_label_avg_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_label_avg_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_dashboard_cont_insights
    ui->scr_dashboard_cont_insights = lv_obj_create(ui->scr_dashboard_cont_data_analysis);
    lv_obj_set_pos(ui->scr_dashboard_cont_insights, 440, 168);
    lv_obj_set_size(ui->scr_dashboard_cont_insights, 235, 237);
    lv_obj_set_scrollbar_mode(ui->scr_dashboard_cont_insights, LV_SCROLLBAR_MODE_OFF);

    //Write style for scr_dashboard_cont_insights, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_dashboard_cont_insights, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scr_dashboard_cont_insights, 45, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scr_dashboard_cont_insights, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scr_dashboard_cont_insights, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_dashboard_cont_insights, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_dashboard_cont_insights, 243, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_dashboard_cont_insights, lv_color_hex(0x0F172A), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_dashboard_cont_insights, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_dashboard_cont_insights, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_dashboard_cont_insights, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_dashboard_cont_insights, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_dashboard_cont_insights, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_cont_insights, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_dashboard_btn_generate_report
    ui->scr_dashboard_btn_generate_report = lv_button_create(ui->scr_dashboard_cont_insights);
    lv_obj_set_pos(ui->scr_dashboard_btn_generate_report, 24, 175);
    lv_obj_set_size(ui->scr_dashboard_btn_generate_report, 188, 40);
    ui->scr_dashboard_btn_generate_report_label = lv_label_create(ui->scr_dashboard_btn_generate_report);
    lv_label_set_text(ui->scr_dashboard_btn_generate_report_label, "GENERATE REPORT");
    lv_label_set_long_mode(ui->scr_dashboard_btn_generate_report_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->scr_dashboard_btn_generate_report_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->scr_dashboard_btn_generate_report, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->scr_dashboard_btn_generate_report_label, LV_PCT(100));

    //Write style for scr_dashboard_btn_generate_report, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->scr_dashboard_btn_generate_report, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_dashboard_btn_generate_report, lv_color_hex(0x112333), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_dashboard_btn_generate_report, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->scr_dashboard_btn_generate_report, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scr_dashboard_btn_generate_report, 48, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scr_dashboard_btn_generate_report, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scr_dashboard_btn_generate_report, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_dashboard_btn_generate_report, 12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_btn_generate_report, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_dashboard_btn_generate_report, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_dashboard_btn_generate_report, &lv_font_Roboto_Black_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_dashboard_btn_generate_report, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_dashboard_btn_generate_report, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for scr_dashboard_btn_generate_report, Part: LV_PART_MAIN, State: LV_STATE_FOCUSED.
    lv_obj_set_style_bg_opa(ui->scr_dashboard_btn_generate_report, 255, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_color(ui->scr_dashboard_btn_generate_report, lv_color_hex(0x112333), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_grad_dir(ui->scr_dashboard_btn_generate_report, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_width(ui->scr_dashboard_btn_generate_report, 1, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_opa(ui->scr_dashboard_btn_generate_report, 53, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_color(ui->scr_dashboard_btn_generate_report, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_side(ui->scr_dashboard_btn_generate_report, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_radius(ui->scr_dashboard_btn_generate_report, 12, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_btn_generate_report, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_color(ui->scr_dashboard_btn_generate_report, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_font(ui->scr_dashboard_btn_generate_report, &lv_font_Roboto_Black_16, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_opa(ui->scr_dashboard_btn_generate_report, 255, LV_PART_MAIN|LV_STATE_FOCUSED);

    //Write style for scr_dashboard_btn_generate_report, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_bg_opa(ui->scr_dashboard_btn_generate_report, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_bg_color(ui->scr_dashboard_btn_generate_report, lv_color_hex(0x112333), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_bg_grad_dir(ui->scr_dashboard_btn_generate_report, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui->scr_dashboard_btn_generate_report, 1, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_border_opa(ui->scr_dashboard_btn_generate_report, 53, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_border_color(ui->scr_dashboard_btn_generate_report, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_border_side(ui->scr_dashboard_btn_generate_report, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_radius(ui->scr_dashboard_btn_generate_report, 12, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_btn_generate_report, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->scr_dashboard_btn_generate_report, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->scr_dashboard_btn_generate_report, &lv_font_Roboto_Black_16, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->scr_dashboard_btn_generate_report, 255, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for scr_dashboard_btn_generate_report, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_bg_opa(ui->scr_dashboard_btn_generate_report, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui->scr_dashboard_btn_generate_report, lv_color_hex(0x112333), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_grad_dir(ui->scr_dashboard_btn_generate_report, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_border_width(ui->scr_dashboard_btn_generate_report, 1, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_border_opa(ui->scr_dashboard_btn_generate_report, 48, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_border_color(ui->scr_dashboard_btn_generate_report, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_border_side(ui->scr_dashboard_btn_generate_report, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_radius(ui->scr_dashboard_btn_generate_report, 12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_btn_generate_report, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->scr_dashboard_btn_generate_report, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->scr_dashboard_btn_generate_report, &lv_font_Roboto_Black_16, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->scr_dashboard_btn_generate_report, 255, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write style for scr_dashboard_btn_generate_report, Part: LV_PART_MAIN, State: LV_STATE_DISABLED.
    lv_obj_set_style_bg_opa(ui->scr_dashboard_btn_generate_report, 255, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_bg_color(ui->scr_dashboard_btn_generate_report, lv_color_hex(0x112333), LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_bg_grad_dir(ui->scr_dashboard_btn_generate_report, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_border_width(ui->scr_dashboard_btn_generate_report, 1, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_border_opa(ui->scr_dashboard_btn_generate_report, 65, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_border_color(ui->scr_dashboard_btn_generate_report, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_border_side(ui->scr_dashboard_btn_generate_report, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_radius(ui->scr_dashboard_btn_generate_report, 12, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_btn_generate_report, 0, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_color(ui->scr_dashboard_btn_generate_report, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_font(ui->scr_dashboard_btn_generate_report, &lv_font_Roboto_Black_16, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_opa(ui->scr_dashboard_btn_generate_report, 255, LV_PART_MAIN|LV_STATE_DISABLED);

    //Write codes scr_dashboard_label_insights
    ui->scr_dashboard_label_insights = lv_label_create(ui->scr_dashboard_cont_insights);
    lv_obj_set_pos(ui->scr_dashboard_label_insights, 19, 20);
    lv_obj_set_size(ui->scr_dashboard_label_insights, 182, 19);
    lv_label_set_text(ui->scr_dashboard_label_insights, "DIAGNOSTIC ÍNSIGHTS");
    lv_label_set_long_mode(ui->scr_dashboard_label_insights, LV_LABEL_LONG_WRAP);

    //Write style for scr_dashboard_label_insights, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_dashboard_label_insights, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_dashboard_label_insights, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_dashboard_label_insights, lv_color_hex(0xABABAB), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_dashboard_label_insights, &lv_font_Roboto_Black_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_dashboard_label_insights, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_dashboard_label_insights, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_dashboard_label_insights, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_dashboard_label_insights, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_dashboard_label_insights, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_dashboard_label_insights, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_dashboard_label_insights, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_dashboard_label_insights, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_dashboard_label_insights, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_label_insights, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_dashboard_lbl_advice
    ui->scr_dashboard_lbl_advice = lv_label_create(ui->scr_dashboard_cont_insights);
    lv_obj_set_pos(ui->scr_dashboard_lbl_advice, 19, 52);
    lv_obj_set_size(ui->scr_dashboard_lbl_advice, 188, 105);
    lv_label_set_text(ui->scr_dashboard_lbl_advice, "COMMENT");
    lv_label_set_long_mode(ui->scr_dashboard_lbl_advice, LV_LABEL_LONG_WRAP);

    //Write style for scr_dashboard_lbl_advice, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_dashboard_lbl_advice, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_dashboard_lbl_advice, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_dashboard_lbl_advice, lv_color_hex(0xABABAB), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_dashboard_lbl_advice, &lv_font_Roboto_Regular_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_dashboard_lbl_advice, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_dashboard_lbl_advice, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_dashboard_lbl_advice, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_dashboard_lbl_advice, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_dashboard_lbl_advice, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_dashboard_lbl_advice, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_dashboard_lbl_advice, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_dashboard_lbl_advice, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_dashboard_lbl_advice, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_lbl_advice, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_dashboard_cont_event_logs
    ui->scr_dashboard_cont_event_logs = lv_obj_create(ui->scr_dashboard);
    lv_obj_set_pos(ui->scr_dashboard_cont_event_logs, 101, 49);
    lv_obj_set_size(ui->scr_dashboard_cont_event_logs, 680, 420);
    lv_obj_set_scrollbar_mode(ui->scr_dashboard_cont_event_logs, LV_SCROLLBAR_MODE_OFF);
    lv_obj_add_flag(ui->scr_dashboard_cont_event_logs, LV_OBJ_FLAG_HIDDEN);

    //Write style for scr_dashboard_cont_event_logs, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_dashboard_cont_event_logs, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_dashboard_cont_event_logs, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_dashboard_cont_event_logs, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_dashboard_cont_event_logs, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_dashboard_cont_event_logs, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_dashboard_cont_event_logs, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_dashboard_cont_event_logs, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_cont_event_logs, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_dashboard_lbl_event_logs
    ui->scr_dashboard_lbl_event_logs = lv_label_create(ui->scr_dashboard_cont_event_logs);
    lv_obj_set_pos(ui->scr_dashboard_lbl_event_logs, 0, 5);
    lv_obj_set_size(ui->scr_dashboard_lbl_event_logs, 172, 11);
    lv_label_set_text(ui->scr_dashboard_lbl_event_logs, "SYSTEM ACTIVITY LOGS");
    lv_label_set_long_mode(ui->scr_dashboard_lbl_event_logs, LV_LABEL_LONG_WRAP);

    //Write style for scr_dashboard_lbl_event_logs, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_dashboard_lbl_event_logs, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_dashboard_lbl_event_logs, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_dashboard_lbl_event_logs, lv_color_hex(0x64748B), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_dashboard_lbl_event_logs, &lv_font_Roboto_Black_10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_dashboard_lbl_event_logs, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_dashboard_lbl_event_logs, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_dashboard_lbl_event_logs, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_dashboard_lbl_event_logs, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_dashboard_lbl_event_logs, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_dashboard_lbl_event_logs, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_dashboard_lbl_event_logs, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_dashboard_lbl_event_logs, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_dashboard_lbl_event_logs, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_lbl_event_logs, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_dashboard_cont_logs
    ui->scr_dashboard_cont_logs = lv_obj_create(ui->scr_dashboard_cont_event_logs);
    lv_obj_set_pos(ui->scr_dashboard_cont_logs, 0, 35);
    lv_obj_set_size(ui->scr_dashboard_cont_logs, 680, 368);
    lv_obj_set_scrollbar_mode(ui->scr_dashboard_cont_logs, LV_SCROLLBAR_MODE_OFF);

    //Write style for scr_dashboard_cont_logs, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_dashboard_cont_logs, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scr_dashboard_cont_logs, 86, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scr_dashboard_cont_logs, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scr_dashboard_cont_logs, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_dashboard_cont_logs, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_dashboard_cont_logs, 49, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_dashboard_cont_logs, lv_color_hex(0x002b82), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_dashboard_cont_logs, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_dashboard_cont_logs, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_dashboard_cont_logs, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_dashboard_cont_logs, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_dashboard_cont_logs, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_cont_logs, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_dashboard_lbl_critical_logs
    ui->scr_dashboard_lbl_critical_logs = lv_label_create(ui->scr_dashboard_cont_logs);
    lv_obj_set_pos(ui->scr_dashboard_lbl_critical_logs, 20, 22);
    lv_obj_set_size(ui->scr_dashboard_lbl_critical_logs, 226, 18);
    lv_label_set_text(ui->scr_dashboard_lbl_critical_logs, "" LV_SYMBOL_BARS "  CRITICAL INCIDENT LOGS");
    lv_label_set_long_mode(ui->scr_dashboard_lbl_critical_logs, LV_LABEL_LONG_WRAP);

    //Write style for scr_dashboard_lbl_critical_logs, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_dashboard_lbl_critical_logs, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_dashboard_lbl_critical_logs, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_dashboard_lbl_critical_logs, lv_color_hex(0xABABAB), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_dashboard_lbl_critical_logs, &lv_font_Roboto_Black_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_dashboard_lbl_critical_logs, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_dashboard_lbl_critical_logs, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_dashboard_lbl_critical_logs, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_dashboard_lbl_critical_logs, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_dashboard_lbl_critical_logs, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_dashboard_lbl_critical_logs, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_dashboard_lbl_critical_logs, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_dashboard_lbl_critical_logs, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_dashboard_lbl_critical_logs, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_lbl_critical_logs, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_dashboard_btn_clear_history
    ui->scr_dashboard_btn_clear_history = lv_button_create(ui->scr_dashboard_cont_logs);
    lv_obj_set_pos(ui->scr_dashboard_btn_clear_history, 510, 10);
    lv_obj_set_size(ui->scr_dashboard_btn_clear_history, 150, 30);
    ui->scr_dashboard_btn_clear_history_label = lv_label_create(ui->scr_dashboard_btn_clear_history);
    lv_label_set_text(ui->scr_dashboard_btn_clear_history_label, "CLEAR HISTORY");
    lv_label_set_long_mode(ui->scr_dashboard_btn_clear_history_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->scr_dashboard_btn_clear_history_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->scr_dashboard_btn_clear_history, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->scr_dashboard_btn_clear_history_label, LV_PCT(100));

    //Write style for scr_dashboard_btn_clear_history, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->scr_dashboard_btn_clear_history, 171, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_dashboard_btn_clear_history, lv_color_hex(0xff003b), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_dashboard_btn_clear_history, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->scr_dashboard_btn_clear_history, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scr_dashboard_btn_clear_history, 94, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scr_dashboard_btn_clear_history, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scr_dashboard_btn_clear_history, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_dashboard_btn_clear_history, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_btn_clear_history, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_dashboard_btn_clear_history, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_dashboard_btn_clear_history, &lv_font_Roboto_Black_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_dashboard_btn_clear_history, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_dashboard_btn_clear_history, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_dashboard_cont_logs_detail
    ui->scr_dashboard_cont_logs_detail = lv_obj_create(ui->scr_dashboard_cont_logs);
    lv_obj_set_pos(ui->scr_dashboard_cont_logs_detail, 38, 60);
    lv_obj_set_size(ui->scr_dashboard_cont_logs_detail, 602, 40);
    lv_obj_set_scrollbar_mode(ui->scr_dashboard_cont_logs_detail, LV_SCROLLBAR_MODE_OFF);

    //Write style for scr_dashboard_cont_logs_detail, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_dashboard_cont_logs_detail, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scr_dashboard_cont_logs_detail, 81, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scr_dashboard_cont_logs_detail, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scr_dashboard_cont_logs_detail, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_dashboard_cont_logs_detail, 12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_dashboard_cont_logs_detail, 131, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_dashboard_cont_logs_detail, lv_color_hex(0x585858), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_dashboard_cont_logs_detail, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_dashboard_cont_logs_detail, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_dashboard_cont_logs_detail, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_dashboard_cont_logs_detail, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_dashboard_cont_logs_detail, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_cont_logs_detail, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_dashboard_lbl_log_detail
    ui->scr_dashboard_lbl_log_detail = lv_label_create(ui->scr_dashboard_cont_logs_detail);
    lv_obj_set_pos(ui->scr_dashboard_lbl_log_detail, 17, 11);
    lv_obj_set_size(ui->scr_dashboard_lbl_log_detail, 405, 15);
    lv_label_set_text(ui->scr_dashboard_lbl_log_detail, "" LV_SYMBOL_OK "  System initizlized on promary node Synaptix");
    lv_label_set_long_mode(ui->scr_dashboard_lbl_log_detail, LV_LABEL_LONG_WRAP);

    //Write style for scr_dashboard_lbl_log_detail, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_dashboard_lbl_log_detail, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_dashboard_lbl_log_detail, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_dashboard_lbl_log_detail, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_dashboard_lbl_log_detail, &lv_font_Roboto_Bold_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_dashboard_lbl_log_detail, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_dashboard_lbl_log_detail, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_dashboard_lbl_log_detail, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_dashboard_lbl_log_detail, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_dashboard_lbl_log_detail, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_dashboard_lbl_log_detail, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_dashboard_lbl_log_detail, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_dashboard_lbl_log_detail, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_dashboard_lbl_log_detail, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_lbl_log_detail, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_dashboard_cont_restart
    ui->scr_dashboard_cont_restart = lv_obj_create(ui->scr_dashboard);
    lv_obj_set_pos(ui->scr_dashboard_cont_restart, 0, 0);
    lv_obj_set_size(ui->scr_dashboard_cont_restart, 800, 480);
    lv_obj_set_scrollbar_mode(ui->scr_dashboard_cont_restart, LV_SCROLLBAR_MODE_OFF);
    lv_obj_add_flag(ui->scr_dashboard_cont_restart, LV_OBJ_FLAG_HIDDEN);

    //Write style for scr_dashboard_cont_restart, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_dashboard_cont_restart, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_dashboard_cont_restart, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_dashboard_cont_restart, 204, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_dashboard_cont_restart, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_dashboard_cont_restart, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_dashboard_cont_restart, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_dashboard_cont_restart, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_dashboard_cont_restart, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_dashboard_cont_restart, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_cont_restart, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_dashboard_cont_restart_system
    ui->scr_dashboard_cont_restart_system = lv_obj_create(ui->scr_dashboard_cont_restart);
    lv_obj_set_pos(ui->scr_dashboard_cont_restart_system, 203, 87);
    lv_obj_set_size(ui->scr_dashboard_cont_restart_system, 400, 300);
    lv_obj_set_scrollbar_mode(ui->scr_dashboard_cont_restart_system, LV_SCROLLBAR_MODE_OFF);

    //Write style for scr_dashboard_cont_restart_system, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_dashboard_cont_restart_system, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scr_dashboard_cont_restart_system, 48, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scr_dashboard_cont_restart_system, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scr_dashboard_cont_restart_system, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_dashboard_cont_restart_system, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_dashboard_cont_restart_system, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_dashboard_cont_restart_system, lv_color_hex(0x0F172A), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_dashboard_cont_restart_system, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_dashboard_cont_restart_system, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_dashboard_cont_restart_system, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_dashboard_cont_restart_system, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_dashboard_cont_restart_system, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_cont_restart_system, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_dashboard_img_12
    ui->scr_dashboard_img_12 = lv_image_create(ui->scr_dashboard_cont_restart_system);
    lv_obj_set_pos(ui->scr_dashboard_img_12, 150, 22);
    lv_obj_set_size(ui->scr_dashboard_img_12, 100, 100);
    lv_obj_add_flag(ui->scr_dashboard_img_12, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->scr_dashboard_img_12, &_power_button_RGB565A8_100x100);
    lv_image_set_pivot(ui->scr_dashboard_img_12, 50,50);
    lv_image_set_rotation(ui->scr_dashboard_img_12, 0);

    //Write style for scr_dashboard_img_12, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->scr_dashboard_img_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->scr_dashboard_img_12, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_dashboard_label_95
    ui->scr_dashboard_label_95 = lv_label_create(ui->scr_dashboard_cont_restart_system);
    lv_obj_set_pos(ui->scr_dashboard_label_95, 0, 144);
    lv_obj_set_size(ui->scr_dashboard_label_95, 400, 24);
    lv_label_set_text(ui->scr_dashboard_label_95, "RESTART SYSTEM?");
    lv_label_set_long_mode(ui->scr_dashboard_label_95, LV_LABEL_LONG_WRAP);

    //Write style for scr_dashboard_label_95, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_dashboard_label_95, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_dashboard_label_95, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_dashboard_label_95, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_dashboard_label_95, &lv_font_Roboto_Black_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_dashboard_label_95, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_dashboard_label_95, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_dashboard_label_95, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_dashboard_label_95, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_dashboard_label_95, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_dashboard_label_95, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_dashboard_label_95, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_dashboard_label_95, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_dashboard_label_95, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_label_95, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_dashboard_label_96
    ui->scr_dashboard_label_96 = lv_label_create(ui->scr_dashboard_cont_restart_system);
    lv_obj_set_pos(ui->scr_dashboard_label_96, 44, 177);
    lv_obj_set_size(ui->scr_dashboard_label_96, 311, 46);
    lv_label_set_text(ui->scr_dashboard_label_96, "The system will reboot now. Current data logging sessions will be resumed after startup.");
    lv_label_set_long_mode(ui->scr_dashboard_label_96, LV_LABEL_LONG_WRAP);

    //Write style for scr_dashboard_label_96, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_dashboard_label_96, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_dashboard_label_96, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_dashboard_label_96, lv_color_hex(0xABABAB), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_dashboard_label_96, &lv_font_Roboto_Regular_14, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_dashboard_label_96, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_dashboard_label_96, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_dashboard_label_96, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_dashboard_label_96, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_dashboard_label_96, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_dashboard_label_96, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_dashboard_label_96, 30, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_dashboard_label_96, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_dashboard_label_96, 30, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_label_96, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_dashboard_btn_restart_confirm
    ui->scr_dashboard_btn_restart_confirm = lv_button_create(ui->scr_dashboard_cont_restart_system);
    lv_obj_set_pos(ui->scr_dashboard_btn_restart_confirm, 207, 237);
    lv_obj_set_size(ui->scr_dashboard_btn_restart_confirm, 174, 38);
    ui->scr_dashboard_btn_restart_confirm_label = lv_label_create(ui->scr_dashboard_btn_restart_confirm);
    lv_label_set_text(ui->scr_dashboard_btn_restart_confirm_label, "CONFIRM");
    lv_label_set_long_mode(ui->scr_dashboard_btn_restart_confirm_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->scr_dashboard_btn_restart_confirm_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->scr_dashboard_btn_restart_confirm, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->scr_dashboard_btn_restart_confirm_label, LV_PCT(100));

    //Write style for scr_dashboard_btn_restart_confirm, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->scr_dashboard_btn_restart_confirm, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_dashboard_btn_restart_confirm, lv_color_hex(0x10B981), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_dashboard_btn_restart_confirm, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->scr_dashboard_btn_restart_confirm, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scr_dashboard_btn_restart_confirm, 37, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scr_dashboard_btn_restart_confirm, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scr_dashboard_btn_restart_confirm, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_dashboard_btn_restart_confirm, 12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_btn_restart_confirm, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_dashboard_btn_restart_confirm, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_dashboard_btn_restart_confirm, &lv_font_Roboto_Black_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_dashboard_btn_restart_confirm, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_dashboard_btn_restart_confirm, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_dashboard_btn_restart_cancel
    ui->scr_dashboard_btn_restart_cancel = lv_button_create(ui->scr_dashboard_cont_restart_system);
    lv_obj_set_pos(ui->scr_dashboard_btn_restart_cancel, 19, 237);
    lv_obj_set_size(ui->scr_dashboard_btn_restart_cancel, 174, 38);
    ui->scr_dashboard_btn_restart_cancel_label = lv_label_create(ui->scr_dashboard_btn_restart_cancel);
    lv_label_set_text(ui->scr_dashboard_btn_restart_cancel_label, "CANCEL");
    lv_label_set_long_mode(ui->scr_dashboard_btn_restart_cancel_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->scr_dashboard_btn_restart_cancel_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->scr_dashboard_btn_restart_cancel, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->scr_dashboard_btn_restart_cancel_label, LV_PCT(100));

    //Write style for scr_dashboard_btn_restart_cancel, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->scr_dashboard_btn_restart_cancel, 193, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_dashboard_btn_restart_cancel, lv_color_hex(0x1d1d1d), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_dashboard_btn_restart_cancel, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->scr_dashboard_btn_restart_cancel, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scr_dashboard_btn_restart_cancel, 37, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scr_dashboard_btn_restart_cancel, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scr_dashboard_btn_restart_cancel, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_dashboard_btn_restart_cancel, 12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_btn_restart_cancel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_dashboard_btn_restart_cancel, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_dashboard_btn_restart_cancel, &lv_font_Roboto_Black_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_dashboard_btn_restart_cancel, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_dashboard_btn_restart_cancel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_dashboard_cont_restore
    ui->scr_dashboard_cont_restore = lv_obj_create(ui->scr_dashboard);
    lv_obj_set_pos(ui->scr_dashboard_cont_restore, 0, 0);
    lv_obj_set_size(ui->scr_dashboard_cont_restore, 800, 480);
    lv_obj_set_scrollbar_mode(ui->scr_dashboard_cont_restore, LV_SCROLLBAR_MODE_OFF);
    lv_obj_add_flag(ui->scr_dashboard_cont_restore, LV_OBJ_FLAG_HIDDEN);

    //Write style for scr_dashboard_cont_restore, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_dashboard_cont_restore, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_dashboard_cont_restore, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_dashboard_cont_restore, 204, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_dashboard_cont_restore, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_dashboard_cont_restore, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_dashboard_cont_restore, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_dashboard_cont_restore, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_dashboard_cont_restore, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_dashboard_cont_restore, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_cont_restore, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_dashboard_cont_31
    ui->scr_dashboard_cont_31 = lv_obj_create(ui->scr_dashboard_cont_restore);
    lv_obj_set_pos(ui->scr_dashboard_cont_31, 203, 87);
    lv_obj_set_size(ui->scr_dashboard_cont_31, 400, 300);
    lv_obj_set_scrollbar_mode(ui->scr_dashboard_cont_31, LV_SCROLLBAR_MODE_OFF);

    //Write style for scr_dashboard_cont_31, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_dashboard_cont_31, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scr_dashboard_cont_31, 48, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scr_dashboard_cont_31, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scr_dashboard_cont_31, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_dashboard_cont_31, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_dashboard_cont_31, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_dashboard_cont_31, lv_color_hex(0x0F172A), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_dashboard_cont_31, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_dashboard_cont_31, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_dashboard_cont_31, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_dashboard_cont_31, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_dashboard_cont_31, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_cont_31, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_dashboard_img_13
    ui->scr_dashboard_img_13 = lv_image_create(ui->scr_dashboard_cont_31);
    lv_obj_set_pos(ui->scr_dashboard_img_13, 150, 22);
    lv_obj_set_size(ui->scr_dashboard_img_13, 100, 100);
    lv_obj_add_flag(ui->scr_dashboard_img_13, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->scr_dashboard_img_13, &_power_RGB565A8_100x100);
    lv_image_set_pivot(ui->scr_dashboard_img_13, 50,50);
    lv_image_set_rotation(ui->scr_dashboard_img_13, 0);

    //Write style for scr_dashboard_img_13, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->scr_dashboard_img_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->scr_dashboard_img_13, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_dashboard_label_98
    ui->scr_dashboard_label_98 = lv_label_create(ui->scr_dashboard_cont_31);
    lv_obj_set_pos(ui->scr_dashboard_label_98, 0, 144);
    lv_obj_set_size(ui->scr_dashboard_label_98, 400, 24);
    lv_label_set_text(ui->scr_dashboard_label_98, "RESTORE DEFAULTS?");
    lv_label_set_long_mode(ui->scr_dashboard_label_98, LV_LABEL_LONG_WRAP);

    //Write style for scr_dashboard_label_98, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_dashboard_label_98, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_dashboard_label_98, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_dashboard_label_98, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_dashboard_label_98, &lv_font_Roboto_Black_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_dashboard_label_98, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_dashboard_label_98, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_dashboard_label_98, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_dashboard_label_98, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_dashboard_label_98, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_dashboard_label_98, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_dashboard_label_98, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_dashboard_label_98, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_dashboard_label_98, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_label_98, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_dashboard_label_97
    ui->scr_dashboard_label_97 = lv_label_create(ui->scr_dashboard_cont_31);
    lv_obj_set_pos(ui->scr_dashboard_label_97, 44, 177);
    lv_obj_set_size(ui->scr_dashboard_label_97, 311, 46);
    lv_label_set_text(ui->scr_dashboard_label_97, "This will erase all custom configurations and network credentials permanently.");
    lv_label_set_long_mode(ui->scr_dashboard_label_97, LV_LABEL_LONG_WRAP);

    //Write style for scr_dashboard_label_97, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_dashboard_label_97, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_dashboard_label_97, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_dashboard_label_97, lv_color_hex(0xABABAB), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_dashboard_label_97, &lv_font_Roboto_Regular_14, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_dashboard_label_97, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_dashboard_label_97, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_dashboard_label_97, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_dashboard_label_97, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_dashboard_label_97, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_dashboard_label_97, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_dashboard_label_97, 30, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_dashboard_label_97, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_dashboard_label_97, 30, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_label_97, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_dashboard_btn_restore_confirm
    ui->scr_dashboard_btn_restore_confirm = lv_button_create(ui->scr_dashboard_cont_31);
    lv_obj_set_pos(ui->scr_dashboard_btn_restore_confirm, 207, 237);
    lv_obj_set_size(ui->scr_dashboard_btn_restore_confirm, 174, 38);
    ui->scr_dashboard_btn_restore_confirm_label = lv_label_create(ui->scr_dashboard_btn_restore_confirm);
    lv_label_set_text(ui->scr_dashboard_btn_restore_confirm_label, "CONFIRM");
    lv_label_set_long_mode(ui->scr_dashboard_btn_restore_confirm_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->scr_dashboard_btn_restore_confirm_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->scr_dashboard_btn_restore_confirm, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->scr_dashboard_btn_restore_confirm_label, LV_PCT(100));

    //Write style for scr_dashboard_btn_restore_confirm, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->scr_dashboard_btn_restore_confirm, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_dashboard_btn_restore_confirm, lv_color_hex(0x10B981), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_dashboard_btn_restore_confirm, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->scr_dashboard_btn_restore_confirm, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scr_dashboard_btn_restore_confirm, 37, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scr_dashboard_btn_restore_confirm, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scr_dashboard_btn_restore_confirm, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_dashboard_btn_restore_confirm, 12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_btn_restore_confirm, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_dashboard_btn_restore_confirm, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_dashboard_btn_restore_confirm, &lv_font_Roboto_Black_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_dashboard_btn_restore_confirm, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_dashboard_btn_restore_confirm, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_dashboard_btn_restore_cancel
    ui->scr_dashboard_btn_restore_cancel = lv_button_create(ui->scr_dashboard_cont_31);
    lv_obj_set_pos(ui->scr_dashboard_btn_restore_cancel, 19, 237);
    lv_obj_set_size(ui->scr_dashboard_btn_restore_cancel, 174, 38);
    ui->scr_dashboard_btn_restore_cancel_label = lv_label_create(ui->scr_dashboard_btn_restore_cancel);
    lv_label_set_text(ui->scr_dashboard_btn_restore_cancel_label, "CANCEL");
    lv_label_set_long_mode(ui->scr_dashboard_btn_restore_cancel_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->scr_dashboard_btn_restore_cancel_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->scr_dashboard_btn_restore_cancel, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->scr_dashboard_btn_restore_cancel_label, LV_PCT(100));

    //Write style for scr_dashboard_btn_restore_cancel, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->scr_dashboard_btn_restore_cancel, 193, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_dashboard_btn_restore_cancel, lv_color_hex(0x1d1d1d), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_dashboard_btn_restore_cancel, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->scr_dashboard_btn_restore_cancel, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scr_dashboard_btn_restore_cancel, 37, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scr_dashboard_btn_restore_cancel, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scr_dashboard_btn_restore_cancel, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_dashboard_btn_restore_cancel, 12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_btn_restore_cancel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_dashboard_btn_restore_cancel, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_dashboard_btn_restore_cancel, &lv_font_Roboto_Black_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_dashboard_btn_restore_cancel, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_dashboard_btn_restore_cancel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of scr_dashboard.


    //Update current screen layout.
    lv_obj_update_layout(ui->scr_dashboard);

}
