#include "ui_auth.h"
#include <string.h>

#define HARDCODED_ADMIN_USER "a"
#define HARDCODED_ADMIN_PASS "a"

bool ui_auth_verify_login(const char *username, const char *password) {
    if (!username || !password) return false;
    return (strcmp(username, HARDCODED_ADMIN_USER) == 0 && 
            strcmp(password, HARDCODED_ADMIN_PASS) == 0);
}

bool ui_auth_verify_secure_settings(const char *password) {
    if (!password) return false;
    return (strcmp(password, HARDCODED_ADMIN_PASS) == 0);
}
