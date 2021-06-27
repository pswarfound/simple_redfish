#include <stdio.h>
#include <string.h>
#include "http.h"
#include "rest_node.h"

void http_handler(con_t con)
{
    rest_node_rw_t rw;
    int ret = rest_handler_find(http_uri_get(con), http_method_get(con), &rw);
    if (rw.handler != NULL) {
        rw.handler(con, &rw);
    }
}

int main(int argc, char **argv)
{
    rest_init();
    
    http_t http = http_create();
    http_start(http, http_handler);
    getchar();
    http_destroy(http);

    rest_destroy();

    return 0;
}
