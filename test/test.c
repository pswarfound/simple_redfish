#include "rest_node.h"
#include "http.h"
#include <stdio.h>
#include <string.h>

typedef struct {
    const char *method_str;
    int method;
} method_map_t;
method_map_t method_map[] = {
    {"GET", HTTP_METHOD_GET},
    {"PUT", HTTP_METHOD_PUT},
    {"POST", HTTP_METHOD_POST},
    {"PATCH", HTTP_METHOD_PATCH},
    {"DELETE", HTTP_METHOD_DELETE},
    {"HEAD", HTTP_METHOD_HEAD},
};

int main(int argc, char **argv)
{
    rest_init();
    do {
//        break;
        int method = 0;
        int i;
        for (i = 0; i < sizeof(method_map) / sizeof(method_map[0]);i++) {
            if (!strcmp(argv[2], method_map[i].method_str)) {
                method = method_map[i].method;
                break;
            }
        }
        if (!method) {
            break;
        }

        http_priv_t http = http_create();
        for (i = 0; i < 1;i++) {
            http->method = method;
            rest_node_rw_t rw;
            int ret = rest_handler_find(argv[1], method, &rw);
            if (rw.handler != NULL) {
                rw.handler(http, &rw);
            }
        }
        http_free((http_t*)&http);
    } while(0);

    rest_destroy();
    return 0;
}
