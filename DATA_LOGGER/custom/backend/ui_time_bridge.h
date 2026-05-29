/**
 * @file ui_time_bridge.h
 * @brief Cầu nối RTC → UI Labels — tự động cập nhật thời gian/ngày lên Dashboard.
 *
 * Tạo LVGL timer (1 giây) đọc thời gian từ ui_time_service và cập nhật
 * 2 label: scr_base_time_val (HH:MM:SS) và scr_base_date_val (YYYY/MM/DD).
 */
#ifndef __UI_TIME_BRIDGE_H_
#define __UI_TIME_BRIDGE_H_

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Khởi tạo timer cập nhật thời gian. Gọi một lần khi Dashboard sẵn sàng.
 */
void ui_time_bridge_start(void);

/**
 * @brief Dừng timer cập nhật thời gian. Gọi khi Controller thoát (screen exit).
 */
void ui_time_bridge_stop(void);

#ifdef __cplusplus
}
#endif

#endif /* __UI_TIME_BRIDGE_H_ */
