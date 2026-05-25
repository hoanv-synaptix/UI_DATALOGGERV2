#include "ui_frontend_api.h"

#include <string.h>
#include "lvgl.h"
#include "ui_screen_controller.h"

#define UI_FRONTEND_UPDATE_QUEUE_CAPACITY 16U

typedef struct {
    ui_register_update_t updates[UI_FRONTEND_UPDATE_QUEUE_CAPACITY];
    size_t head;
    size_t tail;
    size_t count;
    bool drain_pending;
} ui_frontend_queue_t;

static ui_frontend_queue_t s_queue;
static ui_backend_status_t s_backend_status = UI_BACKEND_STATUS_UNKNOWN;

static bool queue_push_copy(const ui_register_update_t *update)
{
    if (!update || s_queue.count >= UI_FRONTEND_UPDATE_QUEUE_CAPACITY) return false;

    s_queue.updates[s_queue.tail] = *update;
    s_queue.tail = (s_queue.tail + 1U) % UI_FRONTEND_UPDATE_QUEUE_CAPACITY;
    s_queue.count++;
    return true;
}

static bool queue_pop(ui_register_update_t *out)
{
    if (!out || s_queue.count == 0U) return false;

    *out = s_queue.updates[s_queue.head];
    s_queue.head = (s_queue.head + 1U) % UI_FRONTEND_UPDATE_QUEUE_CAPACITY;
    s_queue.count--;
    return true;
}

static void drain_register_updates(void *user_data)
{
    ui_register_update_t update;

    (void)user_data;

    s_queue.drain_pending = false;
    while (queue_pop(&update)) {
        (void)ui_screen_controller_apply_register_update(&update);
    }
}

static void schedule_drain(void)
{
    if (s_queue.drain_pending) return;
    s_queue.drain_pending = true;
    lv_async_call(drain_register_updates, NULL);
}

bool ui_frontend_post_register_update(const ui_register_update_t *update)
{
    if (!queue_push_copy(update)) return false;
    schedule_drain();
    return true;
}

bool ui_frontend_post_register_batch(const ui_register_update_t *updates, size_t count)
{
    size_t i;

    if (!updates && count > 0U) return false;

    for (i = 0; i < count; ++i) {
        if (!queue_push_copy(&updates[i])) return false;
    }
    schedule_drain();
    return true;
}

bool ui_frontend_post_command_result(uint32_t request_id, bool ok, const char *message)
{
    (void)request_id;
    (void)ok;
    (void)message;
    return true;
}

bool ui_frontend_post_backend_status(ui_backend_status_t status)
{
    s_backend_status = status;
    return true;
}
