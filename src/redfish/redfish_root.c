#include "rest_node.h"
#include "http.h"

#include <stdio.h>

static int rest_systems_handler()
{
    printf("%s %d\n", __func__, __LINE__);
    return 0;
}
REST_BIND(Root, "/redfish", HTTP_METHOD_GET, rest_systems_handler);
REST_BIND(Root1, "/redfish/v1", HTTP_METHOD_GET, rest_systems_handler);
REST_BIND(Root2, "/redfish/v1/$metadata", HTTP_METHOD_GET, rest_systems_handler);
REST_BIND(Root3, "/redfish/v1/JSONSchemas", HTTP_METHOD_GET, rest_systems_handler);
REST_BIND(Root4, "/redfish/v1/Registries", HTTP_METHOD_GET, rest_systems_handler);
REST_BIND(Root5, "/redfish/v1/Registries/:id", HTTP_METHOD_GET, rest_systems_handler);
REST_BIND(Root6, "/redfish/v1/odata", HTTP_METHOD_GET, rest_systems_handler);
