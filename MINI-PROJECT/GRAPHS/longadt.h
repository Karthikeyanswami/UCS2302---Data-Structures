#include <stdio.h>
#include <stdlib.h>

struct graph
{
    int adj[100][100];
    int vertices;

};

void init(struct graph *g,int n)
{
    g->vertices=n;
    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++)
            g->adj[i][j]=0;
}

void create(struct graph *g,int edges[])
{
    for (int i=0;i<g->vertices;i++)
    {
        g->adj[i][edges[i]]=1;
    }
}

void display(struct graph *g)
{
    for (int i=0;i<g->vertices;i++)
    {
        for (int j=0;j<g->vertices;j++)
        {   printf("%d ",g->adj[i][j]);}
        printf("\n");
    }
}

void dfs(int vertex,int dist_arr[],int visited[],int edges[],int distance,int *ans,int extra_arr[])
{
   
    if (vertex!=-1)
    {
        if (visited[vertex]==0)
        {
            visited[vertex]=1;
            extra_arr[vertex]=1;
            dist_arr[vertex]=distance;
            dfs(edges[vertex],dist_arr,visited,edges,distance+1,ans,extra_arr);
        }
        else if (extra_arr[vertex]==1)
        {
            if (distance-dist_arr[vertex]>*ans)
            {
                *ans=distance-dist_arr[vertex];
            }    
        }
        extra_arr[vertex]=0;
    }
}

int longest_cycle(struct graph *g,int edges[],int dist[],int visited[],int extra_arr[],int *ans)
{
    
    for (int i=0;i<g->vertices;i++)
    {
        if (visited[i]==0)
        {    
            dfs(i,dist,visited,edges,0,ans,extra_arr);
        }
    }
    return *ans;
}
