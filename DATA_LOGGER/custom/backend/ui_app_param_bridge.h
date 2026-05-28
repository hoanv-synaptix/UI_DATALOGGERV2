#ifndef __UI_APP_PARAM_BRIDGE_H_
#define __UI_APP_PARAM_BRIDGE_H_

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Khởi tạo luồng tự động quét (Poll) biến app_param của Backend.
 * Dùng khi Backend không chủ động gọi (Push) dữ liệu sang UI.
 */
void ui_app_param_bridge_start(void);

#ifdef __cplusplus
}
#endif

#endif // __UI_APP_PARAM_BRIDGE_H_
