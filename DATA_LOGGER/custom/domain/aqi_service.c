#include "aqi_service.h"
#include <stddef.h>

/* 
 * Các hằng số Breakpoint (Ngưỡng) không còn được định nghĩa qua macro 
 * vì chúng ta dùng mảng tĩnh (Lookup Table) bên dưới.
 */

/**
 * @brief Cấu trúc định nghĩa một dải giá trị Breakpoint theo chuẩn EPA.
 * Bao gồm Nồng độ Min/Max (C) và Điểm số Min/Max tương ứng (I).
 */
typedef struct {
    int32_t c_low;  /**< Nồng độ cận dưới (Concentration Low) */
    int32_t c_high; /**< Nồng độ cận trên (Concentration High) */
    int32_t i_low;  /**< Điểm AQI cận dưới (Index Low) */
    int32_t i_high; /**< Điểm AQI cận trên (Index High) */
} aqi_bp_t;

// Note: Values are scaled by 10 because frontend stores them with 1 decimal point (e.g. 12.3 is 123)
static const aqi_bp_t bp_pm25[] = {
    {0, 90, 0, 50}, {90, 354, 50, 100}, {354, 554, 100, 150},
    {554, 1254, 150, 200}, {1254, 2254, 200, 300}, {2254, 3254, 300, 400}, {3254, 5004, 400, 500}
};

static const aqi_bp_t bp_pm10[] = {
    {0, 540, 0, 50}, {540, 1540, 50, 100}, {1540, 2540, 100, 150},
    {2540, 3540, 150, 200}, {3540, 4240, 200, 300}, {4240, 5040, 300, 400}, {5040, 6040, 400, 500}
};

static const aqi_bp_t bp_no2[] = {
    {0, 530, 0, 50}, {530, 1000, 50, 100}, {1000, 3600, 100, 150},
    {3600, 6490, 150, 200}, {6490, 12490, 200, 300}, {12490, 16490, 300, 400}, {16490, 20490, 400, 500}
};

static const aqi_bp_t bp_so2[] = {
    {0, 350, 0, 50}, {350, 750, 50, 100}, {750, 1850, 100, 150},
    {1850, 3040, 150, 200}, {3040, 6040, 200, 300}, {6040, 8040, 300, 400}, {8040, 10040, 400, 500}
};

static const aqi_bp_t bp_o3[] = {
    {0, 540, 0, 50}, {540, 700, 50, 100}, {700, 850, 100, 150},
    {850, 1050, 150, 200}, {1050, 2000, 200, 300}, {2000, 5040, 300, 400}, {5040, 6040, 400, 500}
};

/**
 * @brief Hàm nội suy tuyến tính để tính điểm Sub-AQI cho một nồng độ khí.
 * Công thức EPA: I = ((I_High - I_Low) / (C_High - C_Low)) * (C - C_Low) + I_Low
 * 
 * @param val Nồng độ thô đọc được từ cảm biến (đã nhân 10)
 * @param table Bảng Lookup Table tương ứng cho loại khí đó
 * @param size Số lượng phần tử trong Lookup Table
 * @return Điểm AQI đã được làm tròn
 */
static int32_t calc_aqi_subindex(int32_t val, const aqi_bp_t *table, size_t size) {
    if (val < 0) return 0; // Bỏ qua dữ liệu âm (nhiễu cảm biến)
    
    // Quét qua các mốc để tìm khoảng giá trị (range) phù hợp
    for (size_t i = 0; i < size; i++) {
        if (val >= table[i].c_low && val <= table[i].c_high) {
            int32_t c_diff = table[i].c_high - table[i].c_low;
            if (c_diff == 0) return table[i].i_low; // Chống lỗi chia cho 0
            
            int32_t numerator = (table[i].i_high - table[i].i_low) * (val - table[i].c_low);
            // Kỹ thuật cộng (c_diff / 2) vào tử số để làm tròn số nguyên (Round to nearest integer)
            return (numerator + (c_diff / 2)) / c_diff + table[i].i_low;
        }
    }
    
    // Nếu giá trị vượt qua mốc cao nhất của bảng EPA, thực hiện ngoại suy (Extrapolate)
    const aqi_bp_t *last = &table[size - 1];
    int32_t c_diff = last->c_high - last->c_low;
    if (c_diff == 0) return last->i_high;
    
    int32_t numerator = (last->i_high - last->i_low) * (val - last->c_low);
    return (numerator + (c_diff / 2)) / c_diff + last->i_low;
}

int32_t aqi_calc_pm25(int32_t val) {
    return calc_aqi_subindex(val, bp_pm25, sizeof(bp_pm25)/sizeof(bp_pm25[0]));
}

int32_t aqi_calc_pm10(int32_t val) {
    return calc_aqi_subindex(val, bp_pm10, sizeof(bp_pm10)/sizeof(bp_pm10[0]));
}

