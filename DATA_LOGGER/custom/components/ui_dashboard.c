#include "ui_dashboard.h"
#include "gui_guider.h"
#include <stdio.h>

#include "ui_test_data.h"


/* --- COLORS --- */
#define DASH_COLOR_GOOD                 0x00E400 // EPA Green
#define DASH_COLOR_MODERATE             0xFFFF00 // EPA Yellow
#define DASH_COLOR_UNHEALTHY_SENSITIVE  0xFF7E00 // EPA Orange
#define DASH_COLOR_UNHEALTHY            0xFF0000 // EPA Red
#define DASH_COLOR_VERY_UNHEALTHY       0x8F3F97 // EPA Purple
#define DASH_COLOR_HAZARDOUS            0x7E0023 // EPA Maroon
#define DASH_COLOR_DEFAULT              0xFFFFFF // White

/* --- THRESHOLDS --- */
#define DASH_TH_AQI_GOOD            50
#define DASH_TH_AQI_MODERATE        100
#define DASH_TH_AQI_UNHEALTHY       300

#define DASH_TH_PM25_GOOD           12
#define DASH_TH_PM25_MODERATE       35
#define DASH_TH_PM25_UNHEALTHY      150

#define DASH_TH_PM10_GOOD           54
#define DASH_TH_PM10_MODERATE       154
#define DASH_TH_PM10_UNHEALTHY      354

#define DASH_TH_TEMP_C_COOL_MAX     14
#define DASH_TH_TEMP_C_GOOD_MAX     35

#define DASH_TH_HUMI_DRY_MAX        29
#define DASH_TH_HUMI_GOOD_MAX       60

#define DASH_TH_CO2_GOOD            1000
#define DASH_TH_CO2_MODERATE        2000

#define DASH_TH_GAS_GOOD            50
#define DASH_TH_GAS_MODERATE        100

typedef enum {
    LEVEL_GOOD = 0,
    LEVEL_MODERATE,
    LEVEL_UNHEALTHY_SENSITIVE,
    LEVEL_UNHEALTHY,
    LEVEL_VERY_UNHEALTHY,
    LEVEL_HAZARDOUS
} threshold_level_t;

typedef struct {
    int32_t aqi;
    int32_t pm10;
    int32_t pm25;
    int32_t temp;
    int32_t humi;
    int32_t no2;
    int32_t o3;
    int32_t co2;
    int32_t so2;
} ui_dashboard_state_t;

static ui_dashboard_state_t s_dash_state = {0};
static void recalculate_overall_aqi(void);

void ui_dashboard_init(void)
{
    // Inject random test data to simulate sensors
    ui_test_inject_random_dashboard_data();
}

// EPA AQI Breakpoints structure
typedef struct {
    int32_t c_low;
    int32_t c_high;
    int32_t i_low;
    int32_t i_high;
} aqi_bp_t;

// Note: Values are scaled by 10 because frontend stores them with 1 decimal point (e.g. 12.3 is 123)
static const aqi_bp_t bp_pm25[] = {
    {0, 90, 0, 50}, {91, 354, 51, 100}, {355, 554, 101, 150},
    {555, 1254, 151, 200}, {1255, 2254, 201, 300}, {2255, 3254, 301, 400}, {3255, 5004, 401, 500}
};

static const aqi_bp_t bp_pm10[] = {
    {0, 540, 0, 50}, {550, 1540, 51, 100}, {1550, 2540, 101, 150},
    {2550, 3540, 151, 200}, {3550, 4240, 201, 300}, {4250, 5040, 301, 400}, {5050, 6040, 401, 500}
};

static const aqi_bp_t bp_no2[] = {
    {0, 530, 0, 50}, {540, 1000, 51, 100}, {1010, 3600, 101, 150},
    {3610, 6490, 151, 200}, {6500, 12490, 201, 300}, {12500, 16490, 301, 400}, {16500, 20490, 401, 500}
};

static const aqi_bp_t bp_so2[] = {
    {0, 350, 0, 50}, {360, 750, 51, 100}, {760, 1850, 101, 150},
    {1860, 3040, 151, 200}, {3050, 6040, 201, 300}, {6050, 8040, 301, 400}, {8050, 10040, 401, 500}
};

static const aqi_bp_t bp_o3[] = {
    {0, 540, 0, 50}, {550, 700, 51, 100}, {1250, 1640, 101, 150},
    {1650, 2040, 151, 200}, {2050, 4040, 201, 300}, {4050, 5040, 301, 400}, {5050, 6040, 401, 500}
};

