#include <stdlib.h>
#include <stdio.h>

#include "graph.h"

int main(int argc, char **argv) {
    Graph *g = Graph_create();
    g->node_count = 10;

    printf("node count %d\n", g->node_count);
    return 0;
}
