#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "http.h"



http_t http_create(void)
{
    http_priv_t http;

    http = malloc(sizeof(*http));
    if (http) {
        memset(http, 0, sizeof(*http));
    }

    return (http_t)http;
}

void http_free(http_t *p)
{
    free(*p);
    *p = NULL;
}

int http_buffer_data(http_t p, const char *data, size_t len)
{
    http_priv_t priv = (http_priv_t)p;
    size_t l = len > (sizeof(priv->buffered_len) - priv->buffered_len) ?
                    (sizeof(priv->buffered_len) - priv->buffered_len) : len;
    memcpy(&priv->buffer[priv->buffered_len], data, l);
    priv->buffered_len += l;
    return 0;
}

int http_parse_data(http_t p)
{
    http_priv_t priv = (http_priv_t)p;


    return 0;
}

uint8_t http_method_get(http_t p)
{
    return ((http_priv_t)p)->method;
}