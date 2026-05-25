#include <assert.h>
#include <stdio.h>
#include <string.h>

#include "ui_register_adapter.h"
#include "ui_register_map.h"

static void test_wifi_command_maps_to_four_register_writes(void)
{
    ui_platform_command_t cmd;
    ui_register_write_t writes[4];
    size_t count = 0U;

    memset(&cmd, 0, sizeof(cmd));
    memset(writes, 0, sizeof(writes));

    cmd.id = UI_PLATFORM_CMD_SAVE_WIFI_CONFIG;
    cmd.data.wifi.ip_mode = UI_IP_MODE_STATIC;
    strcpy(cmd.data.wifi.ssid, "FactoryNet");
    strcpy(cmd.data.wifi.password, "secret123");
    strcpy(cmd.data.wifi.ip, "192.168.10.42");

    assert(ui_register_adapter_command_to_writes(&cmd, writes, 4U, &count));
    assert(count == 4U);

    assert(writes[0].address == REG_WIFI_MODE);
    assert(writes[0].type == UI_REGISTER_TYPE_UINT8);
    assert(writes[0].value.u8 == 1U);

    assert(writes[1].address == REG_WIFI_SSID);
    assert(writes[1].type == UI_REGISTER_TYPE_STRING);
    assert(strcmp(writes[1].value.string, "FactoryNet") == 0);

    assert(writes[2].address == REG_WIFI_PASSWORD);
    assert(writes[2].type == UI_REGISTER_TYPE_STRING);
    assert(strcmp(writes[2].value.string, "secret123") == 0);

    assert(writes[3].address == REG_WIFI_STATIC_IP);
    assert(writes[3].type == UI_REGISTER_TYPE_STRING);
    assert(strcmp(writes[3].value.string, "192.168.10.42") == 0);
}

static void test_live_wifi_updates_apply_to_runtime_state(void)
{
    ui_runtime_state_t state;
    ui_register_update_t update;

    memset(&state, 0, sizeof(state));
    memset(&update, 0, sizeof(update));

    update.address = REG_LIVE_WIFI_STATUS;
    update.type = UI_REGISTER_TYPE_UINT8;
    update.value.u8 = 1U;
    assert(ui_register_adapter_apply_update(&state, &update));
    assert(state.live.wifi_status == UI_CONNECTION_STATUS_CONNECTING);
    assert(!state.live.wifi_connected);

    update.value.u8 = 2U;
    assert(ui_register_adapter_apply_update(&state, &update));
    assert(state.live.wifi_status == UI_CONNECTION_STATUS_CONNECTED);
    assert(state.live.wifi_connected);

    memset(&update, 0, sizeof(update));
    update.address = REG_LIVE_WIFI_IP;
    update.type = UI_REGISTER_TYPE_STRING;
    strcpy(update.value.string, "192.168.1.20");
    assert(ui_register_adapter_apply_update(&state, &update));
    assert(strcmp(state.live.wifi_live_ip, "192.168.1.20") == 0);
}

int main(void)
{
    test_wifi_command_maps_to_four_register_writes();
    test_live_wifi_updates_apply_to_runtime_state();
    puts("ui register adapter check passed");
    return 0;
}
