#include "cmp_dashboard.h"
#include "gui_guider.h"
#include <stdio.h>

#include "ui_test_data.h"
#include "ui_app_param_bridge.h"
#include "ui_helpers.h"


/* --- BẢNG MÀU EPA CHUẨN --- */
#define DASH_COLOR_GOOD                 0x00E400 // Xanh lá: Tốt
#define DASH_COLOR_MODERATE             0xFFFF00 // Vàng: Trung bình
#define DASH_COLOR_UNHEALTHY_SENSITIVE  0xFF7E00 // Cam: Kém (người nhạy cảm)
#define DASH_COLOR_UNHEALTHY            0xFF0000 // Đỏ: Xấu
#define DASH_COLOR_VERY_UNHEALTHY       0x8F3F97 // Tím: Rất xấu
#define DASH_COLOR_HAZARDOUS            0x7E0023 // Nâu đỏ: Nguy hiểm
#define DASH_COLOR_DEFAULT              0xFFFFFF // Trắng (Chưa có dữ liệu)


/**
 * @struct cmp_dashboard_state_t
 * @brief Bộ nhớ đệm (Cache) lưu trữ trạng thái hiện tại của Dashboard.
 * Thiết kế theo cơ chế: Nhận dữ liệu -> Tính toán -> Lưu Cache -> Vẽ (khi có yêu cầu)
 */
typedef struct {
    int32_t aqi;
    threshold_level_t aqi_level;
    int32_t pm10;
    threshold_level_t pm10_level;
    int32_t pm25;
    threshold_level_t pm25_level;
    int32_t temp;
    threshold_level_t temp_level;
    int32_t humi;
    threshold_level_t humi_level;
    int32_t no2;
    threshold_level_t no2_level;
    int32_t o3;
    threshold_level_t o3_level;
    int32_t co;
    threshold_level_t co_level;
    int32_t so2;
    threshold_level_t so2_level;
} cmp_dashboard_state_t;

static cmp_dashboard_state_t s_dash_state = {0};


void cmp_dashboard_init(void)
{
#ifndef _WIN32
    // Chạy mạch thật: Kích hoạt cầu nối lấy dữ liệu từ Backend
    ui_app_param_bridge_start();
#else
    // Chạy Simulator PC: Dùng data giả ngẫu nhiên
    ui_test_inject_random_dashboard_data();
#endif
}


/**
 * @brief Chuyển đổi từ Mức cảnh báo (Level) sang Màu sắc hiển thị
 */
static lv_color_t color_from_level(threshold_level_t level) {
    switch (level) {
        case LEVEL_GOOD: return lv_color_hex(DASH_COLOR_GOOD);
        case LEVEL_MODERATE: return lv_color_hex(DASH_COLOR_MODERATE);
        case LEVEL_UNHEALTHY_SENSITIVE: return lv_color_hex(DASH_COLOR_UNHEALTHY_SENSITIVE);
        case LEVEL_UNHEALTHY: return lv_color_hex(DASH_COLOR_UNHEALTHY);
        case LEVEL_VERY_UNHEALTHY: return lv_color_hex(DASH_COLOR_VERY_UNHEALTHY);
        case LEVEL_HAZARDOUS: return lv_color_hex(DASH_COLOR_HAZARDOUS);
        default: return lv_color_hex(DASH_COLOR_DEFAULT);
    }
}

/**
 * @brief Chuyển đổi từ Mức cảnh báo (Level) sang Chữ cảnh báo
 */
static const char* status_text_from_level(threshold_level_t level) {
    switch (level) {
        case LEVEL_GOOD: return "GOOD";
        case LEVEL_MODERATE: return "MODERATE";
        case LEVEL_UNHEALTHY_SENSITIVE: return "UNHEALTHY (SG)";
        case LEVEL_UNHEALTHY: return "UNHEALTHY";
        case LEVEL_VERY_UNHEALTHY: return "VERY UNHEALTHY";
        case LEVEL_HAZARDOUS: return "HAZARDOUS";
        default: return "UNKNOWN";
    }
}



/**
 * @brief Hàm trợ giúp: Đổ màu và điền chữ cho cặp Widget (Thông số & Cảnh báo)
 */
static void apply_dashboard_label(lv_obj_t *val_lbl, lv_obj_t *status_lbl, const char *val_str, threshold_level_t level) {
    if (val_lbl) {
        lv_label_set_text(val_lbl, val_str);
        lv_obj_set_style_text_color(val_lbl, color_from_level(level), LV_PART_MAIN | LV_STATE_DEFAULT);
    }
    if (status_lbl) {
        // Cho chữ tự động chạy ngang (marquee) nếu quá dài
        lv_label_set_long_mode(status_lbl, LV_LABEL_LONG_SCROLL_CIRCULAR);
        lv_label_set_text(status_lbl, status_text_from_level(level));
        lv_obj_set_style_text_color(status_lbl, color_from_level(level), LV_PART_MAIN | LV_STATE_DEFAULT);
    }
}


