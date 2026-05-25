#ifndef __UI_REGISTER_MAP_H_
#define __UI_REGISTER_MAP_H_

#include <stddef.h>
#include <stdint.h>
#include "ui_register_types.h"

/* AUTO-GENERATED FILE. DO NOT MODIFY.
 * Source: contract/register_map.csv
 * Regenerate with: python tools/gen_ui_register_map.py
 */

#define REG_WIFI_MODE                    0x1001U /* WiFi IP mode: 0 DHCP, 1 Static */
#define REG_WIFI_SSID                    0x1002U /* WiFi SSID */
#define REG_WIFI_PASSWORD                0x1003U /* WiFi password */
#define REG_WIFI_STATIC_IP               0x1004U /* WiFi static IP address */
#define REG_LIVE_WIFI_IP                 0x5001U /* Current WiFi IP shown on UI */
#define REG_LIVE_WIFI_STATUS             0x5002U /* Current WiFi status: 0 disconnected, 1 connecting, 2 connected, 3 error */
#define REG_DASH_TEMP                    0x6001U /* Dashboard temperature in scaled Celsius */

extern const ui_register_desc_t g_ui_register_map[];
extern const size_t g_ui_register_map_count;

const ui_register_desc_t *ui_register_map_find(uint16_t address);

#endif
