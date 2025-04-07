#include <stdio.h>
#include <stdlib.h>
#include "polyadt.h"

void main()
{
	struct poly *header;
	header = (struct poly*)malloc(sizeof(struct poly));
  header->next = NULL;
	struct poly *header1;
	header1 = (struct poly*)malloc(sizeof(struct poly));
  header1->next = NULL;
	 printf("enter the number of terms of P1:");
  	int n1;
  	scanf("%d",&n1);
 	 printf("enter the number of terms of P2:");
  	int n2;
  	scanf("%d",&n2);
	printf("----POLYNOMIAL 1 ----\n");
  for (int i=0;i<n1;i++)
    {
      printf("TERM %d\n",(i+1));
      printf("enter the coeff :");
      int cf;
      scanf("%d",&cf);
      printf("enter the exponent :");
      int ex;
      scanf("%d",&ex);
      insert(header,cf,ex);
    }

  printf("\n----POLYNOMIAL 2 ----\n");
  for (int i=0;i<n2;i++)
    {
      printf("TERM %d\n",(i+1));
      printf("enter the coeff :");
      int cf;
      scanf("%d",&cf);
      printf("enter the exponent :");
      int ex;
      scanf("%d",&ex);
      insert(header1,cf,ex);
    }

  printf("\n---DISPLAYING---\n");
  printf("\n----POLYNOMIAL 1 ----\n");
  display(header);
  printf("\n----POLYNOMIAL 2 ----\n");
  display(header1);
  printf("\n\n---ADDITION----\n");
  add(header,header1);
  
}