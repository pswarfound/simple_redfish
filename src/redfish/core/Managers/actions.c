
#include <stdio.h>
#include "rest_node.h"
#include "http.h"


static int rest_manager_reset_handler(void *p, rest_node_rw_t *rw)
{
    printf("%s %d\n", __func__, __LINE__);

    switch(http_method_get(p)) {

        case HTTP_METHOD_PUT:
            return 0;

        default:
            return -1;
    }
}

REST_BIND("/redfish/v1/Managers/{id}/Actions/Manager.Reset", HTTP_METHOD_PUT, rest_manager_reset_handler);

static int rest_manager_modifyredundancyset_handler(void *p, rest_node_rw_t *rw)
{
    printf("%s %d\n", __func__, __LINE__);

    switch(http_method_get(p)) {

        case HTTP_METHOD_PUT:
            return 0;

        default:
            return -1;
    }
}

REST_BIND("/redfish/v1/Managers/{id}/Actions/Manager.ModifyRedundancySet", HTTP_METHOD_PUT, rest_manager_modifyredundancyset_handler);

static int rest_manager_forcefailover_handler(void *p, rest_node_rw_t *rw)
{
    printf("%s %d\n", __func__, __LINE__);

    switch(http_method_get(p)) {

        case HTTP_METHOD_PUT:
            return 0;

        default:
            return -1;
    }
}

REST_BIND("/redfish/v1/Managers/{id}/Actions/Manager.ForceFailover", HTTP_METHOD_PUT, rest_manager_forcefailover_handler);

static int rest_manager_resettodefaults_handler(void *p, rest_node_rw_t *rw)
{
    printf("%s %d\n", __func__, __LINE__);

    switch(http_method_get(p)) {

        case HTTP_METHOD_PUT:
            return 0;

        default:
            return -1;
    }
}

REST_BIND("/redfish/v1/Managers/{id}/Actions/Manager.ResetToDefaults", HTTP_METHOD_PUT, rest_manager_resettodefaults_handler);
