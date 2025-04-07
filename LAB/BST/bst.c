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
    printf("\n--FIND MINIMUM--\n");
    struct tree *res = findmin(t);
    printf("MINIMUM : %d",res->data);
    printf("\n--SEARCH--\n");
    printf("enter the key :");
    int key;scanf("%d",&key);
    int r=search(t,key);
    if (r==1)
        printf("ELEMENT PRESENT!\n");
    else 
        printf("ELEMENT IS NOT PRESENT!\n");
    printf("\n--DELETION--\n");
    printf("enter the element to be deleted:");
    int del;scanf("%d",&del);
    delete(t,del);
    printf("\n--AFTER DELETION--\n");
    printf("--INORDER--\n");
    inorder(t);
    printf("\n--PREORDER---\n");
    preorder(t);
    printf("\n--POSTORDER---\n");
    postorder(t);
    printf("\n--LEVEL ORDER--\n");
    levelorder(t,0);
}