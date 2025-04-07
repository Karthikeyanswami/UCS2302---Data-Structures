#include <stdio.h>
#include <stdlib.h>
#include "bstadt.h"

void main()
{
    printf("TREE 1\n");
	struct tree *t;
	t=NULL;
	printf("enter the number of nodes :");
	int n;
	scanf("%d",&n);
	for (int i = 0;i<n;i++)
	{	
		printf("enter the value :");
		int a;
		scanf("%d",&a);
		t=insert(t,a);
	}
	printf("--INORDER--\n");
    inorder(t);
    printf("\n--LEVEL ORDER--\n");
    levelorder(t,0);
    printf("\n\nTREE 2\n");
	struct tree *t1;
	t1=NULL;
	printf("enter the number of nodes :");
	int n1;
	scanf("%d",&n1);
	for (int i = 0;i<n1;i++)
	{	
		printf("enter the value :");
		int a;
		scanf("%d",&a);
		t1=insert(t1,a);
	}
	printf("--INORDER--\n");
    inorder(t1);
    printf("\n--LEVEL ORDER--\n");
    levelorder(t1,0);
    printf("\n--CHECKING---\n");
    int result1 = nodecheck(t,t1);
    if (result1==0)
        printf("TREES ARENT IDENTICAL\n");
    else
    {
         int result = check(t,t1);
         if (result==1)
            printf("TREES ARENT IDENTICAL\n");
        else
            printf("TREES ARE IDENTICAL\n");
    }
    
}