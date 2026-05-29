#include "ui_sub.h"

#include <string.h>
#include <stdlib.h>
#include "lvgl.h"
#include "ctrl_screen.h"
#include "aqi_service.h"
#include "cJSON.h"

static volatile ui_backend_status_t s_backend_status = UI_BACKEND_STATUS_UNKNOWN;

/* =========================================================================
 * Cấu trúc gói tin JSON bất đồng bộ (dùng chung cả 2 path)
 * ========================================================================= */
typedef struct {
    ui_sub_topic_t topic;
    char *payload;
} ui_json_msg_t;

/* ---------- Hàm xử lý JSON trong LVGL thread (safe) ---------- */
static void process_json_msg(ui_json_msg_t *msg)
{
    if (!msg) return;

    if (msg->topic == SUB_TOPIC_SENSOR_DATA) {
        cJSON *root = cJSON_Parse(msg->payload);
        if (root) {
            ui_sensor_data_t sd = {0};
            cJSON *it;

            it = cJSON_GetObjectItem(root, "pm10"); if (it && cJSON_IsNumber(it)) sd.pm10 = it->valueint;
            it = cJSON_GetObjectItem(root, "pm25"); if (it && cJSON_IsNumber(it)) sd.pm25 = it->valueint;
            it = cJSON_GetObjectItem(root, "temp"); if (it && cJSON_IsNumber(it)) sd.temp = it->valueint;
            it = cJSON_GetObjectItem(root, "humi"); if (it && cJSON_IsNumber(it)) sd.humi = it->valueint;
            it = cJSON_GetObjectItem(root, "no2");  if (it && cJSON_IsNumber(it)) sd.no2  = it->valueint;
            it = cJSON_GetObjectItem(root, "o3");   if (it && cJSON_IsNumber(it)) sd.o3   = it->valueint;
            it = cJSON_GetObjectItem(root, "co");   if (it && cJSON_IsNumber(it)) sd.co   = it->valueint;
            it = cJSON_GetObjectItem(root, "so2");  if (it && cJSON_IsNumber(it)) sd.so2  = it->valueint;
            it = cJSON_GetObjectItem(root, "aqi");  if (it && cJSON_IsNumber(it)) sd.aqi  = it->valueint;

            ui_screen_controller_apply_sensor_data(&sd);
            cJSON_Delete(root);
        }
    } else if (msg->topic == SUB_TOPIC_SYS_STATUS) {
        /* TODO: Parse SYS_STATUS JSON → dispatch to controller */
    }

    free(msg->payload);
    free(msg);
}

/* =========================================================================
 * SENSOR: Latest-Wins Mailbox (dùng chung cả 2 path)
 * ========================================================================= */
static ui_sensor_data_t s_latest_sensor;
static volatile bool    s_sensor_dirty = false;

/* =========================================================================
 * FIRMWARE PATH (FreeRTOS): Queue + Critical Section + drain timer
 * ========================================================================= */
#ifndef _WIN32

#include "FreeRTOS.h"
#include "queue.h"

#define UI_JSON_QUEUE_DEPTH  8
static QueueHandle_t s_json_queue = NULL;
static lv_timer_t   *s_drain_timer = NULL;

#define UI_DRAIN_MAX_PER_TICK  3   /* Max JSON messages processed per LVGL tick */

static void ui_drain_timer_cb(lv_timer_t *timer)
{
    (void)timer;

    /* 1. Drain queue JSON -- bounded to prevent blocking LVGL main loop */
    if (s_json_queue) {
        ui_json_msg_t *msg;
        uint8_t processed = 0;
        while (processed < UI_DRAIN_MAX_PER_TICK &&
               xQueueReceive(s_json_queue, &msg, 0) == pdTRUE) {
            process_json_msg(msg);
            processed++;
        }
    }

    /* 2. Drain sensor mailbox (latest-wins) */
    if (s_sensor_dirty) {
        ui_sensor_data_t copy;
        taskENTER_CRITICAL();
        copy = s_latest_sensor;
        s_sensor_dirty = false;
        taskEXIT_CRITICAL();

        ui_screen_controller_apply_sensor_data(&copy);
    }
}

