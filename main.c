#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

int main(int argc, char const *argv[]) {
  fprintf(stdout, "%s\n", (char*)"------ graph with adjacency list implementation ------");
  graph_t* G = (graph_t*)malloc(sizeof(graph_t));
  init_graph(G,6);
  add_vertices(G,1);
  add_vertices(G,2);
  add_vertices(G,3);
  add_vertices(G,4);
  add_vertices(G,5);
  add_vertices(G,6);
  printf("vertices :\n");
  PRINT_VERTICES(G);
  printf("-------------------------------\n");
  add_edge(G, 1, 5);
  add_edge(G, 1, 6);
  add_edge(G, 1, 3);
  add_edge(G, 2, 5);
  add_edge(G, 5, 4);
  add_edge(G, 6, 2);
  add_edge(G, 4, 3);
  add_edge(G, 4, 2);
  add_edge(G, 4, 5);
  printf("neighbors of a:\n");
  PRINT_NEIGHBORS(G, 1);
  printf("-------------------------------\n");
  printf("neighbors of f:\n");
  PRINT_NEIGHBORS(G, 6);
  printf("--------------------------------\n");
  printf("degree of vertice f = %d \n", get_degree_of(G,6));
  printf("degree of vertice d = %d \n", get_degree_of(G,4));
  return 0;
}
