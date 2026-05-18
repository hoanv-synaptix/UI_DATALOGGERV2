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



int scr_wifi_digital_clock_1_min_value = 25;
int scr_wifi_digital_clock_1_hour_value = 11;
int scr_wifi_digital_clock_1_sec_value = 50;
void setup_scr_scr_wifi(lv_ui *ui)
{
    //Write codes scr_wifi
    ui->scr_wifi = lv_obj_create(NULL);
    lv_obj_set_size(ui->scr_wifi, 800, 480);
    lv_obj_set_scrollbar_mode(ui->scr_wifi, LV_SCROLLBAR_MODE_OFF);

    //Write style for scr_wifi, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->scr_wifi, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_wifi_img_1
    ui->scr_wifi_img_1 = lv_image_create(ui->scr_wifi);
    lv_obj_set_pos(ui->scr_wifi_img_1, 0, 0);
    lv_obj_set_size(ui->scr_wifi_img_1, 800, 480);
    lv_obj_add_flag(ui->scr_wifi_img_1, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->scr_wifi_img_1, &_bg_settings_base_RGB565A8_800x480);
    lv_image_set_pivot(ui->scr_wifi_img_1, 50,50);
    lv_image_set_rotation(ui->scr_wifi_img_1, 0);

    //Write style for scr_wifi_img_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->scr_wifi_img_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->scr_wifi_img_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_wifi_HARDWARE
    ui->scr_wifi_HARDWARE = lv_label_create(ui->scr_wifi);
    lv_obj_set_pos(ui->scr_wifi_HARDWARE, 100, 56);
    lv_obj_set_size(ui->scr_wifi_HARDWARE, 172, 11);
    lv_label_set_text(ui->scr_wifi_HARDWARE, "HARDWARE SETUP");
    lv_label_set_long_mode(ui->scr_wifi_HARDWARE, LV_LABEL_LONG_WRAP);

    //Write style for scr_wifi_HARDWARE, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_wifi_HARDWARE, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_wifi_HARDWARE, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_wifi_HARDWARE, lv_color_hex(0x64748B), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_wifi_HARDWARE, &lv_font_Roboto_Black_10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_wifi_HARDWARE, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_wifi_HARDWARE, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_wifi_HARDWARE, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_wifi_HARDWARE, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_wifi_HARDWARE, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_wifi_HARDWARE, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_wifi_HARDWARE, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_wifi_HARDWARE, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_wifi_HARDWARE, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_wifi_HARDWARE, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_wifi_datetext_1
    ui->scr_wifi_datetext_1 = lv_label_create(ui->scr_wifi);
    lv_obj_set_pos(ui->scr_wifi_datetext_1, 600, 30);
    lv_obj_set_size(ui->scr_wifi_datetext_1, 78, 19);
    lv_label_set_text(ui->scr_wifi_datetext_1, "2025/05/15");
    lv_obj_set_style_text_align(ui->scr_wifi_datetext_1, LV_TEXT_ALIGN_CENTER, 0);
    lv_obj_add_flag(ui->scr_wifi_datetext_1, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_add_event_cb(ui->scr_wifi_datetext_1, scr_wifi_datetext_1_event_handler, LV_EVENT_ALL, NULL);

    //Write style for scr_wifi_datetext_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_wifi_datetext_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_wifi_datetext_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_wifi_datetext_1, lv_color_hex(0x64748B), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_wifi_datetext_1, &lv_font_Roboto_Bold_10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_wifi_datetext_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_wifi_datetext_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_wifi_datetext_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_wifi_datetext_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_wifi_datetext_1, 7, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_wifi_datetext_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_wifi_datetext_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_wifi_datetext_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for scr_wifi_datetext_1, Part: LV_PART_MAIN, State: LV_STATE_DISABLED.
    lv_obj_set_style_border_width(ui->scr_wifi_datetext_1, 0, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_radius(ui->scr_wifi_datetext_1, 0, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_color(ui->scr_wifi_datetext_1, lv_color_hex(0x64748B), LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_font(ui->scr_wifi_datetext_1, &lv_font_Roboto_Bold_9, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_opa(ui->scr_wifi_datetext_1, 255, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_letter_space(ui->scr_wifi_datetext_1, 2, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_align(ui->scr_wifi_datetext_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_bg_opa(ui->scr_wifi_datetext_1, 0, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_pad_top(ui->scr_wifi_datetext_1, 7, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_pad_right(ui->scr_wifi_datetext_1, 0, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_pad_left(ui->scr_wifi_datetext_1, 0, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_shadow_width(ui->scr_wifi_datetext_1, 0, LV_PART_MAIN|LV_STATE_DISABLED);

    //Write codes scr_wifi_digital_clock_1
    static bool scr_wifi_digital_clock_1_timer_enabled = false;
    ui->scr_wifi_digital_clock_1 = lv_label_create(ui->scr_wifi);
    lv_obj_set_pos(ui->scr_wifi_digital_clock_1, 695, 30);
    lv_obj_set_size(ui->scr_wifi_digital_clock_1, 74, 19);
    lv_label_set_text(ui->scr_wifi_digital_clock_1, "11:25:50");
    if (!scr_wifi_digital_clock_1_timer_enabled) {
        lv_timer_create(scr_wifi_digital_clock_1_timer, 1000, NULL);
        scr_wifi_digital_clock_1_timer_enabled = true;
    }

    //Write style for scr_wifi_digital_clock_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_radius(ui->scr_wifi_digital_clock_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_wifi_digital_clock_1, lv_color_hex(0x64748B), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_wifi_digital_clock_1, &lv_font_Roboto_Bold_10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_wifi_digital_clock_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_wifi_digital_clock_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_wifi_digital_clock_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_wifi_digital_clock_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_wifi_digital_clock_1, 7, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_wifi_digital_clock_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_wifi_digital_clock_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_wifi_digital_clock_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_wifi_digital_clock_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for scr_wifi_digital_clock_1, Part: LV_PART_MAIN, State: LV_STATE_DISABLED.
    lv_obj_set_style_radius(ui->scr_wifi_digital_clock_1, 0, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_color(ui->scr_wifi_digital_clock_1, lv_color_hex(0x64748B), LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_font(ui->scr_wifi_digital_clock_1, &lv_font_Roboto_Bold_10, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_opa(ui->scr_wifi_digital_clock_1, 255, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_letter_space(ui->scr_wifi_digital_clock_1, 0, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_align(ui->scr_wifi_digital_clock_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_bg_opa(ui->scr_wifi_digital_clock_1, 0, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_pad_top(ui->scr_wifi_digital_clock_1, 7, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_pad_right(ui->scr_wifi_digital_clock_1, 0, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_pad_left(ui->scr_wifi_digital_clock_1, 0, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_shadow_width(ui->scr_wifi_digital_clock_1, 0, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_pad_bottom(ui->scr_wifi_digital_clock_1, 0, LV_PART_MAIN|LV_STATE_DISABLED);

    //Write codes scr_wifi_btn_5
    ui->scr_wifi_btn_5 = lv_button_create(ui->scr_wifi);
    lv_obj_set_pos(ui->scr_wifi_btn_5, 9, 109);
    lv_obj_set_size(ui->scr_wifi_btn_5, 64, 64);
    ui->scr_wifi_btn_5_label = lv_label_create(ui->scr_wifi_btn_5);
    lv_label_set_text(ui->scr_wifi_btn_5_label, "");
    lv_label_set_long_mode(ui->scr_wifi_btn_5_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->scr_wifi_btn_5_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->scr_wifi_btn_5, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->scr_wifi_btn_5_label, LV_PCT(100));

    //Write style for scr_wifi_btn_5, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->scr_wifi_btn_5, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_wifi_btn_5, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_wifi_btn_5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_wifi_btn_5, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_wifi_btn_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_wifi_btn_5, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_wifi_btn_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->scr_wifi_btn_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for scr_wifi_btn_5, Part: LV_PART_MAIN, State: LV_STATE_FOCUSED.
    lv_obj_set_style_text_color(ui->scr_wifi_btn_5, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_font(ui->scr_wifi_btn_5, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_opa(ui->scr_wifi_btn_5, 255, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_opa(ui->scr_wifi_btn_5, 39, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_color(ui->scr_wifi_btn_5, lv_color_hex(0x10B981), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_grad_dir(ui->scr_wifi_btn_5, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_radius(ui->scr_wifi_btn_5, 14, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_shadow_width(ui->scr_wifi_btn_5, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_width(ui->scr_wifi_btn_5, 0, LV_PART_MAIN|LV_STATE_FOCUSED);

    //Write style for scr_wifi_btn_5, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_bg_opa(ui->scr_wifi_btn_5, 40, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_bg_color(ui->scr_wifi_btn_5, lv_color_hex(0x10B981), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_bg_grad_dir(ui->scr_wifi_btn_5, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui->scr_wifi_btn_5, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_radius(ui->scr_wifi_btn_5, 14, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->scr_wifi_btn_5, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->scr_wifi_btn_5, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->scr_wifi_btn_5, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->scr_wifi_btn_5, 255, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for scr_wifi_btn_5, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_bg_opa(ui->scr_wifi_btn_5, 39, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui->scr_wifi_btn_5, lv_color_hex(0x10B981), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_grad_dir(ui->scr_wifi_btn_5, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_border_width(ui->scr_wifi_btn_5, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_radius(ui->scr_wifi_btn_5, 14, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->scr_wifi_btn_5, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->scr_wifi_btn_5, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->scr_wifi_btn_5, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->scr_wifi_btn_5, 255, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write codes scr_wifi_btn_4
    ui->scr_wifi_btn_4 = lv_button_create(ui->scr_wifi);
    lv_obj_set_pos(ui->scr_wifi_btn_4, 9, 181);
    lv_obj_set_size(ui->scr_wifi_btn_4, 64, 64);
    ui->scr_wifi_btn_4_label = lv_label_create(ui->scr_wifi_btn_4);
    lv_label_set_text(ui->scr_wifi_btn_4_label, "");
    lv_label_set_long_mode(ui->scr_wifi_btn_4_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->scr_wifi_btn_4_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->scr_wifi_btn_4, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->scr_wifi_btn_4_label, LV_PCT(100));

    //Write style for scr_wifi_btn_4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_radius(ui->scr_wifi_btn_4, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_wifi_btn_4, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_wifi_btn_4, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_wifi_btn_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_wifi_btn_4, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_wifi_btn_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_wifi_btn_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->scr_wifi_btn_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for scr_wifi_btn_4, Part: LV_PART_MAIN, State: LV_STATE_FOCUSED.
    lv_obj_set_style_radius(ui->scr_wifi_btn_4, 14, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_color(ui->scr_wifi_btn_4, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_font(ui->scr_wifi_btn_4, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_opa(ui->scr_wifi_btn_4, 255, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_opa(ui->scr_wifi_btn_4, 39, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_color(ui->scr_wifi_btn_4, lv_color_hex(0x10B981), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_grad_dir(ui->scr_wifi_btn_4, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_shadow_width(ui->scr_wifi_btn_4, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_width(ui->scr_wifi_btn_4, 0, LV_PART_MAIN|LV_STATE_FOCUSED);

    //Write style for scr_wifi_btn_4, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_bg_opa(ui->scr_wifi_btn_4, 40, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_bg_color(ui->scr_wifi_btn_4, lv_color_hex(0x10B981), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_bg_grad_dir(ui->scr_wifi_btn_4, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui->scr_wifi_btn_4, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_radius(ui->scr_wifi_btn_4, 14, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->scr_wifi_btn_4, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->scr_wifi_btn_4, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->scr_wifi_btn_4, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->scr_wifi_btn_4, 255, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for scr_wifi_btn_4, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_bg_opa(ui->scr_wifi_btn_4, 39, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui->scr_wifi_btn_4, lv_color_hex(0x10B981), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_grad_dir(ui->scr_wifi_btn_4, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_border_width(ui->scr_wifi_btn_4, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_radius(ui->scr_wifi_btn_4, 14, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->scr_wifi_btn_4, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->scr_wifi_btn_4, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->scr_wifi_btn_4, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->scr_wifi_btn_4, 255, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write codes scr_wifi_btn_3
    ui->scr_wifi_btn_3 = lv_button_create(ui->scr_wifi);
    lv_obj_set_pos(ui->scr_wifi_btn_3, 9, 255);
    lv_obj_set_size(ui->scr_wifi_btn_3, 64, 64);
    ui->scr_wifi_btn_3_label = lv_label_create(ui->scr_wifi_btn_3);
    lv_label_set_text(ui->scr_wifi_btn_3_label, "");
    lv_label_set_long_mode(ui->scr_wifi_btn_3_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->scr_wifi_btn_3_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->scr_wifi_btn_3, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->scr_wifi_btn_3_label, LV_PCT(100));

    //Write style for scr_wifi_btn_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->scr_wifi_btn_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->scr_wifi_btn_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_wifi_btn_3, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_wifi_btn_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_wifi_btn_3, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_wifi_btn_3, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_wifi_btn_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_wifi_btn_3, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for scr_wifi_btn_3, Part: LV_PART_MAIN, State: LV_STATE_FOCUSED.
    lv_obj_set_style_bg_opa(ui->scr_wifi_btn_3, 39, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_color(ui->scr_wifi_btn_3, lv_color_hex(0x10B981), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_grad_dir(ui->scr_wifi_btn_3, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_width(ui->scr_wifi_btn_3, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_radius(ui->scr_wifi_btn_3, 14, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_shadow_width(ui->scr_wifi_btn_3, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_color(ui->scr_wifi_btn_3, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_font(ui->scr_wifi_btn_3, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_opa(ui->scr_wifi_btn_3, 255, LV_PART_MAIN|LV_STATE_FOCUSED);

    //Write style for scr_wifi_btn_3, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_bg_opa(ui->scr_wifi_btn_3, 40, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_bg_color(ui->scr_wifi_btn_3, lv_color_hex(0x10B981), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_bg_grad_dir(ui->scr_wifi_btn_3, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui->scr_wifi_btn_3, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_radius(ui->scr_wifi_btn_3, 14, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->scr_wifi_btn_3, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->scr_wifi_btn_3, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->scr_wifi_btn_3, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->scr_wifi_btn_3, 255, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for scr_wifi_btn_3, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_bg_opa(ui->scr_wifi_btn_3, 39, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui->scr_wifi_btn_3, lv_color_hex(0x10B981), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_grad_dir(ui->scr_wifi_btn_3, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_border_width(ui->scr_wifi_btn_3, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_radius(ui->scr_wifi_btn_3, 14, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->scr_wifi_btn_3, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->scr_wifi_btn_3, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->scr_wifi_btn_3, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->scr_wifi_btn_3, 255, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write codes scr_wifi_btn_2
    ui->scr_wifi_btn_2 = lv_button_create(ui->scr_wifi);
    lv_obj_set_pos(ui->scr_wifi_btn_2, 9, 325);
    lv_obj_set_size(ui->scr_wifi_btn_2, 64, 64);
    ui->scr_wifi_btn_2_label = lv_label_create(ui->scr_wifi_btn_2);
    lv_label_set_text(ui->scr_wifi_btn_2_label, "");
    lv_label_set_long_mode(ui->scr_wifi_btn_2_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->scr_wifi_btn_2_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->scr_wifi_btn_2, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->scr_wifi_btn_2_label, LV_PCT(100));

    //Write style for scr_wifi_btn_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->scr_wifi_btn_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->scr_wifi_btn_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_wifi_btn_2, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_wifi_btn_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_wifi_btn_2, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_wifi_btn_2, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_wifi_btn_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_wifi_btn_2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for scr_wifi_btn_2, Part: LV_PART_MAIN, State: LV_STATE_FOCUSED.
    lv_obj_set_style_bg_opa(ui->scr_wifi_btn_2, 39, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_color(ui->scr_wifi_btn_2, lv_color_hex(0x10B981), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_grad_dir(ui->scr_wifi_btn_2, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_width(ui->scr_wifi_btn_2, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_radius(ui->scr_wifi_btn_2, 14, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_shadow_width(ui->scr_wifi_btn_2, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_color(ui->scr_wifi_btn_2, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_font(ui->scr_wifi_btn_2, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_opa(ui->scr_wifi_btn_2, 255, LV_PART_MAIN|LV_STATE_FOCUSED);

    //Write style for scr_wifi_btn_2, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_bg_opa(ui->scr_wifi_btn_2, 40, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_bg_color(ui->scr_wifi_btn_2, lv_color_hex(0x10B981), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_bg_grad_dir(ui->scr_wifi_btn_2, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui->scr_wifi_btn_2, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_radius(ui->scr_wifi_btn_2, 14, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->scr_wifi_btn_2, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->scr_wifi_btn_2, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->scr_wifi_btn_2, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->scr_wifi_btn_2, 255, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for scr_wifi_btn_2, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_bg_opa(ui->scr_wifi_btn_2, 39, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui->scr_wifi_btn_2, lv_color_hex(0x10B981), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_grad_dir(ui->scr_wifi_btn_2, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_border_width(ui->scr_wifi_btn_2, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_radius(ui->scr_wifi_btn_2, 14, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->scr_wifi_btn_2, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->scr_wifi_btn_2, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->scr_wifi_btn_2, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->scr_wifi_btn_2, 255, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write codes scr_wifi_btn_1
    ui->scr_wifi_btn_1 = lv_button_create(ui->scr_wifi);
    lv_obj_set_pos(ui->scr_wifi_btn_1, 9, 393);
    lv_obj_set_size(ui->scr_wifi_btn_1, 64, 64);
    ui->scr_wifi_btn_1_label = lv_label_create(ui->scr_wifi_btn_1);
    lv_label_set_text(ui->scr_wifi_btn_1_label, "");
    lv_label_set_long_mode(ui->scr_wifi_btn_1_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->scr_wifi_btn_1_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->scr_wifi_btn_1, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->scr_wifi_btn_1_label, LV_PCT(100));

    //Write style for scr_wifi_btn_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->scr_wifi_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->scr_wifi_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_wifi_btn_1, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_wifi_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_wifi_btn_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_wifi_btn_1, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_wifi_btn_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_wifi_btn_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for scr_wifi_btn_1, Part: LV_PART_MAIN, State: LV_STATE_FOCUSED.
    lv_obj_set_style_bg_opa(ui->scr_wifi_btn_1, 39, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_color(ui->scr_wifi_btn_1, lv_color_hex(0x10B981), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_grad_dir(ui->scr_wifi_btn_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_width(ui->scr_wifi_btn_1, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_radius(ui->scr_wifi_btn_1, 14, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_shadow_width(ui->scr_wifi_btn_1, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_color(ui->scr_wifi_btn_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_font(ui->scr_wifi_btn_1, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_opa(ui->scr_wifi_btn_1, 255, LV_PART_MAIN|LV_STATE_FOCUSED);

    //Write style for scr_wifi_btn_1, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_bg_opa(ui->scr_wifi_btn_1, 40, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_bg_color(ui->scr_wifi_btn_1, lv_color_hex(0x10B981), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_bg_grad_dir(ui->scr_wifi_btn_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui->scr_wifi_btn_1, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_radius(ui->scr_wifi_btn_1, 14, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->scr_wifi_btn_1, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->scr_wifi_btn_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->scr_wifi_btn_1, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->scr_wifi_btn_1, 255, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for scr_wifi_btn_1, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_bg_opa(ui->scr_wifi_btn_1, 39, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui->scr_wifi_btn_1, lv_color_hex(0x10B981), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_grad_dir(ui->scr_wifi_btn_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_border_width(ui->scr_wifi_btn_1, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_radius(ui->scr_wifi_btn_1, 14, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->scr_wifi_btn_1, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->scr_wifi_btn_1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->scr_wifi_btn_1, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->scr_wifi_btn_1, 255, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write codes scr_wifi_img_5
    ui->scr_wifi_img_5 = lv_image_create(ui->scr_wifi);
    lv_obj_set_pos(ui->scr_wifi_img_5, 546, 32);
    lv_obj_set_size(ui->scr_wifi_img_5, 16, 16);
    lv_obj_add_flag(ui->scr_wifi_img_5, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->scr_wifi_img_5, &_mqtt_on_RGB565A8_16x16);
    lv_image_set_pivot(ui->scr_wifi_img_5, 50,50);
    lv_image_set_rotation(ui->scr_wifi_img_5, 0);

    //Write style for scr_wifi_img_5, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->scr_wifi_img_5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_recolor(ui->scr_wifi_img_5, lv_color_hex(0xababba), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->scr_wifi_img_5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_wifi_img_4
    ui->scr_wifi_img_4 = lv_image_create(ui->scr_wifi);
    lv_obj_set_pos(ui->scr_wifi_img_4, 476, 32);
    lv_obj_set_size(ui->scr_wifi_img_4, 16, 16);
    lv_obj_add_flag(ui->scr_wifi_img_4, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->scr_wifi_img_4, &_wifi_on_RGB565A8_16x16);
    lv_image_set_pivot(ui->scr_wifi_img_4, 50,50);
    lv_image_set_rotation(ui->scr_wifi_img_4, 0);

    //Write style for scr_wifi_img_4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->scr_wifi_img_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_recolor(ui->scr_wifi_img_4, lv_color_hex(0xababab), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->scr_wifi_img_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_wifi_img_3
    ui->scr_wifi_img_3 = lv_image_create(ui->scr_wifi);
    lv_obj_set_pos(ui->scr_wifi_img_3, 546, 32);
    lv_obj_set_size(ui->scr_wifi_img_3, 16, 16);
    lv_obj_add_flag(ui->scr_wifi_img_3, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(ui->scr_wifi_img_3, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->scr_wifi_img_3, &_mqtt_off_RGB565A8_16x16);
    lv_image_set_pivot(ui->scr_wifi_img_3, 50,50);
    lv_image_set_rotation(ui->scr_wifi_img_3, 0);

    //Write style for scr_wifi_img_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->scr_wifi_img_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_recolor(ui->scr_wifi_img_3, lv_color_hex(0xababba), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->scr_wifi_img_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_wifi_img_2
    ui->scr_wifi_img_2 = lv_image_create(ui->scr_wifi);
    lv_obj_set_pos(ui->scr_wifi_img_2, 476, 32);
    lv_obj_set_size(ui->scr_wifi_img_2, 16, 16);
    lv_obj_add_flag(ui->scr_wifi_img_2, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(ui->scr_wifi_img_2, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->scr_wifi_img_2, &_wifi_off_RGB565A8_16x16);
    lv_image_set_pivot(ui->scr_wifi_img_2, 50,50);
    lv_image_set_rotation(ui->scr_wifi_img_2, 0);

    //Write style for scr_wifi_img_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->scr_wifi_img_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_recolor(ui->scr_wifi_img_2, lv_color_hex(0xababba), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->scr_wifi_img_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_wifi_cont_1
    ui->scr_wifi_cont_1 = lv_obj_create(ui->scr_wifi);
    lv_obj_set_pos(ui->scr_wifi_cont_1, 100, 88);
    lv_obj_set_size(ui->scr_wifi_cont_1, 36, 36);
    lv_obj_set_scrollbar_mode(ui->scr_wifi_cont_1, LV_SCROLLBAR_MODE_OFF);

    //Write style for scr_wifi_cont_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_wifi_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_wifi_cont_1, 12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_wifi_cont_1, 13, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_wifi_cont_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_wifi_cont_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_wifi_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_wifi_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_wifi_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_wifi_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_wifi_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_wifi_img_6
    ui->scr_wifi_img_6 = lv_image_create(ui->scr_wifi_cont_1);
    lv_obj_set_pos(ui->scr_wifi_img_6, 6, 6);
    lv_obj_set_size(ui->scr_wifi_img_6, 24, 24);
    lv_obj_add_flag(ui->scr_wifi_img_6, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->scr_wifi_img_6, &_left_arrow_RGB565A8_24x24);
    lv_image_set_pivot(ui->scr_wifi_img_6, 50,50);
    lv_image_set_rotation(ui->scr_wifi_img_6, 0);

    //Write style for scr_wifi_img_6, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->scr_wifi_img_6, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_recolor(ui->scr_wifi_img_6, lv_color_hex(0xABABAB), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->scr_wifi_img_6, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_wifi_btn_6
    ui->scr_wifi_btn_6 = lv_button_create(ui->scr_wifi_cont_1);
    lv_obj_set_pos(ui->scr_wifi_btn_6, 0, 0);
    lv_obj_set_size(ui->scr_wifi_btn_6, 36, 36);
    ui->scr_wifi_btn_6_label = lv_label_create(ui->scr_wifi_btn_6);
    lv_label_set_text(ui->scr_wifi_btn_6_label, "");
    lv_label_set_long_mode(ui->scr_wifi_btn_6_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->scr_wifi_btn_6_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->scr_wifi_btn_6, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->scr_wifi_btn_6_label, LV_PCT(100));

    //Write style for scr_wifi_btn_6, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->scr_wifi_btn_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->scr_wifi_btn_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_wifi_btn_6, 12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_wifi_btn_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_wifi_btn_6, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_wifi_btn_6, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_wifi_btn_6, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_wifi_btn_6, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for scr_wifi_btn_6, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_bg_opa(ui->scr_wifi_btn_6, 28, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_bg_color(ui->scr_wifi_btn_6, lv_color_hex(0x10B981), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_bg_grad_dir(ui->scr_wifi_btn_6, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui->scr_wifi_btn_6, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_radius(ui->scr_wifi_btn_6, 12, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->scr_wifi_btn_6, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->scr_wifi_btn_6, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->scr_wifi_btn_6, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->scr_wifi_btn_6, 255, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for scr_wifi_btn_6, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_bg_opa(ui->scr_wifi_btn_6, 28, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui->scr_wifi_btn_6, lv_color_hex(0x10B981), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_grad_dir(ui->scr_wifi_btn_6, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_border_width(ui->scr_wifi_btn_6, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_radius(ui->scr_wifi_btn_6, 5, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->scr_wifi_btn_6, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->scr_wifi_btn_6, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->scr_wifi_btn_6, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->scr_wifi_btn_6, 255, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write codes scr_wifi_label_1
    ui->scr_wifi_label_1 = lv_label_create(ui->scr_wifi);
    lv_obj_set_pos(ui->scr_wifi_label_1, 148, 100);
    lv_obj_set_size(ui->scr_wifi_label_1, 172, 11);
    lv_label_set_text(ui->scr_wifi_label_1, "NETWORK CONFIGURATION");
    lv_label_set_long_mode(ui->scr_wifi_label_1, LV_LABEL_LONG_WRAP);

    //Write style for scr_wifi_label_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_wifi_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_wifi_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_wifi_label_1, lv_color_hex(0x71717A), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_wifi_label_1, &lv_font_Roboto_Black_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_wifi_label_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_wifi_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_wifi_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_wifi_label_1, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_wifi_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_wifi_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_wifi_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_wifi_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_wifi_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_wifi_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_wifi_cont_2
    ui->scr_wifi_cont_2 = lv_obj_create(ui->scr_wifi);
    lv_obj_set_pos(ui->scr_wifi_cont_2, 100, 140);
    lv_obj_set_size(ui->scr_wifi_cont_2, 660, 320);
    lv_obj_set_scrollbar_mode(ui->scr_wifi_cont_2, LV_SCROLLBAR_MODE_OFF);

    //Write style for scr_wifi_cont_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_wifi_cont_2, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scr_wifi_cont_2, 26, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scr_wifi_cont_2, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scr_wifi_cont_2, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_wifi_cont_2, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_wifi_cont_2, 243, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_wifi_cont_2, lv_color_hex(0x0F172A), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_wifi_cont_2, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_wifi_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_wifi_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_wifi_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_wifi_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_wifi_cont_2, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui->scr_wifi_cont_2, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui->scr_wifi_cont_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui->scr_wifi_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_x(ui->scr_wifi_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_y(ui->scr_wifi_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_wifi_cont_3
    ui->scr_wifi_cont_3 = lv_obj_create(ui->scr_wifi_cont_2);
    lv_obj_set_pos(ui->scr_wifi_cont_3, 23, 13);
    lv_obj_set_size(ui->scr_wifi_cont_3, 612, 290);
    lv_obj_set_scrollbar_mode(ui->scr_wifi_cont_3, LV_SCROLLBAR_MODE_OFF);

    //Write style for scr_wifi_cont_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_wifi_cont_3, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scr_wifi_cont_3, 16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scr_wifi_cont_3, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scr_wifi_cont_3, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_wifi_cont_3, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_wifi_cont_3, 53, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_wifi_cont_3, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_wifi_cont_3, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_wifi_cont_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_wifi_cont_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_wifi_cont_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_wifi_cont_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_wifi_cont_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_wifi_label_2
    ui->scr_wifi_label_2 = lv_label_create(ui->scr_wifi_cont_3);
    lv_obj_set_pos(ui->scr_wifi_label_2, 24, 22);
    lv_obj_set_size(ui->scr_wifi_label_2, 100, 12);
    lv_label_set_text(ui->scr_wifi_label_2, "SSID NAME");
    lv_label_set_long_mode(ui->scr_wifi_label_2, LV_LABEL_LONG_WRAP);

    //Write style for scr_wifi_label_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_wifi_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_wifi_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_wifi_label_2, lv_color_hex(0x52525B), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_wifi_label_2, &lv_font_Roboto_Black_10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_wifi_label_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_wifi_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_wifi_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_wifi_label_2, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_wifi_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_wifi_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_wifi_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_wifi_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_wifi_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_wifi_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_wifi_ta_1
    ui->scr_wifi_ta_1 = lv_textarea_create(ui->scr_wifi_cont_3);
    lv_obj_set_pos(ui->scr_wifi_ta_1, 24, 39);
    lv_obj_set_size(ui->scr_wifi_ta_1, 270, 38);
    lv_textarea_set_text(ui->scr_wifi_ta_1, "Hello World");
    lv_textarea_set_placeholder_text(ui->scr_wifi_ta_1, "");
    lv_textarea_set_password_bullet(ui->scr_wifi_ta_1, "*");
    lv_textarea_set_password_mode(ui->scr_wifi_ta_1, false);
    lv_textarea_set_one_line(ui->scr_wifi_ta_1, true);
    lv_textarea_set_accepted_chars(ui->scr_wifi_ta_1, "");
    lv_textarea_set_max_length(ui->scr_wifi_ta_1, 32);
#if LV_USE_KEYBOARD
    lv_obj_add_event_cb(ui->scr_wifi_ta_1, ta_event_cb, LV_EVENT_ALL, ui->g_kb_top_layer);
#endif

    //Write style for scr_wifi_ta_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->scr_wifi_ta_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_wifi_ta_1, &lv_font_Roboto_Regular_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_wifi_ta_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_wifi_ta_1, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_wifi_ta_1, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_wifi_ta_1, 153, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_wifi_ta_1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_wifi_ta_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->scr_wifi_ta_1, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scr_wifi_ta_1, 61, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scr_wifi_ta_1, lv_color_hex(0xe6e6e6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scr_wifi_ta_1, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_wifi_ta_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_wifi_ta_1, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_wifi_ta_1, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_wifi_ta_1, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_wifi_ta_1, 12, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for scr_wifi_ta_1, Part: LV_PART_MAIN, State: LV_STATE_FOCUSED.
    lv_obj_set_style_text_color(ui->scr_wifi_ta_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_font(ui->scr_wifi_ta_1, &lv_font_Roboto_Regular_12, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_opa(ui->scr_wifi_ta_1, 255, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_opa(ui->scr_wifi_ta_1, 154, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_color(ui->scr_wifi_ta_1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_grad_dir(ui->scr_wifi_ta_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_width(ui->scr_wifi_ta_1, 1, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_opa(ui->scr_wifi_ta_1, 47, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_color(ui->scr_wifi_ta_1, lv_color_hex(0xe6e6e6), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_side(ui->scr_wifi_ta_1, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_shadow_width(ui->scr_wifi_ta_1, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_pad_top(ui->scr_wifi_ta_1, 10, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_pad_right(ui->scr_wifi_ta_1, 20, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_pad_left(ui->scr_wifi_ta_1, 10, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_radius(ui->scr_wifi_ta_1, 12, LV_PART_MAIN|LV_STATE_FOCUSED);

    //Write style for scr_wifi_ta_1, Part: LV_PART_SCROLLBAR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->scr_wifi_ta_1, 255, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_wifi_ta_1, lv_color_hex(0x2195f6), LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_wifi_ta_1, LV_GRAD_DIR_NONE, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_wifi_ta_1, 0, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);

    //Write codes scr_wifi_label_3
    ui->scr_wifi_label_3 = lv_label_create(ui->scr_wifi_cont_3);
    lv_obj_set_pos(ui->scr_wifi_label_3, 309, 21);
    lv_obj_set_size(ui->scr_wifi_label_3, 100, 12);
    lv_label_set_text(ui->scr_wifi_label_3, "PASSWORD");
    lv_label_set_long_mode(ui->scr_wifi_label_3, LV_LABEL_LONG_WRAP);

    //Write style for scr_wifi_label_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_wifi_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_wifi_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_wifi_label_3, lv_color_hex(0x52525B), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_wifi_label_3, &lv_font_Roboto_Black_10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_wifi_label_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_wifi_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_wifi_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_wifi_label_3, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_wifi_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_wifi_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_wifi_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_wifi_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_wifi_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_wifi_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_wifi_ta_2
    ui->scr_wifi_ta_2 = lv_textarea_create(ui->scr_wifi_cont_3);
    lv_obj_set_pos(ui->scr_wifi_ta_2, 309, 38);
    lv_obj_set_size(ui->scr_wifi_ta_2, 275, 38);
    lv_textarea_set_text(ui->scr_wifi_ta_2, "Hello World");
    lv_textarea_set_placeholder_text(ui->scr_wifi_ta_2, "");
    lv_textarea_set_password_bullet(ui->scr_wifi_ta_2, "*");
    lv_textarea_set_password_mode(ui->scr_wifi_ta_2, true);
    lv_textarea_set_one_line(ui->scr_wifi_ta_2, true);
    lv_textarea_set_accepted_chars(ui->scr_wifi_ta_2, "");
    lv_textarea_set_max_length(ui->scr_wifi_ta_2, 32);
#if LV_USE_KEYBOARD
    lv_obj_add_event_cb(ui->scr_wifi_ta_2, ta_event_cb, LV_EVENT_ALL, ui->g_kb_top_layer);
#endif

    //Write style for scr_wifi_ta_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->scr_wifi_ta_2, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_wifi_ta_2, &lv_font_Roboto_Regular_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_wifi_ta_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_wifi_ta_2, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_wifi_ta_2, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_wifi_ta_2, 153, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_wifi_ta_2, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_wifi_ta_2, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->scr_wifi_ta_2, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scr_wifi_ta_2, 61, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scr_wifi_ta_2, lv_color_hex(0xe6e6e6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scr_wifi_ta_2, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_wifi_ta_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_wifi_ta_2, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_wifi_ta_2, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_wifi_ta_2, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_wifi_ta_2, 12, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for scr_wifi_ta_2, Part: LV_PART_MAIN, State: LV_STATE_FOCUSED.
    lv_obj_set_style_text_color(ui->scr_wifi_ta_2, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_font(ui->scr_wifi_ta_2, &lv_font_Roboto_Regular_12, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_opa(ui->scr_wifi_ta_2, 255, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_opa(ui->scr_wifi_ta_2, 154, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_color(ui->scr_wifi_ta_2, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_grad_dir(ui->scr_wifi_ta_2, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_width(ui->scr_wifi_ta_2, 1, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_opa(ui->scr_wifi_ta_2, 47, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_color(ui->scr_wifi_ta_2, lv_color_hex(0xe6e6e6), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_side(ui->scr_wifi_ta_2, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_shadow_width(ui->scr_wifi_ta_2, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_pad_top(ui->scr_wifi_ta_2, 10, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_pad_right(ui->scr_wifi_ta_2, 20, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_pad_left(ui->scr_wifi_ta_2, 10, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_radius(ui->scr_wifi_ta_2, 12, LV_PART_MAIN|LV_STATE_FOCUSED);

    //Write style for scr_wifi_ta_2, Part: LV_PART_SCROLLBAR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->scr_wifi_ta_2, 255, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_wifi_ta_2, lv_color_hex(0x2195f6), LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_wifi_ta_2, LV_GRAD_DIR_NONE, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_wifi_ta_2, 0, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);

    //Write codes scr_wifi_label_4
    ui->scr_wifi_label_4 = lv_label_create(ui->scr_wifi_cont_3);
    lv_obj_set_pos(ui->scr_wifi_label_4, 24, 94);
    lv_obj_set_size(ui->scr_wifi_label_4, 83, 12);
    lv_label_set_text(ui->scr_wifi_label_4, "MODE");
    lv_label_set_long_mode(ui->scr_wifi_label_4, LV_LABEL_LONG_WRAP);

    //Write style for scr_wifi_label_4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_wifi_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_wifi_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_wifi_label_4, lv_color_hex(0x52525B), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_wifi_label_4, &lv_font_Roboto_Black_10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_wifi_label_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_wifi_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_wifi_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_wifi_label_4, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_wifi_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_wifi_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_wifi_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_wifi_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_wifi_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_wifi_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_wifi_ddlist_2
    ui->scr_wifi_ddlist_2 = lv_dropdown_create(ui->scr_wifi_cont_3);
    lv_obj_set_pos(ui->scr_wifi_ddlist_2, 24, 110);
    lv_obj_set_size(ui->scr_wifi_ddlist_2, 100, 38);
    lv_dropdown_set_options(ui->scr_wifi_ddlist_2, "DHCP\nSTATIC");

    //Write style for scr_wifi_ddlist_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->scr_wifi_ddlist_2, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_wifi_ddlist_2, &lv_font_Roboto_Bold_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_wifi_ddlist_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->scr_wifi_ddlist_2, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scr_wifi_ddlist_2, 48, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scr_wifi_ddlist_2, lv_color_hex(0xe1e6ee), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scr_wifi_ddlist_2, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_wifi_ddlist_2, 12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_wifi_ddlist_2, 12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_wifi_ddlist_2, 12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_wifi_ddlist_2, 12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_wifi_ddlist_2, 154, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_wifi_ddlist_2, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_wifi_ddlist_2, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_wifi_ddlist_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for scr_wifi_ddlist_2, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_text_color(ui->scr_wifi_ddlist_2, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->scr_wifi_ddlist_2, &lv_font_Roboto_Black_12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->scr_wifi_ddlist_2, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_border_width(ui->scr_wifi_ddlist_2, 1, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_border_opa(ui->scr_wifi_ddlist_2, 93, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_border_color(ui->scr_wifi_ddlist_2, lv_color_hex(0xe1e6ee), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_border_side(ui->scr_wifi_ddlist_2, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_pad_top(ui->scr_wifi_ddlist_2, 12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_pad_left(ui->scr_wifi_ddlist_2, 12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_pad_right(ui->scr_wifi_ddlist_2, 12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_radius(ui->scr_wifi_ddlist_2, 12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_opa(ui->scr_wifi_ddlist_2, 153, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui->scr_wifi_ddlist_2, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_grad_dir(ui->scr_wifi_ddlist_2, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->scr_wifi_ddlist_2, 0, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write style for scr_wifi_ddlist_2, Part: LV_PART_MAIN, State: LV_STATE_FOCUSED.
    lv_obj_set_style_text_color(ui->scr_wifi_ddlist_2, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_font(ui->scr_wifi_ddlist_2, &lv_font_Roboto_Black_12, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_opa(ui->scr_wifi_ddlist_2, 255, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_width(ui->scr_wifi_ddlist_2, 1, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_opa(ui->scr_wifi_ddlist_2, 57, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_color(ui->scr_wifi_ddlist_2, lv_color_hex(0xe1e6ee), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_side(ui->scr_wifi_ddlist_2, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_pad_top(ui->scr_wifi_ddlist_2, 12, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_pad_left(ui->scr_wifi_ddlist_2, 12, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_pad_right(ui->scr_wifi_ddlist_2, 12, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_radius(ui->scr_wifi_ddlist_2, 12, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_opa(ui->scr_wifi_ddlist_2, 154, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_color(ui->scr_wifi_ddlist_2, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_grad_dir(ui->scr_wifi_ddlist_2, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_shadow_width(ui->scr_wifi_ddlist_2, 0, LV_PART_MAIN|LV_STATE_FOCUSED);

    //Write style for scr_wifi_ddlist_2, Part: LV_PART_MAIN, State: LV_STATE_DISABLED.
    lv_obj_set_style_text_color(ui->scr_wifi_ddlist_2, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_font(ui->scr_wifi_ddlist_2, &lv_font_Roboto_Black_12, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_opa(ui->scr_wifi_ddlist_2, 255, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_border_width(ui->scr_wifi_ddlist_2, 1, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_border_opa(ui->scr_wifi_ddlist_2, 62, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_border_color(ui->scr_wifi_ddlist_2, lv_color_hex(0xe1e6ee), LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_border_side(ui->scr_wifi_ddlist_2, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_pad_top(ui->scr_wifi_ddlist_2, 12, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_pad_left(ui->scr_wifi_ddlist_2, 12, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_pad_right(ui->scr_wifi_ddlist_2, 12, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_radius(ui->scr_wifi_ddlist_2, 12, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_bg_opa(ui->scr_wifi_ddlist_2, 154, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_bg_color(ui->scr_wifi_ddlist_2, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_bg_grad_dir(ui->scr_wifi_ddlist_2, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_shadow_width(ui->scr_wifi_ddlist_2, 0, LV_PART_MAIN|LV_STATE_DISABLED);

    //Write style state: LV_STATE_CHECKED for &style_scr_wifi_ddlist_2_extra_list_selected_checked
    static lv_style_t style_scr_wifi_ddlist_2_extra_list_selected_checked;
    ui_init_style(&style_scr_wifi_ddlist_2_extra_list_selected_checked);

    lv_style_set_border_width(&style_scr_wifi_ddlist_2_extra_list_selected_checked, 1);
    lv_style_set_border_opa(&style_scr_wifi_ddlist_2_extra_list_selected_checked, 255);
    lv_style_set_border_color(&style_scr_wifi_ddlist_2_extra_list_selected_checked, lv_color_hex(0x7a6363));
    lv_style_set_border_side(&style_scr_wifi_ddlist_2_extra_list_selected_checked, LV_BORDER_SIDE_FULL);
    lv_style_set_radius(&style_scr_wifi_ddlist_2_extra_list_selected_checked, 1);
    lv_style_set_bg_opa(&style_scr_wifi_ddlist_2_extra_list_selected_checked, 113);
    lv_style_set_bg_color(&style_scr_wifi_ddlist_2_extra_list_selected_checked, lv_color_hex(0x989898));
    lv_style_set_bg_grad_dir(&style_scr_wifi_ddlist_2_extra_list_selected_checked, LV_GRAD_DIR_NONE);
    lv_obj_add_style(lv_dropdown_get_list(ui->scr_wifi_ddlist_2), &style_scr_wifi_ddlist_2_extra_list_selected_checked, LV_PART_SELECTED|LV_STATE_CHECKED);

    //Write style state: LV_STATE_DEFAULT for &style_scr_wifi_ddlist_2_extra_list_main_default
    static lv_style_t style_scr_wifi_ddlist_2_extra_list_main_default;
    ui_init_style(&style_scr_wifi_ddlist_2_extra_list_main_default);

    lv_style_set_max_height(&style_scr_wifi_ddlist_2_extra_list_main_default, 90);
    lv_style_set_text_color(&style_scr_wifi_ddlist_2_extra_list_main_default, lv_color_hex(0xffffff));
    lv_style_set_text_font(&style_scr_wifi_ddlist_2_extra_list_main_default, &lv_font_Roboto_Black_12);
    lv_style_set_text_opa(&style_scr_wifi_ddlist_2_extra_list_main_default, 255);
    lv_style_set_border_width(&style_scr_wifi_ddlist_2_extra_list_main_default, 0);
    lv_style_set_radius(&style_scr_wifi_ddlist_2_extra_list_main_default, 0);
    lv_style_set_bg_opa(&style_scr_wifi_ddlist_2_extra_list_main_default, 153);
    lv_style_set_bg_color(&style_scr_wifi_ddlist_2_extra_list_main_default, lv_color_hex(0x000000));
    lv_style_set_bg_grad_dir(&style_scr_wifi_ddlist_2_extra_list_main_default, LV_GRAD_DIR_NONE);
    lv_obj_add_style(lv_dropdown_get_list(ui->scr_wifi_ddlist_2), &style_scr_wifi_ddlist_2_extra_list_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_DEFAULT for &style_scr_wifi_ddlist_2_extra_list_scrollbar_default
    static lv_style_t style_scr_wifi_ddlist_2_extra_list_scrollbar_default;
    ui_init_style(&style_scr_wifi_ddlist_2_extra_list_scrollbar_default);

    lv_style_set_radius(&style_scr_wifi_ddlist_2_extra_list_scrollbar_default, 4);
    lv_style_set_bg_opa(&style_scr_wifi_ddlist_2_extra_list_scrollbar_default, 113);
    lv_style_set_bg_color(&style_scr_wifi_ddlist_2_extra_list_scrollbar_default, lv_color_hex(0x000000));
    lv_style_set_bg_grad_dir(&style_scr_wifi_ddlist_2_extra_list_scrollbar_default, LV_GRAD_DIR_NONE);
    lv_obj_add_style(lv_dropdown_get_list(ui->scr_wifi_ddlist_2), &style_scr_wifi_ddlist_2_extra_list_scrollbar_default, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);

    //Write codes scr_wifi_label_5
    ui->scr_wifi_label_5 = lv_label_create(ui->scr_wifi_cont_3);
    lv_obj_set_pos(ui->scr_wifi_label_5, 141, 94);
    lv_obj_set_size(ui->scr_wifi_label_5, 100, 12);
    lv_label_set_text(ui->scr_wifi_label_5, "IP ADDRESS");
    lv_label_set_long_mode(ui->scr_wifi_label_5, LV_LABEL_LONG_WRAP);

    //Write style for scr_wifi_label_5, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_wifi_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_wifi_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_wifi_label_5, lv_color_hex(0x52525B), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_wifi_label_5, &lv_font_Roboto_Black_10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_wifi_label_5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_wifi_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_wifi_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_wifi_label_5, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_wifi_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_wifi_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_wifi_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_wifi_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_wifi_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_wifi_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_wifi_ta_3
    ui->scr_wifi_ta_3 = lv_textarea_create(ui->scr_wifi_cont_3);
    lv_obj_set_pos(ui->scr_wifi_ta_3, 141, 110);
    lv_obj_set_size(ui->scr_wifi_ta_3, 443, 38);
    lv_textarea_set_text(ui->scr_wifi_ta_3, "Hello World");
    lv_textarea_set_placeholder_text(ui->scr_wifi_ta_3, "");
    lv_textarea_set_password_bullet(ui->scr_wifi_ta_3, "*");
    lv_textarea_set_password_mode(ui->scr_wifi_ta_3, false);
    lv_textarea_set_one_line(ui->scr_wifi_ta_3, true);
    lv_textarea_set_accepted_chars(ui->scr_wifi_ta_3, "");
    lv_textarea_set_max_length(ui->scr_wifi_ta_3, 32);
#if LV_USE_KEYBOARD
    lv_obj_add_event_cb(ui->scr_wifi_ta_3, ta_event_cb, LV_EVENT_ALL, ui->g_kb_top_layer);
#endif

    //Write style for scr_wifi_ta_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->scr_wifi_ta_3, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_wifi_ta_3, &lv_font_Roboto_Regular_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_wifi_ta_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_wifi_ta_3, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_wifi_ta_3, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_wifi_ta_3, 153, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_wifi_ta_3, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_wifi_ta_3, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->scr_wifi_ta_3, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scr_wifi_ta_3, 61, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scr_wifi_ta_3, lv_color_hex(0xe6e6e6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scr_wifi_ta_3, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_wifi_ta_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_wifi_ta_3, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_wifi_ta_3, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_wifi_ta_3, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_wifi_ta_3, 12, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for scr_wifi_ta_3, Part: LV_PART_MAIN, State: LV_STATE_FOCUSED.
    lv_obj_set_style_text_color(ui->scr_wifi_ta_3, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_font(ui->scr_wifi_ta_3, &lv_font_Roboto_Regular_12, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_opa(ui->scr_wifi_ta_3, 255, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_opa(ui->scr_wifi_ta_3, 154, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_color(ui->scr_wifi_ta_3, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_grad_dir(ui->scr_wifi_ta_3, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_width(ui->scr_wifi_ta_3, 1, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_opa(ui->scr_wifi_ta_3, 47, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_color(ui->scr_wifi_ta_3, lv_color_hex(0xe6e6e6), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_side(ui->scr_wifi_ta_3, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_shadow_width(ui->scr_wifi_ta_3, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_pad_top(ui->scr_wifi_ta_3, 10, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_pad_right(ui->scr_wifi_ta_3, 20, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_pad_left(ui->scr_wifi_ta_3, 10, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_radius(ui->scr_wifi_ta_3, 12, LV_PART_MAIN|LV_STATE_FOCUSED);

    //Write style for scr_wifi_ta_3, Part: LV_PART_SCROLLBAR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->scr_wifi_ta_3, 255, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_wifi_ta_3, lv_color_hex(0x2195f6), LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_wifi_ta_3, LV_GRAD_DIR_NONE, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_wifi_ta_3, 0, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);

    //Write codes scr_wifi_label_6
    ui->scr_wifi_label_6 = lv_label_create(ui->scr_wifi_cont_3);
    lv_obj_set_pos(ui->scr_wifi_label_6, 24, 160);
    lv_obj_set_size(ui->scr_wifi_label_6, 100, 12);
    lv_label_set_text(ui->scr_wifi_label_6, "WIFI STATUS");
    lv_label_set_long_mode(ui->scr_wifi_label_6, LV_LABEL_LONG_WRAP);

    //Write style for scr_wifi_label_6, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_wifi_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_wifi_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_wifi_label_6, lv_color_hex(0x52525B), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_wifi_label_6, &lv_font_Roboto_Black_10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_wifi_label_6, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_wifi_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_wifi_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_wifi_label_6, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_wifi_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_wifi_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_wifi_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_wifi_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_wifi_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_wifi_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_wifi_ta_4
    ui->scr_wifi_ta_4 = lv_textarea_create(ui->scr_wifi_cont_3);
    lv_obj_set_pos(ui->scr_wifi_ta_4, 24, 177);
    lv_obj_set_size(ui->scr_wifi_ta_4, 560, 38);
    lv_textarea_set_text(ui->scr_wifi_ta_4, "Hello World");
    lv_textarea_set_placeholder_text(ui->scr_wifi_ta_4, "");
    lv_textarea_set_password_bullet(ui->scr_wifi_ta_4, "*");
    lv_textarea_set_password_mode(ui->scr_wifi_ta_4, false);
    lv_textarea_set_one_line(ui->scr_wifi_ta_4, true);
    lv_textarea_set_accepted_chars(ui->scr_wifi_ta_4, "");
    lv_textarea_set_max_length(ui->scr_wifi_ta_4, 32);
#if LV_USE_KEYBOARD
    lv_obj_add_event_cb(ui->scr_wifi_ta_4, ta_event_cb, LV_EVENT_ALL, ui->g_kb_top_layer);
#endif

    //Write style for scr_wifi_ta_4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->scr_wifi_ta_4, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_wifi_ta_4, &lv_font_Roboto_Regular_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_wifi_ta_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_wifi_ta_4, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_wifi_ta_4, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_wifi_ta_4, 153, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_wifi_ta_4, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_wifi_ta_4, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->scr_wifi_ta_4, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scr_wifi_ta_4, 61, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scr_wifi_ta_4, lv_color_hex(0xe6e6e6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scr_wifi_ta_4, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_wifi_ta_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_wifi_ta_4, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_wifi_ta_4, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_wifi_ta_4, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_wifi_ta_4, 12, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for scr_wifi_ta_4, Part: LV_PART_MAIN, State: LV_STATE_FOCUSED.
    lv_obj_set_style_text_color(ui->scr_wifi_ta_4, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_font(ui->scr_wifi_ta_4, &lv_font_Roboto_Regular_12, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_opa(ui->scr_wifi_ta_4, 255, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_opa(ui->scr_wifi_ta_4, 154, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_color(ui->scr_wifi_ta_4, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_grad_dir(ui->scr_wifi_ta_4, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_width(ui->scr_wifi_ta_4, 1, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_opa(ui->scr_wifi_ta_4, 47, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_color(ui->scr_wifi_ta_4, lv_color_hex(0xe6e6e6), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_side(ui->scr_wifi_ta_4, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_shadow_width(ui->scr_wifi_ta_4, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_pad_top(ui->scr_wifi_ta_4, 10, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_pad_right(ui->scr_wifi_ta_4, 20, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_pad_left(ui->scr_wifi_ta_4, 10, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_radius(ui->scr_wifi_ta_4, 12, LV_PART_MAIN|LV_STATE_FOCUSED);

    //Write style for scr_wifi_ta_4, Part: LV_PART_SCROLLBAR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->scr_wifi_ta_4, 255, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_wifi_ta_4, lv_color_hex(0x2195f6), LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_wifi_ta_4, LV_GRAD_DIR_NONE, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_wifi_ta_4, 0, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);

    //Write codes scr_wifi_btn_7
    ui->scr_wifi_btn_7 = lv_button_create(ui->scr_wifi_cont_3);
    lv_obj_set_pos(ui->scr_wifi_btn_7, 24, 231);
    lv_obj_set_size(ui->scr_wifi_btn_7, 560, 38);
    ui->scr_wifi_btn_7_label = lv_label_create(ui->scr_wifi_btn_7);
    lv_label_set_text(ui->scr_wifi_btn_7_label, "APPLY CONFIG");
    lv_label_set_long_mode(ui->scr_wifi_btn_7_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->scr_wifi_btn_7_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->scr_wifi_btn_7, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->scr_wifi_btn_7_label, LV_PCT(100));

    //Write style for scr_wifi_btn_7, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->scr_wifi_btn_7, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_wifi_btn_7, lv_color_hex(0x10B981), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_wifi_btn_7, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->scr_wifi_btn_7, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scr_wifi_btn_7, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scr_wifi_btn_7, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scr_wifi_btn_7, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_wifi_btn_7, 12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_wifi_btn_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_wifi_btn_7, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_wifi_btn_7, &lv_font_Roboto_Black_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_wifi_btn_7, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_wifi_btn_7, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_wifi_ddlist_1
    ui->scr_wifi_ddlist_1 = lv_dropdown_create(ui->scr_wifi);
    lv_obj_set_pos(ui->scr_wifi_ddlist_1, 620, 88);
    lv_obj_set_size(ui->scr_wifi_ddlist_1, 140, 38);
    lv_dropdown_set_options(ui->scr_wifi_ddlist_1, "ETHERNET\nWIFI\nLTE/4G");

    //Write style for scr_wifi_ddlist_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->scr_wifi_ddlist_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_wifi_ddlist_1, &lv_font_Roboto_Bold_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_wifi_ddlist_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->scr_wifi_ddlist_1, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scr_wifi_ddlist_1, 48, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scr_wifi_ddlist_1, lv_color_hex(0xe1e6ee), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scr_wifi_ddlist_1, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_wifi_ddlist_1, 12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_wifi_ddlist_1, 12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_wifi_ddlist_1, 12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_wifi_ddlist_1, 12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_wifi_ddlist_1, 154, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_wifi_ddlist_1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_wifi_ddlist_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_wifi_ddlist_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for scr_wifi_ddlist_1, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_text_color(ui->scr_wifi_ddlist_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->scr_wifi_ddlist_1, &lv_font_Roboto_Black_12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->scr_wifi_ddlist_1, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_border_width(ui->scr_wifi_ddlist_1, 1, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_border_opa(ui->scr_wifi_ddlist_1, 93, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_border_color(ui->scr_wifi_ddlist_1, lv_color_hex(0xe1e6ee), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_border_side(ui->scr_wifi_ddlist_1, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_pad_top(ui->scr_wifi_ddlist_1, 12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_pad_left(ui->scr_wifi_ddlist_1, 12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_pad_right(ui->scr_wifi_ddlist_1, 12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_radius(ui->scr_wifi_ddlist_1, 12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_opa(ui->scr_wifi_ddlist_1, 153, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui->scr_wifi_ddlist_1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_grad_dir(ui->scr_wifi_ddlist_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->scr_wifi_ddlist_1, 0, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write style for scr_wifi_ddlist_1, Part: LV_PART_MAIN, State: LV_STATE_FOCUSED.
    lv_obj_set_style_text_color(ui->scr_wifi_ddlist_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_font(ui->scr_wifi_ddlist_1, &lv_font_Roboto_Black_12, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_opa(ui->scr_wifi_ddlist_1, 255, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_width(ui->scr_wifi_ddlist_1, 1, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_opa(ui->scr_wifi_ddlist_1, 57, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_color(ui->scr_wifi_ddlist_1, lv_color_hex(0xe1e6ee), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_side(ui->scr_wifi_ddlist_1, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_pad_top(ui->scr_wifi_ddlist_1, 12, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_pad_left(ui->scr_wifi_ddlist_1, 12, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_pad_right(ui->scr_wifi_ddlist_1, 12, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_radius(ui->scr_wifi_ddlist_1, 12, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_opa(ui->scr_wifi_ddlist_1, 154, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_color(ui->scr_wifi_ddlist_1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_grad_dir(ui->scr_wifi_ddlist_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_shadow_width(ui->scr_wifi_ddlist_1, 0, LV_PART_MAIN|LV_STATE_FOCUSED);

    //Write style for scr_wifi_ddlist_1, Part: LV_PART_MAIN, State: LV_STATE_DISABLED.
    lv_obj_set_style_text_color(ui->scr_wifi_ddlist_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_font(ui->scr_wifi_ddlist_1, &lv_font_Roboto_Black_12, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_opa(ui->scr_wifi_ddlist_1, 255, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_border_width(ui->scr_wifi_ddlist_1, 1, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_border_opa(ui->scr_wifi_ddlist_1, 62, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_border_color(ui->scr_wifi_ddlist_1, lv_color_hex(0xe1e6ee), LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_border_side(ui->scr_wifi_ddlist_1, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_pad_top(ui->scr_wifi_ddlist_1, 12, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_pad_left(ui->scr_wifi_ddlist_1, 12, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_pad_right(ui->scr_wifi_ddlist_1, 12, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_radius(ui->scr_wifi_ddlist_1, 12, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_bg_opa(ui->scr_wifi_ddlist_1, 154, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_bg_color(ui->scr_wifi_ddlist_1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_bg_grad_dir(ui->scr_wifi_ddlist_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_shadow_width(ui->scr_wifi_ddlist_1, 0, LV_PART_MAIN|LV_STATE_DISABLED);

    //Write style state: LV_STATE_CHECKED for &style_scr_wifi_ddlist_1_extra_list_selected_checked
    static lv_style_t style_scr_wifi_ddlist_1_extra_list_selected_checked;
    ui_init_style(&style_scr_wifi_ddlist_1_extra_list_selected_checked);

    lv_style_set_border_width(&style_scr_wifi_ddlist_1_extra_list_selected_checked, 1);
    lv_style_set_border_opa(&style_scr_wifi_ddlist_1_extra_list_selected_checked, 255);
    lv_style_set_border_color(&style_scr_wifi_ddlist_1_extra_list_selected_checked, lv_color_hex(0x7a6363));
    lv_style_set_border_side(&style_scr_wifi_ddlist_1_extra_list_selected_checked, LV_BORDER_SIDE_FULL);
    lv_style_set_radius(&style_scr_wifi_ddlist_1_extra_list_selected_checked, 1);
    lv_style_set_bg_opa(&style_scr_wifi_ddlist_1_extra_list_selected_checked, 113);
    lv_style_set_bg_color(&style_scr_wifi_ddlist_1_extra_list_selected_checked, lv_color_hex(0x989898));
    lv_style_set_bg_grad_dir(&style_scr_wifi_ddlist_1_extra_list_selected_checked, LV_GRAD_DIR_NONE);
    lv_obj_add_style(lv_dropdown_get_list(ui->scr_wifi_ddlist_1), &style_scr_wifi_ddlist_1_extra_list_selected_checked, LV_PART_SELECTED|LV_STATE_CHECKED);

    //Write style state: LV_STATE_DEFAULT for &style_scr_wifi_ddlist_1_extra_list_main_default
    static lv_style_t style_scr_wifi_ddlist_1_extra_list_main_default;
    ui_init_style(&style_scr_wifi_ddlist_1_extra_list_main_default);

    lv_style_set_max_height(&style_scr_wifi_ddlist_1_extra_list_main_default, 90);
    lv_style_set_text_color(&style_scr_wifi_ddlist_1_extra_list_main_default, lv_color_hex(0xffffff));
    lv_style_set_text_font(&style_scr_wifi_ddlist_1_extra_list_main_default, &lv_font_Roboto_Black_12);
    lv_style_set_text_opa(&style_scr_wifi_ddlist_1_extra_list_main_default, 255);
    lv_style_set_border_width(&style_scr_wifi_ddlist_1_extra_list_main_default, 0);
    lv_style_set_radius(&style_scr_wifi_ddlist_1_extra_list_main_default, 0);
    lv_style_set_bg_opa(&style_scr_wifi_ddlist_1_extra_list_main_default, 153);
    lv_style_set_bg_color(&style_scr_wifi_ddlist_1_extra_list_main_default, lv_color_hex(0x000000));
    lv_style_set_bg_grad_dir(&style_scr_wifi_ddlist_1_extra_list_main_default, LV_GRAD_DIR_NONE);
    lv_obj_add_style(lv_dropdown_get_list(ui->scr_wifi_ddlist_1), &style_scr_wifi_ddlist_1_extra_list_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_DEFAULT for &style_scr_wifi_ddlist_1_extra_list_scrollbar_default
    static lv_style_t style_scr_wifi_ddlist_1_extra_list_scrollbar_default;
    ui_init_style(&style_scr_wifi_ddlist_1_extra_list_scrollbar_default);

    lv_style_set_radius(&style_scr_wifi_ddlist_1_extra_list_scrollbar_default, 4);
    lv_style_set_bg_opa(&style_scr_wifi_ddlist_1_extra_list_scrollbar_default, 113);
    lv_style_set_bg_color(&style_scr_wifi_ddlist_1_extra_list_scrollbar_default, lv_color_hex(0x000000));
    lv_style_set_bg_grad_dir(&style_scr_wifi_ddlist_1_extra_list_scrollbar_default, LV_GRAD_DIR_NONE);
    lv_obj_add_style(lv_dropdown_get_list(ui->scr_wifi_ddlist_1), &style_scr_wifi_ddlist_1_extra_list_scrollbar_default, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);

    //The custom code of scr_wifi.


    //Update current screen layout.
    lv_obj_update_layout(ui->scr_wifi);

    //Init events for screen.
    events_init_scr_wifi(ui);
}
