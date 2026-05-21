#include "custom.h"
#include "ui_runtime_guard.h"
#include "ui_screen_controller.h"

static void custom_runtime_rebind(lv_ui *ui)
{
    if (!ui) return;
    ui_screen_controller_enter(ui);
    ui_runtime_guard_mark_bound(ui->scr_base);
}

void custom_init(lv_ui *ui)
{
    ui_runtime_guard_init(ui, custom_runtime_rebind);
    custom_runtime_rebind(ui);
}

void custom_input_reset(void)
{
    ui_screen_controller_restore_input();
}
