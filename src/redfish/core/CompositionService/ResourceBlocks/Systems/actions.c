
#include <stdio.h>
#include "rest_node.h"
#include "http.h"


static int rest_computersystem_reset_handler(void *p, rest_node_rw_t *rw)
{
    printf("%s %d\n", __func__, __LINE__);

    switch(http_method_get(p)) {

        case HTTP_METHOD_PUT:
            return 0;

        default:
            return -1;
    }
}

REST_BIND("/redfish/v1/CompositionService/ResourceBlocks/{id}/Systems/{id}/Actions/ComputerSystem.Reset", HTTP_METHOD_PUT, rest_computersystem_reset_handler);

static int rest_computersystem_setdefaultbootorder_handler(void *p, rest_node_rw_t *rw)
{
    printf("%s %d\n", __func__, __LINE__);

    switch(http_method_get(p)) {

        case HTTP_METHOD_PUT:
            return 0;

        default:
            return -1;
    }
}

REST_BIND("/redfish/v1/CompositionService/ResourceBlocks/{id}/Systems/{id}/Actions/ComputerSystem.SetDefaultBootOrder", HTTP_METHOD_PUT, rest_computersystem_setdefaultbootorder_handler);

static int rest_computersystem_removeresourceblock_handler(void *p, rest_node_rw_t *rw)
{
    printf("%s %d\n", __func__, __LINE__);

    switch(http_method_get(p)) {

        case HTTP_METHOD_PUT:
            return 0;

        default:
            return -1;
    }
}

REST_BIND("/redfish/v1/CompositionService/ResourceBlocks/{id}/Systems/{id}/Actions/ComputerSystem.RemoveResourceBlock", HTTP_METHOD_PUT, rest_computersystem_removeresourceblock_handler);

static int rest_computersystem_addresourceblock_handler(void *p, rest_node_rw_t *rw)
{
    printf("%s %d\n", __func__, __LINE__);

    switch(http_method_get(p)) {

        case HTTP_METHOD_PUT:
            return 0;

        default:
            return -1;
    }
}

REST_BIND("/redfish/v1/CompositionService/ResourceBlocks/{id}/Systems/{id}/Actions/ComputerSystem.AddResourceBlock", HTTP_METHOD_PUT, rest_computersystem_addresourceblock_handler);
