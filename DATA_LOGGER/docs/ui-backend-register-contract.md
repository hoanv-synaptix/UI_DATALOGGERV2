# UI Backend Register Contract

## Rule

UI widgets and screen controller code stay domain/action based. Register addresses live in `contract/register_map.csv`, generated `contract/generated/ui_register_map.*`, and backend/adapter code only.

Backend must not call LVGL objects directly. Backend-to-UI updates go through `ui_frontend_api.h`. UI-to-backend commands go through `ui_platform_port.h`.

## Current Simulator Flow

The simulator backend is implemented in `sim/ui_sim_backend.c`.

Startup path:

```c
custom_init()
    ui_platform_port_init()
    ui_sim_backend_init()
    ui_screen_controller_enter(ui)
```

`ui_sim_backend_init()` registers:

```c
ui_platform_port_set_state_loader(...)
ui_platform_port_set_command_handler(...)
ui_platform_port_set_register_writer(...)
```

When the UI saves WiFi config, the controller builds `UI_PLATFORM_CMD_SAVE_WIFI_CONFIG`. The register adapter converts it into:

- `REG_WIFI_MODE`
- `REG_WIFI_SSID`
- `REG_WIFI_PASSWORD`
- `REG_WIFI_STATIC_IP`

The simulator backend receives those writes, stores them in RAM, logs the contract, then posts live updates back:

- `REG_LIVE_WIFI_STATUS`
- `REG_LIVE_WIFI_IP`

## Backend Replacement

When hardware/backend code is ready, replace `ui_sim_backend_init()` with the real backend registration. Keep the frontend API and register adapter unchanged.

Real backend-facing callbacks should follow this shape:

```c
bool backend_ui_load_initial_state(ui_runtime_state_t *state, void *ctx);
bool backend_ui_handle_command(const ui_platform_command_t *cmd, void *ctx);
bool backend_ui_write_registers(const ui_register_write_t *writes, size_t count, void *ctx);
```

Register them with:

```c
ui_platform_port_set_state_loader(backend_ui_load_initial_state, backend_ctx);
ui_platform_port_set_command_handler(backend_ui_handle_command, backend_ctx);
ui_platform_port_set_register_writer(backend_ui_write_registers, backend_ctx);
```

Backend-to-UI updates use:

```c
bool ui_frontend_post_register_update(const ui_register_update_t *update);
bool ui_frontend_post_register_batch(const ui_register_update_t *updates, size_t count);
bool ui_frontend_post_command_result(uint32_t request_id, bool ok, const char *message);
bool ui_frontend_post_backend_status(ui_backend_status_t status);
```

## Checks

Run these after changing register contract code:

```powershell
powershell -ExecutionPolicy Bypass -File .\tests\check_ui_register_map.ps1
powershell -ExecutionPolicy Bypass -File .\tests\check_ui_register_boundary.ps1
powershell -ExecutionPolicy Bypass -File .\tests\check_ui_register_adapter.ps1
```
