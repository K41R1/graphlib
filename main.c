#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

int main(int argc, char const *argv[]) {
  fprintf(stdout, "%s\n", (char*)"------ graph with adjacency list implementation ------");
  graph_t* G = (graph_t*)malloc(sizeof(graph_t));
  init_graph(G);
  add_vertices(G,'a');
  add_vertices(G,'b');
  add_vertices(G,'c');
  add_vertices(G,'d');
  add_vertices(G,'e');
  add_vertices(G,'f');
  printf("vertices :\n");
  PRINT_VERTICES(G);
  printf("-------------------------------\n");
  add_edge(G, 'a', 'e');
  add_edge(G, 'a', 'f');
  add_edge(G, 'a', 'c');
  printf("neighbors of a:\n");
  PRINT_NEIGHBORS(G,'a');
  printf("-------------------------------\n");
  return 0;
}
