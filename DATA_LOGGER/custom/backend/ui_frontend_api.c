#include "ui_frontend_api.h"

#include <string.h>
#include <stdlib.h>
#include "lvgl.h"
#include "ui_screen_controller.h"

static ui_backend_status_t s_backend_status = UI_BACKEND_STATUS_UNKNOWN;

typedef struct {
    ui_frontend_topic_t topic;
    char *payload;
} async_json_t;

static void async_json_handler(void *user_data) {
    async_json_t *data = (async_json_t *)user_data;
    if (data) {
        ui_screen_controller_apply_json(data->topic, data->payload);
        free(data->payload);
        free(data);
    }
}

bool ui_frontend_post_json(ui_frontend_topic_t topic, const char *json_payload) {
    if (!json_payload) return false;
    async_json_t *data = (async_json_t *)malloc(sizeof(async_json_t));
    if (!data) return false;
    data->topic = topic;
    
    size_t len = strlen(json_payload);
    data->payload = (char *)malloc(len + 1);
    if (!data->payload) {
        free(data);
        return false;
    }
    strcpy(data->payload, json_payload);
    
    lv_async_call(async_json_handler, data);
    return true;
}

bool ui_frontend_post_backend_status(ui_backend_status_t status)
{
    s_backend_status = status;
    return true;
}
