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
int init_graph(graph_t* g) {
  SET_VERTICES(g,26);
  g->list = ALLOCATE_ARRAY(adjacency_list_t, 26);
  return 0;
}

/**
 * get_hash
 * @param  c
 * @return   hash
 */
int get_hash(char c) {
  if (c >= 65 && c <= 90) {
    return (int)(c - 65) % 26;
  }else if (c >= 97 && c <= 122) {
    return (int)(c - 97) % 26;
  }else {
    return 0x0;
  }
}

/**
 * make_vertice
 * @cost O(1)
 * @param  d
 * @return  vertice_t
 */
vertice_t make_vertice(char d) {
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
void add_vertices(graph_t* g, char v) {
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
 * non oriented graph
 * @param g
 * @param src
 * @param dest
 */
void add_edge(graph_t* g, char src, char dest) {
  int h = get_hash(src);
  vertice_t vt = g->list[h];
  push_new_element(vt->e, dest);
}
