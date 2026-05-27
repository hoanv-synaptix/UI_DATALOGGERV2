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
	lv_obj_t *scr_base;
	bool scr_base_del;
	lv_obj_t *scr_base_img_bg;
	lv_obj_t *scr_base_btn_dashboard;
	lv_obj_t *scr_base_btn_dashboard_label;
	lv_obj_t *scr_base_btn_analystis;
	lv_obj_t *scr_base_btn_analystis_label;
	lv_obj_t *scr_base_btn_event_logs;
	lv_obj_t *scr_base_btn_event_logs_label;
	lv_obj_t *scr_base_btn_settings;
	lv_obj_t *scr_base_btn_settings_label;
	lv_obj_t *scr_base_btn_restart;
	lv_obj_t *scr_base_btn_restart_label;
	lv_obj_t *scr_base_cont_dashboard;
	lv_obj_t *scr_base_lbl_dashboard;
	lv_obj_t *scr_base_cont_aqi;
	lv_obj_t *scr_base_lbl_aqi;
	lv_obj_t *scr_base_lbl_aqi_val;
	lv_obj_t *scr_base_arc_aqi;
	lv_obj_t *scr_base_cont_aqi_status;
	lv_obj_t *scr_base_lbl_Aqi_status;
	lv_obj_t *scr_base_cont_pm10;
	lv_obj_t *scr_base_lbl_pm10;
	lv_obj_t *scr_base_lbl_pm10_val;
	lv_obj_t *scr_base_lbl_pm10_unit;
	lv_obj_t *scr_base_cont_pm10_status;
	lv_obj_t *scr_base_lbl_pm10_status;
	lv_obj_t *scr_base_cont_pm25;
	lv_obj_t *scr_base_lbl_pm25;
	lv_obj_t *scr_base_lbl_pm25_val;
	lv_obj_t *scr_base_lbl_pm25_uint;
	lv_obj_t *scr_base_cont_status;
	lv_obj_t *scr_base_lbl_pm25_status;
	lv_obj_t *scr_base_cont_21;
	lv_obj_t *scr_base_lbl_temp;
	lv_obj_t *scr_base_lbl_temp_val;
	lv_obj_t *scr_base_lbl_temp_unit;
	lv_obj_t *scr_base_img_temp;
	lv_obj_t *scr_base_cont_humi;
	lv_obj_t *scr_base_lbl_humi;
	lv_obj_t *scr_base_lbl_humi_val;
	lv_obj_t *scr_base_lbl_humi_unit;
	lv_obj_t *scr_base_img_humi;
	lv_obj_t *scr_base_cont_no2;
	lv_obj_t *scr_base_lbl_no2;
	lv_obj_t *scr_base_lbl_no2_val;
	lv_obj_t *scr_base_lbl_no2_unit;
	lv_obj_t *scr_base_cont_o3;
	lv_obj_t *scr_base_lbl_03;
	lv_obj_t *scr_base_lbl_03_val;
	lv_obj_t *scr_base_lbl_o3_unit;
	lv_obj_t *scr_base_cont_co2;
	lv_obj_t *scr_base_lbl_co2;
	lv_obj_t *scr_base_lbl_co2_val;
	lv_obj_t *scr_base_lbl_co2_unit;
	lv_obj_t *scr_base_cont_so2;
	lv_obj_t *scr_base_lbl_so2;
	lv_obj_t *scr_base_lbl_so2_val;
	lv_obj_t *scr_base_lbl_so2_unit;
	lv_obj_t *scr_base_cont_data_analysis;
	lv_obj_t *scr_base_label_analysis;
	lv_obj_t *scr_base_cont_trends;
	lv_obj_t *scr_base_cont_chart;
	lv_obj_t *scr_base_chart;
	lv_chart_series_t *scr_base_chart_0;
	lv_chart_series_t *scr_base_chart_1;
	lv_chart_series_t *scr_base_chart_2;
	lv_obj_t *scr_base_label_trends;
	lv_obj_t *scr_base_ddlist_trends;
	lv_obj_t *scr_base_cont_avg;
	lv_obj_t *scr_base_lbl_avg;
	lv_obj_t *scr_base_label_avg_val;
	lv_obj_t *scr_base_cont_insights;
	lv_obj_t *scr_base_btn_generate_report;
	lv_obj_t *scr_base_btn_generate_report_label;
	lv_obj_t *scr_base_label_insights;
	lv_obj_t *scr_base_lbl_advice;
	lv_obj_t *scr_base_cont_event_logs;
	lv_obj_t *scr_base_lbl_event_logs;
	lv_obj_t *scr_base_cont_logs;
	lv_obj_t *scr_base_lbl_critical_logs;
	lv_obj_t *scr_base_btn_clear_history;
	lv_obj_t *scr_base_btn_clear_history_label;
	lv_obj_t *scr_base_cont_logs_detail;
	lv_obj_t *scr_base_lbl_log_detail;
	lv_obj_t *scr_base_cont_hw;
	lv_obj_t *scr_base_label_hw;
	lv_obj_t *scr_base_cont_menu;
	lv_obj_t *scr_base_cont_net;
	lv_obj_t *scr_base_label_99;
	lv_obj_t *scr_base_label_100;
	lv_obj_t *scr_base_img_14;
	lv_obj_t *scr_base_cont_33;
	lv_obj_t *scr_base_img_27;
	lv_obj_t *scr_base_btn_net;
	lv_obj_t *scr_base_btn_net_label;
	lv_obj_t *scr_base_cont_mqtt;
	lv_obj_t *scr_base_label_102;
	lv_obj_t *scr_base_label_101;
	lv_obj_t *scr_base_img_15;
	lv_obj_t *scr_base_cont_35;
	lv_obj_t *scr_base_img_26;
	lv_obj_t *scr_base_btn_mqtt;
	lv_obj_t *scr_base_btn_mqtt_label;
	lv_obj_t *scr_base_cont_modbus;
	lv_obj_t *scr_base_label_104;
	lv_obj_t *scr_base_label_103;
	lv_obj_t *scr_base_img_16;
	lv_obj_t *scr_base_cont_37;
	lv_obj_t *scr_base_img_25;
	lv_obj_t *scr_base_btn_modbus;
	lv_obj_t *scr_base_btn_modbus_label;
	lv_obj_t *scr_base_cont_sys_admin;
	lv_obj_t *scr_base_label_106;
	lv_obj_t *scr_base_label_105;
	lv_obj_t *scr_base_img_17;
	lv_obj_t *scr_base_cont_39;
	lv_obj_t *scr_base_img_24;
	lv_obj_t *scr_base_btn_sys_admin;
	lv_obj_t *scr_base_btn_sys_admin_label;
	lv_obj_t *scr_base_cont_networkconfig;
	lv_obj_t *scr_base_cont_net_back;
	lv_obj_t *scr_base_btn_net_back;
	lv_obj_t *scr_base_btn_net_back_label;
	lv_obj_t *scr_base_img_18;
	lv_obj_t *scr_base_label_107;
	lv_obj_t *scr_base_ddlist_net_option;
	lv_obj_t *scr_base_cont_40;
	lv_obj_t *scr_base_cont_wifi;
	lv_obj_t *scr_base_label_108;
	lv_obj_t *scr_base_label_109;
	lv_obj_t *scr_base_ta_wifi_pass;
	lv_obj_t *scr_base_ta_wifi_ssid;
	lv_obj_t *scr_base_label_110;
	lv_obj_t *scr_base_label_111;
	lv_obj_t *scr_base_ddlist_wifi_mode;
	lv_obj_t *scr_base_ta_wifi_ip;
	lv_obj_t *scr_base_label_112;
	lv_obj_t *scr_base_cont_41;
	lv_obj_t *scr_base_lbl_wifi_status;
	lv_obj_t *scr_base_btn_wifi_apply;
	lv_obj_t *scr_base_btn_wifi_apply_label;
	lv_obj_t *scr_base_ta_1;
	lv_obj_t *scr_base_ta_2;
	lv_obj_t *scr_base_label_213;
	lv_obj_t *scr_base_label_214;
	lv_obj_t *scr_base_cont_ethernet;
	lv_obj_t *scr_base_label_118;
	lv_obj_t *scr_base_label_117;
	lv_obj_t *scr_base_ta_ethernet_gateway;
	lv_obj_t *scr_base_ta_ethernet_subnet;
	lv_obj_t *scr_base_label_116;
	lv_obj_t *scr_base_label_115;
	lv_obj_t *scr_base_ddlist_ethernet_mode;
	lv_obj_t *scr_base_ta_ethernet_ip;
	lv_obj_t *scr_base_label_114;
	lv_obj_t *scr_base_cont_43;
	lv_obj_t *scr_base_lbl_ethernet_status;
	lv_obj_t *scr_base_btn_ethernet_apply;
	lv_obj_t *scr_base_btn_ethernet_apply_label;
	lv_obj_t *scr_base_cont_lte;
	lv_obj_t *scr_base_label_124;
	lv_obj_t *scr_base_label_123;
	lv_obj_t *scr_base_ta_lte_pin_code;
	lv_obj_t *scr_base_ta_lte_apn;
	lv_obj_t *scr_base_label_122;
	lv_obj_t *scr_base_label_121;
	lv_obj_t *scr_base_ta_lte_pass;
	lv_obj_t *scr_base_label_120;
	lv_obj_t *scr_base_cont_45;
	lv_obj_t *scr_base_lbl_lte_status;
	lv_obj_t *scr_base_btn_lte_apply;
	lv_obj_t *scr_base_btn_lte_apply_label;
	lv_obj_t *scr_base_ta_lte_username;
	lv_obj_t *scr_base_label_125;
	lv_obj_t *scr_base_label_126;
	lv_obj_t *scr_base_cont_mqtt_config;
	lv_obj_t *scr_base_cont_mqtt_back;
	lv_obj_t *scr_base_btn_mqtt_back;
	lv_obj_t *scr_base_btn_mqtt_back_label;
	lv_obj_t *scr_base_img_19;
	lv_obj_t *scr_base_label_147;
	lv_obj_t *scr_base_cont_47;
	lv_obj_t *scr_base_cont_48;
	lv_obj_t *scr_base_label_134;
	lv_obj_t *scr_base_label_133;
	lv_obj_t *scr_base_ta_mqtt_port;
	lv_obj_t *scr_base_ta_mqtt_host;
	lv_obj_t *scr_base_label_132;
	lv_obj_t *scr_base_label_131;
	lv_obj_t *scr_base_ta_mqtt_pass;
	lv_obj_t *scr_base_label_130;
	lv_obj_t *scr_base_cont_49;
	lv_obj_t *scr_base_lbl_mqtt_status;
	lv_obj_t *scr_base_btn_mqtt_apply;
	lv_obj_t *scr_base_btn_mqtt_apply_label;
	lv_obj_t *scr_base_ta_mqtt_user;
	lv_obj_t *scr_base_cont_modbus_config;
	lv_obj_t *scr_base_cont_modbus_back;
	lv_obj_t *scr_base_btn_modbus_back;
	lv_obj_t *scr_base_btn_modbus_back_label;
	lv_obj_t *scr_base_img_20;
	lv_obj_t *scr_base_label_168;
	lv_obj_t *scr_base_cont_51;
	lv_obj_t *scr_base_cont_54;
	lv_obj_t *scr_base_label_161;
	lv_obj_t *scr_base_label_160;
	lv_obj_t *scr_base_label_159;
	lv_obj_t *scr_base_label_157;
	lv_obj_t *scr_base_cont_55;
	lv_obj_t *scr_base_lbl_modbus_status;
	lv_obj_t *scr_base_btn_modbus_apply;
	lv_obj_t *scr_base_btn_modbus_apply_label;
	lv_obj_t *scr_base_cont_slave;
	lv_obj_t *scr_base_ta_slave_id;
	lv_obj_t *scr_base_label_158;
	lv_obj_t *scr_base_cont_master;
	lv_obj_t *scr_base_lbl_master;
	lv_obj_t *scr_base_btn_master_adddeivce;
	lv_obj_t *scr_base_btn_master_adddeivce_label;
	lv_obj_t *scr_base_btn_masterviewlist;
	lv_obj_t *scr_base_btn_masterviewlist_label;
	lv_obj_t *scr_base_label_170;
	lv_obj_t *scr_base_label_171;
	lv_obj_t *scr_base_ddlist_modbus_mode;
	lv_obj_t *scr_base_ddlist_modbus_parity;
	lv_obj_t *scr_base_ddlist_modbus_databits;
	lv_obj_t *scr_base_ddlist_modbus_stopbits;
	lv_obj_t *scr_base_ddlist_modbus_baudrate;
	lv_obj_t *scr_base_cont_system_admin;
	lv_obj_t *scr_base_cont_sys_back;
	lv_obj_t *scr_base_btn_sys_back;
	lv_obj_t *scr_base_btn_sys_back_label;
	lv_obj_t *scr_base_img_23;
	lv_obj_t *scr_base_label_194;
	lv_obj_t *scr_base_cont_72;
	lv_obj_t *scr_base_label_205;
	lv_obj_t *scr_base_label_206;
	lv_obj_t *scr_base_label_207;
	lv_obj_t *scr_base_ddlist_screentime_option;
	lv_obj_t *scr_base_slider_brightness;
	lv_obj_t *scr_base_cont_operations;
	lv_obj_t *scr_base_label_208;
	lv_obj_t *scr_base_btn_restart_system;
	lv_obj_t *scr_base_btn_restart_system_label;
	lv_obj_t *scr_base_btn_factory_reset;
	lv_obj_t *scr_base_btn_factory_reset_label;
	lv_obj_t *scr_base_cont_device_operations;
	lv_obj_t *scr_base_label_209;
	lv_obj_t *scr_base_label_210;
	lv_obj_t *scr_base_label_211;
	lv_obj_t *scr_base_label_212;
	lv_obj_t *scr_base_lbl_fw_val;
	lv_obj_t *scr_base_lbl_memory_status_val;
	lv_obj_t *scr_base_lbl_system_uptime_val;
	lv_obj_t *scr_base_cont_data_time;
	lv_obj_t *scr_base_time_val;
	lv_obj_t *scr_base_date_val;
	lv_obj_t *scr_base_line_1;
	lv_obj_t *scr_base_cont_net_mqtt;
	lv_obj_t *scr_base_line_2;
	lv_obj_t *scr_base_lbl_net;
	lv_obj_t *scr_base_lbl_mqtt;
	lv_obj_t *scr_base_img_mqtt_on;
	lv_obj_t *scr_base_img_net_on;
	lv_obj_t *scr_base_img_mqtt_off;
	lv_obj_t *scr_base_img_net_off;
	lv_obj_t *scr_base_cont_device_viewlist;
	lv_obj_t *scr_base_cont_68;
	lv_obj_t *scr_base_cont_69;
	lv_obj_t *scr_base_cont_70;
	lv_obj_t *scr_base_lbl_device_action;
	lv_obj_t *scr_base_lbl_deivce_;
	lv_obj_t *scr_base_lbl_device_register;
	lv_obj_t *scr_base_lbl_device_slave_id;
	lv_obj_t *scr_base_lbl_device_stt;
	lv_obj_t *scr_base_label_184;
	lv_obj_t *scr_base_cont_devicelist_back;
	lv_obj_t *scr_base_btn_devicelist_back;
	lv_obj_t *scr_base_btn_devicelist_back_label;
	lv_obj_t *scr_base_img_21;
	lv_obj_t *scr_base_cont_device_config;
	lv_obj_t *scr_base_cont_62;
	lv_obj_t *scr_base_cont_63;
	lv_obj_t *scr_base_label_180;
	lv_obj_t *scr_base_label_179;
	lv_obj_t *scr_base_label_177;
	lv_obj_t *scr_base_btn_master_device_apply;
	lv_obj_t *scr_base_btn_master_device_apply_label;
	lv_obj_t *scr_base_ddlist_master_device_registers;
	lv_obj_t *scr_base_label_182;
	lv_obj_t *scr_base_label_181;
	lv_obj_t *scr_base_ta_master_device_slaveid;
	lv_obj_t *scr_base_ta_master_device_address;
	lv_obj_t *scr_base_ta_master_device_quantity;
	lv_obj_t *scr_base_ta_3;
	lv_obj_t *scr_base_label_183;
	lv_obj_t *scr_base_cont_deviceconfig_back;
	lv_obj_t *scr_base_btn_deviceconfig_back;
	lv_obj_t *scr_base_btn_deviceconfig_back_label;
	lv_obj_t *scr_base_img_22;
	lv_obj_t *scr_base_cont_restart;
	lv_obj_t *scr_base_cont_restart_system;
	lv_obj_t *scr_base_img_12;
	lv_obj_t *scr_base_label_95;
	lv_obj_t *scr_base_label_96;
	lv_obj_t *scr_base_btn_restart_confirm;
	lv_obj_t *scr_base_btn_restart_confirm_label;
	lv_obj_t *scr_base_btn_restart_cancel;
	lv_obj_t *scr_base_btn_restart_cancel_label;
	lv_obj_t *scr_base_cont_restore;
	lv_obj_t *scr_base_cont_31;
	lv_obj_t *scr_base_img_13;
	lv_obj_t *scr_base_label_98;
	lv_obj_t *scr_base_label_97;
	lv_obj_t *scr_base_btn_restore_confirm;
	lv_obj_t *scr_base_btn_restore_confirm_label;
	lv_obj_t *scr_base_btn_restore_cancel;
	lv_obj_t *scr_base_btn_restore_cancel_label;
	lv_obj_t *scr_base_cont_generate_report;
	lv_obj_t *scr_base_cont_74;
	lv_obj_t *scr_base_img_28;
	lv_obj_t *scr_base_label_216;
	lv_obj_t *scr_base_label_215;
	lv_obj_t *scr_base_btn_generate_report_confirm;
	lv_obj_t *scr_base_btn_generate_report_confirm_label;
	lv_obj_t *scr_base_btn_generate_report_cancel;
	lv_obj_t *scr_base_btn_generate_report_cancel_label;
	lv_obj_t *scr_base_cont_login_settings;
	lv_obj_t *scr_base_cont_76;
	lv_obj_t *scr_base_img_29;
	lv_obj_t *scr_base_label_218;
	lv_obj_t *scr_base_lbl_status_login_setting;
	lv_obj_t *scr_base_btn_login_settings_confirm;
	lv_obj_t *scr_base_btn_login_settings_confirm_label;
	lv_obj_t *scr_base_btn_login_settings_cancel;
	lv_obj_t *scr_base_btn_login_settings_cancel_label;
	lv_obj_t *scr_base_ta_login_settings_pass;
	lv_obj_t *scr_base_img_33;
	lv_obj_t *scr_base_cont_booting_login;
	lv_obj_t *scr_base_cont_78;
	lv_obj_t *scr_base_img_30;
	lv_obj_t *scr_base_label_220;
	lv_obj_t *scr_base_label_login_booting_status;
	lv_obj_t *scr_base_btn_login_booting_confirm;
	lv_obj_t *scr_base_btn_login_booting_confirm_label;
	lv_obj_t *scr_base_btn_login_booting_cancel;
	lv_obj_t *scr_base_btn_login_booting_cancel_label;
	lv_obj_t *scr_base_ta_login_booting_user;
	lv_obj_t *scr_base_img_31;
	lv_obj_t *scr_base_ta_login_booting_pass;
	lv_obj_t *scr_base_img_32;
	lv_obj_t *g_kb_top_layer;
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
void setup_scr_scr_base(lv_ui *ui);
LV_IMAGE_DECLARE(_text_synaptix_color_RGB565A8_256x65);
LV_IMAGE_DECLARE(_bg_base_RGB565_800x480);
LV_IMAGE_DECLARE(_weather_RGB565A8_32x32);
LV_IMAGE_DECLARE(_humidity_RGB565A8_32x32);
LV_IMAGE_DECLARE(_next_RGB565A8_32x32);
LV_IMAGE_DECLARE(_connection_RGB565A8_24x24);
LV_IMAGE_DECLARE(_computer_RGB565A8_24x24);
LV_IMAGE_DECLARE(_communicative_RGB565A8_24x24);
LV_IMAGE_DECLARE(_system_update_RGB565A8_24x24);
LV_IMAGE_DECLARE(_left_arrow_RGB565A8_24x24);
LV_IMAGE_DECLARE(_mqtt_on_RGB565A8_16x16);
LV_IMAGE_DECLARE(_wifi_on_RGB565A8_16x16);
LV_IMAGE_DECLARE(_mqtt_off_RGB565A8_16x16);
LV_IMAGE_DECLARE(_wifi_off_RGB565A8_16x16);
LV_IMAGE_DECLARE(_power_button_RGB565A8_100x100);
LV_IMAGE_DECLARE(_power_RGB565A8_100x100);
LV_IMAGE_DECLARE(_data_analysis_RGB565A8_100x100);
LV_IMAGE_DECLARE(_setting_secure_RGB565A8_100x100);
LV_IMAGE_DECLARE(_padlock_RGB565A8_24x24);
LV_IMAGE_DECLARE(_login_booting_RGB565A8_100x100);
LV_IMAGE_DECLARE(_user_RGB565A8_24x24);

