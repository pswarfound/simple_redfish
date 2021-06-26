
#include <stdio.h>
#include "rest_node.h"
#include "http.h"


static int rest_powerdistribution_transfercontrol_handler(void *p, rest_node_rw_t *rw)
{
    printf("%s %d\n", __func__, __LINE__);

    switch(http_method_get(p)) {

        case HTTP_METHOD_PUT:
            return 0;

        default:
            return -1;
    }
}

REST_BIND("/redfish/v1/PowerEquipment/TransferSwitches/{id}/Actions/PowerDistribution.TransferControl", HTTP_METHOD_PUT, rest_powerdistribution_transfercontrol_handler);
