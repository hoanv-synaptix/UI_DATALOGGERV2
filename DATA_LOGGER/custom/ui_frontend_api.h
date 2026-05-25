#ifndef __UI_FRONTEND_API_H_
#define __UI_FRONTEND_API_H_

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include "ui_register_types.h"

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

bool ui_frontend_post_register_update(const ui_register_update_t *update);
bool ui_frontend_post_register_batch(const ui_register_update_t *updates, size_t count);
bool ui_frontend_post_command_result(uint32_t request_id, bool ok, const char *message);
bool ui_frontend_post_backend_status(ui_backend_status_t status);

#ifdef __cplusplus
}
#endif

#endif
