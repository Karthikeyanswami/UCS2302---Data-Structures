#include <stdio.h>
#include <stdlib.h>
#include "antsadt.h"


void main()
{
    struct graph *g;
    g=(struct graph*)malloc(sizeof(struct graph));
    printf("enter the build array :\n");
    printf("enter the length :");
    int n;scanf("%d",&n);
    int prevRoom[n];
    for (int i=0;i<n;i++)
    {
        printf("enter the num of previous room of room %d :",i);
        int a;scanf("%d",&a);
        prevRoom[i]=a;
    }
    struct queue *q;
    q=(struct queue*)malloc(sizeof(struct queue));
    initqueue(q,n);
    init(g,n);
    construct(g,prevRoom);
    printf("\nDISPLAYING THE ADJACENCY MATRIX\n");
    display(g);
    printf("\n SOME OF THE POSSIBILITIES\n");
    
    toposort(g,q);
    printf("\n");
   
    struct queue *q2;
    q2=(struct queue*)malloc(sizeof(struct queue));
    initqueue(q2,n);
    bfs(g,q2,0);
    printf("\n");
   
    struct stack *s;
    s=(struct stack *)malloc(sizeof(struct stack));
    createstack(s,n);
    dfs(g,s,0);
    printf("\n");
    struct stack *s1;
    s1=(struct stack *)malloc(sizeof(struct stack));
    createstack(s1,n);
    dfs_neg(g,s1,0);
}