static int32_t calc_aqi_subindex(int32_t val, const aqi_bp_t *table, size_t size) {
    if (val < 0) return 0;
    
    // Find the matching range
    for (size_t i = 0; i < size; i++) {
        if (val >= table[i].c_low && val <= table[i].c_high) {
            int32_t c_diff = table[i].c_high - table[i].c_low;
            if (c_diff == 0) return table[i].i_low; // prevent div by zero
            return ((table[i].i_high - table[i].i_low) * (val - table[i].c_low)) / c_diff + table[i].i_low;
        }
    }
    
    // Extrapolate if exceeding max EPA table value
    const aqi_bp_t *last = &table[size - 1];
    int32_t c_diff = last->c_high - last->c_low;
    if (c_diff == 0) return last->i_high;
    return ((last->i_high - last->i_low) * (val - last->c_low)) / c_diff + last->i_low;
}

static void recalculate_overall_aqi(void) {
    int32_t max_aqi = 0;
    int32_t sub_aqi = 0;

    sub_aqi = calc_aqi_subindex(s_dash_state.pm25, bp_pm25, sizeof(bp_pm25)/sizeof(bp_pm25[0]));
    if (sub_aqi > max_aqi) max_aqi = sub_aqi;
    
    sub_aqi = calc_aqi_subindex(s_dash_state.pm10, bp_pm10, sizeof(bp_pm10)/sizeof(bp_pm10[0]));
    if (sub_aqi > max_aqi) max_aqi = sub_aqi;
    
    sub_aqi = calc_aqi_subindex(s_dash_state.no2, bp_no2, sizeof(bp_no2)/sizeof(bp_no2[0]));
    if (sub_aqi > max_aqi) max_aqi = sub_aqi;
    
    sub_aqi = calc_aqi_subindex(s_dash_state.so2, bp_so2, sizeof(bp_so2)/sizeof(bp_so2[0]));
    if (sub_aqi > max_aqi) max_aqi = sub_aqi;
    
    sub_aqi = calc_aqi_subindex(s_dash_state.o3, bp_o3, sizeof(bp_o3)/sizeof(bp_o3[0]));
    if (sub_aqi > max_aqi) max_aqi = sub_aqi;

    s_dash_state.aqi = max_aqi;
}

static threshold_level_t get_aqi_level(int32_t val) {
    if (val <= 50) return LEVEL_GOOD;
    if (val <= 100) return LEVEL_MODERATE;
    if (val <= 150) return LEVEL_UNHEALTHY_SENSITIVE;
    if (val <= 200) return LEVEL_UNHEALTHY;
    if (val <= 300) return LEVEL_VERY_UNHEALTHY;
    return LEVEL_HAZARDOUS;
}

static threshold_level_t get_temp_level(int32_t val) {
    int32_t celsius = val / 10;
    if (celsius <= DASH_TH_TEMP_C_COOL_MAX) return LEVEL_MODERATE; // Cool
    if (celsius <= DASH_TH_TEMP_C_GOOD_MAX) return LEVEL_GOOD;
    return LEVEL_UNHEALTHY; // Hot
}

static threshold_level_t get_humi_level(int32_t val) {
    int32_t real_val = val / 10;
    if (real_val <= DASH_TH_HUMI_DRY_MAX) return LEVEL_MODERATE; // Dry
    if (real_val <= DASH_TH_HUMI_GOOD_MAX) return LEVEL_GOOD;
    return LEVEL_UNHEALTHY; // Wet
}

static threshold_level_t get_co2_level(int32_t val) {
    int32_t real_val = val / 10;
    if (real_val <= DASH_TH_CO2_GOOD) return LEVEL_GOOD;
    if (real_val <= DASH_TH_CO2_MODERATE) return LEVEL_MODERATE;
    return LEVEL_UNHEALTHY;
}


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

static void format_decimal(char *buf, size_t buf_size, int32_t val) {
    int32_t whole = (val < 0 ? -val : val) / 10;
    int32_t frac = (val < 0 ? -val : val) % 10;
    snprintf(buf, buf_size, "%s%d.%d", (val < 0) ? "-" : "", (int)whole, (int)frac);
}

static void apply_dashboard_label(lv_obj_t *val_lbl, lv_obj_t *status_lbl, const char *val_str, threshold_level_t level) {
    if (val_lbl) {
        lv_label_set_text(val_lbl, val_str);
        lv_obj_set_style_text_color(val_lbl, color_from_level(level), LV_PART_MAIN | LV_STATE_DEFAULT);
    }
    if (status_lbl) {
        lv_label_set_long_mode(status_lbl, LV_LABEL_LONG_SCROLL_CIRCULAR);
        lv_label_set_text(status_lbl, status_text_from_level(level));
        lv_obj_set_style_text_color(status_lbl, color_from_level(level), LV_PART_MAIN | LV_STATE_DEFAULT);
    }
}

