#include "ui_platform_port.h"

static ui_platform_state_loader_t s_state_loader = NULL;
static void *s_state_loader_ctx = NULL;
static ui_platform_json_handler_t s_json_handler = NULL;
static void *s_json_handler_ctx = NULL;

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

void ui_platform_port_set_json_handler(ui_platform_json_handler_t handler, void *user_ctx)
{
    s_json_handler = handler;
    s_json_handler_ctx = user_ctx;
}

bool ui_platform_port_submit_json(ui_platform_topic_t topic, const char *json_payload)
{
    if (!json_payload || !s_json_handler) return false;
    return s_json_handler(topic, json_payload, s_json_handler_ctx);
}
