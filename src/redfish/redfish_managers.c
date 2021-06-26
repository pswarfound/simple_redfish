#include "rest_node.h"
#include "http.h"

#include <stdio.h>

static int rest_systems_handler(void *p, rest_node_rw_t *rw)
{
    printf("%s %d %s\n", __func__, __LINE__, p);
    return 0;
}

REST_BIND("/redfish/v1/Managers", HTTP_METHOD_GET, rest_systems_handler);
REST_BIND("/redfish/v1/Managers/{id}", HTTP_METHOD_GET, rest_systems_handler);
REST_BIND("/redfish/v1/Managers/{id}/EthernetInterfaces", HTTP_METHOD_GET, rest_systems_handler);
REST_BIND("/redfish/v1/Managers/{id}/EthernetInterfaces/{id}", HTTP_METHOD_GET, rest_systems_handler);
REST_BIND("/redfish/v1/Managers/{id}/NetworkProtocol", HTTP_METHOD_GET, rest_systems_handler);
REST_BIND("/redfish/v1/Managers/{id}/SecurityService", HTTP_METHOD_GET, rest_systems_handler);
REST_BIND("/redfish/v1/Managers/{id}/SecurityService/HttpsCert", HTTP_METHOD_GET, rest_systems_handler);
REST_BIND("/redfish/v1/Managers/{id}/VirtualMedia/CD", HTTP_METHOD_GET, rest_systems_handler);
REST_BIND("/redfish/v1/Managers/{id}/VirtualMedia/USBStick", HTTP_METHOD_GET, rest_systems_handler);
REST_BIND("/redfish/v1/Managers/{id}/SnmpService", HTTP_METHOD_GET, rest_systems_handler);
