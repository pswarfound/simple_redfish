#ifndef __SIMPLE_REDFISH_HTTP_H__
#define __SIMPLE_REDFISH_HTTP_H__

typedef enum {
    HTTP_METHOD_GET     = 0x2 << 0,
    HTTP_METHOD_POST    = 0x2 << 1,
    HTTP_METHOD_PUT     = 0x2 << 2,
    HTTP_METHOD_DELETE  = 0x2 << 3,
    HTTP_METHOD_PATCH   = 0x2 << 4,
    HTTP_METHOD_HEAD    = 0x2 << 5,
    HTTP_METHOD_OPTIONS = 0x2 << 6,
} http_method_mask_t;

#endif