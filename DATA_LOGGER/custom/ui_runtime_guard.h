#ifndef __UI_RUNTIME_GUARD_H_
#define __UI_RUNTIME_GUARD_H_

#include <stdbool.h>
#include "gui_guider.h"
#include "lvgl.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef void (*ui_runtime_rebind_cb_t)(lv_ui *ui);

void ui_runtime_guard_init(lv_ui *ui, ui_runtime_rebind_cb_t rebind_cb);
void ui_runtime_guard_mark_bound(lv_obj_t *scr_base);
bool ui_runtime_guard_should_rebind(void);
lv_ui *ui_runtime_guard_get_ui(void);

#ifdef __cplusplus
}
#endif

#endif
