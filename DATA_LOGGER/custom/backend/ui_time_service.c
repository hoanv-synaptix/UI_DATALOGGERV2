/**
 * @file ui_time_service.c
 * @brief Triển khai dịch vụ thời gian — wrap standard C time functions.
 *
 * Flow (mạch thật): time(NULL) → _gettimeofday() → HAL_RTC_GetTime/Date
 * Flow (simulator): time(NULL) → Windows system clock
 */
#include "ui_time_service.h"
#include <time.h>

#ifndef _WIN32
#include <sys/time.h>   /* settimeofday() — chỉ có trên POSIX/newlib */
#endif

/* Epoch 2024-01-01 00:00:00 UTC — ngưỡng kiểm tra RTC đã được set chưa */
#define EPOCH_2024  1704067200U

bool ui_time_service_get(ui_time_t *out)
{
    if (!out) return false;

    time_t now = time(NULL);

    /* RTC cold boot: giá trị epoch nhỏ hơn 2024 → chưa được set */
    if ((uint32_t)now < EPOCH_2024) return false;

    struct tm *tm = localtime(&now);
    if (!tm) return false;

    out->year    = (uint16_t)(tm->tm_year + 1900);
    out->month   = (uint8_t)(tm->tm_mon + 1);
    out->day     = (uint8_t)tm->tm_mday;
    out->hour    = (uint8_t)tm->tm_hour;
    out->minute  = (uint8_t)tm->tm_min;
    out->second  = (uint8_t)tm->tm_sec;
    out->weekday = (uint8_t)tm->tm_wday;
    return true;
}

void ui_time_service_set(const ui_time_t *t)
{
    if (!t) return;

#ifndef _WIN32
    /* Mạch thật: set RTC qua POSIX bridge → HAL_RTC_SetTime/SetDate */
    struct tm tm = {0};
    tm.tm_year  = t->year - 1900;
    tm.tm_mon   = t->month - 1;
    tm.tm_mday  = t->day;
    tm.tm_hour  = t->hour;
    tm.tm_min   = t->minute;
    tm.tm_sec   = t->second;
    tm.tm_isdst = -1;

    time_t epoch = mktime(&tm);
    struct timeval tv;
    tv.tv_sec  = epoch;
    tv.tv_usec = 0;
    settimeofday(&tv, NULL);
#else
    /* Simulator: không cần set RTC — Windows tự quản lý thời gian */
    (void)t;
#endif
}
