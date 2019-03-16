#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

int main(int argc, char const *argv[]) {
  fprintf(stdout, "%s\n", (char*)"------ graph with adjacency list implementation ------");
  graph_t* G = (graph_t*)malloc(sizeof(graph_t));
  init_graph(G,6);
  add_vertex(G,0);
  add_vertex(G,1);
  add_vertex(G,2);
  add_vertex(G,3);
  add_vertex(G,4);
  add_vertex(G,5);
  add_edge(G, 0, 4);
  add_edge(G, 0, 5);
  add_edge(G, 1, 4);
  add_edge(G, 4, 3);
  add_edge(G, 5, 1);
  add_edge(G, 3, 1);
  add_edge(G, 3, 4);
  printf("--------------------------------\n");
  printf("degree of vertice 5 = %d \n", get_degree_of(G,5));
  printf("degree of vertice 3 = %d \n", get_degree_of(G,3));
  printf("direct path between (0,4) = %d \n", direct_path_exists(G,0,4));
  printf("direct path between (0,3) = %d \n", direct_path_exists(G,0,3));
  printf("path between (0,3) = %d \n", path_exists(G,0,3));
  printf("path between (0,2) = %d \n", path_exists(G,0,2));
  return 0;
}
