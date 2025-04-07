#include <stdio.h>
#include <stdlib.h>
#include "hardadt.h"

void main()
{
    struct queue *q;
    q=(struct queue*)malloc(sizeof(struct queue));
    init(q);
    printf("enter the input height array :");
    printf("enter length: ");
   /*int n;scanf("%d",&n);
   int height[n];
    for (int i=0;i<n;i++)
    {
        printf("enter the height of %d person",i+1);
        int h;scanf("%d",&h);
        height[i]=h;
    }*/
    //int heights[6]={10,6,8,5,11,9};
    int heights[5]={5,1,2,3,10};
    printf("\nFinding number of visible people\n");
    find_visible(q,heights);
}
