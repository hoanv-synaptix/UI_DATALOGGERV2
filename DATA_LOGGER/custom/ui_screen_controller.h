#ifndef __UI_SCREEN_CONTROLLER_H_
#define __UI_SCREEN_CONTROLLER_H_

#include "ui_context.h"
#include "ui_register_types.h"
#include "ui_state.h"

#ifdef __cplusplus
extern "C" {
#endif

void ui_screen_controller_enter(ui_context_t *ui);
void ui_screen_controller_exit(void);
void ui_screen_controller_dispatch(ui_context_t *ui, ui_action_t action, uint16_t value);
void ui_screen_controller_restore_input(void);
bool ui_screen_controller_apply_register_update(const ui_register_update_t *update);
bool ui_screen_controller_apply_register_batch(const ui_register_update_t *updates, size_t count);

#ifdef __cplusplus
}
#endif

#endif
