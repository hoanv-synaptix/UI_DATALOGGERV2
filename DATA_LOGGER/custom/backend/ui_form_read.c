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
