#include <stdio.h>
#include <stdlib.h>
#include "bstadt.h"

void main()
{
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
    printf("\n--PREORDER---\n");
    preorder(t);
    printf("\n--POSTORDER---\n");
    postorder(t);
    printf("\n--LEVEL ORDER--\n");
    levelorder(t,0);
	printf("\nSUM OF K MINIMUM\n");
	printf("enter k : ");int k;scanf("%d",&k);
	printf("SUM OF K MIN : %d\n",sum(t,k));


}