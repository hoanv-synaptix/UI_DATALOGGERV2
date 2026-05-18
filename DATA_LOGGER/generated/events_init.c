/*
* Copyright 2026 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#include "events_init.h"
#include <stdio.h>
#include "lvgl.h"

#if LV_USE_GUIDER_SIMULATOR && LV_USE_FREEMASTER
#include "freemaster_client.h"
#endif


static void scr_booting_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_SCREEN_LOADED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.scr_dashboard, guider_ui.scr_dashboard_del, &guider_ui.scr_booting_del, setup_scr_scr_dashboard, LV_SCR_LOAD_ANIM_NONE, 200, 1600, false, true);
        break;
    }
    default:
        break;
    }
}

void events_init_scr_booting (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->scr_booting, scr_booting_event_handler, LV_EVENT_ALL, ui);
}

static void scr_dashboard_btn_4_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.scr_analysis, guider_ui.scr_analysis_del, &guider_ui.scr_dashboard_del, setup_scr_scr_analysis, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
        break;
    }
    default:
        break;
    }
}

static void scr_dashboard_btn_5_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.scr_logs, guider_ui.scr_logs_del, &guider_ui.scr_dashboard_del, setup_scr_scr_logs, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
        break;
    }
    default:
        break;
    }
}

static void scr_dashboard_btn_6_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.scr_hw, guider_ui.scr_hw_del, &guider_ui.scr_dashboard_del, setup_scr_scr_hw, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
        break;
    }
    default:
        break;
    }
}

void events_init_scr_dashboard (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->scr_dashboard_btn_4, scr_dashboard_btn_4_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->scr_dashboard_btn_5, scr_dashboard_btn_5_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->scr_dashboard_btn_6, scr_dashboard_btn_6_event_handler, LV_EVENT_ALL, ui);
}

static void scr_analysis_btn_5_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.scr_dashboard, guider_ui.scr_dashboard_del, &guider_ui.scr_analysis_del, setup_scr_scr_dashboard, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
        break;
    }
    default:
        break;
    }
}

static void scr_analysis_btn_3_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.scr_logs, guider_ui.scr_logs_del, &guider_ui.scr_analysis_del, setup_scr_scr_logs, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
        break;
    }
    default:
        break;
    }
}

static void scr_analysis_btn_2_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.scr_hw, guider_ui.scr_hw_del, &guider_ui.scr_analysis_del, setup_scr_scr_hw, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
        break;
    }
    default:
        break;
    }
}

void events_init_scr_analysis (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->scr_analysis_btn_5, scr_analysis_btn_5_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->scr_analysis_btn_3, scr_analysis_btn_3_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->scr_analysis_btn_2, scr_analysis_btn_2_event_handler, LV_EVENT_ALL, ui);
}

static void scr_logs_btn_5_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.scr_dashboard, guider_ui.scr_dashboard_del, &guider_ui.scr_logs_del, setup_scr_scr_dashboard, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
        break;
    }
    default:
        break;
    }
}

static void scr_logs_btn_4_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.scr_analysis, guider_ui.scr_analysis_del, &guider_ui.scr_logs_del, setup_scr_scr_analysis, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
        break;
    }
    default:
        break;
    }
}

static void scr_logs_btn_2_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.scr_hw, guider_ui.scr_hw_del, &guider_ui.scr_logs_del, setup_scr_scr_hw, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
        break;
    }
    default:
        break;
    }
}

void events_init_scr_logs (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->scr_logs_btn_5, scr_logs_btn_5_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->scr_logs_btn_4, scr_logs_btn_4_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->scr_logs_btn_2, scr_logs_btn_2_event_handler, LV_EVENT_ALL, ui);
}

static void scr_hw_btn_5_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.scr_dashboard, guider_ui.scr_dashboard_del, &guider_ui.scr_hw_del, setup_scr_scr_dashboard, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
        break;
    }
    default:
        break;
    }
}

static void scr_hw_btn_4_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.scr_analysis, guider_ui.scr_analysis_del, &guider_ui.scr_hw_del, setup_scr_scr_analysis, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
        break;
    }
    default:
        break;
    }
}

static void scr_hw_btn_3_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.scr_logs, guider_ui.scr_logs_del, &guider_ui.scr_hw_del, setup_scr_scr_logs, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
        break;
    }
    default:
        break;
    }
}

static void scr_hw_btn_6_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.scr_wifi, guider_ui.scr_wifi_del, &guider_ui.scr_hw_del, setup_scr_scr_wifi, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
        break;
    }
    default:
        break;
    }
}

void events_init_scr_hw (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->scr_hw_btn_5, scr_hw_btn_5_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->scr_hw_btn_4, scr_hw_btn_4_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->scr_hw_btn_3, scr_hw_btn_3_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->scr_hw_btn_6, scr_hw_btn_6_event_handler, LV_EVENT_ALL, ui);
}

static void scr_wifi_ddlist_2_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_VALUE_CHANGED:
    {
        uint32_t id = lv_dropdown_get_selected(guider_ui.scr_wifi_ddlist_2);
        lv_obj_set_style_bg_opa(guider_ui.scr_wifi_ta_3, 255, LV_PART_MAIN);
        break;
    }
    default:
        break;
    }
}

void events_init_scr_wifi (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->scr_wifi_ddlist_2, scr_wifi_ddlist_2_event_handler, LV_EVENT_ALL, ui);
}


void events_init(lv_ui *ui)
{

}
