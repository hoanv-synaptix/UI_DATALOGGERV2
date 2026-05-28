#include "custom.h"
#include "ui_pub.h"
#include "ctrl_screen.h"
#include "keyboard_avoidance.h"

void custom_init(void *generated_ui)
{
    // Lấy Factory Pattern: Tập hợp tất cả các con trỏ Widget được sinh tự động
    view_factory_t *ui = view_factory_get();

    // Ép kiểu (void) để báo cho trình biên dịch biết ta cố tình không dùng biến này
    (void)generated_ui;
    
    if (!ui) return;
    
    // Khởi tạo kênh giao tiếp Publisher (gửi lệnh xuống Firmware)
    ui_pub_init();
    
    // Bắt đầu nhúng Controller vào màn hình hiện tại
    ui_screen_controller_enter(ui);
    
    // Kích hoạt tính năng tự động né bàn phím (tránh bàn phím ảo che mất TextInput)
    keyboard_avoidance_init();
}

void custom_input_reset(void)
{
    // Khôi phục lại trạng thái nhập liệu khi luồng ứng dụng yêu cầu
    ui_screen_controller_restore_input();
}
