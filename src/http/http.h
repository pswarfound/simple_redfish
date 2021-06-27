#ifndef __SIMPLE_REDFISH_HTTP_H__
#define __SIMPLE_REDFISH_HTTP_H__
#include <stdint.h>

typedef enum {
    HTTP_METHOD_GET     = 0x2 << 0,
    HTTP_METHOD_POST    = 0x2 << 1,
    HTTP_METHOD_PUT     = 0x2 << 2,
    HTTP_METHOD_DELETE  = 0x2 << 3,
    HTTP_METHOD_PATCH   = 0x2 << 4,
    HTTP_METHOD_HEAD    = 0x2 << 5,
    HTTP_METHOD_OPTIONS = 0x2 << 6,
} http_method_mask_t;

typedef void * http_t;
typedef void * con_t;

typedef void (*http_handler_t)(con_t con);

http_t http_create(void);
int http_start(http_t http, http_handler_t handler);
int http_destroy(http_t http);

uint8_t http_method_get(con_t p);
const char *http_uri_get(con_t p);

int http_printf(con_t con, const char *fmt, ...);

#endif