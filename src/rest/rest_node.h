#ifndef __SIMPLE_REDFISH_REST_NODE_H__
#define __SIMPLE_REDFISH_REST_NODE_H__
#include <stdint.h>
#include <stddef.h>

#define REST_MAX_ID_NUM     3
#define REST_MAX_ID_LEN     32

typedef struct rest_node_rw_tag rest_node_rw_t;
typedef int (*rest_handler)(void *, rest_node_rw_t *);

typedef struct {
    const char *uri_pattern;
    rest_handler handler;
    uint8_t http_method_mask;
} rest_node_ro_t;

typedef union {
    rest_node_ro_t node;
    uint8_t space[32];
} rest_node_space_t;

typedef struct rest_node_rw_tag {
    rest_handler handler;
    char id[REST_MAX_ID_NUM][REST_MAX_ID_LEN];
} rest_node_rw_t;

#define REST_BIND3(_name, _uri, _mask, _handler) \
    static __attribute__((section("rest_node"))) rest_node_space_t __rest_node_##_name = { \
        .node.uri_pattern = _uri, \
        .node.http_method_mask = _mask, \
        .node.handler = _handler, \
    };

#define REST_BIND2(_name, _uri, _mask, _handler) REST_BIND3(_name, _uri, _mask, _handler) \

#define REST_BIND(_uri, _mask, _handler) REST_BIND2(__COUNTER__, _uri, _mask, _handler) \



int rest_init(void);
int rest_destroy(void);
int rest_handler_find(const char *_uri, const int method, rest_node_rw_t *rw);
#endif