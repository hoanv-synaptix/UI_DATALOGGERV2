#include "ui_sub.h"

#include <string.h>
#include <stdlib.h>
#include "lvgl.h"
#include "ctrl_screen.h"
#include "aqi_service.h"

static ui_backend_status_t s_backend_status = UI_BACKEND_STATUS_UNKNOWN;

/**
 * @brief Cấu trúc gói tin bất đồng bộ dùng cho lv_async_call.
 * Khi nhận dữ liệu từ luồng (Thread) khác, ta cần bọc payload lại và chuyển
 * giao vào Thread chính của LVGL để tránh crash bộ nhớ.
 */
typedef struct {
    ui_sub_topic_t topic;
    char *payload;
} async_json_t;

#include "cJSON.h"

/**
 * @brief Hàm Callback được LVGL Thread gọi để thực thi parse JSON và cập nhật giao diện.
 * 
 * @param user_data Con trỏ trỏ tới gói tin `async_json_t` đã được bọc
 */
static void async_json_handler(void *user_data) {
    async_json_t *data = (async_json_t *)user_data;
    if (data) {
        if (data->topic == SUB_TOPIC_SENSOR_DATA) {
            // Bước 1: Phân tích cú pháp JSON
            cJSON *root = cJSON_Parse(data->payload);
            if (root) {
                ui_sensor_data_t sensor_data = {0};
                cJSON *item;
                
                // Bước 2: Trích xuất các trường dữ liệu một cách an toàn
                item = cJSON_GetObjectItem(root, "pm10"); if (item && cJSON_IsNumber(item)) sensor_data.pm10 = item->valueint;
                item = cJSON_GetObjectItem(root, "pm25"); if (item && cJSON_IsNumber(item)) sensor_data.pm25 = item->valueint;
                item = cJSON_GetObjectItem(root, "temp"); if (item && cJSON_IsNumber(item)) sensor_data.temp = item->valueint;
                item = cJSON_GetObjectItem(root, "humi"); if (item && cJSON_IsNumber(item)) sensor_data.humi = item->valueint;
                item = cJSON_GetObjectItem(root, "no2"); if (item && cJSON_IsNumber(item)) sensor_data.no2 = item->valueint;
                item = cJSON_GetObjectItem(root, "o3"); if (item && cJSON_IsNumber(item)) sensor_data.o3 = item->valueint;
                item = cJSON_GetObjectItem(root, "co"); if (item && cJSON_IsNumber(item)) sensor_data.co = item->valueint;
                item = cJSON_GetObjectItem(root, "so2"); if (item && cJSON_IsNumber(item)) sensor_data.so2 = item->valueint;
                item = cJSON_GetObjectItem(root, "aqi"); if (item && cJSON_IsNumber(item)) sensor_data.aqi = item->valueint;
                
                // Bước 3: Đẩy cấu trúc C tĩnh sạch sẽ sang Controller
                ui_screen_controller_apply_sensor_data(&sensor_data);
                
                // Giải phóng bộ nhớ cJSON
                cJSON_Delete(root);
            }
        } else if (data->topic == SUB_TOPIC_SYS_STATUS) {
            // TODO: Parse SYS_STATUS JSON into a struct here and dispatch to Controller
            // example: cJSON_Parse(data->payload);
        }
        
        // Dọn dẹp bộ nhớ đã cấp phát bằng malloc ở hàm ui_sub_post_json
        free(data->payload);
        free(data);
    }
}

bool ui_sub_post_json(ui_sub_topic_t topic, const char *json_payload) {
    if (!json_payload) return false;
    
    // Cấp phát bộ nhớ cho gói tin
    async_json_t *data = (async_json_t *)malloc(sizeof(async_json_t));
    if (!data) return false;
    
    data->topic = topic;
    
    // Cấp phát và sao chép chuỗi JSON vào vùng nhớ Heap an toàn (tránh mất data khi biến cục bộ bị hủy)
    size_t len = strlen(json_payload);
    data->payload = (char *)malloc(len + 1);
    if (!data->payload) {
        free(data);
        return false;
    }
    strcpy(data->payload, json_payload);
    
    // Đẩy việc xử lý hàm callback vào hàng đợi chính của LVGL để đảm bảo Thread-safe
    lv_async_call(async_json_handler, data);
    return true;
}

bool ui_sub_post_backend_status(ui_backend_status_t status)
{
    s_backend_status = status;
    return true;
}

#include "cmp_dashboard.h"

static void async_sensor_data_handler(void *user_data) {
    ui_sensor_data_t *data = (ui_sensor_data_t *)user_data;
    if (data) {
        ui_screen_controller_apply_sensor_data(data);
        free(data); // Giải phóng RAM đã cấp phát
    }
}

bool ui_sub_post_sensor_data(const struct ui_sensor_data_t *data) {
    if (!data) return false;
    
    // Cấp phát Heap để sao chép toàn bộ Struct sang Thread của UI
    ui_sensor_data_t *copy = (ui_sensor_data_t *)malloc(sizeof(ui_sensor_data_t));
    if (!copy) return false;
    
    *copy = *data;
    
    // Gọi thực thi bất đồng bộ an toàn
    lv_async_call(async_sensor_data_handler, copy);
    return true;
}

#ifndef _WIN32
#include "app_param.h"

bool ui_sub_post_app_param(const struct AppParam *param) {
    if (!param) return false;

    ui_sensor_data_t ui_data = {0};
    
    // Ánh xạ (Mapping) và scale dữ liệu x10 để chuyển từ float sang int32_t
    ui_data.pm10 = (int32_t)(param->iaqi.pm10 * 10.0f);
    ui_data.pm25 = (int32_t)(param->iaqi.pm25 * 10.0f);
    ui_data.temp = (int32_t)(param->iaqi.t * 10.0f);
    ui_data.humi = (int32_t)(param->iaqi.h * 10.0f);
    ui_data.no2  = (int32_t)(param->iaqi.no2 * 10.0f);
    ui_data.o3   = (int32_t)(param->iaqi.o3 * 10.0f);
    ui_data.co  = (int32_t)(param->iaqi.co * 10.0f);
    ui_data.so2  = (int32_t)(param->iaqi.so2 * 10.0f);
    ui_data.aqi  = (int32_t)(param->aqi); // AQI là số nguyên 0-500, không scale x10
    
    // Đẩy vào hệ thống xử lý bất đồng bộ
    return ui_sub_post_sensor_data(&ui_data);
}
#endif // _WIN32
