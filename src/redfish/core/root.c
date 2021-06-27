
#include <stdio.h>
#include "rest_node.h"
#include "http.h"


static int rest_redfish_handler(void *p, rest_node_rw_t *rw)
{
    printf("%s %d %d\n", __func__, __LINE__, http_method_get(p));

    switch(http_method_get(p)) {
        case HTTP_METHOD_GET:
        	http_printf(p,
	          "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\nConnection: "
	          "close\r\n\r\n");
            return 0;
        default:
            return -1;
    }
}

REST_BIND("/redfish", HTTP_METHOD_GET|HTTP_METHOD_PUT, rest_redfish_handler);

static int rest_v1_handler(void *p, rest_node_rw_t *rw)
{
    printf("%s %d\n", __func__, __LINE__);

    switch(http_method_get(p)) {
        case HTTP_METHOD_GET:
            return 0;
        default:
            return -1;
    }
}

REST_BIND("/redfish/v1", HTTP_METHOD_GET, rest_v1_handler);

static int rest_metadata_handler(void *p, rest_node_rw_t *rw)
{
    printf("%s %d\n", __func__, __LINE__);

    switch(http_method_get(p)) {
        case HTTP_METHOD_GET:
            return 0;
        default:
            return -1;
    }
}

REST_BIND("/redfish/v1/$metadata", HTTP_METHOD_GET, rest_metadata_handler);

static int rest_odata_handler(void *p, rest_node_rw_t *rw)
{
    printf("%s %d\n", __func__, __LINE__);

    switch(http_method_get(p)) {
        case HTTP_METHOD_GET:
            return 0;
        default:
            return -1;
    }
}

REST_BIND("/redfish/v1/odata", HTTP_METHOD_GET, rest_odata_handler);
