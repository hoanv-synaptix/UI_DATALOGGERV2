#include "custom.h"
#include "ui_pub.h"
#include "ctrl_screen.h"
#include "keyboard_avoidance.h"

#include "ui_sub.h"

static void delayed_setup_cb(lv_timer_t *t)
{
    if (view_factory_is_base_ready()) {
        view_factory_t *ui = view_factory_get();
        if (!ui) return;
        
        // Khởi tạo kênh giao tiếp Publisher
        ui_pub_init();
        
        // Bắt đầu nhúng Controller vào màn hình hiện tại
        ui_screen_controller_enter(ui);
        
        // Kích hoạt tính năng tự động né bàn phím
        keyboard_avoidance_init();
        
        lv_timer_del(t);
    }
}

void custom_init(void *generated_ui)
{
    (void)generated_ui;
    
    // 1. Tạo queue/timer cho ui_sub ngay bây giờ (an toàn luồng, vì đang ở trong GUI Task)
    ui_sub_init();

    // 2. Tạo timer thăm dò chờ scr_base được sinh ra
    lv_timer_create(delayed_setup_cb, 50, NULL);
}

void custom_input_reset(void)
{
    // Khôi phục lại trạng thái nhập liệu khi luồng ứng dụng yêu cầu
    ui_screen_controller_restore_input();
}
