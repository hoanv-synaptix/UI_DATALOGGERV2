/*
* Copyright 2026 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#ifndef GUI_GUIDER_H
#define GUI_GUIDER_H
#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl.h"


typedef struct
{
  
	lv_obj_t *scr_booting;
	bool scr_booting_del;
	lv_obj_t *scr_booting_bar_1;
	lv_obj_t *scr_booting_label_1;
	lv_obj_t *scr_booting_img_1;
	lv_obj_t *scr_dashboard;
	bool scr_dashboard_del;
	lv_obj_t *scr_dashboard_img_bg;
	lv_obj_t *scr_dashboard_date_val;
	lv_obj_t *scr_dashboard_time_val;
	lv_obj_t *scr_dashboard_img_net_on;
	lv_obj_t *scr_dashboard_img_net_off;
	lv_obj_t *scr_dashboard_img_mqtt_off;
	lv_obj_t *scr_dashboard_img_mqtt_on;
	lv_obj_t *scr_dashboard_btn_dashboard;
	lv_obj_t *scr_dashboard_btn_dashboard_label;
	lv_obj_t *scr_dashboard_btn_analystis;
	lv_obj_t *scr_dashboard_btn_analystis_label;
	lv_obj_t *scr_dashboard_btn_event_logs;
	lv_obj_t *scr_dashboard_btn_event_logs_label;
	lv_obj_t *scr_dashboard_btn_settings;
	lv_obj_t *scr_dashboard_btn_settings_label;
	lv_obj_t *scr_dashboard_btn_restart;
	lv_obj_t *scr_dashboard_btn_restart_label;
	lv_obj_t *scr_dashboard_cont_dashboard;
	lv_obj_t *scr_dashboard_lbl_dashboard;
	lv_obj_t *scr_dashboard_cont_aqi;
	lv_obj_t *scr_dashboard_lbl_aqi;
	lv_obj_t *scr_dashboard_lbl_aqi_val;
	lv_obj_t *scr_dashboard_arc_aqi;
	lv_obj_t *scr_dashboard_cont_aqi_status;
	lv_obj_t *scr_dashboard_lbl_Aqi_status;
	lv_obj_t *scr_dashboard_cont_pm10;
	lv_obj_t *scr_dashboard_lbl_pm10;
	lv_obj_t *scr_dashboard_lbl_pm10_val;
	lv_obj_t *scr_dashboard_lbl_pm10_unit;
	lv_obj_t *scr_dashboard_cont_pm10_status;
	lv_obj_t *scr_dashboard_lbl_pm10_status;
	lv_obj_t *scr_dashboard_cont_pm25;
	lv_obj_t *scr_dashboard_lbl_pm25;
	lv_obj_t *scr_dashboard_lbl_pm25_val;
	lv_obj_t *scr_dashboard_lbl_pm25_uint;
	lv_obj_t *scr_dashboard_cont_status;
	lv_obj_t *scr_dashboard_lbl_status;
	lv_obj_t *scr_dashboard_cont_21;
	lv_obj_t *scr_dashboard_lbl_temp;
	lv_obj_t *scr_dashboard_lbl_temp_val;
	lv_obj_t *scr_dashboard_lbl_temp_unit;
	lv_obj_t *scr_dashboard_img_temp;
	lv_obj_t *scr_dashboard_cont_humi;
	lv_obj_t *scr_dashboard_lbl_humi;
	lv_obj_t *scr_dashboard_lbl_humi_val;
	lv_obj_t *scr_dashboard_lbl_humi_unit;
	lv_obj_t *scr_dashboard_img_humi;
	lv_obj_t *scr_dashboard_cont_no2;
	lv_obj_t *scr_dashboard_lbl_no2;
	lv_obj_t *scr_dashboard_lbl_no2_val;
	lv_obj_t *scr_dashboard_lbl_no2_unit;
	lv_obj_t *scr_dashboard_cont_o3;
	lv_obj_t *scr_dashboard_lbl_03;
	lv_obj_t *scr_dashboard_lbl_03_val;
	lv_obj_t *scr_dashboard_lbl_o3_unit;
	lv_obj_t *scr_dashboard_cont_co2;
	lv_obj_t *scr_dashboard_lbl_co2;
	lv_obj_t *scr_dashboard_lbl_co2_val;
	lv_obj_t *scr_dashboard_lbl_co2_unit;
	lv_obj_t *scr_dashboard_cont_so2;
	lv_obj_t *scr_dashboard_lbl_so2;
	lv_obj_t *scr_dashboard_lbl_so2_val;
	lv_obj_t *scr_dashboard_lbl_so2_unit;
	lv_obj_t *scr_dashboard_cont_data_analysis;
	lv_obj_t *scr_dashboard_label_analysis;
	lv_obj_t *scr_dashboard_cont_trends;
	lv_obj_t *scr_dashboard_cont_chart;
	lv_obj_t *scr_dashboard_chart;
	lv_chart_series_t *scr_dashboard_chart_0;
	lv_chart_series_t *scr_dashboard_chart_1;
	lv_chart_series_t *scr_dashboard_chart_2;
	lv_obj_t *scr_dashboard_label_trends;
	lv_obj_t *scr_dashboard_ddlist_trends;
	lv_obj_t *scr_dashboard_cont_avg;
	lv_obj_t *scr_dashboard_lbl_avg;
	lv_obj_t *scr_dashboard_label_avg_val;
	lv_obj_t *scr_dashboard_cont_insights;
	lv_obj_t *scr_dashboard_btn_generate_report;
	lv_obj_t *scr_dashboard_btn_generate_report_label;
	lv_obj_t *scr_dashboard_label_insights;
	lv_obj_t *scr_dashboard_lbl_advice;
	lv_obj_t *scr_dashboard_cont_event_logs;
	lv_obj_t *scr_dashboard_lbl_event_logs;
	lv_obj_t *scr_dashboard_cont_logs;
	lv_obj_t *scr_dashboard_lbl_critical_logs;
	lv_obj_t *scr_dashboard_btn_clear_history;
	lv_obj_t *scr_dashboard_btn_clear_history_label;
	lv_obj_t *scr_dashboard_cont_logs_detail;
	lv_obj_t *scr_dashboard_lbl_log_detail;
	lv_obj_t *scr_dashboard_cont_restart;
	lv_obj_t *scr_dashboard_cont_restart_system;
	lv_obj_t *scr_dashboard_img_12;
	lv_obj_t *scr_dashboard_label_95;
	lv_obj_t *scr_dashboard_label_96;
	lv_obj_t *scr_dashboard_btn_restart_confirm;
	lv_obj_t *scr_dashboard_btn_restart_confirm_label;
	lv_obj_t *scr_dashboard_btn_restart_cancel;
	lv_obj_t *scr_dashboard_btn_restart_cancel_label;
	lv_obj_t *scr_dashboard_cont_restore;
	lv_obj_t *scr_dashboard_cont_31;
	lv_obj_t *scr_dashboard_img_13;
	lv_obj_t *scr_dashboard_label_98;
	lv_obj_t *scr_dashboard_label_97;
	lv_obj_t *scr_dashboard_btn_restore_confirm;
	lv_obj_t *scr_dashboard_btn_restore_confirm_label;
	lv_obj_t *scr_dashboard_btn_restore_cancel;
	lv_obj_t *scr_dashboard_btn_restore_cancel_label;
}lv_ui;

typedef void (*ui_setup_scr_t)(lv_ui * ui);

void ui_init_style(lv_style_t * style);

void ui_load_scr_animation(lv_ui *ui, lv_obj_t ** new_scr, bool new_scr_del, bool * old_scr_del, ui_setup_scr_t setup_scr,
                           lv_screen_load_anim_t anim_type, uint32_t time, uint32_t delay, bool is_clean, bool auto_del);

void ui_animation(void * var, uint32_t duration, int32_t delay, int32_t start_value, int32_t end_value, lv_anim_path_cb_t path_cb,
                  uint32_t repeat_cnt, uint32_t repeat_delay, uint32_t playback_time, uint32_t playback_delay,
                  lv_anim_exec_xcb_t exec_cb, lv_anim_start_cb_t start_cb, lv_anim_completed_cb_t ready_cb, lv_anim_deleted_cb_t deleted_cb);


void init_scr_del_flag(lv_ui *ui);

void setup_bottom_layer(void);

void setup_ui(lv_ui *ui);

void video_play(lv_ui *ui);

void init_keyboard(lv_ui *ui);

extern lv_ui guider_ui;


void setup_scr_scr_booting(lv_ui *ui);
void setup_scr_scr_dashboard(lv_ui *ui);
LV_IMAGE_DECLARE(_logo_boot_RGB565A8_256x65);
LV_IMAGE_DECLARE(_bg_settings_base_RGB565A8_800x480);
LV_IMAGE_DECLARE(_wifi_on_RGB565A8_16x16);
LV_IMAGE_DECLARE(_wifi_off_RGB565A8_16x16);
LV_IMAGE_DECLARE(_mqtt_off_RGB565A8_16x16);
LV_IMAGE_DECLARE(_mqtt_on_RGB565A8_16x16);
LV_IMAGE_DECLARE(_weather_RGB565A8_32x32);
LV_IMAGE_DECLARE(_humidity_RGB565A8_32x32);
LV_IMAGE_DECLARE(_power_button_RGB565A8_100x100);
LV_IMAGE_DECLARE(_power_RGB565A8_100x100);

LV_FONT_DECLARE(lv_font_montserratMedium_16)
LV_FONT_DECLARE(lv_font_Roboto_Bold_10)
LV_FONT_DECLARE(lv_font_Roboto_Bold_9)
LV_FONT_DECLARE(lv_font_montserratMedium_12)
LV_FONT_DECLARE(lv_font_Roboto_Black_10)
LV_FONT_DECLARE(lv_font_Roboto_Black_12)
LV_FONT_DECLARE(lv_font_Roboto_Black_72)
LV_FONT_DECLARE(lv_font_Roboto_Black_30)
LV_FONT_DECLARE(lv_font_Roboto_Black_20)
LV_FONT_DECLARE(lv_font_Roboto_Black_48)
LV_FONT_DECLARE(lv_font_Roboto_Black_11)
LV_FONT_DECLARE(lv_font_Roboto_Black_24)
LV_FONT_DECLARE(lv_font_Roboto_Black_9)
LV_FONT_DECLARE(lv_font_Roboto_Black_16)
LV_FONT_DECLARE(lv_font_Roboto_Bold_12)
LV_FONT_DECLARE(lv_font_Roboto_Bold_40)
LV_FONT_DECLARE(lv_font_Roboto_Regular_12)
LV_FONT_DECLARE(lv_font_Roboto_Regular_14)


#ifdef __cplusplus
}
#endif
#endif
