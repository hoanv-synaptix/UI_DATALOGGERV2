#ifndef __UI_REGISTER_ADAPTER_H_
#define __UI_REGISTER_ADAPTER_H_

#include <stdbool.h>
#include <stddef.h>
#include "ui_platform_port.h"
#include "ui_register_types.h"

#ifdef __cplusplus
extern "C" {
#endif

bool ui_register_adapter_command_to_writes(const ui_platform_command_t *cmd,
                                           ui_register_write_t *writes,
                                           size_t capacity,
                                           size_t *out_count);

bool ui_register_adapter_apply_update(ui_runtime_state_t *state,
                                      const ui_register_update_t *update);

#ifdef __cplusplus
}
#endif

#endif
