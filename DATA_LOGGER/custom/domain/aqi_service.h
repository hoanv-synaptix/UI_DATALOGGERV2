/**
 * @file aqi_service.h
 * @brief Thư viện tính toán Chỉ số Chất lượng Không khí (AQI) và phân loại ngưỡng cảnh báo.
 *
 * Cung cấp các hàm nội suy tuyến tính để tính điểm AQI (Sub-index) theo tiêu chuẩn EPA 
 * của Hoa Kỳ cho các loại khí: PM2.5, PM10, NO2, O3, SO2. Đồng thời đánh giá mức cảnh báo
 * (Good, Moderate,...) cho các thông số Nhiệt độ, Độ ẩm và CO.
 */
#ifndef __aqi_calc_H_
#define __aqi_calc_H_

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @enum threshold_level_t
 * @brief Các mốc cảnh báo tiêu chuẩn cho chất lượng không khí và môi trường.
 */
typedef enum {
    LEVEL_GOOD = 0,               /**< Tốt (Xanh lá) */
    LEVEL_MODERATE,               /**< Trung bình (Vàng) */
    LEVEL_UNHEALTHY_SENSITIVE,    /**< Kém, nhạy cảm (Cam) */
    LEVEL_UNHEALTHY,              /**< Xấu (Đỏ) */
    LEVEL_VERY_UNHEALTHY,         /**< Rất xấu (Tím) */
    LEVEL_HAZARDOUS               /**< Nguy hiểm (Nâu) */
} threshold_level_t;


/**
 * @struct ui_sensor_data_t
 * @brief Cấu trúc lưu trữ dữ liệu thô từ các cảm biến.
 * @note Tất cả các giá trị đều được nhân lên 10 để lưu 1 chữ số thập phân (Ví dụ: 12.5 -> 125).
 */
typedef struct ui_sensor_data_t {
    int32_t pm10;   /**< Bụi mịn PM10 (ug/m3) */
    int32_t pm25;   /**< Bụi mịn PM2.5 (ug/m3) */
    int32_t temp;   /**< Nhiệt độ (Celsius) */
    int32_t humi;   /**< Độ ẩm tương đối (%) */
    int32_t no2;    /**< Khí NO2 (ppb) */
    int32_t o3;     /**< Khí O3 (ppb) */
    int32_t co;    /**< Khí CO (ppm) */
    int32_t so2;    /**< Khí SO2 (ppb) */
    int32_t aqi;    /**< Chỉ số AQI tổng hợp (0-500+) */
} ui_sensor_data_t;

/**
 * @brief Tính điểm AQI tổng hợp (Overall AQI) dựa trên điểm cao nhất của các khí.
 * @param data Con trỏ chứa toàn bộ dữ liệu cảm biến.
 * @return Giá trị AQI tổng (từ 0 - 500+).
 */
uint32_t aqi_calc_overall(const ui_sensor_data_t *data);

/** @brief Nội suy điểm AQI cho bụi PM2.5 */
int32_t aqi_calc_pm25(int32_t val);
/** @brief Nội suy điểm AQI cho bụi PM10 */
int32_t aqi_calc_pm10(int32_t val);
/** @brief Nội suy điểm AQI cho khí NO2 */
int32_t aqi_calc_no2(int32_t val);
/** @brief Nội suy điểm AQI cho khí O3 */
int32_t aqi_calc_o3(int32_t val);
/** @brief Nội suy điểm AQI cho khí SO2 */
int32_t aqi_calc_so2(int32_t val);

/** @brief Quy đổi điểm AQI ra mốc cảnh báo (Good, Moderate,...) */
threshold_level_t get_aqi_level(int32_t aqi_val);
/** @brief Đánh giá mốc cảnh báo cho Nhiệt độ */
threshold_level_t get_temp_level(int32_t temp_val);
/** @brief Đánh giá mốc cảnh báo cho Độ ẩm */
threshold_level_t get_humi_level(int32_t humi_val);
/** @brief Đánh giá mốc cảnh báo cho nồng độ CO */
threshold_level_t get_co_level(int32_t co_val);


#ifdef __cplusplus
}
#endif

#endif // __aqi_calc_H_
