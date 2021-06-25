#ifndef __SIMPLE_REDFISH_HTTP_H__
#define __SIMPLE_REDFISH_HTTP_H__

typedef enum {
    HTTP_METHOD_GET     = 0x1,
    HTTP_METHOD_POST    = 0x2,
    HTTP_METHOD_PATCH   = 0x4,
    HTTP_METHOD_DELETE  = 0x8,
} http_method_mask_t;


#endif