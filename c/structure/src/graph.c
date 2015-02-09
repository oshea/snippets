#include <stdlib.h>

#include "graph.h"

Graph *Graph_create() {
  Graph *g = malloc(sizeof(Graph));

  return g;
}