int32_t aqi_calc_no2(int32_t val) {
    return calc_aqi_subindex(val, bp_no2, sizeof(bp_no2)/sizeof(bp_no2[0]));
}

int32_t aqi_calc_o3(int32_t val) {
    return calc_aqi_subindex(val, bp_o3, sizeof(bp_o3)/sizeof(bp_o3[0]));
}

int32_t aqi_calc_so2(int32_t val) {
    return calc_aqi_subindex(val, bp_so2, sizeof(bp_so2)/sizeof(bp_so2[0]));
}

/**
 * @brief AQI Tổng được tính bằng điểm AQI cao nhất (Worst-case) trong tất cả các khí
 */
uint32_t aqi_calc_overall(const ui_sensor_data_t *data) {
    int32_t max_aqi = 0;
    int32_t sub_aqi = 0;

    if (!data) return 0;

    // So sánh PM2.5
    sub_aqi = aqi_calc_pm25(data->pm25);
    if (sub_aqi > max_aqi) max_aqi = sub_aqi;
    
    // So sánh PM10
    sub_aqi = aqi_calc_pm10(data->pm10);
    if (sub_aqi > max_aqi) max_aqi = sub_aqi;
    
    // So sánh NO2
    sub_aqi = aqi_calc_no2(data->no2);
    if (sub_aqi > max_aqi) max_aqi = sub_aqi;
    
    // So sánh SO2
    sub_aqi = aqi_calc_so2(data->so2);
    if (sub_aqi > max_aqi) max_aqi = sub_aqi;
    
    // So sánh O3
    sub_aqi = aqi_calc_o3(data->o3);
    if (sub_aqi > max_aqi) max_aqi = sub_aqi;

    return (uint32_t)max_aqi;
}

threshold_level_t get_aqi_level(int32_t val) {
    if (val <= 50) return LEVEL_GOOD;
    if (val <= 100) return LEVEL_MODERATE;
    if (val <= 150) return LEVEL_UNHEALTHY_SENSITIVE;
    if (val <= 200) return LEVEL_UNHEALTHY;
    if (val <= 300) return LEVEL_VERY_UNHEALTHY;
    return LEVEL_HAZARDOUS;
}

// Logic phân loại nhiệt độ dựa trên mức độ thoải mái của con người
threshold_level_t get_temp_level(int32_t val) {
    int32_t celsius = val / 10;
    if (celsius >= 20 && celsius <= 25) return LEVEL_GOOD;
    if ((celsius >= 18 && celsius < 20) || (celsius > 25 && celsius <= 28)) return LEVEL_MODERATE;
    if ((celsius >= 15 && celsius < 18) || (celsius > 28 && celsius <= 32)) return LEVEL_UNHEALTHY_SENSITIVE;
    if ((celsius >= 10 && celsius < 15) || (celsius > 32 && celsius <= 38)) return LEVEL_UNHEALTHY;
    if ((celsius >= 5 && celsius < 10) || (celsius > 38 && celsius <= 45)) return LEVEL_VERY_UNHEALTHY;
    return LEVEL_HAZARDOUS;
}

// Logic phân loại độ ẩm dựa trên chuẩn y tế và chống nấm mốc
threshold_level_t get_humi_level(int32_t val) {
    int32_t rh = val / 10;
    if (rh >= 40 && rh <= 60) return LEVEL_GOOD;
    if ((rh >= 30 && rh < 40) || (rh > 60 && rh <= 70)) return LEVEL_MODERATE;
    if ((rh >= 20 && rh < 30) || (rh > 70 && rh <= 80)) return LEVEL_UNHEALTHY_SENSITIVE;
    if ((rh >= 10 && rh < 20) || (rh > 80 && rh <= 90)) return LEVEL_UNHEALTHY;
    if ((rh >= 5 && rh < 10) || (rh > 90 && rh <= 95)) return LEVEL_VERY_UNHEALTHY;
    return LEVEL_HAZARDOUS;
}

// Logic đánh giá khí CO tích tụ trong không gian kín
threshold_level_t get_co_level(int32_t val) {
    int32_t ppm = val / 10;
    if (ppm <= 600) return LEVEL_GOOD;            // Tươi mới
    if (ppm <= 1000) return LEVEL_MODERATE;       // Mức văn phòng bình thường
    if (ppm <= 1500) return LEVEL_UNHEALTHY_SENSITIVE; // Hơi ngột ngạt
    if (ppm <= 2000) return LEVEL_UNHEALTHY;      // Bắt đầu nhức đầu, buồn ngủ
    if (ppm <= 5000) return LEVEL_VERY_UNHEALTHY; // Mức nguy hiểm cho lao động kéo dài
    return LEVEL_HAZARDOUS;
}
