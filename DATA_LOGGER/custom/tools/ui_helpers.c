#include "ui_helpers.h"
#include <stdio.h>

void ui_format_decimal(char *buf, size_t buf_size, int32_t val) {
    // Bảo vệ con trỏ NULL để tránh Crash hệ thống
    if (!buf || buf_size == 0) return;
    
    // Tách phần nguyên và phần thập phân (sử dụng trị tuyệt đối để xử lý số âm)
    int32_t whole = (val < 0 ? -val : val) / 10;
    int32_t frac = (val < 0 ? -val : val) % 10;
    
    // In ra chuỗi với định dạng dấu trừ (nếu có)
    snprintf(buf, buf_size, "%s%d.%d", (val < 0) ? "-" : "", (int)whole, (int)frac);
}
