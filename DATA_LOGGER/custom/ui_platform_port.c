#include "ui_platform_port.h"

static ui_platform_state_loader_t s_state_loader = NULL;
static void *s_state_loader_ctx = NULL;
static ui_platform_command_handler_t s_command_handler = NULL;
static void *s_command_handler_ctx = NULL;
static ui_platform_register_writer_t s_register_writer = NULL;
static void *s_register_writer_ctx = NULL;

void ui_platform_port_init(void)
{
    /*
     * Phase A keeps this seam intentionally empty.
     * Later platform-specific hooks such as diagnostics, timing,
     * or board integrations should land here instead of UI core files.
     */
}

void ui_platform_port_set_state_loader(ui_platform_state_loader_t loader, void *user_ctx)
{
    s_state_loader = loader;
    s_state_loader_ctx = user_ctx;
}

bool ui_platform_port_load_initial_state(ui_runtime_state_t *state)
{
    if (!state || !s_state_loader) return false;
    return s_state_loader(state, s_state_loader_ctx);
}

void ui_platform_port_set_command_handler(ui_platform_command_handler_t handler, void *user_ctx)
{
    s_command_handler = handler;
    s_command_handler_ctx = user_ctx;
}

bool ui_platform_port_submit_command(const ui_platform_command_t *cmd)
{
    if (!cmd || !s_command_handler) return false;
    return s_command_handler(cmd, s_command_handler_ctx);
}

void ui_platform_port_set_register_writer(ui_platform_register_writer_t writer, void *user_ctx)
{
    s_register_writer = writer;
    s_register_writer_ctx = user_ctx;
}

bool ui_platform_port_submit_register_writes(const ui_register_write_t *writes, size_t count)
{
    if (!writes || count == 0U || !s_register_writer) return false;
    return s_register_writer(writes, count, s_register_writer_ctx);
}