LV_FONT_DECLARE(lv_font_montserratMedium_16)
LV_FONT_DECLARE(lv_font_montserratMedium_12)
LV_FONT_DECLARE(lv_font_Roboto_Black_15)
LV_FONT_DECLARE(lv_font_Roboto_Black_25)
LV_FONT_DECLARE(lv_font_Roboto_Black_72)
LV_FONT_DECLARE(lv_font_Roboto_Black_30)
LV_FONT_DECLARE(lv_font_Roboto_Black_48)
LV_FONT_DECLARE(lv_font_Roboto_Black_20)
LV_FONT_DECLARE(lv_font_Roboto_Black_14)
LV_FONT_DECLARE(lv_font_Roboto_Black_26)
LV_FONT_DECLARE(lv_font_Roboto_Black_12)
LV_FONT_DECLARE(lv_font_Roboto_Black_16)
LV_FONT_DECLARE(lv_font_Roboto_Bold_12)
LV_FONT_DECLARE(lv_font_Roboto_Bold_40)
LV_FONT_DECLARE(lv_font_Roboto_Regular_12)
LV_FONT_DECLARE(lv_font_Roboto_Bold_14)
LV_FONT_DECLARE(lv_font_Roboto_Bold_15)
LV_FONT_DECLARE(lv_font_Roboto_Regular_10)
LV_FONT_DECLARE(lv_font_Roboto_Bold_13)
LV_FONT_DECLARE(lv_font_Roboto_Regular_15)
LV_FONT_DECLARE(lv_font_Roboto_Bold_10)
LV_FONT_DECLARE(lv_font_Roboto_Regular_14)
LV_FONT_DECLARE(lv_font_Roboto_Bold_9)
LV_FONT_DECLARE(lv_font_Roboto_Black_18)
LV_FONT_DECLARE(lv_font_Roboto_Regular_18)


#ifdef __cplusplus
}
#endif
#endif
