#include <stdio.h>
#include <stdlib.h>
#include "chartreeadt.h"

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
        char ch[1];
        scanf("%s",ch);
        t=insert(t,ch[0]);
    }
    printf("--INORDER---\n");
    inorder(t);
    printf("\n---LEVEL ORDER---\n");
    levelorder(t,0);
    printf("enter the key to find the parent : ");
    char k[1];
    scanf("%s",k);
    printf("%c ",findparent(t,k[0]));
}