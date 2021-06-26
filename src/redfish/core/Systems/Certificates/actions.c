
#include <stdio.h>
#include "rest_node.h"
#include "http.h"


static int rest_certificate_renew_handler(void *p, rest_node_rw_t *rw)
{
    printf("%s %d\n", __func__, __LINE__);

    switch(http_method_get(p)) {

        case HTTP_METHOD_PUT:
            return 0;

        default:
            return -1;
    }
}

REST_BIND("/redfish/v1/Systems/{id}/Certificates/{id}/Actions/Certificate.Renew", HTTP_METHOD_PUT, rest_certificate_renew_handler);

static int rest_certificate_rekey_handler(void *p, rest_node_rw_t *rw)
{
    printf("%s %d\n", __func__, __LINE__);

    switch(http_method_get(p)) {

        case HTTP_METHOD_PUT:
            return 0;

        default:
            return -1;
    }
}

REST_BIND("/redfish/v1/Systems/{id}/Certificates/{id}/Actions/Certificate.Rekey", HTTP_METHOD_PUT, rest_certificate_rekey_handler);
