#include <stdio.h>
#include <malloc.h>

#include "graph.h"
#include "queue.h"
#include "stack.h"


#define MAXV 100


enum graphNodeStates {
	NODE_UNDISCOVERED,
	NODE_DISCOVERED,
	NODE_PROCESSED
};

enum graphNodeStates gNodeState[MAXV];

struct edgeNode {
	int vertex;
	int weight;
	struct edgeNode *next;
};

struct Graph {
	struct edgeNode *edge[MAXV + 1];
	char degree[MAXV + 1];
	unsigned int nVertices;
	unsigned int nEdges;
	char directed;
};

void initializeGraph(graph g, char directed) {
	printf("init graph\n");
	int i;
	for(i = 0; i < MAXV; i++) {
		g->edge[i] = 0;
		g->degree[i]=0;
	}
	g->nVertices = 0;
	g->nEdges = 0;
	g->directed = directed;

}

graph createGraph(char directed) {
	printf("Creating %s graph\n", directed?"directed":"undirected");
	graph temp;

	temp = (graph)malloc(sizeof(struct Graph));

	if(!temp)
		printf("Error creating Graph Root\n");
	else {
		initializeGraph(temp,directed);
	}

	return temp;

}

void destroyGraph(graph g) {
	
	int i=0;
	for(i = 0; i < MAXV; i++) {
		if(g->edge[i]) {
			struct edgeNode *temp = g->edge[i];
			struct edgeNode *p = NULL;
			while(temp) {
				p = temp->next;
				printf("Removing node %d\n",temp->vertex);
				free(temp);
				temp = p;
			}
		}
	}

	printf("Deleting Graph\n");
	free(g);

}

unsigned int getNoOfVertices(graph g) {

	if(g)
		return g->nVertices;
	else
		return -1;
}


unsigned int getNoOfEdges(graph g) {
	
	if(g)
		return g->nEdges;
	else
		return -1;

}


void printGraph(graph g) {

	unsigned int i=0;
	for( i = 0; i< MAXV ; i++ ) {
		if(g->edge[i]) {
			struct edgeNode *p = g->edge[i];
			while(p) {
				printf("%d -> %d\n",i,p->vertex);
				p = p->next;
			}
		}
	}
}

int insertEdge(graph g, char directed, int x, int y, int weight) {
	int rc = 0;
	printf("insert an Edge\n");
	if(!g) {
		printf("Create Graph first!!\n");
		rc = -1;
	}
	else {

		printf("inserting an Edge\n");
		struct edgeNode *eNode = (struct edgeNode *)malloc(sizeof(struct edgeNode));
		if(!eNode) {
			printf("Error : Creating a Node!!!\n");
			rc = -1;
		}
		else {

			printf("inserting an edge from %d to %d with weight %d \n",x,y,weight);
			eNode->next = NULL;
			eNode->vertex = y;
			eNode->weight = weight;

			if(!g->edge[x])
				g->nVertices++;
			
			eNode->next = g->edge[x];
			g->edge[x] = eNode;
			g->nEdges++;
			g->degree[y]++;
			if(!directed)
				insertEdge(g,!directed,y,x,weight);
			else {
				if(!g->edge[y]) {
					printf("New node to directed graph\n");
					g->nVertices++;
				}
				else
					printf("Node already exists\n");
			}
		}
	}

	return rc;
}

void bfs(graph g, int start) {
	printf("bfs graph traversal from = %d\n",start);
	int i;
	Qptr Q = createQ();
	for(i=0; i<MAXV;i++)
		gNodeState[i] = NODE_UNDISCOVERED;
	struct edgeNode *p = g->edge[start];

	gNodeState[start] = NODE_DISCOVERED;
	nQ(Q,start);

	//printf("%d ", start);	
	while(!isEmpty(Q)) {

		int data = dQ(Q);
		p = g->edge[data];
		printf("%d ",data);
		gNodeState[data] = NODE_PROCESSED;

		//printf("checking vertex = %d\n",data);
		while(p) {
			if(gNodeState[p->vertex] != NODE_PROCESSED) {
				if(gNodeState[p->vertex] != NODE_DISCOVERED) {
					//printf("nQ vertex= %d\n",p->vertex);				
					nQ(Q,p->vertex);
					gNodeState[p->vertex] = NODE_DISCOVERED;
				}
				//else
					//printf("vertex %d is already discoverd\n",p->vertex);
			}
			//else 
				//printf("vertex %d is already processed\n",p->vertex);
			
			p = p->next;
		}

	}
	destroyQ(Q);
	printf("\n");

}


void dfs(graph g, int start) {
	printf("DFS recursive traversal\n");
	int i=0;
	struct edgeNode *p = NULL;
	for(i=0; i< MAXV ; i++)
		gNodeState[i] = NODE_UNDISCOVERED;
	stackPtr st = createStack();
	if(!st) {
		printf("Error Creating stack. returning!!!\n");
		return;
	}

	push(st,start);
	while(!isStackEmpty(st)) {
		int vertex = pop(st);
		printf("%d ",vertex);
		gNodeState[vertex] = NODE_PROCESSED;
		p = g->edge[vertex];
		while(p) {
			if(gNodeState[p->vertex] != NODE_PROCESSED) {
				if(gNodeState[p->vertex] != NODE_DISCOVERED) {

					push(st,p->vertex);
					gNodeState[p->vertex] = NODE_DISCOVERED;
				}
				//else
					//printf("Node %d is already discovered\n",p->vertex);
			}
			//else
				//printf("Node =%d is already processed\n",p->vertex);
			p = p->next;
		}
		
	}
	destroyStack(st);
	printf("\n");

}

void __recursive_dfs(graph g, struct edgeNode *p) {

	//printf("%d ",start);
	if (p) {
		
		if(gNodeState[p->vertex] != NODE_PROCESSED) {
			printf("Checking next for %d\n",p->vertex);
			__recursive_dfs(g, p->next);
			printf("%d\n",p->vertex);
			gNodeState[p->vertex] = NODE_PROCESSED;
			__recursive_dfs(g,g->edge[p->vertex]);
		}
		else {
			printf("Node %d is already processed\n",p->vertex);
			//return;
		}
	}
	else
		printf("NULL\n");
}

void recursive_dfs(graph g, int start) {
	printf("recursive DFS\n");
	int i =0;
	for(i=0; i< MAXV; i++)
		gNodeState[i]= NODE_UNDISCOVERED;
	//printf("done\n");
	if(g) {
		printf("%d\n",start);
		gNodeState[start] = NODE_PROCESSED;
		__recursive_dfs(g,g->edge[start]);
	}
	else
		printf("Graph not right\n");
}


void topological_sort(graph g) {
	printf("topo sort\n");

	//count the in-degrees of all the nodes in the graph
	//get all the nodes with zero in-degrees and push them to queue
	//dequeue the first one and print it
	//decrement in-degree of all the nodes connected to it by one
	//if any one of the node has in-degree of zero, then insert it to the graph

}