void ui_dashboard_apply_json(cJSON *root) {
    if (!root) return;

    cJSON *item;
    
    item = cJSON_GetObjectItem(root, "aqi");
    if (item && cJSON_IsNumber(item)) s_dash_state.aqi = item->valueint;

    item = cJSON_GetObjectItem(root, "pm10");
    if (item && cJSON_IsNumber(item)) s_dash_state.pm10 = item->valueint;

    item = cJSON_GetObjectItem(root, "pm25");
    if (item && cJSON_IsNumber(item)) s_dash_state.pm25 = item->valueint;

    item = cJSON_GetObjectItem(root, "temp");
    if (item && cJSON_IsNumber(item)) s_dash_state.temp = item->valueint;

    item = cJSON_GetObjectItem(root, "humi");
    if (item && cJSON_IsNumber(item)) s_dash_state.humi = item->valueint;

    item = cJSON_GetObjectItem(root, "no2");
    if (item && cJSON_IsNumber(item)) s_dash_state.no2 = item->valueint;

    item = cJSON_GetObjectItem(root, "o3");
    if (item && cJSON_IsNumber(item)) s_dash_state.o3 = item->valueint;

    item = cJSON_GetObjectItem(root, "co2");
    if (item && cJSON_IsNumber(item)) s_dash_state.co2 = item->valueint;

    item = cJSON_GetObjectItem(root, "so2");
    if (item && cJSON_IsNumber(item)) s_dash_state.so2 = item->valueint;

    // Automatically calculate and override AQI based on the updated measurements
    recalculate_overall_aqi();
}

void ui_dashboard_render(bool is_active)
{
    if (!is_active) return;
    
    // We access the global generated UI context directly.
    lv_ui *g = &guider_ui;
    char buf[16];

    // AQI Arc
    if (g->scr_base_arc_aqi) {
        lv_color_t color = color_from_level(get_aqi_level(s_dash_state.aqi));
        lv_arc_set_value(g->scr_base_arc_aqi, s_dash_state.aqi);
        lv_obj_set_style_arc_color(g->scr_base_arc_aqi, color, LV_PART_INDICATOR | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_color(g->scr_base_arc_aqi, color, LV_PART_KNOB | LV_STATE_DEFAULT);
    }

    // AQI
    snprintf(buf, sizeof(buf), "%d", (int)s_dash_state.aqi);
    apply_dashboard_label(g->scr_base_lbl_aqi_val, g->scr_base_lbl_Aqi_status, buf, get_aqi_level(s_dash_state.aqi));

    // PM10
    format_decimal(buf, sizeof(buf), s_dash_state.pm10);
    apply_dashboard_label(g->scr_base_lbl_pm10_val, g->scr_base_lbl_pm10_status, buf, get_aqi_level(calc_aqi_subindex(s_dash_state.pm10, bp_pm10, sizeof(bp_pm10)/sizeof(bp_pm10[0]))));

    // PM2.5
    format_decimal(buf, sizeof(buf), s_dash_state.pm25);
    apply_dashboard_label(g->scr_base_lbl_pm25_val, g->scr_base_lbl_pm25_status, buf, get_aqi_level(calc_aqi_subindex(s_dash_state.pm25, bp_pm25, sizeof(bp_pm25)/sizeof(bp_pm25[0]))));

    // Temp (Has no status label)
    format_decimal(buf, sizeof(buf), s_dash_state.temp);
    apply_dashboard_label(g->scr_base_lbl_temp_val, NULL, buf, get_temp_level(s_dash_state.temp));

    // Humi (Has no status label)
    format_decimal(buf, sizeof(buf), s_dash_state.humi);
    apply_dashboard_label(g->scr_base_lbl_humi_val, NULL, buf, get_humi_level(s_dash_state.humi));

    // NO2
    format_decimal(buf, sizeof(buf), s_dash_state.no2);
    apply_dashboard_label(g->scr_base_lbl_no2_val, NULL, buf, get_aqi_level(calc_aqi_subindex(s_dash_state.no2, bp_no2, sizeof(bp_no2)/sizeof(bp_no2[0]))));

    // O3 (Notice the typo in generated code: scr_base_lbl_03_val)
    format_decimal(buf, sizeof(buf), s_dash_state.o3);
    apply_dashboard_label(g->scr_base_lbl_03_val, NULL, buf, get_aqi_level(calc_aqi_subindex(s_dash_state.o3, bp_o3, sizeof(bp_o3)/sizeof(bp_o3[0]))));

    // CO2
    format_decimal(buf, sizeof(buf), s_dash_state.co2);
    apply_dashboard_label(g->scr_base_lbl_co2_val, NULL, buf, get_co2_level(s_dash_state.co2));

    // SO2
    format_decimal(buf, sizeof(buf), s_dash_state.so2);
    apply_dashboard_label(g->scr_base_lbl_so2_val, NULL, buf, get_aqi_level(calc_aqi_subindex(s_dash_state.so2, bp_so2, sizeof(bp_so2)/sizeof(bp_so2[0]))));
}
