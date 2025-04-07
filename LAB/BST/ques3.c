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
	printf("\n--RANGE--\n");
	printf("enter the lower value of range :");
	int low;scanf("%d",&low);
	printf("enter the higher value of range :");
	int high;scanf("%d",&high);
	printf("--NUMBER OF NODES WITHIN THE RANGE\n");
	num(t,low,high);


}