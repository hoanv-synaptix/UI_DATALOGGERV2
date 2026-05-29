#include "ui_form_read.h"
#include "cJSON.h"
#include <stdlib.h>
#include <string.h>

char *ui_form_read_mqtt(view_factory_t *ui) {
    if (!ui) return NULL;

    // 1. Trích xuất văn bản từ các Text Area thông qua View Factory
    lv_obj_t *ta_host = view_factory_get_textarea(ui, UI_TEXTAREA_MQTT_HOST);
    lv_obj_t *ta_port = view_factory_get_textarea(ui, UI_TEXTAREA_MQTT_PORT);
    lv_obj_t *ta_user = view_factory_get_textarea(ui, UI_TEXTAREA_MQTT_USER);
    lv_obj_t *ta_pass = view_factory_get_textarea(ui, UI_TEXTAREA_MQTT_PASS);

    if (!ta_host || !ta_port || !ta_user || !ta_pass) return NULL;

    const char *host_str = lv_textarea_get_text(ta_host);
    const char *port_str = lv_textarea_get_text(ta_port);
    const char *user_str = lv_textarea_get_text(ta_user);
    const char *pass_str = lv_textarea_get_text(ta_pass);

    // 2. Kiểm tra tính hợp lệ (Validation cơ bản)
    // Host và Port không được rỗng
    if (!host_str || strlen(host_str) == 0) return NULL;
    if (!port_str || strlen(port_str) == 0) return NULL;

    // Chuyển chuỗi Port sang số nguyên
    int port_num = atoi(port_str);
    if (port_num <= 0 || port_num > 65535) return NULL;

    // 3. Đóng gói thành cJSON Object
    cJSON *root = cJSON_CreateObject();
    if (!root) return NULL;

    cJSON_AddStringToObject(root, "host", host_str);
    cJSON_AddNumberToObject(root, "port", port_num);
    
    // User và Pass có thể rỗng
    if (user_str && strlen(user_str) > 0) {
        cJSON_AddStringToObject(root, "username", user_str);
    } else {
        cJSON_AddStringToObject(root, "username", "");
    }

    if (pass_str && strlen(pass_str) > 0) {
        cJSON_AddStringToObject(root, "password", pass_str);
    } else {
        cJSON_AddStringToObject(root, "password", "");
    }

    // Xuất ra chuỗi JSON không có khoảng trắng/xuống dòng để tiết kiệm bộ nhớ
    char *json_str = cJSON_PrintUnformatted(root);
    
    // Xóa object cJSON để tránh memory leak
    cJSON_Delete(root);

    return json_str;
}

char *ui_form_read_wifi(view_factory_t *ui) {
    if (!ui) return NULL;

    lv_obj_t *ta_ssid = view_factory_get_textarea(ui, UI_TEXTAREA_WIFI_SSID);
    lv_obj_t *ta_pass = view_factory_get_textarea(ui, UI_TEXTAREA_WIFI_PASS);

    if (!ta_ssid) return NULL;

    const char *ssid_str = lv_textarea_get_text(ta_ssid);
    if (!ssid_str || strlen(ssid_str) == 0) return NULL;

    cJSON *root = cJSON_CreateObject();
    if (!root) return NULL;

    cJSON_AddStringToObject(root, "ssid", ssid_str);

    const char *pass_str = ta_pass ? lv_textarea_get_text(ta_pass) : "";
    cJSON_AddStringToObject(root, "password", pass_str ? pass_str : "");

    // Optional static IP fields
    lv_obj_t *ta_ip = view_factory_get_textarea(ui, UI_TEXTAREA_WIFI_IP);
    if (ta_ip) {
        const char *ip = lv_textarea_get_text(ta_ip);
        if (ip && strlen(ip) > 0) cJSON_AddStringToObject(root, "ip", ip);
    }

    lv_obj_t *ta_subnet = view_factory_get_textarea(ui, UI_TEXTAREA_WIFI_SUBNET);
    if (ta_subnet) {
        const char *subnet = lv_textarea_get_text(ta_subnet);
        if (subnet && strlen(subnet) > 0) cJSON_AddStringToObject(root, "subnet", subnet);
    }

    lv_obj_t *ta_gw = view_factory_get_textarea(ui, UI_TEXTAREA_WIFI_GATEWAY);
    if (ta_gw) {
        const char *gw = lv_textarea_get_text(ta_gw);
        if (gw && strlen(gw) > 0) cJSON_AddStringToObject(root, "gateway", gw);
    }

    char *json_str = cJSON_PrintUnformatted(root);
    cJSON_Delete(root);
    return json_str;
}

char *ui_form_read_ethernet(view_factory_t *ui) {
    if (!ui) return NULL;

    lv_obj_t *ta_ip = view_factory_get_textarea(ui, UI_TEXTAREA_ETHERNET_IP);
    if (!ta_ip) return NULL;

    const char *ip_str = lv_textarea_get_text(ta_ip);
    if (!ip_str || strlen(ip_str) == 0) return NULL;

    cJSON *root = cJSON_CreateObject();
    if (!root) return NULL;

    cJSON_AddStringToObject(root, "ip", ip_str);

    lv_obj_t *ta_subnet = view_factory_get_textarea(ui, UI_TEXTAREA_ETHERNET_SUBNET);
    if (ta_subnet) {
        const char *subnet = lv_textarea_get_text(ta_subnet);
        if (subnet && strlen(subnet) > 0) cJSON_AddStringToObject(root, "subnet", subnet);
    }

    lv_obj_t *ta_gw = view_factory_get_textarea(ui, UI_TEXTAREA_ETHERNET_GATEWAY);
    if (ta_gw) {
        const char *gw = lv_textarea_get_text(ta_gw);
        if (gw && strlen(gw) > 0) cJSON_AddStringToObject(root, "gateway", gw);
    }

    char *json_str = cJSON_PrintUnformatted(root);
    cJSON_Delete(root);
    return json_str;
}

char *ui_form_read_lte(view_factory_t *ui) {
    if (!ui) return NULL;

    lv_obj_t *ta_apn = view_factory_get_textarea(ui, UI_TEXTAREA_LTE_APN);
    if (!ta_apn) return NULL;

    const char *apn_str = lv_textarea_get_text(ta_apn);
    if (!apn_str || strlen(apn_str) == 0) return NULL;

    cJSON *root = cJSON_CreateObject();
    if (!root) return NULL;

    cJSON_AddStringToObject(root, "apn", apn_str);

    lv_obj_t *ta_user = view_factory_get_textarea(ui, UI_TEXTAREA_LTE_USERNAME);
    if (ta_user) {
        const char *user = lv_textarea_get_text(ta_user);
        if (user && strlen(user) > 0) cJSON_AddStringToObject(root, "username", user);
    }

    lv_obj_t *ta_pass = view_factory_get_textarea(ui, UI_TEXTAREA_LTE_PASS);
    if (ta_pass) {
        const char *pass = lv_textarea_get_text(ta_pass);
        if (pass && strlen(pass) > 0) cJSON_AddStringToObject(root, "password", pass);
    }

    lv_obj_t *ta_pin = view_factory_get_textarea(ui, UI_TEXTAREA_LTE_PIN_CODE);
    if (ta_pin) {
        const char *pin = lv_textarea_get_text(ta_pin);
        if (pin && strlen(pin) > 0) cJSON_AddStringToObject(root, "pin_code", pin);
    }

    char *json_str = cJSON_PrintUnformatted(root);
    cJSON_Delete(root);
    return json_str;
}
