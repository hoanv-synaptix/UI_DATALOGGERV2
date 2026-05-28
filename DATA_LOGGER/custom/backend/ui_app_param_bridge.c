#ifndef _WIN32

#include "ui_app_param_bridge.h"
#include "ui_sub.h"
#include "lvgl.h"
#include "app_param.h"

static void bridge_timer_cb(lv_timer_t *timer) {
    (void)timer;

    // Kéo (Pull) dữ liệu từ biến toàn cục app_param của Backend
    // và đẩy vào luồng (Push) của UI State Machine.
    ui_sub_post_app_param(&app_param);
}

void ui_app_param_bridge_start(void) {
    // Gọi ngay lần đầu tiên để cập nhật UI lập tức
    bridge_timer_cb(NULL);
    
    // Tạo timer của LVGL để tự động quét biến app_param mỗi 1 giây (1000 ms)
    lv_timer_create(bridge_timer_cb, 1000, NULL);
}

#endif // _WIN32

typedef int dummy_ui_app_param_bridge; // Ngăn lỗi file trống trên MingW

