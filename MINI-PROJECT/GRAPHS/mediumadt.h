#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>



struct graph
{
	int edges;
	int vertices;
	int adj[100][100];
    
};

void init(struct graph *g,int n,int e)
{
	g->edges=e;
	g->vertices=n;
	for (int i=0;i<=g->vertices;i++)
	{	for (int j=0;j<=g->vertices;j++)
		{	
			g->adj[i][j]=0;	
		}
	}
    
}

void create(struct graph *g,int graph[][100],int graphcolsize[])
{
	for (int i=0;i<g->edges;i++)
	{
        int v=i;
		for (int j=0;j<graphcolsize[i];j++)
		{
			g->adj[v][graph[i][j]]=1;
		}	
	}
	printf("done create\n");


}

void display(struct graph *g)
{	
	for (int i=0;i<g->vertices;i++)
	{	for (int j=0;j<g->vertices;j++)
		{	printf("%d ",g->adj[i][j]);}
		printf("\n");

	}
}

struct ll
{
	int data;
	struct ll *next;
};

void addpath(struct ll *l,int ele)
{
	struct ll *ptr=l->next;
	struct ll *temp;
	temp=(struct ll*)malloc(sizeof(struct ll));
	temp->data=ele;
	temp->next=NULL;
	if (ptr==NULL)
	{
		l->next=temp;
	}
	else
	{
		struct ll *ptr=l->next;
		while (ptr->next!=NULL)
		{
			ptr=ptr->next;
		}
		ptr->next=temp;
	}
}


void dfs(struct graph *g,int s,int e,struct ll *l,int visited[])
{
	if (s==e)
	{
		struct ll *ptr=l;
		while(ptr!=NULL)
		{
			printf("%d ",ptr->data);
			ptr=ptr->next;
		}
		l->next->next=NULL;
		
		printf("\n");
	}
	visited[s]=1;
	for (int i=0;i<g->vertices;i++)
	{
		if(g->adj[s][i]==1 && visited[i]==0)
		{
			addpath(l,i);
			dfs(g,i,e,l,visited);
		}
	}
	visited[s]=0;
	//l->next=NULL;
	
}




