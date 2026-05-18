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



int scr_dashboard_digital_clock_1_min_value = 25;
int scr_dashboard_digital_clock_1_hour_value = 11;
int scr_dashboard_digital_clock_1_sec_value = 50;
void setup_scr_scr_dashboard(lv_ui *ui)
{
    //Write codes scr_dashboard
    ui->scr_dashboard = lv_obj_create(NULL);
    lv_obj_set_size(ui->scr_dashboard, 800, 480);
    lv_obj_set_scrollbar_mode(ui->scr_dashboard, LV_SCROLLBAR_MODE_OFF);

    //Write style for scr_dashboard, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->scr_dashboard, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_dashboard_img_1
    ui->scr_dashboard_img_1 = lv_image_create(ui->scr_dashboard);
    lv_obj_set_pos(ui->scr_dashboard_img_1, 0, 0);
    lv_obj_set_size(ui->scr_dashboard_img_1, 800, 480);
    lv_obj_add_flag(ui->scr_dashboard_img_1, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->scr_dashboard_img_1, &_bg_settings_base_RGB565A8_800x480);
    lv_image_set_pivot(ui->scr_dashboard_img_1, 50,50);
    lv_image_set_rotation(ui->scr_dashboard_img_1, 0);

    //Write style for scr_dashboard_img_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->scr_dashboard_img_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->scr_dashboard_img_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_dashboard_label_1
    ui->scr_dashboard_label_1 = lv_label_create(ui->scr_dashboard);
    lv_obj_set_pos(ui->scr_dashboard_label_1, 100, 56);
    lv_obj_set_size(ui->scr_dashboard_label_1, 172, 11);
    lv_label_set_text(ui->scr_dashboard_label_1, "REAL-TIME MONITORING");
    lv_label_set_long_mode(ui->scr_dashboard_label_1, LV_LABEL_LONG_WRAP);

    //Write style for scr_dashboard_label_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->scr_dashboard_label_1, lv_color_hex(0x64748B), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_dashboard_label_1, &lv_font_Roboto_Black_10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_dashboard_label_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_dashboard_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_dashboard_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_dashboard_label_1, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_dashboard_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->scr_dashboard_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_dashboard_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_dashboard_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_dashboard_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_dashboard_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_dashboard_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_dashboard_datetext_1
    ui->scr_dashboard_datetext_1 = lv_label_create(ui->scr_dashboard);
    lv_obj_set_pos(ui->scr_dashboard_datetext_1, 600, 30);
    lv_obj_set_size(ui->scr_dashboard_datetext_1, 78, 19);
    lv_label_set_text(ui->scr_dashboard_datetext_1, "2025/05/15");
    lv_obj_set_style_text_align(ui->scr_dashboard_datetext_1, LV_TEXT_ALIGN_CENTER, 0);
    lv_obj_add_flag(ui->scr_dashboard_datetext_1, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_add_event_cb(ui->scr_dashboard_datetext_1, scr_dashboard_datetext_1_event_handler, LV_EVENT_ALL, NULL);

    //Write style for scr_dashboard_datetext_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_radius(ui->scr_dashboard_datetext_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_dashboard_datetext_1, lv_color_hex(0x64748B), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_dashboard_datetext_1, &lv_font_Roboto_Bold_10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_dashboard_datetext_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_dashboard_datetext_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_dashboard_datetext_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_dashboard_datetext_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_dashboard_datetext_1, 7, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_dashboard_datetext_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_dashboard_datetext_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_datetext_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->scr_dashboard_datetext_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for scr_dashboard_datetext_1, Part: LV_PART_MAIN, State: LV_STATE_DISABLED.
    lv_obj_set_style_radius(ui->scr_dashboard_datetext_1, 0, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_color(ui->scr_dashboard_datetext_1, lv_color_hex(0x64748B), LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_font(ui->scr_dashboard_datetext_1, &lv_font_Roboto_Bold_9, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_opa(ui->scr_dashboard_datetext_1, 255, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_letter_space(ui->scr_dashboard_datetext_1, 2, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_align(ui->scr_dashboard_datetext_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_bg_opa(ui->scr_dashboard_datetext_1, 0, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_pad_top(ui->scr_dashboard_datetext_1, 7, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_pad_right(ui->scr_dashboard_datetext_1, 0, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_pad_left(ui->scr_dashboard_datetext_1, 0, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_datetext_1, 0, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_border_width(ui->scr_dashboard_datetext_1, 0, LV_PART_MAIN|LV_STATE_DISABLED);

    //Write codes scr_dashboard_digital_clock_1
    static bool scr_dashboard_digital_clock_1_timer_enabled = false;
    ui->scr_dashboard_digital_clock_1 = lv_label_create(ui->scr_dashboard);
    lv_obj_set_pos(ui->scr_dashboard_digital_clock_1, 695, 30);
    lv_obj_set_size(ui->scr_dashboard_digital_clock_1, 74, 19);
    lv_label_set_text(ui->scr_dashboard_digital_clock_1, "11:25:50");
    if (!scr_dashboard_digital_clock_1_timer_enabled) {
        lv_timer_create(scr_dashboard_digital_clock_1_timer, 1000, NULL);
        scr_dashboard_digital_clock_1_timer_enabled = true;
    }

    //Write style for scr_dashboard_digital_clock_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_radius(ui->scr_dashboard_digital_clock_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_dashboard_digital_clock_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_dashboard_digital_clock_1, 7, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_dashboard_digital_clock_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_dashboard_digital_clock_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_dashboard_digital_clock_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_digital_clock_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_dashboard_digital_clock_1, lv_color_hex(0x64748B), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_dashboard_digital_clock_1, &lv_font_Roboto_Bold_10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_dashboard_digital_clock_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_dashboard_digital_clock_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_dashboard_digital_clock_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for scr_dashboard_digital_clock_1, Part: LV_PART_MAIN, State: LV_STATE_DISABLED.
    lv_obj_set_style_radius(ui->scr_dashboard_digital_clock_1, 0, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_color(ui->scr_dashboard_digital_clock_1, lv_color_hex(0x64748B), LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_font(ui->scr_dashboard_digital_clock_1, &lv_font_Roboto_Bold_10, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_opa(ui->scr_dashboard_digital_clock_1, 255, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_letter_space(ui->scr_dashboard_digital_clock_1, 0, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_align(ui->scr_dashboard_digital_clock_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_bg_opa(ui->scr_dashboard_digital_clock_1, 0, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_pad_top(ui->scr_dashboard_digital_clock_1, 7, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_pad_right(ui->scr_dashboard_digital_clock_1, 0, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_pad_bottom(ui->scr_dashboard_digital_clock_1, 0, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_pad_left(ui->scr_dashboard_digital_clock_1, 0, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_digital_clock_1, 0, LV_PART_MAIN|LV_STATE_DISABLED);

    //Write codes scr_dashboard_cont_1
    ui->scr_dashboard_cont_1 = lv_obj_create(ui->scr_dashboard);
    lv_obj_set_pos(ui->scr_dashboard_cont_1, 100, 86);
    lv_obj_set_size(ui->scr_dashboard_cont_1, 230, 372);
    lv_obj_set_scrollbar_mode(ui->scr_dashboard_cont_1, LV_SCROLLBAR_MODE_OFF);

    //Write style for scr_dashboard_cont_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_dashboard_cont_1, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scr_dashboard_cont_1, 19, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scr_dashboard_cont_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scr_dashboard_cont_1, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_dashboard_cont_1, 24, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_dashboard_cont_1, 243, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_dashboard_cont_1, lv_color_hex(0x0F172A), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_dashboard_cont_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_dashboard_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_dashboard_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_dashboard_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_dashboard_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_cont_1, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui->scr_dashboard_cont_1, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui->scr_dashboard_cont_1, 129, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui->scr_dashboard_cont_1, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_x(ui->scr_dashboard_cont_1, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_y(ui->scr_dashboard_cont_1, 1, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_dashboard_label_2
    ui->scr_dashboard_label_2 = lv_label_create(ui->scr_dashboard_cont_1);
    lv_obj_set_pos(ui->scr_dashboard_label_2, 8, 28);
    lv_obj_set_size(ui->scr_dashboard_label_2, 100, 16);
    lv_label_set_text(ui->scr_dashboard_label_2, "AQI INDEX");
    lv_label_set_long_mode(ui->scr_dashboard_label_2, LV_LABEL_LONG_WRAP);

    //Write style for scr_dashboard_label_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_dashboard_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_dashboard_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_dashboard_label_2, lv_color_hex(0x64748B), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_dashboard_label_2, &lv_font_Roboto_Black_14, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_dashboard_label_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_dashboard_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_dashboard_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_dashboard_label_2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_dashboard_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_dashboard_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_dashboard_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_dashboard_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_dashboard_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_dashboard_cont_2
    ui->scr_dashboard_cont_2 = lv_obj_create(ui->scr_dashboard_cont_1);
    lv_obj_set_pos(ui->scr_dashboard_cont_2, 41, 293);
    lv_obj_set_size(ui->scr_dashboard_cont_2, 150, 50);
    lv_obj_set_scrollbar_mode(ui->scr_dashboard_cont_2, LV_SCROLLBAR_MODE_OFF);

    //Write style for scr_dashboard_cont_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_dashboard_cont_2, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scr_dashboard_cont_2, 44, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scr_dashboard_cont_2, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scr_dashboard_cont_2, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_dashboard_cont_2, 24, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_dashboard_cont_2, 243, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_dashboard_cont_2, lv_color_hex(0x0F172A), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_dashboard_cont_2, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_dashboard_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_dashboard_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_dashboard_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_dashboard_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_dashboard_label_4
    ui->scr_dashboard_label_4 = lv_label_create(ui->scr_dashboard_cont_2);
    lv_obj_set_pos(ui->scr_dashboard_label_4, 24, 12);
    lv_obj_set_size(ui->scr_dashboard_label_4, 100, 26);
    lv_label_set_text(ui->scr_dashboard_label_4, "GOOD");
    lv_label_set_long_mode(ui->scr_dashboard_label_4, LV_LABEL_LONG_WRAP);

    //Write style for scr_dashboard_label_4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_dashboard_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_dashboard_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_dashboard_label_4, lv_color_hex(0x34D399), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_dashboard_label_4, &lv_font_Roboto_Black_24, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_dashboard_label_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_dashboard_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_dashboard_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_dashboard_label_4, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_dashboard_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_dashboard_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_dashboard_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_dashboard_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_dashboard_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_dashboard_cont_3
    ui->scr_dashboard_cont_3 = lv_obj_create(ui->scr_dashboard_cont_1);
    lv_obj_set_pos(ui->scr_dashboard_cont_3, 4, 68);
    lv_obj_set_size(ui->scr_dashboard_cont_3, 218, 200);
    lv_obj_set_scrollbar_mode(ui->scr_dashboard_cont_3, LV_SCROLLBAR_MODE_OFF);

    //Write style for scr_dashboard_cont_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_dashboard_cont_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_dashboard_cont_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_dashboard_cont_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_dashboard_cont_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_dashboard_cont_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_dashboard_cont_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_dashboard_cont_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_cont_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_dashboard_label_3
    ui->scr_dashboard_label_3 = lv_label_create(ui->scr_dashboard_cont_3);
    lv_obj_set_pos(ui->scr_dashboard_label_3, 28, 64);
    lv_obj_set_size(ui->scr_dashboard_label_3, 159, 71);
    lv_label_set_text(ui->scr_dashboard_label_3, "45");
    lv_label_set_long_mode(ui->scr_dashboard_label_3, LV_LABEL_LONG_WRAP);

    //Write style for scr_dashboard_label_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_dashboard_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_dashboard_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_dashboard_label_3, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_dashboard_label_3, &lv_font_Roboto_Bold_72, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_dashboard_label_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_dashboard_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_dashboard_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_dashboard_label_3, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_dashboard_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_dashboard_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_dashboard_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_dashboard_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_dashboard_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_dashboard_arc_1
    ui->scr_dashboard_arc_1 = lv_arc_create(ui->scr_dashboard_cont_3);
    lv_obj_set_pos(ui->scr_dashboard_arc_1, 0, -8);
    lv_obj_set_size(ui->scr_dashboard_arc_1, 220, 220);
    lv_arc_set_mode(ui->scr_dashboard_arc_1, LV_ARC_MODE_NORMAL);
    lv_arc_set_range(ui->scr_dashboard_arc_1, 0, 500);
    lv_arc_set_bg_angles(ui->scr_dashboard_arc_1, 0, 359);
    lv_arc_set_value(ui->scr_dashboard_arc_1, 45);
    lv_arc_set_rotation(ui->scr_dashboard_arc_1, 270);

    //Write style for scr_dashboard_arc_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->scr_dashboard_arc_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->scr_dashboard_arc_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_width(ui->scr_dashboard_arc_1, 12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui->scr_dashboard_arc_1, 51, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_color(ui->scr_dashboard_arc_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_rounded(ui->scr_dashboard_arc_1, true, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_dashboard_arc_1, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_dashboard_arc_1, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_dashboard_arc_1, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_dashboard_arc_1, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_dashboard_arc_1, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_arc_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for scr_dashboard_arc_1, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_arc_width(ui->scr_dashboard_arc_1, 12, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui->scr_dashboard_arc_1, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_color(ui->scr_dashboard_arc_1, lv_color_hex(0x34D399), LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_rounded(ui->scr_dashboard_arc_1, true, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write style for scr_dashboard_arc_1, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->scr_dashboard_arc_1, 0, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui->scr_dashboard_arc_1, 5, LV_PART_KNOB|LV_STATE_DEFAULT);

    //Write codes scr_dashboard_cont_4
    ui->scr_dashboard_cont_4 = lv_obj_create(ui->scr_dashboard);
    lv_obj_set_pos(ui->scr_dashboard_cont_4, 346, 86);
    lv_obj_set_size(ui->scr_dashboard_cont_4, 211, 116);
    lv_obj_set_scrollbar_mode(ui->scr_dashboard_cont_4, LV_SCROLLBAR_MODE_OFF);

    //Write style for scr_dashboard_cont_4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_dashboard_cont_4, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scr_dashboard_cont_4, 19, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scr_dashboard_cont_4, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scr_dashboard_cont_4, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_dashboard_cont_4, 24, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_dashboard_cont_4, 243, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_dashboard_cont_4, lv_color_hex(0x0F172A), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_dashboard_cont_4, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_dashboard_cont_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_dashboard_cont_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_dashboard_cont_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_dashboard_cont_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_cont_4, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui->scr_dashboard_cont_4, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui->scr_dashboard_cont_4, 129, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui->scr_dashboard_cont_4, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_x(ui->scr_dashboard_cont_4, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_y(ui->scr_dashboard_cont_4, 1, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_dashboard_label_5
    ui->scr_dashboard_label_5 = lv_label_create(ui->scr_dashboard_cont_4);
    lv_obj_set_pos(ui->scr_dashboard_label_5, 7, 16);
    lv_obj_set_size(ui->scr_dashboard_label_5, 88, 26);
    lv_label_set_text(ui->scr_dashboard_label_5, "PM 2.5");
    lv_label_set_long_mode(ui->scr_dashboard_label_5, LV_LABEL_LONG_WRAP);

    //Write style for scr_dashboard_label_5, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_dashboard_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_dashboard_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_dashboard_label_5, lv_color_hex(0xCBD5E1), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_dashboard_label_5, &lv_font_Roboto_Black_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_dashboard_label_5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_dashboard_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_dashboard_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_dashboard_label_5, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_dashboard_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_dashboard_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_dashboard_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_dashboard_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_dashboard_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_dashboard_label_13
    ui->scr_dashboard_label_13 = lv_label_create(ui->scr_dashboard_cont_4);
    lv_obj_set_pos(ui->scr_dashboard_label_13, 30, 49);
    lv_obj_set_size(ui->scr_dashboard_label_13, 100, 52);
    lv_label_set_text(ui->scr_dashboard_label_13, "12.4");
    lv_label_set_long_mode(ui->scr_dashboard_label_13, LV_LABEL_LONG_WRAP);

    //Write style for scr_dashboard_label_13, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_dashboard_label_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_dashboard_label_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_dashboard_label_13, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_dashboard_label_13, &lv_font_Roboto_Black_48, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_dashboard_label_13, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_dashboard_label_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_dashboard_label_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_dashboard_label_13, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_dashboard_label_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_dashboard_label_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_dashboard_label_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_dashboard_label_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_dashboard_label_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_label_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_dashboard_cont_12
    ui->scr_dashboard_cont_12 = lv_obj_create(ui->scr_dashboard_cont_4);
    lv_obj_set_pos(ui->scr_dashboard_cont_12, 129, 12);
    lv_obj_set_size(ui->scr_dashboard_cont_12, 60, 20);
    lv_obj_set_scrollbar_mode(ui->scr_dashboard_cont_12, LV_SCROLLBAR_MODE_OFF);

    //Write style for scr_dashboard_cont_12, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_dashboard_cont_12, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scr_dashboard_cont_12, 19, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scr_dashboard_cont_12, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scr_dashboard_cont_12, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_dashboard_cont_12, 24, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_dashboard_cont_12, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_dashboard_cont_12, lv_color_hex(0x100f2c), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_dashboard_cont_12, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_dashboard_cont_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_dashboard_cont_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_dashboard_cont_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_dashboard_cont_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_cont_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_dashboard_label_14
    ui->scr_dashboard_label_14 = lv_label_create(ui->scr_dashboard_cont_12);
    lv_obj_set_pos(ui->scr_dashboard_label_14, 5, 4);
    lv_obj_set_size(ui->scr_dashboard_label_14, 49, 10);
    lv_label_set_text(ui->scr_dashboard_label_14, "NORMAL");
    lv_label_set_long_mode(ui->scr_dashboard_label_14, LV_LABEL_LONG_WRAP);

    //Write style for scr_dashboard_label_14, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_dashboard_label_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_dashboard_label_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_dashboard_label_14, lv_color_hex(0x34D399), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_dashboard_label_14, &lv_font_Roboto_Bold_9, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_dashboard_label_14, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_dashboard_label_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_dashboard_label_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_dashboard_label_14, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_dashboard_label_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_dashboard_label_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_dashboard_label_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_dashboard_label_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_dashboard_label_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_label_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_dashboard_label_15
    ui->scr_dashboard_label_15 = lv_label_create(ui->scr_dashboard_cont_4);
    lv_obj_set_pos(ui->scr_dashboard_label_15, 136, 76);
    lv_obj_set_size(ui->scr_dashboard_label_15, 55, 25);
    lv_label_set_text(ui->scr_dashboard_label_15, "µg/m³");
    lv_label_set_long_mode(ui->scr_dashboard_label_15, LV_LABEL_LONG_WRAP);

    //Write style for scr_dashboard_label_15, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_dashboard_label_15, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_dashboard_label_15, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_dashboard_label_15, lv_color_hex(0xababab), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_dashboard_label_15, &lv_font_Roboto_Black_15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_dashboard_label_15, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_dashboard_label_15, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_dashboard_label_15, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_dashboard_label_15, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_dashboard_label_15, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_dashboard_label_15, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_dashboard_label_15, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_dashboard_label_15, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_dashboard_label_15, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_label_15, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_dashboard_cont_8
    ui->scr_dashboard_cont_8 = lv_obj_create(ui->scr_dashboard);
    lv_obj_set_pos(ui->scr_dashboard_cont_8, 346, 214);
    lv_obj_set_size(ui->scr_dashboard_cont_8, 99, 116);
    lv_obj_set_scrollbar_mode(ui->scr_dashboard_cont_8, LV_SCROLLBAR_MODE_OFF);

    //Write style for scr_dashboard_cont_8, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_dashboard_cont_8, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scr_dashboard_cont_8, 19, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scr_dashboard_cont_8, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scr_dashboard_cont_8, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_dashboard_cont_8, 24, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_dashboard_cont_8, 243, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_dashboard_cont_8, lv_color_hex(0x0F172A), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_dashboard_cont_8, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_dashboard_cont_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_dashboard_cont_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_dashboard_cont_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_dashboard_cont_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_cont_8, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui->scr_dashboard_cont_8, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui->scr_dashboard_cont_8, 79, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui->scr_dashboard_cont_8, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_x(ui->scr_dashboard_cont_8, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_y(ui->scr_dashboard_cont_8, 1, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_dashboard_label_22
    ui->scr_dashboard_label_22 = lv_label_create(ui->scr_dashboard_cont_8);
    lv_obj_set_pos(ui->scr_dashboard_label_22, 45, 88);
    lv_obj_set_size(ui->scr_dashboard_label_22, 55, 16);
    lv_label_set_text(ui->scr_dashboard_label_22, "ppb");
    lv_label_set_long_mode(ui->scr_dashboard_label_22, LV_LABEL_LONG_WRAP);

    //Write style for scr_dashboard_label_22, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_dashboard_label_22, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_dashboard_label_22, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_dashboard_label_22, lv_color_hex(0xababab), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_dashboard_label_22, &lv_font_Roboto_Black_15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_dashboard_label_22, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_dashboard_label_22, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_dashboard_label_22, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_dashboard_label_22, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_dashboard_label_22, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_dashboard_label_22, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_dashboard_label_22, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_dashboard_label_22, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_dashboard_label_22, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_label_22, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_dashboard_label_21
    ui->scr_dashboard_label_21 = lv_label_create(ui->scr_dashboard_cont_8);
    lv_obj_set_pos(ui->scr_dashboard_label_21, 11, 49);
    lv_obj_set_size(ui->scr_dashboard_label_21, 65, 26);
    lv_label_set_text(ui->scr_dashboard_label_21, "12.4");
    lv_label_set_long_mode(ui->scr_dashboard_label_21, LV_LABEL_LONG_WRAP);

    //Write style for scr_dashboard_label_21, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_dashboard_label_21, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_dashboard_label_21, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_dashboard_label_21, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_dashboard_label_21, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_dashboard_label_21, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_dashboard_label_21, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_dashboard_label_21, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_label_21, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_dashboard_label_21, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_dashboard_label_21, &lv_font_Roboto_Black_25, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_dashboard_label_21, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_dashboard_label_21, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_dashboard_label_21, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_dashboard_label_21, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_dashboard_label_20
    ui->scr_dashboard_label_20 = lv_label_create(ui->scr_dashboard_cont_8);
    lv_obj_set_pos(ui->scr_dashboard_label_20, 13, 17);
    lv_obj_set_size(ui->scr_dashboard_label_20, 39, 17);
    lv_label_set_text(ui->scr_dashboard_label_20, "NO2");
    lv_label_set_long_mode(ui->scr_dashboard_label_20, LV_LABEL_LONG_WRAP);

    //Write style for scr_dashboard_label_20, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_dashboard_label_20, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_dashboard_label_20, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_dashboard_label_20, lv_color_hex(0xCBD5E1), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_dashboard_label_20, &lv_font_Roboto_Black_15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_dashboard_label_20, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_dashboard_label_20, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_dashboard_label_20, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_dashboard_label_20, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_dashboard_label_20, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_dashboard_label_20, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_dashboard_label_20, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_dashboard_label_20, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_dashboard_label_20, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_label_20, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_dashboard_cont_13
    ui->scr_dashboard_cont_13 = lv_obj_create(ui->scr_dashboard);
    lv_obj_set_pos(ui->scr_dashboard_cont_13, 573, 86);
    lv_obj_set_size(ui->scr_dashboard_cont_13, 211, 116);
    lv_obj_set_scrollbar_mode(ui->scr_dashboard_cont_13, LV_SCROLLBAR_MODE_OFF);

    //Write style for scr_dashboard_cont_13, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_dashboard_cont_13, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scr_dashboard_cont_13, 19, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scr_dashboard_cont_13, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scr_dashboard_cont_13, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_dashboard_cont_13, 24, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_dashboard_cont_13, 243, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_dashboard_cont_13, lv_color_hex(0x0F172A), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_dashboard_cont_13, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_dashboard_cont_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_dashboard_cont_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_dashboard_cont_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_dashboard_cont_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_cont_13, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui->scr_dashboard_cont_13, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui->scr_dashboard_cont_13, 130, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui->scr_dashboard_cont_13, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_x(ui->scr_dashboard_cont_13, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_y(ui->scr_dashboard_cont_13, 1, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_dashboard_label_19
    ui->scr_dashboard_label_19 = lv_label_create(ui->scr_dashboard_cont_13);
    lv_obj_set_pos(ui->scr_dashboard_label_19, 7, 16);
    lv_obj_set_size(ui->scr_dashboard_label_19, 88, 26);
    lv_label_set_text(ui->scr_dashboard_label_19, "PM 10");
    lv_label_set_long_mode(ui->scr_dashboard_label_19, LV_LABEL_LONG_WRAP);

    //Write style for scr_dashboard_label_19, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_dashboard_label_19, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_dashboard_label_19, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_dashboard_label_19, lv_color_hex(0xCBD5E1), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_dashboard_label_19, &lv_font_Roboto_Black_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_dashboard_label_19, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_dashboard_label_19, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_dashboard_label_19, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_dashboard_label_19, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_dashboard_label_19, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_dashboard_label_19, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_dashboard_label_19, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_dashboard_label_19, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_dashboard_label_19, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_label_19, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_dashboard_label_18
    ui->scr_dashboard_label_18 = lv_label_create(ui->scr_dashboard_cont_13);
    lv_obj_set_pos(ui->scr_dashboard_label_18, 30, 48);
    lv_obj_set_size(ui->scr_dashboard_label_18, 100, 52);
    lv_label_set_text(ui->scr_dashboard_label_18, "28.1");
    lv_label_set_long_mode(ui->scr_dashboard_label_18, LV_LABEL_LONG_WRAP);

    //Write style for scr_dashboard_label_18, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_dashboard_label_18, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_dashboard_label_18, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_dashboard_label_18, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_dashboard_label_18, &lv_font_Roboto_Black_48, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_dashboard_label_18, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_dashboard_label_18, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_dashboard_label_18, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_dashboard_label_18, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_dashboard_label_18, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_dashboard_label_18, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_dashboard_label_18, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_dashboard_label_18, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_dashboard_label_18, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_label_18, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_dashboard_cont_14
    ui->scr_dashboard_cont_14 = lv_obj_create(ui->scr_dashboard_cont_13);
    lv_obj_set_pos(ui->scr_dashboard_cont_14, 129, 12);
    lv_obj_set_size(ui->scr_dashboard_cont_14, 60, 20);
    lv_obj_set_scrollbar_mode(ui->scr_dashboard_cont_14, LV_SCROLLBAR_MODE_OFF);

    //Write style for scr_dashboard_cont_14, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_dashboard_cont_14, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scr_dashboard_cont_14, 19, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scr_dashboard_cont_14, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scr_dashboard_cont_14, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_dashboard_cont_14, 24, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_dashboard_cont_14, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_dashboard_cont_14, lv_color_hex(0x100f2c), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_dashboard_cont_14, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_dashboard_cont_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_dashboard_cont_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_dashboard_cont_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_dashboard_cont_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_cont_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_dashboard_label_17
    ui->scr_dashboard_label_17 = lv_label_create(ui->scr_dashboard_cont_14);
    lv_obj_set_pos(ui->scr_dashboard_label_17, 5, 4);
    lv_obj_set_size(ui->scr_dashboard_label_17, 49, 10);
    lv_label_set_text(ui->scr_dashboard_label_17, "NORMAL");
    lv_label_set_long_mode(ui->scr_dashboard_label_17, LV_LABEL_LONG_WRAP);

    //Write style for scr_dashboard_label_17, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_dashboard_label_17, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_dashboard_label_17, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_dashboard_label_17, lv_color_hex(0x34D399), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_dashboard_label_17, &lv_font_Roboto_Bold_9, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_dashboard_label_17, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_dashboard_label_17, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_dashboard_label_17, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_dashboard_label_17, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_dashboard_label_17, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_dashboard_label_17, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_dashboard_label_17, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_dashboard_label_17, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_dashboard_label_17, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_label_17, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_dashboard_label_16
    ui->scr_dashboard_label_16 = lv_label_create(ui->scr_dashboard_cont_13);
    lv_obj_set_pos(ui->scr_dashboard_label_16, 136, 76);
    lv_obj_set_size(ui->scr_dashboard_label_16, 55, 25);
    lv_label_set_text(ui->scr_dashboard_label_16, "µg/m³");
    lv_label_set_long_mode(ui->scr_dashboard_label_16, LV_LABEL_LONG_WRAP);

    //Write style for scr_dashboard_label_16, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_dashboard_label_16, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_dashboard_label_16, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_dashboard_label_16, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_dashboard_label_16, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_dashboard_label_16, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_dashboard_label_16, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_dashboard_label_16, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_label_16, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_dashboard_label_16, lv_color_hex(0xababab), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_dashboard_label_16, &lv_font_Roboto_Black_15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_dashboard_label_16, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_dashboard_label_16, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_dashboard_label_16, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_dashboard_label_16, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_dashboard_cont_15
    ui->scr_dashboard_cont_15 = lv_obj_create(ui->scr_dashboard);
    lv_obj_set_pos(ui->scr_dashboard_cont_15, 459, 214);
    lv_obj_set_size(ui->scr_dashboard_cont_15, 99, 116);
    lv_obj_set_scrollbar_mode(ui->scr_dashboard_cont_15, LV_SCROLLBAR_MODE_OFF);

    //Write style for scr_dashboard_cont_15, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_dashboard_cont_15, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scr_dashboard_cont_15, 19, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scr_dashboard_cont_15, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scr_dashboard_cont_15, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_dashboard_cont_15, 24, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_dashboard_cont_15, 243, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_dashboard_cont_15, lv_color_hex(0x0F172A), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_dashboard_cont_15, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_dashboard_cont_15, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_dashboard_cont_15, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_dashboard_cont_15, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_dashboard_cont_15, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_cont_15, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui->scr_dashboard_cont_15, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui->scr_dashboard_cont_15, 79, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui->scr_dashboard_cont_15, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_x(ui->scr_dashboard_cont_15, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_y(ui->scr_dashboard_cont_15, 1, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_dashboard_label_25
    ui->scr_dashboard_label_25 = lv_label_create(ui->scr_dashboard_cont_15);
    lv_obj_set_pos(ui->scr_dashboard_label_25, 45, 88);
    lv_obj_set_size(ui->scr_dashboard_label_25, 55, 16);
    lv_label_set_text(ui->scr_dashboard_label_25, "ppb");
    lv_label_set_long_mode(ui->scr_dashboard_label_25, LV_LABEL_LONG_WRAP);

    //Write style for scr_dashboard_label_25, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_dashboard_label_25, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_dashboard_label_25, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_dashboard_label_25, lv_color_hex(0xababab), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_dashboard_label_25, &lv_font_Roboto_Black_15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_dashboard_label_25, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_dashboard_label_25, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_dashboard_label_25, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_dashboard_label_25, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_dashboard_label_25, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_dashboard_label_25, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_dashboard_label_25, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_dashboard_label_25, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_dashboard_label_25, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_label_25, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_dashboard_label_24
    ui->scr_dashboard_label_24 = lv_label_create(ui->scr_dashboard_cont_15);
    lv_obj_set_pos(ui->scr_dashboard_label_24, 11, 49);
    lv_obj_set_size(ui->scr_dashboard_label_24, 65, 26);
    lv_label_set_text(ui->scr_dashboard_label_24, "12.4");
    lv_label_set_long_mode(ui->scr_dashboard_label_24, LV_LABEL_LONG_WRAP);

    //Write style for scr_dashboard_label_24, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_dashboard_label_24, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_dashboard_label_24, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_dashboard_label_24, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_dashboard_label_24, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_dashboard_label_24, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_dashboard_label_24, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_dashboard_label_24, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_label_24, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_dashboard_label_24, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_dashboard_label_24, &lv_font_Roboto_Black_25, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_dashboard_label_24, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_dashboard_label_24, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_dashboard_label_24, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_dashboard_label_24, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_dashboard_label_23
    ui->scr_dashboard_label_23 = lv_label_create(ui->scr_dashboard_cont_15);
    lv_obj_set_pos(ui->scr_dashboard_label_23, 13, 17);
    lv_obj_set_size(ui->scr_dashboard_label_23, 35, 17);
    lv_label_set_text(ui->scr_dashboard_label_23, "O3");
    lv_label_set_long_mode(ui->scr_dashboard_label_23, LV_LABEL_LONG_WRAP);

    //Write style for scr_dashboard_label_23, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_dashboard_label_23, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_dashboard_label_23, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_dashboard_label_23, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_dashboard_label_23, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_dashboard_label_23, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_dashboard_label_23, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_dashboard_label_23, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_label_23, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_dashboard_label_23, lv_color_hex(0xCBD5E1), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_dashboard_label_23, &lv_font_Roboto_Black_15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_dashboard_label_23, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_dashboard_label_23, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_dashboard_label_23, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_dashboard_label_23, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_dashboard_cont_16
    ui->scr_dashboard_cont_16 = lv_obj_create(ui->scr_dashboard);
    lv_obj_set_pos(ui->scr_dashboard_cont_16, 572, 214);
    lv_obj_set_size(ui->scr_dashboard_cont_16, 99, 116);
    lv_obj_set_scrollbar_mode(ui->scr_dashboard_cont_16, LV_SCROLLBAR_MODE_OFF);

    //Write style for scr_dashboard_cont_16, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_dashboard_cont_16, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scr_dashboard_cont_16, 19, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scr_dashboard_cont_16, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scr_dashboard_cont_16, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_dashboard_cont_16, 24, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_dashboard_cont_16, 243, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_dashboard_cont_16, lv_color_hex(0x0F172A), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_dashboard_cont_16, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_dashboard_cont_16, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_dashboard_cont_16, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_dashboard_cont_16, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_dashboard_cont_16, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_cont_16, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui->scr_dashboard_cont_16, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui->scr_dashboard_cont_16, 79, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui->scr_dashboard_cont_16, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_x(ui->scr_dashboard_cont_16, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_y(ui->scr_dashboard_cont_16, 1, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_dashboard_label_28
    ui->scr_dashboard_label_28 = lv_label_create(ui->scr_dashboard_cont_16);
    lv_obj_set_pos(ui->scr_dashboard_label_28, 45, 88);
    lv_obj_set_size(ui->scr_dashboard_label_28, 55, 16);
    lv_label_set_text(ui->scr_dashboard_label_28, "ppb");
    lv_label_set_long_mode(ui->scr_dashboard_label_28, LV_LABEL_LONG_WRAP);

    //Write style for scr_dashboard_label_28, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_dashboard_label_28, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_dashboard_label_28, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_dashboard_label_28, lv_color_hex(0xababab), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_dashboard_label_28, &lv_font_Roboto_Black_15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_dashboard_label_28, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_dashboard_label_28, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_dashboard_label_28, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_dashboard_label_28, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_dashboard_label_28, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_dashboard_label_28, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_dashboard_label_28, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_dashboard_label_28, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_dashboard_label_28, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_label_28, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_dashboard_label_27
    ui->scr_dashboard_label_27 = lv_label_create(ui->scr_dashboard_cont_16);
    lv_obj_set_pos(ui->scr_dashboard_label_27, 11, 49);
    lv_obj_set_size(ui->scr_dashboard_label_27, 65, 26);
    lv_label_set_text(ui->scr_dashboard_label_27, "12.4");
    lv_label_set_long_mode(ui->scr_dashboard_label_27, LV_LABEL_LONG_WRAP);

    //Write style for scr_dashboard_label_27, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_dashboard_label_27, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_dashboard_label_27, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_dashboard_label_27, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_dashboard_label_27, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_dashboard_label_27, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_dashboard_label_27, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_dashboard_label_27, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_label_27, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_dashboard_label_27, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_dashboard_label_27, &lv_font_Roboto_Black_25, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_dashboard_label_27, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_dashboard_label_27, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_dashboard_label_27, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_dashboard_label_27, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_dashboard_label_26
    ui->scr_dashboard_label_26 = lv_label_create(ui->scr_dashboard_cont_16);
    lv_obj_set_pos(ui->scr_dashboard_label_26, 13, 17);
    lv_obj_set_size(ui->scr_dashboard_label_26, 54, 17);
    lv_label_set_text(ui->scr_dashboard_label_26, "CO2");
    lv_label_set_long_mode(ui->scr_dashboard_label_26, LV_LABEL_LONG_WRAP);

    //Write style for scr_dashboard_label_26, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_dashboard_label_26, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_dashboard_label_26, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_dashboard_label_26, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_dashboard_label_26, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_dashboard_label_26, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_dashboard_label_26, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_dashboard_label_26, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_label_26, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_dashboard_label_26, lv_color_hex(0xCBD5E1), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_dashboard_label_26, &lv_font_Roboto_Black_15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_dashboard_label_26, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_dashboard_label_26, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_dashboard_label_26, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_dashboard_label_26, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_dashboard_cont_17
    ui->scr_dashboard_cont_17 = lv_obj_create(ui->scr_dashboard);
    lv_obj_set_pos(ui->scr_dashboard_cont_17, 685, 214);
    lv_obj_set_size(ui->scr_dashboard_cont_17, 99, 116);
    lv_obj_set_scrollbar_mode(ui->scr_dashboard_cont_17, LV_SCROLLBAR_MODE_OFF);

    //Write style for scr_dashboard_cont_17, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_dashboard_cont_17, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scr_dashboard_cont_17, 19, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scr_dashboard_cont_17, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scr_dashboard_cont_17, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_dashboard_cont_17, 24, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_dashboard_cont_17, 243, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_dashboard_cont_17, lv_color_hex(0x0F172A), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_dashboard_cont_17, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_dashboard_cont_17, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_dashboard_cont_17, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_dashboard_cont_17, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_dashboard_cont_17, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_cont_17, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui->scr_dashboard_cont_17, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui->scr_dashboard_cont_17, 79, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui->scr_dashboard_cont_17, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_x(ui->scr_dashboard_cont_17, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_y(ui->scr_dashboard_cont_17, 1, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_dashboard_label_31
    ui->scr_dashboard_label_31 = lv_label_create(ui->scr_dashboard_cont_17);
    lv_obj_set_pos(ui->scr_dashboard_label_31, 45, 88);
    lv_obj_set_size(ui->scr_dashboard_label_31, 55, 16);
    lv_label_set_text(ui->scr_dashboard_label_31, "ppb");
    lv_label_set_long_mode(ui->scr_dashboard_label_31, LV_LABEL_LONG_WRAP);

    //Write style for scr_dashboard_label_31, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_dashboard_label_31, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_dashboard_label_31, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_dashboard_label_31, lv_color_hex(0xababab), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_dashboard_label_31, &lv_font_Roboto_Black_15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_dashboard_label_31, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_dashboard_label_31, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_dashboard_label_31, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_dashboard_label_31, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_dashboard_label_31, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_dashboard_label_31, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_dashboard_label_31, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_dashboard_label_31, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_dashboard_label_31, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_label_31, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_dashboard_label_30
    ui->scr_dashboard_label_30 = lv_label_create(ui->scr_dashboard_cont_17);
    lv_obj_set_pos(ui->scr_dashboard_label_30, 11, 49);
    lv_obj_set_size(ui->scr_dashboard_label_30, 65, 26);
    lv_label_set_text(ui->scr_dashboard_label_30, "12.4");
    lv_label_set_long_mode(ui->scr_dashboard_label_30, LV_LABEL_LONG_WRAP);

    //Write style for scr_dashboard_label_30, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_dashboard_label_30, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_dashboard_label_30, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_dashboard_label_30, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_dashboard_label_30, &lv_font_Roboto_Black_25, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_dashboard_label_30, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_dashboard_label_30, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_dashboard_label_30, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_dashboard_label_30, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_dashboard_label_30, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_dashboard_label_30, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_dashboard_label_30, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_dashboard_label_30, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_dashboard_label_30, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_label_30, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_dashboard_label_29
    ui->scr_dashboard_label_29 = lv_label_create(ui->scr_dashboard_cont_17);
    lv_obj_set_pos(ui->scr_dashboard_label_29, 13, 17);
    lv_obj_set_size(ui->scr_dashboard_label_29, 54, 17);
    lv_label_set_text(ui->scr_dashboard_label_29, "SO2");
    lv_label_set_long_mode(ui->scr_dashboard_label_29, LV_LABEL_LONG_WRAP);

    //Write style for scr_dashboard_label_29, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_dashboard_label_29, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_dashboard_label_29, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_dashboard_label_29, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_dashboard_label_29, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_dashboard_label_29, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_dashboard_label_29, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_dashboard_label_29, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_label_29, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_dashboard_label_29, lv_color_hex(0xCBD5E1), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_dashboard_label_29, &lv_font_Roboto_Black_15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_dashboard_label_29, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_dashboard_label_29, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_dashboard_label_29, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_dashboard_label_29, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_dashboard_cont_18
    ui->scr_dashboard_cont_18 = lv_obj_create(ui->scr_dashboard);
    lv_obj_set_pos(ui->scr_dashboard_cont_18, 346, 342);
    lv_obj_set_size(ui->scr_dashboard_cont_18, 211, 116);
    lv_obj_set_scrollbar_mode(ui->scr_dashboard_cont_18, LV_SCROLLBAR_MODE_OFF);

    //Write style for scr_dashboard_cont_18, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_dashboard_cont_18, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scr_dashboard_cont_18, 19, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scr_dashboard_cont_18, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scr_dashboard_cont_18, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_dashboard_cont_18, 24, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_dashboard_cont_18, 243, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_dashboard_cont_18, lv_color_hex(0x0F172A), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_dashboard_cont_18, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_dashboard_cont_18, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_dashboard_cont_18, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_dashboard_cont_18, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_dashboard_cont_18, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_cont_18, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui->scr_dashboard_cont_18, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui->scr_dashboard_cont_18, 129, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui->scr_dashboard_cont_18, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_x(ui->scr_dashboard_cont_18, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_y(ui->scr_dashboard_cont_18, 1, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_dashboard_label_35
    ui->scr_dashboard_label_35 = lv_label_create(ui->scr_dashboard_cont_18);
    lv_obj_set_pos(ui->scr_dashboard_label_35, 7, 16);
    lv_obj_set_size(ui->scr_dashboard_label_35, 88, 26);
    lv_label_set_text(ui->scr_dashboard_label_35, "TEMP");
    lv_label_set_long_mode(ui->scr_dashboard_label_35, LV_LABEL_LONG_WRAP);

    //Write style for scr_dashboard_label_35, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_dashboard_label_35, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_dashboard_label_35, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_dashboard_label_35, lv_color_hex(0xCBD5E1), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_dashboard_label_35, &lv_font_Roboto_Black_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_dashboard_label_35, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_dashboard_label_35, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_dashboard_label_35, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_dashboard_label_35, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_dashboard_label_35, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_dashboard_label_35, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_dashboard_label_35, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_dashboard_label_35, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_dashboard_label_35, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_label_35, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_dashboard_label_34
    ui->scr_dashboard_label_34 = lv_label_create(ui->scr_dashboard_cont_18);
    lv_obj_set_pos(ui->scr_dashboard_label_34, 46, 50);
    lv_obj_set_size(ui->scr_dashboard_label_34, 100, 52);
    lv_label_set_text(ui->scr_dashboard_label_34, "12.4");
    lv_label_set_long_mode(ui->scr_dashboard_label_34, LV_LABEL_LONG_WRAP);

    //Write style for scr_dashboard_label_34, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_dashboard_label_34, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_dashboard_label_34, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_dashboard_label_34, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_dashboard_label_34, &lv_font_Roboto_Black_48, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_dashboard_label_34, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_dashboard_label_34, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_dashboard_label_34, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_dashboard_label_34, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_dashboard_label_34, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_dashboard_label_34, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_dashboard_label_34, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_dashboard_label_34, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_dashboard_label_34, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_label_34, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_dashboard_label_32
    ui->scr_dashboard_label_32 = lv_label_create(ui->scr_dashboard_cont_18);
    lv_obj_set_pos(ui->scr_dashboard_label_32, 136, 76);
    lv_obj_set_size(ui->scr_dashboard_label_32, 55, 25);
    lv_label_set_text(ui->scr_dashboard_label_32, "°C");
    lv_label_set_long_mode(ui->scr_dashboard_label_32, LV_LABEL_LONG_WRAP);

    //Write style for scr_dashboard_label_32, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_dashboard_label_32, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_dashboard_label_32, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_dashboard_label_32, lv_color_hex(0xababab), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_dashboard_label_32, &lv_font_Roboto_Black_15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_dashboard_label_32, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_dashboard_label_32, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_dashboard_label_32, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_dashboard_label_32, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_dashboard_label_32, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_dashboard_label_32, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_dashboard_label_32, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_dashboard_label_32, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_dashboard_label_32, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_label_32, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_dashboard_img_2
    ui->scr_dashboard_img_2 = lv_image_create(ui->scr_dashboard_cont_18);
    lv_obj_set_pos(ui->scr_dashboard_img_2, 153, 16);
    lv_obj_set_size(ui->scr_dashboard_img_2, 32, 32);
    lv_obj_add_flag(ui->scr_dashboard_img_2, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->scr_dashboard_img_2, &_weather_RGB565A8_32x32);
    lv_image_set_pivot(ui->scr_dashboard_img_2, 50,50);
    lv_image_set_rotation(ui->scr_dashboard_img_2, 0);

    //Write style for scr_dashboard_img_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->scr_dashboard_img_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->scr_dashboard_img_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_dashboard_cont_19
    ui->scr_dashboard_cont_19 = lv_obj_create(ui->scr_dashboard);
    lv_obj_set_pos(ui->scr_dashboard_cont_19, 573, 342);
    lv_obj_set_size(ui->scr_dashboard_cont_19, 211, 116);
    lv_obj_set_scrollbar_mode(ui->scr_dashboard_cont_19, LV_SCROLLBAR_MODE_OFF);

    //Write style for scr_dashboard_cont_19, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_dashboard_cont_19, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scr_dashboard_cont_19, 19, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scr_dashboard_cont_19, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scr_dashboard_cont_19, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_dashboard_cont_19, 24, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_dashboard_cont_19, 243, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_dashboard_cont_19, lv_color_hex(0x0F172A), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_dashboard_cont_19, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_dashboard_cont_19, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_dashboard_cont_19, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_dashboard_cont_19, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_dashboard_cont_19, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_cont_19, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui->scr_dashboard_cont_19, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui->scr_dashboard_cont_19, 129, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui->scr_dashboard_cont_19, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_x(ui->scr_dashboard_cont_19, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_y(ui->scr_dashboard_cont_19, 1, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_dashboard_label_38
    ui->scr_dashboard_label_38 = lv_label_create(ui->scr_dashboard_cont_19);
    lv_obj_set_pos(ui->scr_dashboard_label_38, 7, 16);
    lv_obj_set_size(ui->scr_dashboard_label_38, 88, 26);
    lv_label_set_text(ui->scr_dashboard_label_38, "HUMP");
    lv_label_set_long_mode(ui->scr_dashboard_label_38, LV_LABEL_LONG_WRAP);

    //Write style for scr_dashboard_label_38, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_dashboard_label_38, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_dashboard_label_38, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_dashboard_label_38, lv_color_hex(0xCBD5E1), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_dashboard_label_38, &lv_font_Roboto_Black_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_dashboard_label_38, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_dashboard_label_38, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_dashboard_label_38, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_dashboard_label_38, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_dashboard_label_38, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_dashboard_label_38, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_dashboard_label_38, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_dashboard_label_38, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_dashboard_label_38, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_label_38, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_dashboard_label_37
    ui->scr_dashboard_label_37 = lv_label_create(ui->scr_dashboard_cont_19);
    lv_obj_set_pos(ui->scr_dashboard_label_37, 48, 50);
    lv_obj_set_size(ui->scr_dashboard_label_37, 100, 52);
    lv_label_set_text(ui->scr_dashboard_label_37, "62.0");
    lv_label_set_long_mode(ui->scr_dashboard_label_37, LV_LABEL_LONG_WRAP);

    //Write style for scr_dashboard_label_37, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_dashboard_label_37, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_dashboard_label_37, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_dashboard_label_37, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_dashboard_label_37, &lv_font_Roboto_Black_48, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_dashboard_label_37, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_dashboard_label_37, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_dashboard_label_37, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_dashboard_label_37, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_dashboard_label_37, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_dashboard_label_37, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_dashboard_label_37, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_dashboard_label_37, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_dashboard_label_37, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_label_37, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_dashboard_label_36
    ui->scr_dashboard_label_36 = lv_label_create(ui->scr_dashboard_cont_19);
    lv_obj_set_pos(ui->scr_dashboard_label_36, 136, 76);
    lv_obj_set_size(ui->scr_dashboard_label_36, 55, 25);
    lv_label_set_text(ui->scr_dashboard_label_36, "%");
    lv_label_set_long_mode(ui->scr_dashboard_label_36, LV_LABEL_LONG_WRAP);

    //Write style for scr_dashboard_label_36, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_dashboard_label_36, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_dashboard_label_36, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_dashboard_label_36, lv_color_hex(0xababab), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_dashboard_label_36, &lv_font_Roboto_Black_15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_dashboard_label_36, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_dashboard_label_36, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_dashboard_label_36, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_dashboard_label_36, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_dashboard_label_36, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_dashboard_label_36, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_dashboard_label_36, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_dashboard_label_36, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_dashboard_label_36, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_label_36, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_dashboard_img_3
    ui->scr_dashboard_img_3 = lv_image_create(ui->scr_dashboard_cont_19);
    lv_obj_set_pos(ui->scr_dashboard_img_3, 153, 16);
    lv_obj_set_size(ui->scr_dashboard_img_3, 32, 32);
    lv_obj_add_flag(ui->scr_dashboard_img_3, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->scr_dashboard_img_3, &_humidity_RGB565A8_32x32);
    lv_image_set_pivot(ui->scr_dashboard_img_3, 50,50);
    lv_image_set_rotation(ui->scr_dashboard_img_3, 0);

    //Write style for scr_dashboard_img_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->scr_dashboard_img_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->scr_dashboard_img_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_dashboard_img_4
    ui->scr_dashboard_img_4 = lv_image_create(ui->scr_dashboard);
    lv_obj_set_pos(ui->scr_dashboard_img_4, 476, 32);
    lv_obj_set_size(ui->scr_dashboard_img_4, 16, 16);
    lv_obj_add_flag(ui->scr_dashboard_img_4, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->scr_dashboard_img_4, &_wifi_on_RGB565A8_16x16);
    lv_image_set_pivot(ui->scr_dashboard_img_4, 50,50);
    lv_image_set_rotation(ui->scr_dashboard_img_4, 0);

    //Write style for scr_dashboard_img_4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->scr_dashboard_img_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_recolor(ui->scr_dashboard_img_4, lv_color_hex(0xababab), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->scr_dashboard_img_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_dashboard_img_5
    ui->scr_dashboard_img_5 = lv_image_create(ui->scr_dashboard);
    lv_obj_set_pos(ui->scr_dashboard_img_5, 476, 32);
    lv_obj_set_size(ui->scr_dashboard_img_5, 16, 16);
    lv_obj_add_flag(ui->scr_dashboard_img_5, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(ui->scr_dashboard_img_5, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->scr_dashboard_img_5, &_wifi_off_RGB565A8_16x16);
    lv_image_set_pivot(ui->scr_dashboard_img_5, 50,50);
    lv_image_set_rotation(ui->scr_dashboard_img_5, 0);

    //Write style for scr_dashboard_img_5, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->scr_dashboard_img_5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_recolor(ui->scr_dashboard_img_5, lv_color_hex(0xababba), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->scr_dashboard_img_5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_dashboard_img_6
    ui->scr_dashboard_img_6 = lv_image_create(ui->scr_dashboard);
    lv_obj_set_pos(ui->scr_dashboard_img_6, 546, 32);
    lv_obj_set_size(ui->scr_dashboard_img_6, 16, 16);
    lv_obj_add_flag(ui->scr_dashboard_img_6, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(ui->scr_dashboard_img_6, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->scr_dashboard_img_6, &_mqtt_off_RGB565A8_16x16);
    lv_image_set_pivot(ui->scr_dashboard_img_6, 50,50);
    lv_image_set_rotation(ui->scr_dashboard_img_6, 0);

    //Write style for scr_dashboard_img_6, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->scr_dashboard_img_6, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_recolor(ui->scr_dashboard_img_6, lv_color_hex(0xababba), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->scr_dashboard_img_6, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_dashboard_img_7
    ui->scr_dashboard_img_7 = lv_image_create(ui->scr_dashboard);
    lv_obj_set_pos(ui->scr_dashboard_img_7, 546, 32);
    lv_obj_set_size(ui->scr_dashboard_img_7, 16, 16);
    lv_obj_add_flag(ui->scr_dashboard_img_7, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->scr_dashboard_img_7, &_mqtt_on_RGB565A8_16x16);
    lv_image_set_pivot(ui->scr_dashboard_img_7, 50,50);
    lv_image_set_rotation(ui->scr_dashboard_img_7, 0);

    //Write style for scr_dashboard_img_7, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->scr_dashboard_img_7, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_recolor(ui->scr_dashboard_img_7, lv_color_hex(0xababba), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->scr_dashboard_img_7, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_dashboard_btn_3
    ui->scr_dashboard_btn_3 = lv_button_create(ui->scr_dashboard);
    lv_obj_set_pos(ui->scr_dashboard_btn_3, 9, 109);
    lv_obj_set_size(ui->scr_dashboard_btn_3, 64, 64);
    ui->scr_dashboard_btn_3_label = lv_label_create(ui->scr_dashboard_btn_3);
    lv_label_set_text(ui->scr_dashboard_btn_3_label, "");
    lv_label_set_long_mode(ui->scr_dashboard_btn_3_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->scr_dashboard_btn_3_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->scr_dashboard_btn_3, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->scr_dashboard_btn_3_label, LV_PCT(100));

    //Write style for scr_dashboard_btn_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->scr_dashboard_btn_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->scr_dashboard_btn_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_dashboard_btn_3, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_btn_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_dashboard_btn_3, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_dashboard_btn_3, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_dashboard_btn_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_dashboard_btn_3, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for scr_dashboard_btn_3, Part: LV_PART_MAIN, State: LV_STATE_FOCUSED.
    lv_obj_set_style_bg_opa(ui->scr_dashboard_btn_3, 39, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_color(ui->scr_dashboard_btn_3, lv_color_hex(0x10B981), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_grad_dir(ui->scr_dashboard_btn_3, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_width(ui->scr_dashboard_btn_3, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_radius(ui->scr_dashboard_btn_3, 14, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_btn_3, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_color(ui->scr_dashboard_btn_3, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_font(ui->scr_dashboard_btn_3, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_opa(ui->scr_dashboard_btn_3, 255, LV_PART_MAIN|LV_STATE_FOCUSED);

    //Write style for scr_dashboard_btn_3, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_bg_opa(ui->scr_dashboard_btn_3, 40, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_bg_color(ui->scr_dashboard_btn_3, lv_color_hex(0x10B981), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_bg_grad_dir(ui->scr_dashboard_btn_3, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui->scr_dashboard_btn_3, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_radius(ui->scr_dashboard_btn_3, 14, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_btn_3, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->scr_dashboard_btn_3, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->scr_dashboard_btn_3, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->scr_dashboard_btn_3, 255, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for scr_dashboard_btn_3, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_bg_opa(ui->scr_dashboard_btn_3, 39, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui->scr_dashboard_btn_3, lv_color_hex(0x10B981), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_grad_dir(ui->scr_dashboard_btn_3, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_border_width(ui->scr_dashboard_btn_3, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_radius(ui->scr_dashboard_btn_3, 14, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_btn_3, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->scr_dashboard_btn_3, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->scr_dashboard_btn_3, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->scr_dashboard_btn_3, 255, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write codes scr_dashboard_btn_4
    ui->scr_dashboard_btn_4 = lv_button_create(ui->scr_dashboard);
    lv_obj_set_pos(ui->scr_dashboard_btn_4, 9, 181);
    lv_obj_set_size(ui->scr_dashboard_btn_4, 64, 64);
    ui->scr_dashboard_btn_4_label = lv_label_create(ui->scr_dashboard_btn_4);
    lv_label_set_text(ui->scr_dashboard_btn_4_label, "");
    lv_label_set_long_mode(ui->scr_dashboard_btn_4_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->scr_dashboard_btn_4_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->scr_dashboard_btn_4, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->scr_dashboard_btn_4_label, LV_PCT(100));

    //Write style for scr_dashboard_btn_4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->scr_dashboard_btn_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->scr_dashboard_btn_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_dashboard_btn_4, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_btn_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_dashboard_btn_4, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_dashboard_btn_4, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_dashboard_btn_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_dashboard_btn_4, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for scr_dashboard_btn_4, Part: LV_PART_MAIN, State: LV_STATE_FOCUSED.
    lv_obj_set_style_bg_opa(ui->scr_dashboard_btn_4, 39, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_color(ui->scr_dashboard_btn_4, lv_color_hex(0x10B981), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_grad_dir(ui->scr_dashboard_btn_4, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_width(ui->scr_dashboard_btn_4, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_radius(ui->scr_dashboard_btn_4, 14, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_btn_4, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_color(ui->scr_dashboard_btn_4, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_font(ui->scr_dashboard_btn_4, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_opa(ui->scr_dashboard_btn_4, 255, LV_PART_MAIN|LV_STATE_FOCUSED);

    //Write style for scr_dashboard_btn_4, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_bg_opa(ui->scr_dashboard_btn_4, 40, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_bg_color(ui->scr_dashboard_btn_4, lv_color_hex(0x10B981), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_bg_grad_dir(ui->scr_dashboard_btn_4, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui->scr_dashboard_btn_4, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_radius(ui->scr_dashboard_btn_4, 14, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_btn_4, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->scr_dashboard_btn_4, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->scr_dashboard_btn_4, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->scr_dashboard_btn_4, 255, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for scr_dashboard_btn_4, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_bg_opa(ui->scr_dashboard_btn_4, 39, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui->scr_dashboard_btn_4, lv_color_hex(0x10B981), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_grad_dir(ui->scr_dashboard_btn_4, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_border_width(ui->scr_dashboard_btn_4, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_radius(ui->scr_dashboard_btn_4, 14, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_btn_4, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->scr_dashboard_btn_4, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->scr_dashboard_btn_4, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->scr_dashboard_btn_4, 255, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write codes scr_dashboard_btn_5
    ui->scr_dashboard_btn_5 = lv_button_create(ui->scr_dashboard);
    lv_obj_set_pos(ui->scr_dashboard_btn_5, 9, 255);
    lv_obj_set_size(ui->scr_dashboard_btn_5, 64, 64);
    ui->scr_dashboard_btn_5_label = lv_label_create(ui->scr_dashboard_btn_5);
    lv_label_set_text(ui->scr_dashboard_btn_5_label, "");
    lv_label_set_long_mode(ui->scr_dashboard_btn_5_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->scr_dashboard_btn_5_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->scr_dashboard_btn_5, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->scr_dashboard_btn_5_label, LV_PCT(100));

    //Write style for scr_dashboard_btn_5, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->scr_dashboard_btn_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->scr_dashboard_btn_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_dashboard_btn_5, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_btn_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_dashboard_btn_5, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_dashboard_btn_5, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_dashboard_btn_5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_dashboard_btn_5, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for scr_dashboard_btn_5, Part: LV_PART_MAIN, State: LV_STATE_FOCUSED.
    lv_obj_set_style_bg_opa(ui->scr_dashboard_btn_5, 39, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_color(ui->scr_dashboard_btn_5, lv_color_hex(0x10B981), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_grad_dir(ui->scr_dashboard_btn_5, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_width(ui->scr_dashboard_btn_5, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_radius(ui->scr_dashboard_btn_5, 14, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_btn_5, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_color(ui->scr_dashboard_btn_5, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_font(ui->scr_dashboard_btn_5, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_opa(ui->scr_dashboard_btn_5, 255, LV_PART_MAIN|LV_STATE_FOCUSED);

    //Write style for scr_dashboard_btn_5, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_bg_opa(ui->scr_dashboard_btn_5, 40, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_bg_color(ui->scr_dashboard_btn_5, lv_color_hex(0x10B981), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_bg_grad_dir(ui->scr_dashboard_btn_5, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui->scr_dashboard_btn_5, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_radius(ui->scr_dashboard_btn_5, 14, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_btn_5, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->scr_dashboard_btn_5, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->scr_dashboard_btn_5, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->scr_dashboard_btn_5, 255, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for scr_dashboard_btn_5, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_bg_opa(ui->scr_dashboard_btn_5, 39, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui->scr_dashboard_btn_5, lv_color_hex(0x10B981), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_grad_dir(ui->scr_dashboard_btn_5, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_border_width(ui->scr_dashboard_btn_5, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_radius(ui->scr_dashboard_btn_5, 14, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_btn_5, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->scr_dashboard_btn_5, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->scr_dashboard_btn_5, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->scr_dashboard_btn_5, 255, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write codes scr_dashboard_btn_6
    ui->scr_dashboard_btn_6 = lv_button_create(ui->scr_dashboard);
    lv_obj_set_pos(ui->scr_dashboard_btn_6, 9, 325);
    lv_obj_set_size(ui->scr_dashboard_btn_6, 64, 64);
    ui->scr_dashboard_btn_6_label = lv_label_create(ui->scr_dashboard_btn_6);
    lv_label_set_text(ui->scr_dashboard_btn_6_label, "");
    lv_label_set_long_mode(ui->scr_dashboard_btn_6_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->scr_dashboard_btn_6_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->scr_dashboard_btn_6, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->scr_dashboard_btn_6_label, LV_PCT(100));

    //Write style for scr_dashboard_btn_6, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->scr_dashboard_btn_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->scr_dashboard_btn_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_dashboard_btn_6, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_btn_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_dashboard_btn_6, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_dashboard_btn_6, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_dashboard_btn_6, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_dashboard_btn_6, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for scr_dashboard_btn_6, Part: LV_PART_MAIN, State: LV_STATE_FOCUSED.
    lv_obj_set_style_bg_opa(ui->scr_dashboard_btn_6, 39, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_color(ui->scr_dashboard_btn_6, lv_color_hex(0x10B981), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_grad_dir(ui->scr_dashboard_btn_6, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_width(ui->scr_dashboard_btn_6, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_radius(ui->scr_dashboard_btn_6, 14, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_btn_6, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_color(ui->scr_dashboard_btn_6, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_font(ui->scr_dashboard_btn_6, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_opa(ui->scr_dashboard_btn_6, 255, LV_PART_MAIN|LV_STATE_FOCUSED);

    //Write style for scr_dashboard_btn_6, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_bg_opa(ui->scr_dashboard_btn_6, 40, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_bg_color(ui->scr_dashboard_btn_6, lv_color_hex(0x10B981), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_bg_grad_dir(ui->scr_dashboard_btn_6, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui->scr_dashboard_btn_6, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_radius(ui->scr_dashboard_btn_6, 14, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_btn_6, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->scr_dashboard_btn_6, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->scr_dashboard_btn_6, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->scr_dashboard_btn_6, 255, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for scr_dashboard_btn_6, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_bg_opa(ui->scr_dashboard_btn_6, 39, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui->scr_dashboard_btn_6, lv_color_hex(0x10B981), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_grad_dir(ui->scr_dashboard_btn_6, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_border_width(ui->scr_dashboard_btn_6, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_radius(ui->scr_dashboard_btn_6, 14, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_btn_6, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->scr_dashboard_btn_6, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->scr_dashboard_btn_6, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->scr_dashboard_btn_6, 255, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write codes scr_dashboard_btn_7
    ui->scr_dashboard_btn_7 = lv_button_create(ui->scr_dashboard);
    lv_obj_set_pos(ui->scr_dashboard_btn_7, 9, 393);
    lv_obj_set_size(ui->scr_dashboard_btn_7, 64, 64);
    ui->scr_dashboard_btn_7_label = lv_label_create(ui->scr_dashboard_btn_7);
    lv_label_set_text(ui->scr_dashboard_btn_7_label, "");
    lv_label_set_long_mode(ui->scr_dashboard_btn_7_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->scr_dashboard_btn_7_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->scr_dashboard_btn_7, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->scr_dashboard_btn_7_label, LV_PCT(100));

    //Write style for scr_dashboard_btn_7, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->scr_dashboard_btn_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->scr_dashboard_btn_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_dashboard_btn_7, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_btn_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_dashboard_btn_7, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_dashboard_btn_7, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_dashboard_btn_7, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_dashboard_btn_7, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for scr_dashboard_btn_7, Part: LV_PART_MAIN, State: LV_STATE_FOCUSED.
    lv_obj_set_style_bg_opa(ui->scr_dashboard_btn_7, 39, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_color(ui->scr_dashboard_btn_7, lv_color_hex(0x10B981), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_grad_dir(ui->scr_dashboard_btn_7, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_width(ui->scr_dashboard_btn_7, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_radius(ui->scr_dashboard_btn_7, 14, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_btn_7, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_color(ui->scr_dashboard_btn_7, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_font(ui->scr_dashboard_btn_7, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_opa(ui->scr_dashboard_btn_7, 255, LV_PART_MAIN|LV_STATE_FOCUSED);

    //Write style for scr_dashboard_btn_7, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_bg_opa(ui->scr_dashboard_btn_7, 40, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_bg_color(ui->scr_dashboard_btn_7, lv_color_hex(0x10B981), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_bg_grad_dir(ui->scr_dashboard_btn_7, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui->scr_dashboard_btn_7, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_radius(ui->scr_dashboard_btn_7, 14, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_btn_7, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->scr_dashboard_btn_7, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->scr_dashboard_btn_7, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->scr_dashboard_btn_7, 255, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for scr_dashboard_btn_7, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_bg_opa(ui->scr_dashboard_btn_7, 39, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui->scr_dashboard_btn_7, lv_color_hex(0x10B981), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_grad_dir(ui->scr_dashboard_btn_7, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_border_width(ui->scr_dashboard_btn_7, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_radius(ui->scr_dashboard_btn_7, 14, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->scr_dashboard_btn_7, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->scr_dashboard_btn_7, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->scr_dashboard_btn_7, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->scr_dashboard_btn_7, 255, LV_PART_MAIN|LV_STATE_CHECKED);

    //The custom code of scr_dashboard.


    //Update current screen layout.
    lv_obj_update_layout(ui->scr_dashboard);

    //Init events for screen.
    events_init_scr_dashboard(ui);
}
