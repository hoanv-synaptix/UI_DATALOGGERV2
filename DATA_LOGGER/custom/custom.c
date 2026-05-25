#include "custom.h"
#include "ui_platform_port.h"
#include "ui_screen_controller.h"
#include "ui_sim_backend.h"

void custom_init(void *generated_ui)
{
    ui_context_t *ui = ui_context_get();

    (void)generated_ui;
    if (!ui) return;
    ui_platform_port_init();
    ui_sim_backend_init();
    ui_screen_controller_enter(ui);
}

void custom_input_reset(void)
{
    ui_screen_controller_restore_input();
}
