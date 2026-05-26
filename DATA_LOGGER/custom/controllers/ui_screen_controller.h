#ifndef __UI_SCREEN_CONTROLLER_H_
#define __UI_SCREEN_CONTROLLER_H_

#include "ui_context.h"
#include "ui_state.h"
#include "ui_frontend_api.h"

#ifdef __cplusplus
extern "C" {
#endif

void ui_screen_controller_enter(ui_context_t *ui);
void ui_screen_controller_exit(void);
void ui_screen_controller_dispatch(ui_context_t *ui, ui_action_t action, uint16_t value);
void ui_screen_controller_restore_input(void);
void ui_screen_controller_apply_json(ui_frontend_topic_t topic, const char *json_payload);

#ifdef __cplusplus
}
#endif

#endif