void ui_sub_init(void)
{
    if (!s_json_queue) s_json_queue = xQueueCreate(UI_JSON_QUEUE_DEPTH, sizeof(ui_json_msg_t *));
    if (!s_drain_timer) s_drain_timer = lv_timer_create(ui_drain_timer_cb, 50, NULL);
}


bool ui_sub_post_json(ui_sub_topic_t topic, const char *json_payload)
{
    if (!json_payload) return false;

    ui_json_msg_t *msg = (ui_json_msg_t *)malloc(sizeof(ui_json_msg_t));
    if (!msg) return false;

    msg->topic = topic;

    size_t len = strlen(json_payload);
    msg->payload = (char *)malloc(len + 1);
    if (!msg->payload) {
        free(msg);
        return false;
    }
    strcpy(msg->payload, json_payload);

    if (!s_json_queue) {
        free(msg->payload);
        free(msg);
        return false;
    }

    if (xQueueSend(s_json_queue, &msg, pdMS_TO_TICKS(10)) != pdTRUE) {
        free(msg->payload);
        free(msg);
        return false;
    }

    return true;
}

bool ui_sub_post_sensor_data(const struct ui_sensor_data_t *data)
{
    if (!data) return false;

    taskENTER_CRITICAL();
    s_latest_sensor = *data;
    s_sensor_dirty  = true;
    taskEXIT_CRITICAL();

    return true;
}

#include "app_param.h"

bool ui_sub_post_app_param(const struct AppParam *param) {
    if (!param) return false;

    ui_sensor_data_t ui_data = {0};

    ui_data.pm10 = (int32_t)(param->iaqi.pm10 * 10.0f);
    ui_data.pm25 = (int32_t)(param->iaqi.pm25 * 10.0f);
    ui_data.temp = (int32_t)(param->iaqi.t * 10.0f);
    ui_data.humi = (int32_t)(param->iaqi.h * 10.0f);
    ui_data.no2  = (int32_t)(param->iaqi.no2 * 10.0f);
    ui_data.o3   = (int32_t)(param->iaqi.o3 * 10.0f);
    ui_data.co   = (int32_t)(param->iaqi.co * 10.0f);
    ui_data.so2  = (int32_t)(param->iaqi.so2 * 10.0f);
    ui_data.aqi  = (int32_t)(param->aqi);

    return ui_sub_post_sensor_data(&ui_data);
}

/* =========================================================================
 * SIMULATOR PATH (_WIN32): lv_async_call — single-thread, an toàn
 * ========================================================================= */
#else

static void async_json_handler(void *user_data) {
    process_json_msg((ui_json_msg_t *)user_data);
}

static lv_timer_t *s_sim_drain_timer = NULL;

static void sim_drain_timer_cb(lv_timer_t *timer) {
    (void)timer;
    if (s_sensor_dirty) {
        s_sensor_dirty = false;
        ui_screen_controller_apply_sensor_data(&s_latest_sensor);
    }
}

void ui_sub_init(void)
{
    if (!s_sim_drain_timer)
        s_sim_drain_timer = lv_timer_create(sim_drain_timer_cb, 50, NULL);
}

bool ui_sub_post_json(ui_sub_topic_t topic, const char *json_payload)
{
    if (!json_payload) return false;

    ui_json_msg_t *msg = (ui_json_msg_t *)malloc(sizeof(ui_json_msg_t));
    if (!msg) return false;

    msg->topic = topic;

    size_t len = strlen(json_payload);
    msg->payload = (char *)malloc(len + 1);
    if (!msg->payload) {
        free(msg);
        return false;
    }
    strcpy(msg->payload, json_payload);

    lv_async_call(async_json_handler, msg);
    return true;
}

bool ui_sub_post_sensor_data(const struct ui_sensor_data_t *data)
{
    if (!data) return false;

    s_latest_sensor = *data;
    s_sensor_dirty  = true;
    return true;
}

#endif /* _WIN32 */

/* =========================================================================
 * COMMON: Backend status (không cần thread-safety, chỉ đọc/ghi 1 biến)
 * ========================================================================= */

bool ui_sub_post_backend_status(ui_backend_status_t status)
{
    s_backend_status = status;
    return true;
}
