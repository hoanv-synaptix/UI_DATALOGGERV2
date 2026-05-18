/*
* Copyright 2026 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#ifndef WIDGET_INIT_H
#define WIDGET_INIT_H
#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl.h"
#include "gui_guider.h"

__attribute__((unused)) void kb_event_cb(lv_event_t *e);
__attribute__((unused)) void ta_event_cb(lv_event_t *e);
#if LV_USE_ANALOGCLOCK != 0
void clock_count(int *hour, int *min, int *sec);
void digital_clock_count(int * hour, int * minute, int * seconds, char * meridiem);
#endif


void scr_dashboard_datetext_1_event_handler(lv_event_t *e);
void scr_dashboard_datetext_1_calendar_event_handler(lv_event_t *e);
void scr_dashboard_datetext_1_init_calendar(lv_obj_t *obj, char * s);
void scr_dashboard_digital_clock_1_timer(lv_timer_t *timer);
void scr_analysis_datetext_1_event_handler(lv_event_t *e);
void scr_analysis_datetext_1_calendar_event_handler(lv_event_t *e);
void scr_analysis_datetext_1_init_calendar(lv_obj_t *obj, char * s);
void scr_analysis_digital_clock_1_timer(lv_timer_t *timer);
void scr_logs_datetext_1_event_handler(lv_event_t *e);
void scr_logs_datetext_1_calendar_event_handler(lv_event_t *e);
void scr_logs_datetext_1_init_calendar(lv_obj_t *obj, char * s);
void scr_logs_digital_clock_1_timer(lv_timer_t *timer);
void scr_hw_datetext_1_event_handler(lv_event_t *e);
void scr_hw_datetext_1_calendar_event_handler(lv_event_t *e);
void scr_hw_datetext_1_init_calendar(lv_obj_t *obj, char * s);
void scr_hw_digital_clock_1_timer(lv_timer_t *timer);
void scr_wifi_datetext_1_event_handler(lv_event_t *e);
void scr_wifi_datetext_1_calendar_event_handler(lv_event_t *e);
void scr_wifi_datetext_1_init_calendar(lv_obj_t *obj, char * s);
void scr_wifi_digital_clock_1_timer(lv_timer_t *timer);
void screen_4_datetext_1_event_handler(lv_event_t *e);
void screen_4_datetext_1_calendar_event_handler(lv_event_t *e);
void screen_4_datetext_1_init_calendar(lv_obj_t *obj, char * s);
void screen_4_digital_clock_1_timer(lv_timer_t *timer);
void screen_5_datetext_1_event_handler(lv_event_t *e);
void screen_5_datetext_1_calendar_event_handler(lv_event_t *e);
void screen_5_datetext_1_init_calendar(lv_obj_t *obj, char * s);
void screen_5_digital_clock_1_timer(lv_timer_t *timer);
void screen_6_datetext_1_event_handler(lv_event_t *e);
void screen_6_datetext_1_calendar_event_handler(lv_event_t *e);
void screen_6_datetext_1_init_calendar(lv_obj_t *obj, char * s);
void screen_6_digital_clock_1_timer(lv_timer_t *timer);


#ifdef __cplusplus
}
#endif
#endif
