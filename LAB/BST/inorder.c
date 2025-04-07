#include <stdio.h>
#include <stdlib.h>
#include "inorderadt.h"

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
    int arr1[n];
	int *p1;
    p1=inorder(t,arr1);
    for (int i =0;i<n;i++)
    {
        printf("%d ",p1[i]);
    }
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
    int arr2[n1];
	int *p2;
	printf("--INORDER--\n");
    p2=inorder1(t1,arr2);
    for (int i =0;i<n1;i++)
    {
        printf("%d ",p2[i]);
    }
    printf("\n--LEVEL ORDER--\n");
    levelorder(t1,0);
	printf("\n--SORTED--\n");
	int *r;
	int res[10000];
	r=sort(p1,p2,res,n,n1);
	for (int i = 0;i<(n+n1);i++)
	{
		printf("%d ",r[i]);
	}



}