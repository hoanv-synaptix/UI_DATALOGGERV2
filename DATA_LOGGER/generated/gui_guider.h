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
	lv_obj_t *scr_dashboard_img_1;
	lv_obj_t *scr_dashboard_label_1;
	lv_obj_t *scr_dashboard_datetext_1;
	lv_obj_t *scr_dashboard_digital_clock_1;
	lv_obj_t *scr_dashboard_cont_1;
	lv_obj_t *scr_dashboard_label_2;
	lv_obj_t *scr_dashboard_cont_2;
	lv_obj_t *scr_dashboard_label_4;
	lv_obj_t *scr_dashboard_cont_3;
	lv_obj_t *scr_dashboard_label_3;
	lv_obj_t *scr_dashboard_arc_1;
	lv_obj_t *scr_dashboard_cont_4;
	lv_obj_t *scr_dashboard_label_5;
	lv_obj_t *scr_dashboard_label_13;
	lv_obj_t *scr_dashboard_cont_12;
	lv_obj_t *scr_dashboard_label_14;
	lv_obj_t *scr_dashboard_label_15;
	lv_obj_t *scr_dashboard_cont_8;
	lv_obj_t *scr_dashboard_label_22;
	lv_obj_t *scr_dashboard_label_21;
	lv_obj_t *scr_dashboard_label_20;
	lv_obj_t *scr_dashboard_cont_13;
	lv_obj_t *scr_dashboard_label_19;
	lv_obj_t *scr_dashboard_label_18;
	lv_obj_t *scr_dashboard_cont_14;
	lv_obj_t *scr_dashboard_label_17;
	lv_obj_t *scr_dashboard_label_16;
	lv_obj_t *scr_dashboard_cont_15;
	lv_obj_t *scr_dashboard_label_25;
	lv_obj_t *scr_dashboard_label_24;
	lv_obj_t *scr_dashboard_label_23;
	lv_obj_t *scr_dashboard_cont_16;
	lv_obj_t *scr_dashboard_label_28;
	lv_obj_t *scr_dashboard_label_27;
	lv_obj_t *scr_dashboard_label_26;
	lv_obj_t *scr_dashboard_cont_17;
	lv_obj_t *scr_dashboard_label_31;
	lv_obj_t *scr_dashboard_label_30;
	lv_obj_t *scr_dashboard_label_29;
	lv_obj_t *scr_dashboard_cont_18;
	lv_obj_t *scr_dashboard_label_35;
	lv_obj_t *scr_dashboard_label_34;
	lv_obj_t *scr_dashboard_label_32;
	lv_obj_t *scr_dashboard_img_2;
	lv_obj_t *scr_dashboard_cont_19;
	lv_obj_t *scr_dashboard_label_38;
	lv_obj_t *scr_dashboard_label_37;
	lv_obj_t *scr_dashboard_label_36;
	lv_obj_t *scr_dashboard_img_3;
	lv_obj_t *scr_dashboard_img_4;
	lv_obj_t *scr_dashboard_img_5;
	lv_obj_t *scr_dashboard_img_6;
	lv_obj_t *scr_dashboard_img_7;
	lv_obj_t *scr_dashboard_btn_3;
	lv_obj_t *scr_dashboard_btn_3_label;
	lv_obj_t *scr_dashboard_btn_4;
	lv_obj_t *scr_dashboard_btn_4_label;
	lv_obj_t *scr_dashboard_btn_5;
	lv_obj_t *scr_dashboard_btn_5_label;
	lv_obj_t *scr_dashboard_btn_6;
	lv_obj_t *scr_dashboard_btn_6_label;
	lv_obj_t *scr_dashboard_btn_7;
	lv_obj_t *scr_dashboard_btn_7_label;
	lv_obj_t *scr_analysis;
	bool scr_analysis_del;
	lv_obj_t *scr_analysis_img_1;
	lv_obj_t *scr_analysis_label_1;
	lv_obj_t *scr_analysis_datetext_1;
	lv_obj_t *scr_analysis_digital_clock_1;
	lv_obj_t *scr_analysis_btn_5;
	lv_obj_t *scr_analysis_btn_5_label;
	lv_obj_t *scr_analysis_btn_4;
	lv_obj_t *scr_analysis_btn_4_label;
	lv_obj_t *scr_analysis_btn_3;
	lv_obj_t *scr_analysis_btn_3_label;
	lv_obj_t *scr_analysis_btn_2;
	lv_obj_t *scr_analysis_btn_2_label;
	lv_obj_t *scr_analysis_btn_1;
	lv_obj_t *scr_analysis_btn_1_label;
	lv_obj_t *scr_analysis_img_5;
	lv_obj_t *scr_analysis_img_4;
	lv_obj_t *scr_analysis_img_3;
	lv_obj_t *scr_analysis_img_2;
	lv_obj_t *scr_logs;
	bool scr_logs_del;
	lv_obj_t *scr_logs_img_1;
	lv_obj_t *scr_logs_label_1;
	lv_obj_t *scr_logs_datetext_1;
	lv_obj_t *scr_logs_digital_clock_1;
	lv_obj_t *scr_logs_btn_5;
	lv_obj_t *scr_logs_btn_5_label;
	lv_obj_t *scr_logs_btn_4;
	lv_obj_t *scr_logs_btn_4_label;
	lv_obj_t *scr_logs_btn_3;
	lv_obj_t *scr_logs_btn_3_label;
	lv_obj_t *scr_logs_btn_2;
	lv_obj_t *scr_logs_btn_2_label;
	lv_obj_t *scr_logs_btn_1;
	lv_obj_t *scr_logs_btn_1_label;
	lv_obj_t *scr_logs_img_5;
	lv_obj_t *scr_logs_img_4;
	lv_obj_t *scr_logs_img_3;
	lv_obj_t *scr_logs_img_2;
	lv_obj_t *scr_hw;
	bool scr_hw_del;
	lv_obj_t *scr_hw_img_1;
	lv_obj_t *scr_hw_label_1;
	lv_obj_t *scr_hw_datetext_1;
	lv_obj_t *scr_hw_digital_clock_1;
	lv_obj_t *scr_hw_btn_5;
	lv_obj_t *scr_hw_btn_5_label;
	lv_obj_t *scr_hw_btn_4;
	lv_obj_t *scr_hw_btn_4_label;
	lv_obj_t *scr_hw_btn_3;
	lv_obj_t *scr_hw_btn_3_label;
	lv_obj_t *scr_hw_btn_2;
	lv_obj_t *scr_hw_btn_2_label;
	lv_obj_t *scr_hw_btn_1;
	lv_obj_t *scr_hw_btn_1_label;
	lv_obj_t *scr_hw_img_5;
	lv_obj_t *scr_hw_img_4;
	lv_obj_t *scr_hw_img_3;
	lv_obj_t *scr_hw_img_2;
	lv_obj_t *scr_hw_cont_1;
	lv_obj_t *scr_hw_cont_2;
	lv_obj_t *scr_hw_label_2;
	lv_obj_t *scr_hw_label_3;
	lv_obj_t *scr_hw_img_6;
	lv_obj_t *scr_hw_btn_6;
	lv_obj_t *scr_hw_btn_6_label;
	lv_obj_t *scr_hw_cont_3;
	lv_obj_t *scr_hw_cont_4;
	lv_obj_t *scr_hw_label_5;
	lv_obj_t *scr_hw_label_4;
	lv_obj_t *scr_hw_img_7;
	lv_obj_t *scr_hw_btn_7;
	lv_obj_t *scr_hw_btn_7_label;
	lv_obj_t *scr_hw_cont_5;
	lv_obj_t *scr_hw_cont_6;
	lv_obj_t *scr_hw_label_7;
	lv_obj_t *scr_hw_label_6;
	lv_obj_t *scr_hw_img_8;
	lv_obj_t *scr_hw_btn_8;
	lv_obj_t *scr_hw_btn_8_label;
	lv_obj_t *scr_hw_cont_7;
	lv_obj_t *scr_hw_cont_8;
	lv_obj_t *scr_hw_label_9;
	lv_obj_t *scr_hw_label_8;
	lv_obj_t *scr_hw_img_9;
	lv_obj_t *scr_hw_btn_9;
	lv_obj_t *scr_hw_btn_9_label;
	lv_obj_t *scr_wifi;
	bool scr_wifi_del;
	lv_obj_t *scr_wifi_img_1;
	lv_obj_t *scr_wifi_HARDWARE;
	lv_obj_t *scr_wifi_datetext_1;
	lv_obj_t *scr_wifi_digital_clock_1;
	lv_obj_t *scr_wifi_btn_5;
	lv_obj_t *scr_wifi_btn_5_label;
	lv_obj_t *scr_wifi_btn_4;
	lv_obj_t *scr_wifi_btn_4_label;
	lv_obj_t *scr_wifi_btn_3;
	lv_obj_t *scr_wifi_btn_3_label;
	lv_obj_t *scr_wifi_btn_2;
	lv_obj_t *scr_wifi_btn_2_label;
	lv_obj_t *scr_wifi_btn_1;
	lv_obj_t *scr_wifi_btn_1_label;
	lv_obj_t *scr_wifi_img_5;
	lv_obj_t *scr_wifi_img_4;
	lv_obj_t *scr_wifi_img_3;
	lv_obj_t *scr_wifi_img_2;
	lv_obj_t *scr_wifi_cont_1;
	lv_obj_t *scr_wifi_img_6;
	lv_obj_t *scr_wifi_btn_6;
	lv_obj_t *scr_wifi_btn_6_label;
	lv_obj_t *scr_wifi_label_1;
	lv_obj_t *scr_wifi_cont_2;
	lv_obj_t *scr_wifi_cont_3;
	lv_obj_t *scr_wifi_label_2;
	lv_obj_t *scr_wifi_ta_1;
	lv_obj_t *scr_wifi_label_3;
	lv_obj_t *scr_wifi_ta_2;
	lv_obj_t *scr_wifi_label_4;
	lv_obj_t *scr_wifi_ddlist_2;
	lv_obj_t *scr_wifi_label_5;
	lv_obj_t *scr_wifi_ta_3;
	lv_obj_t *scr_wifi_label_6;
	lv_obj_t *scr_wifi_ta_4;
	lv_obj_t *scr_wifi_btn_7;
	lv_obj_t *scr_wifi_btn_7_label;
	lv_obj_t *scr_wifi_ddlist_1;
	lv_obj_t *screen_4;
	bool screen_4_del;
	lv_obj_t *screen_4_img_1;
	lv_obj_t *screen_4_label_1;
	lv_obj_t *screen_4_datetext_1;
	lv_obj_t *screen_4_digital_clock_1;
	lv_obj_t *screen_4_btn_5;
	lv_obj_t *screen_4_btn_5_label;
	lv_obj_t *screen_4_btn_4;
	lv_obj_t *screen_4_btn_4_label;
	lv_obj_t *screen_4_btn_3;
	lv_obj_t *screen_4_btn_3_label;
	lv_obj_t *screen_4_btn_2;
	lv_obj_t *screen_4_btn_2_label;
	lv_obj_t *screen_4_btn_1;
	lv_obj_t *screen_4_btn_1_label;
	lv_obj_t *screen_4_img_5;
	lv_obj_t *screen_4_img_4;
	lv_obj_t *screen_4_img_3;
	lv_obj_t *screen_4_img_2;
	lv_obj_t *screen_5;
	bool screen_5_del;
	lv_obj_t *screen_5_img_1;
	lv_obj_t *screen_5_label_1;
	lv_obj_t *screen_5_datetext_1;
	lv_obj_t *screen_5_digital_clock_1;
	lv_obj_t *screen_5_btn_5;
	lv_obj_t *screen_5_btn_5_label;
	lv_obj_t *screen_5_btn_4;
	lv_obj_t *screen_5_btn_4_label;
	lv_obj_t *screen_5_btn_3;
	lv_obj_t *screen_5_btn_3_label;
	lv_obj_t *screen_5_btn_2;
	lv_obj_t *screen_5_btn_2_label;
	lv_obj_t *screen_5_btn_1;
	lv_obj_t *screen_5_btn_1_label;
	lv_obj_t *screen_5_img_5;
	lv_obj_t *screen_5_img_4;
	lv_obj_t *screen_5_img_3;
	lv_obj_t *screen_5_img_2;
	lv_obj_t *screen_6;
	bool screen_6_del;
	lv_obj_t *screen_6_img_1;
	lv_obj_t *screen_6_label_1;
	lv_obj_t *screen_6_datetext_1;
	lv_obj_t *screen_6_digital_clock_1;
	lv_obj_t *screen_6_btn_5;
	lv_obj_t *screen_6_btn_5_label;
	lv_obj_t *screen_6_btn_4;
	lv_obj_t *screen_6_btn_4_label;
	lv_obj_t *screen_6_btn_3;
	lv_obj_t *screen_6_btn_3_label;
	lv_obj_t *screen_6_btn_2;
	lv_obj_t *screen_6_btn_2_label;
	lv_obj_t *screen_6_btn_1;
	lv_obj_t *screen_6_btn_1_label;
	lv_obj_t *screen_6_img_5;
	lv_obj_t *screen_6_img_4;
	lv_obj_t *screen_6_img_3;
	lv_obj_t *screen_6_img_2;
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
void setup_scr_scr_analysis(lv_ui *ui);
void setup_scr_scr_logs(lv_ui *ui);
void setup_scr_scr_hw(lv_ui *ui);
void setup_scr_scr_wifi(lv_ui *ui);
void setup_scr_screen_4(lv_ui *ui);
void setup_scr_screen_5(lv_ui *ui);
void setup_scr_screen_6(lv_ui *ui);
LV_IMAGE_DECLARE(_logo_boot_RGB565A8_256x65);
LV_IMAGE_DECLARE(_bg_settings_base_RGB565A8_800x480);
LV_IMAGE_DECLARE(_weather_RGB565A8_32x32);
LV_IMAGE_DECLARE(_humidity_RGB565A8_32x32);
LV_IMAGE_DECLARE(_wifi_on_RGB565A8_16x16);
LV_IMAGE_DECLARE(_wifi_off_RGB565A8_16x16);
LV_IMAGE_DECLARE(_mqtt_off_RGB565A8_16x16);
LV_IMAGE_DECLARE(_mqtt_on_RGB565A8_16x16);
LV_IMAGE_DECLARE(_next_RGB565A8_32x32);
LV_IMAGE_DECLARE(_left_arrow_RGB565A8_24x24);

LV_FONT_DECLARE(lv_font_montserratMedium_16)
LV_FONT_DECLARE(lv_font_Roboto_Black_10)
LV_FONT_DECLARE(lv_font_Roboto_Bold_10)
LV_FONT_DECLARE(lv_font_Roboto_Bold_9)
LV_FONT_DECLARE(lv_font_Roboto_Black_14)
LV_FONT_DECLARE(lv_font_Roboto_Black_24)
LV_FONT_DECLARE(lv_font_Roboto_Bold_72)
LV_FONT_DECLARE(lv_font_Roboto_Black_20)
LV_FONT_DECLARE(lv_font_Roboto_Black_48)
LV_FONT_DECLARE(lv_font_Roboto_Black_15)
LV_FONT_DECLARE(lv_font_Roboto_Black_25)
LV_FONT_DECLARE(lv_font_montserratMedium_12)
LV_FONT_DECLARE(lv_font_Roboto_Bold_14)
LV_FONT_DECLARE(lv_font_Roboto_Black_12)
LV_FONT_DECLARE(lv_font_Roboto_Regular_12)
LV_FONT_DECLARE(lv_font_Roboto_Bold_12)


#ifdef __cplusplus
}
#endif
#endif
