#ifndef __GRAPH_X__
#define __GRAPH_X__
#include "list.h"

#define UPDATE_VERTICES(g) (g->nb_vertices++);

typedef node_t adj_list_t ;
typedef struct graph graph_t;

struct graph {
  int nb_vertices;
  adj_list_t list[];
};

#endif /* end of include guard: __GRAPH_X__ */
