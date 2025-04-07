#include <stdio.h>
#include <stdlib.h>
#include "treeadt.h"
void main()
{
    struct tree *t;
    t=NULL;
    printf("enter the number of nodes:");
    int n;
    scanf("%d",&n);
    for (int i = 0;i<n;i++)
    {
        printf("enter the value :");
        int a;
        scanf("%d",&a);
        t=insert(t,a);
    }
    printf("--INORDER---\n");
    inorder(t);
    printf("\n---LEVEL ORDER---\n");
    levelorder(t,0);
    printf("enter the key to find the parent : ");
    int k;
    scanf("%d",&k);
    printf("%d ",findparent(t,k));
}