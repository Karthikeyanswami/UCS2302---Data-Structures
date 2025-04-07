#include <stdio.h>
#include <stdlib.h>
#include "greatestadt.h"

void main()
{
    struct stack *s;
    s=(struct stack *)malloc(sizeof(struct stack));
    init(s);
    printf("enter the total number of elements :");
    int n;
    scanf("%d",&n);
    for (int i =0;i<n;i++)
    {
        printf("\nenter element :");
        int a;
        scanf("%d",&a);
        check_greatest(s,a);
    }

    while(!isempty(s))
    {
        printf("\n%d has no greater element ",pop(s));
    }




}