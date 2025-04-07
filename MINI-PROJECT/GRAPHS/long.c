#include <stdio.h>
#include <stdlib.h>
#include "longadt.h"

void main()
{
    /*int edges[5]={3,3,4,2,3};
    int dist_arr[5]={0,0,0,0,0};
    int extra_arr[5]={0,0,0,0,0};
    int visited[5]={0,0,0,0,0};*/
    int edges[4]={2,-1,3,1};
    int dist_arr[4]={0,0,0,0};
    int extra_arr[4]={0,0,0,0};
    int visited[4]={0,0,0,0};
    struct graph *g;
    g=(struct graph *)malloc(sizeof(struct graph));
    init(g,5);
    create(g,edges);
    display(g);
    int ans=-1;
   printf("%d ", longest_cycle(g,edges,dist_arr,visited,extra_arr,&ans));
}