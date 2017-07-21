#ifndef GRAPH_H
#define GRAPH_H

typedef struct Graph *graph;


graph createGraph(char directed);
void destroyGraph(graph g);

unsigned int getNoOfVertices(graph g);
unsigned int getNoOfEdges(graph g);

//printing graph different ways
void printGraph(graph g);
void bfs(graph g, int start);
void dfs(graph g, int start);
void recursive_dfs(graph g, int start);
void topological_sort(graph g);


//x and y are two vertex of an edge
//directed is needed for undirected graph since every edge
//occurs twice in a undirected graph, this flag is used
//to insert second time
int insertEdge(graph g,char directed, int x, int y, int weight);

#endif
