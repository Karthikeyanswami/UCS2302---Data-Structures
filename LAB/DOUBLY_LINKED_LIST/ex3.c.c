#include <stdio.h>
#include <stdlib.h>
#include "listadt.h"

void main()
{
  struct node *header;
  header = (struct node *)malloc(sizeof(struct node));
  header->left = NULL;
  header->right = NULL;
  printf("----INSERT FRONT---\n");
  printf("enter the number of elements :");
  int n;
  scanf("%d",&n);
  for (int i = 0;i<n;i++)
    {
      printf("ELEMENT : %d\n",(i+1));
      printf("enter the element :");
      int a;
      scanf("%d",&a);
      insertfront(header,a);
    }
  printf("---DISPLAY---\n");
  display(header);
  printf("\n");

 printf("---LEAST COMMON DIVISOR--\n");
  printf("Least common divisor is : %d \n",divisor(header));
  struct node *h1,*h2;
  h1=(struct node *)malloc(sizeof(struct node));
  h1->left=h1->right=NULL;
  h2=(struct node *)malloc(sizeof(struct node));
  h2->left=h2->right=NULL;
  posneg(header,h1,h2);
  printf("\n--POSITIVE----\n ");
  display(h1);
  printf("\n--NEGATIVE----\n ");
  display(h2);
  printf("\n");

  printf("---FINDING MISSING ELEMENT ---\n");
  printf("enter which missing element you wwant to find :");
  int k;
  scanf("%d",&k);
  printf("MISSING ELEMENT : %d",findmiss(header,k));
  printf("\n----INSERT END---\n");
  printf("enter the number of elements :");
  int n1;
  scanf("%d",&n1);
  for (int i = 0;i<n1;i++)
    {
      printf("ELEMENT : %d\n",(i+1));
      printf("enter the element :");
      int a;
      scanf("%d",&a);
      insertend(header,a);
    }
  printf("---DISPLAY---\n");
  display(header);
  printf("\n");
  printf("---INSERT MIDDLE----\n");
  printf("enter the number of elements to be inserted in middle:");
  int n2;
  scanf("%d",&n2);
  for (int i = 0;i<n2;i++)
    {
      printf("ELEMENT : %d\n",(i+1));
      printf("enter the element :");
      int a;
      scanf("%d",&a);
      printf("enter the key after which the element will be inserted:");
      int ah;
      scanf("%d",&ah);
      insertmiddle(header,ah,a);
    }
  printf("---DISPLAY---\n");
  display(header);
  printf("\n");
  printf("----SEARCH----\n");
  struct node *re;
  printf("enter the element to be searched:");
  int elt;
  scanf("%d",&elt);
  re=search(header,elt);
  if (re==NULL)
    printf("NOT FOUND!\n");
  else
    printf("FOUND!!\n");
  printf("--DELETION--\n");
  printf("enter the element to be deleted :\n");
  int a;
  scanf("%d",&a);
  delete(header,a);
  printf("\n---DISPLAY---\n");
  display(header);
  printf("\n");
  printf("---DUPLICATES ----\n");
  int res = duplicate(header);
  if (res==0)
    printf("NO DUPLICATES\n");
  else
    printf("DUPLICATES FOUND\n");

  printf("---EVEN AND ODD---");
  struct node *h11,*h22;
  h11=(struct node *)malloc(sizeof(struct node));
  h11->left=NULL;
  h11->right=NULL;
  h22=(struct node *)malloc(sizeof(struct node));
  h22->left=NULL;
  h22->right=NULL;
  evenodd(header,h11,h22);
   printf("\n---DISPLAY---\n");
  display(header);
  printf("\nEVEN LIST:\n");
  display(h11);
  printf("\nODD LIST:\n");
  display(h22);
  printf("\n");
  /*printf("\n---ADDITION---\n");
  printf("enter the number to be added :");
  int num;
  scanf("%d",&num);
  int result = add(header,num);
  printf("\n--PALINDROME---\n") ;
  int res1 = palindrome(header,result);
  if (res1==1)
    printf("YES!");
  else
    printf("NO!");*/
}
