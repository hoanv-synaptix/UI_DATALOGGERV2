/**
 * @file ui_time_service.h
 * @brief Dịch vụ thời gian — đọc/ghi RTC qua POSIX bridge (time/settimeofday).
 *
 * Cung cấp API thống nhất cho mọi layer trong lvgl/custom/ cần truy cập thời gian thực.
 * Không phụ thuộc trực tiếp vào HAL — sử dụng standard C time() / localtime().
 */
#ifndef __UI_TIME_SERVICE_H_
#define __UI_TIME_SERVICE_H_

#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/** @brief Cấu trúc thời gian đơn giản, không phụ thuộc struct tm */
typedef struct {
    uint16_t year;      /**< 2024-2099 */
    uint8_t  month;     /**< 1-12 */
    uint8_t  day;       /**< 1-31 */
    uint8_t  hour;      /**< 0-23 */
    uint8_t  minute;    /**< 0-59 */
    uint8_t  second;    /**< 0-59 */
    uint8_t  weekday;   /**< 0=Chủ nhật, 1=Thứ hai, ..., 6=Thứ bảy */
} ui_time_t;

/**
 * @brief Đọc thời gian hiện tại từ RTC (qua POSIX bridge _gettimeofday).
 * @param[out] out Con trỏ để nhận kết quả thời gian
 * @return true nếu RTC có thời gian hợp lệ (epoch >= 2024-01-01, tức đã được set qua SNTP hoặc manual).
 *         false nếu RTC chưa được set (cold boot, chưa có SNTP).
 */
bool ui_time_service_get(ui_time_t *out);

/**
 * @brief Đặt thời gian RTC (dùng cho manual set từ UI/Settings hoặc SNTP callback).
 * @param[in] t Con trỏ đến ui_time_t chứa thời gian cần set
 */
void ui_time_service_set(const ui_time_t *t);

#ifdef __cplusplus
}
#endif

#endif /* __UI_TIME_SERVICE_H_ */
