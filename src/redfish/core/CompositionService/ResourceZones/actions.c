
#include <stdio.h>
#include "rest_node.h"
#include "http.h"


static int rest_zone_addendpoint_handler(void *p, rest_node_rw_t *rw)
{
    printf("%s %d\n", __func__, __LINE__);

    switch(http_method_get(p)) {

        case HTTP_METHOD_PUT:
            return 0;

        default:
            return -1;
    }
}

REST_BIND("/redfish/v1/CompositionService/ResourceZones/{id}/Actions/Zone.AddEndpoint", HTTP_METHOD_PUT, rest_zone_addendpoint_handler);

static int rest_zone_removeendpoint_handler(void *p, rest_node_rw_t *rw)
{
    printf("%s %d\n", __func__, __LINE__);

    switch(http_method_get(p)) {

        case HTTP_METHOD_PUT:
            return 0;

        default:
            return -1;
    }
}

REST_BIND("/redfish/v1/CompositionService/ResourceZones/{id}/Actions/Zone.RemoveEndpoint", HTTP_METHOD_PUT, rest_zone_removeendpoint_handler);
