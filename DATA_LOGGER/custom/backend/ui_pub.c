#include "ui_pub.h"

static ui_pub_state_loader_t s_state_loader = NULL; /**< Hàm Callback của Firmware cung cấp State ban đầu */
static void *s_state_loader_ctx = NULL;
static ui_pub_json_handler_t s_json_handler = NULL; /**< Hàm Callback của Firmware để xử lý JSON */
static void *s_json_handler_ctx = NULL;

void ui_pub_init(void)
{
    /*
     * Vùng khởi tạo trống (Intentionally empty).
     * Các tích hợp phần cứng đặc thù (Platform-specific) như cấu hình RTOS Queue,
     * bộ nhớ chia sẻ, hoặc IPC sẽ được Firmware nhúng chủ động cài đặt
     * qua cơ chế Dependency Injection (DI) bên dưới.
     */
}

void ui_pub_set_state_loader(ui_pub_state_loader_t loader, void *user_ctx)
{
    // Kỹ thuật Dependency Injection: Firmware tự nhét hàm lấy dữ liệu vào đây
    s_state_loader = loader;
    s_state_loader_ctx = user_ctx;
}

bool ui_pub_load_initial_state(ui_runtime_state_t *state)
{
    // Nếu Firmware chưa cung cấp hàm Loader, quá trình khởi tạo UI sẽ bỏ qua
    if (!state || !s_state_loader) return false;
    return s_state_loader(state, s_state_loader_ctx);
}

void ui_pub_set_json_handler(ui_pub_json_handler_t handler, void *user_ctx)
{
    // Kỹ thuật Dependency Injection: Firmware cung cấp hàm Hứng JSON từ UI
    s_json_handler = handler;
    s_json_handler_ctx = user_ctx;
}

bool ui_pub_submit_json(ui_pub_topic_t topic, const char *json_payload)
{
    // Gửi sự kiện xuống tầng Hardware. Hardware có trách nhiệm xử lý và báo về kết quả
    if (!json_payload || !s_json_handler) return false;
    return s_json_handler(topic, json_payload, s_json_handler_ctx);
}
