#include "rest/rest_node.h"
#include "http/http.h"

#include <stdio.h>

static int rest_systems_handler()
{
    printf("%s %d\n", __func__, __LINE__);
    return 0;
}

REST_BIND(systems, "/redfish/v1/Systems", HTTP_METHOD_GET, rest_systems_handler);
REST_BIND(systems_id, "/redfish/v1/Systems/:id", HTTP_METHOD_GET, rest_systems_handler);

REST_BIND(systems_id_processors, "/redfish/v1/Systems/:id/Processors", HTTP_METHOD_GET, rest_systems_handler);
REST_BIND(systems_id_processors_id, "/redfish/v1/Systems/:id/Processors/:id", HTTP_METHOD_GET, rest_systems_handler);

REST_BIND(Systems5, "/redfish/v1/Systems/:id/Memory", HTTP_METHOD_GET, rest_systems_handler);
REST_BIND(Systems6, "/redfish/v1/Systems/:id/Memory/:id", HTTP_METHOD_GET, rest_systems_handler);

REST_BIND(Systems5, "/redfish/v1/Systems/:id/EthernetInterfaces", HTTP_METHOD_GET, rest_systems_handler);
REST_BIND(Systems6, "/redfish/v1/Systems/:id/EthernetInterfaces/:id", HTTP_METHOD_GET, rest_systems_handler);
REST_BIND(Systems6, "/redfish/v1/Systems/:id/EthernetInterfaces/:id/VLANs", HTTP_METHOD_GET, rest_systems_handler);
REST_BIND(Systems6, "/redfish/v1/Systems/:id/EthernetInterfaces/:id/VLANs/:id", HTTP_METHOD_GET, rest_systems_handler);

REST_BIND(Systems6, "/redfish/v1/Systems/:id/Storages", HTTP_METHOD_GET, rest_systems_handler);
REST_BIND(Systems6, "/redfish/v1/Systems/:id/Storages/:id", HTTP_METHOD_GET, rest_systems_handler);
REST_BIND(Systems6, "/redfish/v1/Systems/:id/Storages/:id/Volumes", HTTP_METHOD_GET, rest_systems_handler);
REST_BIND(Systems6, "/redfish/v1/Systems/:id/Storages/:id/Volumes/:id", HTTP_METHOD_GET, rest_systems_handler);

REST_BIND(Systems6, "/redfish/v1/Systems/:id/NetworkInterfaces", HTTP_METHOD_GET, rest_systems_handler);
REST_BIND(Systems6, "/redfish/v1/Systems/:id/NetworkInterfaces/:id", HTTP_METHOD_GET, rest_systems_handler);
REST_BIND(Systems6, "/redfish/v1/Systems/:id/NetworkInterfaces/:id/NetworkPorts", HTTP_METHOD_GET, rest_systems_handler);

REST_BIND(Systems6, "/redfish/v1/Systems/:id/LogServices", HTTP_METHOD_GET, rest_systems_handler);
REST_BIND(Systems6, "/redfish/v1/Systems/:id/LogServices/:id", HTTP_METHOD_GET, rest_systems_handler);
REST_BIND(Systems6, "/redfish/v1/Systems/:id/LogServices/:id/Entries", HTTP_METHOD_GET, rest_systems_handler);
REST_BIND(Systems6, "/redfish/v1/Systems/:id/LogServices/:id/Entries/:id", HTTP_METHOD_GET, rest_systems_handler);


REST_BIND(Systems6, "/redfish/v1/Systems/:id/Bios/Settings", HTTP_METHOD_GET, rest_systems_handler);
REST_BIND(Systems6, "/redfish/v1/Systems/:id/ProcessorsHistoryUsageRate", HTTP_METHOD_GET, rest_systems_handler);
REST_BIND(Systems6, "/redfish/v1/Systems/:id/MemoryHistoryUsageRate", HTTP_METHOD_GET, rest_systems_handler);
REST_BIND(Systems6, "/redfish/v1/Systems/:id/NetworkHistoryUsageRate", HTTP_METHOD_GET, rest_systems_handler);
