#include "rest_node.h"
#include "http.h"

#include <stdio.h>

static int rest_systems_collection_handler(void *p, rest_node_rw_t *rw)
{
    printf("%s %d\n", __func__, __LINE__);
    uint8_t i;
    switch (http_method_get(p)) {
        case HTTP_METHOD_GET:
            printf("%s %d\n", __func__, __LINE__);
            for (i = 0; rw->id[i][0] != 0; i++) {
                printf("id:%d val:%s\n", i, rw->id[i]);
            }
            return 0;
        default:
            printf("%s %d invalid method %x\n", __func__, __LINE__, http_method_get(p));
            return -1;
    }
}

static int rest_systems_system_handler(void *p, rest_node_rw_t *rw)
{
    printf("%s %d\n", __func__, __LINE__);
    uint8_t i;
    switch (http_method_get(p)) {
        case HTTP_METHOD_GET:
            printf("%s %d\n", __func__, __LINE__);
            for (i = 0; rw->id[i][0] != 0; i++) {
                printf("id:%d val:%s\n", i, rw->id[i]);
            }
            return 0;
        default:
            printf("%s %d invalid method %x\n", __func__, __LINE__, http_method_get(p));
            return -1;
    }
}
REST_BIND("/redfish/v1/Systems", HTTP_METHOD_GET, rest_systems_collection_handler);
REST_BIND("/redfish/v1/Systems/{id}", HTTP_METHOD_GET, rest_systems_system_handler);

static int rest_systems_actions_collection_handler(void *p, rest_node_rw_t *rw)
{
    const char *system_id = rw->id[0];

    printf("%s %d system:%s\n", __func__, __LINE__, system_id);

    switch (http_method_get(p)) {
        case HTTP_METHOD_GET:
            return 0;
        default:
            printf("%s %d invalid method %x\n", __func__, __LINE__, http_method_get(p));
            return -1;
    }
}

static int rest_systems_actions_reset_handler(void *p, rest_node_rw_t *rw)
{
    const char *system_id = rw->id[0];

    printf("%s %d system:%s\n", __func__, __LINE__, system_id);

    switch (http_method_get(p)) {
        case HTTP_METHOD_POST:
            return 0;
        default:
            printf("%s %d invalid method %x\n", __func__, __LINE__, http_method_get(p));
            return -1;
    }
}
REST_BIND("/redfish/v1/Systems/{id}/Actions", HTTP_METHOD_GET, rest_systems_actions_collection_handler);
REST_BIND("/redfish/v1/Systems/{id}/Actions/ComputerSystem.Reset", HTTP_METHOD_POST, rest_systems_actions_reset_handler);

static int rest_systems_processors_collection_handler(void *p, rest_node_rw_t *rw)
{
    const char *system_id = rw->id[0];

    printf("%s %d system:%s\n", __func__, __LINE__, system_id);

    switch (http_method_get(p)) {
        case HTTP_METHOD_GET:
            return 0;
        default:
            printf("%s %d invalid method %x\n", __func__, __LINE__, http_method_get(p));
            return -1;
    }
}

static int rest_systems_processors_processor_handler(void *p, rest_node_rw_t *rw)
{
    const char *system_id = rw->id[0];
    const char *processor_id = rw->id[1];

    printf("%s %d system:%s processor:%s\n", __func__, __LINE__, system_id, processor_id);

    switch (http_method_get(p)) {
        case HTTP_METHOD_GET:
            return 0;
        default:
            printf("%s %d invalid method %x\n", __func__, __LINE__, http_method_get(p));
            return -1;
    }
}

REST_BIND("/redfish/v1/Systems/{id}/Processors", HTTP_METHOD_GET, rest_systems_processors_collection_handler);
REST_BIND("/redfish/v1/Systems/{id}/Processors/{id}", HTTP_METHOD_GET, rest_systems_processors_processor_handler);
#if 0
REST_BIND(Systems5, "/redfish/v1/Systems/{id}/Memory", HTTP_METHOD_GET, rest_systems_handler);
REST_BIND(Systems6, "/redfish/v1/Systems/{id}/Memory/{id}", HTTP_METHOD_GET, rest_systems_handler);

REST_BIND(Systems5, "/redfish/v1/Systems/{id}/EthernetInterfaces", HTTP_METHOD_GET, rest_systems_handler);
REST_BIND(Systems6, "/redfish/v1/Systems/{id}/EthernetInterfaces/{id}", HTTP_METHOD_GET, rest_systems_handler);
REST_BIND(Systems6, "/redfish/v1/Systems/{id}/EthernetInterfaces/{id}/VLANs", HTTP_METHOD_GET, rest_systems_handler);
REST_BIND(Systems6, "/redfish/v1/Systems/{id}/EthernetInterfaces/{id}/VLANs/{id}", HTTP_METHOD_GET, rest_systems_handler);

REST_BIND(Systems6, "/redfish/v1/Systems/{id}/Storages", HTTP_METHOD_GET, rest_systems_handler);
REST_BIND(Systems6, "/redfish/v1/Systems/{id}/Storages/{id}", HTTP_METHOD_GET, rest_systems_handler);
REST_BIND(Systems6, "/redfish/v1/Systems/{id}/Storages/{id}/Volumes", HTTP_METHOD_GET, rest_systems_handler);
REST_BIND(Systems6, "/redfish/v1/Systems/{id}/Storages/{id}/Volumes/{id}", HTTP_METHOD_GET, rest_systems_handler);

REST_BIND(Systems6, "/redfish/v1/Systems/{id}/NetworkInterfaces", HTTP_METHOD_GET, rest_systems_handler);
REST_BIND(Systems6, "/redfish/v1/Systems/{id}/NetworkInterfaces/{id}", HTTP_METHOD_GET, rest_systems_handler);
REST_BIND(Systems6, "/redfish/v1/Systems/{id}/NetworkInterfaces/{id}/NetworkPorts", HTTP_METHOD_GET, rest_systems_handler);

REST_BIND(Systems6, "/redfish/v1/Systems/{id}/LogServices", HTTP_METHOD_GET, rest_systems_handler);
REST_BIND(Systems6, "/redfish/v1/Systems/{id}/LogServices/{id}", HTTP_METHOD_GET, rest_systems_handler);
REST_BIND(Systems6, "/redfish/v1/Systems/{id}/LogServices/{id}/Entries", HTTP_METHOD_GET, rest_systems_handler);
REST_BIND(Systems6, "/redfish/v1/Systems/{id}/LogServices/{id}/Entries/{id}", HTTP_METHOD_GET, rest_systems_handler);


REST_BIND(Systems6, "/redfish/v1/Systems/{id}/Bios/Settings", HTTP_METHOD_GET, rest_systems_handler);
REST_BIND(Systems6, "/redfish/v1/Systems/{id}/ProcessorsHistoryUsageRate", HTTP_METHOD_GET, rest_systems_handler);
REST_BIND(Systems6, "/redfish/v1/Systems/{id}/MemoryHistoryUsageRate", HTTP_METHOD_GET, rest_systems_handler);
REST_BIND(Systems6, "/redfish/v1/Systems/{id}/NetworkHistoryUsageRate", HTTP_METHOD_GET, rest_systems_handler);
#endif