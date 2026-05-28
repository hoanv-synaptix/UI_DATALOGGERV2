#ifndef __UI_RUNTIME_GUARD_H_
#define __UI_RUNTIME_GUARD_H_

#include <stdbool.h>
#include "view_factory.h"
#include "lvgl.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef void (*ui_runtime_rebind_cb_t)(view_factory_t *ui);

void ui_runtime_guard_init(view_factory_t *ui, ui_runtime_rebind_cb_t rebind_cb);
void ui_runtime_guard_mark_bound(lv_obj_t *scr_base);
bool ui_runtime_guard_should_rebind(void);
view_factory_t *ui_runtime_guard_get_ui(void);

#ifdef __cplusplus
}
#endif

#endif
