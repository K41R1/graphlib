#ifndef __GRAPH_X__
#define __GRAPH_X__
#include "list.h"

#define GET_VERTICE_DATA(v) (v->e->data)
#define SET_VERTICES(g, n) (g->nb_vertices = n)
#define INC_VERTICES(g) (g->nb_vertices++)
#define ALLOCATE_ARRAY(type,size) ((type*)malloc(size * sizeof(type)))

#define PRINT_VERTICES(g) { \
  adjacency_list_t* l = g->list;\
  for (size_t i = 0; i < g->nb_vertices; i++) {\
      if (l[i] == NULL) {\
        continue;\
      }\
      printf("element %d\n", GET_VERTICE_DATA(l[i]));\
  }\
}

#define PRINT_NEIGHBORS(g,v) {\
  vertice_t vt = g->list[get_hash(v)];\
  PRINT_LIST(vt->e);\
}

typedef struct graph graph_t;
typedef struct vertice* vertice_t;
typedef struct vertice vertice;
typedef vertice_t adjacency_list_t ;

struct graph {
  int nb_vertices;
  adjacency_list_t* list;
};

struct vertice {
  int hash;
  node_t e;
};

int init_graph(graph_t*, int);
void add_vertices(graph_t*, int);
void add_edge(graph_t*, int, int);
vertice_t make_vertice(int);
int get_hash(int);
int get_degree_of(graph_t*, int);

#endif /* end of include guard: __GRAPH_X__ */
