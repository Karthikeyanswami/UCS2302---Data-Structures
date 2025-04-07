#include <stdio.h>
#include <stdlib.h>
#include "mediumadt.h"

void main()
{
	struct graph *g;
	g=(struct graph *)malloc(sizeof(struct graph));
	printf("enter the number of vertices: ");
	int n;scanf("%d",&n);
	printf("enter the length of graph array : ");
	int e;scanf("%d",&e);
	init(g,n,e);
	int graph[100][100]={{4,3,1},{3,2,4},{3},{4},{}};
	int graphcolsize[5]={3,3,1,1,0};
	//int graph[100][100]={{1,2},{3},{3},{}};
	//int graphcolsize[4]={2,1,1,0};
	create(g,graph,graphcolsize);
	display(g);
    printf("\n");
	int visited[5]={0,0,0,0,0};
///int visited[4]={0,0,0,0};
   struct ll *s;
   s=(struct ll *)malloc(sizeof(struct ll));
   s->data=0;
   s->next=NULL;
    dfs(g,0,4,s,visited);
    //dfs(g,0,3,s,visited);
    
    
	
	
}