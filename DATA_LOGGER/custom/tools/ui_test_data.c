#include "ui_test_data.h"
#include "ui_frontend_api.h"
#include "ui_dashboard.h"
#include "lvgl.h"
#include "cJSON.h"
#include <stdlib.h>

static void ui_test_timer_cb(lv_timer_t *timer) {
    (void)timer;

    cJSON *root = cJSON_CreateObject();
    if (!root) return;

    // Note: values are scaled by 10 to provide 1 decimal place.

    // PM2.5: 0.0 to 500.0 µg/m3 -> (0 to 5000)
    cJSON_AddNumberToObject(root, "pm25", rand() % 5001);

    // PM10: 0.0 to 600.0 µg/m3 -> (0 to 6000)
    cJSON_AddNumberToObject(root, "pm10", rand() % 6001);

    // Temp: -10.0 to 50.0 °C -> (-100 to 500)
    cJSON_AddNumberToObject(root, "temp", (rand() % 601) - 100);

    // Humi: 0.0 to 100.0 % -> (0 to 1000)
    cJSON_AddNumberToObject(root, "humi", rand() % 1001);

    // NO2: 0.0 to 1000.0 ppb -> (0 to 10000)
    cJSON_AddNumberToObject(root, "no2", rand() % 10001);

    // SO2: 0.0 to 500.0 ppb -> (0 to 5000)
    cJSON_AddNumberToObject(root, "so2", rand() % 5001);

    // O3: 0.0 to 500.0 ppb -> (0 to 5000)
    cJSON_AddNumberToObject(root, "o3", rand() % 5001);

    // CO2: 400.0 to 2500.0 ppm -> (4000 to 25000)
    cJSON_AddNumberToObject(root, "co2", (rand() % 21001) + 4000);

    // Convert cJSON object to string and post it via Frontend API
    char *json_str = cJSON_PrintUnformatted(root);
    if (json_str) {
        ui_frontend_post_json(UI_FRONTEND_TOPIC_SENSOR_DATA, json_str);
        cJSON_free(json_str);
    }

    // Clean up
    cJSON_Delete(root);

    // Call render to immediately update the visual UI with the new state
    ui_dashboard_render(true);
}

void ui_test_inject_random_dashboard_data(void) {
    // Generate initial values immediately
    ui_test_timer_cb(NULL);
    
    // Create an LVGL timer to periodically randomize values every 30 seconds (30000 ms)
    lv_timer_create(ui_test_timer_cb, 30000, NULL);
}
