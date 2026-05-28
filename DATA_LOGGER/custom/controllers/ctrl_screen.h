/**
 * @file ctrl_screen.h
 * @brief Bộ điều khiển trung tâm (Screen Controller) quản lý toàn bộ vòng đời của màn hình.
 *
 * Gắn kết (Bind) giữa logic ứng dụng (State) và giao diện tĩnh (View).
 * Mọi sự kiện của người dùng, hoặc dữ liệu từ phần cứng (Sensor/JSON)
 * đều phải đi qua Controller này để quyết định việc vẽ lại giao diện.
 */
#ifndef __UI_SCREEN_CONTROLLER_H_
#define __UI_SCREEN_CONTROLLER_H_

#include "view_factory.h"
#include "app_state.h"
#include "ui_sub.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Khởi tạo Controller và gắn (bind) nó vào màn hình Base. 
 * Gọi một lần duy nhất lúc khởi động UI.
 */
void ui_screen_controller_enter(view_factory_t *ui);

/**
 * @brief Gỡ bỏ Controller khỏi màn hình (Dọn dẹp bộ nhớ/timer).
 */
void ui_screen_controller_exit(void);

/**
 * @brief Nhận sự kiện (Action) từ UI (Nút bấm, Gạt công tắc), chuyển cho State Machine xử lý, và gọi lệnh Render.
 */
void ui_screen_controller_dispatch(view_factory_t *ui, ui_action_t action, uint16_t value);

/**
 * @brief Xóa bỏ các trạng thái nhập liệu đang dang dở (Đóng bàn phím, reset TextInput).
 */
void ui_screen_controller_restore_input(void);

/**
 * @brief Hàm Callback để nhận gói dữ liệu cảm biến thời gian thực (AQI, Nhiệt độ,...) từ Firmware.
 */
void ui_screen_controller_apply_sensor_data(const struct ui_sensor_data_t *data);

#ifdef __cplusplus
}
#endif

#endif
