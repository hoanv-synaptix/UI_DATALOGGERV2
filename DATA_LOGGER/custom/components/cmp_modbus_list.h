/**
 * @file cmp_modbus_list.h
 * @brief Component quản lý danh sách cấu hình Modbus (Thêm, Xóa, Sửa lệnh đọc/ghi).
 *
 * Vẽ danh sách các thiết bị Modbus dưới dạng bảng (Table/List) tự cuộn được.
 */
#ifndef CMP_MODBUS_LIST_H
#define CMP_MODBUS_LIST_H

#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl.h"
#include "view_factory.h"

/**
 * @brief Khởi tạo Component danh sách Modbus (chỉ gọi 1 lần khi khởi động UI)
 */
void cmp_modbus_list_init(void);

/**
 * @brief Vẽ lại danh sách thiết bị vào khung chứa (Container).
 * Hàm này sẽ tạo ra các nút bấm (Sửa/Xóa) động (Dynamic Widgets).
 * Cần gọi mỗi khi danh sách có thay đổi hoặc khi mở tab Modbus.
 */
void cmp_modbus_list_render(void);

/**
 * @brief Xử lý khi bấm nút "Apply" (Lưu cấu hình):
 * - Đọc dữ liệu từ các ô nhập liệu (Text Input).
 * - Cập nhật vào danh sách cục bộ (State).
 * - Gửi lệnh xuống Firmware (Backend) để cấu hình phần cứng.
 */
void cmp_modbus_list_handle_apply(view_factory_t *ui);

#ifdef __cplusplus
}
#endif

#endif /* CMP_MODBUS_LIST_H */
