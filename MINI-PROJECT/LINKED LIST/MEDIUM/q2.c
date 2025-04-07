#include <stdio.h>
#include "list3.h"
#include <stdlib.h>

void main()
{
    struct node *header;
     header = (struct node *)malloc(sizeof(struct node));
     header->next = NULL;
    printf("----INSERTION AT FRONT ----\n");
    printf("NUMBER 1\n");
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
    printf("-----DISPLAY----\n");
    display(header);
    printf("\n");
    printf("----INSERTION AT FRONT ----\n");
    /*printf("NUMBER 2\n");
    struct node *header2;
     header2 = (struct node *)malloc(sizeof(struct node));
     header2->next = NULL;
    printf("Enter how many elements you want to enter :");
    int n1;
    scanf("%d",&n1);
    for (int i=0;i<n1;i++)
    {
      int a;
      printf("enter the element :");
      scanf("%d",&a);
      insertfront(header2,a);
    }
    printf("-----DISPLAY----\n");
    display(header2);
    printf("\n");*/

    oddeven(header);


}