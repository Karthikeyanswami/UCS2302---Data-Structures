#include <stdio.h>
#include <stdlib.h>
#include "hard_ll.h"

void main()
{
    struct queue *q;
    q=(struct queue *)malloc(sizeof(struct queue));
    struct queue *ptr[2]; 
    ptr[0]=(struct queue*)malloc(sizeof(struct queue));
    ptr[0]->next = NULL;
    ptr[1]=(struct queue*)malloc(sizeof(struct queue));
    ptr[1]->next = NULL;
    //int heights[6]={10,6,8,5,11,9};
    printf("enter the input height array :\n");
    printf("enter length: ");
    int n;scanf("%d",&n);
   int heights[n];
    for (int i=0;i<n;i++)
    {
        printf("enter the height of person at index %d : ",i);
        int h;scanf("%d",&h);
        heights[i]=h;
    }
    printf("\nScanning for visible people\n");
    visible_people(q,heights,ptr,n);

}