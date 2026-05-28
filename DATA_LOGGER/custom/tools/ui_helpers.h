#ifndef __UI_HELPERS_H_
#define __UI_HELPERS_H_

#include <stdint.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Định dạng một số nguyên có tỷ lệ 10 (Fixed-point) thành chuỗi thập phân.
 * (Ví dụ: truyền vào 125 sẽ xuất ra chuỗi "12.5", truyền vào -32 sẽ ra "-3.2")
 * 
 * @param buf       Bộ đệm chứa chuỗi kết quả (Buffer)
 * @param buf_size  Kích thước bộ đệm (chống tràn mảng)
 * @param val       Giá trị số nguyên đã nhân 10 từ Backend gửi lên
 */
void ui_format_decimal(char *buf, size_t buf_size, int32_t val);

#ifdef __cplusplus
}
#endif

#endif // __UI_HELPERS_H_
