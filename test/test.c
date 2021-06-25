#include "rest_node.h"
#include "http.h"
#include "r3/r3.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    rest_init();
    do {
        rest_handler handler = rest_handler_find(argv[1]);
        if (handler != NULL) {
            handler(argv[1]);
        }
    } while(0);

    rest_destroy();
    return 0;
}
