#ifndef __UI_AUTH_H_
#define __UI_AUTH_H_

#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

bool ui_auth_verify_login(const char *username, const char *password);
bool ui_auth_verify_secure_settings(const char *password);

#ifdef __cplusplus
}
#endif

#endif /* __UI_AUTH_H_ */