void cmp_dashboard_apply_data(const ui_sensor_data_t *data) {
    if (!data) return;

    // Chỉ nhận dữ liệu thô, gửi sang tầng Domain (aqi_service) để tính toán màu/level, 
    // sau đó lưu vào Cache cục bộ. (Chưa vẽ lên màn hình)
    
    s_dash_state.pm10 = data->pm10;
    s_dash_state.pm10_level = get_aqi_level(aqi_calc_pm10(data->pm10));

    s_dash_state.pm25 = data->pm25;
    s_dash_state.pm25_level = get_aqi_level(aqi_calc_pm25(data->pm25));

    s_dash_state.temp = data->temp;
    s_dash_state.temp_level = get_temp_level(data->temp);

    s_dash_state.humi = data->humi;
    s_dash_state.humi_level = get_humi_level(data->humi);

    s_dash_state.no2 = data->no2;
    s_dash_state.no2_level = get_aqi_level(aqi_calc_no2(data->no2));

    s_dash_state.o3 = data->o3;
    s_dash_state.o3_level = get_aqi_level(aqi_calc_o3(data->o3));

    s_dash_state.co = data->co;
    s_dash_state.co_level = get_co_level(data->co);

    s_dash_state.so2 = data->so2;
    s_dash_state.so2_level = get_aqi_level(aqi_calc_so2(data->so2));

    // AQI nhận trực tiếp từ Backend (hoặc random) - không tự tính nữa
    s_dash_state.aqi = data->aqi;
    s_dash_state.aqi_level = get_aqi_level(s_dash_state.aqi);
}

void cmp_dashboard_render(bool is_active)
{
    // Nếu màn hình này không hiển thị, cấm vẽ để tiết kiệm 100% CPU
    if (!is_active) return;
    
    // Sử dụng biến cục bộ sinh bởi GUI Guider (để không phải map từng widget tay)
    lv_ui *g = &guider_ui;
    char buf[16];

    // Cập nhật Vòng cung AQI (Arc)
    if (g->scr_base_arc_aqi) {
        lv_color_t color = color_from_level(s_dash_state.aqi_level);
        lv_arc_set_value(g->scr_base_arc_aqi, s_dash_state.aqi);
        lv_obj_set_style_arc_color(g->scr_base_arc_aqi, color, LV_PART_INDICATOR | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_color(g->scr_base_arc_aqi, color, LV_PART_KNOB | LV_STATE_DEFAULT);
    }

    // AQI (Giá trị nguyên)
    snprintf(buf, sizeof(buf), "%d", (int)s_dash_state.aqi);
    apply_dashboard_label(g->scr_base_lbl_aqi_val, g->scr_base_lbl_Aqi_status, buf, s_dash_state.aqi_level);

    // PM10 (Giá trị thập phân chia 10)
    ui_format_decimal(buf, sizeof(buf), s_dash_state.pm10);
    apply_dashboard_label(g->scr_base_lbl_pm10_val, g->scr_base_lbl_pm10_status, buf, s_dash_state.pm10_level);

    // PM2.5
    ui_format_decimal(buf, sizeof(buf), s_dash_state.pm25);
    apply_dashboard_label(g->scr_base_lbl_pm25_val, g->scr_base_lbl_pm25_status, buf, s_dash_state.pm25_level);

    // Nhiệt độ (Không có nhãn trạng thái đi kèm)
    ui_format_decimal(buf, sizeof(buf), s_dash_state.temp);
    apply_dashboard_label(g->scr_base_lbl_temp_val, NULL, buf, s_dash_state.temp_level);

    // Độ ẩm (Không có nhãn trạng thái đi kèm)
    ui_format_decimal(buf, sizeof(buf), s_dash_state.humi);
    apply_dashboard_label(g->scr_base_lbl_humi_val, NULL, buf, s_dash_state.humi_level);

    // NO2
    ui_format_decimal(buf, sizeof(buf), s_dash_state.no2);
    apply_dashboard_label(g->scr_base_lbl_no2_val, NULL, buf, s_dash_state.no2_level);

    // O3 
    ui_format_decimal(buf, sizeof(buf), s_dash_state.o3);
    apply_dashboard_label(g->scr_base_lbl_o3_val, NULL, buf, s_dash_state.o3_level);

    // CO
    ui_format_decimal(buf, sizeof(buf), s_dash_state.co);
    apply_dashboard_label(g->scr_base_lbl_co_val, NULL, buf, s_dash_state.co_level);

    // SO2
    ui_format_decimal(buf, sizeof(buf), s_dash_state.so2);
    apply_dashboard_label(g->scr_base_lbl_so2_val, NULL, buf, s_dash_state.so2_level);
}
