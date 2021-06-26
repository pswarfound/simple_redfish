
#include <stdio.h>
#include "rest_node.h"
#include "http.h"


static int rest_memory_unlockunit_handler(void *p, rest_node_rw_t *rw)
{
    printf("%s %d\n", __func__, __LINE__);

    switch(http_method_get(p)) {

        case HTTP_METHOD_PUT:
            return 0;

        default:
            return -1;
    }
}

REST_BIND("/redfish/v1/ResourceBlocks/{id}/Systems/{id}/Memory/{id}/Actions/Memory.UnlockUnit", HTTP_METHOD_PUT, rest_memory_unlockunit_handler);

static int rest_memory_secureeraseunit_handler(void *p, rest_node_rw_t *rw)
{
    printf("%s %d\n", __func__, __LINE__);

    switch(http_method_get(p)) {

        case HTTP_METHOD_PUT:
            return 0;

        default:
            return -1;
    }
}

REST_BIND("/redfish/v1/ResourceBlocks/{id}/Systems/{id}/Memory/{id}/Actions/Memory.SecureEraseUnit", HTTP_METHOD_PUT, rest_memory_secureeraseunit_handler);

static int rest_memory_disablepassphrase_handler(void *p, rest_node_rw_t *rw)
{
    printf("%s %d\n", __func__, __LINE__);

    switch(http_method_get(p)) {

        case HTTP_METHOD_PUT:
            return 0;

        default:
            return -1;
    }
}

REST_BIND("/redfish/v1/ResourceBlocks/{id}/Systems/{id}/Memory/{id}/Actions/Memory.DisablePassphrase", HTTP_METHOD_PUT, rest_memory_disablepassphrase_handler);

static int rest_memory_setpassphrase_handler(void *p, rest_node_rw_t *rw)
{
    printf("%s %d\n", __func__, __LINE__);

    switch(http_method_get(p)) {

        case HTTP_METHOD_PUT:
            return 0;

        default:
            return -1;
    }
}

REST_BIND("/redfish/v1/ResourceBlocks/{id}/Systems/{id}/Memory/{id}/Actions/Memory.SetPassphrase", HTTP_METHOD_PUT, rest_memory_setpassphrase_handler);

static int rest_memory_overwriteunit_handler(void *p, rest_node_rw_t *rw)
{
    printf("%s %d\n", __func__, __LINE__);

    switch(http_method_get(p)) {

        case HTTP_METHOD_PUT:
            return 0;

        default:
            return -1;
    }
}

REST_BIND("/redfish/v1/ResourceBlocks/{id}/Systems/{id}/Memory/{id}/Actions/Memory.OverwriteUnit", HTTP_METHOD_PUT, rest_memory_overwriteunit_handler);

static int rest_memory_reset_handler(void *p, rest_node_rw_t *rw)
{
    printf("%s %d\n", __func__, __LINE__);

    switch(http_method_get(p)) {

        case HTTP_METHOD_PUT:
            return 0;

        default:
            return -1;
    }
}

REST_BIND("/redfish/v1/ResourceBlocks/{id}/Systems/{id}/Memory/{id}/Actions/Memory.Reset", HTTP_METHOD_PUT, rest_memory_reset_handler);
