//Jai Shri Ganesh
#include <stdio.h>
#include "graph.h"

int main() {

	//printf("Welcome to Graph code !!\n");
	graph graphRoot = NULL;
	int directed;
	int choice;	
	do {
		printf("Welcome to Graph program\n \
			1. create Graph \n \
			2. destroy Graph \n \
			3. insert an Edge \n \
			4. get no of Edge \n \
			5. get no of vertices \n \
			6. get degree of vertex \n \
			7. Print Graph \n \
			8. bfs \n \
			9. dfs \n \
			10.recursive DFS \n \
			11.Topological sort \n \
			0. exit \n \
			");
		scanf("%d",&choice);
		switch(choice) {
			case 1: {
					//int directed = 0;
					printf("Create Graph\n");
					printf("do you want Directed Graph. 1= directed  or 0 = undirected\n");
					scanf("%d",&directed);
					graphRoot = createGraph(directed);
					break;
				}
			case 2: {
					printf("Destroy Graph\n");
					destroyGraph(graphRoot);
					graphRoot = NULL;
					break;
				}
			case 3: {
					printf("insert an Edge\n");
					int x, y,weight;
					printf("enter x and y and weight \n");
					scanf("%d%d%d",&x,&y,&weight);
					printf("directed ? %d\n",directed);
				        if(insertEdge(graphRoot,directed,x,y,weight) >= 0)
				                printf("Edge added successfully\n");
				        else
				                printf("Error :  Adding Edge\n");

					break;
				}
			case 4: {
					printf("Get no of edges\n");
					int edges = getNoOfEdges(graphRoot);
					if(edges >=0 )
						printf("No of edges in the graph = %u\n",edges);
					else
						printf("Error :  geting the no of edges\n");

					break;
				}

			case 5: {
					printf("Get no of vertices\n");
                                        int vertices = getNoOfVertices(graphRoot);
                                        if(vertices >=0 )
                                                printf("No of vertices in the graph = %u\n", vertices);
                                        else
                                                printf("Error :  geting the no of vertices\n");

                                        break;
				}
			case 6: {
					printf("get degree of a vertex\n");
					break;
				}
			case 7: {
					printf("Print Graph\n");
					printGraph(graphRoot);
					break;
				}
			case 8: {
					printf("bfs\n");
					int start;
					printf("Enter Start location\n");
					scanf("%d",&start);
					bfs(graphRoot,start);
					break;
				}
			case 9: {
					printf("dfs\n");
					int start;
					printf("Enter Start location\n");
					scanf("%d",&start);
					dfs(graphRoot,start);
					break;
				}
			case 10: {
					printf("Print Graph\n");
					int start;
					printf("Enter Start location\n");
					scanf("%d",&start);
					recursive_dfs(graphRoot,start);
				
					break;
				}
			case 11: {
					 printf("Topological sort\n");
					 topological_sort(graphRoot);


			case 0: {
					printf("Hurrrrrr!!!!\n");
					break;
				}
			default: {
					printf("Wrong Choice!!!\n");
					break;
				}
		}

	} while(choice);

	return 0;
}
