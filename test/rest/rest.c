#include "rest_node.h"
#include "http.h"
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
    int ret;
  
    rest_init();
    do {
        int i;

        for (i = 0; i < 1;i++) {
            rest_node_rw_t rw;
            const char *uri = "/redfish/v1";
            int ret = rest_handler_find(uri, HTTP_METHOD_GET, &rw);
            if (rw.handler != NULL) {
                rw.handler(NULL, &rw);
            }
        }
    } while(0);

    rest_destroy();
    return 0;
}
