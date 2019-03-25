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
  add_edge(G, 4, 2);
  printf("--------------------------------\n");
  printf("DFS: \n");
  dfs(G, 1);
  return 0;
}
