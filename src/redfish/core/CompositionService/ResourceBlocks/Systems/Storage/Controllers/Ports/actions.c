
#include <stdio.h>
#include "rest_node.h"
#include "http.h"


static int rest_port_reset_handler(void *p, rest_node_rw_t *rw)
{
    printf("%s %d\n", __func__, __LINE__);

    switch(http_method_get(p)) {

        case HTTP_METHOD_PUT:
            return 0;

        default:
            return -1;
    }
}

REST_BIND("/redfish/v1/CompositionService/ResourceBlocks/{id}/Systems/{id}/Storage/{id}/Controllers/{id}/Ports/{id}/Actions/Port.Reset", HTTP_METHOD_PUT, rest_port_reset_handler);
