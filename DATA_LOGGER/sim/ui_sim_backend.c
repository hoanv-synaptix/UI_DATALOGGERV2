#include "ui_sim_backend.h"

#include <stdio.h>
#include <string.h>
#include "ui_frontend_api.h"
#include "ui_platform_port.h"
#include "ui_register_map.h"

typedef struct {
    ui_ip_mode_t wifi_mode;
    char wifi_ssid[64];
    char wifi_password[64];
    char wifi_static_ip[32];
    bool wifi_connected;
} ui_sim_backend_state_t;

static ui_sim_backend_state_t s_backend;

static void copy_string(char *dst, size_t dst_size, const char *src)
{
    if (!dst || dst_size == 0U) return;
    dst[0] = '\0';
    if (!src) return;

    strncpy(dst, src, dst_size - 1U);
    dst[dst_size - 1U] = '\0';
}

static const char *wifi_live_ip(void)
{
    if (s_backend.wifi_mode == UI_IP_MODE_STATIC && s_backend.wifi_static_ip[0]) {
        return s_backend.wifi_static_ip;
    }
    return "192.168.1.20";
}

static void post_wifi_live_update(void)
{
    ui_register_update_t updates[2];

    memset(updates, 0, sizeof(updates));

    s_backend.wifi_connected = true;

    updates[0].address = REG_LIVE_WIFI_STATUS;
    updates[0].type = UI_REGISTER_TYPE_UINT8;
    updates[0].value.u8 = s_backend.wifi_connected ? 2U : 0U;

    updates[1].address = REG_LIVE_WIFI_IP;
    updates[1].type = UI_REGISTER_TYPE_STRING;
    copy_string(updates[1].value.string, sizeof(updates[1].value.string), wifi_live_ip());

    (void)ui_frontend_post_register_batch(updates, 2U);
}

static bool sim_load_initial_state(ui_runtime_state_t *state, void *user_ctx)
{
    (void)user_ctx;

    if (!state) return false;
    state->live.wifi_connected = s_backend.wifi_connected;
    state->live.wifi_status = s_backend.wifi_connected ? UI_CONNECTION_STATUS_CONNECTED : UI_CONNECTION_STATUS_DISCONNECTED;
    copy_string(state->live.wifi_live_ip, sizeof(state->live.wifi_live_ip),
                s_backend.wifi_connected ? wifi_live_ip() : "");
    return true;
}

static bool sim_handle_command(const ui_platform_command_t *cmd, void *user_ctx)
{
    (void)user_ctx;

    if (!cmd) return false;

    switch (cmd->id) {
    case UI_PLATFORM_CMD_GENERATE_REPORT:
        printf("[sim-backend] command: generate report\n");
        return true;
    case UI_PLATFORM_CMD_REQUEST_RESTART:
        printf("[sim-backend] command: restart requested\n");
        return true;
    case UI_PLATFORM_CMD_REQUEST_FACTORY_RESET:
        printf("[sim-backend] command: factory reset requested\n");
        return true;
    default:
        printf("[sim-backend] command fallback id=%d\n", (int)cmd->id);
        return true;
    }
}

static bool sim_apply_register_write(const ui_register_write_t *write)
{
    if (!write) return false;

    switch (write->address) {
    case REG_WIFI_MODE:
        if (write->type != UI_REGISTER_TYPE_UINT8) return false;
        s_backend.wifi_mode = write->value.u8 == 1U ? UI_IP_MODE_STATIC : UI_IP_MODE_DHCP;
        printf("[sim-backend] write REG_WIFI_MODE=%u\n", (unsigned)write->value.u8);
        return true;
    case REG_WIFI_SSID:
        if (write->type != UI_REGISTER_TYPE_STRING) return false;
        copy_string(s_backend.wifi_ssid, sizeof(s_backend.wifi_ssid), write->value.string);
        printf("[sim-backend] write REG_WIFI_SSID=\"%s\"\n", s_backend.wifi_ssid);
        return true;
    case REG_WIFI_PASSWORD:
        if (write->type != UI_REGISTER_TYPE_STRING) return false;
        copy_string(s_backend.wifi_password, sizeof(s_backend.wifi_password), write->value.string);
        printf("[sim-backend] write REG_WIFI_PASSWORD=<hidden>\n");
        return true;
    case REG_WIFI_STATIC_IP:
        if (write->type != UI_REGISTER_TYPE_STRING) return false;
        copy_string(s_backend.wifi_static_ip, sizeof(s_backend.wifi_static_ip), write->value.string);
        printf("[sim-backend] write REG_WIFI_STATIC_IP=\"%s\"\n", s_backend.wifi_static_ip);
        return true;
    default:
        printf("[sim-backend] unsupported register write 0x%04X\n", (unsigned)write->address);
        return false;
    }
}

static bool sim_write_registers(const ui_register_write_t *writes, size_t count, void *user_ctx)
{
    size_t i;
    bool ok = true;

    (void)user_ctx;

    if (!writes || count == 0U) return false;

    for (i = 0; i < count; ++i) {
        if (!sim_apply_register_write(&writes[i])) {
            ok = false;
        }
    }

    if (ok) {
        post_wifi_live_update();
    }

    return ok;
}

void ui_sim_backend_init(void)
{
    memset(&s_backend, 0, sizeof(s_backend));
    s_backend.wifi_mode = UI_IP_MODE_DHCP;

    ui_platform_port_set_state_loader(sim_load_initial_state, NULL);
    ui_platform_port_set_command_handler(sim_handle_command, NULL);
    ui_platform_port_set_register_writer(sim_write_registers, NULL);
    (void)ui_frontend_post_backend_status(UI_BACKEND_STATUS_ONLINE);
}
