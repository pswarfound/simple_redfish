#include "rest/rest_node.h"
#include "http/http.h"

#include <stdio.h>

static int rest_systems_handler()
{
    printf("%s %d\n", __func__, __LINE__);
    return 0;
}

REST_BIND(Managers1, "/redfish/v1/Managers", HTTP_METHOD_GET, rest_systems_handler);
REST_BIND(Managers2, "/redfish/v1/Managers/:id", HTTP_METHOD_GET, rest_systems_handler);
REST_BIND(Managers3, "/redfish/v1/Managers/:id/EthernetInterfaces", HTTP_METHOD_GET, rest_systems_handler);
REST_BIND(Manager4, "/redfish/v1/Managers/:id/EthernetInterfaces/:id", HTTP_METHOD_GET, rest_systems_handler);
REST_BIND(Managers5, "/redfish/v1/Managers/:id/NetworkProtocol", HTTP_METHOD_GET, rest_systems_handler);
REST_BIND(Managers6, "/redfish/v1/Managers/:id/SecurityService", HTTP_METHOD_GET, rest_systems_handler);
REST_BIND(Managers7, "/redfish/v1/Managers/:id/SecurityService/HttpsCert", HTTP_METHOD_GET, rest_systems_handler);
REST_BIND(Managers8, "/redfish/v1/Managers/:id/VirtualMedia/CD", HTTP_METHOD_GET, rest_systems_handler);
REST_BIND(Managers9, "/redfish/v1/Managers/:id/VirtualMedia/USBStick", HTTP_METHOD_GET, rest_systems_handler);
REST_BIND(Managersa, "/redfish/v1/Managers/:id/SnmpService", HTTP_METHOD_GET, rest_systems_handler);
