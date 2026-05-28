/**
 * @file ui_sub.h
 * @brief Cổng nhận dữ liệu (Subscriber) từ hệ thống Nhúng (Hardware) lên Giao diện (UI).
 * 
 * Đây là cánh cửa duy nhất để Firmware cập nhật trạng thái lên màn hình LVGL.
 * Tất cả dữ liệu đẩy lên đây sẽ được đưa vào hàng đợi bất đồng bộ (lv_async_call) 
 * để đảm bảo an toàn luồng (Thread-safe) cho LVGL.
 */
#ifndef __UI_SUB_H_
#define __UI_SUB_H_

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @enum ui_backend_status_t
 * @brief Trạng thái kết nối của mạch (Ví dụ: Trạng thái WiFi, MQTT, Cloud)
 */
typedef enum {
    UI_BACKEND_STATUS_UNKNOWN = 0,    /**< Chưa xác định */
    UI_BACKEND_STATUS_OFFLINE,        /**< Mất kết nối */
    UI_BACKEND_STATUS_CONNECTING,     /**< Đang kết nối */
    UI_BACKEND_STATUS_ONLINE,         /**< Đã kết nối thành công */
    UI_BACKEND_STATUS_ERROR           /**< Lỗi hệ thống mạng */
} ui_backend_status_t;

/**
 * @enum ui_sub_topic_t
 * @brief Các chủ đề (Topic) mà UI đăng ký nhận dữ liệu từ phần cứng
 */
typedef enum {
    SUB_TOPIC_SENSOR_DATA,   /**< Topic nhận dữ liệu các cảm biến đo lường môi trường */
    SUB_TOPIC_SYS_STATUS     /**< Topic nhận dữ liệu cập nhật trạng thái hệ thống */
} ui_sub_topic_t;

#define UI_JSON_KEY_AQI   "aqi"
#define UI_JSON_KEY_PM25  "pm25"
#define UI_JSON_KEY_PM10  "pm10"
#define UI_JSON_KEY_TEMP  "temp"
#define UI_JSON_KEY_HUMI  "humi"
#define UI_JSON_KEY_NO2   "no2"
#define UI_JSON_KEY_O3    "o3"
#define UI_JSON_KEY_CO   "co"
#define UI_JSON_KEY_SO2   "so2"

/**
 * @brief Hàm nhận chuỗi JSON từ Hardware, phân tích và cập nhật UI một cách an toàn.
 * @param topic Chủ đề dữ liệu đang được gửi lên
 * @param json_payload Chuỗi định dạng JSON chứa cấu hình hoặc dữ liệu
 * @return true nếu gửi thành công vào hàng đợi
 */
bool ui_sub_post_json(ui_sub_topic_t topic, const char *json_payload);

/**
 * @brief Cập nhật trạng thái kết nối mạng của thiết bị
 * @param status Trạng thái mạng hiện tại
 * @return true nếu cập nhật thành công
 */
bool ui_sub_post_backend_status(ui_backend_status_t status);

struct ui_sensor_data_t; // Forward declaration để tránh include chéo

/**
 * @brief Hàm nhận dữ liệu cảm biến trực tiếp bằng Struct (không qua JSON) để tăng tốc độ xử lý.
 * @param data Con trỏ chứa Struct dữ liệu cảm biến
 * @return true nếu gửi thành công vào hàng đợi
 */
bool ui_sub_post_sensor_data(const struct ui_sensor_data_t *data);

struct AppParam;

/**
 * @brief Hàm Adapter nhận trực tiếp cấu trúc AppParam_t của Backend 
 * và chuyển đổi tự động sang luồng UI.
 * @param param Con trỏ tới AppParam_t
 * @return true nếu gửi thành công vào hàng đợi
 */
bool ui_sub_post_app_param(const struct AppParam *param);

#ifdef __cplusplus
}
#endif

#endif // __UI_SUB_H_
