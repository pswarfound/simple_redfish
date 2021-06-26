
#include <stdio.h>
#include "rest_node.h"
#include "http.h"


static int rest_securebootdatabase_resetkeys_handler(void *p, rest_node_rw_t *rw)
{
    printf("%s %d\n", __func__, __LINE__);

    switch(http_method_get(p)) {

        case HTTP_METHOD_PUT:
            return 0;

        default:
            return -1;
    }
}

REST_BIND("/redfish/v1/Systems/{id}/SecureBoot/SecureBootDatabases/{id}/Actions/SecureBootDatabase.ResetKeys", HTTP_METHOD_PUT, rest_securebootdatabase_resetkeys_handler);