/**
 * @file custom.h
 * @brief Điểm khởi đầu (Entry Point) của mã nguồn tự viết (Custom UI).
 * 
 * GUI Guider sẽ gọi hàm `custom_init()` sau khi đã sinh xong các giao diện tự động.
 * Chúng ta sử dụng hàm này để thắt chặt (hook) logic tự viết của mình vào luồng của LVGL.
 */
#ifndef __CUSTOM_H_
#define __CUSTOM_H_
#ifdef __cplusplus
extern "C" {
#endif

#include "view_factory.h"

/**
 * @brief Hàm khởi tạo Custom Code. Được gọi một lần duy nhất lúc khởi động màn hình.
 * @param generated_ui Con trỏ chứa giao diện tự sinh của GUI Guider (thường không sử dụng trực tiếp)
 */
void custom_init(void *generated_ui);

/**
 * @brief Đặt lại (Reset) trạng thái đầu vào, dùng để dọn dẹp biến tạm khi màn hình thay đổi.
 */
void custom_input_reset(void);

#ifdef __cplusplus
}
#endif
#endif // __CUSTOM_H_
