
#include <stdio.h>
#include "rest_node.h"
#include "http.h"


static int rest_volume_checkconsistency_handler(void *p, rest_node_rw_t *rw)
{
    printf("%s %d\n", __func__, __LINE__);

    switch(http_method_get(p)) {

        case HTTP_METHOD_PUT:
            return 0;

        default:
            return -1;
    }
}

REST_BIND("/redfish/v1/Storage/{id}/StoragePools/{id}/AllocatedVolumes/{id}/Actions/Volume.CheckConsistency", HTTP_METHOD_PUT, rest_volume_checkconsistency_handler);

static int rest_volume_splitreplication_handler(void *p, rest_node_rw_t *rw)
{
    printf("%s %d\n", __func__, __LINE__);

    switch(http_method_get(p)) {

        case HTTP_METHOD_PUT:
            return 0;

        default:
            return -1;
    }
}

REST_BIND("/redfish/v1/Storage/{id}/StoragePools/{id}/AllocatedVolumes/{id}/Actions/Volume.SplitReplication", HTTP_METHOD_PUT, rest_volume_splitreplication_handler);

static int rest_volume_removereplicarelationship_handler(void *p, rest_node_rw_t *rw)
{
    printf("%s %d\n", __func__, __LINE__);

    switch(http_method_get(p)) {

        case HTTP_METHOD_PUT:
            return 0;

        default:
            return -1;
    }
}

REST_BIND("/redfish/v1/Storage/{id}/StoragePools/{id}/AllocatedVolumes/{id}/Actions/Volume.RemoveReplicaRelationship", HTTP_METHOD_PUT, rest_volume_removereplicarelationship_handler);

static int rest_volume_suspendreplication_handler(void *p, rest_node_rw_t *rw)
{
    printf("%s %d\n", __func__, __LINE__);

    switch(http_method_get(p)) {

        case HTTP_METHOD_PUT:
            return 0;

        default:
            return -1;
    }
}

REST_BIND("/redfish/v1/Storage/{id}/StoragePools/{id}/AllocatedVolumes/{id}/Actions/Volume.SuspendReplication", HTTP_METHOD_PUT, rest_volume_suspendreplication_handler);

static int rest_volume_resumereplication_handler(void *p, rest_node_rw_t *rw)
{
    printf("%s %d\n", __func__, __LINE__);

    switch(http_method_get(p)) {

        case HTTP_METHOD_PUT:
            return 0;

        default:
            return -1;
    }
}

REST_BIND("/redfish/v1/Storage/{id}/StoragePools/{id}/AllocatedVolumes/{id}/Actions/Volume.ResumeReplication", HTTP_METHOD_PUT, rest_volume_resumereplication_handler);

static int rest_volume_assignreplicatarget_handler(void *p, rest_node_rw_t *rw)
{
    printf("%s %d\n", __func__, __LINE__);

    switch(http_method_get(p)) {

        case HTTP_METHOD_PUT:
            return 0;

        default:
            return -1;
    }
}

REST_BIND("/redfish/v1/Storage/{id}/StoragePools/{id}/AllocatedVolumes/{id}/Actions/Volume.AssignReplicaTarget", HTTP_METHOD_PUT, rest_volume_assignreplicatarget_handler);

static int rest_volume_createreplicatarget_handler(void *p, rest_node_rw_t *rw)
{
    printf("%s %d\n", __func__, __LINE__);

    switch(http_method_get(p)) {

        case HTTP_METHOD_PUT:
            return 0;

        default:
            return -1;
    }
}

REST_BIND("/redfish/v1/Storage/{id}/StoragePools/{id}/AllocatedVolumes/{id}/Actions/Volume.CreateReplicaTarget", HTTP_METHOD_PUT, rest_volume_createreplicatarget_handler);

static int rest_volume_reversereplicationrelationship_handler(void *p, rest_node_rw_t *rw)
{
    printf("%s %d\n", __func__, __LINE__);

    switch(http_method_get(p)) {

        case HTTP_METHOD_PUT:
            return 0;

        default:
            return -1;
    }
}

REST_BIND("/redfish/v1/Storage/{id}/StoragePools/{id}/AllocatedVolumes/{id}/Actions/Volume.ReverseReplicationRelationship", HTTP_METHOD_PUT, rest_volume_reversereplicationrelationship_handler);

static int rest_volume_changeraidlayout_handler(void *p, rest_node_rw_t *rw)
{
    printf("%s %d\n", __func__, __LINE__);

    switch(http_method_get(p)) {

        case HTTP_METHOD_PUT:
            return 0;

        default:
            return -1;
    }
}

REST_BIND("/redfish/v1/Storage/{id}/StoragePools/{id}/AllocatedVolumes/{id}/Actions/Volume.ChangeRAIDLayout", HTTP_METHOD_PUT, rest_volume_changeraidlayout_handler);

static int rest_volume_forceenable_handler(void *p, rest_node_rw_t *rw)
{
    printf("%s %d\n", __func__, __LINE__);

    switch(http_method_get(p)) {

        case HTTP_METHOD_PUT:
            return 0;

        default:
            return -1;
    }
}

REST_BIND("/redfish/v1/Storage/{id}/StoragePools/{id}/AllocatedVolumes/{id}/Actions/Volume.ForceEnable", HTTP_METHOD_PUT, rest_volume_forceenable_handler);

static int rest_volume_initialize_handler(void *p, rest_node_rw_t *rw)
{
    printf("%s %d\n", __func__, __LINE__);

    switch(http_method_get(p)) {

        case HTTP_METHOD_PUT:
            return 0;

        default:
            return -1;
    }
}

REST_BIND("/redfish/v1/Storage/{id}/StoragePools/{id}/AllocatedVolumes/{id}/Actions/Volume.Initialize", HTTP_METHOD_PUT, rest_volume_initialize_handler);
