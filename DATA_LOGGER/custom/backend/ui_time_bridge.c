/**
 * @file ui_time_bridge.c
 * @brief RTC → UI bridge for time & date labels.
 *
 * Strategy: The generated code owns a 1 s lv_timer (scr_base_time_val_timer)
 * that increments three extern int globals and writes the time label.
 * Instead of fighting that timer, we simply overwrite those globals with the
 * real RTC values every second.  The generated timer's next tick then
 * increments by one second and displays — the ±1 s offset is imperceptible.
 *
 * For the date label there is no generated timer, so we write it directly.
 *
 * This avoids any need for LVGL private headers, internal timer-list walks,
 * or modifications to generated code.
 */
#include "ui_time_bridge.h"
#include "ui_time_service.h"
#include "gui_guider.h"
#include "lvgl.h"
#include <stdio.h>

/* ---------------------------------------------------------------------------
 * Generated clock globals (defined in setup_scr_scr_base.c,
 * incremented by the generated scr_base_time_val_timer every 1 s).
 * We overwrite them with the real RTC time each second.
 * --------------------------------------------------------------------------- */
extern int scr_base_time_val_hour_value;
extern int scr_base_time_val_min_value;
extern int scr_base_time_val_sec_value;

static lv_timer_t *s_time_timer = NULL;

/* ---------------------------------------------------------------------------
 * Timer callback — runs every 1 000 ms
 * --------------------------------------------------------------------------- */
static void time_timer_cb(lv_timer_t *timer)
{
    (void)timer;

    ui_time_t now;
    if (!ui_time_service_get(&now)) return;   /* RTC not valid yet → skip */

    /* 1. Feed real time into the generated clock counters.
     *    The generated timer will add +1 s on its next tick — good enough. */
    scr_base_time_val_hour_value = (int)now.hour;
    scr_base_time_val_min_value  = (int)now.minute;
    scr_base_time_val_sec_value  = (int)now.second;

    /* 2. Update the date label directly (no generated timer for it). */
    lv_ui *ui = &guider_ui;
    if (ui->scr_base_date_val && lv_obj_is_valid(ui->scr_base_date_val)) {
        lv_label_set_text_fmt(ui->scr_base_date_val,
                              "%04d/%02d/%02d",
                              now.year, now.month, now.day);
    }
}

/* ---------------------------------------------------------------------------
 * Public API
 * --------------------------------------------------------------------------- */
void ui_time_bridge_start(void)
{
    if (s_time_timer) return;
    s_time_timer = lv_timer_create(time_timer_cb, 1000, NULL);
}

void ui_time_bridge_stop(void)
{
    if (s_time_timer) {
        lv_timer_del(s_time_timer);
        s_time_timer = NULL;
    }
}
