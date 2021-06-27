#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "http.h"
#include "libhttp.h"

typedef struct {
    struct lh_ctx_t *ctx;
    void (*f)(void*);
} *http_priv_t;

typedef struct {
    struct lh_ctx_t *ctx;
    struct lh_con_t *conn;
} *con_priv_t;

typedef struct {
    const char *method_str;
    int method;
} method_map_t;

static method_map_t method_map[] = {
    {"GET", HTTP_METHOD_GET},
    {"PUT", HTTP_METHOD_PUT},
    {"POST", HTTP_METHOD_POST},
    {"PATCH", HTTP_METHOD_PATCH},
    {"DELETE", HTTP_METHOD_DELETE},
    {"HEAD", HTTP_METHOD_HEAD},
};

static int http_parse_method(const char *method, size_t l)
{
    uint8_t i;

    for (i = 0; i < sizeof(method_map) / sizeof(method_map[0]);i++) {
        if (!strncmp(method, method_map[i].method_str, l)) {
            return method_map[i].method;
        }
    }
    return 0;
}

uint8_t http_method_get(con_t p)
{
    con_priv_t priv = (con_priv_t)p;
    const struct lh_rqi_t *request_info = httplib_get_request_info(priv->conn);
    return http_parse_method(request_info->request_method, strlen(request_info->request_method));
}

const char *http_uri_get(con_t p)
{
    con_priv_t priv = (con_priv_t)p;
    const struct lh_rqi_t *request_info = httplib_get_request_info(priv->conn);
    return request_info->local_uri;
}

http_t http_create(void)
{
    http_priv_t priv = malloc(sizeof(*priv));
    return (http_t)priv;
}

static const struct lh_opt_t options[] = {
    {"listening_ports", "9080"},
    {"num_threads", "5"},
    {NULL}
};

static int begin_request_handler(struct lh_ctx_t *ctx, struct lh_con_t *conn)
{
    const struct lh_rqi_t *request_info = httplib_get_request_info(conn);
    int processed = 1;

    http_priv_t priv = request_info->user_data;
    con_priv_t con = malloc(sizeof(*con));
    con->ctx = ctx;
    con->conn = conn;
    priv->f(con);
    free(con);

    return processed;
}

static void httplib_alloc_callback( const char *file, unsigned line, const char *action, int64_t current_bytes, int64_t total_blocks, int64_t total_bytes )
{
    return;
    printf("%s %d %s %d\n", file, line, action, current_bytes);
}

int http_start(http_t http,  http_handler_t f)
{
    struct lh_clb_t callbacks;
    struct lh_ctx_t *ctx;
    http_priv_t priv = (http_t)http;
    priv->f = f;
    // Setup and start Civetweb
    memset(&callbacks, 0, sizeof(callbacks));
    callbacks.begin_request = begin_request_handler;
    if ((ctx = httplib_start(&callbacks, priv, options)) == NULL) {
        printf("%s\n", "Cannot start chat server, fatal exit");
        return -1;
    }
    httplib_set_alloc_callback_func(httplib_alloc_callback);
    priv->ctx = ctx;
    return 0;
}

int http_destroy(http_t http)
{
    http_priv_t priv = (http_t)http;
    httplib_stop(priv->ctx);
    free(http);
}

#include <stdarg.h>
int http_printf(con_t con, const char *fmt, ...)
{
    con_priv_t priv = (con_priv_t)con;
	va_list ap;
	int result;

	va_start( ap, fmt );
    httplib_printf(priv->ctx, priv->conn, fmt, ap);
    va_end( ap );

	return result;
}
