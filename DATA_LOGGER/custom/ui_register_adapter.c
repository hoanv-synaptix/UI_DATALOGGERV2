#include "ui_register_adapter.h"

#include <string.h>
#include "ui_register_map.h"

static bool validate_write_target(uint16_t address, ui_register_type_t type)
{
    const ui_register_desc_t *desc = ui_register_map_find(address);

    if (!desc) return false;
    if (desc->type != type) return false;
    return desc->access == UI_REGISTER_ACCESS_UI_WRITE || desc->access == UI_REGISTER_ACCESS_RW;
}

static bool validate_update_source(uint16_t address, ui_register_type_t type)
{
    const ui_register_desc_t *desc = ui_register_map_find(address);

    if (!desc) return false;
    if (desc->type != type) return false;
    return desc->access == UI_REGISTER_ACCESS_BACKEND_WRITE || desc->access == UI_REGISTER_ACCESS_RW;
}

static bool append_u8(ui_register_write_t *writes, size_t capacity, size_t *count,
                      uint16_t address, uint8_t value)
{
    ui_register_write_t *item;

    if (!writes || !count || *count >= capacity) return false;
    if (!validate_write_target(address, UI_REGISTER_TYPE_UINT8)) return false;

    item = &writes[*count];
    memset(item, 0, sizeof(*item));
    item->address = address;
    item->type = UI_REGISTER_TYPE_UINT8;
    item->value.u8 = value;
    (*count)++;
    return true;
}

static bool append_string(ui_register_write_t *writes, size_t capacity, size_t *count,
                          uint16_t address, const char *value)
{
    const ui_register_desc_t *desc = ui_register_map_find(address);
    ui_register_write_t *item;
    size_t copy_len;

    if (!writes || !count || *count >= capacity) return false;
    if (!desc || !validate_write_target(address, UI_REGISTER_TYPE_STRING)) return false;

    item = &writes[*count];
    memset(item, 0, sizeof(*item));
    item->address = address;
    item->type = UI_REGISTER_TYPE_STRING;
    if (value) {
        copy_len = desc->max_len;
        if (copy_len >= sizeof(item->value.string)) copy_len = sizeof(item->value.string) - 1U;
        strncpy(item->value.string, value, copy_len);
        item->value.string[copy_len] = '\0';
    }
    (*count)++;
    return true;
}

static uint8_t ip_mode_to_register(ui_ip_mode_t mode)
{
    return (mode == UI_IP_MODE_STATIC) ? 1U : 0U;
}

static ui_connection_status_t status_from_register(uint8_t value)
{
    switch (value) {
    case 1U:
        return UI_CONNECTION_STATUS_CONNECTING;
    case 2U:
        return UI_CONNECTION_STATUS_CONNECTED;
    case 3U:
        return UI_CONNECTION_STATUS_ERROR;
    case 0U:
    default:
        return UI_CONNECTION_STATUS_DISCONNECTED;
    }
}

bool ui_register_adapter_command_to_writes(const ui_platform_command_t *cmd,
                                           ui_register_write_t *writes,
                                           size_t capacity,
                                           size_t *out_count)
{
    size_t count = 0U;

    if (!cmd || !writes || !out_count) return false;
    *out_count = 0U;

    switch (cmd->id) {
    case UI_PLATFORM_CMD_SAVE_WIFI_CONFIG:
        if (!append_u8(writes, capacity, &count, REG_WIFI_MODE, ip_mode_to_register(cmd->data.wifi.ip_mode))) return false;
        if (!append_string(writes, capacity, &count, REG_WIFI_SSID, cmd->data.wifi.ssid)) return false;
        if (!append_string(writes, capacity, &count, REG_WIFI_PASSWORD, cmd->data.wifi.password)) return false;
        if (!append_string(writes, capacity, &count, REG_WIFI_STATIC_IP, cmd->data.wifi.ip)) return false;
        *out_count = count;
        return true;
    default:
        return false;
    }
}

bool ui_register_adapter_apply_update(ui_runtime_state_t *state,
                                      const ui_register_update_t *update)
{
    if (!state || !update) return false;

    switch (update->address) {
    case REG_LIVE_WIFI_STATUS:
        if (!validate_update_source(update->address, update->type)) return false;
        state->live.wifi_status = status_from_register(update->value.u8);
        state->live.wifi_connected = state->live.wifi_status == UI_CONNECTION_STATUS_CONNECTED;
        return true;
    case REG_LIVE_WIFI_IP:
        if (!validate_update_source(update->address, update->type)) return false;
        strncpy(state->live.wifi_live_ip, update->value.string, sizeof(state->live.wifi_live_ip) - 1U);
        state->live.wifi_live_ip[sizeof(state->live.wifi_live_ip) - 1U] = '\0';
        return true;
    case REG_DASH_TEMP:
        if (!validate_update_source(update->address, update->type)) return false;
        state->live.dashboard_temp_decicelsius = update->value.i32;
        return true;
    default:
        return false;
    }
}
