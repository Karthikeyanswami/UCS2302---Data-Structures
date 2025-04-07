#include <stdio.h>
#include <stdlib.h>
#include "maxheapadt.h"

void main()
{
	printf("enter the number of elements:");
	int n;
	scanf("%d",&n);
	struct pq *p;
	p=(struct pq*)malloc(sizeof(struct pq));
	init(p);
	for (int i=0;i<n;i++)
	{
		printf("enter the element: ");
		int a;
		scanf("%d",&a);
		insert(p,a);
	
	}
	printf("\n---PRINTING--\n");
	display(p);
	printf("\n");
	printf("--1ST DELETION--\n");
	printf("MAX ELEMENT : %d",delete(p));
	printf("\n---PRINTING--\n");
	display(p);
	printf("\n");
	printf("--2ND DELETION--\n");
	printf("MAX ELEMENT : %d",delete(p));
	printf("\n---PRINTING--\n");
	display(p);
	printf("\n");
	printf("--3RD DELETION--\n");
	printf("MAX ELEMENT : %d",delete(p));
	printf("\n---PRINTING--\n");
	display(p);
	printf("\n");




}