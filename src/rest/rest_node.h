#ifndef __SIMPLE_REDFISH_REST_NODE_H__
#define __SIMPLE_REDFISH_REST_NODE_H__
#include <stdint.h>
#include <stddef.h>

typedef int (*rest_handler)(void *);

typedef struct rest_node_tag {
    const char *uri_pattern;
    rest_handler handler;
    uint8_t http_method_mask;
    uint8_t res[];
} rest_node_t;

typedef union {
    rest_node_t node;
    uint8_t space[32];
} rest_node_space_t;

#define REST_BIND(_name, _uri, _mask, _handler) \
    static __attribute__((section("rest_node"))) rest_node_space_t __rest_node_##_name = { \
        .node.uri_pattern = _uri, \
        .node.http_method_mask = _mask, \
        .node.handler = _handler, \
    };

#endif