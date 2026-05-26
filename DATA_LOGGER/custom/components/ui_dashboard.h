#ifndef __UI_DASHBOARD_H_
#define __UI_DASHBOARD_H_

#include <stdbool.h>
#include <stdint.h>
#include "cJSON.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Initialize the dashboard UI module, caching references to LVGL objects.
 */
void ui_dashboard_init(void);

/**
 * @brief Apply JSON updates to the dashboard module.
 * @param root Parsed cJSON object containing sensor data
 */
void ui_dashboard_apply_json(cJSON *root);

/**
 * @brief Render the dashboard, applying thresholds and updating label colors.
 * @param is_active True if the dashboard is currently visible.
 */
void ui_dashboard_render(bool is_active);

#ifdef __cplusplus
}
#endif

#endif // __UI_DASHBOARD_H_
