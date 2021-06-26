
#include <stdio.h>
#include "rest_node.h"
#include "http.h"


static int rest_ports_id_handler(void *p, rest_node_rw_t *rw)
{
    printf("%s %d\n", __func__, __LINE__);

    switch(http_method_get(p)) {
        case HTTP_METHOD_GET:
            return 0;
        default:
            return -1;
    }
}

REST_BIND("/redfish/v1/CompositionService/ResourceBlocks/{id}/Storage/{id}/StorageControllers/{id}/Ports/{id}", HTTP_METHOD_GET, rest_ports_id_handler);