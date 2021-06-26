
#include <stdio.h>
#include "rest_node.h"
#include "http.h"


static int rest_logservice_clearlog_handler(void *p, rest_node_rw_t *rw)
{
    printf("%s %d\n", __func__, __LINE__);

    switch(http_method_get(p)) {

        case HTTP_METHOD_PUT:
            return 0;

        default:
            return -1;
    }
}

REST_BIND("/redfish/v1/TelemetryService/LogService/Actions/LogService.ClearLog", HTTP_METHOD_PUT, rest_logservice_clearlog_handler);

static int rest_logservice_collectdiagnosticdata_handler(void *p, rest_node_rw_t *rw)
{
    printf("%s %d\n", __func__, __LINE__);

    switch(http_method_get(p)) {

        case HTTP_METHOD_PUT:
            return 0;

        default:
            return -1;
    }
}

REST_BIND("/redfish/v1/TelemetryService/LogService/Actions/LogService.CollectDiagnosticData", HTTP_METHOD_PUT, rest_logservice_collectdiagnosticdata_handler);
