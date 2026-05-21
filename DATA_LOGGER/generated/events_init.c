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
        ui_load_scr_animation(&guider_ui, &guider_ui.scr_base, guider_ui.scr_base_del, &guider_ui.scr_booting_del, setup_scr_scr_base, LV_SCR_LOAD_ANIM_NONE, 200, 1600, false, true);
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


void events_init(lv_ui *ui)
{

}
