#include <stdio.h>
#include "list2.h"
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
    gcd(header);

}