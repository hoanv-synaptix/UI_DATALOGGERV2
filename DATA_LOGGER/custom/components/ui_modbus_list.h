#ifndef UI_MODBUS_LIST_H
#define UI_MODBUS_LIST_H

#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl.h"
#include "ui_context.h"

/* Initialize the modbus list component (call once after UI bootstrap) */
void ui_modbus_list_init(void);

/* Render the device list into the viewlist container.
 * Call this every time the View List screen is shown or data changes. */
void ui_modbus_list_render(void);

/* Handle the Apply button press: read form fields, add command, navigate to list */
void ui_modbus_list_handle_apply(ui_context_t *ui);

#ifdef __cplusplus
}
#endif

#endif /* UI_MODBUS_LIST_H */
