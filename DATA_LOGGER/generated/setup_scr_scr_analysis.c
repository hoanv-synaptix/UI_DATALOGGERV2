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



int scr_analysis_digital_clock_1_min_value = 25;
int scr_analysis_digital_clock_1_hour_value = 11;
int scr_analysis_digital_clock_1_sec_value = 50;
void setup_scr_scr_analysis(lv_ui *ui)
{
    //Write codes scr_analysis
    ui->scr_analysis = lv_obj_create(NULL);
    lv_obj_set_size(ui->scr_analysis, 800, 480);
    lv_obj_set_scrollbar_mode(ui->scr_analysis, LV_SCROLLBAR_MODE_OFF);

    //Write style for scr_analysis, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->scr_analysis, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_analysis_img_1
    ui->scr_analysis_img_1 = lv_image_create(ui->scr_analysis);
    lv_obj_set_pos(ui->scr_analysis_img_1, 0, 0);
    lv_obj_set_size(ui->scr_analysis_img_1, 800, 480);
    lv_obj_add_flag(ui->scr_analysis_img_1, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->scr_analysis_img_1, &_bg_settings_base_RGB565A8_800x480);
    lv_image_set_pivot(ui->scr_analysis_img_1, 50,50);
    lv_image_set_rotation(ui->scr_analysis_img_1, 0);

    //Write style for scr_analysis_img_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->scr_analysis_img_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->scr_analysis_img_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_analysis_label_1
    ui->scr_analysis_label_1 = lv_label_create(ui->scr_analysis);
    lv_obj_set_pos(ui->scr_analysis_label_1, 100, 56);
    lv_obj_set_size(ui->scr_analysis_label_1, 172, 11);
    lv_label_set_text(ui->scr_analysis_label_1, "DATA ANALYSIS TRENDS");
    lv_label_set_long_mode(ui->scr_analysis_label_1, LV_LABEL_LONG_WRAP);

    //Write style for scr_analysis_label_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_analysis_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_analysis_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_analysis_label_1, lv_color_hex(0x64748B), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_analysis_label_1, &lv_font_Roboto_Black_10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_analysis_label_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_analysis_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_analysis_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_analysis_label_1, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_analysis_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_analysis_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_analysis_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_analysis_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_analysis_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_analysis_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_analysis_datetext_1
    ui->scr_analysis_datetext_1 = lv_label_create(ui->scr_analysis);
    lv_obj_set_pos(ui->scr_analysis_datetext_1, 600, 30);
    lv_obj_set_size(ui->scr_analysis_datetext_1, 78, 19);
    lv_label_set_text(ui->scr_analysis_datetext_1, "2025/05/15");
    lv_obj_set_style_text_align(ui->scr_analysis_datetext_1, LV_TEXT_ALIGN_CENTER, 0);
    lv_obj_add_flag(ui->scr_analysis_datetext_1, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_add_event_cb(ui->scr_analysis_datetext_1, scr_analysis_datetext_1_event_handler, LV_EVENT_ALL, NULL);

    //Write style for scr_analysis_datetext_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_analysis_datetext_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_analysis_datetext_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_analysis_datetext_1, lv_color_hex(0x64748B), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_analysis_datetext_1, &lv_font_Roboto_Bold_10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_analysis_datetext_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_analysis_datetext_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_analysis_datetext_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_analysis_datetext_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_analysis_datetext_1, 7, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_analysis_datetext_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_analysis_datetext_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_analysis_datetext_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for scr_analysis_datetext_1, Part: LV_PART_MAIN, State: LV_STATE_DISABLED.
    lv_obj_set_style_border_width(ui->scr_analysis_datetext_1, 0, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_radius(ui->scr_analysis_datetext_1, 0, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_color(ui->scr_analysis_datetext_1, lv_color_hex(0x64748B), LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_font(ui->scr_analysis_datetext_1, &lv_font_Roboto_Bold_9, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_opa(ui->scr_analysis_datetext_1, 255, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_letter_space(ui->scr_analysis_datetext_1, 2, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_align(ui->scr_analysis_datetext_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_bg_opa(ui->scr_analysis_datetext_1, 0, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_pad_top(ui->scr_analysis_datetext_1, 7, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_pad_right(ui->scr_analysis_datetext_1, 0, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_pad_left(ui->scr_analysis_datetext_1, 0, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_shadow_width(ui->scr_analysis_datetext_1, 0, LV_PART_MAIN|LV_STATE_DISABLED);

    //Write codes scr_analysis_digital_clock_1
    static bool scr_analysis_digital_clock_1_timer_enabled = false;
    ui->scr_analysis_digital_clock_1 = lv_label_create(ui->scr_analysis);
    lv_obj_set_pos(ui->scr_analysis_digital_clock_1, 695, 30);
    lv_obj_set_size(ui->scr_analysis_digital_clock_1, 74, 19);
    lv_label_set_text(ui->scr_analysis_digital_clock_1, "11:25:50");
    if (!scr_analysis_digital_clock_1_timer_enabled) {
        lv_timer_create(scr_analysis_digital_clock_1_timer, 1000, NULL);
        scr_analysis_digital_clock_1_timer_enabled = true;
    }

    //Write style for scr_analysis_digital_clock_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_radius(ui->scr_analysis_digital_clock_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_analysis_digital_clock_1, lv_color_hex(0x64748B), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_analysis_digital_clock_1, &lv_font_Roboto_Bold_10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_analysis_digital_clock_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_analysis_digital_clock_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_analysis_digital_clock_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_analysis_digital_clock_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_analysis_digital_clock_1, 7, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_analysis_digital_clock_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_analysis_digital_clock_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_analysis_digital_clock_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_analysis_digital_clock_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for scr_analysis_digital_clock_1, Part: LV_PART_MAIN, State: LV_STATE_DISABLED.
    lv_obj_set_style_radius(ui->scr_analysis_digital_clock_1, 0, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_color(ui->scr_analysis_digital_clock_1, lv_color_hex(0x64748B), LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_font(ui->scr_analysis_digital_clock_1, &lv_font_Roboto_Bold_10, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_opa(ui->scr_analysis_digital_clock_1, 255, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_letter_space(ui->scr_analysis_digital_clock_1, 0, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_align(ui->scr_analysis_digital_clock_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_bg_opa(ui->scr_analysis_digital_clock_1, 0, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_pad_top(ui->scr_analysis_digital_clock_1, 7, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_pad_right(ui->scr_analysis_digital_clock_1, 0, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_pad_left(ui->scr_analysis_digital_clock_1, 0, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_shadow_width(ui->scr_analysis_digital_clock_1, 0, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_pad_bottom(ui->scr_analysis_digital_clock_1, 0, LV_PART_MAIN|LV_STATE_DISABLED);

    //Write codes scr_analysis_btn_5
    ui->scr_analysis_btn_5 = lv_button_create(ui->scr_analysis);
    lv_obj_set_pos(ui->scr_analysis_btn_5, 9, 109);
    lv_obj_set_size(ui->scr_analysis_btn_5, 64, 64);
    ui->scr_analysis_btn_5_label = lv_label_create(ui->scr_analysis_btn_5);
    lv_label_set_text(ui->scr_analysis_btn_5_label, "");
    lv_label_set_long_mode(ui->scr_analysis_btn_5_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->scr_analysis_btn_5_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->scr_analysis_btn_5, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->scr_analysis_btn_5_label, LV_PCT(100));

    //Write style for scr_analysis_btn_5, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->scr_analysis_btn_5, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_analysis_btn_5, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_analysis_btn_5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_analysis_btn_5, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_analysis_btn_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_analysis_btn_5, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_analysis_btn_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->scr_analysis_btn_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for scr_analysis_btn_5, Part: LV_PART_MAIN, State: LV_STATE_FOCUSED.
    lv_obj_set_style_text_color(ui->scr_analysis_btn_5, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_font(ui->scr_analysis_btn_5, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_opa(ui->scr_analysis_btn_5, 255, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_opa(ui->scr_analysis_btn_5, 39, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_color(ui->scr_analysis_btn_5, lv_color_hex(0x10B981), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_grad_dir(ui->scr_analysis_btn_5, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_radius(ui->scr_analysis_btn_5, 14, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_shadow_width(ui->scr_analysis_btn_5, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_width(ui->scr_analysis_btn_5, 0, LV_PART_MAIN|LV_STATE_FOCUSED);

    //Write style for scr_analysis_btn_5, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_bg_opa(ui->scr_analysis_btn_5, 40, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_bg_color(ui->scr_analysis_btn_5, lv_color_hex(0x10B981), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_bg_grad_dir(ui->scr_analysis_btn_5, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui->scr_analysis_btn_5, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_radius(ui->scr_analysis_btn_5, 14, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->scr_analysis_btn_5, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->scr_analysis_btn_5, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->scr_analysis_btn_5, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->scr_analysis_btn_5, 255, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for scr_analysis_btn_5, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_bg_opa(ui->scr_analysis_btn_5, 39, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui->scr_analysis_btn_5, lv_color_hex(0x10B981), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_grad_dir(ui->scr_analysis_btn_5, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_border_width(ui->scr_analysis_btn_5, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_radius(ui->scr_analysis_btn_5, 14, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->scr_analysis_btn_5, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->scr_analysis_btn_5, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->scr_analysis_btn_5, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->scr_analysis_btn_5, 255, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write codes scr_analysis_btn_4
    ui->scr_analysis_btn_4 = lv_button_create(ui->scr_analysis);
    lv_obj_set_pos(ui->scr_analysis_btn_4, 9, 181);
    lv_obj_set_size(ui->scr_analysis_btn_4, 64, 64);
    ui->scr_analysis_btn_4_label = lv_label_create(ui->scr_analysis_btn_4);
    lv_label_set_text(ui->scr_analysis_btn_4_label, "");
    lv_label_set_long_mode(ui->scr_analysis_btn_4_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->scr_analysis_btn_4_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->scr_analysis_btn_4, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->scr_analysis_btn_4_label, LV_PCT(100));

    //Write style for scr_analysis_btn_4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_radius(ui->scr_analysis_btn_4, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_analysis_btn_4, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_analysis_btn_4, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_analysis_btn_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_analysis_btn_4, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_analysis_btn_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_analysis_btn_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->scr_analysis_btn_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for scr_analysis_btn_4, Part: LV_PART_MAIN, State: LV_STATE_FOCUSED.
    lv_obj_set_style_radius(ui->scr_analysis_btn_4, 14, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_color(ui->scr_analysis_btn_4, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_font(ui->scr_analysis_btn_4, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_opa(ui->scr_analysis_btn_4, 255, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_opa(ui->scr_analysis_btn_4, 39, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_color(ui->scr_analysis_btn_4, lv_color_hex(0x10B981), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_grad_dir(ui->scr_analysis_btn_4, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_shadow_width(ui->scr_analysis_btn_4, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_width(ui->scr_analysis_btn_4, 0, LV_PART_MAIN|LV_STATE_FOCUSED);

    //Write style for scr_analysis_btn_4, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_bg_opa(ui->scr_analysis_btn_4, 40, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_bg_color(ui->scr_analysis_btn_4, lv_color_hex(0x10B981), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_bg_grad_dir(ui->scr_analysis_btn_4, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui->scr_analysis_btn_4, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_radius(ui->scr_analysis_btn_4, 14, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->scr_analysis_btn_4, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->scr_analysis_btn_4, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->scr_analysis_btn_4, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->scr_analysis_btn_4, 255, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for scr_analysis_btn_4, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_bg_opa(ui->scr_analysis_btn_4, 39, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui->scr_analysis_btn_4, lv_color_hex(0x10B981), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_grad_dir(ui->scr_analysis_btn_4, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_border_width(ui->scr_analysis_btn_4, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_radius(ui->scr_analysis_btn_4, 14, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->scr_analysis_btn_4, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->scr_analysis_btn_4, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->scr_analysis_btn_4, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->scr_analysis_btn_4, 255, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write codes scr_analysis_btn_3
    ui->scr_analysis_btn_3 = lv_button_create(ui->scr_analysis);
    lv_obj_set_pos(ui->scr_analysis_btn_3, 9, 255);
    lv_obj_set_size(ui->scr_analysis_btn_3, 64, 64);
    ui->scr_analysis_btn_3_label = lv_label_create(ui->scr_analysis_btn_3);
    lv_label_set_text(ui->scr_analysis_btn_3_label, "");
    lv_label_set_long_mode(ui->scr_analysis_btn_3_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->scr_analysis_btn_3_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->scr_analysis_btn_3, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->scr_analysis_btn_3_label, LV_PCT(100));

    //Write style for scr_analysis_btn_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->scr_analysis_btn_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->scr_analysis_btn_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_analysis_btn_3, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_analysis_btn_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_analysis_btn_3, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_analysis_btn_3, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_analysis_btn_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_analysis_btn_3, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for scr_analysis_btn_3, Part: LV_PART_MAIN, State: LV_STATE_FOCUSED.
    lv_obj_set_style_bg_opa(ui->scr_analysis_btn_3, 39, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_color(ui->scr_analysis_btn_3, lv_color_hex(0x10B981), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_grad_dir(ui->scr_analysis_btn_3, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_width(ui->scr_analysis_btn_3, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_radius(ui->scr_analysis_btn_3, 14, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_shadow_width(ui->scr_analysis_btn_3, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_color(ui->scr_analysis_btn_3, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_font(ui->scr_analysis_btn_3, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_opa(ui->scr_analysis_btn_3, 255, LV_PART_MAIN|LV_STATE_FOCUSED);

    //Write style for scr_analysis_btn_3, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_bg_opa(ui->scr_analysis_btn_3, 40, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_bg_color(ui->scr_analysis_btn_3, lv_color_hex(0x10B981), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_bg_grad_dir(ui->scr_analysis_btn_3, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui->scr_analysis_btn_3, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_radius(ui->scr_analysis_btn_3, 14, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->scr_analysis_btn_3, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->scr_analysis_btn_3, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->scr_analysis_btn_3, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->scr_analysis_btn_3, 255, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for scr_analysis_btn_3, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_bg_opa(ui->scr_analysis_btn_3, 39, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui->scr_analysis_btn_3, lv_color_hex(0x10B981), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_grad_dir(ui->scr_analysis_btn_3, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_border_width(ui->scr_analysis_btn_3, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_radius(ui->scr_analysis_btn_3, 14, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->scr_analysis_btn_3, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->scr_analysis_btn_3, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->scr_analysis_btn_3, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->scr_analysis_btn_3, 255, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write codes scr_analysis_btn_2
    ui->scr_analysis_btn_2 = lv_button_create(ui->scr_analysis);
    lv_obj_set_pos(ui->scr_analysis_btn_2, 9, 325);
    lv_obj_set_size(ui->scr_analysis_btn_2, 64, 64);
    ui->scr_analysis_btn_2_label = lv_label_create(ui->scr_analysis_btn_2);
    lv_label_set_text(ui->scr_analysis_btn_2_label, "");
    lv_label_set_long_mode(ui->scr_analysis_btn_2_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->scr_analysis_btn_2_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->scr_analysis_btn_2, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->scr_analysis_btn_2_label, LV_PCT(100));

    //Write style for scr_analysis_btn_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_analysis_btn_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_analysis_btn_2, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_analysis_btn_2, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_analysis_btn_2, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_analysis_btn_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_analysis_btn_2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_analysis_btn_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_analysis_btn_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for scr_analysis_btn_2, Part: LV_PART_MAIN, State: LV_STATE_FOCUSED.
    lv_obj_set_style_border_width(ui->scr_analysis_btn_2, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_radius(ui->scr_analysis_btn_2, 14, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_color(ui->scr_analysis_btn_2, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_font(ui->scr_analysis_btn_2, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_opa(ui->scr_analysis_btn_2, 255, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_opa(ui->scr_analysis_btn_2, 39, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_color(ui->scr_analysis_btn_2, lv_color_hex(0x10B981), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_grad_dir(ui->scr_analysis_btn_2, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_shadow_width(ui->scr_analysis_btn_2, 0, LV_PART_MAIN|LV_STATE_FOCUSED);

    //Write style for scr_analysis_btn_2, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_bg_opa(ui->scr_analysis_btn_2, 40, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_bg_color(ui->scr_analysis_btn_2, lv_color_hex(0x10B981), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_bg_grad_dir(ui->scr_analysis_btn_2, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui->scr_analysis_btn_2, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_radius(ui->scr_analysis_btn_2, 14, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->scr_analysis_btn_2, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->scr_analysis_btn_2, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->scr_analysis_btn_2, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->scr_analysis_btn_2, 255, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for scr_analysis_btn_2, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_bg_opa(ui->scr_analysis_btn_2, 39, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui->scr_analysis_btn_2, lv_color_hex(0x10B981), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_grad_dir(ui->scr_analysis_btn_2, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_border_width(ui->scr_analysis_btn_2, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_radius(ui->scr_analysis_btn_2, 14, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->scr_analysis_btn_2, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->scr_analysis_btn_2, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->scr_analysis_btn_2, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->scr_analysis_btn_2, 255, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write codes scr_analysis_btn_1
    ui->scr_analysis_btn_1 = lv_button_create(ui->scr_analysis);
    lv_obj_set_pos(ui->scr_analysis_btn_1, 9, 393);
    lv_obj_set_size(ui->scr_analysis_btn_1, 64, 64);
    ui->scr_analysis_btn_1_label = lv_label_create(ui->scr_analysis_btn_1);
    lv_label_set_text(ui->scr_analysis_btn_1_label, "");
    lv_label_set_long_mode(ui->scr_analysis_btn_1_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->scr_analysis_btn_1_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->scr_analysis_btn_1, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->scr_analysis_btn_1_label, LV_PCT(100));

    //Write style for scr_analysis_btn_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_radius(ui->scr_analysis_btn_1, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_analysis_btn_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_analysis_btn_1, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_analysis_btn_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_analysis_btn_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_analysis_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_analysis_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->scr_analysis_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for scr_analysis_btn_1, Part: LV_PART_MAIN, State: LV_STATE_FOCUSED.
    lv_obj_set_style_radius(ui->scr_analysis_btn_1, 14, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_color(ui->scr_analysis_btn_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_font(ui->scr_analysis_btn_1, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_opa(ui->scr_analysis_btn_1, 255, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_opa(ui->scr_analysis_btn_1, 39, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_color(ui->scr_analysis_btn_1, lv_color_hex(0x10B981), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_grad_dir(ui->scr_analysis_btn_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_shadow_width(ui->scr_analysis_btn_1, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_width(ui->scr_analysis_btn_1, 0, LV_PART_MAIN|LV_STATE_FOCUSED);

    //Write style for scr_analysis_btn_1, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_bg_opa(ui->scr_analysis_btn_1, 40, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_bg_color(ui->scr_analysis_btn_1, lv_color_hex(0x10B981), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_bg_grad_dir(ui->scr_analysis_btn_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui->scr_analysis_btn_1, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_radius(ui->scr_analysis_btn_1, 14, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->scr_analysis_btn_1, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->scr_analysis_btn_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->scr_analysis_btn_1, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->scr_analysis_btn_1, 255, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for scr_analysis_btn_1, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_bg_opa(ui->scr_analysis_btn_1, 39, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui->scr_analysis_btn_1, lv_color_hex(0x10B981), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_grad_dir(ui->scr_analysis_btn_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_border_width(ui->scr_analysis_btn_1, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_radius(ui->scr_analysis_btn_1, 14, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->scr_analysis_btn_1, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->scr_analysis_btn_1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->scr_analysis_btn_1, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->scr_analysis_btn_1, 255, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write codes scr_analysis_img_5
    ui->scr_analysis_img_5 = lv_image_create(ui->scr_analysis);
    lv_obj_set_pos(ui->scr_analysis_img_5, 546, 32);
    lv_obj_set_size(ui->scr_analysis_img_5, 16, 16);
    lv_obj_add_flag(ui->scr_analysis_img_5, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->scr_analysis_img_5, &_mqtt_on_RGB565A8_16x16);
    lv_image_set_pivot(ui->scr_analysis_img_5, 50,50);
    lv_image_set_rotation(ui->scr_analysis_img_5, 0);

    //Write style for scr_analysis_img_5, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->scr_analysis_img_5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_recolor(ui->scr_analysis_img_5, lv_color_hex(0xababba), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->scr_analysis_img_5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_analysis_img_4
    ui->scr_analysis_img_4 = lv_image_create(ui->scr_analysis);
    lv_obj_set_pos(ui->scr_analysis_img_4, 476, 32);
    lv_obj_set_size(ui->scr_analysis_img_4, 16, 16);
    lv_obj_add_flag(ui->scr_analysis_img_4, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(ui->scr_analysis_img_4, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->scr_analysis_img_4, &_wifi_on_RGB565A8_16x16);
    lv_image_set_pivot(ui->scr_analysis_img_4, 50,50);
    lv_image_set_rotation(ui->scr_analysis_img_4, 0);

    //Write style for scr_analysis_img_4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->scr_analysis_img_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_recolor(ui->scr_analysis_img_4, lv_color_hex(0xababab), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->scr_analysis_img_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_analysis_img_3
    ui->scr_analysis_img_3 = lv_image_create(ui->scr_analysis);
    lv_obj_set_pos(ui->scr_analysis_img_3, 546, 32);
    lv_obj_set_size(ui->scr_analysis_img_3, 16, 16);
    lv_obj_add_flag(ui->scr_analysis_img_3, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(ui->scr_analysis_img_3, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->scr_analysis_img_3, &_mqtt_off_RGB565A8_16x16);
    lv_image_set_pivot(ui->scr_analysis_img_3, 50,50);
    lv_image_set_rotation(ui->scr_analysis_img_3, 0);

    //Write style for scr_analysis_img_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->scr_analysis_img_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_recolor(ui->scr_analysis_img_3, lv_color_hex(0xababba), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->scr_analysis_img_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_analysis_img_2
    ui->scr_analysis_img_2 = lv_image_create(ui->scr_analysis);
    lv_obj_set_pos(ui->scr_analysis_img_2, 476, 32);
    lv_obj_set_size(ui->scr_analysis_img_2, 16, 16);
    lv_obj_add_flag(ui->scr_analysis_img_2, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->scr_analysis_img_2, &_wifi_off_RGB565A8_16x16);
    lv_image_set_pivot(ui->scr_analysis_img_2, 50,50);
    lv_image_set_rotation(ui->scr_analysis_img_2, 0);

    //Write style for scr_analysis_img_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->scr_analysis_img_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_recolor(ui->scr_analysis_img_2, lv_color_hex(0xababba), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->scr_analysis_img_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of scr_analysis.


    //Update current screen layout.
    lv_obj_update_layout(ui->scr_analysis);

    //Init events for screen.
    events_init_scr_analysis(ui);
}
