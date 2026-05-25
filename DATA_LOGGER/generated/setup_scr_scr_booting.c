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



void setup_scr_scr_booting(lv_ui *ui)
{
    //Write codes scr_booting
    ui->scr_booting = lv_obj_create(NULL);
    lv_obj_set_size(ui->scr_booting, 800, 480);
    lv_obj_set_scrollbar_mode(ui->scr_booting, LV_SCROLLBAR_MODE_OFF);

    //Write style for scr_booting, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->scr_booting, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_booting, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_booting, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_booting_bar_1
    ui->scr_booting_bar_1 = lv_bar_create(ui->scr_booting);
    lv_obj_set_pos(ui->scr_booting_bar_1, 200, 400);
    lv_obj_set_size(ui->scr_booting_bar_1, 400, 5);
    lv_obj_set_style_anim_duration(ui->scr_booting_bar_1, 1500, 0);
    lv_bar_set_mode(ui->scr_booting_bar_1, LV_BAR_MODE_NORMAL);
    lv_bar_set_range(ui->scr_booting_bar_1, 0, 100);
    lv_bar_set_value(ui->scr_booting_bar_1, 100, LV_ANIM_ON);

    //Write style for scr_booting_bar_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->scr_booting_bar_1, 76, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_booting_bar_1, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_booting_bar_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_booting_bar_1, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_booting_bar_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for scr_booting_bar_1, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->scr_booting_bar_1, 188, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr_booting_bar_1, lv_color_hex(0xffffff), LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr_booting_bar_1, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_booting_bar_1, 10, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write codes scr_booting_label_1
    ui->scr_booting_label_1 = lv_label_create(ui->scr_booting);
    lv_obj_set_pos(ui->scr_booting_label_1, 302, 370);
    lv_obj_set_size(ui->scr_booting_label_1, 196, 17);
    lv_label_set_text(ui->scr_booting_label_1, "Starting system...");
    lv_label_set_long_mode(ui->scr_booting_label_1, LV_LABEL_LONG_WRAP);

    //Write style for scr_booting_label_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr_booting_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr_booting_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr_booting_label_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr_booting_label_1, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr_booting_label_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr_booting_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr_booting_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr_booting_label_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr_booting_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr_booting_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr_booting_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr_booting_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr_booting_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr_booting_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr_booting_img_1
    ui->scr_booting_img_1 = lv_image_create(ui->scr_booting);
    lv_obj_set_pos(ui->scr_booting_img_1, 272, 174);
    lv_obj_set_size(ui->scr_booting_img_1, 256, 65);
    lv_obj_add_flag(ui->scr_booting_img_1, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->scr_booting_img_1, &_text_synaptix_color_RGB565A8_256x65);
    lv_image_set_pivot(ui->scr_booting_img_1, 50,50);
    lv_image_set_rotation(ui->scr_booting_img_1, 0);

    //Write style for scr_booting_img_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->scr_booting_img_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->scr_booting_img_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of scr_booting.


    //Update current screen layout.
    lv_obj_update_layout(ui->scr_booting);

    //Init events for screen.
    events_init_scr_booting(ui);
}
