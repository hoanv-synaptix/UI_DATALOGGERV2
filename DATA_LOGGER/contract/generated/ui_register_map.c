#include "ui_register_map.h"

const ui_register_desc_t g_ui_register_map[] = {
    {REG_WIFI_MODE, "REG_WIFI_MODE", UI_REGISTER_DOMAIN_WIFI, UI_REGISTER_ACCESS_UI_WRITE, UI_REGISTER_TYPE_UINT8, 1.0f, "", 0U},
    {REG_WIFI_SSID, "REG_WIFI_SSID", UI_REGISTER_DOMAIN_WIFI, UI_REGISTER_ACCESS_UI_WRITE, UI_REGISTER_TYPE_STRING, 1.0f, "", 64U},
    {REG_WIFI_PASSWORD, "REG_WIFI_PASSWORD", UI_REGISTER_DOMAIN_WIFI, UI_REGISTER_ACCESS_UI_WRITE, UI_REGISTER_TYPE_STRING, 1.0f, "", 64U},
    {REG_WIFI_STATIC_IP, "REG_WIFI_STATIC_IP", UI_REGISTER_DOMAIN_WIFI, UI_REGISTER_ACCESS_UI_WRITE, UI_REGISTER_TYPE_STRING, 1.0f, "", 32U},
    {REG_LIVE_WIFI_IP, "REG_LIVE_WIFI_IP", UI_REGISTER_DOMAIN_WIFI, UI_REGISTER_ACCESS_BACKEND_WRITE, UI_REGISTER_TYPE_STRING, 1.0f, "", 32U},
    {REG_LIVE_WIFI_STATUS, "REG_LIVE_WIFI_STATUS", UI_REGISTER_DOMAIN_WIFI, UI_REGISTER_ACCESS_BACKEND_WRITE, UI_REGISTER_TYPE_UINT8, 1.0f, "", 0U},
    {REG_DASH_TEMP, "REG_DASH_TEMP", UI_REGISTER_DOMAIN_DASHBOARD, UI_REGISTER_ACCESS_BACKEND_WRITE, UI_REGISTER_TYPE_INT32, 0.1f, "C", 0U},
};

const size_t g_ui_register_map_count = sizeof(g_ui_register_map) / sizeof(g_ui_register_map[0]);

const ui_register_desc_t *ui_register_map_find(uint16_t address)
{
    size_t i;

    for (i = 0; i < g_ui_register_map_count; ++i) {
        if (g_ui_register_map[i].address == address) return &g_ui_register_map[i];
    }
    return NULL;
}
