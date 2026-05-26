#ifndef __UI_FRONTEND_API_H_
#define __UI_FRONTEND_API_H_

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    UI_BACKEND_STATUS_UNKNOWN = 0,
    UI_BACKEND_STATUS_OFFLINE,
    UI_BACKEND_STATUS_CONNECTING,
    UI_BACKEND_STATUS_ONLINE,
    UI_BACKEND_STATUS_ERROR
} ui_backend_status_t;

typedef enum {
    UI_FRONTEND_TOPIC_SENSOR_DATA,
    UI_FRONTEND_TOPIC_SYSTEM_STATUS
} ui_frontend_topic_t;

#define UI_JSON_KEY_AQI   "aqi"
#define UI_JSON_KEY_PM25  "pm25"
#define UI_JSON_KEY_PM10  "pm10"
#define UI_JSON_KEY_TEMP  "temp"
#define UI_JSON_KEY_HUMI  "humi"
#define UI_JSON_KEY_NO2   "no2"
#define UI_JSON_KEY_O3    "o3"
#define UI_JSON_KEY_CO2   "co2"
#define UI_JSON_KEY_SO2   "so2"

bool ui_frontend_post_json(ui_frontend_topic_t topic, const char *json_payload);
bool ui_frontend_post_backend_status(ui_backend_status_t status);

#ifdef __cplusplus
}
#endif

#endif
