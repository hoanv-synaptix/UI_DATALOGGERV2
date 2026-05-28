#include "ui_runtime_guard.h"

static view_factory_t *s_ui = NULL;
static lv_obj_t *s_bound_scr_base = NULL;
static lv_timer_t *s_watchdog_timer = NULL;
static ui_runtime_rebind_cb_t s_rebind_cb = NULL;

static void watchdog_cb(lv_timer_t *t)
{
    lv_obj_t *base_screen;

    (void)t;
    if (!s_ui || !s_rebind_cb) return;
    base_screen = view_factory_get_base_screen(s_ui);
    if (!base_screen || !lv_obj_is_valid(base_screen)) return;
    if (s_bound_scr_base != base_screen) s_rebind_cb(s_ui);
}

void ui_runtime_guard_init(view_factory_t *ui, ui_runtime_rebind_cb_t rebind_cb)
{
    s_ui = ui;
    s_rebind_cb = rebind_cb;
    if (!s_watchdog_timer) s_watchdog_timer = lv_timer_create(watchdog_cb, 100U, NULL);
}

void ui_runtime_guard_mark_bound(lv_obj_t *scr_base)
{
    s_bound_scr_base = scr_base;
}

bool ui_runtime_guard_should_rebind(void)
{
    lv_obj_t *base_screen;

    if (!s_ui) return false;

    base_screen = view_factory_get_base_screen(s_ui);
    if (!base_screen) return false;
    if (!lv_obj_is_valid(base_screen)) return false;
    return s_bound_scr_base != base_screen;
}

view_factory_t *ui_runtime_guard_get_ui(void)
{
    return s_ui;
}
