#include <stdio.h>
#include "rest_node.h"
#include "http.h"
#include "trie.h"

#define REST_NODE_FOR_EACH(_p) \
    for (_p = (rest_node_t*)&__start_rest_node; \
            (size_t)_p < (size_t)&__stop_rest_node; \
            _p= (rest_node_t*)((uint8_t*)_p+sizeof(rest_node_space_t)))

extern size_t __start_rest_node;
extern size_t __stop_rest_node;


int rest_init(void)
{
    rest_node_t *pNode = NULL;

    REST_NODE_FOR_EACH(pNode) {
        printf("%s\n", pNode->uri_pattern);
    }

    return 0;
}

rest_handler reset_handler_find(const char *_uri)
{
    return NULL;
}

int rest_process(void *p)
{

}