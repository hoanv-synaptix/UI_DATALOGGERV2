/**
 * @file ui_form_read.h
 * @brief Đọc và trích xuất dữ liệu từ các form giao diện LVGL thành định dạng JSON.
 */
#ifndef UI_FORM_READ_H
#define UI_FORM_READ_H

#ifdef __cplusplus
extern "C" {
#endif

#include "view_factory.h"
#include <stdbool.h>

/**
 * @brief Đọc các Text Area của MQTT Form, kiểm tra tính hợp lệ và đóng gói thành chuỗi JSON.
 * 
 * @param ui Con trỏ tới view_factory
 * @return char* Chuỗi JSON chứa cấu hình (Cấp phát động bằng cJSON_PrintUnformatted), 
 *         hoặc NULL nếu kiểm tra tính hợp lệ thất bại (ví dụ để trống Host/Port).
 *         LƯU Ý: Người gọi hàm phải free() chuỗi này sau khi dùng xong.
 */
char *ui_form_read_mqtt(view_factory_t *ui);

#ifdef __cplusplus
}
#endif

#endif /* UI_FORM_READ_H */
