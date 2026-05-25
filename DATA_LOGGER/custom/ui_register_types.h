#ifndef __UI_REGISTER_TYPES_H_
#define __UI_REGISTER_TYPES_H_

#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#define UI_REGISTER_STRING_MAX 96U

typedef enum {
    UI_REGISTER_DOMAIN_WIFI = 0,
    UI_REGISTER_DOMAIN_MQTT,
    UI_REGISTER_DOMAIN_MODBUS,
    UI_REGISTER_DOMAIN_DASHBOARD,
    UI_REGISTER_DOMAIN_SYSTEM
} ui_register_domain_t;

typedef enum {
    UI_REGISTER_ACCESS_UI_WRITE = 0,
    UI_REGISTER_ACCESS_BACKEND_WRITE,
    UI_REGISTER_ACCESS_RW
} ui_register_access_t;

typedef enum {
    UI_REGISTER_TYPE_UINT8 = 0,
    UI_REGISTER_TYPE_INT32,
    UI_REGISTER_TYPE_BOOL,
    UI_REGISTER_TYPE_STRING
} ui_register_type_t;

typedef struct {
    uint16_t address;
    const char *name;
    ui_register_domain_t domain;
    ui_register_access_t access;
    ui_register_type_t type;
    float scale;
    const char *unit;
    uint16_t max_len;
} ui_register_desc_t;

typedef struct {
    uint16_t address;
    ui_register_type_t type;
    uint64_t timestamp_ms;
    union {
        uint8_t u8;
        int32_t i32;
        bool boolean;
        char string[UI_REGISTER_STRING_MAX];
    } value;
} ui_register_update_t;

typedef struct {
    uint16_t address;
    ui_register_type_t type;
    union {
        uint8_t u8;
        int32_t i32;
        bool boolean;
        char string[UI_REGISTER_STRING_MAX];
    } value;
} ui_register_write_t;

#ifdef __cplusplus
}
#endif

#endif
