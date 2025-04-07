#include <stdio.h>
#include <stdlib.h>
#include "pqadt.h"

void main()
{
	printf("enter the number of elements:");
	int n;
	scanf("%d",&n);
	struct pq *p;
	p=(struct pq*)malloc(sizeof(struct pq));
	init(p);
	struct employee *e;
	e=(struct employee*)malloc(sizeof(struct employee));
	for (int i=0;i<n;i++)
	{
		printf("enter the id: ");
		char id;
		scanf(" %c",&id);  //remeber to leave space as the previous \n is there in buffer
		e->id=id;
		printf("enter the salary: ");
		long int sal;
		scanf("%ld",&sal);
		e->salary=sal;
        insert(p,e);
	}
	printf("\n---PRINTING--\n");
	display(p);
	printf("\n");
	printf("--1ST DELETION--\n");
	printf("HIGHEST PRIORITY : %c",delete(p));
	printf("\n---PRINTING--\n");
	display(p);
	printf("\n");
	printf("--2ND DELETION--\n");
	printf("HIGHEST PRIORITY : %c",delete(p));
	printf("\n---PRINTING--\n");
	display(p);
	printf("\n");
	printf("--3RD DELETION--\n");
	printf("HIGHEST PRIORITY : %c",delete(p));
	printf("\n---PRINTING--\n");
	display(p);
	printf("\n");
}