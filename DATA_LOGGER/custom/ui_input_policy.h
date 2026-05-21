#ifndef __UI_INPUT_POLICY_H_
#define __UI_INPUT_POLICY_H_

#include <stdbool.h>
#include "gui_guider.h"
#include "lvgl.h"
#include "ui_state.h"

#ifdef __cplusplus
extern "C" {
#endif

void ui_input_policy_bind(lv_ui *ui);
void ui_input_policy_unbind(void);
void ui_input_policy_apply(lv_ui *ui, const ui_runtime_state_t *state);
bool ui_input_policy_is_enabled(lv_ui *ui, lv_obj_t *input_obj);

#ifdef __cplusplus
}
#endif

#endif
