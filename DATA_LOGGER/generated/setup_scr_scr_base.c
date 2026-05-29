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



int scr_base_time_val_min_value = 25;
int scr_base_time_val_hour_value = 11;
int scr_base_time_val_sec_value = 50;
void setup_scr_scr_base(lv_ui *ui)
{
    //Write codes scr_base
    ui->scr_base = lv_obj_create(NULL);
    lv_obj_set_size(ui->scr_base, 800, 480);
    lv_obj_set_scrollbar_mode(ui->scr_base, LV_SCROLLBAR_MODE_OFF);

    //Write style for scr_base, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->scr_base, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_img_bg
    ui->scr_base_img_bg = lv_image_create(ui->scr_base);
    lv_obj_set_pos(ui->scr_base_img_bg, 0, 0);
    lv_obj_set_size(ui->scr_base_img_bg, 800, 480);
    lv_obj_add_flag(ui->scr_base_img_bg, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->scr_base_img_bg, &_bg_base_RGB565_800x480);
    lv_image_set_pivot(ui->scr_base_img_bg, 50,50);
    lv_image_set_rotation(ui->scr_base_img_bg, 0);

    //Write style for scr_base_img_bg, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->scr_base_img_bg, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->scr_base_img_bg, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_btn_dashboard
    ui->scr_base_btn_dashboard = lv_button_create(ui->scr_base);
    lv_obj_set_pos(ui->scr_base_btn_dashboard, 9, 90);
    lv_obj_set_size(ui->scr_base_btn_dashboard, 64, 64);
    ui->scr_base_btn_dashboard_label = lv_label_create(ui->scr_base_btn_dashboard);
    lv_label_set_text(ui->scr_base_btn_dashboard_label, "");
    lv_label_set_long_mode(ui->scr_base_btn_dashboard_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->scr_base_btn_dashboard_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->scr_base_btn_dashboard, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->scr_base_btn_dashboard_label, LV_PCT(100));

    //Write style for scr_base_btn_dashboard, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->scr_base_btn_dashboard, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->scr_base_btn_dashboard, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_btn_dashboard, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_btn_dashboard, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_base_btn_dashboard, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_btn_dashboard, &lv_font_Roboto_Bold_15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_btn_dashboard, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_btn_dashboard, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for scr_base_btn_dashboard, Part: LV_PART_MAIN, State: LV_STATE_FOCUSED.
    lv_obj_set_style_bg_opa(ui->scr_base_btn_dashboard, 39, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_color(ui->scr_base_btn_dashboard, lv_color_hex(0x10B981), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_btn_dashboard, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_width(ui->scr_base_btn_dashboard, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_radius(ui->scr_base_btn_dashboard, 14, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_shadow_width(ui->scr_base_btn_dashboard, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_color(ui->scr_base_btn_dashboard, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_font(ui->scr_base_btn_dashboard, &lv_font_Roboto_Black_15, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_opa(ui->scr_base_btn_dashboard, 255, LV_PART_MAIN|LV_STATE_FOCUSED);

    //Write style for scr_base_btn_dashboard, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_bg_opa(ui->scr_base_btn_dashboard, 40, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_bg_color(ui->scr_base_btn_dashboard, lv_color_hex(0x10B981), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_btn_dashboard, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui->scr_base_btn_dashboard, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_radius(ui->scr_base_btn_dashboard, 14, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->scr_base_btn_dashboard, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->scr_base_btn_dashboard, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->scr_base_btn_dashboard, &lv_font_Roboto_Black_15, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->scr_base_btn_dashboard, 255, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for scr_base_btn_dashboard, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_bg_opa(ui->scr_base_btn_dashboard, 39, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui->scr_base_btn_dashboard, lv_color_hex(0x10B981), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_btn_dashboard, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_border_width(ui->scr_base_btn_dashboard, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_radius(ui->scr_base_btn_dashboard, 14, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->scr_base_btn_dashboard, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->scr_base_btn_dashboard, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->scr_base_btn_dashboard, &lv_font_Roboto_Black_15, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->scr_base_btn_dashboard, 255, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write codes scr_base_btn_analystis
    ui->scr_base_btn_analystis = lv_button_create(ui->scr_base);
    lv_obj_set_pos(ui->scr_base_btn_analystis, 9, 168);
    lv_obj_set_size(ui->scr_base_btn_analystis, 64, 64);
    ui->scr_base_btn_analystis_label = lv_label_create(ui->scr_base_btn_analystis);
    lv_label_set_text(ui->scr_base_btn_analystis_label, "");
    lv_label_set_long_mode(ui->scr_base_btn_analystis_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->scr_base_btn_analystis_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->scr_base_btn_analystis, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->scr_base_btn_analystis_label, LV_PCT(100));

    //Write style for scr_base_btn_analystis, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->scr_base_btn_analystis, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->scr_base_btn_analystis, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_btn_analystis, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_btn_analystis, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_base_btn_analystis, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_btn_analystis, &lv_font_Roboto_Black_15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_btn_analystis, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_btn_analystis, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for scr_base_btn_analystis, Part: LV_PART_MAIN, State: LV_STATE_FOCUSED.
    lv_obj_set_style_bg_opa(ui->scr_base_btn_analystis, 39, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_color(ui->scr_base_btn_analystis, lv_color_hex(0x10B981), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_btn_analystis, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_width(ui->scr_base_btn_analystis, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_radius(ui->scr_base_btn_analystis, 14, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_shadow_width(ui->scr_base_btn_analystis, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_color(ui->scr_base_btn_analystis, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_font(ui->scr_base_btn_analystis, &lv_font_Roboto_Black_15, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_opa(ui->scr_base_btn_analystis, 255, LV_PART_MAIN|LV_STATE_FOCUSED);

    //Write style for scr_base_btn_analystis, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_bg_opa(ui->scr_base_btn_analystis, 40, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_bg_color(ui->scr_base_btn_analystis, lv_color_hex(0x10B981), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_btn_analystis, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui->scr_base_btn_analystis, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_radius(ui->scr_base_btn_analystis, 14, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->scr_base_btn_analystis, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->scr_base_btn_analystis, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->scr_base_btn_analystis, &lv_font_Roboto_Black_15, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->scr_base_btn_analystis, 255, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for scr_base_btn_analystis, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_bg_opa(ui->scr_base_btn_analystis, 39, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui->scr_base_btn_analystis, lv_color_hex(0x10B981), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_btn_analystis, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_border_width(ui->scr_base_btn_analystis, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_radius(ui->scr_base_btn_analystis, 14, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->scr_base_btn_analystis, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->scr_base_btn_analystis, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->scr_base_btn_analystis, &lv_font_Roboto_Black_15, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->scr_base_btn_analystis, 255, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write style for scr_base_btn_analystis, Part: LV_PART_MAIN, State: LV_STATE_DISABLED.
    lv_obj_set_style_bg_opa(ui->scr_base_btn_analystis, 255, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_bg_color(ui->scr_base_btn_analystis, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_btn_analystis, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_border_width(ui->scr_base_btn_analystis, 0, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_radius(ui->scr_base_btn_analystis, 5, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_shadow_width(ui->scr_base_btn_analystis, 0, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_color(ui->scr_base_btn_analystis, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_font(ui->scr_base_btn_analystis, &lv_font_Roboto_Black_15, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_opa(ui->scr_base_btn_analystis, 255, LV_PART_MAIN|LV_STATE_DISABLED);

    //Write codes scr_base_btn_event_logs
    ui->scr_base_btn_event_logs = lv_button_create(ui->scr_base);
    lv_obj_set_pos(ui->scr_base_btn_event_logs, 9, 240);
    lv_obj_set_size(ui->scr_base_btn_event_logs, 64, 64);
    ui->scr_base_btn_event_logs_label = lv_label_create(ui->scr_base_btn_event_logs);
    lv_label_set_text(ui->scr_base_btn_event_logs_label, "");
    lv_label_set_long_mode(ui->scr_base_btn_event_logs_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->scr_base_btn_event_logs_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->scr_base_btn_event_logs, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->scr_base_btn_event_logs_label, LV_PCT(100));

    //Write style for scr_base_btn_event_logs, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->scr_base_btn_event_logs, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->scr_base_btn_event_logs, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_btn_event_logs, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_btn_event_logs, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_base_btn_event_logs, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_btn_event_logs, &lv_font_Roboto_Black_15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_btn_event_logs, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_btn_event_logs, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for scr_base_btn_event_logs, Part: LV_PART_MAIN, State: LV_STATE_FOCUSED.
    lv_obj_set_style_bg_opa(ui->scr_base_btn_event_logs, 39, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_color(ui->scr_base_btn_event_logs, lv_color_hex(0x10B981), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_btn_event_logs, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_width(ui->scr_base_btn_event_logs, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_radius(ui->scr_base_btn_event_logs, 14, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_shadow_width(ui->scr_base_btn_event_logs, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_color(ui->scr_base_btn_event_logs, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_font(ui->scr_base_btn_event_logs, &lv_font_Roboto_Black_15, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_opa(ui->scr_base_btn_event_logs, 255, LV_PART_MAIN|LV_STATE_FOCUSED);

    //Write style for scr_base_btn_event_logs, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_bg_opa(ui->scr_base_btn_event_logs, 40, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_bg_color(ui->scr_base_btn_event_logs, lv_color_hex(0x10B981), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_btn_event_logs, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui->scr_base_btn_event_logs, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_radius(ui->scr_base_btn_event_logs, 14, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->scr_base_btn_event_logs, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->scr_base_btn_event_logs, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->scr_base_btn_event_logs, &lv_font_Roboto_Black_15, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->scr_base_btn_event_logs, 255, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for scr_base_btn_event_logs, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_bg_opa(ui->scr_base_btn_event_logs, 39, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui->scr_base_btn_event_logs, lv_color_hex(0x10B981), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_btn_event_logs, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_border_width(ui->scr_base_btn_event_logs, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_radius(ui->scr_base_btn_event_logs, 14, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->scr_base_btn_event_logs, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->scr_base_btn_event_logs, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->scr_base_btn_event_logs, &lv_font_Roboto_Black_15, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->scr_base_btn_event_logs, 255, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write style for scr_base_btn_event_logs, Part: LV_PART_MAIN, State: LV_STATE_DISABLED.
    lv_obj_set_style_bg_opa(ui->scr_base_btn_event_logs, 255, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_bg_color(ui->scr_base_btn_event_logs, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_btn_event_logs, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_border_width(ui->scr_base_btn_event_logs, 0, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_radius(ui->scr_base_btn_event_logs, 5, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_shadow_width(ui->scr_base_btn_event_logs, 0, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_color(ui->scr_base_btn_event_logs, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_font(ui->scr_base_btn_event_logs, &lv_font_Roboto_Black_15, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_opa(ui->scr_base_btn_event_logs, 255, LV_PART_MAIN|LV_STATE_DISABLED);

    //Write codes scr_base_btn_settings
    ui->scr_base_btn_settings = lv_button_create(ui->scr_base);
    lv_obj_set_pos(ui->scr_base_btn_settings, 9, 317);
    lv_obj_set_size(ui->scr_base_btn_settings, 64, 64);
    ui->scr_base_btn_settings_label = lv_label_create(ui->scr_base_btn_settings);
    lv_label_set_text(ui->scr_base_btn_settings_label, "");
    lv_label_set_long_mode(ui->scr_base_btn_settings_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->scr_base_btn_settings_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->scr_base_btn_settings, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->scr_base_btn_settings_label, LV_PCT(100));

    //Write style for scr_base_btn_settings, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->scr_base_btn_settings, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->scr_base_btn_settings, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_btn_settings, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_btn_settings, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_base_btn_settings, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_btn_settings, &lv_font_Roboto_Black_15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_btn_settings, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_btn_settings, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for scr_base_btn_settings, Part: LV_PART_MAIN, State: LV_STATE_FOCUSED.
    lv_obj_set_style_bg_opa(ui->scr_base_btn_settings, 39, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_color(ui->scr_base_btn_settings, lv_color_hex(0x10B981), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_btn_settings, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_width(ui->scr_base_btn_settings, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_radius(ui->scr_base_btn_settings, 14, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_shadow_width(ui->scr_base_btn_settings, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_color(ui->scr_base_btn_settings, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_font(ui->scr_base_btn_settings, &lv_font_Roboto_Black_15, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_opa(ui->scr_base_btn_settings, 255, LV_PART_MAIN|LV_STATE_FOCUSED);

    //Write style for scr_base_btn_settings, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_bg_opa(ui->scr_base_btn_settings, 40, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_bg_color(ui->scr_base_btn_settings, lv_color_hex(0x10B981), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_btn_settings, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui->scr_base_btn_settings, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_radius(ui->scr_base_btn_settings, 14, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->scr_base_btn_settings, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->scr_base_btn_settings, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->scr_base_btn_settings, &lv_font_Roboto_Black_15, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->scr_base_btn_settings, 255, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for scr_base_btn_settings, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_bg_opa(ui->scr_base_btn_settings, 39, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui->scr_base_btn_settings, lv_color_hex(0x10B981), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_btn_settings, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_border_width(ui->scr_base_btn_settings, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_radius(ui->scr_base_btn_settings, 14, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->scr_base_btn_settings, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->scr_base_btn_settings, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->scr_base_btn_settings, &lv_font_Roboto_Black_15, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->scr_base_btn_settings, 255, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write style for scr_base_btn_settings, Part: LV_PART_MAIN, State: LV_STATE_DISABLED.
    lv_obj_set_style_bg_opa(ui->scr_base_btn_settings, 255, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_bg_color(ui->scr_base_btn_settings, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_btn_settings, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_border_width(ui->scr_base_btn_settings, 0, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_radius(ui->scr_base_btn_settings, 5, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_shadow_width(ui->scr_base_btn_settings, 0, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_color(ui->scr_base_btn_settings, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_font(ui->scr_base_btn_settings, &lv_font_Roboto_Black_15, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_opa(ui->scr_base_btn_settings, 255, LV_PART_MAIN|LV_STATE_DISABLED);

    //Write codes scr_base_btn_restart
    ui->scr_base_btn_restart = lv_button_create(ui->scr_base);
    lv_obj_set_pos(ui->scr_base_btn_restart, 9, 394);
    lv_obj_set_size(ui->scr_base_btn_restart, 64, 64);
    ui->scr_base_btn_restart_label = lv_label_create(ui->scr_base_btn_restart);
    lv_label_set_text(ui->scr_base_btn_restart_label, "");
    lv_label_set_long_mode(ui->scr_base_btn_restart_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->scr_base_btn_restart_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->scr_base_btn_restart, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->scr_base_btn_restart_label, LV_PCT(100));

    //Write style for scr_base_btn_restart, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->scr_base_btn_restart, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->scr_base_btn_restart, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_btn_restart, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_btn_restart, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_base_btn_restart, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_btn_restart, &lv_font_Roboto_Black_15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_btn_restart, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_btn_restart, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for scr_base_btn_restart, Part: LV_PART_MAIN, State: LV_STATE_FOCUSED.
    lv_obj_set_style_bg_opa(ui->scr_base_btn_restart, 39, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_color(ui->scr_base_btn_restart, lv_color_hex(0x10B981), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_btn_restart, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_width(ui->scr_base_btn_restart, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_radius(ui->scr_base_btn_restart, 14, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_shadow_width(ui->scr_base_btn_restart, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_color(ui->scr_base_btn_restart, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_font(ui->scr_base_btn_restart, &lv_font_Roboto_Black_15, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_opa(ui->scr_base_btn_restart, 255, LV_PART_MAIN|LV_STATE_FOCUSED);

    //Write style for scr_base_btn_restart, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_bg_opa(ui->scr_base_btn_restart, 40, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_bg_color(ui->scr_base_btn_restart, lv_color_hex(0x10B981), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_btn_restart, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui->scr_base_btn_restart, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_radius(ui->scr_base_btn_restart, 14, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->scr_base_btn_restart, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->scr_base_btn_restart, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->scr_base_btn_restart, &lv_font_Roboto_Black_15, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->scr_base_btn_restart, 255, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for scr_base_btn_restart, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_bg_opa(ui->scr_base_btn_restart, 39, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui->scr_base_btn_restart, lv_color_hex(0x10B981), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_btn_restart, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_border_width(ui->scr_base_btn_restart, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_radius(ui->scr_base_btn_restart, 14, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->scr_base_btn_restart, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->scr_base_btn_restart, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->scr_base_btn_restart, &lv_font_Roboto_Black_15, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->scr_base_btn_restart, 255, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write style for scr_base_btn_restart, Part: LV_PART_MAIN, State: LV_STATE_DISABLED.
    lv_obj_set_style_bg_opa(ui->scr_base_btn_restart, 255, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_bg_color(ui->scr_base_btn_restart, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_btn_restart, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_border_width(ui->scr_base_btn_restart, 0, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_radius(ui->scr_base_btn_restart, 5, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_shadow_width(ui->scr_base_btn_restart, 0, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_color(ui->scr_base_btn_restart, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_font(ui->scr_base_btn_restart, &lv_font_Roboto_Black_15, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_opa(ui->scr_base_btn_restart, 255, LV_PART_MAIN|LV_STATE_DISABLED);

    //Write codes scr_base_cont_dashboard
    ui->scr_base_cont_dashboard = lv_obj_create(ui->scr_base);
    lv_obj_set_pos(ui->scr_base_cont_dashboard, 101, 49);
    lv_obj_set_size(ui->scr_base_cont_dashboard, 680, 420);
    lv_obj_set_scrollbar_mode(ui->scr_base_cont_dashboard, LV_SCROLLBAR_MODE_OFF);

    //Write style for scr_base_cont_dashboard, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_cont_dashboard, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_cont_dashboard, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_cont_dashboard, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_cont_dashboard, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_cont_dashboard, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_cont_dashboard, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_cont_dashboard, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_cont_dashboard, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_lbl_dashboard
    ui->scr_base_lbl_dashboard = lv_label_create(ui->scr_base_cont_dashboard);
    lv_obj_set_pos(ui->scr_base_lbl_dashboard, 0, 15);
    lv_obj_set_size(ui->scr_base_lbl_dashboard, 220, 14);
    lv_label_set_text(ui->scr_base_lbl_dashboard, "REAL-TIME MONITORING");
    lv_label_set_long_mode(ui->scr_base_lbl_dashboard, LV_LABEL_LONG_WRAP);

    //Write style for scr_base_lbl_dashboard, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_lbl_dashboard, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_lbl_dashboard, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_base_lbl_dashboard, lv_color_hex(0x64748B), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_lbl_dashboard, &lv_font_Roboto_Black_15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_lbl_dashboard, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_base_lbl_dashboard, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_base_lbl_dashboard, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_lbl_dashboard, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_lbl_dashboard, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_lbl_dashboard, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_lbl_dashboard, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_lbl_dashboard, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_lbl_dashboard, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_lbl_dashboard, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_cont_aqi
    ui->scr_base_cont_aqi = lv_obj_create(ui->scr_base_cont_dashboard);
    lv_obj_set_pos(ui->scr_base_cont_aqi, 0, 40);
    lv_obj_set_size(ui->scr_base_cont_aqi, 230, 372);
    lv_obj_set_scrollbar_mode(ui->scr_base_cont_aqi, LV_SCROLLBAR_MODE_OFF);

    //Write style for scr_base_cont_aqi, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_cont_aqi, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scr_base_cont_aqi, 25, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scr_base_cont_aqi, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scr_base_cont_aqi, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_cont_aqi, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_cont_aqi, 244, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_base_cont_aqi, lv_color_hex(0x0F172A), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_cont_aqi, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_cont_aqi, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_cont_aqi, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_cont_aqi, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_cont_aqi, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_cont_aqi, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_lbl_aqi
    ui->scr_base_lbl_aqi = lv_label_create(ui->scr_base_cont_aqi);
    lv_obj_set_pos(ui->scr_base_lbl_aqi, 18, 30);
    lv_obj_set_size(ui->scr_base_lbl_aqi, 172, 28);
    lv_label_set_text(ui->scr_base_lbl_aqi, "AQI INDEX");
    lv_label_set_long_mode(ui->scr_base_lbl_aqi, LV_LABEL_LONG_WRAP);

    //Write style for scr_base_lbl_aqi, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_lbl_aqi, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_lbl_aqi, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_base_lbl_aqi, lv_color_hex(0x64748B), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_lbl_aqi, &lv_font_Roboto_Black_25, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_lbl_aqi, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_base_lbl_aqi, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_base_lbl_aqi, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_lbl_aqi, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_lbl_aqi, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_lbl_aqi, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_lbl_aqi, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_lbl_aqi, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_lbl_aqi, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_lbl_aqi, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_lbl_aqi_val
    ui->scr_base_lbl_aqi_val = lv_label_create(ui->scr_base_cont_aqi);
    lv_obj_set_pos(ui->scr_base_lbl_aqi_val, 4, 140);
    lv_obj_set_size(ui->scr_base_lbl_aqi_val, 221, 79);
    lv_label_set_text(ui->scr_base_lbl_aqi_val, "45");
    lv_label_set_long_mode(ui->scr_base_lbl_aqi_val, LV_LABEL_LONG_WRAP);

    //Write style for scr_base_lbl_aqi_val, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_lbl_aqi_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_lbl_aqi_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_base_lbl_aqi_val, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_lbl_aqi_val, &lv_font_Roboto_Black_72, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_lbl_aqi_val, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_base_lbl_aqi_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_base_lbl_aqi_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_lbl_aqi_val, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_lbl_aqi_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_lbl_aqi_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_lbl_aqi_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_lbl_aqi_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_lbl_aqi_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_lbl_aqi_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_arc_aqi
    ui->scr_base_arc_aqi = lv_arc_create(ui->scr_base_cont_aqi);
    lv_obj_set_pos(ui->scr_base_arc_aqi, 4, 62);
    lv_obj_set_size(ui->scr_base_arc_aqi, 220, 220);
    lv_arc_set_mode(ui->scr_base_arc_aqi, LV_ARC_MODE_NORMAL);
    lv_arc_set_range(ui->scr_base_arc_aqi, 0, 500);
    lv_arc_set_bg_angles(ui->scr_base_arc_aqi, 0, 359);
    lv_arc_set_value(ui->scr_base_arc_aqi, 45);
    lv_arc_set_rotation(ui->scr_base_arc_aqi, 270);

    //Write style for scr_base_arc_aqi, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->scr_base_arc_aqi, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->scr_base_arc_aqi, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_width(ui->scr_base_arc_aqi, 12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui->scr_base_arc_aqi, 40, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_color(ui->scr_base_arc_aqi, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_rounded(ui->scr_base_arc_aqi, true, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_arc_aqi, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_arc_aqi, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_arc_aqi, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_arc_aqi, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_arc_aqi, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_arc_aqi, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for scr_base_arc_aqi, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_arc_width(ui->scr_base_arc_aqi, 12, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui->scr_base_arc_aqi, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_color(ui->scr_base_arc_aqi, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_rounded(ui->scr_base_arc_aqi, true, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write style for scr_base_arc_aqi, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->scr_base_arc_aqi, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_base_arc_aqi, lv_color_hex(0x2195f6), LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_arc_aqi, LV_GRAD_DIR_NONE, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui->scr_base_arc_aqi, 0, LV_PART_KNOB|LV_STATE_DEFAULT);

    //Write codes scr_base_cont_aqi_status
    ui->scr_base_cont_aqi_status = lv_obj_create(ui->scr_base_cont_aqi);
    lv_obj_set_pos(ui->scr_base_cont_aqi_status, 14, 303);
    lv_obj_set_size(ui->scr_base_cont_aqi_status, 200, 55);
    lv_obj_set_scrollbar_mode(ui->scr_base_cont_aqi_status, LV_SCROLLBAR_MODE_OFF);

    //Write style for scr_base_cont_aqi_status, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_cont_aqi_status, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scr_base_cont_aqi_status, 25, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scr_base_cont_aqi_status, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scr_base_cont_aqi_status, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_cont_aqi_status, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_cont_aqi_status, 244, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_base_cont_aqi_status, lv_color_hex(0x0F172A), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_cont_aqi_status, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_cont_aqi_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_cont_aqi_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_cont_aqi_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_cont_aqi_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_cont_aqi_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_lbl_Aqi_status
    ui->scr_base_lbl_Aqi_status = lv_label_create(ui->scr_base_cont_aqi_status);
    lv_obj_set_pos(ui->scr_base_lbl_Aqi_status, 2, 1);
    lv_obj_set_size(ui->scr_base_lbl_Aqi_status, 192, 50);
    lv_label_set_text(ui->scr_base_lbl_Aqi_status, "GOOD");
    lv_label_set_long_mode(ui->scr_base_lbl_Aqi_status, LV_LABEL_LONG_WRAP);

    //Write style for scr_base_lbl_Aqi_status, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_lbl_Aqi_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_lbl_Aqi_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_base_lbl_Aqi_status, lv_color_hex(0x34D399), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_lbl_Aqi_status, &lv_font_Roboto_Black_30, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_lbl_Aqi_status, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_base_lbl_Aqi_status, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_base_lbl_Aqi_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_lbl_Aqi_status, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_lbl_Aqi_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_lbl_Aqi_status, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_lbl_Aqi_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_lbl_Aqi_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_lbl_Aqi_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_lbl_Aqi_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_cont_pm10
    ui->scr_base_cont_pm10 = lv_obj_create(ui->scr_base_cont_dashboard);
    lv_obj_set_pos(ui->scr_base_cont_pm10, 243, 40);
    lv_obj_set_size(ui->scr_base_cont_pm10, 211, 116);
    lv_obj_set_scrollbar_mode(ui->scr_base_cont_pm10, LV_SCROLLBAR_MODE_OFF);

    //Write style for scr_base_cont_pm10, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_cont_pm10, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scr_base_cont_pm10, 25, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scr_base_cont_pm10, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scr_base_cont_pm10, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_cont_pm10, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_cont_pm10, 244, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_base_cont_pm10, lv_color_hex(0x0F172A), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_cont_pm10, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_cont_pm10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_cont_pm10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_cont_pm10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_cont_pm10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_cont_pm10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_lbl_pm10
    ui->scr_base_lbl_pm10 = lv_label_create(ui->scr_base_cont_pm10);
    lv_obj_set_pos(ui->scr_base_lbl_pm10, 15, 13);
    lv_obj_set_size(ui->scr_base_lbl_pm10, 91, 24);
    lv_label_set_text(ui->scr_base_lbl_pm10, "PM 10");
    lv_label_set_long_mode(ui->scr_base_lbl_pm10, LV_LABEL_LONG_WRAP);

    //Write style for scr_base_lbl_pm10, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_lbl_pm10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_lbl_pm10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_base_lbl_pm10, lv_color_hex(0xCBD5E1), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_lbl_pm10, &lv_font_Roboto_Black_25, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_lbl_pm10, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_base_lbl_pm10, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_base_lbl_pm10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_lbl_pm10, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_lbl_pm10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_lbl_pm10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_lbl_pm10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_lbl_pm10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_lbl_pm10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_lbl_pm10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_lbl_pm10_val
    ui->scr_base_lbl_pm10_val = lv_label_create(ui->scr_base_cont_pm10);
    lv_obj_set_pos(ui->scr_base_lbl_pm10_val, 5, 52);
    lv_obj_set_size(ui->scr_base_lbl_pm10_val, 135, 44);
    lv_label_set_text(ui->scr_base_lbl_pm10_val, "12.4");
    lv_label_set_long_mode(ui->scr_base_lbl_pm10_val, LV_LABEL_LONG_WRAP);

    //Write style for scr_base_lbl_pm10_val, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_lbl_pm10_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_lbl_pm10_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_base_lbl_pm10_val, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_lbl_pm10_val, &lv_font_Roboto_Black_48, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_lbl_pm10_val, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_base_lbl_pm10_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_base_lbl_pm10_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_lbl_pm10_val, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_lbl_pm10_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_lbl_pm10_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_lbl_pm10_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_lbl_pm10_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_lbl_pm10_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_lbl_pm10_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_lbl_pm10_unit
    ui->scr_base_lbl_pm10_unit = lv_label_create(ui->scr_base_cont_pm10);
    lv_obj_set_pos(ui->scr_base_lbl_pm10_unit, 148, 72);
    lv_obj_set_size(ui->scr_base_lbl_pm10_unit, 60, 24);
    lv_label_set_text(ui->scr_base_lbl_pm10_unit, "µg/m³");
    lv_label_set_long_mode(ui->scr_base_lbl_pm10_unit, LV_LABEL_LONG_WRAP);

    //Write style for scr_base_lbl_pm10_unit, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_lbl_pm10_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_lbl_pm10_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_base_lbl_pm10_unit, lv_color_hex(0xCBD5E1), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_lbl_pm10_unit, &lv_font_Roboto_Black_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_lbl_pm10_unit, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_base_lbl_pm10_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_base_lbl_pm10_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_lbl_pm10_unit, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_lbl_pm10_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_lbl_pm10_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_lbl_pm10_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_lbl_pm10_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_lbl_pm10_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_lbl_pm10_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_img_34
    ui->scr_base_img_34 = lv_image_create(ui->scr_base_cont_pm10);
    lv_obj_set_pos(ui->scr_base_img_34, 150, 8);
    lv_obj_set_size(ui->scr_base_img_34, 40, 40);
    lv_obj_add_flag(ui->scr_base_img_34, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->scr_base_img_34, &_PM25_RGB565A8_40x40);
    lv_image_set_pivot(ui->scr_base_img_34, 50,50);
    lv_image_set_rotation(ui->scr_base_img_34, 0);

    //Write style for scr_base_img_34, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->scr_base_img_34, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->scr_base_img_34, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_cont_pm25
    ui->scr_base_cont_pm25 = lv_obj_create(ui->scr_base_cont_dashboard);
    lv_obj_set_pos(ui->scr_base_cont_pm25, 467, 40);
    lv_obj_set_size(ui->scr_base_cont_pm25, 211, 116);
    lv_obj_set_scrollbar_mode(ui->scr_base_cont_pm25, LV_SCROLLBAR_MODE_OFF);

    //Write style for scr_base_cont_pm25, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_cont_pm25, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scr_base_cont_pm25, 25, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scr_base_cont_pm25, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scr_base_cont_pm25, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_cont_pm25, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_cont_pm25, 244, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_base_cont_pm25, lv_color_hex(0x0F172A), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_cont_pm25, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_cont_pm25, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_cont_pm25, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_cont_pm25, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_cont_pm25, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_cont_pm25, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_lbl_pm25
    ui->scr_base_lbl_pm25 = lv_label_create(ui->scr_base_cont_pm25);
    lv_obj_set_pos(ui->scr_base_lbl_pm25, 15, 13);
    lv_obj_set_size(ui->scr_base_lbl_pm25, 95, 24);
    lv_label_set_text(ui->scr_base_lbl_pm25, "PM 2.5");
    lv_label_set_long_mode(ui->scr_base_lbl_pm25, LV_LABEL_LONG_WRAP);

    //Write style for scr_base_lbl_pm25, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_lbl_pm25, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_lbl_pm25, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_base_lbl_pm25, lv_color_hex(0xCBD5E1), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_lbl_pm25, &lv_font_Roboto_Black_25, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_lbl_pm25, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_base_lbl_pm25, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_base_lbl_pm25, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_lbl_pm25, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_lbl_pm25, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_lbl_pm25, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_lbl_pm25, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_lbl_pm25, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_lbl_pm25, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_lbl_pm25, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_lbl_pm25_val
    ui->scr_base_lbl_pm25_val = lv_label_create(ui->scr_base_cont_pm25);
    lv_obj_set_pos(ui->scr_base_lbl_pm25_val, 3, 52);
    lv_obj_set_size(ui->scr_base_lbl_pm25_val, 137, 44);
    lv_label_set_text(ui->scr_base_lbl_pm25_val, "12.4");
    lv_label_set_long_mode(ui->scr_base_lbl_pm25_val, LV_LABEL_LONG_WRAP);

    //Write style for scr_base_lbl_pm25_val, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_lbl_pm25_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_lbl_pm25_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_base_lbl_pm25_val, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_lbl_pm25_val, &lv_font_Roboto_Black_48, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_lbl_pm25_val, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_base_lbl_pm25_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_base_lbl_pm25_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_lbl_pm25_val, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_lbl_pm25_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_lbl_pm25_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_lbl_pm25_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_lbl_pm25_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_lbl_pm25_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_lbl_pm25_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_lbl_pm25_uint
    ui->scr_base_lbl_pm25_uint = lv_label_create(ui->scr_base_cont_pm25);
    lv_obj_set_pos(ui->scr_base_lbl_pm25_uint, 148, 72);
    lv_obj_set_size(ui->scr_base_lbl_pm25_uint, 60, 24);
    lv_label_set_text(ui->scr_base_lbl_pm25_uint, "µg/m³");
    lv_label_set_long_mode(ui->scr_base_lbl_pm25_uint, LV_LABEL_LONG_WRAP);

    //Write style for scr_base_lbl_pm25_uint, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_lbl_pm25_uint, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_lbl_pm25_uint, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_base_lbl_pm25_uint, lv_color_hex(0xCBD5E1), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_lbl_pm25_uint, &lv_font_Roboto_Black_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_lbl_pm25_uint, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_base_lbl_pm25_uint, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_base_lbl_pm25_uint, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_lbl_pm25_uint, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_lbl_pm25_uint, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_lbl_pm25_uint, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_lbl_pm25_uint, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_lbl_pm25_uint, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_lbl_pm25_uint, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_lbl_pm25_uint, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_img_35
    ui->scr_base_img_35 = lv_image_create(ui->scr_base_cont_pm25);
    lv_obj_set_pos(ui->scr_base_img_35, 147, 8);
    lv_obj_set_size(ui->scr_base_img_35, 40, 40);
    lv_obj_add_flag(ui->scr_base_img_35, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->scr_base_img_35, &_PM10_RGB565A8_40x40);
    lv_image_set_pivot(ui->scr_base_img_35, 50,50);
    lv_image_set_rotation(ui->scr_base_img_35, 0);

    //Write style for scr_base_img_35, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->scr_base_img_35, 198, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_recolor(ui->scr_base_img_35, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->scr_base_img_35, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_cont_21
    ui->scr_base_cont_21 = lv_obj_create(ui->scr_base_cont_dashboard);
    lv_obj_set_pos(ui->scr_base_cont_21, 243, 296);
    lv_obj_set_size(ui->scr_base_cont_21, 211, 116);
    lv_obj_set_scrollbar_mode(ui->scr_base_cont_21, LV_SCROLLBAR_MODE_OFF);

    //Write style for scr_base_cont_21, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_cont_21, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scr_base_cont_21, 25, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scr_base_cont_21, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scr_base_cont_21, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_cont_21, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_cont_21, 244, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_base_cont_21, lv_color_hex(0x0F172A), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_cont_21, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_cont_21, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_cont_21, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_cont_21, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_cont_21, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_cont_21, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_lbl_temp
    ui->scr_base_lbl_temp = lv_label_create(ui->scr_base_cont_21);
    lv_obj_set_pos(ui->scr_base_lbl_temp, 15, 13);
    lv_obj_set_size(ui->scr_base_lbl_temp, 81, 24);
    lv_label_set_text(ui->scr_base_lbl_temp, "TEMP");
    lv_label_set_long_mode(ui->scr_base_lbl_temp, LV_LABEL_LONG_WRAP);

    //Write style for scr_base_lbl_temp, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_lbl_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_lbl_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_base_lbl_temp, lv_color_hex(0xCBD5E1), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_lbl_temp, &lv_font_Roboto_Black_25, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_lbl_temp, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_base_lbl_temp, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_base_lbl_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_lbl_temp, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_lbl_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_lbl_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_lbl_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_lbl_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_lbl_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_lbl_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_lbl_temp_val
    ui->scr_base_lbl_temp_val = lv_label_create(ui->scr_base_cont_21);
    lv_obj_set_pos(ui->scr_base_lbl_temp_val, 3, 51);
    lv_obj_set_size(ui->scr_base_lbl_temp_val, 137, 44);
    lv_label_set_text(ui->scr_base_lbl_temp_val, "30.0");
    lv_label_set_long_mode(ui->scr_base_lbl_temp_val, LV_LABEL_LONG_WRAP);

    //Write style for scr_base_lbl_temp_val, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_lbl_temp_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_lbl_temp_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_base_lbl_temp_val, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_lbl_temp_val, &lv_font_Roboto_Black_48, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_lbl_temp_val, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_base_lbl_temp_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_base_lbl_temp_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_lbl_temp_val, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_lbl_temp_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_lbl_temp_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_lbl_temp_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_lbl_temp_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_lbl_temp_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_lbl_temp_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_lbl_temp_unit
    ui->scr_base_lbl_temp_unit = lv_label_create(ui->scr_base_cont_21);
    lv_obj_set_pos(ui->scr_base_lbl_temp_unit, 147, 72);
    lv_obj_set_size(ui->scr_base_lbl_temp_unit, 60, 24);
    lv_label_set_text(ui->scr_base_lbl_temp_unit, "°C");
    lv_label_set_long_mode(ui->scr_base_lbl_temp_unit, LV_LABEL_LONG_WRAP);

    //Write style for scr_base_lbl_temp_unit, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_lbl_temp_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_lbl_temp_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_base_lbl_temp_unit, lv_color_hex(0xCBD5E1), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_lbl_temp_unit, &lv_font_Roboto_Black_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_lbl_temp_unit, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_base_lbl_temp_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_base_lbl_temp_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_lbl_temp_unit, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_lbl_temp_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_lbl_temp_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_lbl_temp_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_lbl_temp_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_lbl_temp_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_lbl_temp_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_img_temp
    ui->scr_base_img_temp = lv_image_create(ui->scr_base_cont_21);
    lv_obj_set_pos(ui->scr_base_img_temp, 150, 15);
    lv_obj_set_size(ui->scr_base_img_temp, 32, 32);
    lv_obj_add_flag(ui->scr_base_img_temp, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->scr_base_img_temp, &_weather_RGB565A8_32x32);
    lv_image_set_pivot(ui->scr_base_img_temp, 50,50);
    lv_image_set_rotation(ui->scr_base_img_temp, 0);

    //Write style for scr_base_img_temp, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->scr_base_img_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->scr_base_img_temp, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_cont_humi
    ui->scr_base_cont_humi = lv_obj_create(ui->scr_base_cont_dashboard);
    lv_obj_set_pos(ui->scr_base_cont_humi, 467, 296);
    lv_obj_set_size(ui->scr_base_cont_humi, 211, 116);
    lv_obj_set_scrollbar_mode(ui->scr_base_cont_humi, LV_SCROLLBAR_MODE_OFF);

    //Write style for scr_base_cont_humi, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_cont_humi, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scr_base_cont_humi, 25, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scr_base_cont_humi, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scr_base_cont_humi, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_cont_humi, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_cont_humi, 244, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_base_cont_humi, lv_color_hex(0x0F172A), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_cont_humi, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_cont_humi, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_cont_humi, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_cont_humi, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_cont_humi, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_cont_humi, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_lbl_humi
    ui->scr_base_lbl_humi = lv_label_create(ui->scr_base_cont_humi);
    lv_obj_set_pos(ui->scr_base_lbl_humi, 15, 13);
    lv_obj_set_size(ui->scr_base_lbl_humi, 81, 24);
    lv_label_set_text(ui->scr_base_lbl_humi, "HUMI");
    lv_label_set_long_mode(ui->scr_base_lbl_humi, LV_LABEL_LONG_WRAP);

    //Write style for scr_base_lbl_humi, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_lbl_humi, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_lbl_humi, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_base_lbl_humi, lv_color_hex(0xCBD5E1), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_lbl_humi, &lv_font_Roboto_Black_25, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_lbl_humi, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_base_lbl_humi, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_base_lbl_humi, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_lbl_humi, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_lbl_humi, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_lbl_humi, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_lbl_humi, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_lbl_humi, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_lbl_humi, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_lbl_humi, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_lbl_humi_val
    ui->scr_base_lbl_humi_val = lv_label_create(ui->scr_base_cont_humi);
    lv_obj_set_pos(ui->scr_base_lbl_humi_val, 4, 52);
    lv_obj_set_size(ui->scr_base_lbl_humi_val, 136, 44);
    lv_label_set_text(ui->scr_base_lbl_humi_val, "70.0");
    lv_label_set_long_mode(ui->scr_base_lbl_humi_val, LV_LABEL_LONG_WRAP);

    //Write style for scr_base_lbl_humi_val, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_lbl_humi_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_lbl_humi_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_base_lbl_humi_val, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_lbl_humi_val, &lv_font_Roboto_Black_48, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_lbl_humi_val, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_base_lbl_humi_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_base_lbl_humi_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_lbl_humi_val, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_lbl_humi_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_lbl_humi_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_lbl_humi_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_lbl_humi_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_lbl_humi_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_lbl_humi_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_lbl_humi_unit
    ui->scr_base_lbl_humi_unit = lv_label_create(ui->scr_base_cont_humi);
    lv_obj_set_pos(ui->scr_base_lbl_humi_unit, 148, 72);
    lv_obj_set_size(ui->scr_base_lbl_humi_unit, 60, 24);
    lv_label_set_text(ui->scr_base_lbl_humi_unit, "%");
    lv_label_set_long_mode(ui->scr_base_lbl_humi_unit, LV_LABEL_LONG_WRAP);

    //Write style for scr_base_lbl_humi_unit, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_lbl_humi_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_lbl_humi_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_base_lbl_humi_unit, lv_color_hex(0xCBD5E1), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_lbl_humi_unit, &lv_font_Roboto_Black_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_lbl_humi_unit, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_base_lbl_humi_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_base_lbl_humi_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_lbl_humi_unit, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_lbl_humi_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_lbl_humi_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_lbl_humi_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_lbl_humi_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_lbl_humi_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_lbl_humi_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_img_humi
    ui->scr_base_img_humi = lv_image_create(ui->scr_base_cont_humi);
    lv_obj_set_pos(ui->scr_base_img_humi, 150, 15);
    lv_obj_set_size(ui->scr_base_img_humi, 32, 32);
    lv_obj_add_flag(ui->scr_base_img_humi, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->scr_base_img_humi, &_humidity_RGB565A8_32x32);
    lv_image_set_pivot(ui->scr_base_img_humi, 50,50);
    lv_image_set_rotation(ui->scr_base_img_humi, 0);

    //Write style for scr_base_img_humi, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->scr_base_img_humi, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->scr_base_img_humi, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_cont_no2
    ui->scr_base_cont_no2 = lv_obj_create(ui->scr_base_cont_dashboard);
    lv_obj_set_pos(ui->scr_base_cont_no2, 243, 168);
    lv_obj_set_size(ui->scr_base_cont_no2, 99, 116);
    lv_obj_set_scrollbar_mode(ui->scr_base_cont_no2, LV_SCROLLBAR_MODE_OFF);

    //Write style for scr_base_cont_no2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_cont_no2, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scr_base_cont_no2, 25, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scr_base_cont_no2, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scr_base_cont_no2, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_cont_no2, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_cont_no2, 244, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_base_cont_no2, lv_color_hex(0x0F172A), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_cont_no2, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_cont_no2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_cont_no2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_cont_no2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_cont_no2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_cont_no2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_lbl_no2
    ui->scr_base_lbl_no2 = lv_label_create(ui->scr_base_cont_no2);
    lv_obj_set_pos(ui->scr_base_lbl_no2, 15, 13);
    lv_obj_set_size(ui->scr_base_lbl_no2, 81, 22);
    lv_label_set_text(ui->scr_base_lbl_no2, "NO2");
    lv_label_set_long_mode(ui->scr_base_lbl_no2, LV_LABEL_LONG_WRAP);

    //Write style for scr_base_lbl_no2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_lbl_no2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_lbl_no2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_base_lbl_no2, lv_color_hex(0xCBD5E1), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_lbl_no2, &lv_font_Roboto_Black_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_lbl_no2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_base_lbl_no2, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_base_lbl_no2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_lbl_no2, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_lbl_no2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_lbl_no2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_lbl_no2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_lbl_no2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_lbl_no2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_lbl_no2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_lbl_no2_val
    ui->scr_base_lbl_no2_val = lv_label_create(ui->scr_base_cont_no2);
    lv_obj_set_pos(ui->scr_base_lbl_no2_val, 3, 45);
    lv_obj_set_size(ui->scr_base_lbl_no2_val, 93, 27);
    lv_label_set_text(ui->scr_base_lbl_no2_val, "12.4");
    lv_label_set_long_mode(ui->scr_base_lbl_no2_val, LV_LABEL_LONG_WRAP);

    //Write style for scr_base_lbl_no2_val, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_lbl_no2_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_lbl_no2_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_base_lbl_no2_val, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_lbl_no2_val, &lv_font_Roboto_Black_26, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_lbl_no2_val, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_base_lbl_no2_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_base_lbl_no2_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_lbl_no2_val, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_lbl_no2_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_lbl_no2_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_lbl_no2_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_lbl_no2_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_lbl_no2_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_lbl_no2_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_lbl_no2_unit
    ui->scr_base_lbl_no2_unit = lv_label_create(ui->scr_base_cont_no2);
    lv_obj_set_pos(ui->scr_base_lbl_no2_unit, 39, 88);
    lv_obj_set_size(ui->scr_base_lbl_no2_unit, 47, 12);
    lv_label_set_text(ui->scr_base_lbl_no2_unit, "µg/m³");
    lv_label_set_long_mode(ui->scr_base_lbl_no2_unit, LV_LABEL_LONG_WRAP);

    //Write style for scr_base_lbl_no2_unit, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_lbl_no2_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_lbl_no2_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_base_lbl_no2_unit, lv_color_hex(0xCBD5E1), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_lbl_no2_unit, &lv_font_Roboto_Black_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_lbl_no2_unit, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_base_lbl_no2_unit, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_base_lbl_no2_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_lbl_no2_unit, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_lbl_no2_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_lbl_no2_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_lbl_no2_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_lbl_no2_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_lbl_no2_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_lbl_no2_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_cont_o3
    ui->scr_base_cont_o3 = lv_obj_create(ui->scr_base_cont_dashboard);
    lv_obj_set_pos(ui->scr_base_cont_o3, 355, 168);
    lv_obj_set_size(ui->scr_base_cont_o3, 99, 116);
    lv_obj_set_scrollbar_mode(ui->scr_base_cont_o3, LV_SCROLLBAR_MODE_OFF);

    //Write style for scr_base_cont_o3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_cont_o3, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scr_base_cont_o3, 25, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scr_base_cont_o3, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scr_base_cont_o3, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_cont_o3, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_cont_o3, 244, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_base_cont_o3, lv_color_hex(0x0F172A), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_cont_o3, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_cont_o3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_cont_o3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_cont_o3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_cont_o3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_cont_o3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_lbl_o3
    ui->scr_base_lbl_o3 = lv_label_create(ui->scr_base_cont_o3);
    lv_obj_set_pos(ui->scr_base_lbl_o3, 15, 13);
    lv_obj_set_size(ui->scr_base_lbl_o3, 81, 22);
    lv_label_set_text(ui->scr_base_lbl_o3, "O3");
    lv_label_set_long_mode(ui->scr_base_lbl_o3, LV_LABEL_LONG_WRAP);

    //Write style for scr_base_lbl_o3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_lbl_o3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_lbl_o3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_base_lbl_o3, lv_color_hex(0xCBD5E1), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_lbl_o3, &lv_font_Roboto_Black_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_lbl_o3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_base_lbl_o3, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_base_lbl_o3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_lbl_o3, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_lbl_o3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_lbl_o3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_lbl_o3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_lbl_o3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_lbl_o3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_lbl_o3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_lbl_o3_val
    ui->scr_base_lbl_o3_val = lv_label_create(ui->scr_base_cont_o3);
    lv_obj_set_pos(ui->scr_base_lbl_o3_val, 2, 45);
    lv_obj_set_size(ui->scr_base_lbl_o3_val, 91, 27);
    lv_label_set_text(ui->scr_base_lbl_o3_val, "12.4");
    lv_label_set_long_mode(ui->scr_base_lbl_o3_val, LV_LABEL_LONG_WRAP);

    //Write style for scr_base_lbl_o3_val, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_lbl_o3_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_lbl_o3_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_base_lbl_o3_val, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_lbl_o3_val, &lv_font_Roboto_Black_26, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_lbl_o3_val, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_base_lbl_o3_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_base_lbl_o3_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_lbl_o3_val, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_lbl_o3_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_lbl_o3_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_lbl_o3_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_lbl_o3_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_lbl_o3_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_lbl_o3_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_lbl_o3_unit
    ui->scr_base_lbl_o3_unit = lv_label_create(ui->scr_base_cont_o3);
    lv_obj_set_pos(ui->scr_base_lbl_o3_unit, 38, 88);
    lv_obj_set_size(ui->scr_base_lbl_o3_unit, 48, 12);
    lv_label_set_text(ui->scr_base_lbl_o3_unit, "µg/m³");
    lv_label_set_long_mode(ui->scr_base_lbl_o3_unit, LV_LABEL_LONG_WRAP);

    //Write style for scr_base_lbl_o3_unit, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_lbl_o3_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_lbl_o3_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_base_lbl_o3_unit, lv_color_hex(0xCBD5E1), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_lbl_o3_unit, &lv_font_Roboto_Black_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_lbl_o3_unit, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_base_lbl_o3_unit, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_base_lbl_o3_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_lbl_o3_unit, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_lbl_o3_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_lbl_o3_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_lbl_o3_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_lbl_o3_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_lbl_o3_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_lbl_o3_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_cont_co2
    ui->scr_base_cont_co2 = lv_obj_create(ui->scr_base_cont_dashboard);
    lv_obj_set_pos(ui->scr_base_cont_co2, 467, 168);
    lv_obj_set_size(ui->scr_base_cont_co2, 99, 116);
    lv_obj_set_scrollbar_mode(ui->scr_base_cont_co2, LV_SCROLLBAR_MODE_OFF);

    //Write style for scr_base_cont_co2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_cont_co2, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scr_base_cont_co2, 25, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scr_base_cont_co2, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scr_base_cont_co2, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_cont_co2, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_cont_co2, 244, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_base_cont_co2, lv_color_hex(0x0F172A), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_cont_co2, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_cont_co2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_cont_co2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_cont_co2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_cont_co2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_cont_co2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_lbl_co
    ui->scr_base_lbl_co = lv_label_create(ui->scr_base_cont_co2);
    lv_obj_set_pos(ui->scr_base_lbl_co, 15, 13);
    lv_obj_set_size(ui->scr_base_lbl_co, 81, 21);
    lv_label_set_text(ui->scr_base_lbl_co, "CO");
    lv_label_set_long_mode(ui->scr_base_lbl_co, LV_LABEL_LONG_WRAP);

    //Write style for scr_base_lbl_co, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_lbl_co, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_lbl_co, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_base_lbl_co, lv_color_hex(0xCBD5E1), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_lbl_co, &lv_font_Roboto_Black_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_lbl_co, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_base_lbl_co, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_base_lbl_co, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_lbl_co, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_lbl_co, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_lbl_co, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_lbl_co, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_lbl_co, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_lbl_co, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_lbl_co, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_lbl_co_val
    ui->scr_base_lbl_co_val = lv_label_create(ui->scr_base_cont_co2);
    lv_obj_set_pos(ui->scr_base_lbl_co_val, 3, 45);
    lv_obj_set_size(ui->scr_base_lbl_co_val, 92, 27);
    lv_label_set_text(ui->scr_base_lbl_co_val, "12.4");
    lv_label_set_long_mode(ui->scr_base_lbl_co_val, LV_LABEL_LONG_WRAP);

    //Write style for scr_base_lbl_co_val, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_lbl_co_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_lbl_co_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_base_lbl_co_val, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_lbl_co_val, &lv_font_Roboto_Black_26, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_lbl_co_val, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_base_lbl_co_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_base_lbl_co_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_lbl_co_val, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_lbl_co_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_lbl_co_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_lbl_co_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_lbl_co_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_lbl_co_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_lbl_co_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_lbl_co_unit
    ui->scr_base_lbl_co_unit = lv_label_create(ui->scr_base_cont_co2);
    lv_obj_set_pos(ui->scr_base_lbl_co_unit, 31, 88);
    lv_obj_set_size(ui->scr_base_lbl_co_unit, 55, 12);
    lv_label_set_text(ui->scr_base_lbl_co_unit, "µg/m³");
    lv_label_set_long_mode(ui->scr_base_lbl_co_unit, LV_LABEL_LONG_WRAP);

    //Write style for scr_base_lbl_co_unit, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_lbl_co_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_lbl_co_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_base_lbl_co_unit, lv_color_hex(0xCBD5E1), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_lbl_co_unit, &lv_font_Roboto_Black_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_lbl_co_unit, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_base_lbl_co_unit, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_base_lbl_co_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_lbl_co_unit, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_lbl_co_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_lbl_co_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_lbl_co_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_lbl_co_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_lbl_co_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_lbl_co_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_cont_so2
    ui->scr_base_cont_so2 = lv_obj_create(ui->scr_base_cont_dashboard);
    lv_obj_set_pos(ui->scr_base_cont_so2, 579, 168);
    lv_obj_set_size(ui->scr_base_cont_so2, 99, 116);
    lv_obj_set_scrollbar_mode(ui->scr_base_cont_so2, LV_SCROLLBAR_MODE_OFF);

    //Write style for scr_base_cont_so2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_cont_so2, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scr_base_cont_so2, 25, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scr_base_cont_so2, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scr_base_cont_so2, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_cont_so2, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_cont_so2, 244, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_base_cont_so2, lv_color_hex(0x0F172A), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_cont_so2, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_cont_so2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_cont_so2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_cont_so2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_cont_so2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_cont_so2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_lbl_so2
    ui->scr_base_lbl_so2 = lv_label_create(ui->scr_base_cont_so2);
    lv_obj_set_pos(ui->scr_base_lbl_so2, 15, 13);
    lv_obj_set_size(ui->scr_base_lbl_so2, 81, 22);
    lv_label_set_text(ui->scr_base_lbl_so2, "SO2");
    lv_label_set_long_mode(ui->scr_base_lbl_so2, LV_LABEL_LONG_WRAP);

    //Write style for scr_base_lbl_so2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_lbl_so2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_lbl_so2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_base_lbl_so2, lv_color_hex(0xCBD5E1), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_lbl_so2, &lv_font_Roboto_Black_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_lbl_so2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_base_lbl_so2, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_base_lbl_so2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_lbl_so2, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_lbl_so2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_lbl_so2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_lbl_so2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_lbl_so2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_lbl_so2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_lbl_so2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_lbl_so2_val
    ui->scr_base_lbl_so2_val = lv_label_create(ui->scr_base_cont_so2);
    lv_obj_set_pos(ui->scr_base_lbl_so2_val, 8, 45);
    lv_obj_set_size(ui->scr_base_lbl_so2_val, 86, 27);
    lv_label_set_text(ui->scr_base_lbl_so2_val, "12.4");
    lv_label_set_long_mode(ui->scr_base_lbl_so2_val, LV_LABEL_LONG_WRAP);

    //Write style for scr_base_lbl_so2_val, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_lbl_so2_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_lbl_so2_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_base_lbl_so2_val, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_lbl_so2_val, &lv_font_Roboto_Black_26, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_lbl_so2_val, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_base_lbl_so2_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_base_lbl_so2_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_lbl_so2_val, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_lbl_so2_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_lbl_so2_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_lbl_so2_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_lbl_so2_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_lbl_so2_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_lbl_so2_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_lbl_so2_unit
    ui->scr_base_lbl_so2_unit = lv_label_create(ui->scr_base_cont_so2);
    lv_obj_set_pos(ui->scr_base_lbl_so2_unit, 40, 88);
    lv_obj_set_size(ui->scr_base_lbl_so2_unit, 46, 12);
    lv_label_set_text(ui->scr_base_lbl_so2_unit, "µg/m³");
    lv_label_set_long_mode(ui->scr_base_lbl_so2_unit, LV_LABEL_LONG_WRAP);

    //Write style for scr_base_lbl_so2_unit, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_lbl_so2_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_lbl_so2_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_base_lbl_so2_unit, lv_color_hex(0xCBD5E1), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_lbl_so2_unit, &lv_font_Roboto_Black_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_lbl_so2_unit, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_base_lbl_so2_unit, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_base_lbl_so2_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_lbl_so2_unit, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_lbl_so2_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_lbl_so2_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_lbl_so2_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_lbl_so2_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_lbl_so2_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_lbl_so2_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_cont_data_analysis
    ui->scr_base_cont_data_analysis = lv_obj_create(ui->scr_base);
    lv_obj_set_pos(ui->scr_base_cont_data_analysis, 100, 49);
    lv_obj_set_size(ui->scr_base_cont_data_analysis, 680, 420);
    lv_obj_set_scrollbar_mode(ui->scr_base_cont_data_analysis, LV_SCROLLBAR_MODE_OFF);
    lv_obj_add_flag(ui->scr_base_cont_data_analysis, LV_OBJ_FLAG_HIDDEN);

    //Write style for scr_base_cont_data_analysis, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_cont_data_analysis, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_cont_data_analysis, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_cont_data_analysis, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_cont_data_analysis, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_cont_data_analysis, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_cont_data_analysis, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_cont_data_analysis, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_cont_data_analysis, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_label_analysis
    ui->scr_base_label_analysis = lv_label_create(ui->scr_base_cont_data_analysis);
    lv_obj_set_pos(ui->scr_base_label_analysis, 0, 15);
    lv_obj_set_size(ui->scr_base_label_analysis, 236, 17);
    lv_label_set_text(ui->scr_base_label_analysis, "DATA ANALYSIS TRENDS");
    lv_label_set_long_mode(ui->scr_base_label_analysis, LV_LABEL_LONG_WRAP);

    //Write style for scr_base_label_analysis, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_label_analysis, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_label_analysis, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_base_label_analysis, lv_color_hex(0x64748B), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_label_analysis, &lv_font_Roboto_Black_15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_label_analysis, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_base_label_analysis, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_base_label_analysis, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_label_analysis, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_label_analysis, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_label_analysis, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_label_analysis, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_label_analysis, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_label_analysis, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_label_analysis, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_cont_trends
    ui->scr_base_cont_trends = lv_obj_create(ui->scr_base_cont_data_analysis);
    lv_obj_set_pos(ui->scr_base_cont_trends, 0, 37);
    lv_obj_set_size(ui->scr_base_cont_trends, 424, 372);
    lv_obj_set_scrollbar_mode(ui->scr_base_cont_trends, LV_SCROLLBAR_MODE_OFF);

    //Write style for scr_base_cont_trends, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_cont_trends, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scr_base_cont_trends, 45, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scr_base_cont_trends, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scr_base_cont_trends, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_cont_trends, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_cont_trends, 243, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_base_cont_trends, lv_color_hex(0x0F172A), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_cont_trends, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_cont_trends, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_cont_trends, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_cont_trends, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_cont_trends, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_cont_trends, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_cont_chart
    ui->scr_base_cont_chart = lv_obj_create(ui->scr_base_cont_trends);
    lv_obj_set_pos(ui->scr_base_cont_chart, 22, 53);
    lv_obj_set_size(ui->scr_base_cont_chart, 380, 300);
    lv_obj_set_scrollbar_mode(ui->scr_base_cont_chart, LV_SCROLLBAR_MODE_OFF);

    //Write style for scr_base_cont_chart, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_cont_chart, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scr_base_cont_chart, 45, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scr_base_cont_chart, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scr_base_cont_chart, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_cont_chart, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_cont_chart, 78, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_base_cont_chart, lv_color_hex(0x08143d), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_cont_chart, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_cont_chart, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_cont_chart, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_cont_chart, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_cont_chart, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_cont_chart, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_chart
    ui->scr_base_chart = lv_chart_create(ui->scr_base_cont_chart);
    lv_obj_set_pos(ui->scr_base_chart, 9, 27);
    lv_obj_set_size(ui->scr_base_chart, 355, 250);
    lv_obj_set_scrollbar_mode(ui->scr_base_chart, LV_SCROLLBAR_MODE_OFF);
    lv_chart_set_type(ui->scr_base_chart, LV_CHART_TYPE_LINE);
    lv_chart_set_div_line_count(ui->scr_base_chart, 3, 5);
    lv_chart_set_point_count(ui->scr_base_chart, 5);
    lv_chart_set_range(ui->scr_base_chart, LV_CHART_AXIS_PRIMARY_Y, 0, 500);
    lv_chart_set_range(ui->scr_base_chart, LV_CHART_AXIS_SECONDARY_Y, 0, 100);
    ui->scr_base_chart_0 = lv_chart_add_series(ui->scr_base_chart, lv_color_hex(0xffffff), LV_CHART_AXIS_PRIMARY_Y);
#if LV_USE_FREEMASTER == 0
    lv_chart_set_next_value(ui->scr_base_chart, ui->scr_base_chart_0, 1);
    lv_chart_set_next_value(ui->scr_base_chart, ui->scr_base_chart_0, 50);
    lv_chart_set_next_value(ui->scr_base_chart, ui->scr_base_chart_0, 100);
    lv_chart_set_next_value(ui->scr_base_chart, ui->scr_base_chart_0, 200);
    lv_chart_set_next_value(ui->scr_base_chart, ui->scr_base_chart_0, 50);
#endif
    ui->scr_base_chart_1 = lv_chart_add_series(ui->scr_base_chart, lv_color_hex(0x000000), LV_CHART_AXIS_PRIMARY_Y);
#if LV_USE_FREEMASTER == 0
    lv_chart_set_next_value(ui->scr_base_chart, ui->scr_base_chart_1, 100);
    lv_chart_set_next_value(ui->scr_base_chart, ui->scr_base_chart_1, 200);
    lv_chart_set_next_value(ui->scr_base_chart, ui->scr_base_chart_1, 40);
    lv_chart_set_next_value(ui->scr_base_chart, ui->scr_base_chart_1, 80);
    lv_chart_set_next_value(ui->scr_base_chart, ui->scr_base_chart_1, 300);
#endif
    ui->scr_base_chart_2 = lv_chart_add_series(ui->scr_base_chart, lv_color_hex(0x098D6B), LV_CHART_AXIS_PRIMARY_Y);
#if LV_USE_FREEMASTER == 0
    lv_chart_set_next_value(ui->scr_base_chart, ui->scr_base_chart_2, 30);
    lv_chart_set_next_value(ui->scr_base_chart, ui->scr_base_chart_2, 200);
    lv_chart_set_next_value(ui->scr_base_chart, ui->scr_base_chart_2, 300);
    lv_chart_set_next_value(ui->scr_base_chart, ui->scr_base_chart_2, 100);
    lv_chart_set_next_value(ui->scr_base_chart, ui->scr_base_chart_2, 50);
#endif

    //Write style for scr_base_chart, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->scr_base_chart, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->scr_base_chart, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scr_base_chart, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scr_base_chart, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scr_base_chart, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_chart, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_width(ui->scr_base_chart, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_color(ui->scr_base_chart, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_opa(ui->scr_base_chart, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_chart, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for scr_base_chart, Part: LV_PART_MAIN, State: LV_STATE_FOCUSED.
    lv_obj_set_style_border_width(ui->scr_base_chart, 1, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_opa(ui->scr_base_chart, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_color(ui->scr_base_chart, lv_color_hex(0xe8e8e8), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_side(ui->scr_base_chart, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_opa(ui->scr_base_chart, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_radius(ui->scr_base_chart, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_line_opa(ui->scr_base_chart, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_shadow_width(ui->scr_base_chart, 0, LV_PART_MAIN|LV_STATE_FOCUSED);

    //Write codes scr_base_label_trends
    ui->scr_base_label_trends = lv_label_create(ui->scr_base_cont_trends);
    lv_obj_set_pos(ui->scr_base_label_trends, 22, 20);
    lv_obj_set_size(ui->scr_base_label_trends, 168, 19);
    lv_label_set_text(ui->scr_base_label_trends, "TRENDS ANALYSIS");
    lv_label_set_long_mode(ui->scr_base_label_trends, LV_LABEL_LONG_WRAP);

    //Write style for scr_base_label_trends, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_label_trends, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_label_trends, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_base_label_trends, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_label_trends, &lv_font_Roboto_Black_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_label_trends, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_base_label_trends, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_base_label_trends, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_label_trends, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_label_trends, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_label_trends, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_label_trends, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_label_trends, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_label_trends, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_label_trends, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_ddlist_trends
    ui->scr_base_ddlist_trends = lv_dropdown_create(ui->scr_base_cont_trends);
    lv_obj_set_pos(ui->scr_base_ddlist_trends, 301, 7);
    lv_obj_set_size(ui->scr_base_ddlist_trends, 100, 38);
    lv_dropdown_set_options(ui->scr_base_ddlist_trends, "AQI\nPM 2.5\nPM 10");

    //Write style for scr_base_ddlist_trends, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->scr_base_ddlist_trends, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_ddlist_trends, &lv_font_Roboto_Bold_14, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_ddlist_trends, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->scr_base_ddlist_trends, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scr_base_ddlist_trends, 48, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scr_base_ddlist_trends, lv_color_hex(0xe1e6ee), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scr_base_ddlist_trends, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_ddlist_trends, 12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_ddlist_trends, 12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_ddlist_trends, 12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_ddlist_trends, 12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_ddlist_trends, 154, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_base_ddlist_trends, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_ddlist_trends, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_ddlist_trends, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for scr_base_ddlist_trends, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_text_color(ui->scr_base_ddlist_trends, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->scr_base_ddlist_trends, &lv_font_Roboto_Black_14, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->scr_base_ddlist_trends, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_border_width(ui->scr_base_ddlist_trends, 1, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_border_opa(ui->scr_base_ddlist_trends, 93, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_border_color(ui->scr_base_ddlist_trends, lv_color_hex(0xe1e6ee), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_border_side(ui->scr_base_ddlist_trends, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_pad_top(ui->scr_base_ddlist_trends, 12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_pad_left(ui->scr_base_ddlist_trends, 12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_pad_right(ui->scr_base_ddlist_trends, 12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_radius(ui->scr_base_ddlist_trends, 12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_opa(ui->scr_base_ddlist_trends, 153, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui->scr_base_ddlist_trends, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_ddlist_trends, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->scr_base_ddlist_trends, 0, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write style for scr_base_ddlist_trends, Part: LV_PART_MAIN, State: LV_STATE_FOCUSED.
    lv_obj_set_style_text_color(ui->scr_base_ddlist_trends, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_font(ui->scr_base_ddlist_trends, &lv_font_Roboto_Black_14, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_opa(ui->scr_base_ddlist_trends, 255, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_width(ui->scr_base_ddlist_trends, 1, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_opa(ui->scr_base_ddlist_trends, 57, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_color(ui->scr_base_ddlist_trends, lv_color_hex(0xe1e6ee), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_side(ui->scr_base_ddlist_trends, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_pad_top(ui->scr_base_ddlist_trends, 12, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_pad_left(ui->scr_base_ddlist_trends, 12, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_pad_right(ui->scr_base_ddlist_trends, 12, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_radius(ui->scr_base_ddlist_trends, 12, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_opa(ui->scr_base_ddlist_trends, 154, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_color(ui->scr_base_ddlist_trends, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_ddlist_trends, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_shadow_width(ui->scr_base_ddlist_trends, 0, LV_PART_MAIN|LV_STATE_FOCUSED);

    //Write style for scr_base_ddlist_trends, Part: LV_PART_MAIN, State: LV_STATE_DISABLED.
    lv_obj_set_style_text_color(ui->scr_base_ddlist_trends, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_font(ui->scr_base_ddlist_trends, &lv_font_Roboto_Black_14, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_opa(ui->scr_base_ddlist_trends, 255, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_border_width(ui->scr_base_ddlist_trends, 1, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_border_opa(ui->scr_base_ddlist_trends, 62, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_border_color(ui->scr_base_ddlist_trends, lv_color_hex(0xe1e6ee), LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_border_side(ui->scr_base_ddlist_trends, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_pad_top(ui->scr_base_ddlist_trends, 12, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_pad_left(ui->scr_base_ddlist_trends, 12, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_pad_right(ui->scr_base_ddlist_trends, 12, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_radius(ui->scr_base_ddlist_trends, 12, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_bg_opa(ui->scr_base_ddlist_trends, 154, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_bg_color(ui->scr_base_ddlist_trends, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_ddlist_trends, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_shadow_width(ui->scr_base_ddlist_trends, 0, LV_PART_MAIN|LV_STATE_DISABLED);

    //Write style state: LV_STATE_CHECKED for &style_scr_base_ddlist_trends_extra_list_selected_checked
    static lv_style_t style_scr_base_ddlist_trends_extra_list_selected_checked;
    ui_init_style(&style_scr_base_ddlist_trends_extra_list_selected_checked);

    lv_style_set_border_width(&style_scr_base_ddlist_trends_extra_list_selected_checked, 1);
    lv_style_set_border_opa(&style_scr_base_ddlist_trends_extra_list_selected_checked, 255);
    lv_style_set_border_color(&style_scr_base_ddlist_trends_extra_list_selected_checked, lv_color_hex(0x7a6363));
    lv_style_set_border_side(&style_scr_base_ddlist_trends_extra_list_selected_checked, LV_BORDER_SIDE_FULL);
    lv_style_set_radius(&style_scr_base_ddlist_trends_extra_list_selected_checked, 1);
    lv_style_set_bg_opa(&style_scr_base_ddlist_trends_extra_list_selected_checked, 113);
    lv_style_set_bg_color(&style_scr_base_ddlist_trends_extra_list_selected_checked, lv_color_hex(0x989898));
    lv_style_set_bg_grad_dir(&style_scr_base_ddlist_trends_extra_list_selected_checked, LV_GRAD_DIR_NONE);
    lv_obj_add_style(lv_dropdown_get_list(ui->scr_base_ddlist_trends), &style_scr_base_ddlist_trends_extra_list_selected_checked, LV_PART_SELECTED|LV_STATE_CHECKED);

    //Write style state: LV_STATE_DEFAULT for &style_scr_base_ddlist_trends_extra_list_main_default
    static lv_style_t style_scr_base_ddlist_trends_extra_list_main_default;
    ui_init_style(&style_scr_base_ddlist_trends_extra_list_main_default);

    lv_style_set_max_height(&style_scr_base_ddlist_trends_extra_list_main_default, 90);
    lv_style_set_text_color(&style_scr_base_ddlist_trends_extra_list_main_default, lv_color_hex(0xffffff));
    lv_style_set_text_font(&style_scr_base_ddlist_trends_extra_list_main_default, &lv_font_Roboto_Black_12);
    lv_style_set_text_opa(&style_scr_base_ddlist_trends_extra_list_main_default, 255);
    lv_style_set_border_width(&style_scr_base_ddlist_trends_extra_list_main_default, 0);
    lv_style_set_radius(&style_scr_base_ddlist_trends_extra_list_main_default, 0);
    lv_style_set_bg_opa(&style_scr_base_ddlist_trends_extra_list_main_default, 153);
    lv_style_set_bg_color(&style_scr_base_ddlist_trends_extra_list_main_default, lv_color_hex(0x000000));
    lv_style_set_bg_grad_dir(&style_scr_base_ddlist_trends_extra_list_main_default, LV_GRAD_DIR_NONE);
    lv_obj_add_style(lv_dropdown_get_list(ui->scr_base_ddlist_trends), &style_scr_base_ddlist_trends_extra_list_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_DEFAULT for &style_scr_base_ddlist_trends_extra_list_scrollbar_default
    static lv_style_t style_scr_base_ddlist_trends_extra_list_scrollbar_default;
    ui_init_style(&style_scr_base_ddlist_trends_extra_list_scrollbar_default);

    lv_style_set_radius(&style_scr_base_ddlist_trends_extra_list_scrollbar_default, 4);
    lv_style_set_bg_opa(&style_scr_base_ddlist_trends_extra_list_scrollbar_default, 113);
    lv_style_set_bg_color(&style_scr_base_ddlist_trends_extra_list_scrollbar_default, lv_color_hex(0x000000));
    lv_style_set_bg_grad_dir(&style_scr_base_ddlist_trends_extra_list_scrollbar_default, LV_GRAD_DIR_NONE);
    lv_obj_add_style(lv_dropdown_get_list(ui->scr_base_ddlist_trends), &style_scr_base_ddlist_trends_extra_list_scrollbar_default, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);

    //Write codes scr_base_cont_avg
    ui->scr_base_cont_avg = lv_obj_create(ui->scr_base_cont_data_analysis);
    lv_obj_set_pos(ui->scr_base_cont_avg, 440, 37);
    lv_obj_set_size(ui->scr_base_cont_avg, 235, 117);
    lv_obj_set_scrollbar_mode(ui->scr_base_cont_avg, LV_SCROLLBAR_MODE_OFF);

    //Write style for scr_base_cont_avg, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_cont_avg, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scr_base_cont_avg, 45, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scr_base_cont_avg, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scr_base_cont_avg, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_cont_avg, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_cont_avg, 243, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_base_cont_avg, lv_color_hex(0x0F172A), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_cont_avg, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_cont_avg, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_cont_avg, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_cont_avg, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_cont_avg, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_cont_avg, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_lbl_avg
    ui->scr_base_lbl_avg = lv_label_create(ui->scr_base_cont_avg);
    lv_obj_set_pos(ui->scr_base_lbl_avg, 20, 20);
    lv_obj_set_size(ui->scr_base_lbl_avg, 168, 19);
    lv_label_set_text(ui->scr_base_lbl_avg, "AVERAGE VALUE");
    lv_label_set_long_mode(ui->scr_base_lbl_avg, LV_LABEL_LONG_WRAP);

    //Write style for scr_base_lbl_avg, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_lbl_avg, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_lbl_avg, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_base_lbl_avg, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_lbl_avg, &lv_font_Roboto_Black_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_lbl_avg, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_base_lbl_avg, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_base_lbl_avg, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_lbl_avg, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_lbl_avg, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_lbl_avg, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_lbl_avg, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_lbl_avg, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_lbl_avg, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_lbl_avg, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_label_avg_val
    ui->scr_base_label_avg_val = lv_label_create(ui->scr_base_cont_avg);
    lv_obj_set_pos(ui->scr_base_label_avg_val, 59, 54);
    lv_obj_set_size(ui->scr_base_label_avg_val, 121, 41);
    lv_label_set_text(ui->scr_base_label_avg_val, "50.0");
    lv_label_set_long_mode(ui->scr_base_label_avg_val, LV_LABEL_LONG_WRAP);

    //Write style for scr_base_label_avg_val, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_label_avg_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_label_avg_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_base_label_avg_val, lv_color_hex(0x00ff70), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_label_avg_val, &lv_font_Roboto_Bold_40, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_label_avg_val, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_base_label_avg_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_base_label_avg_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_label_avg_val, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_label_avg_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_label_avg_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_label_avg_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_label_avg_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_label_avg_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_label_avg_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_cont_insights
    ui->scr_base_cont_insights = lv_obj_create(ui->scr_base_cont_data_analysis);
    lv_obj_set_pos(ui->scr_base_cont_insights, 440, 168);
    lv_obj_set_size(ui->scr_base_cont_insights, 235, 237);
    lv_obj_set_scrollbar_mode(ui->scr_base_cont_insights, LV_SCROLLBAR_MODE_OFF);

    //Write style for scr_base_cont_insights, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_cont_insights, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scr_base_cont_insights, 45, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scr_base_cont_insights, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scr_base_cont_insights, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_cont_insights, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_cont_insights, 243, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_base_cont_insights, lv_color_hex(0x0F172A), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_cont_insights, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_cont_insights, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_cont_insights, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_cont_insights, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_cont_insights, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_cont_insights, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_btn_generate_report
    ui->scr_base_btn_generate_report = lv_button_create(ui->scr_base_cont_insights);
    lv_obj_set_pos(ui->scr_base_btn_generate_report, 22, 175);
    lv_obj_set_size(ui->scr_base_btn_generate_report, 188, 40);
    ui->scr_base_btn_generate_report_label = lv_label_create(ui->scr_base_btn_generate_report);
    lv_label_set_text(ui->scr_base_btn_generate_report_label, "GENERATE REPORT");
    lv_label_set_long_mode(ui->scr_base_btn_generate_report_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->scr_base_btn_generate_report_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->scr_base_btn_generate_report, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->scr_base_btn_generate_report_label, LV_PCT(100));

    //Write style for scr_base_btn_generate_report, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->scr_base_btn_generate_report, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_base_btn_generate_report, lv_color_hex(0x112333), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_btn_generate_report, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->scr_base_btn_generate_report, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scr_base_btn_generate_report, 48, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scr_base_btn_generate_report, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scr_base_btn_generate_report, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_btn_generate_report, 12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_btn_generate_report, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_base_btn_generate_report, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_btn_generate_report, &lv_font_Roboto_Black_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_btn_generate_report, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_btn_generate_report, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for scr_base_btn_generate_report, Part: LV_PART_MAIN, State: LV_STATE_FOCUSED.
    lv_obj_set_style_bg_opa(ui->scr_base_btn_generate_report, 255, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_color(ui->scr_base_btn_generate_report, lv_color_hex(0x112333), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_btn_generate_report, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_width(ui->scr_base_btn_generate_report, 1, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_opa(ui->scr_base_btn_generate_report, 53, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_color(ui->scr_base_btn_generate_report, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_side(ui->scr_base_btn_generate_report, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_radius(ui->scr_base_btn_generate_report, 12, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_shadow_width(ui->scr_base_btn_generate_report, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_color(ui->scr_base_btn_generate_report, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_font(ui->scr_base_btn_generate_report, &lv_font_Roboto_Black_16, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_opa(ui->scr_base_btn_generate_report, 255, LV_PART_MAIN|LV_STATE_FOCUSED);

    //Write style for scr_base_btn_generate_report, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_bg_opa(ui->scr_base_btn_generate_report, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_bg_color(ui->scr_base_btn_generate_report, lv_color_hex(0x112333), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_btn_generate_report, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui->scr_base_btn_generate_report, 1, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_border_opa(ui->scr_base_btn_generate_report, 53, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_border_color(ui->scr_base_btn_generate_report, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_border_side(ui->scr_base_btn_generate_report, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_radius(ui->scr_base_btn_generate_report, 12, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->scr_base_btn_generate_report, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->scr_base_btn_generate_report, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->scr_base_btn_generate_report, &lv_font_Roboto_Black_16, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->scr_base_btn_generate_report, 255, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for scr_base_btn_generate_report, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_bg_opa(ui->scr_base_btn_generate_report, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui->scr_base_btn_generate_report, lv_color_hex(0x112333), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_btn_generate_report, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_border_width(ui->scr_base_btn_generate_report, 1, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_border_opa(ui->scr_base_btn_generate_report, 48, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_border_color(ui->scr_base_btn_generate_report, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_border_side(ui->scr_base_btn_generate_report, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_radius(ui->scr_base_btn_generate_report, 12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->scr_base_btn_generate_report, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->scr_base_btn_generate_report, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->scr_base_btn_generate_report, &lv_font_Roboto_Black_16, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->scr_base_btn_generate_report, 255, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write style for scr_base_btn_generate_report, Part: LV_PART_MAIN, State: LV_STATE_DISABLED.
    lv_obj_set_style_bg_opa(ui->scr_base_btn_generate_report, 255, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_bg_color(ui->scr_base_btn_generate_report, lv_color_hex(0x112333), LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_btn_generate_report, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_border_width(ui->scr_base_btn_generate_report, 1, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_border_opa(ui->scr_base_btn_generate_report, 65, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_border_color(ui->scr_base_btn_generate_report, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_border_side(ui->scr_base_btn_generate_report, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_radius(ui->scr_base_btn_generate_report, 12, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_shadow_width(ui->scr_base_btn_generate_report, 0, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_color(ui->scr_base_btn_generate_report, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_font(ui->scr_base_btn_generate_report, &lv_font_Roboto_Black_16, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_opa(ui->scr_base_btn_generate_report, 255, LV_PART_MAIN|LV_STATE_DISABLED);

    //Write codes scr_base_label_insights
    ui->scr_base_label_insights = lv_label_create(ui->scr_base_cont_insights);
    lv_obj_set_pos(ui->scr_base_label_insights, 20, 20);
    lv_obj_set_size(ui->scr_base_label_insights, 201, 19);
    lv_label_set_text(ui->scr_base_label_insights, "DIAGNOSTIC INSIGHTS");
    lv_label_set_long_mode(ui->scr_base_label_insights, LV_LABEL_LONG_WRAP);

    //Write style for scr_base_label_insights, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_label_insights, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_label_insights, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_base_label_insights, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_label_insights, &lv_font_Roboto_Black_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_label_insights, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_base_label_insights, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_base_label_insights, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_label_insights, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_label_insights, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_label_insights, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_label_insights, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_label_insights, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_label_insights, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_label_insights, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_lbl_advice
    ui->scr_base_lbl_advice = lv_label_create(ui->scr_base_cont_insights);
    lv_obj_set_pos(ui->scr_base_lbl_advice, 19, 52);
    lv_obj_set_size(ui->scr_base_lbl_advice, 188, 105);
    lv_label_set_text(ui->scr_base_lbl_advice, "COMMENT");
    lv_label_set_long_mode(ui->scr_base_lbl_advice, LV_LABEL_LONG_WRAP);

    //Write style for scr_base_lbl_advice, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_lbl_advice, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_lbl_advice, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_base_lbl_advice, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_lbl_advice, &lv_font_Roboto_Regular_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_lbl_advice, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_base_lbl_advice, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_base_lbl_advice, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_lbl_advice, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_lbl_advice, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_lbl_advice, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_lbl_advice, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_lbl_advice, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_lbl_advice, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_lbl_advice, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_cont_event_logs
    ui->scr_base_cont_event_logs = lv_obj_create(ui->scr_base);
    lv_obj_set_pos(ui->scr_base_cont_event_logs, 101, 49);
    lv_obj_set_size(ui->scr_base_cont_event_logs, 680, 420);
    lv_obj_set_scrollbar_mode(ui->scr_base_cont_event_logs, LV_SCROLLBAR_MODE_OFF);
    lv_obj_add_flag(ui->scr_base_cont_event_logs, LV_OBJ_FLAG_HIDDEN);

    //Write style for scr_base_cont_event_logs, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_cont_event_logs, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_cont_event_logs, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_cont_event_logs, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_cont_event_logs, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_cont_event_logs, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_cont_event_logs, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_cont_event_logs, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_cont_event_logs, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_lbl_event_logs
    ui->scr_base_lbl_event_logs = lv_label_create(ui->scr_base_cont_event_logs);
    lv_obj_set_pos(ui->scr_base_lbl_event_logs, 0, 15);
    lv_obj_set_size(ui->scr_base_lbl_event_logs, 254, 18);
    lv_label_set_text(ui->scr_base_lbl_event_logs, "SYSTEM ACTIVITY LOGS");
    lv_label_set_long_mode(ui->scr_base_lbl_event_logs, LV_LABEL_LONG_WRAP);

    //Write style for scr_base_lbl_event_logs, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_lbl_event_logs, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_lbl_event_logs, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_base_lbl_event_logs, lv_color_hex(0x64748B), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_lbl_event_logs, &lv_font_Roboto_Black_15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_lbl_event_logs, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_base_lbl_event_logs, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_base_lbl_event_logs, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_lbl_event_logs, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_lbl_event_logs, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_lbl_event_logs, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_lbl_event_logs, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_lbl_event_logs, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_lbl_event_logs, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_lbl_event_logs, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_cont_logs
    ui->scr_base_cont_logs = lv_obj_create(ui->scr_base_cont_event_logs);
    lv_obj_set_pos(ui->scr_base_cont_logs, 0, 35);
    lv_obj_set_size(ui->scr_base_cont_logs, 680, 368);
    lv_obj_set_scrollbar_mode(ui->scr_base_cont_logs, LV_SCROLLBAR_MODE_OFF);

    //Write style for scr_base_cont_logs, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_cont_logs, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scr_base_cont_logs, 86, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scr_base_cont_logs, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scr_base_cont_logs, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_cont_logs, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_cont_logs, 49, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_base_cont_logs, lv_color_hex(0x002b82), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_cont_logs, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_cont_logs, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_cont_logs, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_cont_logs, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_cont_logs, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_cont_logs, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_lbl_critical_logs
    ui->scr_base_lbl_critical_logs = lv_label_create(ui->scr_base_cont_logs);
    lv_obj_set_pos(ui->scr_base_lbl_critical_logs, 20, 22);
    lv_obj_set_size(ui->scr_base_lbl_critical_logs, 296, 18);
    lv_label_set_text(ui->scr_base_lbl_critical_logs, "" LV_SYMBOL_BARS "  CRITICAL INCIDENT LOGS");
    lv_label_set_long_mode(ui->scr_base_lbl_critical_logs, LV_LABEL_LONG_WRAP);

    //Write style for scr_base_lbl_critical_logs, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_lbl_critical_logs, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_lbl_critical_logs, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_base_lbl_critical_logs, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_lbl_critical_logs, &lv_font_Roboto_Black_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_lbl_critical_logs, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_base_lbl_critical_logs, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_base_lbl_critical_logs, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_lbl_critical_logs, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_lbl_critical_logs, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_lbl_critical_logs, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_lbl_critical_logs, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_lbl_critical_logs, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_lbl_critical_logs, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_lbl_critical_logs, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_btn_clear_history
    ui->scr_base_btn_clear_history = lv_button_create(ui->scr_base_cont_logs);
    lv_obj_set_pos(ui->scr_base_btn_clear_history, 510, 10);
    lv_obj_set_size(ui->scr_base_btn_clear_history, 150, 30);
    ui->scr_base_btn_clear_history_label = lv_label_create(ui->scr_base_btn_clear_history);
    lv_label_set_text(ui->scr_base_btn_clear_history_label, "CLEAR HISTORY");
    lv_label_set_long_mode(ui->scr_base_btn_clear_history_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->scr_base_btn_clear_history_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->scr_base_btn_clear_history, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->scr_base_btn_clear_history_label, LV_PCT(100));

    //Write style for scr_base_btn_clear_history, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->scr_base_btn_clear_history, 171, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_base_btn_clear_history, lv_color_hex(0xff003b), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_btn_clear_history, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->scr_base_btn_clear_history, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scr_base_btn_clear_history, 94, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scr_base_btn_clear_history, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scr_base_btn_clear_history, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_btn_clear_history, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_btn_clear_history, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_base_btn_clear_history, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_btn_clear_history, &lv_font_Roboto_Black_14, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_btn_clear_history, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_btn_clear_history, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for scr_base_btn_clear_history, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_bg_opa(ui->scr_base_btn_clear_history, 197, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui->scr_base_btn_clear_history, lv_color_hex(0xff003b), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_btn_clear_history, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_border_width(ui->scr_base_btn_clear_history, 1, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_border_opa(ui->scr_base_btn_clear_history, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_border_color(ui->scr_base_btn_clear_history, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_border_side(ui->scr_base_btn_clear_history, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_radius(ui->scr_base_btn_clear_history, 10, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->scr_base_btn_clear_history, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->scr_base_btn_clear_history, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->scr_base_btn_clear_history, &lv_font_Roboto_Black_14, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->scr_base_btn_clear_history, 255, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write codes scr_base_cont_logs_detail
    ui->scr_base_cont_logs_detail = lv_obj_create(ui->scr_base_cont_logs);
    lv_obj_set_pos(ui->scr_base_cont_logs_detail, 38, 60);
    lv_obj_set_size(ui->scr_base_cont_logs_detail, 602, 40);
    lv_obj_set_scrollbar_mode(ui->scr_base_cont_logs_detail, LV_SCROLLBAR_MODE_OFF);

    //Write style for scr_base_cont_logs_detail, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_cont_logs_detail, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scr_base_cont_logs_detail, 81, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scr_base_cont_logs_detail, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scr_base_cont_logs_detail, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_cont_logs_detail, 12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_cont_logs_detail, 131, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_base_cont_logs_detail, lv_color_hex(0x585858), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_cont_logs_detail, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_cont_logs_detail, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_cont_logs_detail, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_cont_logs_detail, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_cont_logs_detail, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_cont_logs_detail, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_lbl_log_detail
    ui->scr_base_lbl_log_detail = lv_label_create(ui->scr_base_cont_logs_detail);
    lv_obj_set_pos(ui->scr_base_lbl_log_detail, 17, 11);
    lv_obj_set_size(ui->scr_base_lbl_log_detail, 405, 15);
    lv_label_set_text(ui->scr_base_lbl_log_detail, "" LV_SYMBOL_OK "  System initizlized on promary node Synaptix");
    lv_label_set_long_mode(ui->scr_base_lbl_log_detail, LV_LABEL_LONG_WRAP);

    //Write style for scr_base_lbl_log_detail, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_lbl_log_detail, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_lbl_log_detail, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_base_lbl_log_detail, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_lbl_log_detail, &lv_font_Roboto_Bold_14, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_lbl_log_detail, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_base_lbl_log_detail, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_base_lbl_log_detail, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_lbl_log_detail, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_lbl_log_detail, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_lbl_log_detail, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_lbl_log_detail, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_lbl_log_detail, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_lbl_log_detail, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_lbl_log_detail, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_cont_hw
    ui->scr_base_cont_hw = lv_obj_create(ui->scr_base);
    lv_obj_set_pos(ui->scr_base_cont_hw, 101, 48);
    lv_obj_set_size(ui->scr_base_cont_hw, 680, 420);
    lv_obj_set_scrollbar_mode(ui->scr_base_cont_hw, LV_SCROLLBAR_MODE_OFF);
    lv_obj_add_flag(ui->scr_base_cont_hw, LV_OBJ_FLAG_HIDDEN);

    //Write style for scr_base_cont_hw, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_cont_hw, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_cont_hw, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_cont_hw, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_cont_hw, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_cont_hw, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_cont_hw, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_cont_hw, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_cont_hw, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_label_hw
    ui->scr_base_label_hw = lv_label_create(ui->scr_base_cont_hw);
    lv_obj_set_pos(ui->scr_base_label_hw, 0, 15);
    lv_obj_set_size(ui->scr_base_label_hw, 172, 17);
    lv_label_set_text(ui->scr_base_label_hw, "HARDWARE SETUP");
    lv_label_set_long_mode(ui->scr_base_label_hw, LV_LABEL_LONG_WRAP);

    //Write style for scr_base_label_hw, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_label_hw, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_label_hw, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_base_label_hw, lv_color_hex(0x64748B), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_label_hw, &lv_font_Roboto_Black_15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_label_hw, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_base_label_hw, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_base_label_hw, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_label_hw, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_label_hw, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_label_hw, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_label_hw, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_label_hw, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_label_hw, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_label_hw, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_cont_menu
    ui->scr_base_cont_menu = lv_obj_create(ui->scr_base_cont_hw);
    lv_obj_set_pos(ui->scr_base_cont_menu, 0, 35);
    lv_obj_set_size(ui->scr_base_cont_menu, 677, 374);
    lv_obj_set_scrollbar_mode(ui->scr_base_cont_menu, LV_SCROLLBAR_MODE_OFF);
    lv_obj_add_flag(ui->scr_base_cont_menu, LV_OBJ_FLAG_HIDDEN);

    //Write style for scr_base_cont_menu, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_cont_menu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_cont_menu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_cont_menu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_cont_menu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_cont_menu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_cont_menu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_cont_menu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_cont_menu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_cont_net
    ui->scr_base_cont_net = lv_obj_create(ui->scr_base_cont_menu);
    lv_obj_set_pos(ui->scr_base_cont_net, 0, 4);
    lv_obj_set_size(ui->scr_base_cont_net, 660, 80);
    lv_obj_set_scrollbar_mode(ui->scr_base_cont_net, LV_SCROLLBAR_MODE_OFF);

    //Write style for scr_base_cont_net, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_cont_net, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scr_base_cont_net, 54, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scr_base_cont_net, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scr_base_cont_net, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_cont_net, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_cont_net, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_cont_net, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_cont_net, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_cont_net, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_cont_net, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_cont_net, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_label_99
    ui->scr_base_label_99 = lv_label_create(ui->scr_base_cont_net);
    lv_obj_set_pos(ui->scr_base_label_99, 80, 21);
    lv_obj_set_size(ui->scr_base_label_99, 381, 18);
    lv_label_set_text(ui->scr_base_label_99, "NETWORK CONFIGURATION");
    lv_label_set_long_mode(ui->scr_base_label_99, LV_LABEL_LONG_WRAP);

    //Write style for scr_base_label_99, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_label_99, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_label_99, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_base_label_99, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_label_99, &lv_font_Roboto_Bold_15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_label_99, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_base_label_99, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_base_label_99, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_label_99, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_label_99, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_label_99, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_label_99, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_label_99, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_label_99, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_label_99, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_label_100
    ui->scr_base_label_100 = lv_label_create(ui->scr_base_cont_net);
    lv_obj_set_pos(ui->scr_base_label_100, 80, 46);
    lv_obj_set_size(ui->scr_base_label_100, 381, 18);
    lv_label_set_text(ui->scr_base_label_100, "LTE, WIFI & ETHERNET MANAGEMENT");
    lv_label_set_long_mode(ui->scr_base_label_100, LV_LABEL_LONG_WRAP);

    //Write style for scr_base_label_100, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_label_100, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_label_100, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_base_label_100, lv_color_hex(0xababab), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_label_100, &lv_font_Roboto_Regular_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_label_100, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_base_label_100, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_base_label_100, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_label_100, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_label_100, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_label_100, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_label_100, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_label_100, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_label_100, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_label_100, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_img_14
    ui->scr_base_img_14 = lv_image_create(ui->scr_base_cont_net);
    lv_obj_set_pos(ui->scr_base_img_14, 603, 23);
    lv_obj_set_size(ui->scr_base_img_14, 32, 32);
    lv_obj_add_flag(ui->scr_base_img_14, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->scr_base_img_14, &_next_RGB565A8_32x32);
    lv_image_set_pivot(ui->scr_base_img_14, 50,50);
    lv_image_set_rotation(ui->scr_base_img_14, 0);

    //Write style for scr_base_img_14, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->scr_base_img_14, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_recolor(ui->scr_base_img_14, lv_color_hex(0xababab), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->scr_base_img_14, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_cont_33
    ui->scr_base_cont_33 = lv_obj_create(ui->scr_base_cont_net);
    lv_obj_set_pos(ui->scr_base_cont_33, 23, 19);
    lv_obj_set_size(ui->scr_base_cont_33, 40, 40);
    lv_obj_set_scrollbar_mode(ui->scr_base_cont_33, LV_SCROLLBAR_MODE_OFF);

    //Write style for scr_base_cont_33, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_cont_33, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scr_base_cont_33, 40, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scr_base_cont_33, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scr_base_cont_33, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_cont_33, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_cont_33, 128, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_base_cont_33, lv_color_hex(0x10B981), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_cont_33, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_cont_33, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_cont_33, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_cont_33, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_cont_33, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_cont_33, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_img_27
    ui->scr_base_img_27 = lv_image_create(ui->scr_base_cont_33);
    lv_obj_set_pos(ui->scr_base_img_27, 7, 8);
    lv_obj_set_size(ui->scr_base_img_27, 24, 24);
    lv_obj_add_flag(ui->scr_base_img_27, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->scr_base_img_27, &_connection_RGB565A8_24x24);
    lv_image_set_pivot(ui->scr_base_img_27, 50,50);
    lv_image_set_rotation(ui->scr_base_img_27, 0);

    //Write style for scr_base_img_27, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->scr_base_img_27, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_recolor(ui->scr_base_img_27, lv_color_hex(0xABABAB), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->scr_base_img_27, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_btn_net
    ui->scr_base_btn_net = lv_button_create(ui->scr_base_cont_net);
    lv_obj_set_pos(ui->scr_base_btn_net, 0, 0);
    lv_obj_set_size(ui->scr_base_btn_net, 660, 80);
    ui->scr_base_btn_net_label = lv_label_create(ui->scr_base_btn_net);
    lv_label_set_text(ui->scr_base_btn_net_label, "");
    lv_label_set_long_mode(ui->scr_base_btn_net_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->scr_base_btn_net_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->scr_base_btn_net, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->scr_base_btn_net_label, LV_PCT(100));

    //Write style for scr_base_btn_net, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->scr_base_btn_net, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->scr_base_btn_net, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_btn_net, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_btn_net, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_base_btn_net, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_btn_net, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_btn_net, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_btn_net, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for scr_base_btn_net, Part: LV_PART_MAIN, State: LV_STATE_FOCUSED.
    lv_obj_set_style_bg_opa(ui->scr_base_btn_net, 43, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_color(ui->scr_base_btn_net, lv_color_hex(0x10B981), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_btn_net, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_width(ui->scr_base_btn_net, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_radius(ui->scr_base_btn_net, 20, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_shadow_width(ui->scr_base_btn_net, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_color(ui->scr_base_btn_net, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_font(ui->scr_base_btn_net, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_opa(ui->scr_base_btn_net, 255, LV_PART_MAIN|LV_STATE_FOCUSED);

    //Write style for scr_base_btn_net, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_bg_opa(ui->scr_base_btn_net, 60, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_bg_color(ui->scr_base_btn_net, lv_color_hex(0x10B981), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_btn_net, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui->scr_base_btn_net, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_radius(ui->scr_base_btn_net, 20, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->scr_base_btn_net, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->scr_base_btn_net, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->scr_base_btn_net, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->scr_base_btn_net, 255, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for scr_base_btn_net, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_bg_opa(ui->scr_base_btn_net, 58, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui->scr_base_btn_net, lv_color_hex(0x10B981), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_btn_net, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_border_width(ui->scr_base_btn_net, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_radius(ui->scr_base_btn_net, 20, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->scr_base_btn_net, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->scr_base_btn_net, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->scr_base_btn_net, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->scr_base_btn_net, 255, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write style for scr_base_btn_net, Part: LV_PART_MAIN, State: LV_STATE_DISABLED.
    lv_obj_set_style_bg_opa(ui->scr_base_btn_net, 56, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_bg_color(ui->scr_base_btn_net, lv_color_hex(0x10B981), LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_btn_net, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_border_width(ui->scr_base_btn_net, 0, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_radius(ui->scr_base_btn_net, 20, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_shadow_width(ui->scr_base_btn_net, 0, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_color(ui->scr_base_btn_net, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_font(ui->scr_base_btn_net, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_opa(ui->scr_base_btn_net, 255, LV_PART_MAIN|LV_STATE_DISABLED);

    //Write codes scr_base_cont_mqtt
    ui->scr_base_cont_mqtt = lv_obj_create(ui->scr_base_cont_menu);
    lv_obj_set_pos(ui->scr_base_cont_mqtt, 0, 94);
    lv_obj_set_size(ui->scr_base_cont_mqtt, 660, 80);
    lv_obj_set_scrollbar_mode(ui->scr_base_cont_mqtt, LV_SCROLLBAR_MODE_OFF);

    //Write style for scr_base_cont_mqtt, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_cont_mqtt, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scr_base_cont_mqtt, 54, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scr_base_cont_mqtt, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scr_base_cont_mqtt, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_cont_mqtt, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_cont_mqtt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_cont_mqtt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_cont_mqtt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_cont_mqtt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_cont_mqtt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_cont_mqtt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_label_102
    ui->scr_base_label_102 = lv_label_create(ui->scr_base_cont_mqtt);
    lv_obj_set_pos(ui->scr_base_label_102, 80, 21);
    lv_obj_set_size(ui->scr_base_label_102, 381, 18);
    lv_label_set_text(ui->scr_base_label_102, "MQTT PROTOCOL");
    lv_label_set_long_mode(ui->scr_base_label_102, LV_LABEL_LONG_WRAP);

    //Write style for scr_base_label_102, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_label_102, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_label_102, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_base_label_102, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_label_102, &lv_font_Roboto_Bold_15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_label_102, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_base_label_102, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_base_label_102, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_label_102, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_label_102, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_label_102, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_label_102, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_label_102, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_label_102, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_label_102, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_label_101
    ui->scr_base_label_101 = lv_label_create(ui->scr_base_cont_mqtt);
    lv_obj_set_pos(ui->scr_base_label_101, 80, 46);
    lv_obj_set_size(ui->scr_base_label_101, 381, 18);
    lv_label_set_text(ui->scr_base_label_101, "BROKER & AUTHENTICATION");
    lv_label_set_long_mode(ui->scr_base_label_101, LV_LABEL_LONG_WRAP);

    //Write style for scr_base_label_101, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_label_101, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_label_101, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_base_label_101, lv_color_hex(0xababab), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_label_101, &lv_font_Roboto_Regular_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_label_101, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_base_label_101, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_base_label_101, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_label_101, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_label_101, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_label_101, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_label_101, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_label_101, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_label_101, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_label_101, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_img_15
    ui->scr_base_img_15 = lv_image_create(ui->scr_base_cont_mqtt);
    lv_obj_set_pos(ui->scr_base_img_15, 603, 23);
    lv_obj_set_size(ui->scr_base_img_15, 32, 32);
    lv_obj_add_flag(ui->scr_base_img_15, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->scr_base_img_15, &_next_RGB565A8_32x32);
    lv_image_set_pivot(ui->scr_base_img_15, 50,50);
    lv_image_set_rotation(ui->scr_base_img_15, 0);

    //Write style for scr_base_img_15, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->scr_base_img_15, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_recolor(ui->scr_base_img_15, lv_color_hex(0xababab), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->scr_base_img_15, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_cont_35
    ui->scr_base_cont_35 = lv_obj_create(ui->scr_base_cont_mqtt);
    lv_obj_set_pos(ui->scr_base_cont_35, 23, 19);
    lv_obj_set_size(ui->scr_base_cont_35, 40, 40);
    lv_obj_set_scrollbar_mode(ui->scr_base_cont_35, LV_SCROLLBAR_MODE_OFF);

    //Write style for scr_base_cont_35, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_cont_35, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scr_base_cont_35, 40, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scr_base_cont_35, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scr_base_cont_35, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_cont_35, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_cont_35, 129, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_base_cont_35, lv_color_hex(0x3B82F6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_cont_35, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_cont_35, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_cont_35, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_cont_35, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_cont_35, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_cont_35, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_img_26
    ui->scr_base_img_26 = lv_image_create(ui->scr_base_cont_35);
    lv_obj_set_pos(ui->scr_base_img_26, 7, 8);
    lv_obj_set_size(ui->scr_base_img_26, 24, 24);
    lv_obj_add_flag(ui->scr_base_img_26, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->scr_base_img_26, &_computer_RGB565A8_24x24);
    lv_image_set_pivot(ui->scr_base_img_26, 50,50);
    lv_image_set_rotation(ui->scr_base_img_26, 0);

    //Write style for scr_base_img_26, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->scr_base_img_26, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_recolor(ui->scr_base_img_26, lv_color_hex(0xABABAB), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->scr_base_img_26, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_btn_mqtt
    ui->scr_base_btn_mqtt = lv_button_create(ui->scr_base_cont_mqtt);
    lv_obj_set_pos(ui->scr_base_btn_mqtt, 0, 0);
    lv_obj_set_size(ui->scr_base_btn_mqtt, 660, 80);
    ui->scr_base_btn_mqtt_label = lv_label_create(ui->scr_base_btn_mqtt);
    lv_label_set_text(ui->scr_base_btn_mqtt_label, "");
    lv_label_set_long_mode(ui->scr_base_btn_mqtt_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->scr_base_btn_mqtt_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->scr_base_btn_mqtt, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->scr_base_btn_mqtt_label, LV_PCT(100));

    //Write style for scr_base_btn_mqtt, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->scr_base_btn_mqtt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->scr_base_btn_mqtt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_btn_mqtt, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_btn_mqtt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_base_btn_mqtt, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_btn_mqtt, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_btn_mqtt, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_btn_mqtt, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for scr_base_btn_mqtt, Part: LV_PART_MAIN, State: LV_STATE_FOCUSED.
    lv_obj_set_style_bg_opa(ui->scr_base_btn_mqtt, 43, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_color(ui->scr_base_btn_mqtt, lv_color_hex(0x10B981), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_btn_mqtt, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_width(ui->scr_base_btn_mqtt, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_radius(ui->scr_base_btn_mqtt, 20, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_shadow_width(ui->scr_base_btn_mqtt, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_color(ui->scr_base_btn_mqtt, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_font(ui->scr_base_btn_mqtt, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_opa(ui->scr_base_btn_mqtt, 255, LV_PART_MAIN|LV_STATE_FOCUSED);

    //Write style for scr_base_btn_mqtt, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_bg_opa(ui->scr_base_btn_mqtt, 60, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_bg_color(ui->scr_base_btn_mqtt, lv_color_hex(0x10B981), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_btn_mqtt, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui->scr_base_btn_mqtt, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_radius(ui->scr_base_btn_mqtt, 20, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->scr_base_btn_mqtt, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->scr_base_btn_mqtt, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->scr_base_btn_mqtt, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->scr_base_btn_mqtt, 255, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for scr_base_btn_mqtt, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_bg_opa(ui->scr_base_btn_mqtt, 58, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui->scr_base_btn_mqtt, lv_color_hex(0x10B981), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_btn_mqtt, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_border_width(ui->scr_base_btn_mqtt, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_radius(ui->scr_base_btn_mqtt, 20, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->scr_base_btn_mqtt, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->scr_base_btn_mqtt, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->scr_base_btn_mqtt, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->scr_base_btn_mqtt, 255, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write style for scr_base_btn_mqtt, Part: LV_PART_MAIN, State: LV_STATE_DISABLED.
    lv_obj_set_style_bg_opa(ui->scr_base_btn_mqtt, 56, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_bg_color(ui->scr_base_btn_mqtt, lv_color_hex(0x10B981), LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_btn_mqtt, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_border_width(ui->scr_base_btn_mqtt, 0, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_radius(ui->scr_base_btn_mqtt, 20, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_shadow_width(ui->scr_base_btn_mqtt, 0, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_color(ui->scr_base_btn_mqtt, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_font(ui->scr_base_btn_mqtt, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_opa(ui->scr_base_btn_mqtt, 255, LV_PART_MAIN|LV_STATE_DISABLED);

    //Write codes scr_base_cont_modbus
    ui->scr_base_cont_modbus = lv_obj_create(ui->scr_base_cont_menu);
    lv_obj_set_pos(ui->scr_base_cont_modbus, 0, 184);
    lv_obj_set_size(ui->scr_base_cont_modbus, 660, 80);
    lv_obj_set_scrollbar_mode(ui->scr_base_cont_modbus, LV_SCROLLBAR_MODE_OFF);

    //Write style for scr_base_cont_modbus, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_cont_modbus, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scr_base_cont_modbus, 54, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scr_base_cont_modbus, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scr_base_cont_modbus, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_cont_modbus, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_cont_modbus, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_cont_modbus, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_cont_modbus, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_cont_modbus, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_cont_modbus, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_cont_modbus, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_label_104
    ui->scr_base_label_104 = lv_label_create(ui->scr_base_cont_modbus);
    lv_obj_set_pos(ui->scr_base_label_104, 80, 21);
    lv_obj_set_size(ui->scr_base_label_104, 381, 18);
    lv_label_set_text(ui->scr_base_label_104, "MODBUS RTU SETUP");
    lv_label_set_long_mode(ui->scr_base_label_104, LV_LABEL_LONG_WRAP);

    //Write style for scr_base_label_104, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_label_104, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_label_104, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_base_label_104, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_label_104, &lv_font_Roboto_Bold_15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_label_104, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_base_label_104, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_base_label_104, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_label_104, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_label_104, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_label_104, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_label_104, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_label_104, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_label_104, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_label_104, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_label_103
    ui->scr_base_label_103 = lv_label_create(ui->scr_base_cont_modbus);
    lv_obj_set_pos(ui->scr_base_label_103, 80, 46);
    lv_obj_set_size(ui->scr_base_label_103, 381, 18);
    lv_label_set_text(ui->scr_base_label_103, "SLAVE SETTINGS & BAUDRATE");
    lv_label_set_long_mode(ui->scr_base_label_103, LV_LABEL_LONG_WRAP);

    //Write style for scr_base_label_103, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_label_103, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_label_103, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_base_label_103, lv_color_hex(0xababab), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_label_103, &lv_font_Roboto_Regular_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_label_103, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_base_label_103, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_base_label_103, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_label_103, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_label_103, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_label_103, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_label_103, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_label_103, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_label_103, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_label_103, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_img_16
    ui->scr_base_img_16 = lv_image_create(ui->scr_base_cont_modbus);
    lv_obj_set_pos(ui->scr_base_img_16, 603, 23);
    lv_obj_set_size(ui->scr_base_img_16, 32, 32);
    lv_obj_add_flag(ui->scr_base_img_16, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->scr_base_img_16, &_next_RGB565A8_32x32);
    lv_image_set_pivot(ui->scr_base_img_16, 50,50);
    lv_image_set_rotation(ui->scr_base_img_16, 0);

    //Write style for scr_base_img_16, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->scr_base_img_16, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_recolor(ui->scr_base_img_16, lv_color_hex(0xababab), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->scr_base_img_16, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_cont_37
    ui->scr_base_cont_37 = lv_obj_create(ui->scr_base_cont_modbus);
    lv_obj_set_pos(ui->scr_base_cont_37, 23, 19);
    lv_obj_set_size(ui->scr_base_cont_37, 40, 40);
    lv_obj_set_scrollbar_mode(ui->scr_base_cont_37, LV_SCROLLBAR_MODE_OFF);

    //Write style for scr_base_cont_37, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_cont_37, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scr_base_cont_37, 40, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scr_base_cont_37, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scr_base_cont_37, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_cont_37, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_cont_37, 128, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_base_cont_37, lv_color_hex(0xF59E0B), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_cont_37, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_cont_37, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_cont_37, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_cont_37, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_cont_37, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_cont_37, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_img_25
    ui->scr_base_img_25 = lv_image_create(ui->scr_base_cont_37);
    lv_obj_set_pos(ui->scr_base_img_25, 7, 8);
    lv_obj_set_size(ui->scr_base_img_25, 24, 24);
    lv_obj_add_flag(ui->scr_base_img_25, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->scr_base_img_25, &_communicative_RGB565A8_24x24);
    lv_image_set_pivot(ui->scr_base_img_25, 50,50);
    lv_image_set_rotation(ui->scr_base_img_25, 0);

    //Write style for scr_base_img_25, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->scr_base_img_25, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_recolor(ui->scr_base_img_25, lv_color_hex(0xABABAB), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->scr_base_img_25, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_btn_modbus
    ui->scr_base_btn_modbus = lv_button_create(ui->scr_base_cont_modbus);
    lv_obj_set_pos(ui->scr_base_btn_modbus, 0, 0);
    lv_obj_set_size(ui->scr_base_btn_modbus, 660, 80);
    ui->scr_base_btn_modbus_label = lv_label_create(ui->scr_base_btn_modbus);
    lv_label_set_text(ui->scr_base_btn_modbus_label, "");
    lv_label_set_long_mode(ui->scr_base_btn_modbus_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->scr_base_btn_modbus_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->scr_base_btn_modbus, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->scr_base_btn_modbus_label, LV_PCT(100));

    //Write style for scr_base_btn_modbus, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->scr_base_btn_modbus, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->scr_base_btn_modbus, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_btn_modbus, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_btn_modbus, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_base_btn_modbus, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_btn_modbus, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_btn_modbus, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_btn_modbus, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for scr_base_btn_modbus, Part: LV_PART_MAIN, State: LV_STATE_FOCUSED.
    lv_obj_set_style_bg_opa(ui->scr_base_btn_modbus, 43, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_color(ui->scr_base_btn_modbus, lv_color_hex(0x10B981), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_btn_modbus, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_width(ui->scr_base_btn_modbus, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_radius(ui->scr_base_btn_modbus, 20, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_shadow_width(ui->scr_base_btn_modbus, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_color(ui->scr_base_btn_modbus, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_font(ui->scr_base_btn_modbus, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_opa(ui->scr_base_btn_modbus, 255, LV_PART_MAIN|LV_STATE_FOCUSED);

    //Write style for scr_base_btn_modbus, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_bg_opa(ui->scr_base_btn_modbus, 60, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_bg_color(ui->scr_base_btn_modbus, lv_color_hex(0x10B981), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_btn_modbus, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui->scr_base_btn_modbus, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_radius(ui->scr_base_btn_modbus, 20, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->scr_base_btn_modbus, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->scr_base_btn_modbus, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->scr_base_btn_modbus, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->scr_base_btn_modbus, 255, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for scr_base_btn_modbus, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_bg_opa(ui->scr_base_btn_modbus, 58, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui->scr_base_btn_modbus, lv_color_hex(0x10B981), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_btn_modbus, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_border_width(ui->scr_base_btn_modbus, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_radius(ui->scr_base_btn_modbus, 20, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->scr_base_btn_modbus, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->scr_base_btn_modbus, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->scr_base_btn_modbus, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->scr_base_btn_modbus, 255, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write style for scr_base_btn_modbus, Part: LV_PART_MAIN, State: LV_STATE_DISABLED.
    lv_obj_set_style_bg_opa(ui->scr_base_btn_modbus, 56, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_bg_color(ui->scr_base_btn_modbus, lv_color_hex(0x10B981), LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_btn_modbus, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_border_width(ui->scr_base_btn_modbus, 0, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_radius(ui->scr_base_btn_modbus, 20, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_shadow_width(ui->scr_base_btn_modbus, 0, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_color(ui->scr_base_btn_modbus, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_font(ui->scr_base_btn_modbus, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_opa(ui->scr_base_btn_modbus, 255, LV_PART_MAIN|LV_STATE_DISABLED);

    //Write codes scr_base_cont_sys_admin
    ui->scr_base_cont_sys_admin = lv_obj_create(ui->scr_base_cont_menu);
    lv_obj_set_pos(ui->scr_base_cont_sys_admin, 0, 274);
    lv_obj_set_size(ui->scr_base_cont_sys_admin, 660, 80);
    lv_obj_set_scrollbar_mode(ui->scr_base_cont_sys_admin, LV_SCROLLBAR_MODE_OFF);

    //Write style for scr_base_cont_sys_admin, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_cont_sys_admin, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scr_base_cont_sys_admin, 54, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scr_base_cont_sys_admin, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scr_base_cont_sys_admin, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_cont_sys_admin, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_cont_sys_admin, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_cont_sys_admin, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_cont_sys_admin, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_cont_sys_admin, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_cont_sys_admin, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_cont_sys_admin, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_label_106
    ui->scr_base_label_106 = lv_label_create(ui->scr_base_cont_sys_admin);
    lv_obj_set_pos(ui->scr_base_label_106, 80, 21);
    lv_obj_set_size(ui->scr_base_label_106, 381, 18);
    lv_label_set_text(ui->scr_base_label_106, "SYSTEM ADMINISTRATION");
    lv_label_set_long_mode(ui->scr_base_label_106, LV_LABEL_LONG_WRAP);

    //Write style for scr_base_label_106, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_label_106, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_label_106, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_base_label_106, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_label_106, &lv_font_Roboto_Bold_15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_label_106, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_base_label_106, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_base_label_106, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_label_106, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_label_106, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_label_106, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_label_106, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_label_106, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_label_106, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_label_106, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_label_105
    ui->scr_base_label_105 = lv_label_create(ui->scr_base_cont_sys_admin);
    lv_obj_set_pos(ui->scr_base_label_105, 80, 46);
    lv_obj_set_size(ui->scr_base_label_105, 381, 18);
    lv_label_set_text(ui->scr_base_label_105, "MAINTENANCE, UI & INFIRMATION");
    lv_label_set_long_mode(ui->scr_base_label_105, LV_LABEL_LONG_WRAP);

    //Write style for scr_base_label_105, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_label_105, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_label_105, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_base_label_105, lv_color_hex(0xababab), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_label_105, &lv_font_Roboto_Regular_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_label_105, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_base_label_105, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_base_label_105, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_label_105, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_label_105, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_label_105, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_label_105, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_label_105, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_label_105, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_label_105, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_img_17
    ui->scr_base_img_17 = lv_image_create(ui->scr_base_cont_sys_admin);
    lv_obj_set_pos(ui->scr_base_img_17, 603, 23);
    lv_obj_set_size(ui->scr_base_img_17, 32, 32);
    lv_obj_add_flag(ui->scr_base_img_17, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->scr_base_img_17, &_next_RGB565A8_32x32);
    lv_image_set_pivot(ui->scr_base_img_17, 50,50);
    lv_image_set_rotation(ui->scr_base_img_17, 0);

    //Write style for scr_base_img_17, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->scr_base_img_17, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_recolor(ui->scr_base_img_17, lv_color_hex(0xababab), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->scr_base_img_17, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_cont_39
    ui->scr_base_cont_39 = lv_obj_create(ui->scr_base_cont_sys_admin);
    lv_obj_set_pos(ui->scr_base_cont_39, 23, 19);
    lv_obj_set_size(ui->scr_base_cont_39, 40, 40);
    lv_obj_set_scrollbar_mode(ui->scr_base_cont_39, LV_SCROLLBAR_MODE_OFF);

    //Write style for scr_base_cont_39, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_cont_39, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scr_base_cont_39, 40, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scr_base_cont_39, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scr_base_cont_39, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_cont_39, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_cont_39, 129, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_base_cont_39, lv_color_hex(0xA855F7), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_cont_39, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_cont_39, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_cont_39, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_cont_39, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_cont_39, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_cont_39, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_img_24
    ui->scr_base_img_24 = lv_image_create(ui->scr_base_cont_39);
    lv_obj_set_pos(ui->scr_base_img_24, 7, 7);
    lv_obj_set_size(ui->scr_base_img_24, 24, 24);
    lv_obj_add_flag(ui->scr_base_img_24, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->scr_base_img_24, &_system_update_RGB565A8_24x24);
    lv_image_set_pivot(ui->scr_base_img_24, 50,50);
    lv_image_set_rotation(ui->scr_base_img_24, 0);

    //Write style for scr_base_img_24, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->scr_base_img_24, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_recolor(ui->scr_base_img_24, lv_color_hex(0xABABAB), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->scr_base_img_24, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_btn_sys_admin
    ui->scr_base_btn_sys_admin = lv_button_create(ui->scr_base_cont_sys_admin);
    lv_obj_set_pos(ui->scr_base_btn_sys_admin, 0, 0);
    lv_obj_set_size(ui->scr_base_btn_sys_admin, 660, 80);
    ui->scr_base_btn_sys_admin_label = lv_label_create(ui->scr_base_btn_sys_admin);
    lv_label_set_text(ui->scr_base_btn_sys_admin_label, "");
    lv_label_set_long_mode(ui->scr_base_btn_sys_admin_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->scr_base_btn_sys_admin_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->scr_base_btn_sys_admin, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->scr_base_btn_sys_admin_label, LV_PCT(100));

    //Write style for scr_base_btn_sys_admin, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->scr_base_btn_sys_admin, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->scr_base_btn_sys_admin, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_btn_sys_admin, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_btn_sys_admin, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_base_btn_sys_admin, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_btn_sys_admin, &lv_font_Roboto_Black_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_btn_sys_admin, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_btn_sys_admin, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for scr_base_btn_sys_admin, Part: LV_PART_MAIN, State: LV_STATE_FOCUSED.
    lv_obj_set_style_bg_opa(ui->scr_base_btn_sys_admin, 43, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_color(ui->scr_base_btn_sys_admin, lv_color_hex(0x10B981), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_btn_sys_admin, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_width(ui->scr_base_btn_sys_admin, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_radius(ui->scr_base_btn_sys_admin, 20, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_shadow_width(ui->scr_base_btn_sys_admin, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_color(ui->scr_base_btn_sys_admin, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_font(ui->scr_base_btn_sys_admin, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_opa(ui->scr_base_btn_sys_admin, 255, LV_PART_MAIN|LV_STATE_FOCUSED);

    //Write style for scr_base_btn_sys_admin, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_bg_opa(ui->scr_base_btn_sys_admin, 60, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_bg_color(ui->scr_base_btn_sys_admin, lv_color_hex(0x10B981), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_btn_sys_admin, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui->scr_base_btn_sys_admin, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_radius(ui->scr_base_btn_sys_admin, 20, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->scr_base_btn_sys_admin, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->scr_base_btn_sys_admin, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->scr_base_btn_sys_admin, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->scr_base_btn_sys_admin, 255, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for scr_base_btn_sys_admin, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_bg_opa(ui->scr_base_btn_sys_admin, 58, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui->scr_base_btn_sys_admin, lv_color_hex(0x10B981), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_btn_sys_admin, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_border_width(ui->scr_base_btn_sys_admin, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_radius(ui->scr_base_btn_sys_admin, 20, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->scr_base_btn_sys_admin, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->scr_base_btn_sys_admin, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->scr_base_btn_sys_admin, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->scr_base_btn_sys_admin, 255, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write style for scr_base_btn_sys_admin, Part: LV_PART_MAIN, State: LV_STATE_DISABLED.
    lv_obj_set_style_bg_opa(ui->scr_base_btn_sys_admin, 56, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_bg_color(ui->scr_base_btn_sys_admin, lv_color_hex(0x10B981), LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_btn_sys_admin, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_border_width(ui->scr_base_btn_sys_admin, 0, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_radius(ui->scr_base_btn_sys_admin, 20, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_shadow_width(ui->scr_base_btn_sys_admin, 0, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_color(ui->scr_base_btn_sys_admin, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_font(ui->scr_base_btn_sys_admin, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_opa(ui->scr_base_btn_sys_admin, 255, LV_PART_MAIN|LV_STATE_DISABLED);

    //Write codes scr_base_cont_networkconfig
    ui->scr_base_cont_networkconfig = lv_obj_create(ui->scr_base_cont_hw);
    lv_obj_set_pos(ui->scr_base_cont_networkconfig, 0, 35);
    lv_obj_set_size(ui->scr_base_cont_networkconfig, 677, 380);
    lv_obj_set_scrollbar_mode(ui->scr_base_cont_networkconfig, LV_SCROLLBAR_MODE_OFF);

    //Write style for scr_base_cont_networkconfig, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_cont_networkconfig, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_cont_networkconfig, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_cont_networkconfig, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_cont_networkconfig, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_cont_networkconfig, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_cont_networkconfig, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_cont_networkconfig, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_cont_networkconfig, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_cont_net_back
    ui->scr_base_cont_net_back = lv_obj_create(ui->scr_base_cont_networkconfig);
    lv_obj_set_pos(ui->scr_base_cont_net_back, 0, 5);
    lv_obj_set_size(ui->scr_base_cont_net_back, 40, 40);
    lv_obj_set_scrollbar_mode(ui->scr_base_cont_net_back, LV_SCROLLBAR_MODE_OFF);

    //Write style for scr_base_cont_net_back, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_cont_net_back, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scr_base_cont_net_back, 71, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scr_base_cont_net_back, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scr_base_cont_net_back, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_cont_net_back, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_cont_net_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_cont_net_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_cont_net_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_cont_net_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_cont_net_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_cont_net_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_img_18
    ui->scr_base_img_18 = lv_image_create(ui->scr_base_cont_net_back);
    lv_obj_set_pos(ui->scr_base_img_18, 7, 7);
    lv_obj_set_size(ui->scr_base_img_18, 24, 24);
    lv_obj_add_flag(ui->scr_base_img_18, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->scr_base_img_18, &_left_arrow_RGB565A8_24x24);
    lv_image_set_pivot(ui->scr_base_img_18, 50,50);
    lv_image_set_rotation(ui->scr_base_img_18, 0);

    //Write style for scr_base_img_18, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->scr_base_img_18, 189, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_recolor(ui->scr_base_img_18, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->scr_base_img_18, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_btn_net_back
    ui->scr_base_btn_net_back = lv_button_create(ui->scr_base_cont_net_back);
    lv_obj_set_pos(ui->scr_base_btn_net_back, -6, -6);
    lv_obj_set_size(ui->scr_base_btn_net_back, 50, 50);
    ui->scr_base_btn_net_back_label = lv_label_create(ui->scr_base_btn_net_back);
    lv_label_set_text(ui->scr_base_btn_net_back_label, "");
    lv_label_set_long_mode(ui->scr_base_btn_net_back_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->scr_base_btn_net_back_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->scr_base_btn_net_back, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->scr_base_btn_net_back_label, LV_PCT(100));

    //Write style for scr_base_btn_net_back, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->scr_base_btn_net_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->scr_base_btn_net_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_btn_net_back, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_btn_net_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_base_btn_net_back, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_btn_net_back, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_btn_net_back, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_btn_net_back, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for scr_base_btn_net_back, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_bg_opa(ui->scr_base_btn_net_back, 42, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_bg_color(ui->scr_base_btn_net_back, lv_color_hex(0x10B981), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_btn_net_back, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui->scr_base_btn_net_back, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_radius(ui->scr_base_btn_net_back, 10, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->scr_base_btn_net_back, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->scr_base_btn_net_back, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->scr_base_btn_net_back, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->scr_base_btn_net_back, 255, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for scr_base_btn_net_back, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_bg_opa(ui->scr_base_btn_net_back, 44, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui->scr_base_btn_net_back, lv_color_hex(0x10B981), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_btn_net_back, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_border_width(ui->scr_base_btn_net_back, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_radius(ui->scr_base_btn_net_back, 10, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->scr_base_btn_net_back, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->scr_base_btn_net_back, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->scr_base_btn_net_back, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->scr_base_btn_net_back, 255, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write codes scr_base_label_107
    ui->scr_base_label_107 = lv_label_create(ui->scr_base_cont_networkconfig);
    lv_obj_set_pos(ui->scr_base_label_107, 44, 18);
    lv_obj_set_size(ui->scr_base_label_107, 227, 17);
    lv_label_set_text(ui->scr_base_label_107, "NETWORK CONFIGURATION");
    lv_label_set_long_mode(ui->scr_base_label_107, LV_LABEL_LONG_WRAP);

    //Write style for scr_base_label_107, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_label_107, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_label_107, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_base_label_107, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_label_107, &lv_font_Roboto_Bold_15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_label_107, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_base_label_107, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_base_label_107, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_label_107, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_label_107, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_label_107, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_label_107, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_label_107, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_label_107, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_label_107, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_ddlist_net_option
    ui->scr_base_ddlist_net_option = lv_dropdown_create(ui->scr_base_cont_networkconfig);
    lv_obj_set_pos(ui->scr_base_ddlist_net_option, 520, 0);
    lv_obj_set_size(ui->scr_base_ddlist_net_option, 140, 38);
    lv_dropdown_set_options(ui->scr_base_ddlist_net_option, "ETHERNET\nWIFI\nLTE/4G");

    //Write style for scr_base_ddlist_net_option, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->scr_base_ddlist_net_option, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_ddlist_net_option, &lv_font_Roboto_Regular_14, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_ddlist_net_option, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->scr_base_ddlist_net_option, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scr_base_ddlist_net_option, 56, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scr_base_ddlist_net_option, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scr_base_ddlist_net_option, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_ddlist_net_option, 12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_ddlist_net_option, 12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_ddlist_net_option, 12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_ddlist_net_option, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_ddlist_net_option, 130, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_base_ddlist_net_option, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_ddlist_net_option, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_ddlist_net_option, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for scr_base_ddlist_net_option, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_text_color(ui->scr_base_ddlist_net_option, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->scr_base_ddlist_net_option, &lv_font_Roboto_Regular_14, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->scr_base_ddlist_net_option, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_border_width(ui->scr_base_ddlist_net_option, 1, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_border_opa(ui->scr_base_ddlist_net_option, 58, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_border_color(ui->scr_base_ddlist_net_option, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_border_side(ui->scr_base_ddlist_net_option, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_pad_top(ui->scr_base_ddlist_net_option, 12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_pad_left(ui->scr_base_ddlist_net_option, 12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_pad_right(ui->scr_base_ddlist_net_option, 12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_radius(ui->scr_base_ddlist_net_option, 10, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_opa(ui->scr_base_ddlist_net_option, 129, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui->scr_base_ddlist_net_option, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_ddlist_net_option, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->scr_base_ddlist_net_option, 0, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write style for scr_base_ddlist_net_option, Part: LV_PART_MAIN, State: LV_STATE_FOCUSED.
    lv_obj_set_style_text_color(ui->scr_base_ddlist_net_option, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_font(ui->scr_base_ddlist_net_option, &lv_font_Roboto_Regular_14, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_opa(ui->scr_base_ddlist_net_option, 255, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_width(ui->scr_base_ddlist_net_option, 1, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_opa(ui->scr_base_ddlist_net_option, 70, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_color(ui->scr_base_ddlist_net_option, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_side(ui->scr_base_ddlist_net_option, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_pad_top(ui->scr_base_ddlist_net_option, 12, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_pad_left(ui->scr_base_ddlist_net_option, 12, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_pad_right(ui->scr_base_ddlist_net_option, 12, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_radius(ui->scr_base_ddlist_net_option, 10, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_opa(ui->scr_base_ddlist_net_option, 130, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_color(ui->scr_base_ddlist_net_option, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_ddlist_net_option, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_shadow_width(ui->scr_base_ddlist_net_option, 0, LV_PART_MAIN|LV_STATE_FOCUSED);

    //Write style for scr_base_ddlist_net_option, Part: LV_PART_MAIN, State: LV_STATE_DISABLED.
    lv_obj_set_style_text_color(ui->scr_base_ddlist_net_option, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_font(ui->scr_base_ddlist_net_option, &lv_font_Roboto_Regular_14, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_opa(ui->scr_base_ddlist_net_option, 255, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_border_width(ui->scr_base_ddlist_net_option, 1, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_border_opa(ui->scr_base_ddlist_net_option, 61, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_border_color(ui->scr_base_ddlist_net_option, lv_color_hex(0xe1e6ee), LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_border_side(ui->scr_base_ddlist_net_option, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_pad_top(ui->scr_base_ddlist_net_option, 12, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_pad_left(ui->scr_base_ddlist_net_option, 12, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_pad_right(ui->scr_base_ddlist_net_option, 12, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_radius(ui->scr_base_ddlist_net_option, 10, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_bg_opa(ui->scr_base_ddlist_net_option, 130, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_bg_color(ui->scr_base_ddlist_net_option, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_ddlist_net_option, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_shadow_width(ui->scr_base_ddlist_net_option, 0, LV_PART_MAIN|LV_STATE_DISABLED);

    //Write style state: LV_STATE_CHECKED for &style_scr_base_ddlist_net_option_extra_list_selected_checked
    static lv_style_t style_scr_base_ddlist_net_option_extra_list_selected_checked;
    ui_init_style(&style_scr_base_ddlist_net_option_extra_list_selected_checked);

    lv_style_set_border_width(&style_scr_base_ddlist_net_option_extra_list_selected_checked, 1);
    lv_style_set_border_opa(&style_scr_base_ddlist_net_option_extra_list_selected_checked, 255);
    lv_style_set_border_color(&style_scr_base_ddlist_net_option_extra_list_selected_checked, lv_color_hex(0xe1e6ee));
    lv_style_set_border_side(&style_scr_base_ddlist_net_option_extra_list_selected_checked, LV_BORDER_SIDE_FULL);
    lv_style_set_radius(&style_scr_base_ddlist_net_option_extra_list_selected_checked, 1);
    lv_style_set_bg_opa(&style_scr_base_ddlist_net_option_extra_list_selected_checked, 129);
    lv_style_set_bg_color(&style_scr_base_ddlist_net_option_extra_list_selected_checked, lv_color_hex(0x00a1b5));
    lv_style_set_bg_grad_dir(&style_scr_base_ddlist_net_option_extra_list_selected_checked, LV_GRAD_DIR_NONE);
    lv_obj_add_style(lv_dropdown_get_list(ui->scr_base_ddlist_net_option), &style_scr_base_ddlist_net_option_extra_list_selected_checked, LV_PART_SELECTED|LV_STATE_CHECKED);

    //Write style state: LV_STATE_DEFAULT for &style_scr_base_ddlist_net_option_extra_list_main_default
    static lv_style_t style_scr_base_ddlist_net_option_extra_list_main_default;
    ui_init_style(&style_scr_base_ddlist_net_option_extra_list_main_default);

    lv_style_set_max_height(&style_scr_base_ddlist_net_option_extra_list_main_default, 90);
    lv_style_set_text_color(&style_scr_base_ddlist_net_option_extra_list_main_default, lv_color_hex(0xfdfdfd));
    lv_style_set_text_font(&style_scr_base_ddlist_net_option_extra_list_main_default, &lv_font_Roboto_Regular_14);
    lv_style_set_text_opa(&style_scr_base_ddlist_net_option_extra_list_main_default, 255);
    lv_style_set_border_width(&style_scr_base_ddlist_net_option_extra_list_main_default, 1);
    lv_style_set_border_opa(&style_scr_base_ddlist_net_option_extra_list_main_default, 54);
    lv_style_set_border_color(&style_scr_base_ddlist_net_option_extra_list_main_default, lv_color_hex(0xffffff));
    lv_style_set_border_side(&style_scr_base_ddlist_net_option_extra_list_main_default, LV_BORDER_SIDE_FULL);
    lv_style_set_radius(&style_scr_base_ddlist_net_option_extra_list_main_default, 5);
    lv_style_set_bg_opa(&style_scr_base_ddlist_net_option_extra_list_main_default, 129);
    lv_style_set_bg_color(&style_scr_base_ddlist_net_option_extra_list_main_default, lv_color_hex(0x000000));
    lv_style_set_bg_grad_dir(&style_scr_base_ddlist_net_option_extra_list_main_default, LV_GRAD_DIR_NONE);
    lv_obj_add_style(lv_dropdown_get_list(ui->scr_base_ddlist_net_option), &style_scr_base_ddlist_net_option_extra_list_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_DEFAULT for &style_scr_base_ddlist_net_option_extra_list_scrollbar_default
    static lv_style_t style_scr_base_ddlist_net_option_extra_list_scrollbar_default;
    ui_init_style(&style_scr_base_ddlist_net_option_extra_list_scrollbar_default);

    lv_style_set_radius(&style_scr_base_ddlist_net_option_extra_list_scrollbar_default, 3);
    lv_style_set_bg_opa(&style_scr_base_ddlist_net_option_extra_list_scrollbar_default, 54);
    lv_style_set_bg_color(&style_scr_base_ddlist_net_option_extra_list_scrollbar_default, lv_color_hex(0xcccccc));
    lv_style_set_bg_grad_dir(&style_scr_base_ddlist_net_option_extra_list_scrollbar_default, LV_GRAD_DIR_NONE);
    lv_obj_add_style(lv_dropdown_get_list(ui->scr_base_ddlist_net_option), &style_scr_base_ddlist_net_option_extra_list_scrollbar_default, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);

    //Write codes scr_base_cont_40
    ui->scr_base_cont_40 = lv_obj_create(ui->scr_base_cont_networkconfig);
    lv_obj_set_pos(ui->scr_base_cont_40, 0, 55);
    lv_obj_set_size(ui->scr_base_cont_40, 660, 320);
    lv_obj_set_scrollbar_mode(ui->scr_base_cont_40, LV_SCROLLBAR_MODE_OFF);

    //Write style for scr_base_cont_40, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_cont_40, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scr_base_cont_40, 65, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scr_base_cont_40, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scr_base_cont_40, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_cont_40, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_cont_40, 243, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_base_cont_40, lv_color_hex(0x0F172A), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_cont_40, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_cont_40, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_cont_40, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_cont_40, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_cont_40, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_cont_40, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_cont_wifi
    ui->scr_base_cont_wifi = lv_obj_create(ui->scr_base_cont_40);
    lv_obj_set_pos(ui->scr_base_cont_wifi, 23, 14);
    lv_obj_set_size(ui->scr_base_cont_wifi, 612, 290);
    lv_obj_set_scrollbar_mode(ui->scr_base_cont_wifi, LV_SCROLLBAR_MODE_OFF);
    lv_obj_add_flag(ui->scr_base_cont_wifi, LV_OBJ_FLAG_HIDDEN);

    //Write style for scr_base_cont_wifi, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_cont_wifi, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scr_base_cont_wifi, 65, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scr_base_cont_wifi, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scr_base_cont_wifi, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_cont_wifi, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_cont_wifi, 51, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_base_cont_wifi, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_cont_wifi, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_cont_wifi, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_cont_wifi, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_cont_wifi, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_cont_wifi, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_cont_wifi, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_label_108
    ui->scr_base_label_108 = lv_label_create(ui->scr_base_cont_wifi);
    lv_obj_set_pos(ui->scr_base_label_108, 176, 24);
    lv_obj_set_size(ui->scr_base_label_108, 161, 17);
    lv_label_set_text(ui->scr_base_label_108, "SSID NAME");
    lv_label_set_long_mode(ui->scr_base_label_108, LV_LABEL_LONG_WRAP);

    //Write style for scr_base_label_108, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_label_108, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_label_108, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_base_label_108, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_label_108, &lv_font_Roboto_Bold_15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_label_108, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_base_label_108, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_base_label_108, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_label_108, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_label_108, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_label_108, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_label_108, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_label_108, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_label_108, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_label_108, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_label_109
    ui->scr_base_label_109 = lv_label_create(ui->scr_base_cont_wifi);
    lv_obj_set_pos(ui->scr_base_label_109, 388, 24);
    lv_obj_set_size(ui->scr_base_label_109, 161, 13);
    lv_label_set_text(ui->scr_base_label_109, "PASSWORD");
    lv_label_set_long_mode(ui->scr_base_label_109, LV_LABEL_LONG_WRAP);

    //Write style for scr_base_label_109, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_label_109, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_label_109, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_base_label_109, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_label_109, &lv_font_Roboto_Bold_15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_label_109, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_base_label_109, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_base_label_109, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_label_109, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_label_109, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_label_109, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_label_109, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_label_109, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_label_109, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_label_109, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_ta_wifi_pass
    ui->scr_base_ta_wifi_pass = lv_textarea_create(ui->scr_base_cont_wifi);
    lv_obj_set_pos(ui->scr_base_ta_wifi_pass, 388, 50);
    lv_obj_set_size(ui->scr_base_ta_wifi_pass, 200, 38);
    lv_textarea_set_text(ui->scr_base_ta_wifi_pass, "");
    lv_textarea_set_placeholder_text(ui->scr_base_ta_wifi_pass, "Enter password...");
    lv_textarea_set_password_bullet(ui->scr_base_ta_wifi_pass, "*");
    lv_textarea_set_password_mode(ui->scr_base_ta_wifi_pass, true);
    lv_textarea_set_one_line(ui->scr_base_ta_wifi_pass, true);
    lv_textarea_set_accepted_chars(ui->scr_base_ta_wifi_pass, "");
    lv_textarea_set_max_length(ui->scr_base_ta_wifi_pass, 32);
#if LV_USE_KEYBOARD
    lv_obj_add_event_cb(ui->scr_base_ta_wifi_pass, ta_event_cb, LV_EVENT_ALL, ui->g_kb_top_layer);
#endif

    //Write style for scr_base_ta_wifi_pass, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->scr_base_ta_wifi_pass, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_ta_wifi_pass, &lv_font_Roboto_Regular_14, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_ta_wifi_pass, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_base_ta_wifi_pass, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_ta_wifi_pass, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_ta_wifi_pass, 130, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_base_ta_wifi_pass, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_ta_wifi_pass, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->scr_base_ta_wifi_pass, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scr_base_ta_wifi_pass, 58, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scr_base_ta_wifi_pass, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scr_base_ta_wifi_pass, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_ta_wifi_pass, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_ta_wifi_pass, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_ta_wifi_pass, 12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_ta_wifi_pass, 12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_ta_wifi_pass, 10, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for scr_base_ta_wifi_pass, Part: LV_PART_MAIN, State: LV_STATE_FOCUSED.
    lv_obj_set_style_text_color(ui->scr_base_ta_wifi_pass, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_font(ui->scr_base_ta_wifi_pass, &lv_font_Roboto_Regular_14, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_opa(ui->scr_base_ta_wifi_pass, 255, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_opa(ui->scr_base_ta_wifi_pass, 130, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_color(ui->scr_base_ta_wifi_pass, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_ta_wifi_pass, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_width(ui->scr_base_ta_wifi_pass, 1, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_opa(ui->scr_base_ta_wifi_pass, 53, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_color(ui->scr_base_ta_wifi_pass, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_side(ui->scr_base_ta_wifi_pass, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_shadow_width(ui->scr_base_ta_wifi_pass, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_pad_top(ui->scr_base_ta_wifi_pass, 10, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_pad_right(ui->scr_base_ta_wifi_pass, 12, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_pad_left(ui->scr_base_ta_wifi_pass, 12, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_radius(ui->scr_base_ta_wifi_pass, 10, LV_PART_MAIN|LV_STATE_FOCUSED);

    //Write style for scr_base_ta_wifi_pass, Part: LV_PART_SCROLLBAR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->scr_base_ta_wifi_pass, 255, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_base_ta_wifi_pass, lv_color_hex(0x2195f6), LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_ta_wifi_pass, LV_GRAD_DIR_NONE, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_ta_wifi_pass, 0, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);

    //Write codes scr_base_ta_wifi_ssid
    ui->scr_base_ta_wifi_ssid = lv_textarea_create(ui->scr_base_cont_wifi);
    lv_obj_set_pos(ui->scr_base_ta_wifi_ssid, 176, 50);
    lv_obj_set_size(ui->scr_base_ta_wifi_ssid, 200, 38);
    lv_textarea_set_text(ui->scr_base_ta_wifi_ssid, "");
    lv_textarea_set_placeholder_text(ui->scr_base_ta_wifi_ssid, "Enter SSID...");
    lv_textarea_set_password_bullet(ui->scr_base_ta_wifi_ssid, "*");
    lv_textarea_set_password_mode(ui->scr_base_ta_wifi_ssid, false);
    lv_textarea_set_one_line(ui->scr_base_ta_wifi_ssid, true);
    lv_textarea_set_accepted_chars(ui->scr_base_ta_wifi_ssid, "");
    lv_textarea_set_max_length(ui->scr_base_ta_wifi_ssid, 32);
#if LV_USE_KEYBOARD
    lv_obj_add_event_cb(ui->scr_base_ta_wifi_ssid, ta_event_cb, LV_EVENT_ALL, ui->g_kb_top_layer);
#endif

    //Write style for scr_base_ta_wifi_ssid, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->scr_base_ta_wifi_ssid, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_ta_wifi_ssid, &lv_font_Roboto_Regular_14, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_ta_wifi_ssid, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_base_ta_wifi_ssid, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_ta_wifi_ssid, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_ta_wifi_ssid, 130, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_base_ta_wifi_ssid, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_ta_wifi_ssid, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->scr_base_ta_wifi_ssid, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scr_base_ta_wifi_ssid, 58, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scr_base_ta_wifi_ssid, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scr_base_ta_wifi_ssid, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_ta_wifi_ssid, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_ta_wifi_ssid, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_ta_wifi_ssid, 12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_ta_wifi_ssid, 12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_ta_wifi_ssid, 10, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for scr_base_ta_wifi_ssid, Part: LV_PART_MAIN, State: LV_STATE_FOCUSED.
    lv_obj_set_style_text_color(ui->scr_base_ta_wifi_ssid, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_font(ui->scr_base_ta_wifi_ssid, &lv_font_Roboto_Regular_14, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_opa(ui->scr_base_ta_wifi_ssid, 255, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_opa(ui->scr_base_ta_wifi_ssid, 130, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_color(ui->scr_base_ta_wifi_ssid, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_ta_wifi_ssid, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_width(ui->scr_base_ta_wifi_ssid, 1, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_opa(ui->scr_base_ta_wifi_ssid, 53, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_color(ui->scr_base_ta_wifi_ssid, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_side(ui->scr_base_ta_wifi_ssid, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_shadow_width(ui->scr_base_ta_wifi_ssid, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_pad_top(ui->scr_base_ta_wifi_ssid, 10, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_pad_right(ui->scr_base_ta_wifi_ssid, 12, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_pad_left(ui->scr_base_ta_wifi_ssid, 12, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_radius(ui->scr_base_ta_wifi_ssid, 10, LV_PART_MAIN|LV_STATE_FOCUSED);

    //Write style for scr_base_ta_wifi_ssid, Part: LV_PART_SCROLLBAR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->scr_base_ta_wifi_ssid, 255, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_base_ta_wifi_ssid, lv_color_hex(0x2195f6), LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_ta_wifi_ssid, LV_GRAD_DIR_NONE, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_ta_wifi_ssid, 0, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);

    //Write codes scr_base_label_110
    ui->scr_base_label_110 = lv_label_create(ui->scr_base_cont_wifi);
    lv_obj_set_pos(ui->scr_base_label_110, 24, 24);
    lv_obj_set_size(ui->scr_base_label_110, 80, 17);
    lv_label_set_text(ui->scr_base_label_110, "MODE");
    lv_label_set_long_mode(ui->scr_base_label_110, LV_LABEL_LONG_WRAP);

    //Write style for scr_base_label_110, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_label_110, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_label_110, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_base_label_110, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_label_110, &lv_font_Roboto_Bold_15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_label_110, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_base_label_110, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_base_label_110, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_label_110, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_label_110, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_label_110, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_label_110, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_label_110, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_label_110, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_label_110, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_label_111
    ui->scr_base_label_111 = lv_label_create(ui->scr_base_cont_wifi);
    lv_obj_set_pos(ui->scr_base_label_111, 24, 114);
    lv_obj_set_size(ui->scr_base_label_111, 161, 17);
    lv_label_set_text(ui->scr_base_label_111, "IP ADDRESS");
    lv_label_set_long_mode(ui->scr_base_label_111, LV_LABEL_LONG_WRAP);

    //Write style for scr_base_label_111, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_label_111, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_label_111, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_base_label_111, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_label_111, &lv_font_Roboto_Bold_15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_label_111, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_base_label_111, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_base_label_111, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_label_111, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_label_111, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_label_111, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_label_111, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_label_111, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_label_111, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_label_111, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for scr_base_label_111, Part: LV_PART_MAIN, State: LV_STATE_DISABLED.
    lv_obj_set_style_border_width(ui->scr_base_label_111, 0, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_radius(ui->scr_base_label_111, 0, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_color(ui->scr_base_label_111, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_font(ui->scr_base_label_111, &lv_font_Roboto_Black_15, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_opa(ui->scr_base_label_111, 58, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_letter_space(ui->scr_base_label_111, 0, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_line_space(ui->scr_base_label_111, 0, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_align(ui->scr_base_label_111, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_bg_opa(ui->scr_base_label_111, 0, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_pad_top(ui->scr_base_label_111, 0, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_pad_right(ui->scr_base_label_111, 0, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_pad_bottom(ui->scr_base_label_111, 0, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_pad_left(ui->scr_base_label_111, 0, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_shadow_width(ui->scr_base_label_111, 0, LV_PART_MAIN|LV_STATE_DISABLED);

    //Write codes scr_base_ddlist_wifi_mode
    ui->scr_base_ddlist_wifi_mode = lv_dropdown_create(ui->scr_base_cont_wifi);
    lv_obj_set_pos(ui->scr_base_ddlist_wifi_mode, 24, 50);
    lv_obj_set_size(ui->scr_base_ddlist_wifi_mode, 140, 38);
    lv_dropdown_set_options(ui->scr_base_ddlist_wifi_mode, "DHCP\nSTATIC");

    //Write style for scr_base_ddlist_wifi_mode, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->scr_base_ddlist_wifi_mode, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_ddlist_wifi_mode, &lv_font_Roboto_Regular_14, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_ddlist_wifi_mode, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->scr_base_ddlist_wifi_mode, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scr_base_ddlist_wifi_mode, 56, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scr_base_ddlist_wifi_mode, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scr_base_ddlist_wifi_mode, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_ddlist_wifi_mode, 12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_ddlist_wifi_mode, 12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_ddlist_wifi_mode, 12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_ddlist_wifi_mode, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_ddlist_wifi_mode, 130, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_base_ddlist_wifi_mode, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_ddlist_wifi_mode, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_ddlist_wifi_mode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for scr_base_ddlist_wifi_mode, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_text_color(ui->scr_base_ddlist_wifi_mode, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->scr_base_ddlist_wifi_mode, &lv_font_Roboto_Regular_14, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->scr_base_ddlist_wifi_mode, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_border_width(ui->scr_base_ddlist_wifi_mode, 1, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_border_opa(ui->scr_base_ddlist_wifi_mode, 58, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_border_color(ui->scr_base_ddlist_wifi_mode, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_border_side(ui->scr_base_ddlist_wifi_mode, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_pad_top(ui->scr_base_ddlist_wifi_mode, 12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_pad_left(ui->scr_base_ddlist_wifi_mode, 12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_pad_right(ui->scr_base_ddlist_wifi_mode, 12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_radius(ui->scr_base_ddlist_wifi_mode, 10, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_opa(ui->scr_base_ddlist_wifi_mode, 129, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui->scr_base_ddlist_wifi_mode, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_ddlist_wifi_mode, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->scr_base_ddlist_wifi_mode, 0, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write style for scr_base_ddlist_wifi_mode, Part: LV_PART_MAIN, State: LV_STATE_FOCUSED.
    lv_obj_set_style_text_color(ui->scr_base_ddlist_wifi_mode, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_font(ui->scr_base_ddlist_wifi_mode, &lv_font_Roboto_Regular_14, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_opa(ui->scr_base_ddlist_wifi_mode, 255, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_width(ui->scr_base_ddlist_wifi_mode, 1, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_opa(ui->scr_base_ddlist_wifi_mode, 70, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_color(ui->scr_base_ddlist_wifi_mode, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_side(ui->scr_base_ddlist_wifi_mode, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_pad_top(ui->scr_base_ddlist_wifi_mode, 12, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_pad_left(ui->scr_base_ddlist_wifi_mode, 12, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_pad_right(ui->scr_base_ddlist_wifi_mode, 12, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_radius(ui->scr_base_ddlist_wifi_mode, 10, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_opa(ui->scr_base_ddlist_wifi_mode, 130, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_color(ui->scr_base_ddlist_wifi_mode, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_ddlist_wifi_mode, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_shadow_width(ui->scr_base_ddlist_wifi_mode, 0, LV_PART_MAIN|LV_STATE_FOCUSED);

    //Write style for scr_base_ddlist_wifi_mode, Part: LV_PART_MAIN, State: LV_STATE_DISABLED.
    lv_obj_set_style_text_color(ui->scr_base_ddlist_wifi_mode, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_font(ui->scr_base_ddlist_wifi_mode, &lv_font_Roboto_Regular_14, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_opa(ui->scr_base_ddlist_wifi_mode, 255, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_border_width(ui->scr_base_ddlist_wifi_mode, 1, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_border_opa(ui->scr_base_ddlist_wifi_mode, 61, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_border_color(ui->scr_base_ddlist_wifi_mode, lv_color_hex(0xe1e6ee), LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_border_side(ui->scr_base_ddlist_wifi_mode, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_pad_top(ui->scr_base_ddlist_wifi_mode, 12, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_pad_left(ui->scr_base_ddlist_wifi_mode, 12, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_pad_right(ui->scr_base_ddlist_wifi_mode, 12, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_radius(ui->scr_base_ddlist_wifi_mode, 10, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_bg_opa(ui->scr_base_ddlist_wifi_mode, 130, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_bg_color(ui->scr_base_ddlist_wifi_mode, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_ddlist_wifi_mode, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_shadow_width(ui->scr_base_ddlist_wifi_mode, 0, LV_PART_MAIN|LV_STATE_DISABLED);

    //Write style state: LV_STATE_CHECKED for &style_scr_base_ddlist_wifi_mode_extra_list_selected_checked
    static lv_style_t style_scr_base_ddlist_wifi_mode_extra_list_selected_checked;
    ui_init_style(&style_scr_base_ddlist_wifi_mode_extra_list_selected_checked);

    lv_style_set_border_width(&style_scr_base_ddlist_wifi_mode_extra_list_selected_checked, 1);
    lv_style_set_border_opa(&style_scr_base_ddlist_wifi_mode_extra_list_selected_checked, 255);
    lv_style_set_border_color(&style_scr_base_ddlist_wifi_mode_extra_list_selected_checked, lv_color_hex(0xe1e6ee));
    lv_style_set_border_side(&style_scr_base_ddlist_wifi_mode_extra_list_selected_checked, LV_BORDER_SIDE_FULL);
    lv_style_set_radius(&style_scr_base_ddlist_wifi_mode_extra_list_selected_checked, 1);
    lv_style_set_bg_opa(&style_scr_base_ddlist_wifi_mode_extra_list_selected_checked, 129);
    lv_style_set_bg_color(&style_scr_base_ddlist_wifi_mode_extra_list_selected_checked, lv_color_hex(0x00a1b5));
    lv_style_set_bg_grad_dir(&style_scr_base_ddlist_wifi_mode_extra_list_selected_checked, LV_GRAD_DIR_NONE);
    lv_obj_add_style(lv_dropdown_get_list(ui->scr_base_ddlist_wifi_mode), &style_scr_base_ddlist_wifi_mode_extra_list_selected_checked, LV_PART_SELECTED|LV_STATE_CHECKED);

    //Write style state: LV_STATE_DEFAULT for &style_scr_base_ddlist_wifi_mode_extra_list_main_default
    static lv_style_t style_scr_base_ddlist_wifi_mode_extra_list_main_default;
    ui_init_style(&style_scr_base_ddlist_wifi_mode_extra_list_main_default);

    lv_style_set_max_height(&style_scr_base_ddlist_wifi_mode_extra_list_main_default, 90);
    lv_style_set_text_color(&style_scr_base_ddlist_wifi_mode_extra_list_main_default, lv_color_hex(0xfdfdfd));
    lv_style_set_text_font(&style_scr_base_ddlist_wifi_mode_extra_list_main_default, &lv_font_Roboto_Regular_14);
    lv_style_set_text_opa(&style_scr_base_ddlist_wifi_mode_extra_list_main_default, 255);
    lv_style_set_border_width(&style_scr_base_ddlist_wifi_mode_extra_list_main_default, 1);
    lv_style_set_border_opa(&style_scr_base_ddlist_wifi_mode_extra_list_main_default, 54);
    lv_style_set_border_color(&style_scr_base_ddlist_wifi_mode_extra_list_main_default, lv_color_hex(0xffffff));
    lv_style_set_border_side(&style_scr_base_ddlist_wifi_mode_extra_list_main_default, LV_BORDER_SIDE_FULL);
    lv_style_set_radius(&style_scr_base_ddlist_wifi_mode_extra_list_main_default, 5);
    lv_style_set_bg_opa(&style_scr_base_ddlist_wifi_mode_extra_list_main_default, 129);
    lv_style_set_bg_color(&style_scr_base_ddlist_wifi_mode_extra_list_main_default, lv_color_hex(0x000000));
    lv_style_set_bg_grad_dir(&style_scr_base_ddlist_wifi_mode_extra_list_main_default, LV_GRAD_DIR_NONE);
    lv_obj_add_style(lv_dropdown_get_list(ui->scr_base_ddlist_wifi_mode), &style_scr_base_ddlist_wifi_mode_extra_list_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_DEFAULT for &style_scr_base_ddlist_wifi_mode_extra_list_scrollbar_default
    static lv_style_t style_scr_base_ddlist_wifi_mode_extra_list_scrollbar_default;
    ui_init_style(&style_scr_base_ddlist_wifi_mode_extra_list_scrollbar_default);

    lv_style_set_radius(&style_scr_base_ddlist_wifi_mode_extra_list_scrollbar_default, 3);
    lv_style_set_bg_opa(&style_scr_base_ddlist_wifi_mode_extra_list_scrollbar_default, 54);
    lv_style_set_bg_color(&style_scr_base_ddlist_wifi_mode_extra_list_scrollbar_default, lv_color_hex(0xcccccc));
    lv_style_set_bg_grad_dir(&style_scr_base_ddlist_wifi_mode_extra_list_scrollbar_default, LV_GRAD_DIR_NONE);
    lv_obj_add_style(lv_dropdown_get_list(ui->scr_base_ddlist_wifi_mode), &style_scr_base_ddlist_wifi_mode_extra_list_scrollbar_default, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);

    //Write codes scr_base_ta_wifi_ip
    ui->scr_base_ta_wifi_ip = lv_textarea_create(ui->scr_base_cont_wifi);
    lv_obj_set_pos(ui->scr_base_ta_wifi_ip, 24, 140);
    lv_obj_set_size(ui->scr_base_ta_wifi_ip, 180, 38);
    lv_textarea_set_text(ui->scr_base_ta_wifi_ip, "");
    lv_textarea_set_placeholder_text(ui->scr_base_ta_wifi_ip, "Enter IP address...");
    lv_textarea_set_password_bullet(ui->scr_base_ta_wifi_ip, "*");
    lv_textarea_set_password_mode(ui->scr_base_ta_wifi_ip, false);
    lv_textarea_set_one_line(ui->scr_base_ta_wifi_ip, true);
    lv_textarea_set_accepted_chars(ui->scr_base_ta_wifi_ip, "");
    lv_textarea_set_max_length(ui->scr_base_ta_wifi_ip, 32);
#if LV_USE_KEYBOARD
    lv_obj_add_event_cb(ui->scr_base_ta_wifi_ip, ta_event_cb, LV_EVENT_ALL, ui->g_kb_top_layer);
#endif

    //Write style for scr_base_ta_wifi_ip, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->scr_base_ta_wifi_ip, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_ta_wifi_ip, &lv_font_Roboto_Regular_14, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_ta_wifi_ip, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_base_ta_wifi_ip, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_ta_wifi_ip, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_ta_wifi_ip, 130, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_base_ta_wifi_ip, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_ta_wifi_ip, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->scr_base_ta_wifi_ip, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scr_base_ta_wifi_ip, 58, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scr_base_ta_wifi_ip, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scr_base_ta_wifi_ip, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_ta_wifi_ip, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_ta_wifi_ip, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_ta_wifi_ip, 12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_ta_wifi_ip, 12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_ta_wifi_ip, 10, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for scr_base_ta_wifi_ip, Part: LV_PART_MAIN, State: LV_STATE_FOCUSED.
    lv_obj_set_style_text_color(ui->scr_base_ta_wifi_ip, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_font(ui->scr_base_ta_wifi_ip, &lv_font_Roboto_Regular_14, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_opa(ui->scr_base_ta_wifi_ip, 255, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_opa(ui->scr_base_ta_wifi_ip, 130, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_color(ui->scr_base_ta_wifi_ip, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_ta_wifi_ip, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_width(ui->scr_base_ta_wifi_ip, 1, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_opa(ui->scr_base_ta_wifi_ip, 53, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_color(ui->scr_base_ta_wifi_ip, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_side(ui->scr_base_ta_wifi_ip, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_shadow_width(ui->scr_base_ta_wifi_ip, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_pad_top(ui->scr_base_ta_wifi_ip, 10, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_pad_right(ui->scr_base_ta_wifi_ip, 12, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_pad_left(ui->scr_base_ta_wifi_ip, 12, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_radius(ui->scr_base_ta_wifi_ip, 10, LV_PART_MAIN|LV_STATE_FOCUSED);

    //Write style for scr_base_ta_wifi_ip, Part: LV_PART_SCROLLBAR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->scr_base_ta_wifi_ip, 255, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_base_ta_wifi_ip, lv_color_hex(0x2195f6), LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_ta_wifi_ip, LV_GRAD_DIR_NONE, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_ta_wifi_ip, 0, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);

    //Write codes scr_base_lbl_wifi_status
    ui->scr_base_lbl_wifi_status = lv_label_create(ui->scr_base_cont_wifi);
    lv_obj_set_pos(ui->scr_base_lbl_wifi_status, 22, 200);
    lv_obj_set_size(ui->scr_base_lbl_wifi_status, 560, 17);
    lv_label_set_text(ui->scr_base_lbl_wifi_status, "Configure your settings to connect to an wifi network.");
    lv_label_set_long_mode(ui->scr_base_lbl_wifi_status, LV_LABEL_LONG_WRAP);

    //Write style for scr_base_lbl_wifi_status, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_lbl_wifi_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_lbl_wifi_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_base_lbl_wifi_status, lv_color_hex(0x71717A), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_lbl_wifi_status, &lv_font_Roboto_Regular_15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_lbl_wifi_status, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_base_lbl_wifi_status, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_base_lbl_wifi_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_lbl_wifi_status, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_lbl_wifi_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_lbl_wifi_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_lbl_wifi_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_lbl_wifi_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_lbl_wifi_status, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_lbl_wifi_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_btn_wifi_apply
    ui->scr_base_btn_wifi_apply = lv_button_create(ui->scr_base_cont_wifi);
    lv_obj_set_pos(ui->scr_base_btn_wifi_apply, 23, 236);
    lv_obj_set_size(ui->scr_base_btn_wifi_apply, 560, 38);
    ui->scr_base_btn_wifi_apply_label = lv_label_create(ui->scr_base_btn_wifi_apply);
    lv_label_set_text(ui->scr_base_btn_wifi_apply_label, "APPLY CONFIG");
    lv_label_set_long_mode(ui->scr_base_btn_wifi_apply_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->scr_base_btn_wifi_apply_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->scr_base_btn_wifi_apply, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->scr_base_btn_wifi_apply_label, LV_PCT(100));

    //Write style for scr_base_btn_wifi_apply, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->scr_base_btn_wifi_apply, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_base_btn_wifi_apply, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_btn_wifi_apply, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->scr_base_btn_wifi_apply, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scr_base_btn_wifi_apply, 63, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scr_base_btn_wifi_apply, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scr_base_btn_wifi_apply, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_btn_wifi_apply, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_btn_wifi_apply, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_base_btn_wifi_apply, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_btn_wifi_apply, &lv_font_Roboto_Black_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_btn_wifi_apply, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_btn_wifi_apply, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for scr_base_btn_wifi_apply, Part: LV_PART_MAIN, State: LV_STATE_FOCUSED.
    lv_obj_set_style_bg_opa(ui->scr_base_btn_wifi_apply, 255, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_color(ui->scr_base_btn_wifi_apply, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_btn_wifi_apply, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_width(ui->scr_base_btn_wifi_apply, 1, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_opa(ui->scr_base_btn_wifi_apply, 255, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_color(ui->scr_base_btn_wifi_apply, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_side(ui->scr_base_btn_wifi_apply, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_radius(ui->scr_base_btn_wifi_apply, 10, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_shadow_width(ui->scr_base_btn_wifi_apply, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_color(ui->scr_base_btn_wifi_apply, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_font(ui->scr_base_btn_wifi_apply, &lv_font_Roboto_Black_16, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_opa(ui->scr_base_btn_wifi_apply, 255, LV_PART_MAIN|LV_STATE_FOCUSED);

    //Write style for scr_base_btn_wifi_apply, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_bg_opa(ui->scr_base_btn_wifi_apply, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_bg_color(ui->scr_base_btn_wifi_apply, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_btn_wifi_apply, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui->scr_base_btn_wifi_apply, 1, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_border_opa(ui->scr_base_btn_wifi_apply, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_border_color(ui->scr_base_btn_wifi_apply, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_border_side(ui->scr_base_btn_wifi_apply, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_radius(ui->scr_base_btn_wifi_apply, 10, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->scr_base_btn_wifi_apply, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->scr_base_btn_wifi_apply, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->scr_base_btn_wifi_apply, &lv_font_Roboto_Black_16, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->scr_base_btn_wifi_apply, 255, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for scr_base_btn_wifi_apply, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_bg_opa(ui->scr_base_btn_wifi_apply, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui->scr_base_btn_wifi_apply, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_btn_wifi_apply, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_border_width(ui->scr_base_btn_wifi_apply, 1, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_border_opa(ui->scr_base_btn_wifi_apply, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_border_color(ui->scr_base_btn_wifi_apply, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_border_side(ui->scr_base_btn_wifi_apply, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_radius(ui->scr_base_btn_wifi_apply, 10, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->scr_base_btn_wifi_apply, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->scr_base_btn_wifi_apply, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->scr_base_btn_wifi_apply, &lv_font_Roboto_Black_16, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->scr_base_btn_wifi_apply, 255, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write style for scr_base_btn_wifi_apply, Part: LV_PART_MAIN, State: LV_STATE_DISABLED.
    lv_obj_set_style_bg_opa(ui->scr_base_btn_wifi_apply, 255, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_bg_color(ui->scr_base_btn_wifi_apply, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_btn_wifi_apply, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_border_width(ui->scr_base_btn_wifi_apply, 1, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_border_opa(ui->scr_base_btn_wifi_apply, 255, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_border_color(ui->scr_base_btn_wifi_apply, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_border_side(ui->scr_base_btn_wifi_apply, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_radius(ui->scr_base_btn_wifi_apply, 10, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_shadow_width(ui->scr_base_btn_wifi_apply, 0, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_color(ui->scr_base_btn_wifi_apply, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_font(ui->scr_base_btn_wifi_apply, &lv_font_Roboto_Black_16, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_opa(ui->scr_base_btn_wifi_apply, 255, LV_PART_MAIN|LV_STATE_DISABLED);

    //Write codes scr_base_ta_wifi_subnetmark
    ui->scr_base_ta_wifi_subnetmark = lv_textarea_create(ui->scr_base_cont_wifi);
    lv_obj_set_pos(ui->scr_base_ta_wifi_subnetmark, 216, 140);
    lv_obj_set_size(ui->scr_base_ta_wifi_subnetmark, 180, 38);
    lv_textarea_set_text(ui->scr_base_ta_wifi_subnetmark, "");
    lv_textarea_set_placeholder_text(ui->scr_base_ta_wifi_subnetmark, "Enter subnet mark...");
    lv_textarea_set_password_bullet(ui->scr_base_ta_wifi_subnetmark, "*");
    lv_textarea_set_password_mode(ui->scr_base_ta_wifi_subnetmark, false);
    lv_textarea_set_one_line(ui->scr_base_ta_wifi_subnetmark, true);
    lv_textarea_set_accepted_chars(ui->scr_base_ta_wifi_subnetmark, "");
    lv_textarea_set_max_length(ui->scr_base_ta_wifi_subnetmark, 32);
#if LV_USE_KEYBOARD
    lv_obj_add_event_cb(ui->scr_base_ta_wifi_subnetmark, ta_event_cb, LV_EVENT_ALL, ui->g_kb_top_layer);
#endif

    //Write style for scr_base_ta_wifi_subnetmark, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->scr_base_ta_wifi_subnetmark, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_ta_wifi_subnetmark, &lv_font_Roboto_Regular_14, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_ta_wifi_subnetmark, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_base_ta_wifi_subnetmark, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_ta_wifi_subnetmark, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_ta_wifi_subnetmark, 130, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_base_ta_wifi_subnetmark, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_ta_wifi_subnetmark, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->scr_base_ta_wifi_subnetmark, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scr_base_ta_wifi_subnetmark, 58, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scr_base_ta_wifi_subnetmark, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scr_base_ta_wifi_subnetmark, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_ta_wifi_subnetmark, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_ta_wifi_subnetmark, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_ta_wifi_subnetmark, 12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_ta_wifi_subnetmark, 12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_ta_wifi_subnetmark, 10, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for scr_base_ta_wifi_subnetmark, Part: LV_PART_MAIN, State: LV_STATE_FOCUSED.
    lv_obj_set_style_text_color(ui->scr_base_ta_wifi_subnetmark, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_font(ui->scr_base_ta_wifi_subnetmark, &lv_font_Roboto_Regular_14, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_opa(ui->scr_base_ta_wifi_subnetmark, 255, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_opa(ui->scr_base_ta_wifi_subnetmark, 130, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_color(ui->scr_base_ta_wifi_subnetmark, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_ta_wifi_subnetmark, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_width(ui->scr_base_ta_wifi_subnetmark, 1, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_opa(ui->scr_base_ta_wifi_subnetmark, 53, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_color(ui->scr_base_ta_wifi_subnetmark, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_side(ui->scr_base_ta_wifi_subnetmark, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_shadow_width(ui->scr_base_ta_wifi_subnetmark, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_pad_top(ui->scr_base_ta_wifi_subnetmark, 10, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_pad_right(ui->scr_base_ta_wifi_subnetmark, 12, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_pad_left(ui->scr_base_ta_wifi_subnetmark, 12, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_radius(ui->scr_base_ta_wifi_subnetmark, 10, LV_PART_MAIN|LV_STATE_FOCUSED);

    //Write style for scr_base_ta_wifi_subnetmark, Part: LV_PART_SCROLLBAR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->scr_base_ta_wifi_subnetmark, 255, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_base_ta_wifi_subnetmark, lv_color_hex(0x2195f6), LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_ta_wifi_subnetmark, LV_GRAD_DIR_NONE, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_ta_wifi_subnetmark, 0, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);

    //Write codes scr_base_ta_wifi_gateway
    ui->scr_base_ta_wifi_gateway = lv_textarea_create(ui->scr_base_cont_wifi);
    lv_obj_set_pos(ui->scr_base_ta_wifi_gateway, 408, 140);
    lv_obj_set_size(ui->scr_base_ta_wifi_gateway, 180, 38);
    lv_textarea_set_text(ui->scr_base_ta_wifi_gateway, "");
    lv_textarea_set_placeholder_text(ui->scr_base_ta_wifi_gateway, "Enter gatewaty...");
    lv_textarea_set_password_bullet(ui->scr_base_ta_wifi_gateway, "*");
    lv_textarea_set_password_mode(ui->scr_base_ta_wifi_gateway, false);
    lv_textarea_set_one_line(ui->scr_base_ta_wifi_gateway, true);
    lv_textarea_set_accepted_chars(ui->scr_base_ta_wifi_gateway, "");
    lv_textarea_set_max_length(ui->scr_base_ta_wifi_gateway, 32);
#if LV_USE_KEYBOARD
    lv_obj_add_event_cb(ui->scr_base_ta_wifi_gateway, ta_event_cb, LV_EVENT_ALL, ui->g_kb_top_layer);
#endif

    //Write style for scr_base_ta_wifi_gateway, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->scr_base_ta_wifi_gateway, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_ta_wifi_gateway, &lv_font_Roboto_Regular_14, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_ta_wifi_gateway, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_base_ta_wifi_gateway, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_ta_wifi_gateway, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_ta_wifi_gateway, 130, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_base_ta_wifi_gateway, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_ta_wifi_gateway, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->scr_base_ta_wifi_gateway, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scr_base_ta_wifi_gateway, 58, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scr_base_ta_wifi_gateway, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scr_base_ta_wifi_gateway, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_ta_wifi_gateway, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_ta_wifi_gateway, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_ta_wifi_gateway, 12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_ta_wifi_gateway, 12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_ta_wifi_gateway, 10, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for scr_base_ta_wifi_gateway, Part: LV_PART_MAIN, State: LV_STATE_FOCUSED.
    lv_obj_set_style_text_color(ui->scr_base_ta_wifi_gateway, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_font(ui->scr_base_ta_wifi_gateway, &lv_font_Roboto_Regular_14, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_opa(ui->scr_base_ta_wifi_gateway, 255, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_opa(ui->scr_base_ta_wifi_gateway, 130, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_color(ui->scr_base_ta_wifi_gateway, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_ta_wifi_gateway, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_width(ui->scr_base_ta_wifi_gateway, 1, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_opa(ui->scr_base_ta_wifi_gateway, 53, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_color(ui->scr_base_ta_wifi_gateway, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_side(ui->scr_base_ta_wifi_gateway, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_shadow_width(ui->scr_base_ta_wifi_gateway, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_pad_top(ui->scr_base_ta_wifi_gateway, 10, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_pad_right(ui->scr_base_ta_wifi_gateway, 12, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_pad_left(ui->scr_base_ta_wifi_gateway, 12, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_radius(ui->scr_base_ta_wifi_gateway, 10, LV_PART_MAIN|LV_STATE_FOCUSED);

    //Write style for scr_base_ta_wifi_gateway, Part: LV_PART_SCROLLBAR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->scr_base_ta_wifi_gateway, 255, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_base_ta_wifi_gateway, lv_color_hex(0x2195f6), LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_ta_wifi_gateway, LV_GRAD_DIR_NONE, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_ta_wifi_gateway, 0, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);

    //Write codes scr_base_label_213
    ui->scr_base_label_213 = lv_label_create(ui->scr_base_cont_wifi);
    lv_obj_set_pos(ui->scr_base_label_213, 216, 113);
    lv_obj_set_size(ui->scr_base_label_213, 161, 17);
    lv_label_set_text(ui->scr_base_label_213, "SUBNET MARK");
    lv_label_set_long_mode(ui->scr_base_label_213, LV_LABEL_LONG_WRAP);

    //Write style for scr_base_label_213, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_label_213, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_label_213, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_base_label_213, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_label_213, &lv_font_Roboto_Bold_15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_label_213, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_base_label_213, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_base_label_213, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_label_213, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_label_213, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_label_213, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_label_213, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_label_213, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_label_213, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_label_213, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for scr_base_label_213, Part: LV_PART_MAIN, State: LV_STATE_DISABLED.
    lv_obj_set_style_border_width(ui->scr_base_label_213, 0, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_radius(ui->scr_base_label_213, 0, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_color(ui->scr_base_label_213, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_font(ui->scr_base_label_213, &lv_font_Roboto_Black_15, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_opa(ui->scr_base_label_213, 60, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_letter_space(ui->scr_base_label_213, 0, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_line_space(ui->scr_base_label_213, 0, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_align(ui->scr_base_label_213, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_bg_opa(ui->scr_base_label_213, 0, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_pad_top(ui->scr_base_label_213, 0, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_pad_right(ui->scr_base_label_213, 0, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_pad_bottom(ui->scr_base_label_213, 0, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_pad_left(ui->scr_base_label_213, 0, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_shadow_width(ui->scr_base_label_213, 0, LV_PART_MAIN|LV_STATE_DISABLED);

    //Write codes scr_base_label_214
    ui->scr_base_label_214 = lv_label_create(ui->scr_base_cont_wifi);
    lv_obj_set_pos(ui->scr_base_label_214, 408, 114);
    lv_obj_set_size(ui->scr_base_label_214, 161, 17);
    lv_label_set_text(ui->scr_base_label_214, "GATEWAY");
    lv_label_set_long_mode(ui->scr_base_label_214, LV_LABEL_LONG_WRAP);

    //Write style for scr_base_label_214, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_label_214, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_label_214, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_base_label_214, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_label_214, &lv_font_Roboto_Bold_15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_label_214, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_base_label_214, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_base_label_214, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_label_214, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_label_214, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_label_214, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_label_214, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_label_214, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_label_214, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_label_214, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for scr_base_label_214, Part: LV_PART_MAIN, State: LV_STATE_DISABLED.
    lv_obj_set_style_border_width(ui->scr_base_label_214, 0, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_radius(ui->scr_base_label_214, 0, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_color(ui->scr_base_label_214, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_font(ui->scr_base_label_214, &lv_font_Roboto_Black_15, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_opa(ui->scr_base_label_214, 67, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_letter_space(ui->scr_base_label_214, 0, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_line_space(ui->scr_base_label_214, 0, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_align(ui->scr_base_label_214, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_bg_opa(ui->scr_base_label_214, 0, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_pad_top(ui->scr_base_label_214, 0, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_pad_right(ui->scr_base_label_214, 0, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_pad_bottom(ui->scr_base_label_214, 0, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_pad_left(ui->scr_base_label_214, 0, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_shadow_width(ui->scr_base_label_214, 0, LV_PART_MAIN|LV_STATE_DISABLED);

    //Write codes scr_base_cont_ethernet
    ui->scr_base_cont_ethernet = lv_obj_create(ui->scr_base_cont_40);
    lv_obj_set_pos(ui->scr_base_cont_ethernet, 23, 14);
    lv_obj_set_size(ui->scr_base_cont_ethernet, 612, 290);
    lv_obj_set_scrollbar_mode(ui->scr_base_cont_ethernet, LV_SCROLLBAR_MODE_OFF);

    //Write style for scr_base_cont_ethernet, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_cont_ethernet, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scr_base_cont_ethernet, 65, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scr_base_cont_ethernet, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scr_base_cont_ethernet, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_cont_ethernet, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_cont_ethernet, 51, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_base_cont_ethernet, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_cont_ethernet, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_cont_ethernet, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_cont_ethernet, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_cont_ethernet, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_cont_ethernet, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_cont_ethernet, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_label_118
    ui->scr_base_label_118 = lv_label_create(ui->scr_base_cont_ethernet);
    lv_obj_set_pos(ui->scr_base_label_118, 23, 108);
    lv_obj_set_size(ui->scr_base_label_118, 161, 17);
    lv_label_set_text(ui->scr_base_label_118, "SUBNET MASK");
    lv_label_set_long_mode(ui->scr_base_label_118, LV_LABEL_LONG_WRAP);

    //Write style for scr_base_label_118, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_label_118, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_label_118, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_base_label_118, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_label_118, &lv_font_Roboto_Bold_15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_label_118, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_base_label_118, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_base_label_118, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_label_118, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_label_118, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_label_118, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_label_118, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_label_118, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_label_118, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_label_118, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for scr_base_label_118, Part: LV_PART_MAIN, State: LV_STATE_DISABLED.
    lv_obj_set_style_border_width(ui->scr_base_label_118, 0, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_radius(ui->scr_base_label_118, 0, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_color(ui->scr_base_label_118, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_font(ui->scr_base_label_118, &lv_font_Roboto_Black_15, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_opa(ui->scr_base_label_118, 49, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_letter_space(ui->scr_base_label_118, 0, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_line_space(ui->scr_base_label_118, 0, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_align(ui->scr_base_label_118, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_bg_opa(ui->scr_base_label_118, 0, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_pad_top(ui->scr_base_label_118, 0, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_pad_right(ui->scr_base_label_118, 0, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_pad_bottom(ui->scr_base_label_118, 0, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_pad_left(ui->scr_base_label_118, 0, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_shadow_width(ui->scr_base_label_118, 0, LV_PART_MAIN|LV_STATE_DISABLED);

    //Write codes scr_base_label_117
    ui->scr_base_label_117 = lv_label_create(ui->scr_base_cont_ethernet);
    lv_obj_set_pos(ui->scr_base_label_117, 312, 108);
    lv_obj_set_size(ui->scr_base_label_117, 161, 13);
    lv_label_set_text(ui->scr_base_label_117, "GATEWAY");
    lv_label_set_long_mode(ui->scr_base_label_117, LV_LABEL_LONG_WRAP);

    //Write style for scr_base_label_117, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_label_117, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_label_117, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_base_label_117, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_label_117, &lv_font_Roboto_Bold_15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_label_117, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_base_label_117, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_base_label_117, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_label_117, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_label_117, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_label_117, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_label_117, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_label_117, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_label_117, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_label_117, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for scr_base_label_117, Part: LV_PART_MAIN, State: LV_STATE_DISABLED.
    lv_obj_set_style_border_width(ui->scr_base_label_117, 0, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_radius(ui->scr_base_label_117, 0, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_color(ui->scr_base_label_117, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_font(ui->scr_base_label_117, &lv_font_Roboto_Black_15, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_opa(ui->scr_base_label_117, 49, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_letter_space(ui->scr_base_label_117, 0, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_line_space(ui->scr_base_label_117, 0, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_align(ui->scr_base_label_117, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_bg_opa(ui->scr_base_label_117, 0, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_pad_top(ui->scr_base_label_117, 0, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_pad_right(ui->scr_base_label_117, 0, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_pad_bottom(ui->scr_base_label_117, 0, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_pad_left(ui->scr_base_label_117, 0, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_shadow_width(ui->scr_base_label_117, 0, LV_PART_MAIN|LV_STATE_DISABLED);

    //Write codes scr_base_ta_ethernet_gateway
    ui->scr_base_ta_ethernet_gateway = lv_textarea_create(ui->scr_base_cont_ethernet);
    lv_obj_set_pos(ui->scr_base_ta_ethernet_gateway, 312, 134);
    lv_obj_set_size(ui->scr_base_ta_ethernet_gateway, 275, 38);
    lv_textarea_set_text(ui->scr_base_ta_ethernet_gateway, "");
    lv_textarea_set_placeholder_text(ui->scr_base_ta_ethernet_gateway, "Enter gateway...");
    lv_textarea_set_password_bullet(ui->scr_base_ta_ethernet_gateway, "*");
    lv_textarea_set_password_mode(ui->scr_base_ta_ethernet_gateway, false);
    lv_textarea_set_one_line(ui->scr_base_ta_ethernet_gateway, true);
    lv_textarea_set_accepted_chars(ui->scr_base_ta_ethernet_gateway, "");
    lv_textarea_set_max_length(ui->scr_base_ta_ethernet_gateway, 32);
#if LV_USE_KEYBOARD
    lv_obj_add_event_cb(ui->scr_base_ta_ethernet_gateway, ta_event_cb, LV_EVENT_ALL, ui->g_kb_top_layer);
#endif

    //Write style for scr_base_ta_ethernet_gateway, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->scr_base_ta_ethernet_gateway, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_ta_ethernet_gateway, &lv_font_Roboto_Regular_14, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_ta_ethernet_gateway, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_base_ta_ethernet_gateway, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_ta_ethernet_gateway, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_ta_ethernet_gateway, 130, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_base_ta_ethernet_gateway, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_ta_ethernet_gateway, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->scr_base_ta_ethernet_gateway, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scr_base_ta_ethernet_gateway, 58, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scr_base_ta_ethernet_gateway, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scr_base_ta_ethernet_gateway, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_ta_ethernet_gateway, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_ta_ethernet_gateway, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_ta_ethernet_gateway, 12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_ta_ethernet_gateway, 12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_ta_ethernet_gateway, 10, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for scr_base_ta_ethernet_gateway, Part: LV_PART_MAIN, State: LV_STATE_FOCUSED.
    lv_obj_set_style_text_color(ui->scr_base_ta_ethernet_gateway, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_font(ui->scr_base_ta_ethernet_gateway, &lv_font_Roboto_Regular_14, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_opa(ui->scr_base_ta_ethernet_gateway, 255, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_opa(ui->scr_base_ta_ethernet_gateway, 130, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_color(ui->scr_base_ta_ethernet_gateway, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_ta_ethernet_gateway, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_width(ui->scr_base_ta_ethernet_gateway, 1, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_opa(ui->scr_base_ta_ethernet_gateway, 53, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_color(ui->scr_base_ta_ethernet_gateway, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_side(ui->scr_base_ta_ethernet_gateway, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_shadow_width(ui->scr_base_ta_ethernet_gateway, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_pad_top(ui->scr_base_ta_ethernet_gateway, 10, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_pad_right(ui->scr_base_ta_ethernet_gateway, 12, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_pad_left(ui->scr_base_ta_ethernet_gateway, 12, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_radius(ui->scr_base_ta_ethernet_gateway, 10, LV_PART_MAIN|LV_STATE_FOCUSED);

    //Write style for scr_base_ta_ethernet_gateway, Part: LV_PART_SCROLLBAR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->scr_base_ta_ethernet_gateway, 255, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_base_ta_ethernet_gateway, lv_color_hex(0x2195f6), LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_ta_ethernet_gateway, LV_GRAD_DIR_NONE, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_ta_ethernet_gateway, 0, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);

    //Write codes scr_base_ta_ethernet_subnet
    ui->scr_base_ta_ethernet_subnet = lv_textarea_create(ui->scr_base_cont_ethernet);
    lv_obj_set_pos(ui->scr_base_ta_ethernet_subnet, 23, 134);
    lv_obj_set_size(ui->scr_base_ta_ethernet_subnet, 275, 38);
    lv_textarea_set_text(ui->scr_base_ta_ethernet_subnet, "");
    lv_textarea_set_placeholder_text(ui->scr_base_ta_ethernet_subnet, "Enter subnet mask...");
    lv_textarea_set_password_bullet(ui->scr_base_ta_ethernet_subnet, "*");
    lv_textarea_set_password_mode(ui->scr_base_ta_ethernet_subnet, false);
    lv_textarea_set_one_line(ui->scr_base_ta_ethernet_subnet, true);
    lv_textarea_set_accepted_chars(ui->scr_base_ta_ethernet_subnet, "");
    lv_textarea_set_max_length(ui->scr_base_ta_ethernet_subnet, 32);
#if LV_USE_KEYBOARD
    lv_obj_add_event_cb(ui->scr_base_ta_ethernet_subnet, ta_event_cb, LV_EVENT_ALL, ui->g_kb_top_layer);
#endif

    //Write style for scr_base_ta_ethernet_subnet, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->scr_base_ta_ethernet_subnet, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_ta_ethernet_subnet, &lv_font_Roboto_Regular_14, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_ta_ethernet_subnet, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_base_ta_ethernet_subnet, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_ta_ethernet_subnet, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_ta_ethernet_subnet, 130, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_base_ta_ethernet_subnet, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_ta_ethernet_subnet, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->scr_base_ta_ethernet_subnet, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scr_base_ta_ethernet_subnet, 58, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scr_base_ta_ethernet_subnet, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scr_base_ta_ethernet_subnet, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_ta_ethernet_subnet, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_ta_ethernet_subnet, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_ta_ethernet_subnet, 12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_ta_ethernet_subnet, 12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_ta_ethernet_subnet, 10, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for scr_base_ta_ethernet_subnet, Part: LV_PART_MAIN, State: LV_STATE_FOCUSED.
    lv_obj_set_style_text_color(ui->scr_base_ta_ethernet_subnet, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_font(ui->scr_base_ta_ethernet_subnet, &lv_font_Roboto_Regular_14, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_opa(ui->scr_base_ta_ethernet_subnet, 255, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_opa(ui->scr_base_ta_ethernet_subnet, 130, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_color(ui->scr_base_ta_ethernet_subnet, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_ta_ethernet_subnet, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_width(ui->scr_base_ta_ethernet_subnet, 1, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_opa(ui->scr_base_ta_ethernet_subnet, 53, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_color(ui->scr_base_ta_ethernet_subnet, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_side(ui->scr_base_ta_ethernet_subnet, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_shadow_width(ui->scr_base_ta_ethernet_subnet, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_pad_top(ui->scr_base_ta_ethernet_subnet, 10, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_pad_right(ui->scr_base_ta_ethernet_subnet, 12, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_pad_left(ui->scr_base_ta_ethernet_subnet, 12, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_radius(ui->scr_base_ta_ethernet_subnet, 10, LV_PART_MAIN|LV_STATE_FOCUSED);

    //Write style for scr_base_ta_ethernet_subnet, Part: LV_PART_SCROLLBAR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->scr_base_ta_ethernet_subnet, 255, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_base_ta_ethernet_subnet, lv_color_hex(0x2195f6), LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_ta_ethernet_subnet, LV_GRAD_DIR_NONE, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_ta_ethernet_subnet, 0, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);

    //Write codes scr_base_label_116
    ui->scr_base_label_116 = lv_label_create(ui->scr_base_cont_ethernet);
    lv_obj_set_pos(ui->scr_base_label_116, 23, 23);
    lv_obj_set_size(ui->scr_base_label_116, 80, 17);
    lv_label_set_text(ui->scr_base_label_116, "MODE");
    lv_label_set_long_mode(ui->scr_base_label_116, LV_LABEL_LONG_WRAP);

    //Write style for scr_base_label_116, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_label_116, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_label_116, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_base_label_116, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_label_116, &lv_font_Roboto_Bold_15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_label_116, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_base_label_116, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_base_label_116, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_label_116, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_label_116, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_label_116, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_label_116, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_label_116, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_label_116, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_label_116, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_label_115
    ui->scr_base_label_115 = lv_label_create(ui->scr_base_cont_ethernet);
    lv_obj_set_pos(ui->scr_base_label_115, 177, 23);
    lv_obj_set_size(ui->scr_base_label_115, 161, 17);
    lv_label_set_text(ui->scr_base_label_115, "IP ADDRESS");
    lv_label_set_long_mode(ui->scr_base_label_115, LV_LABEL_LONG_WRAP);

    //Write style for scr_base_label_115, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_label_115, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_label_115, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_base_label_115, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_label_115, &lv_font_Roboto_Bold_15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_label_115, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_base_label_115, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_base_label_115, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_label_115, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_label_115, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_label_115, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_label_115, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_label_115, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_label_115, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_label_115, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for scr_base_label_115, Part: LV_PART_MAIN, State: LV_STATE_DISABLED.
    lv_obj_set_style_border_width(ui->scr_base_label_115, 0, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_radius(ui->scr_base_label_115, 0, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_color(ui->scr_base_label_115, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_font(ui->scr_base_label_115, &lv_font_Roboto_Black_15, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_opa(ui->scr_base_label_115, 60, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_letter_space(ui->scr_base_label_115, 0, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_line_space(ui->scr_base_label_115, 0, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_align(ui->scr_base_label_115, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_bg_opa(ui->scr_base_label_115, 0, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_pad_top(ui->scr_base_label_115, 0, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_pad_right(ui->scr_base_label_115, 0, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_pad_bottom(ui->scr_base_label_115, 0, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_pad_left(ui->scr_base_label_115, 0, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_shadow_width(ui->scr_base_label_115, 0, LV_PART_MAIN|LV_STATE_DISABLED);

    //Write codes scr_base_ddlist_ethernet_mode
    ui->scr_base_ddlist_ethernet_mode = lv_dropdown_create(ui->scr_base_cont_ethernet);
    lv_obj_set_pos(ui->scr_base_ddlist_ethernet_mode, 23, 48);
    lv_obj_set_size(ui->scr_base_ddlist_ethernet_mode, 140, 38);
    lv_dropdown_set_options(ui->scr_base_ddlist_ethernet_mode, "DHCP\nSTATIC");

    //Write style for scr_base_ddlist_ethernet_mode, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->scr_base_ddlist_ethernet_mode, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_ddlist_ethernet_mode, &lv_font_Roboto_Regular_14, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_ddlist_ethernet_mode, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->scr_base_ddlist_ethernet_mode, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scr_base_ddlist_ethernet_mode, 56, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scr_base_ddlist_ethernet_mode, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scr_base_ddlist_ethernet_mode, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_ddlist_ethernet_mode, 12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_ddlist_ethernet_mode, 12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_ddlist_ethernet_mode, 12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_ddlist_ethernet_mode, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_ddlist_ethernet_mode, 130, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_base_ddlist_ethernet_mode, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_ddlist_ethernet_mode, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_ddlist_ethernet_mode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for scr_base_ddlist_ethernet_mode, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_text_color(ui->scr_base_ddlist_ethernet_mode, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->scr_base_ddlist_ethernet_mode, &lv_font_Roboto_Regular_14, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->scr_base_ddlist_ethernet_mode, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_border_width(ui->scr_base_ddlist_ethernet_mode, 1, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_border_opa(ui->scr_base_ddlist_ethernet_mode, 58, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_border_color(ui->scr_base_ddlist_ethernet_mode, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_border_side(ui->scr_base_ddlist_ethernet_mode, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_pad_top(ui->scr_base_ddlist_ethernet_mode, 12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_pad_left(ui->scr_base_ddlist_ethernet_mode, 12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_pad_right(ui->scr_base_ddlist_ethernet_mode, 12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_radius(ui->scr_base_ddlist_ethernet_mode, 10, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_opa(ui->scr_base_ddlist_ethernet_mode, 129, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui->scr_base_ddlist_ethernet_mode, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_ddlist_ethernet_mode, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->scr_base_ddlist_ethernet_mode, 0, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write style for scr_base_ddlist_ethernet_mode, Part: LV_PART_MAIN, State: LV_STATE_FOCUSED.
    lv_obj_set_style_text_color(ui->scr_base_ddlist_ethernet_mode, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_font(ui->scr_base_ddlist_ethernet_mode, &lv_font_Roboto_Regular_14, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_opa(ui->scr_base_ddlist_ethernet_mode, 255, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_width(ui->scr_base_ddlist_ethernet_mode, 1, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_opa(ui->scr_base_ddlist_ethernet_mode, 70, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_color(ui->scr_base_ddlist_ethernet_mode, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_side(ui->scr_base_ddlist_ethernet_mode, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_pad_top(ui->scr_base_ddlist_ethernet_mode, 12, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_pad_left(ui->scr_base_ddlist_ethernet_mode, 12, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_pad_right(ui->scr_base_ddlist_ethernet_mode, 12, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_radius(ui->scr_base_ddlist_ethernet_mode, 10, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_opa(ui->scr_base_ddlist_ethernet_mode, 130, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_color(ui->scr_base_ddlist_ethernet_mode, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_ddlist_ethernet_mode, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_shadow_width(ui->scr_base_ddlist_ethernet_mode, 0, LV_PART_MAIN|LV_STATE_FOCUSED);

    //Write style for scr_base_ddlist_ethernet_mode, Part: LV_PART_MAIN, State: LV_STATE_DISABLED.
    lv_obj_set_style_text_color(ui->scr_base_ddlist_ethernet_mode, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_font(ui->scr_base_ddlist_ethernet_mode, &lv_font_Roboto_Regular_14, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_opa(ui->scr_base_ddlist_ethernet_mode, 255, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_border_width(ui->scr_base_ddlist_ethernet_mode, 1, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_border_opa(ui->scr_base_ddlist_ethernet_mode, 61, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_border_color(ui->scr_base_ddlist_ethernet_mode, lv_color_hex(0xe1e6ee), LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_border_side(ui->scr_base_ddlist_ethernet_mode, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_pad_top(ui->scr_base_ddlist_ethernet_mode, 12, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_pad_left(ui->scr_base_ddlist_ethernet_mode, 12, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_pad_right(ui->scr_base_ddlist_ethernet_mode, 12, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_radius(ui->scr_base_ddlist_ethernet_mode, 10, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_bg_opa(ui->scr_base_ddlist_ethernet_mode, 130, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_bg_color(ui->scr_base_ddlist_ethernet_mode, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_ddlist_ethernet_mode, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_shadow_width(ui->scr_base_ddlist_ethernet_mode, 0, LV_PART_MAIN|LV_STATE_DISABLED);

    //Write style state: LV_STATE_CHECKED for &style_scr_base_ddlist_ethernet_mode_extra_list_selected_checked
    static lv_style_t style_scr_base_ddlist_ethernet_mode_extra_list_selected_checked;
    ui_init_style(&style_scr_base_ddlist_ethernet_mode_extra_list_selected_checked);

    lv_style_set_border_width(&style_scr_base_ddlist_ethernet_mode_extra_list_selected_checked, 1);
    lv_style_set_border_opa(&style_scr_base_ddlist_ethernet_mode_extra_list_selected_checked, 255);
    lv_style_set_border_color(&style_scr_base_ddlist_ethernet_mode_extra_list_selected_checked, lv_color_hex(0xe1e6ee));
    lv_style_set_border_side(&style_scr_base_ddlist_ethernet_mode_extra_list_selected_checked, LV_BORDER_SIDE_FULL);
    lv_style_set_radius(&style_scr_base_ddlist_ethernet_mode_extra_list_selected_checked, 1);
    lv_style_set_bg_opa(&style_scr_base_ddlist_ethernet_mode_extra_list_selected_checked, 129);
    lv_style_set_bg_color(&style_scr_base_ddlist_ethernet_mode_extra_list_selected_checked, lv_color_hex(0x00a1b5));
    lv_style_set_bg_grad_dir(&style_scr_base_ddlist_ethernet_mode_extra_list_selected_checked, LV_GRAD_DIR_NONE);
    lv_obj_add_style(lv_dropdown_get_list(ui->scr_base_ddlist_ethernet_mode), &style_scr_base_ddlist_ethernet_mode_extra_list_selected_checked, LV_PART_SELECTED|LV_STATE_CHECKED);

    //Write style state: LV_STATE_DEFAULT for &style_scr_base_ddlist_ethernet_mode_extra_list_main_default
    static lv_style_t style_scr_base_ddlist_ethernet_mode_extra_list_main_default;
    ui_init_style(&style_scr_base_ddlist_ethernet_mode_extra_list_main_default);

    lv_style_set_max_height(&style_scr_base_ddlist_ethernet_mode_extra_list_main_default, 90);
    lv_style_set_text_color(&style_scr_base_ddlist_ethernet_mode_extra_list_main_default, lv_color_hex(0xfdfdfd));
    lv_style_set_text_font(&style_scr_base_ddlist_ethernet_mode_extra_list_main_default, &lv_font_Roboto_Regular_14);
    lv_style_set_text_opa(&style_scr_base_ddlist_ethernet_mode_extra_list_main_default, 255);
    lv_style_set_border_width(&style_scr_base_ddlist_ethernet_mode_extra_list_main_default, 1);
    lv_style_set_border_opa(&style_scr_base_ddlist_ethernet_mode_extra_list_main_default, 54);
    lv_style_set_border_color(&style_scr_base_ddlist_ethernet_mode_extra_list_main_default, lv_color_hex(0xffffff));
    lv_style_set_border_side(&style_scr_base_ddlist_ethernet_mode_extra_list_main_default, LV_BORDER_SIDE_FULL);
    lv_style_set_radius(&style_scr_base_ddlist_ethernet_mode_extra_list_main_default, 5);
    lv_style_set_bg_opa(&style_scr_base_ddlist_ethernet_mode_extra_list_main_default, 129);
    lv_style_set_bg_color(&style_scr_base_ddlist_ethernet_mode_extra_list_main_default, lv_color_hex(0x000000));
    lv_style_set_bg_grad_dir(&style_scr_base_ddlist_ethernet_mode_extra_list_main_default, LV_GRAD_DIR_NONE);
    lv_obj_add_style(lv_dropdown_get_list(ui->scr_base_ddlist_ethernet_mode), &style_scr_base_ddlist_ethernet_mode_extra_list_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_DEFAULT for &style_scr_base_ddlist_ethernet_mode_extra_list_scrollbar_default
    static lv_style_t style_scr_base_ddlist_ethernet_mode_extra_list_scrollbar_default;
    ui_init_style(&style_scr_base_ddlist_ethernet_mode_extra_list_scrollbar_default);

    lv_style_set_radius(&style_scr_base_ddlist_ethernet_mode_extra_list_scrollbar_default, 3);
    lv_style_set_bg_opa(&style_scr_base_ddlist_ethernet_mode_extra_list_scrollbar_default, 54);
    lv_style_set_bg_color(&style_scr_base_ddlist_ethernet_mode_extra_list_scrollbar_default, lv_color_hex(0xcccccc));
    lv_style_set_bg_grad_dir(&style_scr_base_ddlist_ethernet_mode_extra_list_scrollbar_default, LV_GRAD_DIR_NONE);
    lv_obj_add_style(lv_dropdown_get_list(ui->scr_base_ddlist_ethernet_mode), &style_scr_base_ddlist_ethernet_mode_extra_list_scrollbar_default, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);

    //Write codes scr_base_ta_ethernet_ip
    ui->scr_base_ta_ethernet_ip = lv_textarea_create(ui->scr_base_cont_ethernet);
    lv_obj_set_pos(ui->scr_base_ta_ethernet_ip, 177, 48);
    lv_obj_set_size(ui->scr_base_ta_ethernet_ip, 410, 38);
    lv_textarea_set_text(ui->scr_base_ta_ethernet_ip, "");
    lv_textarea_set_placeholder_text(ui->scr_base_ta_ethernet_ip, "Enter IP address...");
    lv_textarea_set_password_bullet(ui->scr_base_ta_ethernet_ip, "*");
    lv_textarea_set_password_mode(ui->scr_base_ta_ethernet_ip, false);
    lv_textarea_set_one_line(ui->scr_base_ta_ethernet_ip, true);
    lv_textarea_set_accepted_chars(ui->scr_base_ta_ethernet_ip, "");
    lv_textarea_set_max_length(ui->scr_base_ta_ethernet_ip, 32);
#if LV_USE_KEYBOARD
    lv_obj_add_event_cb(ui->scr_base_ta_ethernet_ip, ta_event_cb, LV_EVENT_ALL, ui->g_kb_top_layer);
#endif

    //Write style for scr_base_ta_ethernet_ip, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->scr_base_ta_ethernet_ip, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_ta_ethernet_ip, &lv_font_Roboto_Regular_14, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_ta_ethernet_ip, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_base_ta_ethernet_ip, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_ta_ethernet_ip, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_ta_ethernet_ip, 130, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_base_ta_ethernet_ip, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_ta_ethernet_ip, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->scr_base_ta_ethernet_ip, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scr_base_ta_ethernet_ip, 58, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scr_base_ta_ethernet_ip, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scr_base_ta_ethernet_ip, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_ta_ethernet_ip, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_ta_ethernet_ip, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_ta_ethernet_ip, 12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_ta_ethernet_ip, 12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_ta_ethernet_ip, 10, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for scr_base_ta_ethernet_ip, Part: LV_PART_MAIN, State: LV_STATE_FOCUSED.
    lv_obj_set_style_text_color(ui->scr_base_ta_ethernet_ip, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_font(ui->scr_base_ta_ethernet_ip, &lv_font_Roboto_Regular_14, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_opa(ui->scr_base_ta_ethernet_ip, 255, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_opa(ui->scr_base_ta_ethernet_ip, 130, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_color(ui->scr_base_ta_ethernet_ip, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_ta_ethernet_ip, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_width(ui->scr_base_ta_ethernet_ip, 1, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_opa(ui->scr_base_ta_ethernet_ip, 53, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_color(ui->scr_base_ta_ethernet_ip, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_side(ui->scr_base_ta_ethernet_ip, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_shadow_width(ui->scr_base_ta_ethernet_ip, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_pad_top(ui->scr_base_ta_ethernet_ip, 10, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_pad_right(ui->scr_base_ta_ethernet_ip, 12, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_pad_left(ui->scr_base_ta_ethernet_ip, 12, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_radius(ui->scr_base_ta_ethernet_ip, 10, LV_PART_MAIN|LV_STATE_FOCUSED);

    //Write style for scr_base_ta_ethernet_ip, Part: LV_PART_SCROLLBAR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->scr_base_ta_ethernet_ip, 255, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_base_ta_ethernet_ip, lv_color_hex(0x2195f6), LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_ta_ethernet_ip, LV_GRAD_DIR_NONE, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_ta_ethernet_ip, 0, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);

    //Write codes scr_base_lbl_ethernet_status
    ui->scr_base_lbl_ethernet_status = lv_label_create(ui->scr_base_cont_ethernet);
    lv_obj_set_pos(ui->scr_base_lbl_ethernet_status, 25, 195);
    lv_obj_set_size(ui->scr_base_lbl_ethernet_status, 560, 17);
    lv_label_set_text(ui->scr_base_lbl_ethernet_status, "Configure your settings to connect to an Ethernet network.");
    lv_label_set_long_mode(ui->scr_base_lbl_ethernet_status, LV_LABEL_LONG_WRAP);

    //Write style for scr_base_lbl_ethernet_status, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_lbl_ethernet_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_lbl_ethernet_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_base_lbl_ethernet_status, lv_color_hex(0x71717A), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_lbl_ethernet_status, &lv_font_Roboto_Regular_15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_lbl_ethernet_status, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_base_lbl_ethernet_status, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_base_lbl_ethernet_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_lbl_ethernet_status, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_lbl_ethernet_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_lbl_ethernet_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_lbl_ethernet_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_lbl_ethernet_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_lbl_ethernet_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_lbl_ethernet_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_btn_ethernet_apply
    ui->scr_base_btn_ethernet_apply = lv_button_create(ui->scr_base_cont_ethernet);
    lv_obj_set_pos(ui->scr_base_btn_ethernet_apply, 23, 230);
    lv_obj_set_size(ui->scr_base_btn_ethernet_apply, 560, 38);
    ui->scr_base_btn_ethernet_apply_label = lv_label_create(ui->scr_base_btn_ethernet_apply);
    lv_label_set_text(ui->scr_base_btn_ethernet_apply_label, "APPLY CONFIG");
    lv_label_set_long_mode(ui->scr_base_btn_ethernet_apply_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->scr_base_btn_ethernet_apply_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->scr_base_btn_ethernet_apply, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->scr_base_btn_ethernet_apply_label, LV_PCT(100));

    //Write style for scr_base_btn_ethernet_apply, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->scr_base_btn_ethernet_apply, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_base_btn_ethernet_apply, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_btn_ethernet_apply, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->scr_base_btn_ethernet_apply, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scr_base_btn_ethernet_apply, 63, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scr_base_btn_ethernet_apply, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scr_base_btn_ethernet_apply, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_btn_ethernet_apply, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_btn_ethernet_apply, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_base_btn_ethernet_apply, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_btn_ethernet_apply, &lv_font_Roboto_Black_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_btn_ethernet_apply, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_btn_ethernet_apply, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for scr_base_btn_ethernet_apply, Part: LV_PART_MAIN, State: LV_STATE_FOCUSED.
    lv_obj_set_style_bg_opa(ui->scr_base_btn_ethernet_apply, 255, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_color(ui->scr_base_btn_ethernet_apply, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_btn_ethernet_apply, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_width(ui->scr_base_btn_ethernet_apply, 1, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_opa(ui->scr_base_btn_ethernet_apply, 255, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_color(ui->scr_base_btn_ethernet_apply, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_side(ui->scr_base_btn_ethernet_apply, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_radius(ui->scr_base_btn_ethernet_apply, 10, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_shadow_width(ui->scr_base_btn_ethernet_apply, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_color(ui->scr_base_btn_ethernet_apply, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_font(ui->scr_base_btn_ethernet_apply, &lv_font_Roboto_Black_16, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_opa(ui->scr_base_btn_ethernet_apply, 255, LV_PART_MAIN|LV_STATE_FOCUSED);

    //Write style for scr_base_btn_ethernet_apply, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_bg_opa(ui->scr_base_btn_ethernet_apply, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_bg_color(ui->scr_base_btn_ethernet_apply, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_btn_ethernet_apply, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui->scr_base_btn_ethernet_apply, 1, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_border_opa(ui->scr_base_btn_ethernet_apply, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_border_color(ui->scr_base_btn_ethernet_apply, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_border_side(ui->scr_base_btn_ethernet_apply, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_radius(ui->scr_base_btn_ethernet_apply, 10, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->scr_base_btn_ethernet_apply, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->scr_base_btn_ethernet_apply, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->scr_base_btn_ethernet_apply, &lv_font_Roboto_Black_16, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->scr_base_btn_ethernet_apply, 255, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for scr_base_btn_ethernet_apply, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_bg_opa(ui->scr_base_btn_ethernet_apply, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui->scr_base_btn_ethernet_apply, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_btn_ethernet_apply, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_border_width(ui->scr_base_btn_ethernet_apply, 1, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_border_opa(ui->scr_base_btn_ethernet_apply, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_border_color(ui->scr_base_btn_ethernet_apply, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_border_side(ui->scr_base_btn_ethernet_apply, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_radius(ui->scr_base_btn_ethernet_apply, 10, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->scr_base_btn_ethernet_apply, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->scr_base_btn_ethernet_apply, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->scr_base_btn_ethernet_apply, &lv_font_Roboto_Black_16, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->scr_base_btn_ethernet_apply, 255, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write style for scr_base_btn_ethernet_apply, Part: LV_PART_MAIN, State: LV_STATE_DISABLED.
    lv_obj_set_style_bg_opa(ui->scr_base_btn_ethernet_apply, 255, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_bg_color(ui->scr_base_btn_ethernet_apply, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_btn_ethernet_apply, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_border_width(ui->scr_base_btn_ethernet_apply, 1, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_border_opa(ui->scr_base_btn_ethernet_apply, 255, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_border_color(ui->scr_base_btn_ethernet_apply, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_border_side(ui->scr_base_btn_ethernet_apply, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_radius(ui->scr_base_btn_ethernet_apply, 10, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_shadow_width(ui->scr_base_btn_ethernet_apply, 0, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_color(ui->scr_base_btn_ethernet_apply, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_font(ui->scr_base_btn_ethernet_apply, &lv_font_Roboto_Black_16, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_opa(ui->scr_base_btn_ethernet_apply, 255, LV_PART_MAIN|LV_STATE_DISABLED);

    //Write codes scr_base_cont_lte
    ui->scr_base_cont_lte = lv_obj_create(ui->scr_base_cont_40);
    lv_obj_set_pos(ui->scr_base_cont_lte, 23, 14);
    lv_obj_set_size(ui->scr_base_cont_lte, 612, 290);
    lv_obj_set_scrollbar_mode(ui->scr_base_cont_lte, LV_SCROLLBAR_MODE_OFF);
    lv_obj_add_flag(ui->scr_base_cont_lte, LV_OBJ_FLAG_HIDDEN);

    //Write style for scr_base_cont_lte, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_cont_lte, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scr_base_cont_lte, 65, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scr_base_cont_lte, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scr_base_cont_lte, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_cont_lte, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_cont_lte, 51, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_base_cont_lte, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_cont_lte, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_cont_lte, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_cont_lte, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_cont_lte, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_cont_lte, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_cont_lte, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_label_124
    ui->scr_base_label_124 = lv_label_create(ui->scr_base_cont_lte);
    lv_obj_set_pos(ui->scr_base_label_124, 23, 20);
    lv_obj_set_size(ui->scr_base_label_124, 161, 17);
    lv_label_set_text(ui->scr_base_label_124, "APN NAME");
    lv_label_set_long_mode(ui->scr_base_label_124, LV_LABEL_LONG_WRAP);

    //Write style for scr_base_label_124, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_label_124, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_label_124, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_base_label_124, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_label_124, &lv_font_Roboto_Bold_15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_label_124, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_base_label_124, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_base_label_124, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_label_124, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_label_124, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_label_124, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_label_124, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_label_124, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_label_124, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_label_124, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_label_123
    ui->scr_base_label_123 = lv_label_create(ui->scr_base_cont_lte);
    lv_obj_set_pos(ui->scr_base_label_123, 312, 21);
    lv_obj_set_size(ui->scr_base_label_123, 161, 13);
    lv_label_set_text(ui->scr_base_label_123, "SIM PIN CODE");
    lv_label_set_long_mode(ui->scr_base_label_123, LV_LABEL_LONG_WRAP);

    //Write style for scr_base_label_123, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_label_123, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_label_123, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_base_label_123, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_label_123, &lv_font_Roboto_Bold_15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_label_123, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_base_label_123, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_base_label_123, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_label_123, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_label_123, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_label_123, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_label_123, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_label_123, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_label_123, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_label_123, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_ta_lte_pin_code
    ui->scr_base_ta_lte_pin_code = lv_textarea_create(ui->scr_base_cont_lte);
    lv_obj_set_pos(ui->scr_base_ta_lte_pin_code, 312, 46);
    lv_obj_set_size(ui->scr_base_ta_lte_pin_code, 275, 38);
    lv_textarea_set_text(ui->scr_base_ta_lte_pin_code, "");
    lv_textarea_set_placeholder_text(ui->scr_base_ta_lte_pin_code, "Enter sim pin code...");
    lv_textarea_set_password_bullet(ui->scr_base_ta_lte_pin_code, "*");
    lv_textarea_set_password_mode(ui->scr_base_ta_lte_pin_code, false);
    lv_textarea_set_one_line(ui->scr_base_ta_lte_pin_code, true);
    lv_textarea_set_accepted_chars(ui->scr_base_ta_lte_pin_code, "");
    lv_textarea_set_max_length(ui->scr_base_ta_lte_pin_code, 32);
#if LV_USE_KEYBOARD
    lv_obj_add_event_cb(ui->scr_base_ta_lte_pin_code, ta_event_cb, LV_EVENT_ALL, ui->g_kb_top_layer);
#endif

    //Write style for scr_base_ta_lte_pin_code, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->scr_base_ta_lte_pin_code, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_ta_lte_pin_code, &lv_font_Roboto_Regular_14, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_ta_lte_pin_code, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_base_ta_lte_pin_code, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_ta_lte_pin_code, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_ta_lte_pin_code, 130, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_base_ta_lte_pin_code, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_ta_lte_pin_code, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->scr_base_ta_lte_pin_code, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scr_base_ta_lte_pin_code, 58, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scr_base_ta_lte_pin_code, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scr_base_ta_lte_pin_code, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_ta_lte_pin_code, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_ta_lte_pin_code, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_ta_lte_pin_code, 12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_ta_lte_pin_code, 12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_ta_lte_pin_code, 10, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for scr_base_ta_lte_pin_code, Part: LV_PART_MAIN, State: LV_STATE_FOCUSED.
    lv_obj_set_style_text_color(ui->scr_base_ta_lte_pin_code, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_font(ui->scr_base_ta_lte_pin_code, &lv_font_Roboto_Regular_14, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_opa(ui->scr_base_ta_lte_pin_code, 255, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_opa(ui->scr_base_ta_lte_pin_code, 130, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_color(ui->scr_base_ta_lte_pin_code, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_ta_lte_pin_code, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_width(ui->scr_base_ta_lte_pin_code, 1, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_opa(ui->scr_base_ta_lte_pin_code, 53, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_color(ui->scr_base_ta_lte_pin_code, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_side(ui->scr_base_ta_lte_pin_code, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_shadow_width(ui->scr_base_ta_lte_pin_code, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_pad_top(ui->scr_base_ta_lte_pin_code, 10, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_pad_right(ui->scr_base_ta_lte_pin_code, 12, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_pad_left(ui->scr_base_ta_lte_pin_code, 12, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_radius(ui->scr_base_ta_lte_pin_code, 10, LV_PART_MAIN|LV_STATE_FOCUSED);

    //Write style for scr_base_ta_lte_pin_code, Part: LV_PART_SCROLLBAR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->scr_base_ta_lte_pin_code, 255, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_base_ta_lte_pin_code, lv_color_hex(0x2195f6), LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_ta_lte_pin_code, LV_GRAD_DIR_NONE, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_ta_lte_pin_code, 0, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);

    //Write codes scr_base_ta_lte_apn
    ui->scr_base_ta_lte_apn = lv_textarea_create(ui->scr_base_cont_lte);
    lv_obj_set_pos(ui->scr_base_ta_lte_apn, 23, 46);
    lv_obj_set_size(ui->scr_base_ta_lte_apn, 275, 38);
    lv_textarea_set_text(ui->scr_base_ta_lte_apn, "");
    lv_textarea_set_placeholder_text(ui->scr_base_ta_lte_apn, "Enter APN...");
    lv_textarea_set_password_bullet(ui->scr_base_ta_lte_apn, "*");
    lv_textarea_set_password_mode(ui->scr_base_ta_lte_apn, false);
    lv_textarea_set_one_line(ui->scr_base_ta_lte_apn, true);
    lv_textarea_set_accepted_chars(ui->scr_base_ta_lte_apn, "");
    lv_textarea_set_max_length(ui->scr_base_ta_lte_apn, 32);
#if LV_USE_KEYBOARD
    lv_obj_add_event_cb(ui->scr_base_ta_lte_apn, ta_event_cb, LV_EVENT_ALL, ui->g_kb_top_layer);
#endif

    //Write style for scr_base_ta_lte_apn, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->scr_base_ta_lte_apn, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_ta_lte_apn, &lv_font_Roboto_Regular_14, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_ta_lte_apn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_base_ta_lte_apn, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_ta_lte_apn, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_ta_lte_apn, 130, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_base_ta_lte_apn, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_ta_lte_apn, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->scr_base_ta_lte_apn, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scr_base_ta_lte_apn, 58, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scr_base_ta_lte_apn, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scr_base_ta_lte_apn, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_ta_lte_apn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_ta_lte_apn, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_ta_lte_apn, 12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_ta_lte_apn, 12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_ta_lte_apn, 10, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for scr_base_ta_lte_apn, Part: LV_PART_MAIN, State: LV_STATE_FOCUSED.
    lv_obj_set_style_text_color(ui->scr_base_ta_lte_apn, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_font(ui->scr_base_ta_lte_apn, &lv_font_Roboto_Regular_14, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_opa(ui->scr_base_ta_lte_apn, 255, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_opa(ui->scr_base_ta_lte_apn, 130, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_color(ui->scr_base_ta_lte_apn, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_ta_lte_apn, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_width(ui->scr_base_ta_lte_apn, 1, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_opa(ui->scr_base_ta_lte_apn, 53, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_color(ui->scr_base_ta_lte_apn, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_side(ui->scr_base_ta_lte_apn, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_shadow_width(ui->scr_base_ta_lte_apn, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_pad_top(ui->scr_base_ta_lte_apn, 10, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_pad_right(ui->scr_base_ta_lte_apn, 12, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_pad_left(ui->scr_base_ta_lte_apn, 12, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_radius(ui->scr_base_ta_lte_apn, 10, LV_PART_MAIN|LV_STATE_FOCUSED);

    //Write style for scr_base_ta_lte_apn, Part: LV_PART_SCROLLBAR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->scr_base_ta_lte_apn, 255, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_base_ta_lte_apn, lv_color_hex(0x2195f6), LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_ta_lte_apn, LV_GRAD_DIR_NONE, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_ta_lte_apn, 0, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);

    //Write codes scr_base_label_122
    ui->scr_base_label_122 = lv_label_create(ui->scr_base_cont_lte);
    lv_obj_set_pos(ui->scr_base_label_122, 23, 108);
    lv_obj_set_size(ui->scr_base_label_122, 90, 17);
    lv_label_set_text(ui->scr_base_label_122, "USERNAME");
    lv_label_set_long_mode(ui->scr_base_label_122, LV_LABEL_LONG_WRAP);

    //Write style for scr_base_label_122, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_label_122, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_label_122, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_base_label_122, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_label_122, &lv_font_Roboto_Bold_15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_label_122, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_base_label_122, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_base_label_122, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_label_122, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_label_122, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_label_122, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_label_122, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_label_122, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_label_122, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_label_122, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_label_121
    ui->scr_base_label_121 = lv_label_create(ui->scr_base_cont_lte);
    lv_obj_set_pos(ui->scr_base_label_121, 312, 109);
    lv_obj_set_size(ui->scr_base_label_121, 90, 17);
    lv_label_set_text(ui->scr_base_label_121, "PASSWORD");
    lv_label_set_long_mode(ui->scr_base_label_121, LV_LABEL_LONG_WRAP);

    //Write style for scr_base_label_121, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_label_121, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_label_121, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_base_label_121, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_label_121, &lv_font_Roboto_Bold_15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_label_121, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_base_label_121, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_base_label_121, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_label_121, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_label_121, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_label_121, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_label_121, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_label_121, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_label_121, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_label_121, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_ta_lte_pass
    ui->scr_base_ta_lte_pass = lv_textarea_create(ui->scr_base_cont_lte);
    lv_obj_set_pos(ui->scr_base_ta_lte_pass, 312, 134);
    lv_obj_set_size(ui->scr_base_ta_lte_pass, 275, 38);
    lv_textarea_set_text(ui->scr_base_ta_lte_pass, "");
    lv_textarea_set_placeholder_text(ui->scr_base_ta_lte_pass, "Enter password...");
    lv_textarea_set_password_bullet(ui->scr_base_ta_lte_pass, "*");
    lv_textarea_set_password_mode(ui->scr_base_ta_lte_pass, true);
    lv_textarea_set_one_line(ui->scr_base_ta_lte_pass, true);
    lv_textarea_set_accepted_chars(ui->scr_base_ta_lte_pass, "");
    lv_textarea_set_max_length(ui->scr_base_ta_lte_pass, 32);
#if LV_USE_KEYBOARD
    lv_obj_add_event_cb(ui->scr_base_ta_lte_pass, ta_event_cb, LV_EVENT_ALL, ui->g_kb_top_layer);
#endif

    //Write style for scr_base_ta_lte_pass, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->scr_base_ta_lte_pass, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_ta_lte_pass, &lv_font_Roboto_Regular_14, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_ta_lte_pass, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_base_ta_lte_pass, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_ta_lte_pass, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_ta_lte_pass, 130, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_base_ta_lte_pass, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_ta_lte_pass, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->scr_base_ta_lte_pass, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scr_base_ta_lte_pass, 58, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scr_base_ta_lte_pass, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scr_base_ta_lte_pass, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_ta_lte_pass, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_ta_lte_pass, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_ta_lte_pass, 12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_ta_lte_pass, 12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_ta_lte_pass, 10, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for scr_base_ta_lte_pass, Part: LV_PART_MAIN, State: LV_STATE_FOCUSED.
    lv_obj_set_style_text_color(ui->scr_base_ta_lte_pass, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_font(ui->scr_base_ta_lte_pass, &lv_font_Roboto_Regular_14, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_opa(ui->scr_base_ta_lte_pass, 255, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_opa(ui->scr_base_ta_lte_pass, 130, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_color(ui->scr_base_ta_lte_pass, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_ta_lte_pass, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_width(ui->scr_base_ta_lte_pass, 1, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_opa(ui->scr_base_ta_lte_pass, 53, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_color(ui->scr_base_ta_lte_pass, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_side(ui->scr_base_ta_lte_pass, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_shadow_width(ui->scr_base_ta_lte_pass, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_pad_top(ui->scr_base_ta_lte_pass, 10, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_pad_right(ui->scr_base_ta_lte_pass, 12, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_pad_left(ui->scr_base_ta_lte_pass, 12, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_radius(ui->scr_base_ta_lte_pass, 10, LV_PART_MAIN|LV_STATE_FOCUSED);

    //Write style for scr_base_ta_lte_pass, Part: LV_PART_SCROLLBAR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->scr_base_ta_lte_pass, 255, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_base_ta_lte_pass, lv_color_hex(0x2195f6), LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_ta_lte_pass, LV_GRAD_DIR_NONE, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_ta_lte_pass, 0, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);

    //Write codes scr_base_lbl_lte_status
    ui->scr_base_lbl_lte_status = lv_label_create(ui->scr_base_cont_lte);
    lv_obj_set_pos(ui->scr_base_lbl_lte_status, 27, 198);
    lv_obj_set_size(ui->scr_base_lbl_lte_status, 560, 17);
    lv_label_set_text(ui->scr_base_lbl_lte_status, "Configure your settings to connect to an LTE network.");
    lv_label_set_long_mode(ui->scr_base_lbl_lte_status, LV_LABEL_LONG_WRAP);

    //Write style for scr_base_lbl_lte_status, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_lbl_lte_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_lbl_lte_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_base_lbl_lte_status, lv_color_hex(0x71717A), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_lbl_lte_status, &lv_font_Roboto_Regular_15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_lbl_lte_status, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_base_lbl_lte_status, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_base_lbl_lte_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_lbl_lte_status, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_lbl_lte_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_lbl_lte_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_lbl_lte_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_lbl_lte_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_lbl_lte_status, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_lbl_lte_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_btn_lte_apply
    ui->scr_base_btn_lte_apply = lv_button_create(ui->scr_base_cont_lte);
    lv_obj_set_pos(ui->scr_base_btn_lte_apply, 23, 236);
    lv_obj_set_size(ui->scr_base_btn_lte_apply, 560, 38);
    ui->scr_base_btn_lte_apply_label = lv_label_create(ui->scr_base_btn_lte_apply);
    lv_label_set_text(ui->scr_base_btn_lte_apply_label, "APPLY CONFIG");
    lv_label_set_long_mode(ui->scr_base_btn_lte_apply_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->scr_base_btn_lte_apply_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->scr_base_btn_lte_apply, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->scr_base_btn_lte_apply_label, LV_PCT(100));

    //Write style for scr_base_btn_lte_apply, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->scr_base_btn_lte_apply, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_base_btn_lte_apply, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_btn_lte_apply, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->scr_base_btn_lte_apply, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scr_base_btn_lte_apply, 63, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scr_base_btn_lte_apply, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scr_base_btn_lte_apply, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_btn_lte_apply, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_btn_lte_apply, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_base_btn_lte_apply, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_btn_lte_apply, &lv_font_Roboto_Black_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_btn_lte_apply, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_btn_lte_apply, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for scr_base_btn_lte_apply, Part: LV_PART_MAIN, State: LV_STATE_FOCUSED.
    lv_obj_set_style_bg_opa(ui->scr_base_btn_lte_apply, 255, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_color(ui->scr_base_btn_lte_apply, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_btn_lte_apply, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_width(ui->scr_base_btn_lte_apply, 1, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_opa(ui->scr_base_btn_lte_apply, 255, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_color(ui->scr_base_btn_lte_apply, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_side(ui->scr_base_btn_lte_apply, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_radius(ui->scr_base_btn_lte_apply, 10, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_shadow_width(ui->scr_base_btn_lte_apply, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_color(ui->scr_base_btn_lte_apply, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_font(ui->scr_base_btn_lte_apply, &lv_font_Roboto_Black_16, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_opa(ui->scr_base_btn_lte_apply, 255, LV_PART_MAIN|LV_STATE_FOCUSED);

    //Write style for scr_base_btn_lte_apply, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_bg_opa(ui->scr_base_btn_lte_apply, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_bg_color(ui->scr_base_btn_lte_apply, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_btn_lte_apply, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui->scr_base_btn_lte_apply, 1, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_border_opa(ui->scr_base_btn_lte_apply, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_border_color(ui->scr_base_btn_lte_apply, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_border_side(ui->scr_base_btn_lte_apply, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_radius(ui->scr_base_btn_lte_apply, 10, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->scr_base_btn_lte_apply, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->scr_base_btn_lte_apply, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->scr_base_btn_lte_apply, &lv_font_Roboto_Black_16, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->scr_base_btn_lte_apply, 255, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for scr_base_btn_lte_apply, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_bg_opa(ui->scr_base_btn_lte_apply, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui->scr_base_btn_lte_apply, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_btn_lte_apply, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_border_width(ui->scr_base_btn_lte_apply, 1, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_border_opa(ui->scr_base_btn_lte_apply, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_border_color(ui->scr_base_btn_lte_apply, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_border_side(ui->scr_base_btn_lte_apply, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_radius(ui->scr_base_btn_lte_apply, 10, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->scr_base_btn_lte_apply, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->scr_base_btn_lte_apply, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->scr_base_btn_lte_apply, &lv_font_Roboto_Black_16, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->scr_base_btn_lte_apply, 255, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write style for scr_base_btn_lte_apply, Part: LV_PART_MAIN, State: LV_STATE_DISABLED.
    lv_obj_set_style_bg_opa(ui->scr_base_btn_lte_apply, 255, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_bg_color(ui->scr_base_btn_lte_apply, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_btn_lte_apply, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_border_width(ui->scr_base_btn_lte_apply, 1, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_border_opa(ui->scr_base_btn_lte_apply, 255, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_border_color(ui->scr_base_btn_lte_apply, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_border_side(ui->scr_base_btn_lte_apply, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_radius(ui->scr_base_btn_lte_apply, 10, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_shadow_width(ui->scr_base_btn_lte_apply, 0, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_color(ui->scr_base_btn_lte_apply, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_font(ui->scr_base_btn_lte_apply, &lv_font_Roboto_Black_16, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_opa(ui->scr_base_btn_lte_apply, 255, LV_PART_MAIN|LV_STATE_DISABLED);

    //Write codes scr_base_ta_lte_username
    ui->scr_base_ta_lte_username = lv_textarea_create(ui->scr_base_cont_lte);
    lv_obj_set_pos(ui->scr_base_ta_lte_username, 23, 134);
    lv_obj_set_size(ui->scr_base_ta_lte_username, 275, 38);
    lv_textarea_set_text(ui->scr_base_ta_lte_username, "");
    lv_textarea_set_placeholder_text(ui->scr_base_ta_lte_username, "Enter username...");
    lv_textarea_set_password_bullet(ui->scr_base_ta_lte_username, "*");
    lv_textarea_set_password_mode(ui->scr_base_ta_lte_username, false);
    lv_textarea_set_one_line(ui->scr_base_ta_lte_username, true);
    lv_textarea_set_accepted_chars(ui->scr_base_ta_lte_username, "");
    lv_textarea_set_max_length(ui->scr_base_ta_lte_username, 32);
#if LV_USE_KEYBOARD
    lv_obj_add_event_cb(ui->scr_base_ta_lte_username, ta_event_cb, LV_EVENT_ALL, ui->g_kb_top_layer);
#endif

    //Write style for scr_base_ta_lte_username, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->scr_base_ta_lte_username, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_ta_lte_username, &lv_font_Roboto_Regular_14, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_ta_lte_username, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_base_ta_lte_username, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_ta_lte_username, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_ta_lte_username, 130, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_base_ta_lte_username, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_ta_lte_username, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->scr_base_ta_lte_username, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scr_base_ta_lte_username, 58, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scr_base_ta_lte_username, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scr_base_ta_lte_username, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_ta_lte_username, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_ta_lte_username, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_ta_lte_username, 12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_ta_lte_username, 12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_ta_lte_username, 10, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for scr_base_ta_lte_username, Part: LV_PART_MAIN, State: LV_STATE_FOCUSED.
    lv_obj_set_style_text_color(ui->scr_base_ta_lte_username, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_font(ui->scr_base_ta_lte_username, &lv_font_Roboto_Regular_14, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_opa(ui->scr_base_ta_lte_username, 255, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_opa(ui->scr_base_ta_lte_username, 130, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_color(ui->scr_base_ta_lte_username, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_ta_lte_username, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_width(ui->scr_base_ta_lte_username, 1, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_opa(ui->scr_base_ta_lte_username, 53, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_color(ui->scr_base_ta_lte_username, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_side(ui->scr_base_ta_lte_username, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_shadow_width(ui->scr_base_ta_lte_username, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_pad_top(ui->scr_base_ta_lte_username, 10, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_pad_right(ui->scr_base_ta_lte_username, 12, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_pad_left(ui->scr_base_ta_lte_username, 12, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_radius(ui->scr_base_ta_lte_username, 10, LV_PART_MAIN|LV_STATE_FOCUSED);

    //Write style for scr_base_ta_lte_username, Part: LV_PART_SCROLLBAR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->scr_base_ta_lte_username, 255, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_base_ta_lte_username, lv_color_hex(0x2195f6), LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_ta_lte_username, LV_GRAD_DIR_NONE, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_ta_lte_username, 0, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);

    //Write codes scr_base_label_125
    ui->scr_base_label_125 = lv_label_create(ui->scr_base_cont_lte);
    lv_obj_set_pos(ui->scr_base_label_125, 115, 110);
    lv_obj_set_size(ui->scr_base_label_125, 80, 12);
    lv_label_set_text(ui->scr_base_label_125, "(OPTIONAL)");
    lv_label_set_long_mode(ui->scr_base_label_125, LV_LABEL_LONG_WRAP);

    //Write style for scr_base_label_125, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_label_125, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_label_125, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_base_label_125, lv_color_hex(0x71717A), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_label_125, &lv_font_Roboto_Black_10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_label_125, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_base_label_125, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_base_label_125, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_label_125, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_label_125, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_label_125, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_label_125, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_label_125, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_label_125, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_label_125, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_label_126
    ui->scr_base_label_126 = lv_label_create(ui->scr_base_cont_lte);
    lv_obj_set_pos(ui->scr_base_label_126, 404, 111);
    lv_obj_set_size(ui->scr_base_label_126, 80, 12);
    lv_label_set_text(ui->scr_base_label_126, "(OPTIONAL)");
    lv_label_set_long_mode(ui->scr_base_label_126, LV_LABEL_LONG_WRAP);

    //Write style for scr_base_label_126, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_label_126, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_label_126, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_base_label_126, lv_color_hex(0x71717A), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_label_126, &lv_font_Roboto_Black_10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_label_126, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_base_label_126, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_base_label_126, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_label_126, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_label_126, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_label_126, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_label_126, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_label_126, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_label_126, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_label_126, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_cont_mqtt_config
    ui->scr_base_cont_mqtt_config = lv_obj_create(ui->scr_base_cont_hw);
    lv_obj_set_pos(ui->scr_base_cont_mqtt_config, 0, 35);
    lv_obj_set_size(ui->scr_base_cont_mqtt_config, 677, 380);
    lv_obj_set_scrollbar_mode(ui->scr_base_cont_mqtt_config, LV_SCROLLBAR_MODE_OFF);
    lv_obj_add_flag(ui->scr_base_cont_mqtt_config, LV_OBJ_FLAG_HIDDEN);

    //Write style for scr_base_cont_mqtt_config, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_cont_mqtt_config, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_cont_mqtt_config, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_cont_mqtt_config, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_cont_mqtt_config, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_cont_mqtt_config, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_cont_mqtt_config, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_cont_mqtt_config, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_cont_mqtt_config, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_cont_mqtt_back
    ui->scr_base_cont_mqtt_back = lv_obj_create(ui->scr_base_cont_mqtt_config);
    lv_obj_set_pos(ui->scr_base_cont_mqtt_back, 0, 5);
    lv_obj_set_size(ui->scr_base_cont_mqtt_back, 40, 40);
    lv_obj_set_scrollbar_mode(ui->scr_base_cont_mqtt_back, LV_SCROLLBAR_MODE_OFF);

    //Write style for scr_base_cont_mqtt_back, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_cont_mqtt_back, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scr_base_cont_mqtt_back, 71, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scr_base_cont_mqtt_back, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scr_base_cont_mqtt_back, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_cont_mqtt_back, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_cont_mqtt_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_cont_mqtt_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_cont_mqtt_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_cont_mqtt_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_cont_mqtt_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_cont_mqtt_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_img_19
    ui->scr_base_img_19 = lv_image_create(ui->scr_base_cont_mqtt_back);
    lv_obj_set_pos(ui->scr_base_img_19, 7, 7);
    lv_obj_set_size(ui->scr_base_img_19, 24, 24);
    lv_obj_add_flag(ui->scr_base_img_19, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->scr_base_img_19, &_left_arrow_RGB565A8_24x24);
    lv_image_set_pivot(ui->scr_base_img_19, 50,50);
    lv_image_set_rotation(ui->scr_base_img_19, 0);

    //Write style for scr_base_img_19, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->scr_base_img_19, 189, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_recolor(ui->scr_base_img_19, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->scr_base_img_19, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_btn_mqtt_back
    ui->scr_base_btn_mqtt_back = lv_button_create(ui->scr_base_cont_mqtt_back);
    lv_obj_set_pos(ui->scr_base_btn_mqtt_back, -6, -6);
    lv_obj_set_size(ui->scr_base_btn_mqtt_back, 50, 50);
    ui->scr_base_btn_mqtt_back_label = lv_label_create(ui->scr_base_btn_mqtt_back);
    lv_label_set_text(ui->scr_base_btn_mqtt_back_label, "");
    lv_label_set_long_mode(ui->scr_base_btn_mqtt_back_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->scr_base_btn_mqtt_back_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->scr_base_btn_mqtt_back, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->scr_base_btn_mqtt_back_label, LV_PCT(100));

    //Write style for scr_base_btn_mqtt_back, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->scr_base_btn_mqtt_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->scr_base_btn_mqtt_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_btn_mqtt_back, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_btn_mqtt_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_base_btn_mqtt_back, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_btn_mqtt_back, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_btn_mqtt_back, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_btn_mqtt_back, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for scr_base_btn_mqtt_back, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_bg_opa(ui->scr_base_btn_mqtt_back, 42, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_bg_color(ui->scr_base_btn_mqtt_back, lv_color_hex(0x10B981), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_btn_mqtt_back, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui->scr_base_btn_mqtt_back, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_radius(ui->scr_base_btn_mqtt_back, 10, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->scr_base_btn_mqtt_back, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->scr_base_btn_mqtt_back, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->scr_base_btn_mqtt_back, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->scr_base_btn_mqtt_back, 255, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for scr_base_btn_mqtt_back, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_bg_opa(ui->scr_base_btn_mqtt_back, 44, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui->scr_base_btn_mqtt_back, lv_color_hex(0x10B981), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_btn_mqtt_back, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_border_width(ui->scr_base_btn_mqtt_back, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_radius(ui->scr_base_btn_mqtt_back, 10, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->scr_base_btn_mqtt_back, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->scr_base_btn_mqtt_back, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->scr_base_btn_mqtt_back, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->scr_base_btn_mqtt_back, 255, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write codes scr_base_label_147
    ui->scr_base_label_147 = lv_label_create(ui->scr_base_cont_mqtt_config);
    lv_obj_set_pos(ui->scr_base_label_147, 44, 16);
    lv_obj_set_size(ui->scr_base_label_147, 267, 17);
    lv_label_set_text(ui->scr_base_label_147, "MQTT PROTOCOL SETUP");
    lv_label_set_long_mode(ui->scr_base_label_147, LV_LABEL_LONG_WRAP);

    //Write style for scr_base_label_147, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_label_147, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_label_147, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_base_label_147, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_label_147, &lv_font_Roboto_Bold_15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_label_147, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_base_label_147, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_base_label_147, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_label_147, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_label_147, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_label_147, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_label_147, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_label_147, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_label_147, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_label_147, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_cont_47
    ui->scr_base_cont_47 = lv_obj_create(ui->scr_base_cont_mqtt_config);
    lv_obj_set_pos(ui->scr_base_cont_47, 0, 55);
    lv_obj_set_size(ui->scr_base_cont_47, 660, 320);
    lv_obj_set_scrollbar_mode(ui->scr_base_cont_47, LV_SCROLLBAR_MODE_OFF);

    //Write style for scr_base_cont_47, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_cont_47, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scr_base_cont_47, 65, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scr_base_cont_47, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scr_base_cont_47, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_cont_47, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_cont_47, 243, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_base_cont_47, lv_color_hex(0x0F172A), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_cont_47, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_cont_47, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_cont_47, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_cont_47, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_cont_47, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_cont_47, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_cont_48
    ui->scr_base_cont_48 = lv_obj_create(ui->scr_base_cont_47);
    lv_obj_set_pos(ui->scr_base_cont_48, 23, 14);
    lv_obj_set_size(ui->scr_base_cont_48, 612, 290);
    lv_obj_set_scrollbar_mode(ui->scr_base_cont_48, LV_SCROLLBAR_MODE_OFF);

    //Write style for scr_base_cont_48, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_cont_48, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scr_base_cont_48, 65, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scr_base_cont_48, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scr_base_cont_48, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_cont_48, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_cont_48, 51, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_base_cont_48, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_cont_48, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_cont_48, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_cont_48, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_cont_48, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_cont_48, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_cont_48, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_label_134
    ui->scr_base_label_134 = lv_label_create(ui->scr_base_cont_48);
    lv_obj_set_pos(ui->scr_base_label_134, 23, 21);
    lv_obj_set_size(ui->scr_base_label_134, 161, 17);
    lv_label_set_text(ui->scr_base_label_134, "HOST");
    lv_label_set_long_mode(ui->scr_base_label_134, LV_LABEL_LONG_WRAP);

    //Write style for scr_base_label_134, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_label_134, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_label_134, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_base_label_134, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_label_134, &lv_font_Roboto_Bold_15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_label_134, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_base_label_134, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_base_label_134, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_label_134, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_label_134, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_label_134, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_label_134, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_label_134, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_label_134, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_label_134, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_label_133
    ui->scr_base_label_133 = lv_label_create(ui->scr_base_cont_48);
    lv_obj_set_pos(ui->scr_base_label_133, 312, 22);
    lv_obj_set_size(ui->scr_base_label_133, 161, 13);
    lv_label_set_text(ui->scr_base_label_133, "PORT");
    lv_label_set_long_mode(ui->scr_base_label_133, LV_LABEL_LONG_WRAP);

    //Write style for scr_base_label_133, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_label_133, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_label_133, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_base_label_133, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_label_133, &lv_font_Roboto_Bold_15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_label_133, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_base_label_133, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_base_label_133, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_label_133, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_label_133, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_label_133, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_label_133, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_label_133, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_label_133, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_label_133, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_ta_mqtt_port
    ui->scr_base_ta_mqtt_port = lv_textarea_create(ui->scr_base_cont_48);
    lv_obj_set_pos(ui->scr_base_ta_mqtt_port, 312, 47);
    lv_obj_set_size(ui->scr_base_ta_mqtt_port, 275, 38);
    lv_textarea_set_text(ui->scr_base_ta_mqtt_port, "");
    lv_textarea_set_placeholder_text(ui->scr_base_ta_mqtt_port, "Enter port...");
    lv_textarea_set_password_bullet(ui->scr_base_ta_mqtt_port, "*");
    lv_textarea_set_password_mode(ui->scr_base_ta_mqtt_port, false);
    lv_textarea_set_one_line(ui->scr_base_ta_mqtt_port, true);
    lv_textarea_set_accepted_chars(ui->scr_base_ta_mqtt_port, "");
    lv_textarea_set_max_length(ui->scr_base_ta_mqtt_port, 32);
#if LV_USE_KEYBOARD
    lv_obj_add_event_cb(ui->scr_base_ta_mqtt_port, ta_event_cb, LV_EVENT_ALL, ui->g_kb_top_layer);
#endif

    //Write style for scr_base_ta_mqtt_port, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->scr_base_ta_mqtt_port, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_ta_mqtt_port, &lv_font_Roboto_Regular_14, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_ta_mqtt_port, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_base_ta_mqtt_port, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_ta_mqtt_port, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_ta_mqtt_port, 130, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_base_ta_mqtt_port, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_ta_mqtt_port, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->scr_base_ta_mqtt_port, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scr_base_ta_mqtt_port, 58, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scr_base_ta_mqtt_port, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scr_base_ta_mqtt_port, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_ta_mqtt_port, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_ta_mqtt_port, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_ta_mqtt_port, 12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_ta_mqtt_port, 12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_ta_mqtt_port, 10, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for scr_base_ta_mqtt_port, Part: LV_PART_MAIN, State: LV_STATE_FOCUSED.
    lv_obj_set_style_text_color(ui->scr_base_ta_mqtt_port, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_font(ui->scr_base_ta_mqtt_port, &lv_font_Roboto_Regular_14, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_opa(ui->scr_base_ta_mqtt_port, 255, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_opa(ui->scr_base_ta_mqtt_port, 130, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_color(ui->scr_base_ta_mqtt_port, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_ta_mqtt_port, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_width(ui->scr_base_ta_mqtt_port, 1, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_opa(ui->scr_base_ta_mqtt_port, 53, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_color(ui->scr_base_ta_mqtt_port, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_side(ui->scr_base_ta_mqtt_port, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_shadow_width(ui->scr_base_ta_mqtt_port, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_pad_top(ui->scr_base_ta_mqtt_port, 10, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_pad_right(ui->scr_base_ta_mqtt_port, 12, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_pad_left(ui->scr_base_ta_mqtt_port, 12, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_radius(ui->scr_base_ta_mqtt_port, 10, LV_PART_MAIN|LV_STATE_FOCUSED);

    //Write style for scr_base_ta_mqtt_port, Part: LV_PART_SCROLLBAR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->scr_base_ta_mqtt_port, 255, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_base_ta_mqtt_port, lv_color_hex(0x2195f6), LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_ta_mqtt_port, LV_GRAD_DIR_NONE, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_ta_mqtt_port, 0, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);

    //Write codes scr_base_ta_mqtt_host
    ui->scr_base_ta_mqtt_host = lv_textarea_create(ui->scr_base_cont_48);
    lv_obj_set_pos(ui->scr_base_ta_mqtt_host, 23, 47);
    lv_obj_set_size(ui->scr_base_ta_mqtt_host, 275, 38);
    lv_textarea_set_text(ui->scr_base_ta_mqtt_host, "");
    lv_textarea_set_placeholder_text(ui->scr_base_ta_mqtt_host, "Enter host...");
    lv_textarea_set_password_bullet(ui->scr_base_ta_mqtt_host, "*");
    lv_textarea_set_password_mode(ui->scr_base_ta_mqtt_host, false);
    lv_textarea_set_one_line(ui->scr_base_ta_mqtt_host, true);
    lv_textarea_set_accepted_chars(ui->scr_base_ta_mqtt_host, "");
    lv_textarea_set_max_length(ui->scr_base_ta_mqtt_host, 32);
#if LV_USE_KEYBOARD
    lv_obj_add_event_cb(ui->scr_base_ta_mqtt_host, ta_event_cb, LV_EVENT_ALL, ui->g_kb_top_layer);
#endif

    //Write style for scr_base_ta_mqtt_host, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->scr_base_ta_mqtt_host, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_ta_mqtt_host, &lv_font_Roboto_Regular_14, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_ta_mqtt_host, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_base_ta_mqtt_host, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_ta_mqtt_host, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_ta_mqtt_host, 130, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_base_ta_mqtt_host, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_ta_mqtt_host, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->scr_base_ta_mqtt_host, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scr_base_ta_mqtt_host, 58, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scr_base_ta_mqtt_host, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scr_base_ta_mqtt_host, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_ta_mqtt_host, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_ta_mqtt_host, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_ta_mqtt_host, 12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_ta_mqtt_host, 12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_ta_mqtt_host, 10, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for scr_base_ta_mqtt_host, Part: LV_PART_MAIN, State: LV_STATE_FOCUSED.
    lv_obj_set_style_text_color(ui->scr_base_ta_mqtt_host, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_font(ui->scr_base_ta_mqtt_host, &lv_font_Roboto_Regular_14, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_opa(ui->scr_base_ta_mqtt_host, 255, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_opa(ui->scr_base_ta_mqtt_host, 130, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_color(ui->scr_base_ta_mqtt_host, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_ta_mqtt_host, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_width(ui->scr_base_ta_mqtt_host, 1, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_opa(ui->scr_base_ta_mqtt_host, 53, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_color(ui->scr_base_ta_mqtt_host, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_side(ui->scr_base_ta_mqtt_host, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_shadow_width(ui->scr_base_ta_mqtt_host, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_pad_top(ui->scr_base_ta_mqtt_host, 10, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_pad_right(ui->scr_base_ta_mqtt_host, 12, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_pad_left(ui->scr_base_ta_mqtt_host, 12, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_radius(ui->scr_base_ta_mqtt_host, 10, LV_PART_MAIN|LV_STATE_FOCUSED);

    //Write style for scr_base_ta_mqtt_host, Part: LV_PART_SCROLLBAR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->scr_base_ta_mqtt_host, 255, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_base_ta_mqtt_host, lv_color_hex(0x2195f6), LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_ta_mqtt_host, LV_GRAD_DIR_NONE, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_ta_mqtt_host, 0, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);

    //Write codes scr_base_label_132
    ui->scr_base_label_132 = lv_label_create(ui->scr_base_cont_48);
    lv_obj_set_pos(ui->scr_base_label_132, 23, 111);
    lv_obj_set_size(ui->scr_base_label_132, 108, 17);
    lv_label_set_text(ui->scr_base_label_132, "USERNAME");
    lv_label_set_long_mode(ui->scr_base_label_132, LV_LABEL_LONG_WRAP);

    //Write style for scr_base_label_132, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_label_132, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_label_132, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_base_label_132, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_label_132, &lv_font_Roboto_Bold_15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_label_132, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_base_label_132, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_base_label_132, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_label_132, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_label_132, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_label_132, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_label_132, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_label_132, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_label_132, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_label_132, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_label_131
    ui->scr_base_label_131 = lv_label_create(ui->scr_base_cont_48);
    lv_obj_set_pos(ui->scr_base_label_131, 312, 111);
    lv_obj_set_size(ui->scr_base_label_131, 123, 17);
    lv_label_set_text(ui->scr_base_label_131, "PASSWORD");
    lv_label_set_long_mode(ui->scr_base_label_131, LV_LABEL_LONG_WRAP);

    //Write style for scr_base_label_131, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_label_131, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_label_131, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_base_label_131, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_label_131, &lv_font_Roboto_Bold_15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_label_131, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_base_label_131, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_base_label_131, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_label_131, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_label_131, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_label_131, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_label_131, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_label_131, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_label_131, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_label_131, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_ta_mqtt_pass
    ui->scr_base_ta_mqtt_pass = lv_textarea_create(ui->scr_base_cont_48);
    lv_obj_set_pos(ui->scr_base_ta_mqtt_pass, 312, 137);
    lv_obj_set_size(ui->scr_base_ta_mqtt_pass, 275, 38);
    lv_textarea_set_text(ui->scr_base_ta_mqtt_pass, "");
    lv_textarea_set_placeholder_text(ui->scr_base_ta_mqtt_pass, "Enter password...");
    lv_textarea_set_password_bullet(ui->scr_base_ta_mqtt_pass, "*");
    lv_textarea_set_password_mode(ui->scr_base_ta_mqtt_pass, true);
    lv_textarea_set_one_line(ui->scr_base_ta_mqtt_pass, true);
    lv_textarea_set_accepted_chars(ui->scr_base_ta_mqtt_pass, "");
    lv_textarea_set_max_length(ui->scr_base_ta_mqtt_pass, 32);
#if LV_USE_KEYBOARD
    lv_obj_add_event_cb(ui->scr_base_ta_mqtt_pass, ta_event_cb, LV_EVENT_ALL, ui->g_kb_top_layer);
#endif

    //Write style for scr_base_ta_mqtt_pass, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->scr_base_ta_mqtt_pass, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_ta_mqtt_pass, &lv_font_Roboto_Regular_14, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_ta_mqtt_pass, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_base_ta_mqtt_pass, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_ta_mqtt_pass, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_ta_mqtt_pass, 130, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_base_ta_mqtt_pass, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_ta_mqtt_pass, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->scr_base_ta_mqtt_pass, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scr_base_ta_mqtt_pass, 58, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scr_base_ta_mqtt_pass, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scr_base_ta_mqtt_pass, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_ta_mqtt_pass, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_ta_mqtt_pass, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_ta_mqtt_pass, 12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_ta_mqtt_pass, 12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_ta_mqtt_pass, 10, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for scr_base_ta_mqtt_pass, Part: LV_PART_MAIN, State: LV_STATE_FOCUSED.
    lv_obj_set_style_text_color(ui->scr_base_ta_mqtt_pass, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_font(ui->scr_base_ta_mqtt_pass, &lv_font_Roboto_Regular_14, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_opa(ui->scr_base_ta_mqtt_pass, 255, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_opa(ui->scr_base_ta_mqtt_pass, 130, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_color(ui->scr_base_ta_mqtt_pass, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_ta_mqtt_pass, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_width(ui->scr_base_ta_mqtt_pass, 1, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_opa(ui->scr_base_ta_mqtt_pass, 53, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_color(ui->scr_base_ta_mqtt_pass, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_side(ui->scr_base_ta_mqtt_pass, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_shadow_width(ui->scr_base_ta_mqtt_pass, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_pad_top(ui->scr_base_ta_mqtt_pass, 10, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_pad_right(ui->scr_base_ta_mqtt_pass, 12, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_pad_left(ui->scr_base_ta_mqtt_pass, 12, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_radius(ui->scr_base_ta_mqtt_pass, 10, LV_PART_MAIN|LV_STATE_FOCUSED);

    //Write style for scr_base_ta_mqtt_pass, Part: LV_PART_SCROLLBAR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->scr_base_ta_mqtt_pass, 255, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_base_ta_mqtt_pass, lv_color_hex(0x2195f6), LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_ta_mqtt_pass, LV_GRAD_DIR_NONE, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_ta_mqtt_pass, 0, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);

    //Write codes scr_base_lbl_mqtt_status
    ui->scr_base_lbl_mqtt_status = lv_label_create(ui->scr_base_cont_48);
    lv_obj_set_pos(ui->scr_base_lbl_mqtt_status, 23, 200);
    lv_obj_set_size(ui->scr_base_lbl_mqtt_status, 560, 17);
    lv_label_set_text(ui->scr_base_lbl_mqtt_status, "Configure your settings to connect to an MQTT broker.");
    lv_label_set_long_mode(ui->scr_base_lbl_mqtt_status, LV_LABEL_LONG_WRAP);

    //Write style for scr_base_lbl_mqtt_status, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_lbl_mqtt_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_lbl_mqtt_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_base_lbl_mqtt_status, lv_color_hex(0x71717A), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_lbl_mqtt_status, &lv_font_Roboto_Regular_15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_lbl_mqtt_status, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_base_lbl_mqtt_status, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_base_lbl_mqtt_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_lbl_mqtt_status, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_lbl_mqtt_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_lbl_mqtt_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_lbl_mqtt_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_lbl_mqtt_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_lbl_mqtt_status, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_lbl_mqtt_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_btn_mqtt_apply
    ui->scr_base_btn_mqtt_apply = lv_button_create(ui->scr_base_cont_48);
    lv_obj_set_pos(ui->scr_base_btn_mqtt_apply, 23, 236);
    lv_obj_set_size(ui->scr_base_btn_mqtt_apply, 560, 38);
    ui->scr_base_btn_mqtt_apply_label = lv_label_create(ui->scr_base_btn_mqtt_apply);
    lv_label_set_text(ui->scr_base_btn_mqtt_apply_label, "APPLY CONFIG");
    lv_label_set_long_mode(ui->scr_base_btn_mqtt_apply_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->scr_base_btn_mqtt_apply_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->scr_base_btn_mqtt_apply, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->scr_base_btn_mqtt_apply_label, LV_PCT(100));

    //Write style for scr_base_btn_mqtt_apply, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->scr_base_btn_mqtt_apply, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_base_btn_mqtt_apply, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_btn_mqtt_apply, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->scr_base_btn_mqtt_apply, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scr_base_btn_mqtt_apply, 63, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scr_base_btn_mqtt_apply, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scr_base_btn_mqtt_apply, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_btn_mqtt_apply, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_btn_mqtt_apply, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_base_btn_mqtt_apply, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_btn_mqtt_apply, &lv_font_Roboto_Black_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_btn_mqtt_apply, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_btn_mqtt_apply, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for scr_base_btn_mqtt_apply, Part: LV_PART_MAIN, State: LV_STATE_FOCUSED.
    lv_obj_set_style_bg_opa(ui->scr_base_btn_mqtt_apply, 255, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_color(ui->scr_base_btn_mqtt_apply, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_btn_mqtt_apply, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_width(ui->scr_base_btn_mqtt_apply, 1, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_opa(ui->scr_base_btn_mqtt_apply, 255, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_color(ui->scr_base_btn_mqtt_apply, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_side(ui->scr_base_btn_mqtt_apply, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_radius(ui->scr_base_btn_mqtt_apply, 10, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_shadow_width(ui->scr_base_btn_mqtt_apply, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_color(ui->scr_base_btn_mqtt_apply, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_font(ui->scr_base_btn_mqtt_apply, &lv_font_Roboto_Black_16, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_opa(ui->scr_base_btn_mqtt_apply, 255, LV_PART_MAIN|LV_STATE_FOCUSED);

    //Write style for scr_base_btn_mqtt_apply, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_bg_opa(ui->scr_base_btn_mqtt_apply, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_bg_color(ui->scr_base_btn_mqtt_apply, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_btn_mqtt_apply, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui->scr_base_btn_mqtt_apply, 1, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_border_opa(ui->scr_base_btn_mqtt_apply, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_border_color(ui->scr_base_btn_mqtt_apply, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_border_side(ui->scr_base_btn_mqtt_apply, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_radius(ui->scr_base_btn_mqtt_apply, 10, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->scr_base_btn_mqtt_apply, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->scr_base_btn_mqtt_apply, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->scr_base_btn_mqtt_apply, &lv_font_Roboto_Black_16, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->scr_base_btn_mqtt_apply, 255, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for scr_base_btn_mqtt_apply, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_bg_opa(ui->scr_base_btn_mqtt_apply, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui->scr_base_btn_mqtt_apply, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_btn_mqtt_apply, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_border_width(ui->scr_base_btn_mqtt_apply, 1, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_border_opa(ui->scr_base_btn_mqtt_apply, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_border_color(ui->scr_base_btn_mqtt_apply, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_border_side(ui->scr_base_btn_mqtt_apply, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_radius(ui->scr_base_btn_mqtt_apply, 10, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->scr_base_btn_mqtt_apply, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->scr_base_btn_mqtt_apply, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->scr_base_btn_mqtt_apply, &lv_font_Roboto_Black_16, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->scr_base_btn_mqtt_apply, 255, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write style for scr_base_btn_mqtt_apply, Part: LV_PART_MAIN, State: LV_STATE_DISABLED.
    lv_obj_set_style_bg_opa(ui->scr_base_btn_mqtt_apply, 255, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_bg_color(ui->scr_base_btn_mqtt_apply, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_btn_mqtt_apply, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_border_width(ui->scr_base_btn_mqtt_apply, 1, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_border_opa(ui->scr_base_btn_mqtt_apply, 255, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_border_color(ui->scr_base_btn_mqtt_apply, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_border_side(ui->scr_base_btn_mqtt_apply, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_radius(ui->scr_base_btn_mqtt_apply, 10, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_shadow_width(ui->scr_base_btn_mqtt_apply, 0, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_color(ui->scr_base_btn_mqtt_apply, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_font(ui->scr_base_btn_mqtt_apply, &lv_font_Roboto_Black_16, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_opa(ui->scr_base_btn_mqtt_apply, 255, LV_PART_MAIN|LV_STATE_DISABLED);

    //Write codes scr_base_ta_mqtt_user
    ui->scr_base_ta_mqtt_user = lv_textarea_create(ui->scr_base_cont_48);
    lv_obj_set_pos(ui->scr_base_ta_mqtt_user, 23, 137);
    lv_obj_set_size(ui->scr_base_ta_mqtt_user, 275, 38);
    lv_textarea_set_text(ui->scr_base_ta_mqtt_user, "");
    lv_textarea_set_placeholder_text(ui->scr_base_ta_mqtt_user, "Enter username...");
    lv_textarea_set_password_bullet(ui->scr_base_ta_mqtt_user, "*");
    lv_textarea_set_password_mode(ui->scr_base_ta_mqtt_user, false);
    lv_textarea_set_one_line(ui->scr_base_ta_mqtt_user, true);
    lv_textarea_set_accepted_chars(ui->scr_base_ta_mqtt_user, "");
    lv_textarea_set_max_length(ui->scr_base_ta_mqtt_user, 32);
#if LV_USE_KEYBOARD
    lv_obj_add_event_cb(ui->scr_base_ta_mqtt_user, ta_event_cb, LV_EVENT_ALL, ui->g_kb_top_layer);
#endif

    //Write style for scr_base_ta_mqtt_user, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->scr_base_ta_mqtt_user, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_ta_mqtt_user, &lv_font_Roboto_Regular_14, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_ta_mqtt_user, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_base_ta_mqtt_user, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_ta_mqtt_user, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_ta_mqtt_user, 130, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_base_ta_mqtt_user, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_ta_mqtt_user, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->scr_base_ta_mqtt_user, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scr_base_ta_mqtt_user, 58, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scr_base_ta_mqtt_user, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scr_base_ta_mqtt_user, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_ta_mqtt_user, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_ta_mqtt_user, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_ta_mqtt_user, 12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_ta_mqtt_user, 12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_ta_mqtt_user, 10, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for scr_base_ta_mqtt_user, Part: LV_PART_MAIN, State: LV_STATE_FOCUSED.
    lv_obj_set_style_text_color(ui->scr_base_ta_mqtt_user, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_font(ui->scr_base_ta_mqtt_user, &lv_font_Roboto_Regular_14, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_opa(ui->scr_base_ta_mqtt_user, 255, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_opa(ui->scr_base_ta_mqtt_user, 130, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_color(ui->scr_base_ta_mqtt_user, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_ta_mqtt_user, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_width(ui->scr_base_ta_mqtt_user, 1, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_opa(ui->scr_base_ta_mqtt_user, 53, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_color(ui->scr_base_ta_mqtt_user, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_side(ui->scr_base_ta_mqtt_user, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_shadow_width(ui->scr_base_ta_mqtt_user, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_pad_top(ui->scr_base_ta_mqtt_user, 10, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_pad_right(ui->scr_base_ta_mqtt_user, 12, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_pad_left(ui->scr_base_ta_mqtt_user, 12, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_radius(ui->scr_base_ta_mqtt_user, 10, LV_PART_MAIN|LV_STATE_FOCUSED);

    //Write style for scr_base_ta_mqtt_user, Part: LV_PART_SCROLLBAR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->scr_base_ta_mqtt_user, 255, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_base_ta_mqtt_user, lv_color_hex(0x2195f6), LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_ta_mqtt_user, LV_GRAD_DIR_NONE, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_ta_mqtt_user, 0, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);

    //Write codes scr_base_cont_modbus_config
    ui->scr_base_cont_modbus_config = lv_obj_create(ui->scr_base_cont_hw);
    lv_obj_set_pos(ui->scr_base_cont_modbus_config, 0, 35);
    lv_obj_set_size(ui->scr_base_cont_modbus_config, 677, 380);
    lv_obj_set_scrollbar_mode(ui->scr_base_cont_modbus_config, LV_SCROLLBAR_MODE_OFF);
    lv_obj_add_flag(ui->scr_base_cont_modbus_config, LV_OBJ_FLAG_HIDDEN);

    //Write style for scr_base_cont_modbus_config, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_cont_modbus_config, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_cont_modbus_config, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_cont_modbus_config, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_cont_modbus_config, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_cont_modbus_config, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_cont_modbus_config, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_cont_modbus_config, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_cont_modbus_config, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_cont_modbus_back
    ui->scr_base_cont_modbus_back = lv_obj_create(ui->scr_base_cont_modbus_config);
    lv_obj_set_pos(ui->scr_base_cont_modbus_back, 0, 5);
    lv_obj_set_size(ui->scr_base_cont_modbus_back, 40, 40);
    lv_obj_set_scrollbar_mode(ui->scr_base_cont_modbus_back, LV_SCROLLBAR_MODE_OFF);

    //Write style for scr_base_cont_modbus_back, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_cont_modbus_back, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scr_base_cont_modbus_back, 71, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scr_base_cont_modbus_back, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scr_base_cont_modbus_back, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_cont_modbus_back, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_cont_modbus_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_cont_modbus_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_cont_modbus_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_cont_modbus_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_cont_modbus_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_cont_modbus_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_img_20
    ui->scr_base_img_20 = lv_image_create(ui->scr_base_cont_modbus_back);
    lv_obj_set_pos(ui->scr_base_img_20, 7, 7);
    lv_obj_set_size(ui->scr_base_img_20, 24, 24);
    lv_obj_add_flag(ui->scr_base_img_20, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->scr_base_img_20, &_left_arrow_RGB565A8_24x24);
    lv_image_set_pivot(ui->scr_base_img_20, 50,50);
    lv_image_set_rotation(ui->scr_base_img_20, 0);

    //Write style for scr_base_img_20, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->scr_base_img_20, 189, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_recolor(ui->scr_base_img_20, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->scr_base_img_20, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_btn_modbus_back
    ui->scr_base_btn_modbus_back = lv_button_create(ui->scr_base_cont_modbus_back);
    lv_obj_set_pos(ui->scr_base_btn_modbus_back, -6, -6);
    lv_obj_set_size(ui->scr_base_btn_modbus_back, 50, 50);
    ui->scr_base_btn_modbus_back_label = lv_label_create(ui->scr_base_btn_modbus_back);
    lv_label_set_text(ui->scr_base_btn_modbus_back_label, "");
    lv_label_set_long_mode(ui->scr_base_btn_modbus_back_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->scr_base_btn_modbus_back_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->scr_base_btn_modbus_back, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->scr_base_btn_modbus_back_label, LV_PCT(100));

    //Write style for scr_base_btn_modbus_back, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->scr_base_btn_modbus_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->scr_base_btn_modbus_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_btn_modbus_back, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_btn_modbus_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_base_btn_modbus_back, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_btn_modbus_back, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_btn_modbus_back, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_btn_modbus_back, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for scr_base_btn_modbus_back, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_bg_opa(ui->scr_base_btn_modbus_back, 42, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_bg_color(ui->scr_base_btn_modbus_back, lv_color_hex(0x10B981), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_btn_modbus_back, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui->scr_base_btn_modbus_back, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_radius(ui->scr_base_btn_modbus_back, 10, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->scr_base_btn_modbus_back, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->scr_base_btn_modbus_back, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->scr_base_btn_modbus_back, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->scr_base_btn_modbus_back, 255, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for scr_base_btn_modbus_back, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_bg_opa(ui->scr_base_btn_modbus_back, 44, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui->scr_base_btn_modbus_back, lv_color_hex(0x10B981), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_btn_modbus_back, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_border_width(ui->scr_base_btn_modbus_back, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_radius(ui->scr_base_btn_modbus_back, 10, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->scr_base_btn_modbus_back, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->scr_base_btn_modbus_back, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->scr_base_btn_modbus_back, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->scr_base_btn_modbus_back, 255, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write codes scr_base_label_168
    ui->scr_base_label_168 = lv_label_create(ui->scr_base_cont_modbus_config);
    lv_obj_set_pos(ui->scr_base_label_168, 44, 16);
    lv_obj_set_size(ui->scr_base_label_168, 270, 17);
    lv_label_set_text(ui->scr_base_label_168, "MODBUS RTU CONFIGURATION");
    lv_label_set_long_mode(ui->scr_base_label_168, LV_LABEL_LONG_WRAP);

    //Write style for scr_base_label_168, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_label_168, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_label_168, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_base_label_168, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_label_168, &lv_font_Roboto_Bold_15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_label_168, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_base_label_168, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_base_label_168, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_label_168, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_label_168, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_label_168, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_label_168, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_label_168, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_label_168, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_label_168, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_cont_51
    ui->scr_base_cont_51 = lv_obj_create(ui->scr_base_cont_modbus_config);
    lv_obj_set_pos(ui->scr_base_cont_51, 0, 55);
    lv_obj_set_size(ui->scr_base_cont_51, 660, 320);
    lv_obj_set_scrollbar_mode(ui->scr_base_cont_51, LV_SCROLLBAR_MODE_OFF);

    //Write style for scr_base_cont_51, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_cont_51, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scr_base_cont_51, 65, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scr_base_cont_51, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scr_base_cont_51, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_cont_51, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_cont_51, 243, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_base_cont_51, lv_color_hex(0x0F172A), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_cont_51, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_cont_51, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_cont_51, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_cont_51, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_cont_51, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_cont_51, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_cont_54
    ui->scr_base_cont_54 = lv_obj_create(ui->scr_base_cont_51);
    lv_obj_set_pos(ui->scr_base_cont_54, 23, 14);
    lv_obj_set_size(ui->scr_base_cont_54, 612, 290);
    lv_obj_set_scrollbar_mode(ui->scr_base_cont_54, LV_SCROLLBAR_MODE_OFF);

    //Write style for scr_base_cont_54, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_cont_54, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scr_base_cont_54, 65, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scr_base_cont_54, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scr_base_cont_54, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_cont_54, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_cont_54, 51, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_base_cont_54, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_cont_54, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_cont_54, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_cont_54, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_cont_54, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_cont_54, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_cont_54, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_label_161
    ui->scr_base_label_161 = lv_label_create(ui->scr_base_cont_54);
    lv_obj_set_pos(ui->scr_base_label_161, 23, 110);
    lv_obj_set_size(ui->scr_base_label_161, 108, 17);
    lv_label_set_text(ui->scr_base_label_161, "BAUD RATE");
    lv_label_set_long_mode(ui->scr_base_label_161, LV_LABEL_LONG_WRAP);

    //Write style for scr_base_label_161, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_label_161, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_label_161, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_base_label_161, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_label_161, &lv_font_Roboto_Bold_15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_label_161, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_base_label_161, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_base_label_161, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_label_161, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_label_161, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_label_161, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_label_161, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_label_161, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_label_161, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_label_161, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_label_160
    ui->scr_base_label_160 = lv_label_create(ui->scr_base_cont_54);
    lv_obj_set_pos(ui->scr_base_label_160, 307, 110);
    lv_obj_set_size(ui->scr_base_label_160, 101, 13);
    lv_label_set_text(ui->scr_base_label_160, "DATA BITS");
    lv_label_set_long_mode(ui->scr_base_label_160, LV_LABEL_LONG_WRAP);

    //Write style for scr_base_label_160, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_label_160, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_label_160, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_base_label_160, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_label_160, &lv_font_Roboto_Bold_15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_label_160, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_base_label_160, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_base_label_160, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_label_160, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_label_160, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_label_160, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_label_160, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_label_160, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_label_160, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_label_160, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_label_159
    ui->scr_base_label_159 = lv_label_create(ui->scr_base_cont_54);
    lv_obj_set_pos(ui->scr_base_label_159, 23, 24);
    lv_obj_set_size(ui->scr_base_label_159, 80, 17);
    lv_label_set_text(ui->scr_base_label_159, "MODE");
    lv_label_set_long_mode(ui->scr_base_label_159, LV_LABEL_LONG_WRAP);

    //Write style for scr_base_label_159, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_label_159, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_label_159, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_base_label_159, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_label_159, &lv_font_Roboto_Bold_15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_label_159, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_base_label_159, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_base_label_159, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_label_159, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_label_159, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_label_159, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_label_159, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_label_159, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_label_159, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_label_159, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_lbl_modbus_status
    ui->scr_base_lbl_modbus_status = lv_label_create(ui->scr_base_cont_54);
    lv_obj_set_pos(ui->scr_base_lbl_modbus_status, 24, 197);
    lv_obj_set_size(ui->scr_base_lbl_modbus_status, 517, 17);
    lv_label_set_text(ui->scr_base_lbl_modbus_status, "Configure your settings to connect to a Modbus network.");
    lv_label_set_long_mode(ui->scr_base_lbl_modbus_status, LV_LABEL_LONG_WRAP);

    //Write style for scr_base_lbl_modbus_status, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_lbl_modbus_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_lbl_modbus_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_base_lbl_modbus_status, lv_color_hex(0x71717A), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_lbl_modbus_status, &lv_font_Roboto_Regular_15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_lbl_modbus_status, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_base_lbl_modbus_status, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_base_lbl_modbus_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_lbl_modbus_status, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_lbl_modbus_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_lbl_modbus_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_lbl_modbus_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_lbl_modbus_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_lbl_modbus_status, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_lbl_modbus_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_btn_modbus_apply
    ui->scr_base_btn_modbus_apply = lv_button_create(ui->scr_base_cont_54);
    lv_obj_set_pos(ui->scr_base_btn_modbus_apply, 23, 233);
    lv_obj_set_size(ui->scr_base_btn_modbus_apply, 560, 38);
    ui->scr_base_btn_modbus_apply_label = lv_label_create(ui->scr_base_btn_modbus_apply);
    lv_label_set_text(ui->scr_base_btn_modbus_apply_label, "APPLY CONFIG");
    lv_label_set_long_mode(ui->scr_base_btn_modbus_apply_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->scr_base_btn_modbus_apply_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->scr_base_btn_modbus_apply, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->scr_base_btn_modbus_apply_label, LV_PCT(100));

    //Write style for scr_base_btn_modbus_apply, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->scr_base_btn_modbus_apply, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_base_btn_modbus_apply, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_btn_modbus_apply, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->scr_base_btn_modbus_apply, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scr_base_btn_modbus_apply, 63, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scr_base_btn_modbus_apply, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scr_base_btn_modbus_apply, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_btn_modbus_apply, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_btn_modbus_apply, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_base_btn_modbus_apply, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_btn_modbus_apply, &lv_font_Roboto_Black_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_btn_modbus_apply, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_btn_modbus_apply, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for scr_base_btn_modbus_apply, Part: LV_PART_MAIN, State: LV_STATE_FOCUSED.
    lv_obj_set_style_bg_opa(ui->scr_base_btn_modbus_apply, 255, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_color(ui->scr_base_btn_modbus_apply, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_btn_modbus_apply, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_width(ui->scr_base_btn_modbus_apply, 1, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_opa(ui->scr_base_btn_modbus_apply, 255, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_color(ui->scr_base_btn_modbus_apply, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_side(ui->scr_base_btn_modbus_apply, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_radius(ui->scr_base_btn_modbus_apply, 10, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_shadow_width(ui->scr_base_btn_modbus_apply, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_color(ui->scr_base_btn_modbus_apply, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_font(ui->scr_base_btn_modbus_apply, &lv_font_Roboto_Black_16, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_opa(ui->scr_base_btn_modbus_apply, 255, LV_PART_MAIN|LV_STATE_FOCUSED);

    //Write style for scr_base_btn_modbus_apply, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_bg_opa(ui->scr_base_btn_modbus_apply, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_bg_color(ui->scr_base_btn_modbus_apply, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_btn_modbus_apply, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui->scr_base_btn_modbus_apply, 1, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_border_opa(ui->scr_base_btn_modbus_apply, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_border_color(ui->scr_base_btn_modbus_apply, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_border_side(ui->scr_base_btn_modbus_apply, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_radius(ui->scr_base_btn_modbus_apply, 10, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->scr_base_btn_modbus_apply, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->scr_base_btn_modbus_apply, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->scr_base_btn_modbus_apply, &lv_font_Roboto_Black_16, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->scr_base_btn_modbus_apply, 255, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for scr_base_btn_modbus_apply, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_bg_opa(ui->scr_base_btn_modbus_apply, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui->scr_base_btn_modbus_apply, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_btn_modbus_apply, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_border_width(ui->scr_base_btn_modbus_apply, 1, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_border_opa(ui->scr_base_btn_modbus_apply, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_border_color(ui->scr_base_btn_modbus_apply, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_border_side(ui->scr_base_btn_modbus_apply, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_radius(ui->scr_base_btn_modbus_apply, 10, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->scr_base_btn_modbus_apply, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->scr_base_btn_modbus_apply, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->scr_base_btn_modbus_apply, &lv_font_Roboto_Black_16, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->scr_base_btn_modbus_apply, 255, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write style for scr_base_btn_modbus_apply, Part: LV_PART_MAIN, State: LV_STATE_DISABLED.
    lv_obj_set_style_bg_opa(ui->scr_base_btn_modbus_apply, 255, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_bg_color(ui->scr_base_btn_modbus_apply, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_btn_modbus_apply, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_border_width(ui->scr_base_btn_modbus_apply, 1, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_border_opa(ui->scr_base_btn_modbus_apply, 255, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_border_color(ui->scr_base_btn_modbus_apply, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_border_side(ui->scr_base_btn_modbus_apply, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_radius(ui->scr_base_btn_modbus_apply, 10, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_shadow_width(ui->scr_base_btn_modbus_apply, 0, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_color(ui->scr_base_btn_modbus_apply, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_font(ui->scr_base_btn_modbus_apply, &lv_font_Roboto_Black_16, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_opa(ui->scr_base_btn_modbus_apply, 255, LV_PART_MAIN|LV_STATE_DISABLED);

    //Write codes scr_base_cont_slave
    ui->scr_base_cont_slave = lv_obj_create(ui->scr_base_cont_54);
    lv_obj_set_pos(ui->scr_base_cont_slave, 175, 7);
    lv_obj_set_size(ui->scr_base_cont_slave, 417, 88);
    lv_obj_set_scrollbar_mode(ui->scr_base_cont_slave, LV_SCROLLBAR_MODE_OFF);
    lv_obj_add_flag(ui->scr_base_cont_slave, LV_OBJ_FLAG_HIDDEN);

    //Write style for scr_base_cont_slave, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_cont_slave, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scr_base_cont_slave, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scr_base_cont_slave, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scr_base_cont_slave, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_cont_slave, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_cont_slave, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_cont_slave, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_cont_slave, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_cont_slave, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_cont_slave, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_cont_slave, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_ta_slave_id
    ui->scr_base_ta_slave_id = lv_textarea_create(ui->scr_base_cont_slave);
    lv_obj_set_pos(ui->scr_base_ta_slave_id, 0, 42);
    lv_obj_set_size(ui->scr_base_ta_slave_id, 405, 38);
    lv_textarea_set_text(ui->scr_base_ta_slave_id, "");
    lv_textarea_set_placeholder_text(ui->scr_base_ta_slave_id, "Enter Slave ID...");
    lv_textarea_set_password_bullet(ui->scr_base_ta_slave_id, "*");
    lv_textarea_set_password_mode(ui->scr_base_ta_slave_id, false);
    lv_textarea_set_one_line(ui->scr_base_ta_slave_id, true);
    lv_textarea_set_accepted_chars(ui->scr_base_ta_slave_id, "");
    lv_textarea_set_max_length(ui->scr_base_ta_slave_id, 32);
#if LV_USE_KEYBOARD
    lv_obj_add_event_cb(ui->scr_base_ta_slave_id, ta_event_cb, LV_EVENT_ALL, ui->g_kb_top_layer);
#endif

    //Write style for scr_base_ta_slave_id, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->scr_base_ta_slave_id, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_ta_slave_id, &lv_font_Roboto_Regular_14, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_ta_slave_id, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_base_ta_slave_id, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_ta_slave_id, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_ta_slave_id, 130, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_base_ta_slave_id, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_ta_slave_id, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->scr_base_ta_slave_id, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scr_base_ta_slave_id, 58, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scr_base_ta_slave_id, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scr_base_ta_slave_id, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_ta_slave_id, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_ta_slave_id, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_ta_slave_id, 12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_ta_slave_id, 12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_ta_slave_id, 10, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for scr_base_ta_slave_id, Part: LV_PART_MAIN, State: LV_STATE_FOCUSED.
    lv_obj_set_style_text_color(ui->scr_base_ta_slave_id, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_font(ui->scr_base_ta_slave_id, &lv_font_Roboto_Regular_14, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_opa(ui->scr_base_ta_slave_id, 255, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_opa(ui->scr_base_ta_slave_id, 130, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_color(ui->scr_base_ta_slave_id, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_ta_slave_id, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_width(ui->scr_base_ta_slave_id, 1, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_opa(ui->scr_base_ta_slave_id, 53, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_color(ui->scr_base_ta_slave_id, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_side(ui->scr_base_ta_slave_id, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_shadow_width(ui->scr_base_ta_slave_id, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_pad_top(ui->scr_base_ta_slave_id, 10, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_pad_right(ui->scr_base_ta_slave_id, 12, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_pad_left(ui->scr_base_ta_slave_id, 12, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_radius(ui->scr_base_ta_slave_id, 10, LV_PART_MAIN|LV_STATE_FOCUSED);

    //Write style for scr_base_ta_slave_id, Part: LV_PART_SCROLLBAR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->scr_base_ta_slave_id, 255, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_base_ta_slave_id, lv_color_hex(0x2195f6), LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_ta_slave_id, LV_GRAD_DIR_NONE, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_ta_slave_id, 0, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);

    //Write codes scr_base_label_158
    ui->scr_base_label_158 = lv_label_create(ui->scr_base_cont_slave);
    lv_obj_set_pos(ui->scr_base_label_158, 0, 17);
    lv_obj_set_size(ui->scr_base_label_158, 161, 17);
    lv_label_set_text(ui->scr_base_label_158, "SLAVE ID");
    lv_label_set_long_mode(ui->scr_base_label_158, LV_LABEL_LONG_WRAP);

    //Write style for scr_base_label_158, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_label_158, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_label_158, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_base_label_158, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_label_158, &lv_font_Roboto_Bold_15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_label_158, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_base_label_158, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_base_label_158, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_label_158, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_label_158, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_label_158, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_label_158, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_label_158, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_label_158, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_label_158, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_cont_master
    ui->scr_base_cont_master = lv_obj_create(ui->scr_base_cont_54);
    lv_obj_set_pos(ui->scr_base_cont_master, 175, 7);
    lv_obj_set_size(ui->scr_base_cont_master, 417, 82);
    lv_obj_set_scrollbar_mode(ui->scr_base_cont_master, LV_SCROLLBAR_MODE_OFF);

    //Write style for scr_base_cont_master, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_cont_master, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scr_base_cont_master, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scr_base_cont_master, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scr_base_cont_master, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_cont_master, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_cont_master, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_cont_master, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_cont_master, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_cont_master, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_cont_master, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_cont_master, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_lbl_master
    ui->scr_base_lbl_master = lv_label_create(ui->scr_base_cont_master);
    lv_obj_set_pos(ui->scr_base_lbl_master, 0, 15);
    lv_obj_set_size(ui->scr_base_lbl_master, 161, 17);
    lv_label_set_text(ui->scr_base_lbl_master, "MASTER CONTROLS");
    lv_label_set_long_mode(ui->scr_base_lbl_master, LV_LABEL_LONG_WRAP);

    //Write style for scr_base_lbl_master, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_lbl_master, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_lbl_master, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_base_lbl_master, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_lbl_master, &lv_font_Roboto_Bold_15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_lbl_master, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_base_lbl_master, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_base_lbl_master, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_lbl_master, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_lbl_master, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_lbl_master, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_lbl_master, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_lbl_master, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_lbl_master, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_lbl_master, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_btn_master_adddeivce
    ui->scr_base_btn_master_adddeivce = lv_button_create(ui->scr_base_cont_master);
    lv_obj_set_pos(ui->scr_base_btn_master_adddeivce, 0, 41);
    lv_obj_set_size(ui->scr_base_btn_master_adddeivce, 198, 38);
    ui->scr_base_btn_master_adddeivce_label = lv_label_create(ui->scr_base_btn_master_adddeivce);
    lv_label_set_text(ui->scr_base_btn_master_adddeivce_label, "" LV_SYMBOL_UPLOAD "  ADD DEVICES");
    lv_label_set_long_mode(ui->scr_base_btn_master_adddeivce_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->scr_base_btn_master_adddeivce_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->scr_base_btn_master_adddeivce, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->scr_base_btn_master_adddeivce_label, LV_PCT(100));

    //Write style for scr_base_btn_master_adddeivce, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->scr_base_btn_master_adddeivce, 153, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_base_btn_master_adddeivce, lv_color_hex(0x4d5256), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_btn_master_adddeivce, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->scr_base_btn_master_adddeivce, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scr_base_btn_master_adddeivce, 63, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scr_base_btn_master_adddeivce, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scr_base_btn_master_adddeivce, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_btn_master_adddeivce, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_btn_master_adddeivce, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_base_btn_master_adddeivce, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_btn_master_adddeivce, &lv_font_Roboto_Black_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_btn_master_adddeivce, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_btn_master_adddeivce, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for scr_base_btn_master_adddeivce, Part: LV_PART_MAIN, State: LV_STATE_FOCUSED.
    lv_obj_set_style_bg_opa(ui->scr_base_btn_master_adddeivce, 255, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_color(ui->scr_base_btn_master_adddeivce, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_btn_master_adddeivce, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_width(ui->scr_base_btn_master_adddeivce, 1, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_opa(ui->scr_base_btn_master_adddeivce, 255, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_color(ui->scr_base_btn_master_adddeivce, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_side(ui->scr_base_btn_master_adddeivce, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_radius(ui->scr_base_btn_master_adddeivce, 10, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_shadow_width(ui->scr_base_btn_master_adddeivce, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_color(ui->scr_base_btn_master_adddeivce, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_font(ui->scr_base_btn_master_adddeivce, &lv_font_Roboto_Black_16, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_opa(ui->scr_base_btn_master_adddeivce, 255, LV_PART_MAIN|LV_STATE_FOCUSED);

    //Write style for scr_base_btn_master_adddeivce, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_bg_opa(ui->scr_base_btn_master_adddeivce, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_bg_color(ui->scr_base_btn_master_adddeivce, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_btn_master_adddeivce, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui->scr_base_btn_master_adddeivce, 1, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_border_opa(ui->scr_base_btn_master_adddeivce, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_border_color(ui->scr_base_btn_master_adddeivce, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_border_side(ui->scr_base_btn_master_adddeivce, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_radius(ui->scr_base_btn_master_adddeivce, 10, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->scr_base_btn_master_adddeivce, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->scr_base_btn_master_adddeivce, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->scr_base_btn_master_adddeivce, &lv_font_Roboto_Black_16, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->scr_base_btn_master_adddeivce, 255, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for scr_base_btn_master_adddeivce, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_bg_opa(ui->scr_base_btn_master_adddeivce, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui->scr_base_btn_master_adddeivce, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_btn_master_adddeivce, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_border_width(ui->scr_base_btn_master_adddeivce, 1, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_border_opa(ui->scr_base_btn_master_adddeivce, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_border_color(ui->scr_base_btn_master_adddeivce, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_border_side(ui->scr_base_btn_master_adddeivce, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_radius(ui->scr_base_btn_master_adddeivce, 10, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->scr_base_btn_master_adddeivce, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->scr_base_btn_master_adddeivce, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->scr_base_btn_master_adddeivce, &lv_font_Roboto_Black_16, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->scr_base_btn_master_adddeivce, 255, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write style for scr_base_btn_master_adddeivce, Part: LV_PART_MAIN, State: LV_STATE_DISABLED.
    lv_obj_set_style_bg_opa(ui->scr_base_btn_master_adddeivce, 255, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_bg_color(ui->scr_base_btn_master_adddeivce, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_btn_master_adddeivce, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_border_width(ui->scr_base_btn_master_adddeivce, 1, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_border_opa(ui->scr_base_btn_master_adddeivce, 255, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_border_color(ui->scr_base_btn_master_adddeivce, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_border_side(ui->scr_base_btn_master_adddeivce, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_radius(ui->scr_base_btn_master_adddeivce, 10, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_shadow_width(ui->scr_base_btn_master_adddeivce, 0, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_color(ui->scr_base_btn_master_adddeivce, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_font(ui->scr_base_btn_master_adddeivce, &lv_font_Roboto_Black_16, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_opa(ui->scr_base_btn_master_adddeivce, 255, LV_PART_MAIN|LV_STATE_DISABLED);

    //Write codes scr_base_btn_masterviewlist
    ui->scr_base_btn_masterviewlist = lv_button_create(ui->scr_base_cont_master);
    lv_obj_set_pos(ui->scr_base_btn_masterviewlist, 207, 41);
    lv_obj_set_size(ui->scr_base_btn_masterviewlist, 198, 38);
    ui->scr_base_btn_masterviewlist_label = lv_label_create(ui->scr_base_btn_masterviewlist);
    lv_label_set_text(ui->scr_base_btn_masterviewlist_label, "" LV_SYMBOL_BARS " VIEW LIST");
    lv_label_set_long_mode(ui->scr_base_btn_masterviewlist_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->scr_base_btn_masterviewlist_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->scr_base_btn_masterviewlist, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->scr_base_btn_masterviewlist_label, LV_PCT(100));

    //Write style for scr_base_btn_masterviewlist, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->scr_base_btn_masterviewlist, 153, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_base_btn_masterviewlist, lv_color_hex(0x4d5256), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_btn_masterviewlist, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->scr_base_btn_masterviewlist, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scr_base_btn_masterviewlist, 63, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scr_base_btn_masterviewlist, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scr_base_btn_masterviewlist, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_btn_masterviewlist, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_btn_masterviewlist, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_base_btn_masterviewlist, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_btn_masterviewlist, &lv_font_Roboto_Black_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_btn_masterviewlist, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_btn_masterviewlist, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for scr_base_btn_masterviewlist, Part: LV_PART_MAIN, State: LV_STATE_FOCUSED.
    lv_obj_set_style_bg_opa(ui->scr_base_btn_masterviewlist, 255, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_color(ui->scr_base_btn_masterviewlist, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_btn_masterviewlist, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_width(ui->scr_base_btn_masterviewlist, 1, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_opa(ui->scr_base_btn_masterviewlist, 255, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_color(ui->scr_base_btn_masterviewlist, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_side(ui->scr_base_btn_masterviewlist, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_radius(ui->scr_base_btn_masterviewlist, 10, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_shadow_width(ui->scr_base_btn_masterviewlist, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_color(ui->scr_base_btn_masterviewlist, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_font(ui->scr_base_btn_masterviewlist, &lv_font_Roboto_Black_16, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_opa(ui->scr_base_btn_masterviewlist, 255, LV_PART_MAIN|LV_STATE_FOCUSED);

    //Write style for scr_base_btn_masterviewlist, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_bg_opa(ui->scr_base_btn_masterviewlist, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_bg_color(ui->scr_base_btn_masterviewlist, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_btn_masterviewlist, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui->scr_base_btn_masterviewlist, 1, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_border_opa(ui->scr_base_btn_masterviewlist, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_border_color(ui->scr_base_btn_masterviewlist, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_border_side(ui->scr_base_btn_masterviewlist, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_radius(ui->scr_base_btn_masterviewlist, 10, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->scr_base_btn_masterviewlist, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->scr_base_btn_masterviewlist, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->scr_base_btn_masterviewlist, &lv_font_Roboto_Black_16, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->scr_base_btn_masterviewlist, 255, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for scr_base_btn_masterviewlist, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_bg_opa(ui->scr_base_btn_masterviewlist, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui->scr_base_btn_masterviewlist, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_btn_masterviewlist, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_border_width(ui->scr_base_btn_masterviewlist, 1, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_border_opa(ui->scr_base_btn_masterviewlist, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_border_color(ui->scr_base_btn_masterviewlist, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_border_side(ui->scr_base_btn_masterviewlist, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_radius(ui->scr_base_btn_masterviewlist, 10, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->scr_base_btn_masterviewlist, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->scr_base_btn_masterviewlist, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->scr_base_btn_masterviewlist, &lv_font_Roboto_Black_16, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->scr_base_btn_masterviewlist, 255, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write style for scr_base_btn_masterviewlist, Part: LV_PART_MAIN, State: LV_STATE_DISABLED.
    lv_obj_set_style_bg_opa(ui->scr_base_btn_masterviewlist, 255, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_bg_color(ui->scr_base_btn_masterviewlist, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_btn_masterviewlist, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_border_width(ui->scr_base_btn_masterviewlist, 1, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_border_opa(ui->scr_base_btn_masterviewlist, 255, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_border_color(ui->scr_base_btn_masterviewlist, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_border_side(ui->scr_base_btn_masterviewlist, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_radius(ui->scr_base_btn_masterviewlist, 10, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_shadow_width(ui->scr_base_btn_masterviewlist, 0, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_color(ui->scr_base_btn_masterviewlist, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_font(ui->scr_base_btn_masterviewlist, &lv_font_Roboto_Black_16, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_opa(ui->scr_base_btn_masterviewlist, 255, LV_PART_MAIN|LV_STATE_DISABLED);

    //Write codes scr_base_label_170
    ui->scr_base_label_170 = lv_label_create(ui->scr_base_cont_54);
    lv_obj_set_pos(ui->scr_base_label_170, 165, 110);
    lv_obj_set_size(ui->scr_base_label_170, 85, 17);
    lv_label_set_text(ui->scr_base_label_170, "PARITY");
    lv_label_set_long_mode(ui->scr_base_label_170, LV_LABEL_LONG_WRAP);

    //Write style for scr_base_label_170, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_label_170, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_label_170, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_base_label_170, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_label_170, &lv_font_Roboto_Bold_15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_label_170, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_base_label_170, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_base_label_170, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_label_170, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_label_170, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_label_170, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_label_170, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_label_170, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_label_170, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_label_170, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_label_171
    ui->scr_base_label_171 = lv_label_create(ui->scr_base_cont_54);
    lv_obj_set_pos(ui->scr_base_label_171, 449, 110);
    lv_obj_set_size(ui->scr_base_label_171, 117, 13);
    lv_label_set_text(ui->scr_base_label_171, "STOP BITS");
    lv_label_set_long_mode(ui->scr_base_label_171, LV_LABEL_LONG_WRAP);

    //Write style for scr_base_label_171, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_label_171, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_label_171, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_base_label_171, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_label_171, &lv_font_Roboto_Bold_15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_label_171, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_base_label_171, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_base_label_171, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_label_171, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_label_171, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_label_171, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_label_171, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_label_171, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_label_171, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_label_171, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_ddlist_modbus_mode
    ui->scr_base_ddlist_modbus_mode = lv_dropdown_create(ui->scr_base_cont_54);
    lv_obj_set_pos(ui->scr_base_ddlist_modbus_mode, 23, 50);
    lv_obj_set_size(ui->scr_base_ddlist_modbus_mode, 140, 38);
    lv_dropdown_set_options(ui->scr_base_ddlist_modbus_mode, "MASTER\nSLAVE");

    //Write style for scr_base_ddlist_modbus_mode, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->scr_base_ddlist_modbus_mode, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_ddlist_modbus_mode, &lv_font_Roboto_Regular_14, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_ddlist_modbus_mode, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->scr_base_ddlist_modbus_mode, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scr_base_ddlist_modbus_mode, 56, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scr_base_ddlist_modbus_mode, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scr_base_ddlist_modbus_mode, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_ddlist_modbus_mode, 12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_ddlist_modbus_mode, 12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_ddlist_modbus_mode, 12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_ddlist_modbus_mode, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_ddlist_modbus_mode, 130, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_base_ddlist_modbus_mode, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_ddlist_modbus_mode, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_ddlist_modbus_mode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for scr_base_ddlist_modbus_mode, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_text_color(ui->scr_base_ddlist_modbus_mode, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->scr_base_ddlist_modbus_mode, &lv_font_Roboto_Regular_14, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->scr_base_ddlist_modbus_mode, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_border_width(ui->scr_base_ddlist_modbus_mode, 1, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_border_opa(ui->scr_base_ddlist_modbus_mode, 58, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_border_color(ui->scr_base_ddlist_modbus_mode, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_border_side(ui->scr_base_ddlist_modbus_mode, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_pad_top(ui->scr_base_ddlist_modbus_mode, 12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_pad_left(ui->scr_base_ddlist_modbus_mode, 12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_pad_right(ui->scr_base_ddlist_modbus_mode, 12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_radius(ui->scr_base_ddlist_modbus_mode, 10, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_opa(ui->scr_base_ddlist_modbus_mode, 129, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui->scr_base_ddlist_modbus_mode, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_ddlist_modbus_mode, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->scr_base_ddlist_modbus_mode, 0, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write style for scr_base_ddlist_modbus_mode, Part: LV_PART_MAIN, State: LV_STATE_FOCUSED.
    lv_obj_set_style_text_color(ui->scr_base_ddlist_modbus_mode, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_font(ui->scr_base_ddlist_modbus_mode, &lv_font_Roboto_Regular_14, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_opa(ui->scr_base_ddlist_modbus_mode, 255, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_width(ui->scr_base_ddlist_modbus_mode, 1, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_opa(ui->scr_base_ddlist_modbus_mode, 70, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_color(ui->scr_base_ddlist_modbus_mode, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_side(ui->scr_base_ddlist_modbus_mode, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_pad_top(ui->scr_base_ddlist_modbus_mode, 12, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_pad_left(ui->scr_base_ddlist_modbus_mode, 12, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_pad_right(ui->scr_base_ddlist_modbus_mode, 12, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_radius(ui->scr_base_ddlist_modbus_mode, 10, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_opa(ui->scr_base_ddlist_modbus_mode, 130, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_color(ui->scr_base_ddlist_modbus_mode, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_ddlist_modbus_mode, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_shadow_width(ui->scr_base_ddlist_modbus_mode, 0, LV_PART_MAIN|LV_STATE_FOCUSED);

    //Write style for scr_base_ddlist_modbus_mode, Part: LV_PART_MAIN, State: LV_STATE_DISABLED.
    lv_obj_set_style_text_color(ui->scr_base_ddlist_modbus_mode, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_font(ui->scr_base_ddlist_modbus_mode, &lv_font_Roboto_Regular_14, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_opa(ui->scr_base_ddlist_modbus_mode, 255, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_border_width(ui->scr_base_ddlist_modbus_mode, 1, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_border_opa(ui->scr_base_ddlist_modbus_mode, 61, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_border_color(ui->scr_base_ddlist_modbus_mode, lv_color_hex(0xe1e6ee), LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_border_side(ui->scr_base_ddlist_modbus_mode, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_pad_top(ui->scr_base_ddlist_modbus_mode, 12, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_pad_left(ui->scr_base_ddlist_modbus_mode, 12, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_pad_right(ui->scr_base_ddlist_modbus_mode, 12, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_radius(ui->scr_base_ddlist_modbus_mode, 10, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_bg_opa(ui->scr_base_ddlist_modbus_mode, 130, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_bg_color(ui->scr_base_ddlist_modbus_mode, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_ddlist_modbus_mode, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_shadow_width(ui->scr_base_ddlist_modbus_mode, 0, LV_PART_MAIN|LV_STATE_DISABLED);

    //Write style state: LV_STATE_CHECKED for &style_scr_base_ddlist_modbus_mode_extra_list_selected_checked
    static lv_style_t style_scr_base_ddlist_modbus_mode_extra_list_selected_checked;
    ui_init_style(&style_scr_base_ddlist_modbus_mode_extra_list_selected_checked);

    lv_style_set_border_width(&style_scr_base_ddlist_modbus_mode_extra_list_selected_checked, 1);
    lv_style_set_border_opa(&style_scr_base_ddlist_modbus_mode_extra_list_selected_checked, 255);
    lv_style_set_border_color(&style_scr_base_ddlist_modbus_mode_extra_list_selected_checked, lv_color_hex(0xe1e6ee));
    lv_style_set_border_side(&style_scr_base_ddlist_modbus_mode_extra_list_selected_checked, LV_BORDER_SIDE_FULL);
    lv_style_set_radius(&style_scr_base_ddlist_modbus_mode_extra_list_selected_checked, 1);
    lv_style_set_bg_opa(&style_scr_base_ddlist_modbus_mode_extra_list_selected_checked, 129);
    lv_style_set_bg_color(&style_scr_base_ddlist_modbus_mode_extra_list_selected_checked, lv_color_hex(0x00a1b5));
    lv_style_set_bg_grad_dir(&style_scr_base_ddlist_modbus_mode_extra_list_selected_checked, LV_GRAD_DIR_NONE);
    lv_obj_add_style(lv_dropdown_get_list(ui->scr_base_ddlist_modbus_mode), &style_scr_base_ddlist_modbus_mode_extra_list_selected_checked, LV_PART_SELECTED|LV_STATE_CHECKED);

    //Write style state: LV_STATE_DEFAULT for &style_scr_base_ddlist_modbus_mode_extra_list_main_default
    static lv_style_t style_scr_base_ddlist_modbus_mode_extra_list_main_default;
    ui_init_style(&style_scr_base_ddlist_modbus_mode_extra_list_main_default);

    lv_style_set_max_height(&style_scr_base_ddlist_modbus_mode_extra_list_main_default, 90);
    lv_style_set_text_color(&style_scr_base_ddlist_modbus_mode_extra_list_main_default, lv_color_hex(0xfdfdfd));
    lv_style_set_text_font(&style_scr_base_ddlist_modbus_mode_extra_list_main_default, &lv_font_Roboto_Regular_14);
    lv_style_set_text_opa(&style_scr_base_ddlist_modbus_mode_extra_list_main_default, 255);
    lv_style_set_border_width(&style_scr_base_ddlist_modbus_mode_extra_list_main_default, 1);
    lv_style_set_border_opa(&style_scr_base_ddlist_modbus_mode_extra_list_main_default, 54);
    lv_style_set_border_color(&style_scr_base_ddlist_modbus_mode_extra_list_main_default, lv_color_hex(0xffffff));
    lv_style_set_border_side(&style_scr_base_ddlist_modbus_mode_extra_list_main_default, LV_BORDER_SIDE_FULL);
    lv_style_set_radius(&style_scr_base_ddlist_modbus_mode_extra_list_main_default, 5);
    lv_style_set_bg_opa(&style_scr_base_ddlist_modbus_mode_extra_list_main_default, 129);
    lv_style_set_bg_color(&style_scr_base_ddlist_modbus_mode_extra_list_main_default, lv_color_hex(0x000000));
    lv_style_set_bg_grad_dir(&style_scr_base_ddlist_modbus_mode_extra_list_main_default, LV_GRAD_DIR_NONE);
    lv_obj_add_style(lv_dropdown_get_list(ui->scr_base_ddlist_modbus_mode), &style_scr_base_ddlist_modbus_mode_extra_list_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_DEFAULT for &style_scr_base_ddlist_modbus_mode_extra_list_scrollbar_default
    static lv_style_t style_scr_base_ddlist_modbus_mode_extra_list_scrollbar_default;
    ui_init_style(&style_scr_base_ddlist_modbus_mode_extra_list_scrollbar_default);

    lv_style_set_radius(&style_scr_base_ddlist_modbus_mode_extra_list_scrollbar_default, 3);
    lv_style_set_bg_opa(&style_scr_base_ddlist_modbus_mode_extra_list_scrollbar_default, 54);
    lv_style_set_bg_color(&style_scr_base_ddlist_modbus_mode_extra_list_scrollbar_default, lv_color_hex(0xcccccc));
    lv_style_set_bg_grad_dir(&style_scr_base_ddlist_modbus_mode_extra_list_scrollbar_default, LV_GRAD_DIR_NONE);
    lv_obj_add_style(lv_dropdown_get_list(ui->scr_base_ddlist_modbus_mode), &style_scr_base_ddlist_modbus_mode_extra_list_scrollbar_default, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);

    //Write codes scr_base_ddlist_modbus_parity
    ui->scr_base_ddlist_modbus_parity = lv_dropdown_create(ui->scr_base_cont_54);
    lv_obj_set_pos(ui->scr_base_ddlist_modbus_parity, 165, 135);
    lv_obj_set_size(ui->scr_base_ddlist_modbus_parity, 133, 38);
    lv_dropdown_set_options(ui->scr_base_ddlist_modbus_parity, "NONE\nEVEN\nODD");

    //Write style for scr_base_ddlist_modbus_parity, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->scr_base_ddlist_modbus_parity, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_ddlist_modbus_parity, &lv_font_Roboto_Regular_14, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_ddlist_modbus_parity, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->scr_base_ddlist_modbus_parity, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scr_base_ddlist_modbus_parity, 56, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scr_base_ddlist_modbus_parity, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scr_base_ddlist_modbus_parity, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_ddlist_modbus_parity, 12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_ddlist_modbus_parity, 12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_ddlist_modbus_parity, 12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_ddlist_modbus_parity, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_ddlist_modbus_parity, 130, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_base_ddlist_modbus_parity, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_ddlist_modbus_parity, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_ddlist_modbus_parity, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for scr_base_ddlist_modbus_parity, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_text_color(ui->scr_base_ddlist_modbus_parity, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->scr_base_ddlist_modbus_parity, &lv_font_Roboto_Regular_14, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->scr_base_ddlist_modbus_parity, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_border_width(ui->scr_base_ddlist_modbus_parity, 1, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_border_opa(ui->scr_base_ddlist_modbus_parity, 58, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_border_color(ui->scr_base_ddlist_modbus_parity, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_border_side(ui->scr_base_ddlist_modbus_parity, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_pad_top(ui->scr_base_ddlist_modbus_parity, 12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_pad_left(ui->scr_base_ddlist_modbus_parity, 12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_pad_right(ui->scr_base_ddlist_modbus_parity, 12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_radius(ui->scr_base_ddlist_modbus_parity, 10, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_opa(ui->scr_base_ddlist_modbus_parity, 129, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui->scr_base_ddlist_modbus_parity, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_ddlist_modbus_parity, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->scr_base_ddlist_modbus_parity, 0, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write style for scr_base_ddlist_modbus_parity, Part: LV_PART_MAIN, State: LV_STATE_FOCUSED.
    lv_obj_set_style_text_color(ui->scr_base_ddlist_modbus_parity, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_font(ui->scr_base_ddlist_modbus_parity, &lv_font_Roboto_Regular_14, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_opa(ui->scr_base_ddlist_modbus_parity, 255, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_width(ui->scr_base_ddlist_modbus_parity, 1, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_opa(ui->scr_base_ddlist_modbus_parity, 70, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_color(ui->scr_base_ddlist_modbus_parity, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_side(ui->scr_base_ddlist_modbus_parity, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_pad_top(ui->scr_base_ddlist_modbus_parity, 12, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_pad_left(ui->scr_base_ddlist_modbus_parity, 12, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_pad_right(ui->scr_base_ddlist_modbus_parity, 12, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_radius(ui->scr_base_ddlist_modbus_parity, 10, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_opa(ui->scr_base_ddlist_modbus_parity, 130, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_color(ui->scr_base_ddlist_modbus_parity, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_ddlist_modbus_parity, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_shadow_width(ui->scr_base_ddlist_modbus_parity, 0, LV_PART_MAIN|LV_STATE_FOCUSED);

    //Write style for scr_base_ddlist_modbus_parity, Part: LV_PART_MAIN, State: LV_STATE_DISABLED.
    lv_obj_set_style_text_color(ui->scr_base_ddlist_modbus_parity, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_font(ui->scr_base_ddlist_modbus_parity, &lv_font_Roboto_Regular_14, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_opa(ui->scr_base_ddlist_modbus_parity, 255, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_border_width(ui->scr_base_ddlist_modbus_parity, 1, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_border_opa(ui->scr_base_ddlist_modbus_parity, 61, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_border_color(ui->scr_base_ddlist_modbus_parity, lv_color_hex(0xe1e6ee), LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_border_side(ui->scr_base_ddlist_modbus_parity, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_pad_top(ui->scr_base_ddlist_modbus_parity, 12, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_pad_left(ui->scr_base_ddlist_modbus_parity, 12, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_pad_right(ui->scr_base_ddlist_modbus_parity, 12, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_radius(ui->scr_base_ddlist_modbus_parity, 10, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_bg_opa(ui->scr_base_ddlist_modbus_parity, 130, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_bg_color(ui->scr_base_ddlist_modbus_parity, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_ddlist_modbus_parity, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_shadow_width(ui->scr_base_ddlist_modbus_parity, 0, LV_PART_MAIN|LV_STATE_DISABLED);

    //Write style state: LV_STATE_CHECKED for &style_scr_base_ddlist_modbus_parity_extra_list_selected_checked
    static lv_style_t style_scr_base_ddlist_modbus_parity_extra_list_selected_checked;
    ui_init_style(&style_scr_base_ddlist_modbus_parity_extra_list_selected_checked);

    lv_style_set_border_width(&style_scr_base_ddlist_modbus_parity_extra_list_selected_checked, 1);
    lv_style_set_border_opa(&style_scr_base_ddlist_modbus_parity_extra_list_selected_checked, 255);
    lv_style_set_border_color(&style_scr_base_ddlist_modbus_parity_extra_list_selected_checked, lv_color_hex(0xe1e6ee));
    lv_style_set_border_side(&style_scr_base_ddlist_modbus_parity_extra_list_selected_checked, LV_BORDER_SIDE_FULL);
    lv_style_set_radius(&style_scr_base_ddlist_modbus_parity_extra_list_selected_checked, 1);
    lv_style_set_bg_opa(&style_scr_base_ddlist_modbus_parity_extra_list_selected_checked, 129);
    lv_style_set_bg_color(&style_scr_base_ddlist_modbus_parity_extra_list_selected_checked, lv_color_hex(0x00a1b5));
    lv_style_set_bg_grad_dir(&style_scr_base_ddlist_modbus_parity_extra_list_selected_checked, LV_GRAD_DIR_NONE);
    lv_obj_add_style(lv_dropdown_get_list(ui->scr_base_ddlist_modbus_parity), &style_scr_base_ddlist_modbus_parity_extra_list_selected_checked, LV_PART_SELECTED|LV_STATE_CHECKED);

    //Write style state: LV_STATE_DEFAULT for &style_scr_base_ddlist_modbus_parity_extra_list_main_default
    static lv_style_t style_scr_base_ddlist_modbus_parity_extra_list_main_default;
    ui_init_style(&style_scr_base_ddlist_modbus_parity_extra_list_main_default);

    lv_style_set_max_height(&style_scr_base_ddlist_modbus_parity_extra_list_main_default, 90);
    lv_style_set_text_color(&style_scr_base_ddlist_modbus_parity_extra_list_main_default, lv_color_hex(0xfdfdfd));
    lv_style_set_text_font(&style_scr_base_ddlist_modbus_parity_extra_list_main_default, &lv_font_Roboto_Regular_14);
    lv_style_set_text_opa(&style_scr_base_ddlist_modbus_parity_extra_list_main_default, 255);
    lv_style_set_border_width(&style_scr_base_ddlist_modbus_parity_extra_list_main_default, 1);
    lv_style_set_border_opa(&style_scr_base_ddlist_modbus_parity_extra_list_main_default, 54);
    lv_style_set_border_color(&style_scr_base_ddlist_modbus_parity_extra_list_main_default, lv_color_hex(0xffffff));
    lv_style_set_border_side(&style_scr_base_ddlist_modbus_parity_extra_list_main_default, LV_BORDER_SIDE_FULL);
    lv_style_set_radius(&style_scr_base_ddlist_modbus_parity_extra_list_main_default, 5);
    lv_style_set_bg_opa(&style_scr_base_ddlist_modbus_parity_extra_list_main_default, 129);
    lv_style_set_bg_color(&style_scr_base_ddlist_modbus_parity_extra_list_main_default, lv_color_hex(0x000000));
    lv_style_set_bg_grad_dir(&style_scr_base_ddlist_modbus_parity_extra_list_main_default, LV_GRAD_DIR_NONE);
    lv_obj_add_style(lv_dropdown_get_list(ui->scr_base_ddlist_modbus_parity), &style_scr_base_ddlist_modbus_parity_extra_list_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_DEFAULT for &style_scr_base_ddlist_modbus_parity_extra_list_scrollbar_default
    static lv_style_t style_scr_base_ddlist_modbus_parity_extra_list_scrollbar_default;
    ui_init_style(&style_scr_base_ddlist_modbus_parity_extra_list_scrollbar_default);

    lv_style_set_radius(&style_scr_base_ddlist_modbus_parity_extra_list_scrollbar_default, 3);
    lv_style_set_bg_opa(&style_scr_base_ddlist_modbus_parity_extra_list_scrollbar_default, 54);
    lv_style_set_bg_color(&style_scr_base_ddlist_modbus_parity_extra_list_scrollbar_default, lv_color_hex(0xcccccc));
    lv_style_set_bg_grad_dir(&style_scr_base_ddlist_modbus_parity_extra_list_scrollbar_default, LV_GRAD_DIR_NONE);
    lv_obj_add_style(lv_dropdown_get_list(ui->scr_base_ddlist_modbus_parity), &style_scr_base_ddlist_modbus_parity_extra_list_scrollbar_default, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);

    //Write codes scr_base_ddlist_modbus_databits
    ui->scr_base_ddlist_modbus_databits = lv_dropdown_create(ui->scr_base_cont_54);
    lv_obj_set_pos(ui->scr_base_ddlist_modbus_databits, 307, 135);
    lv_obj_set_size(ui->scr_base_ddlist_modbus_databits, 133, 38);
    lv_dropdown_set_options(ui->scr_base_ddlist_modbus_databits, "8\n7");

    //Write style for scr_base_ddlist_modbus_databits, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->scr_base_ddlist_modbus_databits, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_ddlist_modbus_databits, &lv_font_Roboto_Regular_14, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_ddlist_modbus_databits, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->scr_base_ddlist_modbus_databits, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scr_base_ddlist_modbus_databits, 56, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scr_base_ddlist_modbus_databits, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scr_base_ddlist_modbus_databits, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_ddlist_modbus_databits, 12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_ddlist_modbus_databits, 12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_ddlist_modbus_databits, 12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_ddlist_modbus_databits, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_ddlist_modbus_databits, 130, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_base_ddlist_modbus_databits, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_ddlist_modbus_databits, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_ddlist_modbus_databits, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for scr_base_ddlist_modbus_databits, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_text_color(ui->scr_base_ddlist_modbus_databits, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->scr_base_ddlist_modbus_databits, &lv_font_Roboto_Regular_14, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->scr_base_ddlist_modbus_databits, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_border_width(ui->scr_base_ddlist_modbus_databits, 1, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_border_opa(ui->scr_base_ddlist_modbus_databits, 58, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_border_color(ui->scr_base_ddlist_modbus_databits, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_border_side(ui->scr_base_ddlist_modbus_databits, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_pad_top(ui->scr_base_ddlist_modbus_databits, 12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_pad_left(ui->scr_base_ddlist_modbus_databits, 12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_pad_right(ui->scr_base_ddlist_modbus_databits, 12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_radius(ui->scr_base_ddlist_modbus_databits, 10, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_opa(ui->scr_base_ddlist_modbus_databits, 129, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui->scr_base_ddlist_modbus_databits, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_ddlist_modbus_databits, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->scr_base_ddlist_modbus_databits, 0, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write style for scr_base_ddlist_modbus_databits, Part: LV_PART_MAIN, State: LV_STATE_FOCUSED.
    lv_obj_set_style_text_color(ui->scr_base_ddlist_modbus_databits, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_font(ui->scr_base_ddlist_modbus_databits, &lv_font_Roboto_Regular_14, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_opa(ui->scr_base_ddlist_modbus_databits, 255, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_width(ui->scr_base_ddlist_modbus_databits, 1, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_opa(ui->scr_base_ddlist_modbus_databits, 70, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_color(ui->scr_base_ddlist_modbus_databits, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_side(ui->scr_base_ddlist_modbus_databits, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_pad_top(ui->scr_base_ddlist_modbus_databits, 12, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_pad_left(ui->scr_base_ddlist_modbus_databits, 12, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_pad_right(ui->scr_base_ddlist_modbus_databits, 12, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_radius(ui->scr_base_ddlist_modbus_databits, 10, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_opa(ui->scr_base_ddlist_modbus_databits, 130, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_color(ui->scr_base_ddlist_modbus_databits, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_ddlist_modbus_databits, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_shadow_width(ui->scr_base_ddlist_modbus_databits, 0, LV_PART_MAIN|LV_STATE_FOCUSED);

    //Write style for scr_base_ddlist_modbus_databits, Part: LV_PART_MAIN, State: LV_STATE_DISABLED.
    lv_obj_set_style_text_color(ui->scr_base_ddlist_modbus_databits, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_font(ui->scr_base_ddlist_modbus_databits, &lv_font_Roboto_Regular_14, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_opa(ui->scr_base_ddlist_modbus_databits, 255, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_border_width(ui->scr_base_ddlist_modbus_databits, 1, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_border_opa(ui->scr_base_ddlist_modbus_databits, 61, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_border_color(ui->scr_base_ddlist_modbus_databits, lv_color_hex(0xe1e6ee), LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_border_side(ui->scr_base_ddlist_modbus_databits, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_pad_top(ui->scr_base_ddlist_modbus_databits, 12, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_pad_left(ui->scr_base_ddlist_modbus_databits, 12, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_pad_right(ui->scr_base_ddlist_modbus_databits, 12, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_radius(ui->scr_base_ddlist_modbus_databits, 10, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_bg_opa(ui->scr_base_ddlist_modbus_databits, 130, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_bg_color(ui->scr_base_ddlist_modbus_databits, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_ddlist_modbus_databits, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_shadow_width(ui->scr_base_ddlist_modbus_databits, 0, LV_PART_MAIN|LV_STATE_DISABLED);

    //Write style state: LV_STATE_CHECKED for &style_scr_base_ddlist_modbus_databits_extra_list_selected_checked
    static lv_style_t style_scr_base_ddlist_modbus_databits_extra_list_selected_checked;
    ui_init_style(&style_scr_base_ddlist_modbus_databits_extra_list_selected_checked);

    lv_style_set_border_width(&style_scr_base_ddlist_modbus_databits_extra_list_selected_checked, 1);
    lv_style_set_border_opa(&style_scr_base_ddlist_modbus_databits_extra_list_selected_checked, 255);
    lv_style_set_border_color(&style_scr_base_ddlist_modbus_databits_extra_list_selected_checked, lv_color_hex(0xe1e6ee));
    lv_style_set_border_side(&style_scr_base_ddlist_modbus_databits_extra_list_selected_checked, LV_BORDER_SIDE_FULL);
    lv_style_set_radius(&style_scr_base_ddlist_modbus_databits_extra_list_selected_checked, 1);
    lv_style_set_bg_opa(&style_scr_base_ddlist_modbus_databits_extra_list_selected_checked, 129);
    lv_style_set_bg_color(&style_scr_base_ddlist_modbus_databits_extra_list_selected_checked, lv_color_hex(0x00a1b5));
    lv_style_set_bg_grad_dir(&style_scr_base_ddlist_modbus_databits_extra_list_selected_checked, LV_GRAD_DIR_NONE);
    lv_obj_add_style(lv_dropdown_get_list(ui->scr_base_ddlist_modbus_databits), &style_scr_base_ddlist_modbus_databits_extra_list_selected_checked, LV_PART_SELECTED|LV_STATE_CHECKED);

    //Write style state: LV_STATE_DEFAULT for &style_scr_base_ddlist_modbus_databits_extra_list_main_default
    static lv_style_t style_scr_base_ddlist_modbus_databits_extra_list_main_default;
    ui_init_style(&style_scr_base_ddlist_modbus_databits_extra_list_main_default);

    lv_style_set_max_height(&style_scr_base_ddlist_modbus_databits_extra_list_main_default, 90);
    lv_style_set_text_color(&style_scr_base_ddlist_modbus_databits_extra_list_main_default, lv_color_hex(0xfdfdfd));
    lv_style_set_text_font(&style_scr_base_ddlist_modbus_databits_extra_list_main_default, &lv_font_Roboto_Regular_14);
    lv_style_set_text_opa(&style_scr_base_ddlist_modbus_databits_extra_list_main_default, 255);
    lv_style_set_border_width(&style_scr_base_ddlist_modbus_databits_extra_list_main_default, 1);
    lv_style_set_border_opa(&style_scr_base_ddlist_modbus_databits_extra_list_main_default, 54);
    lv_style_set_border_color(&style_scr_base_ddlist_modbus_databits_extra_list_main_default, lv_color_hex(0xffffff));
    lv_style_set_border_side(&style_scr_base_ddlist_modbus_databits_extra_list_main_default, LV_BORDER_SIDE_FULL);
    lv_style_set_radius(&style_scr_base_ddlist_modbus_databits_extra_list_main_default, 5);
    lv_style_set_bg_opa(&style_scr_base_ddlist_modbus_databits_extra_list_main_default, 129);
    lv_style_set_bg_color(&style_scr_base_ddlist_modbus_databits_extra_list_main_default, lv_color_hex(0x000000));
    lv_style_set_bg_grad_dir(&style_scr_base_ddlist_modbus_databits_extra_list_main_default, LV_GRAD_DIR_NONE);
    lv_obj_add_style(lv_dropdown_get_list(ui->scr_base_ddlist_modbus_databits), &style_scr_base_ddlist_modbus_databits_extra_list_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_DEFAULT for &style_scr_base_ddlist_modbus_databits_extra_list_scrollbar_default
    static lv_style_t style_scr_base_ddlist_modbus_databits_extra_list_scrollbar_default;
    ui_init_style(&style_scr_base_ddlist_modbus_databits_extra_list_scrollbar_default);

    lv_style_set_radius(&style_scr_base_ddlist_modbus_databits_extra_list_scrollbar_default, 3);
    lv_style_set_bg_opa(&style_scr_base_ddlist_modbus_databits_extra_list_scrollbar_default, 54);
    lv_style_set_bg_color(&style_scr_base_ddlist_modbus_databits_extra_list_scrollbar_default, lv_color_hex(0xcccccc));
    lv_style_set_bg_grad_dir(&style_scr_base_ddlist_modbus_databits_extra_list_scrollbar_default, LV_GRAD_DIR_NONE);
    lv_obj_add_style(lv_dropdown_get_list(ui->scr_base_ddlist_modbus_databits), &style_scr_base_ddlist_modbus_databits_extra_list_scrollbar_default, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);

    //Write codes scr_base_ddlist_modbus_stopbits
    ui->scr_base_ddlist_modbus_stopbits = lv_dropdown_create(ui->scr_base_cont_54);
    lv_obj_set_pos(ui->scr_base_ddlist_modbus_stopbits, 449, 135);
    lv_obj_set_size(ui->scr_base_ddlist_modbus_stopbits, 133, 38);
    lv_dropdown_set_options(ui->scr_base_ddlist_modbus_stopbits, "1\n1.5\n2");

    //Write style for scr_base_ddlist_modbus_stopbits, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->scr_base_ddlist_modbus_stopbits, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_ddlist_modbus_stopbits, &lv_font_Roboto_Regular_14, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_ddlist_modbus_stopbits, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->scr_base_ddlist_modbus_stopbits, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scr_base_ddlist_modbus_stopbits, 56, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scr_base_ddlist_modbus_stopbits, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scr_base_ddlist_modbus_stopbits, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_ddlist_modbus_stopbits, 12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_ddlist_modbus_stopbits, 12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_ddlist_modbus_stopbits, 12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_ddlist_modbus_stopbits, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_ddlist_modbus_stopbits, 130, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_base_ddlist_modbus_stopbits, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_ddlist_modbus_stopbits, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_ddlist_modbus_stopbits, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for scr_base_ddlist_modbus_stopbits, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_text_color(ui->scr_base_ddlist_modbus_stopbits, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->scr_base_ddlist_modbus_stopbits, &lv_font_Roboto_Regular_14, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->scr_base_ddlist_modbus_stopbits, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_border_width(ui->scr_base_ddlist_modbus_stopbits, 1, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_border_opa(ui->scr_base_ddlist_modbus_stopbits, 58, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_border_color(ui->scr_base_ddlist_modbus_stopbits, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_border_side(ui->scr_base_ddlist_modbus_stopbits, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_pad_top(ui->scr_base_ddlist_modbus_stopbits, 12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_pad_left(ui->scr_base_ddlist_modbus_stopbits, 12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_pad_right(ui->scr_base_ddlist_modbus_stopbits, 12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_radius(ui->scr_base_ddlist_modbus_stopbits, 10, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_opa(ui->scr_base_ddlist_modbus_stopbits, 129, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui->scr_base_ddlist_modbus_stopbits, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_ddlist_modbus_stopbits, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->scr_base_ddlist_modbus_stopbits, 0, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write style for scr_base_ddlist_modbus_stopbits, Part: LV_PART_MAIN, State: LV_STATE_FOCUSED.
    lv_obj_set_style_text_color(ui->scr_base_ddlist_modbus_stopbits, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_font(ui->scr_base_ddlist_modbus_stopbits, &lv_font_Roboto_Regular_14, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_opa(ui->scr_base_ddlist_modbus_stopbits, 255, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_width(ui->scr_base_ddlist_modbus_stopbits, 1, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_opa(ui->scr_base_ddlist_modbus_stopbits, 70, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_color(ui->scr_base_ddlist_modbus_stopbits, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_side(ui->scr_base_ddlist_modbus_stopbits, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_pad_top(ui->scr_base_ddlist_modbus_stopbits, 12, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_pad_left(ui->scr_base_ddlist_modbus_stopbits, 12, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_pad_right(ui->scr_base_ddlist_modbus_stopbits, 12, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_radius(ui->scr_base_ddlist_modbus_stopbits, 10, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_opa(ui->scr_base_ddlist_modbus_stopbits, 130, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_color(ui->scr_base_ddlist_modbus_stopbits, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_ddlist_modbus_stopbits, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_shadow_width(ui->scr_base_ddlist_modbus_stopbits, 0, LV_PART_MAIN|LV_STATE_FOCUSED);

    //Write style for scr_base_ddlist_modbus_stopbits, Part: LV_PART_MAIN, State: LV_STATE_DISABLED.
    lv_obj_set_style_text_color(ui->scr_base_ddlist_modbus_stopbits, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_font(ui->scr_base_ddlist_modbus_stopbits, &lv_font_Roboto_Regular_14, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_opa(ui->scr_base_ddlist_modbus_stopbits, 255, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_border_width(ui->scr_base_ddlist_modbus_stopbits, 1, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_border_opa(ui->scr_base_ddlist_modbus_stopbits, 61, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_border_color(ui->scr_base_ddlist_modbus_stopbits, lv_color_hex(0xe1e6ee), LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_border_side(ui->scr_base_ddlist_modbus_stopbits, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_pad_top(ui->scr_base_ddlist_modbus_stopbits, 12, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_pad_left(ui->scr_base_ddlist_modbus_stopbits, 12, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_pad_right(ui->scr_base_ddlist_modbus_stopbits, 12, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_radius(ui->scr_base_ddlist_modbus_stopbits, 10, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_bg_opa(ui->scr_base_ddlist_modbus_stopbits, 130, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_bg_color(ui->scr_base_ddlist_modbus_stopbits, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_ddlist_modbus_stopbits, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_shadow_width(ui->scr_base_ddlist_modbus_stopbits, 0, LV_PART_MAIN|LV_STATE_DISABLED);

    //Write style state: LV_STATE_CHECKED for &style_scr_base_ddlist_modbus_stopbits_extra_list_selected_checked
    static lv_style_t style_scr_base_ddlist_modbus_stopbits_extra_list_selected_checked;
    ui_init_style(&style_scr_base_ddlist_modbus_stopbits_extra_list_selected_checked);

    lv_style_set_border_width(&style_scr_base_ddlist_modbus_stopbits_extra_list_selected_checked, 1);
    lv_style_set_border_opa(&style_scr_base_ddlist_modbus_stopbits_extra_list_selected_checked, 255);
    lv_style_set_border_color(&style_scr_base_ddlist_modbus_stopbits_extra_list_selected_checked, lv_color_hex(0xe1e6ee));
    lv_style_set_border_side(&style_scr_base_ddlist_modbus_stopbits_extra_list_selected_checked, LV_BORDER_SIDE_FULL);
    lv_style_set_radius(&style_scr_base_ddlist_modbus_stopbits_extra_list_selected_checked, 1);
    lv_style_set_bg_opa(&style_scr_base_ddlist_modbus_stopbits_extra_list_selected_checked, 129);
    lv_style_set_bg_color(&style_scr_base_ddlist_modbus_stopbits_extra_list_selected_checked, lv_color_hex(0x00a1b5));
    lv_style_set_bg_grad_dir(&style_scr_base_ddlist_modbus_stopbits_extra_list_selected_checked, LV_GRAD_DIR_NONE);
    lv_obj_add_style(lv_dropdown_get_list(ui->scr_base_ddlist_modbus_stopbits), &style_scr_base_ddlist_modbus_stopbits_extra_list_selected_checked, LV_PART_SELECTED|LV_STATE_CHECKED);

    //Write style state: LV_STATE_DEFAULT for &style_scr_base_ddlist_modbus_stopbits_extra_list_main_default
    static lv_style_t style_scr_base_ddlist_modbus_stopbits_extra_list_main_default;
    ui_init_style(&style_scr_base_ddlist_modbus_stopbits_extra_list_main_default);

    lv_style_set_max_height(&style_scr_base_ddlist_modbus_stopbits_extra_list_main_default, 90);
    lv_style_set_text_color(&style_scr_base_ddlist_modbus_stopbits_extra_list_main_default, lv_color_hex(0xfdfdfd));
    lv_style_set_text_font(&style_scr_base_ddlist_modbus_stopbits_extra_list_main_default, &lv_font_Roboto_Regular_14);
    lv_style_set_text_opa(&style_scr_base_ddlist_modbus_stopbits_extra_list_main_default, 255);
    lv_style_set_border_width(&style_scr_base_ddlist_modbus_stopbits_extra_list_main_default, 1);
    lv_style_set_border_opa(&style_scr_base_ddlist_modbus_stopbits_extra_list_main_default, 54);
    lv_style_set_border_color(&style_scr_base_ddlist_modbus_stopbits_extra_list_main_default, lv_color_hex(0xffffff));
    lv_style_set_border_side(&style_scr_base_ddlist_modbus_stopbits_extra_list_main_default, LV_BORDER_SIDE_FULL);
    lv_style_set_radius(&style_scr_base_ddlist_modbus_stopbits_extra_list_main_default, 5);
    lv_style_set_bg_opa(&style_scr_base_ddlist_modbus_stopbits_extra_list_main_default, 129);
    lv_style_set_bg_color(&style_scr_base_ddlist_modbus_stopbits_extra_list_main_default, lv_color_hex(0x000000));
    lv_style_set_bg_grad_dir(&style_scr_base_ddlist_modbus_stopbits_extra_list_main_default, LV_GRAD_DIR_NONE);
    lv_obj_add_style(lv_dropdown_get_list(ui->scr_base_ddlist_modbus_stopbits), &style_scr_base_ddlist_modbus_stopbits_extra_list_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_DEFAULT for &style_scr_base_ddlist_modbus_stopbits_extra_list_scrollbar_default
    static lv_style_t style_scr_base_ddlist_modbus_stopbits_extra_list_scrollbar_default;
    ui_init_style(&style_scr_base_ddlist_modbus_stopbits_extra_list_scrollbar_default);

    lv_style_set_radius(&style_scr_base_ddlist_modbus_stopbits_extra_list_scrollbar_default, 3);
    lv_style_set_bg_opa(&style_scr_base_ddlist_modbus_stopbits_extra_list_scrollbar_default, 54);
    lv_style_set_bg_color(&style_scr_base_ddlist_modbus_stopbits_extra_list_scrollbar_default, lv_color_hex(0xcccccc));
    lv_style_set_bg_grad_dir(&style_scr_base_ddlist_modbus_stopbits_extra_list_scrollbar_default, LV_GRAD_DIR_NONE);
    lv_obj_add_style(lv_dropdown_get_list(ui->scr_base_ddlist_modbus_stopbits), &style_scr_base_ddlist_modbus_stopbits_extra_list_scrollbar_default, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);

    //Write codes scr_base_ddlist_modbus_baudrate
    ui->scr_base_ddlist_modbus_baudrate = lv_dropdown_create(ui->scr_base_cont_54);
    lv_obj_set_pos(ui->scr_base_ddlist_modbus_baudrate, 23, 135);
    lv_obj_set_size(ui->scr_base_ddlist_modbus_baudrate, 133, 38);
    lv_dropdown_set_options(ui->scr_base_ddlist_modbus_baudrate, "4800\n9600\n14400\n19200\n115200");

    //Write style for scr_base_ddlist_modbus_baudrate, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->scr_base_ddlist_modbus_baudrate, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_ddlist_modbus_baudrate, &lv_font_Roboto_Regular_14, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_ddlist_modbus_baudrate, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->scr_base_ddlist_modbus_baudrate, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scr_base_ddlist_modbus_baudrate, 56, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scr_base_ddlist_modbus_baudrate, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scr_base_ddlist_modbus_baudrate, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_ddlist_modbus_baudrate, 12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_ddlist_modbus_baudrate, 12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_ddlist_modbus_baudrate, 12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_ddlist_modbus_baudrate, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_ddlist_modbus_baudrate, 130, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_base_ddlist_modbus_baudrate, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_ddlist_modbus_baudrate, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_ddlist_modbus_baudrate, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for scr_base_ddlist_modbus_baudrate, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_text_color(ui->scr_base_ddlist_modbus_baudrate, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->scr_base_ddlist_modbus_baudrate, &lv_font_Roboto_Regular_14, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->scr_base_ddlist_modbus_baudrate, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_border_width(ui->scr_base_ddlist_modbus_baudrate, 1, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_border_opa(ui->scr_base_ddlist_modbus_baudrate, 58, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_border_color(ui->scr_base_ddlist_modbus_baudrate, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_border_side(ui->scr_base_ddlist_modbus_baudrate, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_pad_top(ui->scr_base_ddlist_modbus_baudrate, 12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_pad_left(ui->scr_base_ddlist_modbus_baudrate, 12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_pad_right(ui->scr_base_ddlist_modbus_baudrate, 12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_radius(ui->scr_base_ddlist_modbus_baudrate, 10, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_opa(ui->scr_base_ddlist_modbus_baudrate, 129, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui->scr_base_ddlist_modbus_baudrate, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_ddlist_modbus_baudrate, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->scr_base_ddlist_modbus_baudrate, 0, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write style for scr_base_ddlist_modbus_baudrate, Part: LV_PART_MAIN, State: LV_STATE_FOCUSED.
    lv_obj_set_style_text_color(ui->scr_base_ddlist_modbus_baudrate, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_font(ui->scr_base_ddlist_modbus_baudrate, &lv_font_Roboto_Regular_14, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_opa(ui->scr_base_ddlist_modbus_baudrate, 255, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_width(ui->scr_base_ddlist_modbus_baudrate, 1, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_opa(ui->scr_base_ddlist_modbus_baudrate, 70, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_color(ui->scr_base_ddlist_modbus_baudrate, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_side(ui->scr_base_ddlist_modbus_baudrate, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_pad_top(ui->scr_base_ddlist_modbus_baudrate, 12, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_pad_left(ui->scr_base_ddlist_modbus_baudrate, 12, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_pad_right(ui->scr_base_ddlist_modbus_baudrate, 12, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_radius(ui->scr_base_ddlist_modbus_baudrate, 10, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_opa(ui->scr_base_ddlist_modbus_baudrate, 130, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_color(ui->scr_base_ddlist_modbus_baudrate, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_ddlist_modbus_baudrate, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_shadow_width(ui->scr_base_ddlist_modbus_baudrate, 0, LV_PART_MAIN|LV_STATE_FOCUSED);

    //Write style for scr_base_ddlist_modbus_baudrate, Part: LV_PART_MAIN, State: LV_STATE_DISABLED.
    lv_obj_set_style_text_color(ui->scr_base_ddlist_modbus_baudrate, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_font(ui->scr_base_ddlist_modbus_baudrate, &lv_font_Roboto_Regular_14, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_opa(ui->scr_base_ddlist_modbus_baudrate, 255, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_border_width(ui->scr_base_ddlist_modbus_baudrate, 1, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_border_opa(ui->scr_base_ddlist_modbus_baudrate, 61, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_border_color(ui->scr_base_ddlist_modbus_baudrate, lv_color_hex(0xe1e6ee), LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_border_side(ui->scr_base_ddlist_modbus_baudrate, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_pad_top(ui->scr_base_ddlist_modbus_baudrate, 12, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_pad_left(ui->scr_base_ddlist_modbus_baudrate, 12, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_pad_right(ui->scr_base_ddlist_modbus_baudrate, 12, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_radius(ui->scr_base_ddlist_modbus_baudrate, 10, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_bg_opa(ui->scr_base_ddlist_modbus_baudrate, 130, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_bg_color(ui->scr_base_ddlist_modbus_baudrate, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_ddlist_modbus_baudrate, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_shadow_width(ui->scr_base_ddlist_modbus_baudrate, 0, LV_PART_MAIN|LV_STATE_DISABLED);

    //Write style state: LV_STATE_CHECKED for &style_scr_base_ddlist_modbus_baudrate_extra_list_selected_checked
    static lv_style_t style_scr_base_ddlist_modbus_baudrate_extra_list_selected_checked;
    ui_init_style(&style_scr_base_ddlist_modbus_baudrate_extra_list_selected_checked);

    lv_style_set_border_width(&style_scr_base_ddlist_modbus_baudrate_extra_list_selected_checked, 1);
    lv_style_set_border_opa(&style_scr_base_ddlist_modbus_baudrate_extra_list_selected_checked, 255);
    lv_style_set_border_color(&style_scr_base_ddlist_modbus_baudrate_extra_list_selected_checked, lv_color_hex(0xe1e6ee));
    lv_style_set_border_side(&style_scr_base_ddlist_modbus_baudrate_extra_list_selected_checked, LV_BORDER_SIDE_FULL);
    lv_style_set_radius(&style_scr_base_ddlist_modbus_baudrate_extra_list_selected_checked, 1);
    lv_style_set_bg_opa(&style_scr_base_ddlist_modbus_baudrate_extra_list_selected_checked, 129);
    lv_style_set_bg_color(&style_scr_base_ddlist_modbus_baudrate_extra_list_selected_checked, lv_color_hex(0x00a1b5));
    lv_style_set_bg_grad_dir(&style_scr_base_ddlist_modbus_baudrate_extra_list_selected_checked, LV_GRAD_DIR_NONE);
    lv_obj_add_style(lv_dropdown_get_list(ui->scr_base_ddlist_modbus_baudrate), &style_scr_base_ddlist_modbus_baudrate_extra_list_selected_checked, LV_PART_SELECTED|LV_STATE_CHECKED);

    //Write style state: LV_STATE_DEFAULT for &style_scr_base_ddlist_modbus_baudrate_extra_list_main_default
    static lv_style_t style_scr_base_ddlist_modbus_baudrate_extra_list_main_default;
    ui_init_style(&style_scr_base_ddlist_modbus_baudrate_extra_list_main_default);

    lv_style_set_max_height(&style_scr_base_ddlist_modbus_baudrate_extra_list_main_default, 90);
    lv_style_set_text_color(&style_scr_base_ddlist_modbus_baudrate_extra_list_main_default, lv_color_hex(0xfdfdfd));
    lv_style_set_text_font(&style_scr_base_ddlist_modbus_baudrate_extra_list_main_default, &lv_font_Roboto_Regular_14);
    lv_style_set_text_opa(&style_scr_base_ddlist_modbus_baudrate_extra_list_main_default, 255);
    lv_style_set_border_width(&style_scr_base_ddlist_modbus_baudrate_extra_list_main_default, 1);
    lv_style_set_border_opa(&style_scr_base_ddlist_modbus_baudrate_extra_list_main_default, 54);
    lv_style_set_border_color(&style_scr_base_ddlist_modbus_baudrate_extra_list_main_default, lv_color_hex(0xffffff));
    lv_style_set_border_side(&style_scr_base_ddlist_modbus_baudrate_extra_list_main_default, LV_BORDER_SIDE_FULL);
    lv_style_set_radius(&style_scr_base_ddlist_modbus_baudrate_extra_list_main_default, 5);
    lv_style_set_bg_opa(&style_scr_base_ddlist_modbus_baudrate_extra_list_main_default, 129);
    lv_style_set_bg_color(&style_scr_base_ddlist_modbus_baudrate_extra_list_main_default, lv_color_hex(0x000000));
    lv_style_set_bg_grad_dir(&style_scr_base_ddlist_modbus_baudrate_extra_list_main_default, LV_GRAD_DIR_NONE);
    lv_obj_add_style(lv_dropdown_get_list(ui->scr_base_ddlist_modbus_baudrate), &style_scr_base_ddlist_modbus_baudrate_extra_list_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_DEFAULT for &style_scr_base_ddlist_modbus_baudrate_extra_list_scrollbar_default
    static lv_style_t style_scr_base_ddlist_modbus_baudrate_extra_list_scrollbar_default;
    ui_init_style(&style_scr_base_ddlist_modbus_baudrate_extra_list_scrollbar_default);

    lv_style_set_radius(&style_scr_base_ddlist_modbus_baudrate_extra_list_scrollbar_default, 3);
    lv_style_set_bg_opa(&style_scr_base_ddlist_modbus_baudrate_extra_list_scrollbar_default, 54);
    lv_style_set_bg_color(&style_scr_base_ddlist_modbus_baudrate_extra_list_scrollbar_default, lv_color_hex(0xcccccc));
    lv_style_set_bg_grad_dir(&style_scr_base_ddlist_modbus_baudrate_extra_list_scrollbar_default, LV_GRAD_DIR_NONE);
    lv_obj_add_style(lv_dropdown_get_list(ui->scr_base_ddlist_modbus_baudrate), &style_scr_base_ddlist_modbus_baudrate_extra_list_scrollbar_default, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);

    //Write codes scr_base_cont_system_admin
    ui->scr_base_cont_system_admin = lv_obj_create(ui->scr_base_cont_hw);
    lv_obj_set_pos(ui->scr_base_cont_system_admin, 0, 35);
    lv_obj_set_size(ui->scr_base_cont_system_admin, 677, 380);
    lv_obj_set_scrollbar_mode(ui->scr_base_cont_system_admin, LV_SCROLLBAR_MODE_OFF);
    lv_obj_add_flag(ui->scr_base_cont_system_admin, LV_OBJ_FLAG_HIDDEN);

    //Write style for scr_base_cont_system_admin, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_cont_system_admin, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_cont_system_admin, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_cont_system_admin, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_cont_system_admin, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_cont_system_admin, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_cont_system_admin, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_cont_system_admin, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_cont_system_admin, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_cont_sys_back
    ui->scr_base_cont_sys_back = lv_obj_create(ui->scr_base_cont_system_admin);
    lv_obj_set_pos(ui->scr_base_cont_sys_back, 0, 5);
    lv_obj_set_size(ui->scr_base_cont_sys_back, 40, 40);
    lv_obj_set_scrollbar_mode(ui->scr_base_cont_sys_back, LV_SCROLLBAR_MODE_OFF);

    //Write style for scr_base_cont_sys_back, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_cont_sys_back, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scr_base_cont_sys_back, 71, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scr_base_cont_sys_back, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scr_base_cont_sys_back, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_cont_sys_back, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_cont_sys_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_cont_sys_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_cont_sys_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_cont_sys_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_cont_sys_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_cont_sys_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_img_23
    ui->scr_base_img_23 = lv_image_create(ui->scr_base_cont_sys_back);
    lv_obj_set_pos(ui->scr_base_img_23, 7, 7);
    lv_obj_set_size(ui->scr_base_img_23, 24, 24);
    lv_obj_add_flag(ui->scr_base_img_23, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->scr_base_img_23, &_left_arrow_RGB565A8_24x24);
    lv_image_set_pivot(ui->scr_base_img_23, 50,50);
    lv_image_set_rotation(ui->scr_base_img_23, 0);

    //Write style for scr_base_img_23, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->scr_base_img_23, 189, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_recolor(ui->scr_base_img_23, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->scr_base_img_23, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_btn_sys_back
    ui->scr_base_btn_sys_back = lv_button_create(ui->scr_base_cont_sys_back);
    lv_obj_set_pos(ui->scr_base_btn_sys_back, -6, -6);
    lv_obj_set_size(ui->scr_base_btn_sys_back, 50, 50);
    ui->scr_base_btn_sys_back_label = lv_label_create(ui->scr_base_btn_sys_back);
    lv_label_set_text(ui->scr_base_btn_sys_back_label, "");
    lv_label_set_long_mode(ui->scr_base_btn_sys_back_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->scr_base_btn_sys_back_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->scr_base_btn_sys_back, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->scr_base_btn_sys_back_label, LV_PCT(100));

    //Write style for scr_base_btn_sys_back, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->scr_base_btn_sys_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->scr_base_btn_sys_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_btn_sys_back, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_btn_sys_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_base_btn_sys_back, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_btn_sys_back, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_btn_sys_back, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_btn_sys_back, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for scr_base_btn_sys_back, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_bg_opa(ui->scr_base_btn_sys_back, 42, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_bg_color(ui->scr_base_btn_sys_back, lv_color_hex(0x10B981), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_btn_sys_back, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui->scr_base_btn_sys_back, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_radius(ui->scr_base_btn_sys_back, 10, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->scr_base_btn_sys_back, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->scr_base_btn_sys_back, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->scr_base_btn_sys_back, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->scr_base_btn_sys_back, 255, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for scr_base_btn_sys_back, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_bg_opa(ui->scr_base_btn_sys_back, 44, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui->scr_base_btn_sys_back, lv_color_hex(0x10B981), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_btn_sys_back, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_border_width(ui->scr_base_btn_sys_back, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_radius(ui->scr_base_btn_sys_back, 10, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->scr_base_btn_sys_back, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->scr_base_btn_sys_back, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->scr_base_btn_sys_back, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->scr_base_btn_sys_back, 255, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write codes scr_base_label_194
    ui->scr_base_label_194 = lv_label_create(ui->scr_base_cont_system_admin);
    lv_obj_set_pos(ui->scr_base_label_194, 44, 16);
    lv_obj_set_size(ui->scr_base_label_194, 270, 17);
    lv_label_set_text(ui->scr_base_label_194, "MODBUS RTU CONFIGURATION");
    lv_label_set_long_mode(ui->scr_base_label_194, LV_LABEL_LONG_WRAP);

    //Write style for scr_base_label_194, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_label_194, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_label_194, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_base_label_194, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_label_194, &lv_font_Roboto_Bold_15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_label_194, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_base_label_194, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_base_label_194, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_label_194, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_label_194, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_label_194, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_label_194, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_label_194, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_label_194, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_label_194, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_cont_72
    ui->scr_base_cont_72 = lv_obj_create(ui->scr_base_cont_system_admin);
    lv_obj_set_pos(ui->scr_base_cont_72, 5, 53);
    lv_obj_set_size(ui->scr_base_cont_72, 660, 134);
    lv_obj_set_scrollbar_mode(ui->scr_base_cont_72, LV_SCROLLBAR_MODE_OFF);

    //Write style for scr_base_cont_72, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_cont_72, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scr_base_cont_72, 65, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scr_base_cont_72, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scr_base_cont_72, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_cont_72, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_cont_72, 243, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_base_cont_72, lv_color_hex(0x0F172A), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_cont_72, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_cont_72, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_cont_72, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_cont_72, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_cont_72, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_cont_72, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_label_205
    ui->scr_base_label_205 = lv_label_create(ui->scr_base_cont_72);
    lv_obj_set_pos(ui->scr_base_label_205, 25, 13);
    lv_obj_set_size(ui->scr_base_label_205, 231, 17);
    lv_label_set_text(ui->scr_base_label_205, "DISPLAY CONFIGURATION");
    lv_label_set_long_mode(ui->scr_base_label_205, LV_LABEL_LONG_WRAP);

    //Write style for scr_base_label_205, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_label_205, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_label_205, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_base_label_205, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_label_205, &lv_font_Roboto_Bold_15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_label_205, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_base_label_205, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_base_label_205, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_label_205, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_label_205, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_label_205, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_label_205, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_label_205, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_label_205, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_label_205, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_label_206
    ui->scr_base_label_206 = lv_label_create(ui->scr_base_cont_72);
    lv_obj_set_pos(ui->scr_base_label_206, 26, 40);
    lv_obj_set_size(ui->scr_base_label_206, 166, 17);
    lv_label_set_text(ui->scr_base_label_206, "BRIGHTNESS");
    lv_label_set_long_mode(ui->scr_base_label_206, LV_LABEL_LONG_WRAP);

    //Write style for scr_base_label_206, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_label_206, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_label_206, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_base_label_206, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_label_206, &lv_font_Roboto_Bold_13, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_label_206, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_base_label_206, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_base_label_206, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_label_206, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_label_206, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_label_206, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_label_206, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_label_206, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_label_206, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_label_206, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_label_207
    ui->scr_base_label_207 = lv_label_create(ui->scr_base_cont_72);
    lv_obj_set_pos(ui->scr_base_label_207, 353, 40);
    lv_obj_set_size(ui->scr_base_label_207, 166, 17);
    lv_label_set_text(ui->scr_base_label_207, "SCREEN TIMEOUT");
    lv_label_set_long_mode(ui->scr_base_label_207, LV_LABEL_LONG_WRAP);

    //Write style for scr_base_label_207, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_label_207, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_label_207, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_base_label_207, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_label_207, &lv_font_Roboto_Bold_13, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_label_207, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_base_label_207, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_base_label_207, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_label_207, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_label_207, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_label_207, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_label_207, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_label_207, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_label_207, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_label_207, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_ddlist_screentime_option
    ui->scr_base_ddlist_screentime_option = lv_dropdown_create(ui->scr_base_cont_72);
    lv_obj_set_pos(ui->scr_base_ddlist_screentime_option, 353, 62);
    lv_obj_set_size(ui->scr_base_ddlist_screentime_option, 133, 38);
    lv_dropdown_set_options(ui->scr_base_ddlist_screentime_option, "OFF\n1M\n5M\n10M");

    //Write style for scr_base_ddlist_screentime_option, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->scr_base_ddlist_screentime_option, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_ddlist_screentime_option, &lv_font_Roboto_Regular_14, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_ddlist_screentime_option, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->scr_base_ddlist_screentime_option, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scr_base_ddlist_screentime_option, 56, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scr_base_ddlist_screentime_option, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scr_base_ddlist_screentime_option, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_ddlist_screentime_option, 12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_ddlist_screentime_option, 12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_ddlist_screentime_option, 12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_ddlist_screentime_option, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_ddlist_screentime_option, 130, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_base_ddlist_screentime_option, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_ddlist_screentime_option, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_ddlist_screentime_option, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for scr_base_ddlist_screentime_option, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_text_color(ui->scr_base_ddlist_screentime_option, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->scr_base_ddlist_screentime_option, &lv_font_Roboto_Regular_14, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->scr_base_ddlist_screentime_option, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_border_width(ui->scr_base_ddlist_screentime_option, 1, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_border_opa(ui->scr_base_ddlist_screentime_option, 58, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_border_color(ui->scr_base_ddlist_screentime_option, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_border_side(ui->scr_base_ddlist_screentime_option, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_pad_top(ui->scr_base_ddlist_screentime_option, 12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_pad_left(ui->scr_base_ddlist_screentime_option, 12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_pad_right(ui->scr_base_ddlist_screentime_option, 12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_radius(ui->scr_base_ddlist_screentime_option, 10, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_opa(ui->scr_base_ddlist_screentime_option, 129, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui->scr_base_ddlist_screentime_option, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_ddlist_screentime_option, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->scr_base_ddlist_screentime_option, 0, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write style for scr_base_ddlist_screentime_option, Part: LV_PART_MAIN, State: LV_STATE_FOCUSED.
    lv_obj_set_style_text_color(ui->scr_base_ddlist_screentime_option, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_font(ui->scr_base_ddlist_screentime_option, &lv_font_Roboto_Regular_14, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_opa(ui->scr_base_ddlist_screentime_option, 255, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_width(ui->scr_base_ddlist_screentime_option, 1, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_opa(ui->scr_base_ddlist_screentime_option, 70, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_color(ui->scr_base_ddlist_screentime_option, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_side(ui->scr_base_ddlist_screentime_option, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_pad_top(ui->scr_base_ddlist_screentime_option, 12, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_pad_left(ui->scr_base_ddlist_screentime_option, 12, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_pad_right(ui->scr_base_ddlist_screentime_option, 12, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_radius(ui->scr_base_ddlist_screentime_option, 10, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_opa(ui->scr_base_ddlist_screentime_option, 130, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_color(ui->scr_base_ddlist_screentime_option, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_ddlist_screentime_option, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_shadow_width(ui->scr_base_ddlist_screentime_option, 0, LV_PART_MAIN|LV_STATE_FOCUSED);

    //Write style for scr_base_ddlist_screentime_option, Part: LV_PART_MAIN, State: LV_STATE_DISABLED.
    lv_obj_set_style_text_color(ui->scr_base_ddlist_screentime_option, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_font(ui->scr_base_ddlist_screentime_option, &lv_font_Roboto_Regular_14, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_opa(ui->scr_base_ddlist_screentime_option, 255, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_border_width(ui->scr_base_ddlist_screentime_option, 1, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_border_opa(ui->scr_base_ddlist_screentime_option, 61, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_border_color(ui->scr_base_ddlist_screentime_option, lv_color_hex(0xe1e6ee), LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_border_side(ui->scr_base_ddlist_screentime_option, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_pad_top(ui->scr_base_ddlist_screentime_option, 12, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_pad_left(ui->scr_base_ddlist_screentime_option, 12, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_pad_right(ui->scr_base_ddlist_screentime_option, 12, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_radius(ui->scr_base_ddlist_screentime_option, 10, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_bg_opa(ui->scr_base_ddlist_screentime_option, 130, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_bg_color(ui->scr_base_ddlist_screentime_option, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_ddlist_screentime_option, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_shadow_width(ui->scr_base_ddlist_screentime_option, 0, LV_PART_MAIN|LV_STATE_DISABLED);

    //Write style state: LV_STATE_CHECKED for &style_scr_base_ddlist_screentime_option_extra_list_selected_checked
    static lv_style_t style_scr_base_ddlist_screentime_option_extra_list_selected_checked;
    ui_init_style(&style_scr_base_ddlist_screentime_option_extra_list_selected_checked);

    lv_style_set_border_width(&style_scr_base_ddlist_screentime_option_extra_list_selected_checked, 1);
    lv_style_set_border_opa(&style_scr_base_ddlist_screentime_option_extra_list_selected_checked, 255);
    lv_style_set_border_color(&style_scr_base_ddlist_screentime_option_extra_list_selected_checked, lv_color_hex(0xe1e6ee));
    lv_style_set_border_side(&style_scr_base_ddlist_screentime_option_extra_list_selected_checked, LV_BORDER_SIDE_FULL);
    lv_style_set_radius(&style_scr_base_ddlist_screentime_option_extra_list_selected_checked, 1);
    lv_style_set_bg_opa(&style_scr_base_ddlist_screentime_option_extra_list_selected_checked, 129);
    lv_style_set_bg_color(&style_scr_base_ddlist_screentime_option_extra_list_selected_checked, lv_color_hex(0x00a1b5));
    lv_style_set_bg_grad_dir(&style_scr_base_ddlist_screentime_option_extra_list_selected_checked, LV_GRAD_DIR_NONE);
    lv_obj_add_style(lv_dropdown_get_list(ui->scr_base_ddlist_screentime_option), &style_scr_base_ddlist_screentime_option_extra_list_selected_checked, LV_PART_SELECTED|LV_STATE_CHECKED);

    //Write style state: LV_STATE_DEFAULT for &style_scr_base_ddlist_screentime_option_extra_list_main_default
    static lv_style_t style_scr_base_ddlist_screentime_option_extra_list_main_default;
    ui_init_style(&style_scr_base_ddlist_screentime_option_extra_list_main_default);

    lv_style_set_max_height(&style_scr_base_ddlist_screentime_option_extra_list_main_default, 90);
    lv_style_set_text_color(&style_scr_base_ddlist_screentime_option_extra_list_main_default, lv_color_hex(0xfdfdfd));
    lv_style_set_text_font(&style_scr_base_ddlist_screentime_option_extra_list_main_default, &lv_font_Roboto_Regular_14);
    lv_style_set_text_opa(&style_scr_base_ddlist_screentime_option_extra_list_main_default, 255);
    lv_style_set_border_width(&style_scr_base_ddlist_screentime_option_extra_list_main_default, 1);
    lv_style_set_border_opa(&style_scr_base_ddlist_screentime_option_extra_list_main_default, 54);
    lv_style_set_border_color(&style_scr_base_ddlist_screentime_option_extra_list_main_default, lv_color_hex(0xffffff));
    lv_style_set_border_side(&style_scr_base_ddlist_screentime_option_extra_list_main_default, LV_BORDER_SIDE_FULL);
    lv_style_set_radius(&style_scr_base_ddlist_screentime_option_extra_list_main_default, 5);
    lv_style_set_bg_opa(&style_scr_base_ddlist_screentime_option_extra_list_main_default, 129);
    lv_style_set_bg_color(&style_scr_base_ddlist_screentime_option_extra_list_main_default, lv_color_hex(0x000000));
    lv_style_set_bg_grad_dir(&style_scr_base_ddlist_screentime_option_extra_list_main_default, LV_GRAD_DIR_NONE);
    lv_obj_add_style(lv_dropdown_get_list(ui->scr_base_ddlist_screentime_option), &style_scr_base_ddlist_screentime_option_extra_list_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_DEFAULT for &style_scr_base_ddlist_screentime_option_extra_list_scrollbar_default
    static lv_style_t style_scr_base_ddlist_screentime_option_extra_list_scrollbar_default;
    ui_init_style(&style_scr_base_ddlist_screentime_option_extra_list_scrollbar_default);

    lv_style_set_radius(&style_scr_base_ddlist_screentime_option_extra_list_scrollbar_default, 3);
    lv_style_set_bg_opa(&style_scr_base_ddlist_screentime_option_extra_list_scrollbar_default, 54);
    lv_style_set_bg_color(&style_scr_base_ddlist_screentime_option_extra_list_scrollbar_default, lv_color_hex(0xcccccc));
    lv_style_set_bg_grad_dir(&style_scr_base_ddlist_screentime_option_extra_list_scrollbar_default, LV_GRAD_DIR_NONE);
    lv_obj_add_style(lv_dropdown_get_list(ui->scr_base_ddlist_screentime_option), &style_scr_base_ddlist_screentime_option_extra_list_scrollbar_default, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);

    //Write codes scr_base_slider_brightness
    ui->scr_base_slider_brightness = lv_slider_create(ui->scr_base_cont_72);
    lv_obj_set_pos(ui->scr_base_slider_brightness, 25, 77);
    lv_obj_set_size(ui->scr_base_slider_brightness, 270, 8);
    lv_slider_set_range(ui->scr_base_slider_brightness, 0, 100);
    lv_slider_set_mode(ui->scr_base_slider_brightness, LV_SLIDER_MODE_NORMAL);
    lv_slider_set_value(ui->scr_base_slider_brightness, 50, LV_ANIM_OFF);

    //Write style for scr_base_slider_brightness, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->scr_base_slider_brightness, 52, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_base_slider_brightness, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_slider_brightness, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_slider_brightness, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_outline_width(ui->scr_base_slider_brightness, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_slider_brightness, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for scr_base_slider_brightness, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->scr_base_slider_brightness, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_base_slider_brightness, lv_color_hex(0xb9d4eb), LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_slider_brightness, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_slider_brightness, 8, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write style for scr_base_slider_brightness, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->scr_base_slider_brightness, 0, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_slider_brightness, 8, LV_PART_KNOB|LV_STATE_DEFAULT);

    //Write codes scr_base_cont_operations
    ui->scr_base_cont_operations = lv_obj_create(ui->scr_base_cont_system_admin);
    lv_obj_set_pos(ui->scr_base_cont_operations, 5, 202);
    lv_obj_set_size(ui->scr_base_cont_operations, 321, 170);
    lv_obj_set_scrollbar_mode(ui->scr_base_cont_operations, LV_SCROLLBAR_MODE_OFF);

    //Write style for scr_base_cont_operations, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_cont_operations, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scr_base_cont_operations, 65, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scr_base_cont_operations, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scr_base_cont_operations, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_cont_operations, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_cont_operations, 243, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_base_cont_operations, lv_color_hex(0x0F172A), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_cont_operations, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_cont_operations, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_cont_operations, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_cont_operations, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_cont_operations, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_cont_operations, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_label_208
    ui->scr_base_label_208 = lv_label_create(ui->scr_base_cont_operations);
    lv_obj_set_pos(ui->scr_base_label_208, 25, 25);
    lv_obj_set_size(ui->scr_base_label_208, 166, 17);
    lv_label_set_text(ui->scr_base_label_208, "DEVICE OPERATIONS");
    lv_label_set_long_mode(ui->scr_base_label_208, LV_LABEL_LONG_WRAP);

    //Write style for scr_base_label_208, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_label_208, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_label_208, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_base_label_208, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_label_208, &lv_font_Roboto_Bold_15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_label_208, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_base_label_208, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_base_label_208, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_label_208, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_label_208, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_label_208, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_label_208, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_label_208, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_label_208, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_label_208, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_btn_restart_system
    ui->scr_base_btn_restart_system = lv_button_create(ui->scr_base_cont_operations);
    lv_obj_set_pos(ui->scr_base_btn_restart_system, 25, 56);
    lv_obj_set_size(ui->scr_base_btn_restart_system, 274, 38);
    ui->scr_base_btn_restart_system_label = lv_label_create(ui->scr_base_btn_restart_system);
    lv_label_set_text(ui->scr_base_btn_restart_system_label, "RESTART SYSTEM");
    lv_label_set_long_mode(ui->scr_base_btn_restart_system_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->scr_base_btn_restart_system_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->scr_base_btn_restart_system, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->scr_base_btn_restart_system_label, LV_PCT(100));

    //Write style for scr_base_btn_restart_system, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->scr_base_btn_restart_system, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_base_btn_restart_system, lv_color_hex(0x191d20), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_btn_restart_system, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->scr_base_btn_restart_system, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scr_base_btn_restart_system, 63, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scr_base_btn_restart_system, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scr_base_btn_restart_system, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_btn_restart_system, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_btn_restart_system, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_base_btn_restart_system, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_btn_restart_system, &lv_font_Roboto_Black_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_btn_restart_system, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_btn_restart_system, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for scr_base_btn_restart_system, Part: LV_PART_MAIN, State: LV_STATE_FOCUSED.
    lv_obj_set_style_bg_opa(ui->scr_base_btn_restart_system, 255, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_color(ui->scr_base_btn_restart_system, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_btn_restart_system, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_width(ui->scr_base_btn_restart_system, 1, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_opa(ui->scr_base_btn_restart_system, 255, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_color(ui->scr_base_btn_restart_system, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_side(ui->scr_base_btn_restart_system, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_radius(ui->scr_base_btn_restart_system, 10, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_shadow_width(ui->scr_base_btn_restart_system, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_color(ui->scr_base_btn_restart_system, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_font(ui->scr_base_btn_restart_system, &lv_font_Roboto_Black_16, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_opa(ui->scr_base_btn_restart_system, 255, LV_PART_MAIN|LV_STATE_FOCUSED);

    //Write style for scr_base_btn_restart_system, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_bg_opa(ui->scr_base_btn_restart_system, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_bg_color(ui->scr_base_btn_restart_system, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_btn_restart_system, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui->scr_base_btn_restart_system, 1, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_border_opa(ui->scr_base_btn_restart_system, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_border_color(ui->scr_base_btn_restart_system, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_border_side(ui->scr_base_btn_restart_system, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_radius(ui->scr_base_btn_restart_system, 10, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->scr_base_btn_restart_system, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->scr_base_btn_restart_system, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->scr_base_btn_restart_system, &lv_font_Roboto_Black_16, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->scr_base_btn_restart_system, 255, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for scr_base_btn_restart_system, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_bg_opa(ui->scr_base_btn_restart_system, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui->scr_base_btn_restart_system, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_btn_restart_system, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_border_width(ui->scr_base_btn_restart_system, 1, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_border_opa(ui->scr_base_btn_restart_system, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_border_color(ui->scr_base_btn_restart_system, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_border_side(ui->scr_base_btn_restart_system, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_radius(ui->scr_base_btn_restart_system, 10, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->scr_base_btn_restart_system, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->scr_base_btn_restart_system, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->scr_base_btn_restart_system, &lv_font_Roboto_Black_16, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->scr_base_btn_restart_system, 255, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write style for scr_base_btn_restart_system, Part: LV_PART_MAIN, State: LV_STATE_DISABLED.
    lv_obj_set_style_bg_opa(ui->scr_base_btn_restart_system, 255, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_bg_color(ui->scr_base_btn_restart_system, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_btn_restart_system, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_border_width(ui->scr_base_btn_restart_system, 1, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_border_opa(ui->scr_base_btn_restart_system, 255, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_border_color(ui->scr_base_btn_restart_system, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_border_side(ui->scr_base_btn_restart_system, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_radius(ui->scr_base_btn_restart_system, 10, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_shadow_width(ui->scr_base_btn_restart_system, 0, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_color(ui->scr_base_btn_restart_system, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_font(ui->scr_base_btn_restart_system, &lv_font_Roboto_Black_16, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_opa(ui->scr_base_btn_restart_system, 255, LV_PART_MAIN|LV_STATE_DISABLED);

    //Write codes scr_base_btn_factory_reset
    ui->scr_base_btn_factory_reset = lv_button_create(ui->scr_base_cont_operations);
    lv_obj_set_pos(ui->scr_base_btn_factory_reset, 25, 106);
    lv_obj_set_size(ui->scr_base_btn_factory_reset, 274, 38);
    ui->scr_base_btn_factory_reset_label = lv_label_create(ui->scr_base_btn_factory_reset);
    lv_label_set_text(ui->scr_base_btn_factory_reset_label, "FACTORY RESET");
    lv_label_set_long_mode(ui->scr_base_btn_factory_reset_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->scr_base_btn_factory_reset_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->scr_base_btn_factory_reset, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->scr_base_btn_factory_reset_label, LV_PCT(100));

    //Write style for scr_base_btn_factory_reset, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->scr_base_btn_factory_reset, 203, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_base_btn_factory_reset, lv_color_hex(0x91444f), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_btn_factory_reset, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->scr_base_btn_factory_reset, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scr_base_btn_factory_reset, 63, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scr_base_btn_factory_reset, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scr_base_btn_factory_reset, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_btn_factory_reset, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_btn_factory_reset, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_base_btn_factory_reset, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_btn_factory_reset, &lv_font_Roboto_Black_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_btn_factory_reset, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_btn_factory_reset, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for scr_base_btn_factory_reset, Part: LV_PART_MAIN, State: LV_STATE_FOCUSED.
    lv_obj_set_style_bg_opa(ui->scr_base_btn_factory_reset, 255, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_color(ui->scr_base_btn_factory_reset, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_btn_factory_reset, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_width(ui->scr_base_btn_factory_reset, 1, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_opa(ui->scr_base_btn_factory_reset, 255, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_color(ui->scr_base_btn_factory_reset, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_side(ui->scr_base_btn_factory_reset, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_radius(ui->scr_base_btn_factory_reset, 10, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_shadow_width(ui->scr_base_btn_factory_reset, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_color(ui->scr_base_btn_factory_reset, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_font(ui->scr_base_btn_factory_reset, &lv_font_Roboto_Black_16, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_opa(ui->scr_base_btn_factory_reset, 255, LV_PART_MAIN|LV_STATE_FOCUSED);

    //Write style for scr_base_btn_factory_reset, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_bg_opa(ui->scr_base_btn_factory_reset, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_bg_color(ui->scr_base_btn_factory_reset, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_btn_factory_reset, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui->scr_base_btn_factory_reset, 1, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_border_opa(ui->scr_base_btn_factory_reset, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_border_color(ui->scr_base_btn_factory_reset, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_border_side(ui->scr_base_btn_factory_reset, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_radius(ui->scr_base_btn_factory_reset, 10, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->scr_base_btn_factory_reset, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->scr_base_btn_factory_reset, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->scr_base_btn_factory_reset, &lv_font_Roboto_Black_16, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->scr_base_btn_factory_reset, 255, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for scr_base_btn_factory_reset, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_bg_opa(ui->scr_base_btn_factory_reset, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui->scr_base_btn_factory_reset, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_btn_factory_reset, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_border_width(ui->scr_base_btn_factory_reset, 1, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_border_opa(ui->scr_base_btn_factory_reset, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_border_color(ui->scr_base_btn_factory_reset, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_border_side(ui->scr_base_btn_factory_reset, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_radius(ui->scr_base_btn_factory_reset, 10, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->scr_base_btn_factory_reset, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->scr_base_btn_factory_reset, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->scr_base_btn_factory_reset, &lv_font_Roboto_Black_16, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->scr_base_btn_factory_reset, 255, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write style for scr_base_btn_factory_reset, Part: LV_PART_MAIN, State: LV_STATE_DISABLED.
    lv_obj_set_style_bg_opa(ui->scr_base_btn_factory_reset, 255, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_bg_color(ui->scr_base_btn_factory_reset, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_btn_factory_reset, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_border_width(ui->scr_base_btn_factory_reset, 1, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_border_opa(ui->scr_base_btn_factory_reset, 255, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_border_color(ui->scr_base_btn_factory_reset, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_border_side(ui->scr_base_btn_factory_reset, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_radius(ui->scr_base_btn_factory_reset, 10, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_shadow_width(ui->scr_base_btn_factory_reset, 0, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_color(ui->scr_base_btn_factory_reset, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_font(ui->scr_base_btn_factory_reset, &lv_font_Roboto_Black_16, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_opa(ui->scr_base_btn_factory_reset, 255, LV_PART_MAIN|LV_STATE_DISABLED);

    //Write codes scr_base_cont_device_operations
    ui->scr_base_cont_device_operations = lv_obj_create(ui->scr_base_cont_system_admin);
    lv_obj_set_pos(ui->scr_base_cont_device_operations, 339, 202);
    lv_obj_set_size(ui->scr_base_cont_device_operations, 321, 170);
    lv_obj_set_scrollbar_mode(ui->scr_base_cont_device_operations, LV_SCROLLBAR_MODE_OFF);

    //Write style for scr_base_cont_device_operations, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_cont_device_operations, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scr_base_cont_device_operations, 65, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scr_base_cont_device_operations, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scr_base_cont_device_operations, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_cont_device_operations, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_cont_device_operations, 243, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_base_cont_device_operations, lv_color_hex(0x0F172A), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_cont_device_operations, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_cont_device_operations, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_cont_device_operations, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_cont_device_operations, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_cont_device_operations, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_cont_device_operations, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_label_209
    ui->scr_base_label_209 = lv_label_create(ui->scr_base_cont_device_operations);
    lv_obj_set_pos(ui->scr_base_label_209, 25, 25);
    lv_obj_set_size(ui->scr_base_label_209, 166, 17);
    lv_label_set_text(ui->scr_base_label_209, "DEVICE OPERATIONS");
    lv_label_set_long_mode(ui->scr_base_label_209, LV_LABEL_LONG_WRAP);

    //Write style for scr_base_label_209, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_label_209, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_label_209, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_base_label_209, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_label_209, &lv_font_Roboto_Bold_15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_label_209, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_base_label_209, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_base_label_209, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_label_209, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_label_209, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_label_209, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_label_209, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_label_209, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_label_209, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_label_209, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_label_210
    ui->scr_base_label_210 = lv_label_create(ui->scr_base_cont_device_operations);
    lv_obj_set_pos(ui->scr_base_label_210, 35, 57);
    lv_obj_set_size(ui->scr_base_label_210, 95, 17);
    lv_label_set_text(ui->scr_base_label_210, "FW VERSION");
    lv_label_set_long_mode(ui->scr_base_label_210, LV_LABEL_LONG_WRAP);

    //Write style for scr_base_label_210, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_label_210, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_label_210, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_base_label_210, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_label_210, &lv_font_Roboto_Bold_14, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_label_210, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_base_label_210, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_base_label_210, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_label_210, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_label_210, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_label_210, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_label_210, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_label_210, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_label_210, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_label_210, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_label_211
    ui->scr_base_label_211 = lv_label_create(ui->scr_base_cont_device_operations);
    lv_obj_set_pos(ui->scr_base_label_211, 35, 92);
    lv_obj_set_size(ui->scr_base_label_211, 134, 17);
    lv_label_set_text(ui->scr_base_label_211, "MEMORY STATUS");
    lv_label_set_long_mode(ui->scr_base_label_211, LV_LABEL_LONG_WRAP);

    //Write style for scr_base_label_211, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_label_211, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_label_211, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_base_label_211, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_label_211, &lv_font_Roboto_Bold_14, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_label_211, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_base_label_211, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_base_label_211, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_label_211, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_label_211, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_label_211, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_label_211, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_label_211, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_label_211, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_label_211, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_label_212
    ui->scr_base_label_212 = lv_label_create(ui->scr_base_cont_device_operations);
    lv_obj_set_pos(ui->scr_base_label_212, 35, 127);
    lv_obj_set_size(ui->scr_base_label_212, 130, 17);
    lv_label_set_text(ui->scr_base_label_212, "SYSTEM UPTIME");
    lv_label_set_long_mode(ui->scr_base_label_212, LV_LABEL_LONG_WRAP);

    //Write style for scr_base_label_212, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_label_212, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_label_212, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_base_label_212, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_label_212, &lv_font_Roboto_Bold_14, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_label_212, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_base_label_212, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_base_label_212, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_label_212, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_label_212, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_label_212, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_label_212, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_label_212, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_label_212, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_label_212, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_lbl_fw_val
    ui->scr_base_lbl_fw_val = lv_label_create(ui->scr_base_cont_device_operations);
    lv_obj_set_pos(ui->scr_base_lbl_fw_val, 175, 57);
    lv_obj_set_size(ui->scr_base_lbl_fw_val, 99, 17);
    lv_label_set_text(ui->scr_base_lbl_fw_val, "FW VERSION");
    lv_label_set_long_mode(ui->scr_base_lbl_fw_val, LV_LABEL_LONG_WRAP);

    //Write style for scr_base_lbl_fw_val, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_lbl_fw_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_lbl_fw_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_base_lbl_fw_val, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_lbl_fw_val, &lv_font_Roboto_Bold_14, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_lbl_fw_val, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_base_lbl_fw_val, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_base_lbl_fw_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_lbl_fw_val, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_lbl_fw_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_lbl_fw_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_lbl_fw_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_lbl_fw_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_lbl_fw_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_lbl_fw_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_lbl_memory_status_val
    ui->scr_base_lbl_memory_status_val = lv_label_create(ui->scr_base_cont_device_operations);
    lv_obj_set_pos(ui->scr_base_lbl_memory_status_val, 181, 92);
    lv_obj_set_size(ui->scr_base_lbl_memory_status_val, 93, 17);
    lv_label_set_text(ui->scr_base_lbl_memory_status_val, "FW VERSION");
    lv_label_set_long_mode(ui->scr_base_lbl_memory_status_val, LV_LABEL_LONG_WRAP);

    //Write style for scr_base_lbl_memory_status_val, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_lbl_memory_status_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_lbl_memory_status_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_base_lbl_memory_status_val, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_lbl_memory_status_val, &lv_font_Roboto_Bold_14, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_lbl_memory_status_val, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_base_lbl_memory_status_val, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_base_lbl_memory_status_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_lbl_memory_status_val, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_lbl_memory_status_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_lbl_memory_status_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_lbl_memory_status_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_lbl_memory_status_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_lbl_memory_status_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_lbl_memory_status_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_lbl_system_uptime_val
    ui->scr_base_lbl_system_uptime_val = lv_label_create(ui->scr_base_cont_device_operations);
    lv_obj_set_pos(ui->scr_base_lbl_system_uptime_val, 165, 127);
    lv_obj_set_size(ui->scr_base_lbl_system_uptime_val, 109, 17);
    lv_label_set_text(ui->scr_base_lbl_system_uptime_val, "FW VERSION");
    lv_label_set_long_mode(ui->scr_base_lbl_system_uptime_val, LV_LABEL_LONG_WRAP);

    //Write style for scr_base_lbl_system_uptime_val, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_lbl_system_uptime_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_lbl_system_uptime_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_base_lbl_system_uptime_val, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_lbl_system_uptime_val, &lv_font_Roboto_Bold_14, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_lbl_system_uptime_val, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_base_lbl_system_uptime_val, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_base_lbl_system_uptime_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_lbl_system_uptime_val, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_lbl_system_uptime_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_lbl_system_uptime_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_lbl_system_uptime_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_lbl_system_uptime_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_lbl_system_uptime_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_lbl_system_uptime_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_cont_data_time
    ui->scr_base_cont_data_time = lv_obj_create(ui->scr_base);
    lv_obj_set_pos(ui->scr_base_cont_data_time, 587, 22);
    lv_obj_set_size(ui->scr_base_cont_data_time, 200, 40);
    lv_obj_set_scrollbar_mode(ui->scr_base_cont_data_time, LV_SCROLLBAR_MODE_OFF);

    //Write style for scr_base_cont_data_time, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_cont_data_time, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scr_base_cont_data_time, 34, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scr_base_cont_data_time, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scr_base_cont_data_time, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_cont_data_time, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_cont_data_time, 65, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_base_cont_data_time, lv_color_hex(0x3d3d3d), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_cont_data_time, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_cont_data_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_cont_data_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_cont_data_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_cont_data_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_cont_data_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_time_val
    static bool scr_base_time_val_timer_enabled = false;
    ui->scr_base_time_val = lv_label_create(ui->scr_base_cont_data_time);
    lv_obj_set_pos(ui->scr_base_time_val, 112, 6);
    lv_obj_set_size(ui->scr_base_time_val, 79, 26);
    lv_label_set_text(ui->scr_base_time_val, "11:25:50");
    if (!scr_base_time_val_timer_enabled) {
        lv_timer_create(scr_base_time_val_timer, 1000, NULL);
        scr_base_time_val_timer_enabled = true;
    }

    //Write style for scr_base_time_val, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_radius(ui->scr_base_time_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_base_time_val, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_time_val, &lv_font_Roboto_Black_14, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_time_val, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_base_time_val, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_time_val, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_time_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_time_val, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_time_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_time_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_time_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_time_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for scr_base_time_val, Part: LV_PART_MAIN, State: LV_STATE_DISABLED.
    lv_obj_set_style_radius(ui->scr_base_time_val, 0, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_color(ui->scr_base_time_val, lv_color_hex(0x64748B), LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_font(ui->scr_base_time_val, &lv_font_Roboto_Bold_10, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_opa(ui->scr_base_time_val, 255, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_letter_space(ui->scr_base_time_val, 0, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_align(ui->scr_base_time_val, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_bg_opa(ui->scr_base_time_val, 0, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_pad_top(ui->scr_base_time_val, 7, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_pad_right(ui->scr_base_time_val, 0, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_pad_bottom(ui->scr_base_time_val, 0, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_pad_left(ui->scr_base_time_val, 0, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_shadow_width(ui->scr_base_time_val, 0, LV_PART_MAIN|LV_STATE_DISABLED);

    //Write codes scr_base_date_val
    ui->scr_base_date_val = lv_label_create(ui->scr_base_cont_data_time);
    lv_obj_set_pos(ui->scr_base_date_val, 13, 6);
    lv_obj_set_size(ui->scr_base_date_val, 87, 26);
    lv_label_set_text(ui->scr_base_date_val, "2025/05/15");
    lv_obj_set_style_text_align(ui->scr_base_date_val, LV_TEXT_ALIGN_CENTER, 0);
    lv_obj_add_flag(ui->scr_base_date_val, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_add_event_cb(ui->scr_base_date_val, scr_base_date_val_event_handler, LV_EVENT_ALL, NULL);

    //Write style for scr_base_date_val, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->scr_base_date_val, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_date_val, &lv_font_Roboto_Black_14, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_date_val, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_base_date_val, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_date_val, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_date_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->scr_base_date_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_date_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_date_val, 7, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_date_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_date_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_date_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for scr_base_date_val, Part: LV_PART_MAIN, State: LV_STATE_DISABLED.
    lv_obj_set_style_text_color(ui->scr_base_date_val, lv_color_hex(0x64748B), LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_font(ui->scr_base_date_val, &lv_font_Roboto_Bold_9, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_opa(ui->scr_base_date_val, 255, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_letter_space(ui->scr_base_date_val, 2, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_align(ui->scr_base_date_val, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_bg_opa(ui->scr_base_date_val, 0, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_border_width(ui->scr_base_date_val, 0, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_radius(ui->scr_base_date_val, 0, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_pad_top(ui->scr_base_date_val, 7, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_pad_right(ui->scr_base_date_val, 0, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_pad_left(ui->scr_base_date_val, 0, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_shadow_width(ui->scr_base_date_val, 0, LV_PART_MAIN|LV_STATE_DISABLED);

    //Write codes scr_base_line_1
    ui->scr_base_line_1 = lv_line_create(ui->scr_base_cont_data_time);
    lv_obj_set_pos(ui->scr_base_line_1, 110, 6);
    lv_obj_set_size(ui->scr_base_line_1, 8, 35);
    static lv_point_precise_t scr_base_line_1[] = {{0, 0},{0, 25}};
    lv_line_set_points(ui->scr_base_line_1, scr_base_line_1, 2);

    //Write style for scr_base_line_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_line_width(ui->scr_base_line_1, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_color(ui->scr_base_line_1, lv_color_hex(0x757575), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_opa(ui->scr_base_line_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_rounded(ui->scr_base_line_1, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_cont_net_mqtt
    ui->scr_base_cont_net_mqtt = lv_obj_create(ui->scr_base);
    lv_obj_set_pos(ui->scr_base_cont_net_mqtt, 400, 22);
    lv_obj_set_size(ui->scr_base_cont_net_mqtt, 174, 40);
    lv_obj_set_scrollbar_mode(ui->scr_base_cont_net_mqtt, LV_SCROLLBAR_MODE_OFF);

    //Write style for scr_base_cont_net_mqtt, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_cont_net_mqtt, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scr_base_cont_net_mqtt, 34, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scr_base_cont_net_mqtt, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scr_base_cont_net_mqtt, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_cont_net_mqtt, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_cont_net_mqtt, 65, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_base_cont_net_mqtt, lv_color_hex(0x3d3d3d), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_cont_net_mqtt, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_cont_net_mqtt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_cont_net_mqtt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_cont_net_mqtt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_cont_net_mqtt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_cont_net_mqtt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_line_2
    ui->scr_base_line_2 = lv_line_create(ui->scr_base_cont_net_mqtt);
    lv_obj_set_pos(ui->scr_base_line_2, 76, 6);
    lv_obj_set_size(ui->scr_base_line_2, 4, 35);
    static lv_point_precise_t scr_base_line_2[] = {{0, 0},{0, 25}};
    lv_line_set_points(ui->scr_base_line_2, scr_base_line_2, 2);

    //Write style for scr_base_line_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_line_width(ui->scr_base_line_2, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_color(ui->scr_base_line_2, lv_color_hex(0x757575), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_opa(ui->scr_base_line_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_rounded(ui->scr_base_line_2, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_lbl_net
    ui->scr_base_lbl_net = lv_label_create(ui->scr_base_cont_net_mqtt);
    lv_obj_set_pos(ui->scr_base_lbl_net, 14, 6);
    lv_obj_set_size(ui->scr_base_lbl_net, 35, 26);
    lv_label_set_text(ui->scr_base_lbl_net, "NET");
    lv_label_set_long_mode(ui->scr_base_lbl_net, LV_LABEL_LONG_WRAP);

    //Write style for scr_base_lbl_net, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_lbl_net, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_lbl_net, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_base_lbl_net, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_lbl_net, &lv_font_Roboto_Black_14, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_lbl_net, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_base_lbl_net, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_base_lbl_net, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_lbl_net, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_lbl_net, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_lbl_net, 7, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_lbl_net, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_lbl_net, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_lbl_net, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_lbl_net, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_lbl_mqtt
    ui->scr_base_lbl_mqtt = lv_label_create(ui->scr_base_cont_net_mqtt);
    lv_obj_set_pos(ui->scr_base_lbl_mqtt, 87, 6);
    lv_obj_set_size(ui->scr_base_lbl_mqtt, 51, 26);
    lv_label_set_text(ui->scr_base_lbl_mqtt, "MQTT");
    lv_label_set_long_mode(ui->scr_base_lbl_mqtt, LV_LABEL_LONG_WRAP);

    //Write style for scr_base_lbl_mqtt, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_lbl_mqtt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_lbl_mqtt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_base_lbl_mqtt, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_lbl_mqtt, &lv_font_Roboto_Black_14, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_lbl_mqtt, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_base_lbl_mqtt, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_base_lbl_mqtt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_lbl_mqtt, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_lbl_mqtt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_lbl_mqtt, 7, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_lbl_mqtt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_lbl_mqtt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_lbl_mqtt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_lbl_mqtt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_img_mqtt_on
    ui->scr_base_img_mqtt_on = lv_image_create(ui->scr_base_cont_net_mqtt);
    lv_obj_set_pos(ui->scr_base_img_mqtt_on, 138, 11);
    lv_obj_set_size(ui->scr_base_img_mqtt_on, 16, 16);
    lv_obj_add_flag(ui->scr_base_img_mqtt_on, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->scr_base_img_mqtt_on, &_mqtt_on_RGB565A8_16x16);
    lv_image_set_pivot(ui->scr_base_img_mqtt_on, 50,50);
    lv_image_set_rotation(ui->scr_base_img_mqtt_on, 0);

    //Write style for scr_base_img_mqtt_on, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->scr_base_img_mqtt_on, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_recolor(ui->scr_base_img_mqtt_on, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->scr_base_img_mqtt_on, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_img_net_on
    ui->scr_base_img_net_on = lv_image_create(ui->scr_base_cont_net_mqtt);
    lv_obj_set_pos(ui->scr_base_img_net_on, 50, 11);
    lv_obj_set_size(ui->scr_base_img_net_on, 16, 16);
    lv_obj_add_flag(ui->scr_base_img_net_on, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->scr_base_img_net_on, &_wifi_on_RGB565A8_16x16);
    lv_image_set_pivot(ui->scr_base_img_net_on, 50,50);
    lv_image_set_rotation(ui->scr_base_img_net_on, 0);

    //Write style for scr_base_img_net_on, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->scr_base_img_net_on, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_recolor(ui->scr_base_img_net_on, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->scr_base_img_net_on, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_img_mqtt_off
    ui->scr_base_img_mqtt_off = lv_image_create(ui->scr_base_cont_net_mqtt);
    lv_obj_set_pos(ui->scr_base_img_mqtt_off, 138, 11);
    lv_obj_set_size(ui->scr_base_img_mqtt_off, 16, 16);
    lv_obj_add_flag(ui->scr_base_img_mqtt_off, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(ui->scr_base_img_mqtt_off, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->scr_base_img_mqtt_off, &_mqtt_off_RGB565A8_16x16);
    lv_image_set_pivot(ui->scr_base_img_mqtt_off, 50,50);
    lv_image_set_rotation(ui->scr_base_img_mqtt_off, 0);

    //Write style for scr_base_img_mqtt_off, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->scr_base_img_mqtt_off, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_recolor(ui->scr_base_img_mqtt_off, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->scr_base_img_mqtt_off, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_img_net_off
    ui->scr_base_img_net_off = lv_image_create(ui->scr_base_cont_net_mqtt);
    lv_obj_set_pos(ui->scr_base_img_net_off, 50, 11);
    lv_obj_set_size(ui->scr_base_img_net_off, 16, 16);
    lv_obj_add_flag(ui->scr_base_img_net_off, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(ui->scr_base_img_net_off, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->scr_base_img_net_off, &_wifi_off_RGB565A8_16x16);
    lv_image_set_pivot(ui->scr_base_img_net_off, 50,50);
    lv_image_set_rotation(ui->scr_base_img_net_off, 0);

    //Write style for scr_base_img_net_off, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->scr_base_img_net_off, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_recolor(ui->scr_base_img_net_off, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->scr_base_img_net_off, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_cont_device_viewlist
    ui->scr_base_cont_device_viewlist = lv_obj_create(ui->scr_base);
    lv_obj_set_pos(ui->scr_base_cont_device_viewlist, 0, 0);
    lv_obj_set_size(ui->scr_base_cont_device_viewlist, 800, 480);
    lv_obj_set_scrollbar_mode(ui->scr_base_cont_device_viewlist, LV_SCROLLBAR_MODE_OFF);
    lv_obj_add_flag(ui->scr_base_cont_device_viewlist, LV_OBJ_FLAG_HIDDEN);

    //Write style for scr_base_cont_device_viewlist, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_cont_device_viewlist, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_cont_device_viewlist, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_cont_device_viewlist, 206, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_base_cont_device_viewlist, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_cont_device_viewlist, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_cont_device_viewlist, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_cont_device_viewlist, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_cont_device_viewlist, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_cont_device_viewlist, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_cont_device_viewlist, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_cont_68
    ui->scr_base_cont_68 = lv_obj_create(ui->scr_base_cont_device_viewlist);
    lv_obj_set_pos(ui->scr_base_cont_68, 70, 30);
    lv_obj_set_size(ui->scr_base_cont_68, 660, 420);
    lv_obj_set_scrollbar_mode(ui->scr_base_cont_68, LV_SCROLLBAR_MODE_OFF);

    //Write style for scr_base_cont_68, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_cont_68, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scr_base_cont_68, 65, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scr_base_cont_68, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scr_base_cont_68, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_cont_68, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_cont_68, 243, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_base_cont_68, lv_color_hex(0x0F172A), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_cont_68, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_cont_68, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_cont_68, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_cont_68, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_cont_68, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_cont_68, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_cont_69
    ui->scr_base_cont_69 = lv_obj_create(ui->scr_base_cont_68);
    lv_obj_set_pos(ui->scr_base_cont_69, 26, 51);
    lv_obj_set_size(ui->scr_base_cont_69, 612, 346);
    lv_obj_set_scrollbar_mode(ui->scr_base_cont_69, LV_SCROLLBAR_MODE_OFF);

    //Write style for scr_base_cont_69, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_cont_69, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scr_base_cont_69, 65, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scr_base_cont_69, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scr_base_cont_69, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_cont_69, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_cont_69, 51, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_base_cont_69, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_cont_69, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_cont_69, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_cont_69, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_cont_69, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_cont_69, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_cont_69, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_cont_70
    ui->scr_base_cont_70 = lv_obj_create(ui->scr_base_cont_69);
    lv_obj_set_pos(ui->scr_base_cont_70, 0, 20);
    lv_obj_set_size(ui->scr_base_cont_70, 612, 44);
    lv_obj_set_scrollbar_mode(ui->scr_base_cont_70, LV_SCROLLBAR_MODE_OFF);

    //Write style for scr_base_cont_70, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_cont_70, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scr_base_cont_70, 56, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scr_base_cont_70, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scr_base_cont_70, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_cont_70, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_cont_70, 43, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_base_cont_70, lv_color_hex(0x1c0f0f), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_cont_70, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_cont_70, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_cont_70, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_cont_70, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_cont_70, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_cont_70, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_lbl_device_action
    ui->scr_base_lbl_device_action = lv_label_create(ui->scr_base_cont_70);
    lv_obj_set_pos(ui->scr_base_lbl_device_action, 529, 15);
    lv_obj_set_size(ui->scr_base_lbl_device_action, 68, 17);
    lv_label_set_text(ui->scr_base_lbl_device_action, "ACTION");
    lv_label_set_long_mode(ui->scr_base_lbl_device_action, LV_LABEL_LONG_WRAP);

    //Write style for scr_base_lbl_device_action, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_lbl_device_action, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_lbl_device_action, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_base_lbl_device_action, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_lbl_device_action, &lv_font_Roboto_Bold_14, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_lbl_device_action, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_base_lbl_device_action, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_base_lbl_device_action, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_lbl_device_action, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_lbl_device_action, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_lbl_device_action, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_lbl_device_action, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_lbl_device_action, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_lbl_device_action, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_lbl_device_action, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_lbl_deivce_quantity
    ui->scr_base_lbl_deivce_quantity = lv_label_create(ui->scr_base_cont_70);
    lv_obj_set_pos(ui->scr_base_lbl_deivce_quantity, 431, 15);
    lv_obj_set_size(ui->scr_base_lbl_deivce_quantity, 82, 17);
    lv_label_set_text(ui->scr_base_lbl_deivce_quantity, "QUANTITY");
    lv_label_set_long_mode(ui->scr_base_lbl_deivce_quantity, LV_LABEL_LONG_WRAP);

    //Write style for scr_base_lbl_deivce_quantity, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_lbl_deivce_quantity, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_lbl_deivce_quantity, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_base_lbl_deivce_quantity, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_lbl_deivce_quantity, &lv_font_Roboto_Bold_14, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_lbl_deivce_quantity, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_base_lbl_deivce_quantity, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_base_lbl_deivce_quantity, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_lbl_deivce_quantity, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_lbl_deivce_quantity, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_lbl_deivce_quantity, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_lbl_deivce_quantity, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_lbl_deivce_quantity, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_lbl_deivce_quantity, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_lbl_deivce_quantity, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_lbl_device_register
    ui->scr_base_lbl_device_register = lv_label_create(ui->scr_base_cont_70);
    lv_obj_set_pos(ui->scr_base_lbl_device_register, 150, 15);
    lv_obj_set_size(ui->scr_base_lbl_device_register, 119, 17);
    lv_label_set_text(ui->scr_base_lbl_device_register, "REGISTER TYPE");
    lv_label_set_long_mode(ui->scr_base_lbl_device_register, LV_LABEL_LONG_WRAP);

    //Write style for scr_base_lbl_device_register, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_lbl_device_register, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_lbl_device_register, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_base_lbl_device_register, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_lbl_device_register, &lv_font_Roboto_Bold_14, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_lbl_device_register, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_base_lbl_device_register, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_base_lbl_device_register, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_lbl_device_register, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_lbl_device_register, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_lbl_device_register, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_lbl_device_register, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_lbl_device_register, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_lbl_device_register, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_lbl_device_register, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_lbl_device_slave_id
    ui->scr_base_lbl_device_slave_id = lv_label_create(ui->scr_base_cont_70);
    lv_obj_set_pos(ui->scr_base_lbl_device_slave_id, 66, 15);
    lv_obj_set_size(ui->scr_base_lbl_device_slave_id, 68, 17);
    lv_label_set_text(ui->scr_base_lbl_device_slave_id, "SLAVE ID");
    lv_label_set_long_mode(ui->scr_base_lbl_device_slave_id, LV_LABEL_LONG_WRAP);

    //Write style for scr_base_lbl_device_slave_id, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_lbl_device_slave_id, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_lbl_device_slave_id, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_base_lbl_device_slave_id, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_lbl_device_slave_id, &lv_font_Roboto_Bold_14, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_lbl_device_slave_id, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_base_lbl_device_slave_id, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_base_lbl_device_slave_id, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_lbl_device_slave_id, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_lbl_device_slave_id, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_lbl_device_slave_id, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_lbl_device_slave_id, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_lbl_device_slave_id, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_lbl_device_slave_id, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_lbl_device_slave_id, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_lbl_device_stt
    ui->scr_base_lbl_device_stt = lv_label_create(ui->scr_base_cont_70);
    lv_obj_set_pos(ui->scr_base_lbl_device_stt, 14, 15);
    lv_obj_set_size(ui->scr_base_lbl_device_stt, 36, 17);
    lv_label_set_text(ui->scr_base_lbl_device_stt, "STT");
    lv_label_set_long_mode(ui->scr_base_lbl_device_stt, LV_LABEL_LONG_WRAP);

    //Write style for scr_base_lbl_device_stt, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_lbl_device_stt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_lbl_device_stt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_base_lbl_device_stt, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_lbl_device_stt, &lv_font_Roboto_Bold_14, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_lbl_device_stt, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_base_lbl_device_stt, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_base_lbl_device_stt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_lbl_device_stt, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_lbl_device_stt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_lbl_device_stt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_lbl_device_stt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_lbl_device_stt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_lbl_device_stt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_lbl_device_stt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_lbl_device_register_remap
    ui->scr_base_lbl_device_register_remap = lv_label_create(ui->scr_base_cont_70);
    lv_obj_set_pos(ui->scr_base_lbl_device_register_remap, 285, 15);
    lv_obj_set_size(ui->scr_base_lbl_device_register_remap, 130, 17);
    lv_label_set_text(ui->scr_base_lbl_device_register_remap, "REGISTER REMAP");
    lv_label_set_long_mode(ui->scr_base_lbl_device_register_remap, LV_LABEL_LONG_WRAP);

    //Write style for scr_base_lbl_device_register_remap, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_lbl_device_register_remap, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_lbl_device_register_remap, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_base_lbl_device_register_remap, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_lbl_device_register_remap, &lv_font_Roboto_Bold_14, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_lbl_device_register_remap, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_base_lbl_device_register_remap, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_base_lbl_device_register_remap, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_lbl_device_register_remap, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_lbl_device_register_remap, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_lbl_device_register_remap, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_lbl_device_register_remap, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_lbl_device_register_remap, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_lbl_device_register_remap, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_lbl_device_register_remap, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_label_184
    ui->scr_base_label_184 = lv_label_create(ui->scr_base_cont_68);
    lv_obj_set_pos(ui->scr_base_label_184, 209, 15);
    lv_obj_set_size(ui->scr_base_label_184, 242, 24);
    lv_label_set_text(ui->scr_base_label_184, " " LV_SYMBOL_LIST "  DEVICE LIST");
    lv_label_set_long_mode(ui->scr_base_label_184, LV_LABEL_LONG_WRAP);

    //Write style for scr_base_label_184, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_label_184, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_label_184, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_base_label_184, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_label_184, &lv_font_Roboto_Black_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_label_184, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_base_label_184, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_base_label_184, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_label_184, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_label_184, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_label_184, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_label_184, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_label_184, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_label_184, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_label_184, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_cont_devicelist_back
    ui->scr_base_cont_devicelist_back = lv_obj_create(ui->scr_base_cont_68);
    lv_obj_set_pos(ui->scr_base_cont_devicelist_back, 5, 5);
    lv_obj_set_size(ui->scr_base_cont_devicelist_back, 40, 40);
    lv_obj_set_scrollbar_mode(ui->scr_base_cont_devicelist_back, LV_SCROLLBAR_MODE_OFF);

    //Write style for scr_base_cont_devicelist_back, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_cont_devicelist_back, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scr_base_cont_devicelist_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scr_base_cont_devicelist_back, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scr_base_cont_devicelist_back, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_cont_devicelist_back, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_cont_devicelist_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_cont_devicelist_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_cont_devicelist_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_cont_devicelist_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_cont_devicelist_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_cont_devicelist_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_img_21
    ui->scr_base_img_21 = lv_image_create(ui->scr_base_cont_devicelist_back);
    lv_obj_set_pos(ui->scr_base_img_21, 7, 7);
    lv_obj_set_size(ui->scr_base_img_21, 24, 24);
    lv_obj_add_flag(ui->scr_base_img_21, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->scr_base_img_21, &_left_arrow_RGB565A8_24x24);
    lv_image_set_pivot(ui->scr_base_img_21, 50,50);
    lv_image_set_rotation(ui->scr_base_img_21, 0);

    //Write style for scr_base_img_21, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->scr_base_img_21, 189, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_recolor(ui->scr_base_img_21, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->scr_base_img_21, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_btn_devicelist_back
    ui->scr_base_btn_devicelist_back = lv_button_create(ui->scr_base_cont_devicelist_back);
    lv_obj_set_pos(ui->scr_base_btn_devicelist_back, -6, -6);
    lv_obj_set_size(ui->scr_base_btn_devicelist_back, 50, 50);
    ui->scr_base_btn_devicelist_back_label = lv_label_create(ui->scr_base_btn_devicelist_back);
    lv_label_set_text(ui->scr_base_btn_devicelist_back_label, "");
    lv_label_set_long_mode(ui->scr_base_btn_devicelist_back_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->scr_base_btn_devicelist_back_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->scr_base_btn_devicelist_back, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->scr_base_btn_devicelist_back_label, LV_PCT(100));

    //Write style for scr_base_btn_devicelist_back, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->scr_base_btn_devicelist_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->scr_base_btn_devicelist_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_btn_devicelist_back, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_btn_devicelist_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_base_btn_devicelist_back, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_btn_devicelist_back, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_btn_devicelist_back, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_btn_devicelist_back, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for scr_base_btn_devicelist_back, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_bg_opa(ui->scr_base_btn_devicelist_back, 42, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_bg_color(ui->scr_base_btn_devicelist_back, lv_color_hex(0x10B981), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_btn_devicelist_back, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui->scr_base_btn_devicelist_back, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_radius(ui->scr_base_btn_devicelist_back, 10, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->scr_base_btn_devicelist_back, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->scr_base_btn_devicelist_back, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->scr_base_btn_devicelist_back, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->scr_base_btn_devicelist_back, 255, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for scr_base_btn_devicelist_back, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_bg_opa(ui->scr_base_btn_devicelist_back, 44, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui->scr_base_btn_devicelist_back, lv_color_hex(0x10B981), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_btn_devicelist_back, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_border_width(ui->scr_base_btn_devicelist_back, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_radius(ui->scr_base_btn_devicelist_back, 10, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->scr_base_btn_devicelist_back, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->scr_base_btn_devicelist_back, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->scr_base_btn_devicelist_back, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->scr_base_btn_devicelist_back, 255, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write codes scr_base_cont_device_config
    ui->scr_base_cont_device_config = lv_obj_create(ui->scr_base);
    lv_obj_set_pos(ui->scr_base_cont_device_config, 0, 0);
    lv_obj_set_size(ui->scr_base_cont_device_config, 800, 480);
    lv_obj_set_scrollbar_mode(ui->scr_base_cont_device_config, LV_SCROLLBAR_MODE_OFF);
    lv_obj_add_flag(ui->scr_base_cont_device_config, LV_OBJ_FLAG_HIDDEN);

    //Write style for scr_base_cont_device_config, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_cont_device_config, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_cont_device_config, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_cont_device_config, 207, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_base_cont_device_config, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_cont_device_config, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_cont_device_config, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_cont_device_config, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_cont_device_config, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_cont_device_config, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_cont_device_config, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_cont_62
    ui->scr_base_cont_62 = lv_obj_create(ui->scr_base_cont_device_config);
    lv_obj_set_pos(ui->scr_base_cont_62, 70, 20);
    lv_obj_set_size(ui->scr_base_cont_62, 660, 440);
    lv_obj_set_scrollbar_mode(ui->scr_base_cont_62, LV_SCROLLBAR_MODE_OFF);

    //Write style for scr_base_cont_62, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_cont_62, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scr_base_cont_62, 65, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scr_base_cont_62, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scr_base_cont_62, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_cont_62, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_cont_62, 243, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_base_cont_62, lv_color_hex(0x0F172A), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_cont_62, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_cont_62, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_cont_62, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_cont_62, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_cont_62, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_cont_62, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_cont_63
    ui->scr_base_cont_63 = lv_obj_create(ui->scr_base_cont_62);
    lv_obj_set_pos(ui->scr_base_cont_63, 26, 53);
    lv_obj_set_size(ui->scr_base_cont_63, 612, 370);
    lv_obj_set_scrollbar_mode(ui->scr_base_cont_63, LV_SCROLLBAR_MODE_OFF);

    //Write style for scr_base_cont_63, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_cont_63, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scr_base_cont_63, 65, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scr_base_cont_63, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scr_base_cont_63, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_cont_63, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_cont_63, 51, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_base_cont_63, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_cont_63, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_cont_63, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_cont_63, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_cont_63, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_cont_63, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_cont_63, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_label_180
    ui->scr_base_label_180 = lv_label_create(ui->scr_base_cont_63);
    lv_obj_set_pos(ui->scr_base_label_180, 23, 13);
    lv_obj_set_size(ui->scr_base_label_180, 124, 17);
    lv_label_set_text(ui->scr_base_label_180, "SLAVE ID");
    lv_label_set_long_mode(ui->scr_base_label_180, LV_LABEL_LONG_WRAP);

    //Write style for scr_base_label_180, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_label_180, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_label_180, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_base_label_180, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_label_180, &lv_font_Roboto_Bold_15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_label_180, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_base_label_180, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_base_label_180, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_label_180, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_label_180, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_label_180, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_label_180, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_label_180, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_label_180, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_label_180, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_label_179
    ui->scr_base_label_179 = lv_label_create(ui->scr_base_cont_63);
    lv_obj_set_pos(ui->scr_base_label_179, 23, 92);
    lv_obj_set_size(ui->scr_base_label_179, 225, 13);
    lv_label_set_text(ui->scr_base_label_179, "REGISTER TYPE");
    lv_label_set_long_mode(ui->scr_base_label_179, LV_LABEL_LONG_WRAP);

    //Write style for scr_base_label_179, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_label_179, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_label_179, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_base_label_179, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_label_179, &lv_font_Roboto_Bold_15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_label_179, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_base_label_179, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_base_label_179, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_label_179, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_label_179, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_label_179, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_label_179, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_label_179, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_label_179, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_label_179, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_label_177
    ui->scr_base_label_177 = lv_label_create(ui->scr_base_cont_63);
    lv_obj_set_pos(ui->scr_base_label_177, 22, 240);
    lv_obj_set_size(ui->scr_base_label_177, 288, 17);
    lv_label_set_text(ui->scr_base_label_177, "REGISTER ADDRESS REMAPPING");
    lv_label_set_long_mode(ui->scr_base_label_177, LV_LABEL_LONG_WRAP);

    //Write style for scr_base_label_177, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_label_177, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_label_177, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_base_label_177, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_label_177, &lv_font_Roboto_Bold_15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_label_177, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_base_label_177, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_base_label_177, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_label_177, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_label_177, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_label_177, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_label_177, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_label_177, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_label_177, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_label_177, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_btn_master_device_apply
    ui->scr_base_btn_master_device_apply = lv_button_create(ui->scr_base_cont_63);
    lv_obj_set_pos(ui->scr_base_btn_master_device_apply, 22, 315);
    lv_obj_set_size(ui->scr_base_btn_master_device_apply, 560, 38);
    ui->scr_base_btn_master_device_apply_label = lv_label_create(ui->scr_base_btn_master_device_apply);
    lv_label_set_text(ui->scr_base_btn_master_device_apply_label, "APPLY CONFIG");
    lv_label_set_long_mode(ui->scr_base_btn_master_device_apply_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->scr_base_btn_master_device_apply_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->scr_base_btn_master_device_apply, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->scr_base_btn_master_device_apply_label, LV_PCT(100));

    //Write style for scr_base_btn_master_device_apply, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->scr_base_btn_master_device_apply, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_base_btn_master_device_apply, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_btn_master_device_apply, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->scr_base_btn_master_device_apply, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scr_base_btn_master_device_apply, 63, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scr_base_btn_master_device_apply, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scr_base_btn_master_device_apply, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_btn_master_device_apply, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_btn_master_device_apply, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_base_btn_master_device_apply, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_btn_master_device_apply, &lv_font_Roboto_Black_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_btn_master_device_apply, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_btn_master_device_apply, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for scr_base_btn_master_device_apply, Part: LV_PART_MAIN, State: LV_STATE_FOCUSED.
    lv_obj_set_style_bg_opa(ui->scr_base_btn_master_device_apply, 255, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_color(ui->scr_base_btn_master_device_apply, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_btn_master_device_apply, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_width(ui->scr_base_btn_master_device_apply, 1, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_opa(ui->scr_base_btn_master_device_apply, 255, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_color(ui->scr_base_btn_master_device_apply, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_side(ui->scr_base_btn_master_device_apply, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_radius(ui->scr_base_btn_master_device_apply, 10, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_shadow_width(ui->scr_base_btn_master_device_apply, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_color(ui->scr_base_btn_master_device_apply, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_font(ui->scr_base_btn_master_device_apply, &lv_font_Roboto_Black_16, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_opa(ui->scr_base_btn_master_device_apply, 255, LV_PART_MAIN|LV_STATE_FOCUSED);

    //Write style for scr_base_btn_master_device_apply, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_bg_opa(ui->scr_base_btn_master_device_apply, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_bg_color(ui->scr_base_btn_master_device_apply, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_btn_master_device_apply, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui->scr_base_btn_master_device_apply, 1, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_border_opa(ui->scr_base_btn_master_device_apply, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_border_color(ui->scr_base_btn_master_device_apply, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_border_side(ui->scr_base_btn_master_device_apply, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_radius(ui->scr_base_btn_master_device_apply, 10, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->scr_base_btn_master_device_apply, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->scr_base_btn_master_device_apply, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->scr_base_btn_master_device_apply, &lv_font_Roboto_Black_16, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->scr_base_btn_master_device_apply, 255, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for scr_base_btn_master_device_apply, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_bg_opa(ui->scr_base_btn_master_device_apply, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui->scr_base_btn_master_device_apply, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_btn_master_device_apply, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_border_width(ui->scr_base_btn_master_device_apply, 1, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_border_opa(ui->scr_base_btn_master_device_apply, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_border_color(ui->scr_base_btn_master_device_apply, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_border_side(ui->scr_base_btn_master_device_apply, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_radius(ui->scr_base_btn_master_device_apply, 10, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->scr_base_btn_master_device_apply, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->scr_base_btn_master_device_apply, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->scr_base_btn_master_device_apply, &lv_font_Roboto_Black_16, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->scr_base_btn_master_device_apply, 255, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write style for scr_base_btn_master_device_apply, Part: LV_PART_MAIN, State: LV_STATE_DISABLED.
    lv_obj_set_style_bg_opa(ui->scr_base_btn_master_device_apply, 255, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_bg_color(ui->scr_base_btn_master_device_apply, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_btn_master_device_apply, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_border_width(ui->scr_base_btn_master_device_apply, 1, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_border_opa(ui->scr_base_btn_master_device_apply, 255, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_border_color(ui->scr_base_btn_master_device_apply, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_border_side(ui->scr_base_btn_master_device_apply, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_radius(ui->scr_base_btn_master_device_apply, 10, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_shadow_width(ui->scr_base_btn_master_device_apply, 0, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_color(ui->scr_base_btn_master_device_apply, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_font(ui->scr_base_btn_master_device_apply, &lv_font_Roboto_Black_16, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_opa(ui->scr_base_btn_master_device_apply, 255, LV_PART_MAIN|LV_STATE_DISABLED);

    //Write codes scr_base_ddlist_master_device_registers
    ui->scr_base_ddlist_master_device_registers = lv_dropdown_create(ui->scr_base_cont_63);
    lv_obj_set_pos(ui->scr_base_ddlist_master_device_registers, 22, 113);
    lv_obj_set_size(ui->scr_base_ddlist_master_device_registers, 270, 38);
    lv_dropdown_set_options(ui->scr_base_ddlist_master_device_registers, "READ COILS\nREAD DISCRETE INPUTS\nREAD HOLDING REGS\nREAD INPUT REGS\nWRITE SINGLE COIL\nWRITE SINGLE REG\nWRITE MULTI COILS\nWRITE MULTI REGS");

    //Write style for scr_base_ddlist_master_device_registers, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->scr_base_ddlist_master_device_registers, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_ddlist_master_device_registers, &lv_font_Roboto_Regular_14, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_ddlist_master_device_registers, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->scr_base_ddlist_master_device_registers, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scr_base_ddlist_master_device_registers, 56, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scr_base_ddlist_master_device_registers, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scr_base_ddlist_master_device_registers, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_ddlist_master_device_registers, 12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_ddlist_master_device_registers, 12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_ddlist_master_device_registers, 12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_ddlist_master_device_registers, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_ddlist_master_device_registers, 130, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_base_ddlist_master_device_registers, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_ddlist_master_device_registers, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_ddlist_master_device_registers, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for scr_base_ddlist_master_device_registers, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_text_color(ui->scr_base_ddlist_master_device_registers, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->scr_base_ddlist_master_device_registers, &lv_font_Roboto_Regular_14, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->scr_base_ddlist_master_device_registers, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_border_width(ui->scr_base_ddlist_master_device_registers, 1, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_border_opa(ui->scr_base_ddlist_master_device_registers, 58, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_border_color(ui->scr_base_ddlist_master_device_registers, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_border_side(ui->scr_base_ddlist_master_device_registers, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_pad_top(ui->scr_base_ddlist_master_device_registers, 12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_pad_left(ui->scr_base_ddlist_master_device_registers, 12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_pad_right(ui->scr_base_ddlist_master_device_registers, 12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_radius(ui->scr_base_ddlist_master_device_registers, 10, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_opa(ui->scr_base_ddlist_master_device_registers, 129, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui->scr_base_ddlist_master_device_registers, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_ddlist_master_device_registers, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->scr_base_ddlist_master_device_registers, 0, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write style for scr_base_ddlist_master_device_registers, Part: LV_PART_MAIN, State: LV_STATE_FOCUSED.
    lv_obj_set_style_text_color(ui->scr_base_ddlist_master_device_registers, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_font(ui->scr_base_ddlist_master_device_registers, &lv_font_Roboto_Regular_14, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_opa(ui->scr_base_ddlist_master_device_registers, 255, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_width(ui->scr_base_ddlist_master_device_registers, 1, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_opa(ui->scr_base_ddlist_master_device_registers, 70, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_color(ui->scr_base_ddlist_master_device_registers, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_side(ui->scr_base_ddlist_master_device_registers, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_pad_top(ui->scr_base_ddlist_master_device_registers, 12, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_pad_left(ui->scr_base_ddlist_master_device_registers, 12, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_pad_right(ui->scr_base_ddlist_master_device_registers, 12, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_radius(ui->scr_base_ddlist_master_device_registers, 10, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_opa(ui->scr_base_ddlist_master_device_registers, 130, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_color(ui->scr_base_ddlist_master_device_registers, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_ddlist_master_device_registers, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_shadow_width(ui->scr_base_ddlist_master_device_registers, 0, LV_PART_MAIN|LV_STATE_FOCUSED);

    //Write style for scr_base_ddlist_master_device_registers, Part: LV_PART_MAIN, State: LV_STATE_DISABLED.
    lv_obj_set_style_text_color(ui->scr_base_ddlist_master_device_registers, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_font(ui->scr_base_ddlist_master_device_registers, &lv_font_Roboto_Regular_14, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_opa(ui->scr_base_ddlist_master_device_registers, 255, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_border_width(ui->scr_base_ddlist_master_device_registers, 1, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_border_opa(ui->scr_base_ddlist_master_device_registers, 61, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_border_color(ui->scr_base_ddlist_master_device_registers, lv_color_hex(0xe1e6ee), LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_border_side(ui->scr_base_ddlist_master_device_registers, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_pad_top(ui->scr_base_ddlist_master_device_registers, 12, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_pad_left(ui->scr_base_ddlist_master_device_registers, 12, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_pad_right(ui->scr_base_ddlist_master_device_registers, 12, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_radius(ui->scr_base_ddlist_master_device_registers, 10, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_bg_opa(ui->scr_base_ddlist_master_device_registers, 130, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_bg_color(ui->scr_base_ddlist_master_device_registers, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_ddlist_master_device_registers, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_shadow_width(ui->scr_base_ddlist_master_device_registers, 0, LV_PART_MAIN|LV_STATE_DISABLED);

    //Write style state: LV_STATE_CHECKED for &style_scr_base_ddlist_master_device_registers_extra_list_selected_checked
    static lv_style_t style_scr_base_ddlist_master_device_registers_extra_list_selected_checked;
    ui_init_style(&style_scr_base_ddlist_master_device_registers_extra_list_selected_checked);

    lv_style_set_border_width(&style_scr_base_ddlist_master_device_registers_extra_list_selected_checked, 1);
    lv_style_set_border_opa(&style_scr_base_ddlist_master_device_registers_extra_list_selected_checked, 255);
    lv_style_set_border_color(&style_scr_base_ddlist_master_device_registers_extra_list_selected_checked, lv_color_hex(0xe1e6ee));
    lv_style_set_border_side(&style_scr_base_ddlist_master_device_registers_extra_list_selected_checked, LV_BORDER_SIDE_FULL);
    lv_style_set_radius(&style_scr_base_ddlist_master_device_registers_extra_list_selected_checked, 1);
    lv_style_set_bg_opa(&style_scr_base_ddlist_master_device_registers_extra_list_selected_checked, 129);
    lv_style_set_bg_color(&style_scr_base_ddlist_master_device_registers_extra_list_selected_checked, lv_color_hex(0x00a1b5));
    lv_style_set_bg_grad_dir(&style_scr_base_ddlist_master_device_registers_extra_list_selected_checked, LV_GRAD_DIR_NONE);
    lv_obj_add_style(lv_dropdown_get_list(ui->scr_base_ddlist_master_device_registers), &style_scr_base_ddlist_master_device_registers_extra_list_selected_checked, LV_PART_SELECTED|LV_STATE_CHECKED);

    //Write style state: LV_STATE_DEFAULT for &style_scr_base_ddlist_master_device_registers_extra_list_main_default
    static lv_style_t style_scr_base_ddlist_master_device_registers_extra_list_main_default;
    ui_init_style(&style_scr_base_ddlist_master_device_registers_extra_list_main_default);

    lv_style_set_max_height(&style_scr_base_ddlist_master_device_registers_extra_list_main_default, 90);
    lv_style_set_text_color(&style_scr_base_ddlist_master_device_registers_extra_list_main_default, lv_color_hex(0xfdfdfd));
    lv_style_set_text_font(&style_scr_base_ddlist_master_device_registers_extra_list_main_default, &lv_font_Roboto_Regular_14);
    lv_style_set_text_opa(&style_scr_base_ddlist_master_device_registers_extra_list_main_default, 255);
    lv_style_set_border_width(&style_scr_base_ddlist_master_device_registers_extra_list_main_default, 1);
    lv_style_set_border_opa(&style_scr_base_ddlist_master_device_registers_extra_list_main_default, 54);
    lv_style_set_border_color(&style_scr_base_ddlist_master_device_registers_extra_list_main_default, lv_color_hex(0xffffff));
    lv_style_set_border_side(&style_scr_base_ddlist_master_device_registers_extra_list_main_default, LV_BORDER_SIDE_FULL);
    lv_style_set_radius(&style_scr_base_ddlist_master_device_registers_extra_list_main_default, 5);
    lv_style_set_bg_opa(&style_scr_base_ddlist_master_device_registers_extra_list_main_default, 180);
    lv_style_set_bg_color(&style_scr_base_ddlist_master_device_registers_extra_list_main_default, lv_color_hex(0x000000));
    lv_style_set_bg_grad_dir(&style_scr_base_ddlist_master_device_registers_extra_list_main_default, LV_GRAD_DIR_NONE);
    lv_obj_add_style(lv_dropdown_get_list(ui->scr_base_ddlist_master_device_registers), &style_scr_base_ddlist_master_device_registers_extra_list_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_DEFAULT for &style_scr_base_ddlist_master_device_registers_extra_list_scrollbar_default
    static lv_style_t style_scr_base_ddlist_master_device_registers_extra_list_scrollbar_default;
    ui_init_style(&style_scr_base_ddlist_master_device_registers_extra_list_scrollbar_default);

    lv_style_set_radius(&style_scr_base_ddlist_master_device_registers_extra_list_scrollbar_default, 3);
    lv_style_set_bg_opa(&style_scr_base_ddlist_master_device_registers_extra_list_scrollbar_default, 47);
    lv_style_set_bg_color(&style_scr_base_ddlist_master_device_registers_extra_list_scrollbar_default, lv_color_hex(0xcccccc));
    lv_style_set_bg_grad_dir(&style_scr_base_ddlist_master_device_registers_extra_list_scrollbar_default, LV_GRAD_DIR_NONE);
    lv_obj_add_style(lv_dropdown_get_list(ui->scr_base_ddlist_master_device_registers), &style_scr_base_ddlist_master_device_registers_extra_list_scrollbar_default, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);

    //Write codes scr_base_label_182
    ui->scr_base_label_182 = lv_label_create(ui->scr_base_cont_63);
    lv_obj_set_pos(ui->scr_base_label_182, 22, 163);
    lv_obj_set_size(ui->scr_base_label_182, 112, 13);
    lv_label_set_text(ui->scr_base_label_182, "QUANTITY");
    lv_label_set_long_mode(ui->scr_base_label_182, LV_LABEL_LONG_WRAP);

    //Write style for scr_base_label_182, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_label_182, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_label_182, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_base_label_182, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_label_182, &lv_font_Roboto_Bold_15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_label_182, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_base_label_182, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_base_label_182, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_label_182, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_label_182, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_label_182, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_label_182, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_label_182, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_label_182, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_label_182, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_label_181
    ui->scr_base_label_181 = lv_label_create(ui->scr_base_cont_63);
    lv_obj_set_pos(ui->scr_base_label_181, 313, 90);
    lv_obj_set_size(ui->scr_base_label_181, 174, 17);
    lv_label_set_text(ui->scr_base_label_181, "REGISTER ADDRESS");
    lv_label_set_long_mode(ui->scr_base_label_181, LV_LABEL_LONG_WRAP);

    //Write style for scr_base_label_181, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_label_181, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_label_181, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_base_label_181, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_label_181, &lv_font_Roboto_Bold_15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_label_181, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_base_label_181, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_base_label_181, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_label_181, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_label_181, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_label_181, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_label_181, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_label_181, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_label_181, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_label_181, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_ta_master_device_slaveid
    ui->scr_base_ta_master_device_slaveid = lv_textarea_create(ui->scr_base_cont_63);
    lv_obj_set_pos(ui->scr_base_ta_master_device_slaveid, 23, 35);
    lv_obj_set_size(ui->scr_base_ta_master_device_slaveid, 560, 38);
    lv_textarea_set_text(ui->scr_base_ta_master_device_slaveid, "");
    lv_textarea_set_placeholder_text(ui->scr_base_ta_master_device_slaveid, "Enter Slave ID...");
    lv_textarea_set_password_bullet(ui->scr_base_ta_master_device_slaveid, "*");
    lv_textarea_set_password_mode(ui->scr_base_ta_master_device_slaveid, false);
    lv_textarea_set_one_line(ui->scr_base_ta_master_device_slaveid, true);
    lv_textarea_set_accepted_chars(ui->scr_base_ta_master_device_slaveid, "");
    lv_textarea_set_max_length(ui->scr_base_ta_master_device_slaveid, 32);
#if LV_USE_KEYBOARD
    lv_obj_add_event_cb(ui->scr_base_ta_master_device_slaveid, ta_event_cb, LV_EVENT_ALL, ui->g_kb_top_layer);
#endif

    //Write style for scr_base_ta_master_device_slaveid, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->scr_base_ta_master_device_slaveid, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_ta_master_device_slaveid, &lv_font_Roboto_Regular_14, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_ta_master_device_slaveid, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_base_ta_master_device_slaveid, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_ta_master_device_slaveid, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_ta_master_device_slaveid, 130, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_base_ta_master_device_slaveid, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_ta_master_device_slaveid, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->scr_base_ta_master_device_slaveid, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scr_base_ta_master_device_slaveid, 58, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scr_base_ta_master_device_slaveid, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scr_base_ta_master_device_slaveid, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_ta_master_device_slaveid, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_ta_master_device_slaveid, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_ta_master_device_slaveid, 12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_ta_master_device_slaveid, 12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_ta_master_device_slaveid, 10, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for scr_base_ta_master_device_slaveid, Part: LV_PART_MAIN, State: LV_STATE_FOCUSED.
    lv_obj_set_style_text_color(ui->scr_base_ta_master_device_slaveid, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_font(ui->scr_base_ta_master_device_slaveid, &lv_font_Roboto_Regular_14, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_opa(ui->scr_base_ta_master_device_slaveid, 255, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_opa(ui->scr_base_ta_master_device_slaveid, 130, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_color(ui->scr_base_ta_master_device_slaveid, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_ta_master_device_slaveid, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_width(ui->scr_base_ta_master_device_slaveid, 1, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_opa(ui->scr_base_ta_master_device_slaveid, 53, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_color(ui->scr_base_ta_master_device_slaveid, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_side(ui->scr_base_ta_master_device_slaveid, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_shadow_width(ui->scr_base_ta_master_device_slaveid, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_pad_top(ui->scr_base_ta_master_device_slaveid, 10, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_pad_right(ui->scr_base_ta_master_device_slaveid, 12, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_pad_left(ui->scr_base_ta_master_device_slaveid, 12, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_radius(ui->scr_base_ta_master_device_slaveid, 10, LV_PART_MAIN|LV_STATE_FOCUSED);

    //Write style for scr_base_ta_master_device_slaveid, Part: LV_PART_SCROLLBAR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->scr_base_ta_master_device_slaveid, 255, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_base_ta_master_device_slaveid, lv_color_hex(0x2195f6), LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_ta_master_device_slaveid, LV_GRAD_DIR_NONE, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_ta_master_device_slaveid, 0, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);

    //Write codes scr_base_ta_master_device_address
    ui->scr_base_ta_master_device_address = lv_textarea_create(ui->scr_base_cont_63);
    lv_obj_set_pos(ui->scr_base_ta_master_device_address, 312, 113);
    lv_obj_set_size(ui->scr_base_ta_master_device_address, 270, 38);
    lv_textarea_set_text(ui->scr_base_ta_master_device_address, "");
    lv_textarea_set_placeholder_text(ui->scr_base_ta_master_device_address, "Enter Register address...");
    lv_textarea_set_password_bullet(ui->scr_base_ta_master_device_address, "*");
    lv_textarea_set_password_mode(ui->scr_base_ta_master_device_address, false);
    lv_textarea_set_one_line(ui->scr_base_ta_master_device_address, true);
    lv_textarea_set_accepted_chars(ui->scr_base_ta_master_device_address, "");
    lv_textarea_set_max_length(ui->scr_base_ta_master_device_address, 32);
#if LV_USE_KEYBOARD
    lv_obj_add_event_cb(ui->scr_base_ta_master_device_address, ta_event_cb, LV_EVENT_ALL, ui->g_kb_top_layer);
#endif

    //Write style for scr_base_ta_master_device_address, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->scr_base_ta_master_device_address, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_ta_master_device_address, &lv_font_Roboto_Regular_14, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_ta_master_device_address, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_base_ta_master_device_address, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_ta_master_device_address, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_ta_master_device_address, 130, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_base_ta_master_device_address, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_ta_master_device_address, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->scr_base_ta_master_device_address, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scr_base_ta_master_device_address, 58, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scr_base_ta_master_device_address, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scr_base_ta_master_device_address, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_ta_master_device_address, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_ta_master_device_address, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_ta_master_device_address, 12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_ta_master_device_address, 12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_ta_master_device_address, 10, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for scr_base_ta_master_device_address, Part: LV_PART_MAIN, State: LV_STATE_FOCUSED.
    lv_obj_set_style_text_color(ui->scr_base_ta_master_device_address, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_font(ui->scr_base_ta_master_device_address, &lv_font_Roboto_Regular_14, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_opa(ui->scr_base_ta_master_device_address, 255, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_opa(ui->scr_base_ta_master_device_address, 130, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_color(ui->scr_base_ta_master_device_address, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_ta_master_device_address, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_width(ui->scr_base_ta_master_device_address, 1, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_opa(ui->scr_base_ta_master_device_address, 53, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_color(ui->scr_base_ta_master_device_address, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_side(ui->scr_base_ta_master_device_address, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_shadow_width(ui->scr_base_ta_master_device_address, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_pad_top(ui->scr_base_ta_master_device_address, 10, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_pad_right(ui->scr_base_ta_master_device_address, 12, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_pad_left(ui->scr_base_ta_master_device_address, 12, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_radius(ui->scr_base_ta_master_device_address, 10, LV_PART_MAIN|LV_STATE_FOCUSED);

    //Write style for scr_base_ta_master_device_address, Part: LV_PART_SCROLLBAR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->scr_base_ta_master_device_address, 255, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_base_ta_master_device_address, lv_color_hex(0x2195f6), LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_ta_master_device_address, LV_GRAD_DIR_NONE, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_ta_master_device_address, 0, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);

    //Write codes scr_base_ta_master_device_quantity
    ui->scr_base_ta_master_device_quantity = lv_textarea_create(ui->scr_base_cont_63);
    lv_obj_set_pos(ui->scr_base_ta_master_device_quantity, 22, 185);
    lv_obj_set_size(ui->scr_base_ta_master_device_quantity, 560, 38);
    lv_textarea_set_text(ui->scr_base_ta_master_device_quantity, "");
    lv_textarea_set_placeholder_text(ui->scr_base_ta_master_device_quantity, "Enter Quantity...");
    lv_textarea_set_password_bullet(ui->scr_base_ta_master_device_quantity, "*");
    lv_textarea_set_password_mode(ui->scr_base_ta_master_device_quantity, false);
    lv_textarea_set_one_line(ui->scr_base_ta_master_device_quantity, true);
    lv_textarea_set_accepted_chars(ui->scr_base_ta_master_device_quantity, "");
    lv_textarea_set_max_length(ui->scr_base_ta_master_device_quantity, 32);
#if LV_USE_KEYBOARD
    lv_obj_add_event_cb(ui->scr_base_ta_master_device_quantity, ta_event_cb, LV_EVENT_ALL, ui->g_kb_top_layer);
#endif

    //Write style for scr_base_ta_master_device_quantity, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->scr_base_ta_master_device_quantity, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_ta_master_device_quantity, &lv_font_Roboto_Regular_14, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_ta_master_device_quantity, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_base_ta_master_device_quantity, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_ta_master_device_quantity, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_ta_master_device_quantity, 130, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_base_ta_master_device_quantity, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_ta_master_device_quantity, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->scr_base_ta_master_device_quantity, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scr_base_ta_master_device_quantity, 58, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scr_base_ta_master_device_quantity, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scr_base_ta_master_device_quantity, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_ta_master_device_quantity, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_ta_master_device_quantity, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_ta_master_device_quantity, 12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_ta_master_device_quantity, 12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_ta_master_device_quantity, 10, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for scr_base_ta_master_device_quantity, Part: LV_PART_MAIN, State: LV_STATE_FOCUSED.
    lv_obj_set_style_text_color(ui->scr_base_ta_master_device_quantity, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_font(ui->scr_base_ta_master_device_quantity, &lv_font_Roboto_Regular_14, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_opa(ui->scr_base_ta_master_device_quantity, 255, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_opa(ui->scr_base_ta_master_device_quantity, 130, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_color(ui->scr_base_ta_master_device_quantity, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_ta_master_device_quantity, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_width(ui->scr_base_ta_master_device_quantity, 1, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_opa(ui->scr_base_ta_master_device_quantity, 53, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_color(ui->scr_base_ta_master_device_quantity, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_side(ui->scr_base_ta_master_device_quantity, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_shadow_width(ui->scr_base_ta_master_device_quantity, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_pad_top(ui->scr_base_ta_master_device_quantity, 10, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_pad_right(ui->scr_base_ta_master_device_quantity, 12, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_pad_left(ui->scr_base_ta_master_device_quantity, 12, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_radius(ui->scr_base_ta_master_device_quantity, 10, LV_PART_MAIN|LV_STATE_FOCUSED);

    //Write style for scr_base_ta_master_device_quantity, Part: LV_PART_SCROLLBAR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->scr_base_ta_master_device_quantity, 255, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_base_ta_master_device_quantity, lv_color_hex(0x2195f6), LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_ta_master_device_quantity, LV_GRAD_DIR_NONE, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_ta_master_device_quantity, 0, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);

    //Write codes scr_base_ta_master_device_register_mapping
    ui->scr_base_ta_master_device_register_mapping = lv_textarea_create(ui->scr_base_cont_63);
    lv_obj_set_pos(ui->scr_base_ta_master_device_register_mapping, 22, 260);
    lv_obj_set_size(ui->scr_base_ta_master_device_register_mapping, 560, 38);
    lv_textarea_set_text(ui->scr_base_ta_master_device_register_mapping, "");
    lv_textarea_set_placeholder_text(ui->scr_base_ta_master_device_register_mapping, "Enter register address remapping...");
    lv_textarea_set_password_bullet(ui->scr_base_ta_master_device_register_mapping, "*");
    lv_textarea_set_password_mode(ui->scr_base_ta_master_device_register_mapping, false);
    lv_textarea_set_one_line(ui->scr_base_ta_master_device_register_mapping, true);
    lv_textarea_set_accepted_chars(ui->scr_base_ta_master_device_register_mapping, "");
    lv_textarea_set_max_length(ui->scr_base_ta_master_device_register_mapping, 32);
#if LV_USE_KEYBOARD
    lv_obj_add_event_cb(ui->scr_base_ta_master_device_register_mapping, ta_event_cb, LV_EVENT_ALL, ui->g_kb_top_layer);
#endif

    //Write style for scr_base_ta_master_device_register_mapping, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->scr_base_ta_master_device_register_mapping, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_ta_master_device_register_mapping, &lv_font_Roboto_Regular_14, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_ta_master_device_register_mapping, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_base_ta_master_device_register_mapping, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_ta_master_device_register_mapping, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_ta_master_device_register_mapping, 130, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_base_ta_master_device_register_mapping, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_ta_master_device_register_mapping, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->scr_base_ta_master_device_register_mapping, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scr_base_ta_master_device_register_mapping, 58, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scr_base_ta_master_device_register_mapping, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scr_base_ta_master_device_register_mapping, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_ta_master_device_register_mapping, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_ta_master_device_register_mapping, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_ta_master_device_register_mapping, 12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_ta_master_device_register_mapping, 12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_ta_master_device_register_mapping, 10, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for scr_base_ta_master_device_register_mapping, Part: LV_PART_MAIN, State: LV_STATE_FOCUSED.
    lv_obj_set_style_text_color(ui->scr_base_ta_master_device_register_mapping, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_font(ui->scr_base_ta_master_device_register_mapping, &lv_font_Roboto_Regular_14, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_opa(ui->scr_base_ta_master_device_register_mapping, 255, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_opa(ui->scr_base_ta_master_device_register_mapping, 130, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_color(ui->scr_base_ta_master_device_register_mapping, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_ta_master_device_register_mapping, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_width(ui->scr_base_ta_master_device_register_mapping, 1, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_opa(ui->scr_base_ta_master_device_register_mapping, 53, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_color(ui->scr_base_ta_master_device_register_mapping, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_side(ui->scr_base_ta_master_device_register_mapping, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_shadow_width(ui->scr_base_ta_master_device_register_mapping, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_pad_top(ui->scr_base_ta_master_device_register_mapping, 10, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_pad_right(ui->scr_base_ta_master_device_register_mapping, 12, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_pad_left(ui->scr_base_ta_master_device_register_mapping, 12, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_radius(ui->scr_base_ta_master_device_register_mapping, 10, LV_PART_MAIN|LV_STATE_FOCUSED);

    //Write style for scr_base_ta_master_device_register_mapping, Part: LV_PART_SCROLLBAR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->scr_base_ta_master_device_register_mapping, 255, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_base_ta_master_device_register_mapping, lv_color_hex(0x2195f6), LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_ta_master_device_register_mapping, LV_GRAD_DIR_NONE, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_ta_master_device_register_mapping, 0, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);

    //Write codes scr_base_label_183
    ui->scr_base_label_183 = lv_label_create(ui->scr_base_cont_62);
    lv_obj_set_pos(ui->scr_base_label_183, 209, 15);
    lv_obj_set_size(ui->scr_base_label_183, 242, 24);
    lv_label_set_text(ui->scr_base_label_183, "" LV_SYMBOL_DOWNLOAD "  DEVICE CONFIGURATION ");
    lv_label_set_long_mode(ui->scr_base_label_183, LV_LABEL_LONG_WRAP);

    //Write style for scr_base_label_183, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_label_183, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_label_183, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_base_label_183, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_label_183, &lv_font_Roboto_Black_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_label_183, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_base_label_183, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_base_label_183, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_label_183, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_label_183, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_label_183, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_label_183, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_label_183, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_label_183, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_label_183, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_cont_deviceconfig_back
    ui->scr_base_cont_deviceconfig_back = lv_obj_create(ui->scr_base_cont_62);
    lv_obj_set_pos(ui->scr_base_cont_deviceconfig_back, 5, 5);
    lv_obj_set_size(ui->scr_base_cont_deviceconfig_back, 40, 40);
    lv_obj_set_scrollbar_mode(ui->scr_base_cont_deviceconfig_back, LV_SCROLLBAR_MODE_OFF);

    //Write style for scr_base_cont_deviceconfig_back, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_cont_deviceconfig_back, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scr_base_cont_deviceconfig_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scr_base_cont_deviceconfig_back, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scr_base_cont_deviceconfig_back, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_cont_deviceconfig_back, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_cont_deviceconfig_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_cont_deviceconfig_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_cont_deviceconfig_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_cont_deviceconfig_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_cont_deviceconfig_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_cont_deviceconfig_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_img_22
    ui->scr_base_img_22 = lv_image_create(ui->scr_base_cont_deviceconfig_back);
    lv_obj_set_pos(ui->scr_base_img_22, 7, 7);
    lv_obj_set_size(ui->scr_base_img_22, 24, 24);
    lv_obj_add_flag(ui->scr_base_img_22, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->scr_base_img_22, &_left_arrow_RGB565A8_24x24);
    lv_image_set_pivot(ui->scr_base_img_22, 50,50);
    lv_image_set_rotation(ui->scr_base_img_22, 0);

    //Write style for scr_base_img_22, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->scr_base_img_22, 189, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_recolor(ui->scr_base_img_22, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->scr_base_img_22, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_btn_deviceconfig_back
    ui->scr_base_btn_deviceconfig_back = lv_button_create(ui->scr_base_cont_deviceconfig_back);
    lv_obj_set_pos(ui->scr_base_btn_deviceconfig_back, -6, -6);
    lv_obj_set_size(ui->scr_base_btn_deviceconfig_back, 50, 50);
    ui->scr_base_btn_deviceconfig_back_label = lv_label_create(ui->scr_base_btn_deviceconfig_back);
    lv_label_set_text(ui->scr_base_btn_deviceconfig_back_label, "");
    lv_label_set_long_mode(ui->scr_base_btn_deviceconfig_back_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->scr_base_btn_deviceconfig_back_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->scr_base_btn_deviceconfig_back, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->scr_base_btn_deviceconfig_back_label, LV_PCT(100));

    //Write style for scr_base_btn_deviceconfig_back, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->scr_base_btn_deviceconfig_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->scr_base_btn_deviceconfig_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_btn_deviceconfig_back, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_btn_deviceconfig_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_base_btn_deviceconfig_back, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_btn_deviceconfig_back, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_btn_deviceconfig_back, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_btn_deviceconfig_back, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for scr_base_btn_deviceconfig_back, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_bg_opa(ui->scr_base_btn_deviceconfig_back, 42, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_bg_color(ui->scr_base_btn_deviceconfig_back, lv_color_hex(0x10B981), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_btn_deviceconfig_back, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui->scr_base_btn_deviceconfig_back, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_radius(ui->scr_base_btn_deviceconfig_back, 10, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->scr_base_btn_deviceconfig_back, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->scr_base_btn_deviceconfig_back, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->scr_base_btn_deviceconfig_back, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->scr_base_btn_deviceconfig_back, 255, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for scr_base_btn_deviceconfig_back, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_bg_opa(ui->scr_base_btn_deviceconfig_back, 44, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui->scr_base_btn_deviceconfig_back, lv_color_hex(0x10B981), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_btn_deviceconfig_back, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_border_width(ui->scr_base_btn_deviceconfig_back, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_radius(ui->scr_base_btn_deviceconfig_back, 10, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->scr_base_btn_deviceconfig_back, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->scr_base_btn_deviceconfig_back, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->scr_base_btn_deviceconfig_back, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->scr_base_btn_deviceconfig_back, 255, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write codes scr_base_cont_restart
    ui->scr_base_cont_restart = lv_obj_create(ui->scr_base);
    lv_obj_set_pos(ui->scr_base_cont_restart, 0, 0);
    lv_obj_set_size(ui->scr_base_cont_restart, 800, 480);
    lv_obj_set_scrollbar_mode(ui->scr_base_cont_restart, LV_SCROLLBAR_MODE_OFF);
    lv_obj_add_flag(ui->scr_base_cont_restart, LV_OBJ_FLAG_HIDDEN);

    //Write style for scr_base_cont_restart, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_cont_restart, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_cont_restart, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_cont_restart, 204, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_base_cont_restart, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_cont_restart, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_cont_restart, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_cont_restart, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_cont_restart, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_cont_restart, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_cont_restart, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_cont_restart_system
    ui->scr_base_cont_restart_system = lv_obj_create(ui->scr_base_cont_restart);
    lv_obj_set_pos(ui->scr_base_cont_restart_system, 203, 87);
    lv_obj_set_size(ui->scr_base_cont_restart_system, 400, 300);
    lv_obj_set_scrollbar_mode(ui->scr_base_cont_restart_system, LV_SCROLLBAR_MODE_OFF);

    //Write style for scr_base_cont_restart_system, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_cont_restart_system, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scr_base_cont_restart_system, 48, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scr_base_cont_restart_system, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scr_base_cont_restart_system, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_cont_restart_system, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_cont_restart_system, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_base_cont_restart_system, lv_color_hex(0x0F172A), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_cont_restart_system, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_cont_restart_system, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_cont_restart_system, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_cont_restart_system, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_cont_restart_system, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_cont_restart_system, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_img_12
    ui->scr_base_img_12 = lv_image_create(ui->scr_base_cont_restart_system);
    lv_obj_set_pos(ui->scr_base_img_12, 150, 22);
    lv_obj_set_size(ui->scr_base_img_12, 100, 100);
    lv_obj_add_flag(ui->scr_base_img_12, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->scr_base_img_12, &_power_button_RGB565A8_100x100);
    lv_image_set_pivot(ui->scr_base_img_12, 50,50);
    lv_image_set_rotation(ui->scr_base_img_12, 0);

    //Write style for scr_base_img_12, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->scr_base_img_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->scr_base_img_12, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_label_95
    ui->scr_base_label_95 = lv_label_create(ui->scr_base_cont_restart_system);
    lv_obj_set_pos(ui->scr_base_label_95, 0, 138);
    lv_obj_set_size(ui->scr_base_label_95, 400, 30);
    lv_label_set_text(ui->scr_base_label_95, "RESTART SYSTEM?");
    lv_label_set_long_mode(ui->scr_base_label_95, LV_LABEL_LONG_WRAP);

    //Write style for scr_base_label_95, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_label_95, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_label_95, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_base_label_95, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_label_95, &lv_font_Roboto_Black_25, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_label_95, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_base_label_95, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_base_label_95, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_label_95, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_label_95, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_label_95, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_label_95, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_label_95, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_label_95, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_label_95, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_label_96
    ui->scr_base_label_96 = lv_label_create(ui->scr_base_cont_restart_system);
    lv_obj_set_pos(ui->scr_base_label_96, 44, 177);
    lv_obj_set_size(ui->scr_base_label_96, 311, 46);
    lv_label_set_text(ui->scr_base_label_96, "The system will reboot now. Current data logging sessions will be resumed after startup.");
    lv_label_set_long_mode(ui->scr_base_label_96, LV_LABEL_LONG_WRAP);

    //Write style for scr_base_label_96, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_label_96, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_label_96, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_base_label_96, lv_color_hex(0xABABAB), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_label_96, &lv_font_Roboto_Regular_14, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_label_96, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_base_label_96, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_base_label_96, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_label_96, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_label_96, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_label_96, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_label_96, 30, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_label_96, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_label_96, 30, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_label_96, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_btn_restart_confirm
    ui->scr_base_btn_restart_confirm = lv_button_create(ui->scr_base_cont_restart_system);
    lv_obj_set_pos(ui->scr_base_btn_restart_confirm, 207, 237);
    lv_obj_set_size(ui->scr_base_btn_restart_confirm, 174, 38);
    ui->scr_base_btn_restart_confirm_label = lv_label_create(ui->scr_base_btn_restart_confirm);
    lv_label_set_text(ui->scr_base_btn_restart_confirm_label, "CONFIRM");
    lv_label_set_long_mode(ui->scr_base_btn_restart_confirm_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->scr_base_btn_restart_confirm_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->scr_base_btn_restart_confirm, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->scr_base_btn_restart_confirm_label, LV_PCT(100));

    //Write style for scr_base_btn_restart_confirm, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->scr_base_btn_restart_confirm, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_base_btn_restart_confirm, lv_color_hex(0x10B981), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_btn_restart_confirm, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->scr_base_btn_restart_confirm, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scr_base_btn_restart_confirm, 37, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scr_base_btn_restart_confirm, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scr_base_btn_restart_confirm, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_btn_restart_confirm, 12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_btn_restart_confirm, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_base_btn_restart_confirm, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_btn_restart_confirm, &lv_font_Roboto_Black_15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_btn_restart_confirm, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_btn_restart_confirm, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_btn_restart_cancel
    ui->scr_base_btn_restart_cancel = lv_button_create(ui->scr_base_cont_restart_system);
    lv_obj_set_pos(ui->scr_base_btn_restart_cancel, 19, 237);
    lv_obj_set_size(ui->scr_base_btn_restart_cancel, 174, 38);
    ui->scr_base_btn_restart_cancel_label = lv_label_create(ui->scr_base_btn_restart_cancel);
    lv_label_set_text(ui->scr_base_btn_restart_cancel_label, "CANCEL");
    lv_label_set_long_mode(ui->scr_base_btn_restart_cancel_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->scr_base_btn_restart_cancel_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->scr_base_btn_restart_cancel, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->scr_base_btn_restart_cancel_label, LV_PCT(100));

    //Write style for scr_base_btn_restart_cancel, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->scr_base_btn_restart_cancel, 193, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_base_btn_restart_cancel, lv_color_hex(0x1d1d1d), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_btn_restart_cancel, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->scr_base_btn_restart_cancel, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scr_base_btn_restart_cancel, 37, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scr_base_btn_restart_cancel, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scr_base_btn_restart_cancel, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_btn_restart_cancel, 12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_btn_restart_cancel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_base_btn_restart_cancel, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_btn_restart_cancel, &lv_font_Roboto_Black_15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_btn_restart_cancel, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_btn_restart_cancel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_cont_restore
    ui->scr_base_cont_restore = lv_obj_create(ui->scr_base);
    lv_obj_set_pos(ui->scr_base_cont_restore, 0, 0);
    lv_obj_set_size(ui->scr_base_cont_restore, 800, 480);
    lv_obj_set_scrollbar_mode(ui->scr_base_cont_restore, LV_SCROLLBAR_MODE_OFF);
    lv_obj_add_flag(ui->scr_base_cont_restore, LV_OBJ_FLAG_HIDDEN);

    //Write style for scr_base_cont_restore, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_cont_restore, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_cont_restore, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_cont_restore, 204, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_base_cont_restore, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_cont_restore, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_cont_restore, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_cont_restore, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_cont_restore, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_cont_restore, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_cont_restore, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_cont_31
    ui->scr_base_cont_31 = lv_obj_create(ui->scr_base_cont_restore);
    lv_obj_set_pos(ui->scr_base_cont_31, 203, 87);
    lv_obj_set_size(ui->scr_base_cont_31, 400, 300);
    lv_obj_set_scrollbar_mode(ui->scr_base_cont_31, LV_SCROLLBAR_MODE_OFF);

    //Write style for scr_base_cont_31, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_cont_31, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scr_base_cont_31, 48, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scr_base_cont_31, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scr_base_cont_31, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_cont_31, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_cont_31, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_base_cont_31, lv_color_hex(0x0F172A), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_cont_31, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_cont_31, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_cont_31, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_cont_31, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_cont_31, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_cont_31, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_img_13
    ui->scr_base_img_13 = lv_image_create(ui->scr_base_cont_31);
    lv_obj_set_pos(ui->scr_base_img_13, 150, 22);
    lv_obj_set_size(ui->scr_base_img_13, 100, 100);
    lv_obj_add_flag(ui->scr_base_img_13, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->scr_base_img_13, &_power_RGB565A8_100x100);
    lv_image_set_pivot(ui->scr_base_img_13, 50,50);
    lv_image_set_rotation(ui->scr_base_img_13, 0);

    //Write style for scr_base_img_13, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->scr_base_img_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->scr_base_img_13, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_label_98
    ui->scr_base_label_98 = lv_label_create(ui->scr_base_cont_31);
    lv_obj_set_pos(ui->scr_base_label_98, 0, 140);
    lv_obj_set_size(ui->scr_base_label_98, 400, 31);
    lv_label_set_text(ui->scr_base_label_98, "RESTORE DEFAULTS?");
    lv_label_set_long_mode(ui->scr_base_label_98, LV_LABEL_LONG_WRAP);

    //Write style for scr_base_label_98, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_label_98, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_label_98, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_base_label_98, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_label_98, &lv_font_Roboto_Black_25, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_label_98, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_base_label_98, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_base_label_98, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_label_98, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_label_98, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_label_98, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_label_98, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_label_98, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_label_98, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_label_98, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_label_97
    ui->scr_base_label_97 = lv_label_create(ui->scr_base_cont_31);
    lv_obj_set_pos(ui->scr_base_label_97, 37, 179);
    lv_obj_set_size(ui->scr_base_label_97, 326, 46);
    lv_label_set_text(ui->scr_base_label_97, "This will erase all custom configurations and network credentials permanently.");
    lv_label_set_long_mode(ui->scr_base_label_97, LV_LABEL_LONG_WRAP);

    //Write style for scr_base_label_97, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_label_97, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_label_97, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_base_label_97, lv_color_hex(0xABABAB), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_label_97, &lv_font_Roboto_Regular_14, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_label_97, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_base_label_97, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_base_label_97, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_label_97, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_label_97, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_label_97, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_label_97, 30, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_label_97, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_label_97, 30, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_label_97, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_btn_restore_confirm
    ui->scr_base_btn_restore_confirm = lv_button_create(ui->scr_base_cont_31);
    lv_obj_set_pos(ui->scr_base_btn_restore_confirm, 207, 237);
    lv_obj_set_size(ui->scr_base_btn_restore_confirm, 174, 38);
    ui->scr_base_btn_restore_confirm_label = lv_label_create(ui->scr_base_btn_restore_confirm);
    lv_label_set_text(ui->scr_base_btn_restore_confirm_label, "CONFIRM");
    lv_label_set_long_mode(ui->scr_base_btn_restore_confirm_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->scr_base_btn_restore_confirm_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->scr_base_btn_restore_confirm, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->scr_base_btn_restore_confirm_label, LV_PCT(100));

    //Write style for scr_base_btn_restore_confirm, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->scr_base_btn_restore_confirm, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_base_btn_restore_confirm, lv_color_hex(0x10B981), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_btn_restore_confirm, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->scr_base_btn_restore_confirm, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scr_base_btn_restore_confirm, 37, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scr_base_btn_restore_confirm, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scr_base_btn_restore_confirm, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_btn_restore_confirm, 12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_btn_restore_confirm, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_base_btn_restore_confirm, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_btn_restore_confirm, &lv_font_Roboto_Black_15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_btn_restore_confirm, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_btn_restore_confirm, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_btn_restore_cancel
    ui->scr_base_btn_restore_cancel = lv_button_create(ui->scr_base_cont_31);
    lv_obj_set_pos(ui->scr_base_btn_restore_cancel, 19, 237);
    lv_obj_set_size(ui->scr_base_btn_restore_cancel, 174, 38);
    ui->scr_base_btn_restore_cancel_label = lv_label_create(ui->scr_base_btn_restore_cancel);
    lv_label_set_text(ui->scr_base_btn_restore_cancel_label, "CANCEL");
    lv_label_set_long_mode(ui->scr_base_btn_restore_cancel_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->scr_base_btn_restore_cancel_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->scr_base_btn_restore_cancel, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->scr_base_btn_restore_cancel_label, LV_PCT(100));

    //Write style for scr_base_btn_restore_cancel, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->scr_base_btn_restore_cancel, 193, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_base_btn_restore_cancel, lv_color_hex(0x1d1d1d), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_btn_restore_cancel, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->scr_base_btn_restore_cancel, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scr_base_btn_restore_cancel, 37, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scr_base_btn_restore_cancel, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scr_base_btn_restore_cancel, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_btn_restore_cancel, 12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_btn_restore_cancel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_base_btn_restore_cancel, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_btn_restore_cancel, &lv_font_Roboto_Black_15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_btn_restore_cancel, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_btn_restore_cancel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_cont_generate_report
    ui->scr_base_cont_generate_report = lv_obj_create(ui->scr_base);
    lv_obj_set_pos(ui->scr_base_cont_generate_report, 0, 0);
    lv_obj_set_size(ui->scr_base_cont_generate_report, 800, 480);
    lv_obj_set_scrollbar_mode(ui->scr_base_cont_generate_report, LV_SCROLLBAR_MODE_OFF);
    lv_obj_add_flag(ui->scr_base_cont_generate_report, LV_OBJ_FLAG_HIDDEN);

    //Write style for scr_base_cont_generate_report, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_cont_generate_report, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_cont_generate_report, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_cont_generate_report, 204, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_base_cont_generate_report, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_cont_generate_report, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_cont_generate_report, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_cont_generate_report, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_cont_generate_report, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_cont_generate_report, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_cont_generate_report, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_cont_74
    ui->scr_base_cont_74 = lv_obj_create(ui->scr_base_cont_generate_report);
    lv_obj_set_pos(ui->scr_base_cont_74, 203, 87);
    lv_obj_set_size(ui->scr_base_cont_74, 400, 300);
    lv_obj_set_scrollbar_mode(ui->scr_base_cont_74, LV_SCROLLBAR_MODE_OFF);

    //Write style for scr_base_cont_74, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_cont_74, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scr_base_cont_74, 48, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scr_base_cont_74, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scr_base_cont_74, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_cont_74, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_cont_74, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_base_cont_74, lv_color_hex(0x0F172A), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_cont_74, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_cont_74, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_cont_74, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_cont_74, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_cont_74, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_cont_74, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_img_28
    ui->scr_base_img_28 = lv_image_create(ui->scr_base_cont_74);
    lv_obj_set_pos(ui->scr_base_img_28, 150, 22);
    lv_obj_set_size(ui->scr_base_img_28, 100, 100);
    lv_obj_add_flag(ui->scr_base_img_28, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->scr_base_img_28, &_data_analysis_RGB565A8_100x100);
    lv_image_set_pivot(ui->scr_base_img_28, 50,50);
    lv_image_set_rotation(ui->scr_base_img_28, 0);

    //Write style for scr_base_img_28, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->scr_base_img_28, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->scr_base_img_28, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_label_216
    ui->scr_base_label_216 = lv_label_create(ui->scr_base_cont_74);
    lv_obj_set_pos(ui->scr_base_label_216, 0, 144);
    lv_obj_set_size(ui->scr_base_label_216, 400, 24);
    lv_label_set_text(ui->scr_base_label_216, "GENERATE REPORT?");
    lv_label_set_long_mode(ui->scr_base_label_216, LV_LABEL_LONG_WRAP);

    //Write style for scr_base_label_216, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_label_216, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_label_216, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_base_label_216, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_label_216, &lv_font_Roboto_Black_25, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_label_216, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_base_label_216, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_base_label_216, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_label_216, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_label_216, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_label_216, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_label_216, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_label_216, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_label_216, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_label_216, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_label_215
    ui->scr_base_label_215 = lv_label_create(ui->scr_base_cont_74);
    lv_obj_set_pos(ui->scr_base_label_215, 2, 180);
    lv_obj_set_size(ui->scr_base_label_215, 395, 51);
    lv_label_set_text(ui->scr_base_label_215, "This will compile system diagnostic insights and historical data logs. Make sure a USB drive is inserted before proceeding.");
    lv_label_set_long_mode(ui->scr_base_label_215, LV_LABEL_LONG_WRAP);

    //Write style for scr_base_label_215, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_label_215, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_label_215, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_base_label_215, lv_color_hex(0xABABAB), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_label_215, &lv_font_Roboto_Regular_14, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_label_215, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_base_label_215, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_base_label_215, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_label_215, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_label_215, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_label_215, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_label_215, 30, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_label_215, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_label_215, 30, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_label_215, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_btn_generate_report_confirm
    ui->scr_base_btn_generate_report_confirm = lv_button_create(ui->scr_base_cont_74);
    lv_obj_set_pos(ui->scr_base_btn_generate_report_confirm, 207, 243);
    lv_obj_set_size(ui->scr_base_btn_generate_report_confirm, 174, 38);
    ui->scr_base_btn_generate_report_confirm_label = lv_label_create(ui->scr_base_btn_generate_report_confirm);
    lv_label_set_text(ui->scr_base_btn_generate_report_confirm_label, "CONFIRM");
    lv_label_set_long_mode(ui->scr_base_btn_generate_report_confirm_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->scr_base_btn_generate_report_confirm_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->scr_base_btn_generate_report_confirm, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->scr_base_btn_generate_report_confirm_label, LV_PCT(100));

    //Write style for scr_base_btn_generate_report_confirm, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->scr_base_btn_generate_report_confirm, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_base_btn_generate_report_confirm, lv_color_hex(0x10B981), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_btn_generate_report_confirm, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->scr_base_btn_generate_report_confirm, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scr_base_btn_generate_report_confirm, 37, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scr_base_btn_generate_report_confirm, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scr_base_btn_generate_report_confirm, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_btn_generate_report_confirm, 12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_btn_generate_report_confirm, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_base_btn_generate_report_confirm, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_btn_generate_report_confirm, &lv_font_Roboto_Black_15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_btn_generate_report_confirm, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_btn_generate_report_confirm, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_btn_generate_report_cancel
    ui->scr_base_btn_generate_report_cancel = lv_button_create(ui->scr_base_cont_74);
    lv_obj_set_pos(ui->scr_base_btn_generate_report_cancel, 19, 243);
    lv_obj_set_size(ui->scr_base_btn_generate_report_cancel, 174, 38);
    ui->scr_base_btn_generate_report_cancel_label = lv_label_create(ui->scr_base_btn_generate_report_cancel);
    lv_label_set_text(ui->scr_base_btn_generate_report_cancel_label, "CANCEL");
    lv_label_set_long_mode(ui->scr_base_btn_generate_report_cancel_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->scr_base_btn_generate_report_cancel_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->scr_base_btn_generate_report_cancel, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->scr_base_btn_generate_report_cancel_label, LV_PCT(100));

    //Write style for scr_base_btn_generate_report_cancel, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->scr_base_btn_generate_report_cancel, 193, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_base_btn_generate_report_cancel, lv_color_hex(0x1d1d1d), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_btn_generate_report_cancel, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->scr_base_btn_generate_report_cancel, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scr_base_btn_generate_report_cancel, 37, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scr_base_btn_generate_report_cancel, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scr_base_btn_generate_report_cancel, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_btn_generate_report_cancel, 12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_btn_generate_report_cancel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_base_btn_generate_report_cancel, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_btn_generate_report_cancel, &lv_font_Roboto_Black_15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_btn_generate_report_cancel, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_btn_generate_report_cancel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_cont_login_settings
    ui->scr_base_cont_login_settings = lv_obj_create(ui->scr_base);
    lv_obj_set_pos(ui->scr_base_cont_login_settings, 0, 0);
    lv_obj_set_size(ui->scr_base_cont_login_settings, 800, 480);
    lv_obj_set_scrollbar_mode(ui->scr_base_cont_login_settings, LV_SCROLLBAR_MODE_OFF);
    lv_obj_add_flag(ui->scr_base_cont_login_settings, LV_OBJ_FLAG_HIDDEN);

    //Write style for scr_base_cont_login_settings, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_cont_login_settings, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_cont_login_settings, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_cont_login_settings, 204, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_base_cont_login_settings, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_cont_login_settings, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_cont_login_settings, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_cont_login_settings, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_cont_login_settings, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_cont_login_settings, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_cont_login_settings, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_cont_76
    ui->scr_base_cont_76 = lv_obj_create(ui->scr_base_cont_login_settings);
    lv_obj_set_pos(ui->scr_base_cont_76, 190, 65);
    lv_obj_set_size(ui->scr_base_cont_76, 420, 350);
    lv_obj_set_scrollbar_mode(ui->scr_base_cont_76, LV_SCROLLBAR_MODE_OFF);

    //Write style for scr_base_cont_76, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_cont_76, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scr_base_cont_76, 48, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scr_base_cont_76, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scr_base_cont_76, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_cont_76, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_cont_76, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_base_cont_76, lv_color_hex(0x0F172A), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_cont_76, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_cont_76, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_cont_76, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_cont_76, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_cont_76, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_cont_76, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_img_29
    ui->scr_base_img_29 = lv_image_create(ui->scr_base_cont_76);
    lv_obj_set_pos(ui->scr_base_img_29, 160, 22);
    lv_obj_set_size(ui->scr_base_img_29, 100, 100);
    lv_obj_add_flag(ui->scr_base_img_29, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->scr_base_img_29, &_configuration_RGB565A8_100x100);
    lv_image_set_pivot(ui->scr_base_img_29, 50,50);
    lv_image_set_rotation(ui->scr_base_img_29, 0);

    //Write style for scr_base_img_29, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->scr_base_img_29, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->scr_base_img_29, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_label_218
    ui->scr_base_label_218 = lv_label_create(ui->scr_base_cont_76);
    lv_obj_set_pos(ui->scr_base_label_218, 2, 137);
    lv_obj_set_size(ui->scr_base_label_218, 416, 28);
    lv_label_set_text(ui->scr_base_label_218, "ADMIN LOGIN");
    lv_label_set_long_mode(ui->scr_base_label_218, LV_LABEL_LONG_WRAP);

    //Write style for scr_base_label_218, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_label_218, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_label_218, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_base_label_218, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_label_218, &lv_font_Roboto_Black_25, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_label_218, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_base_label_218, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_base_label_218, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_label_218, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_label_218, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_label_218, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_label_218, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_label_218, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_label_218, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_label_218, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_lbl_status_login_setting
    ui->scr_base_lbl_status_login_setting = lv_label_create(ui->scr_base_cont_76);
    lv_obj_set_pos(ui->scr_base_lbl_status_login_setting, 5, 257);
    lv_obj_set_size(ui->scr_base_lbl_status_login_setting, 410, 18);
    lv_label_set_text(ui->scr_base_lbl_status_login_setting, "Enter password to access settings.");
    lv_label_set_long_mode(ui->scr_base_lbl_status_login_setting, LV_LABEL_LONG_WRAP);

    //Write style for scr_base_lbl_status_login_setting, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_lbl_status_login_setting, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_lbl_status_login_setting, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_base_lbl_status_login_setting, lv_color_hex(0xABABAB), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_lbl_status_login_setting, &lv_font_Roboto_Regular_14, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_lbl_status_login_setting, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_base_lbl_status_login_setting, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_base_lbl_status_login_setting, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_lbl_status_login_setting, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_lbl_status_login_setting, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_lbl_status_login_setting, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_lbl_status_login_setting, 30, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_lbl_status_login_setting, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_lbl_status_login_setting, 30, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_lbl_status_login_setting, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_btn_login_settings_confirm
    ui->scr_base_btn_login_settings_confirm = lv_button_create(ui->scr_base_cont_76);
    lv_obj_set_pos(ui->scr_base_btn_login_settings_confirm, 216, 285);
    lv_obj_set_size(ui->scr_base_btn_login_settings_confirm, 174, 38);
    ui->scr_base_btn_login_settings_confirm_label = lv_label_create(ui->scr_base_btn_login_settings_confirm);
    lv_label_set_text(ui->scr_base_btn_login_settings_confirm_label, "CONFIRM");
    lv_label_set_long_mode(ui->scr_base_btn_login_settings_confirm_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->scr_base_btn_login_settings_confirm_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->scr_base_btn_login_settings_confirm, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->scr_base_btn_login_settings_confirm_label, LV_PCT(100));

    //Write style for scr_base_btn_login_settings_confirm, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->scr_base_btn_login_settings_confirm, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_base_btn_login_settings_confirm, lv_color_hex(0x10B981), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_btn_login_settings_confirm, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->scr_base_btn_login_settings_confirm, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scr_base_btn_login_settings_confirm, 37, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scr_base_btn_login_settings_confirm, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scr_base_btn_login_settings_confirm, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_btn_login_settings_confirm, 12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_btn_login_settings_confirm, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_base_btn_login_settings_confirm, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_btn_login_settings_confirm, &lv_font_Roboto_Black_15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_btn_login_settings_confirm, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_btn_login_settings_confirm, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_btn_login_settings_cancel
    ui->scr_base_btn_login_settings_cancel = lv_button_create(ui->scr_base_cont_76);
    lv_obj_set_pos(ui->scr_base_btn_login_settings_cancel, 30, 285);
    lv_obj_set_size(ui->scr_base_btn_login_settings_cancel, 174, 38);
    ui->scr_base_btn_login_settings_cancel_label = lv_label_create(ui->scr_base_btn_login_settings_cancel);
    lv_label_set_text(ui->scr_base_btn_login_settings_cancel_label, "CANCEL");
    lv_label_set_long_mode(ui->scr_base_btn_login_settings_cancel_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->scr_base_btn_login_settings_cancel_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->scr_base_btn_login_settings_cancel, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->scr_base_btn_login_settings_cancel_label, LV_PCT(100));

    //Write style for scr_base_btn_login_settings_cancel, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->scr_base_btn_login_settings_cancel, 193, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_base_btn_login_settings_cancel, lv_color_hex(0x1d1d1d), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_btn_login_settings_cancel, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->scr_base_btn_login_settings_cancel, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scr_base_btn_login_settings_cancel, 37, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scr_base_btn_login_settings_cancel, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scr_base_btn_login_settings_cancel, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_btn_login_settings_cancel, 12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_btn_login_settings_cancel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_base_btn_login_settings_cancel, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_btn_login_settings_cancel, &lv_font_Roboto_Black_15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_btn_login_settings_cancel, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_btn_login_settings_cancel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_ta_login_settings_pass
    ui->scr_base_ta_login_settings_pass = lv_textarea_create(ui->scr_base_cont_76);
    lv_obj_set_pos(ui->scr_base_ta_login_settings_pass, 30, 188);
    lv_obj_set_size(ui->scr_base_ta_login_settings_pass, 360, 50);
    lv_textarea_set_text(ui->scr_base_ta_login_settings_pass, "");
    lv_textarea_set_placeholder_text(ui->scr_base_ta_login_settings_pass, "Enter password...");
    lv_textarea_set_password_bullet(ui->scr_base_ta_login_settings_pass, "*");
    lv_textarea_set_password_mode(ui->scr_base_ta_login_settings_pass, true);
    lv_textarea_set_one_line(ui->scr_base_ta_login_settings_pass, true);
    lv_textarea_set_accepted_chars(ui->scr_base_ta_login_settings_pass, "");
    lv_textarea_set_max_length(ui->scr_base_ta_login_settings_pass, 32);
#if LV_USE_KEYBOARD
    lv_obj_add_event_cb(ui->scr_base_ta_login_settings_pass, ta_event_cb, LV_EVENT_ALL, ui->g_kb_top_layer);
#endif

    //Write style for scr_base_ta_login_settings_pass, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->scr_base_ta_login_settings_pass, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_ta_login_settings_pass, &lv_font_Roboto_Regular_14, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_ta_login_settings_pass, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_base_ta_login_settings_pass, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_ta_login_settings_pass, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_ta_login_settings_pass, 130, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_base_ta_login_settings_pass, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_ta_login_settings_pass, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->scr_base_ta_login_settings_pass, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scr_base_ta_login_settings_pass, 58, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scr_base_ta_login_settings_pass, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scr_base_ta_login_settings_pass, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_ta_login_settings_pass, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_ta_login_settings_pass, 15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_ta_login_settings_pass, 12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_ta_login_settings_pass, 50, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_ta_login_settings_pass, 10, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for scr_base_ta_login_settings_pass, Part: LV_PART_MAIN, State: LV_STATE_FOCUSED.
    lv_obj_set_style_text_color(ui->scr_base_ta_login_settings_pass, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_font(ui->scr_base_ta_login_settings_pass, &lv_font_Roboto_Regular_14, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_opa(ui->scr_base_ta_login_settings_pass, 255, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_opa(ui->scr_base_ta_login_settings_pass, 130, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_color(ui->scr_base_ta_login_settings_pass, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_ta_login_settings_pass, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_width(ui->scr_base_ta_login_settings_pass, 1, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_opa(ui->scr_base_ta_login_settings_pass, 53, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_color(ui->scr_base_ta_login_settings_pass, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_side(ui->scr_base_ta_login_settings_pass, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_shadow_width(ui->scr_base_ta_login_settings_pass, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_pad_top(ui->scr_base_ta_login_settings_pass, 15, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_pad_right(ui->scr_base_ta_login_settings_pass, 12, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_pad_left(ui->scr_base_ta_login_settings_pass, 50, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_radius(ui->scr_base_ta_login_settings_pass, 10, LV_PART_MAIN|LV_STATE_FOCUSED);

    //Write style for scr_base_ta_login_settings_pass, Part: LV_PART_SCROLLBAR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->scr_base_ta_login_settings_pass, 255, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_base_ta_login_settings_pass, lv_color_hex(0x2195f6), LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_ta_login_settings_pass, LV_GRAD_DIR_NONE, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_ta_login_settings_pass, 0, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);

    //Write codes scr_base_img_33
    ui->scr_base_img_33 = lv_image_create(ui->scr_base_cont_76);
    lv_obj_set_pos(ui->scr_base_img_33, 42, 198);
    lv_obj_set_size(ui->scr_base_img_33, 24, 24);
    lv_obj_add_flag(ui->scr_base_img_33, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->scr_base_img_33, &_padlock_RGB565A8_24x24);
    lv_image_set_pivot(ui->scr_base_img_33, 50,50);
    lv_image_set_rotation(ui->scr_base_img_33, 0);

    //Write style for scr_base_img_33, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->scr_base_img_33, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_recolor(ui->scr_base_img_33, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->scr_base_img_33, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_cont_booting_login
    ui->scr_base_cont_booting_login = lv_obj_create(ui->scr_base);
    lv_obj_set_pos(ui->scr_base_cont_booting_login, 0, 0);
    lv_obj_set_size(ui->scr_base_cont_booting_login, 800, 480);
    lv_obj_set_scrollbar_mode(ui->scr_base_cont_booting_login, LV_SCROLLBAR_MODE_OFF);
    lv_obj_add_flag(ui->scr_base_cont_booting_login, LV_OBJ_FLAG_HIDDEN);

    //Write style for scr_base_cont_booting_login, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_cont_booting_login, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_cont_booting_login, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_cont_booting_login, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_base_cont_booting_login, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_cont_booting_login, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_cont_booting_login, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_cont_booting_login, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_cont_booting_login, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_cont_booting_login, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_cont_booting_login, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_cont_78
    ui->scr_base_cont_78 = lv_obj_create(ui->scr_base_cont_booting_login);
    lv_obj_set_pos(ui->scr_base_cont_78, 180, 50);
    lv_obj_set_size(ui->scr_base_cont_78, 440, 350);
    lv_obj_set_scrollbar_mode(ui->scr_base_cont_78, LV_SCROLLBAR_MODE_OFF);

    //Write style for scr_base_cont_78, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_cont_78, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scr_base_cont_78, 48, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scr_base_cont_78, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scr_base_cont_78, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_cont_78, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_cont_78, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_base_cont_78, lv_color_hex(0x0F172A), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_cont_78, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_cont_78, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_cont_78, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_cont_78, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_cont_78, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_cont_78, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_img_30
    ui->scr_base_img_30 = lv_image_create(ui->scr_base_cont_78);
    lv_obj_set_pos(ui->scr_base_img_30, 91, 17);
    lv_obj_set_size(ui->scr_base_img_30, 256, 65);
    lv_obj_add_flag(ui->scr_base_img_30, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->scr_base_img_30, &_text_synaptix_color_RGB565A8_256x65);
    lv_image_set_pivot(ui->scr_base_img_30, 50,50);
    lv_image_set_rotation(ui->scr_base_img_30, 0);

    //Write style for scr_base_img_30, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->scr_base_img_30, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->scr_base_img_30, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_label_220
    ui->scr_base_label_220 = lv_label_create(ui->scr_base_cont_78);
    lv_obj_set_pos(ui->scr_base_label_220, 2, 100);
    lv_obj_set_size(ui->scr_base_label_220, 434, 28);
    lv_label_set_text(ui->scr_base_label_220, "LOGIN SYSTEM");
    lv_label_set_long_mode(ui->scr_base_label_220, LV_LABEL_LONG_WRAP);

    //Write style for scr_base_label_220, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_label_220, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_label_220, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_base_label_220, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_label_220, &lv_font_Roboto_Black_25, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_label_220, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_base_label_220, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_base_label_220, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_label_220, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_label_220, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_label_220, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_label_220, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_label_220, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_label_220, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_label_220, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_label_login_booting_status
    ui->scr_base_label_login_booting_status = lv_label_create(ui->scr_base_cont_78);
    lv_obj_set_pos(ui->scr_base_label_login_booting_status, 14, 264);
    lv_obj_set_size(ui->scr_base_label_login_booting_status, 410, 18);
    lv_label_set_text(ui->scr_base_label_login_booting_status, "Enter password to access settings.");
    lv_label_set_long_mode(ui->scr_base_label_login_booting_status, LV_LABEL_LONG_WRAP);

    //Write style for scr_base_label_login_booting_status, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_base_label_login_booting_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_label_login_booting_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_base_label_login_booting_status, lv_color_hex(0xABABAB), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_label_login_booting_status, &lv_font_Roboto_Regular_14, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_label_login_booting_status, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_base_label_login_booting_status, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_base_label_login_booting_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_label_login_booting_status, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_label_login_booting_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_label_login_booting_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_label_login_booting_status, 30, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_base_label_login_booting_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_label_login_booting_status, 30, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_label_login_booting_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_btn_login_booting_confirm
    ui->scr_base_btn_login_booting_confirm = lv_button_create(ui->scr_base_cont_78);
    lv_obj_set_pos(ui->scr_base_btn_login_booting_confirm, 225, 294);
    lv_obj_set_size(ui->scr_base_btn_login_booting_confirm, 174, 38);
    ui->scr_base_btn_login_booting_confirm_label = lv_label_create(ui->scr_base_btn_login_booting_confirm);
    lv_label_set_text(ui->scr_base_btn_login_booting_confirm_label, "CONFIRM");
    lv_label_set_long_mode(ui->scr_base_btn_login_booting_confirm_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->scr_base_btn_login_booting_confirm_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->scr_base_btn_login_booting_confirm, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->scr_base_btn_login_booting_confirm_label, LV_PCT(100));

    //Write style for scr_base_btn_login_booting_confirm, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->scr_base_btn_login_booting_confirm, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_base_btn_login_booting_confirm, lv_color_hex(0x10B981), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_btn_login_booting_confirm, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->scr_base_btn_login_booting_confirm, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scr_base_btn_login_booting_confirm, 37, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scr_base_btn_login_booting_confirm, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scr_base_btn_login_booting_confirm, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_btn_login_booting_confirm, 12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_btn_login_booting_confirm, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_base_btn_login_booting_confirm, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_btn_login_booting_confirm, &lv_font_Roboto_Black_15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_btn_login_booting_confirm, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_btn_login_booting_confirm, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_btn_login_booting_cancel
    ui->scr_base_btn_login_booting_cancel = lv_button_create(ui->scr_base_cont_78);
    lv_obj_set_pos(ui->scr_base_btn_login_booting_cancel, 39, 294);
    lv_obj_set_size(ui->scr_base_btn_login_booting_cancel, 174, 38);
    ui->scr_base_btn_login_booting_cancel_label = lv_label_create(ui->scr_base_btn_login_booting_cancel);
    lv_label_set_text(ui->scr_base_btn_login_booting_cancel_label, "CANCEL");
    lv_label_set_long_mode(ui->scr_base_btn_login_booting_cancel_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->scr_base_btn_login_booting_cancel_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->scr_base_btn_login_booting_cancel, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->scr_base_btn_login_booting_cancel_label, LV_PCT(100));

    //Write style for scr_base_btn_login_booting_cancel, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->scr_base_btn_login_booting_cancel, 193, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_base_btn_login_booting_cancel, lv_color_hex(0x1d1d1d), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_btn_login_booting_cancel, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->scr_base_btn_login_booting_cancel, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scr_base_btn_login_booting_cancel, 37, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scr_base_btn_login_booting_cancel, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scr_base_btn_login_booting_cancel, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_btn_login_booting_cancel, 12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_btn_login_booting_cancel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_base_btn_login_booting_cancel, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_btn_login_booting_cancel, &lv_font_Roboto_Black_15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_btn_login_booting_cancel, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_btn_login_booting_cancel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_ta_login_booting_user
    ui->scr_base_ta_login_booting_user = lv_textarea_create(ui->scr_base_cont_78);
    lv_obj_set_pos(ui->scr_base_ta_login_booting_user, 39, 145);
    lv_obj_set_size(ui->scr_base_ta_login_booting_user, 360, 50);
    lv_textarea_set_text(ui->scr_base_ta_login_booting_user, "");
    lv_textarea_set_placeholder_text(ui->scr_base_ta_login_booting_user, "Enter username...");
    lv_textarea_set_password_bullet(ui->scr_base_ta_login_booting_user, "*");
    lv_textarea_set_password_mode(ui->scr_base_ta_login_booting_user, false);
    lv_textarea_set_one_line(ui->scr_base_ta_login_booting_user, true);
    lv_textarea_set_accepted_chars(ui->scr_base_ta_login_booting_user, "");
    lv_textarea_set_max_length(ui->scr_base_ta_login_booting_user, 32);
#if LV_USE_KEYBOARD
    lv_obj_add_event_cb(ui->scr_base_ta_login_booting_user, ta_event_cb, LV_EVENT_ALL, ui->g_kb_top_layer);
#endif

    //Write style for scr_base_ta_login_booting_user, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->scr_base_ta_login_booting_user, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_ta_login_booting_user, &lv_font_Roboto_Regular_14, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_ta_login_booting_user, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_base_ta_login_booting_user, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_ta_login_booting_user, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_ta_login_booting_user, 130, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_base_ta_login_booting_user, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_ta_login_booting_user, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->scr_base_ta_login_booting_user, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scr_base_ta_login_booting_user, 58, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scr_base_ta_login_booting_user, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scr_base_ta_login_booting_user, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_ta_login_booting_user, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_ta_login_booting_user, 15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_ta_login_booting_user, 12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_ta_login_booting_user, 50, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_ta_login_booting_user, 10, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for scr_base_ta_login_booting_user, Part: LV_PART_MAIN, State: LV_STATE_FOCUSED.
    lv_obj_set_style_text_color(ui->scr_base_ta_login_booting_user, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_font(ui->scr_base_ta_login_booting_user, &lv_font_Roboto_Regular_14, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_opa(ui->scr_base_ta_login_booting_user, 255, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_opa(ui->scr_base_ta_login_booting_user, 130, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_color(ui->scr_base_ta_login_booting_user, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_ta_login_booting_user, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_width(ui->scr_base_ta_login_booting_user, 1, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_opa(ui->scr_base_ta_login_booting_user, 53, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_color(ui->scr_base_ta_login_booting_user, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_side(ui->scr_base_ta_login_booting_user, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_shadow_width(ui->scr_base_ta_login_booting_user, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_pad_top(ui->scr_base_ta_login_booting_user, 15, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_pad_right(ui->scr_base_ta_login_booting_user, 12, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_pad_left(ui->scr_base_ta_login_booting_user, 50, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_radius(ui->scr_base_ta_login_booting_user, 10, LV_PART_MAIN|LV_STATE_FOCUSED);

    //Write style for scr_base_ta_login_booting_user, Part: LV_PART_SCROLLBAR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->scr_base_ta_login_booting_user, 255, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_base_ta_login_booting_user, lv_color_hex(0x2195f6), LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_ta_login_booting_user, LV_GRAD_DIR_NONE, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_ta_login_booting_user, 0, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);

    //Write codes scr_base_img_31
    ui->scr_base_img_31 = lv_image_create(ui->scr_base_cont_78);
    lv_obj_set_pos(ui->scr_base_img_31, 51, 156);
    lv_obj_set_size(ui->scr_base_img_31, 24, 24);
    lv_obj_add_flag(ui->scr_base_img_31, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->scr_base_img_31, &_user_RGB565A8_24x24);
    lv_image_set_pivot(ui->scr_base_img_31, 50,50);
    lv_image_set_rotation(ui->scr_base_img_31, 0);

    //Write style for scr_base_img_31, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->scr_base_img_31, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_recolor(ui->scr_base_img_31, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->scr_base_img_31, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_base_ta_login_booting_pass
    ui->scr_base_ta_login_booting_pass = lv_textarea_create(ui->scr_base_cont_78);
    lv_obj_set_pos(ui->scr_base_ta_login_booting_pass, 39, 203);
    lv_obj_set_size(ui->scr_base_ta_login_booting_pass, 360, 50);
    lv_textarea_set_text(ui->scr_base_ta_login_booting_pass, "");
    lv_textarea_set_placeholder_text(ui->scr_base_ta_login_booting_pass, "Enter password...");
    lv_textarea_set_password_bullet(ui->scr_base_ta_login_booting_pass, "*");
    lv_textarea_set_password_mode(ui->scr_base_ta_login_booting_pass, true);
    lv_textarea_set_one_line(ui->scr_base_ta_login_booting_pass, true);
    lv_textarea_set_accepted_chars(ui->scr_base_ta_login_booting_pass, "");
    lv_textarea_set_max_length(ui->scr_base_ta_login_booting_pass, 32);
#if LV_USE_KEYBOARD
    lv_obj_add_event_cb(ui->scr_base_ta_login_booting_pass, ta_event_cb, LV_EVENT_ALL, ui->g_kb_top_layer);
#endif

    //Write style for scr_base_ta_login_booting_pass, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->scr_base_ta_login_booting_pass, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_base_ta_login_booting_pass, &lv_font_Roboto_Regular_14, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_base_ta_login_booting_pass, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_base_ta_login_booting_pass, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_base_ta_login_booting_pass, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_base_ta_login_booting_pass, 130, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_base_ta_login_booting_pass, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_ta_login_booting_pass, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->scr_base_ta_login_booting_pass, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scr_base_ta_login_booting_pass, 58, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scr_base_ta_login_booting_pass, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scr_base_ta_login_booting_pass, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_base_ta_login_booting_pass, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_base_ta_login_booting_pass, 15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_base_ta_login_booting_pass, 12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_base_ta_login_booting_pass, 50, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_ta_login_booting_pass, 10, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for scr_base_ta_login_booting_pass, Part: LV_PART_MAIN, State: LV_STATE_FOCUSED.
    lv_obj_set_style_text_color(ui->scr_base_ta_login_booting_pass, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_font(ui->scr_base_ta_login_booting_pass, &lv_font_Roboto_Regular_14, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_opa(ui->scr_base_ta_login_booting_pass, 255, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_opa(ui->scr_base_ta_login_booting_pass, 130, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_color(ui->scr_base_ta_login_booting_pass, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_ta_login_booting_pass, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_width(ui->scr_base_ta_login_booting_pass, 1, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_opa(ui->scr_base_ta_login_booting_pass, 53, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_color(ui->scr_base_ta_login_booting_pass, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_side(ui->scr_base_ta_login_booting_pass, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_shadow_width(ui->scr_base_ta_login_booting_pass, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_pad_top(ui->scr_base_ta_login_booting_pass, 15, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_pad_right(ui->scr_base_ta_login_booting_pass, 12, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_pad_left(ui->scr_base_ta_login_booting_pass, 50, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_radius(ui->scr_base_ta_login_booting_pass, 10, LV_PART_MAIN|LV_STATE_FOCUSED);

    //Write style for scr_base_ta_login_booting_pass, Part: LV_PART_SCROLLBAR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->scr_base_ta_login_booting_pass, 255, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_base_ta_login_booting_pass, lv_color_hex(0x2195f6), LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_base_ta_login_booting_pass, LV_GRAD_DIR_NONE, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_base_ta_login_booting_pass, 0, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);

    //Write codes scr_base_img_32
    ui->scr_base_img_32 = lv_image_create(ui->scr_base_cont_78);
    lv_obj_set_pos(ui->scr_base_img_32, 51, 213);
    lv_obj_set_size(ui->scr_base_img_32, 24, 24);
    lv_obj_add_flag(ui->scr_base_img_32, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->scr_base_img_32, &_padlock_RGB565A8_24x24);
    lv_image_set_pivot(ui->scr_base_img_32, 50,50);
    lv_image_set_rotation(ui->scr_base_img_32, 0);

    //Write style for scr_base_img_32, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->scr_base_img_32, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_recolor(ui->scr_base_img_32, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->scr_base_img_32, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of scr_base.


    //Update current screen layout.
    lv_obj_update_layout(ui->scr_base);

}
