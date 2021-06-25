#include <stdio.h>
#include "rest_node.h"
#include "http.h"
#include "r3/r3.h"

#define REST_NODE_FOR_EACH(_p) \
    for (_p = (rest_node_t*)&__start_rest_node; \
            (size_t)_p < (size_t)&__stop_rest_node; \
            _p= (rest_node_t*)((uint8_t*)_p+sizeof(rest_node_space_t)))

extern size_t __start_rest_node;
extern size_t __stop_rest_node;

static  R3Node * n = NULL;

int rest_init(void)
{
    rest_node_t *pNode = NULL;

    n = r3_tree_create(3);

    REST_NODE_FOR_EACH(pNode) {
        r3_tree_insert_routel(n, pNode->http_method_mask, pNode->uri_pattern, strlen(pNode->uri_pattern), pNode->handler);
    }
    char *errstr = NULL;
    int err = r3_tree_compile(n, &errstr);
    if(err) {
        printf("%s\n",errstr);
        free(errstr);
        return -1;
    }
    printf("rest init ok\n");
    return 0;
}

int rest_destroy(void)
{
    r3_tree_free(n);
}

rest_handler rest_handler_find(const char *_uri)
{
    match_entry * entry;
    R3Route *matched_route;
    size_t i;
    rest_handler handler = NULL;

    entry = match_entry_create(_uri);
    entry->request_method = METHOD_GET;
    matched_route = r3_tree_match_route(n, entry);
    if (matched_route) {
        printf("%s %d\n", __func__, __LINE__);
        handler = (rest_handler)matched_route->data;
        if (entry->vars.tokens.size == entry->vars.slugs.size) {
            for (i = 0; i < entry->vars.tokens.size; i++) {
                // entry->vars.slugs.entries[i];
                // entry->vars.tokens.entries[i];
                printf("Slug name is: %*.*s\n",entry->vars.slugs.entries[i].len,
                    entry->vars.slugs.entries[i].len, entry->vars.slugs.entries[i].base);
                printf("Slug value is: %*.*s\n",entry->vars.tokens.entries[i].len,
                    entry->vars.tokens.entries[i].len, entry->vars.tokens.entries[i].base);
            }
        } else {
            printf("Slugs and tokens sizes are not equal\n");
            for (i = 0; i < entry->vars.slugs.size; i++) {
                printf("Slug name is: %*.*s\n",entry->vars.slugs.entries[i].len,
                    entry->vars.slugs.entries[i].len, entry->vars.slugs.entries[i].base);
            }
            for (i = 0; i < entry->vars.tokens.size; i++) {
                printf("Slug value is: %*.*s\n",entry->vars.tokens.entries[i].len,
                    entry->vars.tokens.entries[i].len, entry->vars.tokens.entries[i].base);
            }
        }
    }
    // free the objects at the end
    match_entry_free(entry);
    return handler;
}

int rest_process(void *p)
{

}