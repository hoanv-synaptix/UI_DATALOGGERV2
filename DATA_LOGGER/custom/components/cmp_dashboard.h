/**
 * @file cmp_dashboard.h
 * @brief Component chịu trách nhiệm vẽ màn hình Dashboard (Tổng quan).
 *
 * Tách biệt hoàn toàn logic tính toán (tầng Domain) với logic hiển thị.
 * Nhận dữ liệu (đã được tính toán AQI) và ánh xạ lên giao diện LVGL tĩnh
 * (được sinh bởi NXP GUI Guider).
 */
#ifndef __CMP_DASHBOARD_H_
#define __CMP_DASHBOARD_H_

#include <stdbool.h>
#include <stdint.h>
#include "aqi_service.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Khởi tạo Dashboard Component, có thể tiêm dữ liệu giả (Test Data)
 */
void cmp_dashboard_init(void);

/**
 * @brief Nhận gói dữ liệu cảm biến mới và lưu vào State nội bộ (chưa vẽ).
 * @param data Con trỏ tới gói dữ liệu thô từ cảm biến.
 */
void cmp_dashboard_apply_data(const ui_sensor_data_t *data);

/**
 * @brief Thực thi lệnh Vẽ (Render) màn hình Dashboard, thay đổi màu sắc và text.
 * @param is_active True nếu màn hình Dashboard đang được bật (ngăn không cho vẽ ngầm tốn CPU)
 */
void cmp_dashboard_render(bool is_active);

#ifdef __cplusplus
}
#endif

#endif // __cmp_dashboard_H_
