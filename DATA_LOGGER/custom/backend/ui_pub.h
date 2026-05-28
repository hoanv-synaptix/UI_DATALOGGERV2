/**
 * @file ui_pub.h
 * @brief Cổng xuất dữ liệu (Publisher) từ Giao diện (UI) xuống hệ thống Nhúng (Hardware).
 * 
 * Đây là cầu nối duy nhất (Adapter Pattern) để UI gửi lệnh hoặc cấu hình xuống Firmware.
 * Nhờ có lớp trung gian này, source code UI hoàn toàn độc lập với phần cứng cụ thể
 * (có thể chạy trên ESP32, STM32, Linux, v.v.).
 */
#ifndef __UI_PUB_H_
#define __UI_PUB_H_

#include <stdbool.h>
#include <stddef.h>
#include "app_state.h"

#ifdef __cplusplus
extern "C" {
#endif



/**
 * @enum ui_pub_topic_t
 * @brief Các chủ đề (Topic) mà UI có thể phát dữ liệu xuống Firmware.
 */
typedef enum {
    PUB_TOPIC_WIFI,       /**< Yêu cầu cấu hình WiFi */
    PUB_TOPIC_ETHERNET,   /**< Yêu cầu cấu hình Ethernet */
    PUB_TOPIC_LTE,        /**< Yêu cầu cấu hình Mạng di động (LTE/4G) */
    PUB_TOPIC_MQTT,       /**< Yêu cầu cấu hình MQTT */
    PUB_TOPIC_MODBUS,     /**< Yêu cầu cập nhật cấu hình Modbus (Polling list) */
    PUB_TOPIC_SYS_CTRL    /**< Yêu cầu điều khiển hệ thống (Khởi động lại, Cập nhật Firmware) */
} ui_pub_topic_t;

/**
 * @brief Định nghĩa con trỏ hàm (Function Pointer) để Hardware nạp trạng thái ban đầu cho UI.
 */
typedef bool (*ui_pub_state_loader_t)(ui_runtime_state_t *state, void *user_ctx);

/**
 * @brief Định nghĩa con trỏ hàm (Function Pointer) để Hardware bắt các sự kiện JSON từ UI gửi xuống.
 */
typedef bool (*ui_pub_json_handler_t)(ui_pub_topic_t topic, const char *json_payload, void *user_ctx);

/** @brief Khởi tạo hệ thống Publisher */
void ui_pub_init(void);

/**
 * @brief Firmware đăng ký hàm callback để bơm (inject) trạng thái ban đầu khi UI vừa khởi động.
 */
void ui_pub_set_state_loader(ui_pub_state_loader_t loader, void *user_ctx);

/**
 * @brief Yêu cầu Hardware nạp dữ liệu khởi tạo. (Được gọi bởi luồng UI)
 */
bool ui_pub_load_initial_state(ui_runtime_state_t *state);

/**
 * @brief Firmware đăng ký hàm callback để hứng các lệnh JSON từ UI phát xuống.
 */
void ui_pub_set_json_handler(ui_pub_json_handler_t handler, void *user_ctx);

/**
 * @brief Đẩy một chuỗi JSON chứa lệnh/cấu hình từ UI xuống Firmware xử lý.
 * @param topic Phân loại luồng dữ liệu (WIFI, MODBUS,...)
 * @param json_payload Chuỗi JSON
 * @return true nếu Hardware đã tiếp nhận thành công
 */
bool ui_pub_submit_json(ui_pub_topic_t topic, const char *json_payload);

#ifdef __cplusplus
}
#endif

#endif // __UI_PUB_H_
