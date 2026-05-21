#ifndef __UI_SCREEN_CONTROLLER_H_
#define __UI_SCREEN_CONTROLLER_H_

#include "gui_guider.h"
#include "ui_state.h"

#ifdef __cplusplus
extern "C" {
#endif

void ui_screen_controller_enter(lv_ui *ui);
void ui_screen_controller_exit(void);
void ui_screen_controller_dispatch(lv_ui *ui, ui_action_t action, uint16_t value);
void ui_screen_controller_restore_input(void);

#ifdef __cplusplus
}
#endif

#endif
