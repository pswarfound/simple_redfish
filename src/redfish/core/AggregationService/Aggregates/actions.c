
#include <stdio.h>
#include "rest_node.h"
#include "http.h"


static int rest_aggregate_removeelements_handler(void *p, rest_node_rw_t *rw)
{
    printf("%s %d\n", __func__, __LINE__);

    switch(http_method_get(p)) {

        case HTTP_METHOD_PUT:
            return 0;

        default:
            return -1;
    }
}

REST_BIND("/redfish/v1/AggregationService/Aggregates/{id}/Actions/Aggregate.RemoveElements", HTTP_METHOD_PUT, rest_aggregate_removeelements_handler);

static int rest_aggregate_addelements_handler(void *p, rest_node_rw_t *rw)
{
    printf("%s %d\n", __func__, __LINE__);

    switch(http_method_get(p)) {

        case HTTP_METHOD_PUT:
            return 0;

        default:
            return -1;
    }
}

REST_BIND("/redfish/v1/AggregationService/Aggregates/{id}/Actions/Aggregate.AddElements", HTTP_METHOD_PUT, rest_aggregate_addelements_handler);

static int rest_aggregate_reset_handler(void *p, rest_node_rw_t *rw)
{
    printf("%s %d\n", __func__, __LINE__);

    switch(http_method_get(p)) {

        case HTTP_METHOD_PUT:
            return 0;

        default:
            return -1;
    }
}

REST_BIND("/redfish/v1/AggregationService/Aggregates/{id}/Actions/Aggregate.Reset", HTTP_METHOD_PUT, rest_aggregate_reset_handler);

static int rest_aggregate_setdefaultbootorder_handler(void *p, rest_node_rw_t *rw)
{
    printf("%s %d\n", __func__, __LINE__);

    switch(http_method_get(p)) {

        case HTTP_METHOD_PUT:
            return 0;

        default:
            return -1;
    }
}

REST_BIND("/redfish/v1/AggregationService/Aggregates/{id}/Actions/Aggregate.SetDefaultBootOrder", HTTP_METHOD_PUT, rest_aggregate_setdefaultbootorder_handler);
