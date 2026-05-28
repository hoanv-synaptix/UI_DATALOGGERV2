/**
 * @file ctrl_navigation.h
 * @brief Quản lý hệ thống sự kiện điều hướng (Nút bấm, Chuyển tab, Danh sách thả xuống).
 *
 * Chức năng chính: Đăng ký (Bind) toàn bộ sự kiện Click/Change từ giao diện LVGL
 * và chuyển đổi chúng thành các tín hiệu Action để đẩy sang State Machine xử lý.
 */
#ifndef __UI_EVENTS_NAVIGATION_H_
#define __UI_EVENTS_NAVIGATION_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "view_factory.h"

/**
 * @brief Khởi tạo và gắn (Bind) tất cả các sự kiện tương tác của người dùng.
 * @param ui Con trỏ tới bộ giao diện tĩnh
 */
void ui_events_navigation_init(view_factory_t *ui);

#ifdef __cplusplus
}
#endif
#endif
