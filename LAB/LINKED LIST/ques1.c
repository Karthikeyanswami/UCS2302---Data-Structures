#include <stdio.h>
#include "listadt.h"
#include <stdlib.h>
void main()
{
  struct node *header;
  header = (struct node *)malloc(sizeof(struct node));
  header->next = NULL;
  printf("----INSERTION AT FRONT ----\n");
  printf("Enter how many elements you want to enter :");
  int n;
  scanf("%d",&n);
  for (int i=0;i<n;i++)
    {
      int a;
      printf("enter the element :");
      scanf("%d",&a);
      insertfront(header,a);
    }
 printf("\n");
  printf("-----DISPLAY----\n");
  display(header);
  printf("\n");
    printf("----INSERTION AT END ----\n");
  printf("Enter how many elements you want to enter :");
  int n1;
  scanf("%d",&n1);
  for (int i=0;i<n1;i++)
    {
      int a;
      printf("enter the element :");
      scanf("%d",&a);
      insertAtEnd(header,a);
    }
 printf("\n");
  printf("-----DISPLAY----\n");
  display(header);
  printf("\n");
  printf("\n\n-----SEARCHING FOR AN ELEMENT -----\n ");
  int ch;
  printf("Enter the element to be searched :\n");
  scanf("%d",&ch);
  int res = search(header,ch);
  if (res!=-1)
      printf("%d \n",res);
     
  else
    printf("%d \n",res);
  printf("\n");
  display(header);
  printf("\n----FINDING MIDDLE ELEMENT ----\n");
  findMiddleElt(header);
  printf("\n");
 display(header);
  /*printf("\n\n----LENGTH ----\n");
  printf("LENGTH : %d",length(header));
  printf("\n");*/
  //display(header);
  printf("\n\n---REVERSING A LINKED LIST-----\n");
  reverseList(header);
  
  printf("\n");
  display(header);
  printf("\n----DELETION OF AN ELEMENT ----\n");
  int elt;
  printf("Enter the deleted element :");
  scanf("%d",&elt);
  deleteElt(header,elt);
  printf("\n");
  display(header);
  tocorrupt(header,2);
  printf("\nLIST GETTING CORRUPTED....\n");
  printf("--CORRUPTED LIST ?----\n");
  printf("%d ",corrupt(header));
  
}