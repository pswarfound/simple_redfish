#include "rest_node.h"
#include "http.h"

#include <stdio.h>

static int rest_root_handler(void *p)
{
    printf("%s %d\n", __func__, __LINE__);

    switch (http_method_get(p)) {
        case HTTP_METHOD_GET:
            printf("%s %d\n", __func__, __LINE__);
            return 0;
        default:
            printf("%s %d invalid method %x\n", __func__, __LINE__, http_method_get(p));
            return -1;
    }
}

REST_BIND("/redfish", HTTP_METHOD_GET|HTTP_METHOD_PUT, rest_root_handler);
REST_BIND("/redfish/v1", HTTP_METHOD_GET, rest_root_handler);
REST_BIND("/redfish/v1/$metadata", HTTP_METHOD_GET, rest_root_handler);
REST_BIND("/redfish/v1/JSONSchemas", HTTP_METHOD_GET, rest_root_handler);
REST_BIND("/redfish/v1/Registries", HTTP_METHOD_GET, rest_root_handler);
REST_BIND("/redfish/v1/Registries/{id}", HTTP_METHOD_GET, rest_root_handler);
REST_BIND("/redfish/v1/odata/", HTTP_METHOD_GET, rest_root_handler);
