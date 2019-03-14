#include "graph.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * init_graph
 * @cost O(1)
 * @param  g
 * @param  vertices
 * @return success|error
 */
int init_graph(graph_t* g, int vertices) {
  SET_VERTICES(g,vertices);
  g->list = ALLOCATE_ARRAY(adjacency_list_t, vertices);
  return 0;
}

/**
 * get_hash
 * @param  c
 * @return   hash
 */
int get_hash(int c) {
  return c;
}

/**
 * make_vertice
 * @cost O(1)
 * @param  d
 * @return  vertice_t
 */
vertice_t make_vertice(int d) {
  node_t elm = make_node(d);
  vertice_t v = (vertice_t)malloc(sizeof(vertice));
  if (!v) {
    fprintf(stderr, "error: malloc()\n");
    exit(-1);
  }
  v->hash = get_hash(d);
  v->e = elm;
  return v;
}

/**
 * add_vertices
 * @cost O(1)
 * @param g
 * @param v
 */
void add_vertices(graph_t* g, int v) {
  vertice_t vt = make_vertice(v);
  int h = vt->hash;
  if (g->list[h] != NULL) {
    fprintf(stderr, "element already exists !!\n");
    return;
  }
  g->list[vt->hash] = vt;
}


/**
 * add_edge
 * @cost O(m) where m is the length of vertex neighbors
 * @param g
 * @param src
 * @param dest
 */
void add_edge(graph_t* g, int src, int dest) {
  int h = get_hash(src);
  vertice_t vt = g->list[h];
  push_new_element(vt->e, dest);
  h = get_hash(dest);
  vt = g->list[h];
  push_new_element(vt->e, src);
}

/**
 * @cost
 * @param  v
 * @return degree
 */
int get_degree_of(graph_t* g, int v) {
  int h = get_hash(v);
  vertice_t vt = g->list[h];
  return get_list_length(vt->e) - 1;
}

int direct_path_exists(graph_t* g, int u, int v) {
  int h = get_hash(u);
  vertice_t vt = g->list[h];
  return list_contains(vt->e, v);
}


int path_exists(graph_t* g, int src, int dest) {
  int h = get_hash(src);
  vertice_t vt = g->list[h];
  if (list_contains(vt->e, dest) > 0) {
    return 1;
  }
  if (vt->e->next == NULL) {
    return -1;
  }
  int x = vt->e->next->data;
  vt->e = shift_element(vt->e);
  return path_exists(g,x,dest);
}
