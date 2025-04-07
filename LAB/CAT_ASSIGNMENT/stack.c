#include <stdio.h>
#include <stdlib.h>
#include "stackadt.h"
#include <stdbool.h>
void main()
{
    printf("enter the url length :");
    int n;scanf("%d",&n);
    struct stack *h=(struct stack*)malloc(sizeof(struct stack));
    create(h);
    for (int i=0;i<n;i++)
    {
        printf("enter the url one by one :");
        char c;
        scanf(" %c",&c);
        push(h,c);
    }
   
    printf("\nenter the current url/window :");
    char s;
    scanf(" %c",&s);
    
    int ch;
    while (true)
    {
        printf("\n\n1.FORWARD\n2.BACKWARD\n3.PRINT\n4.BREAK\n");
        printf("Enter your choice : ");
        scanf("%d",&ch);
        if (ch==1)
        {
                printf("Next URL : %c",forward(h,s));

        }
       else if (ch==2)
        {
            printf("Previous URL : %c",backward(h,s));
        }
        else if (ch==3)
        {
            printf("Existing URLS : ");
             print(h);
        }
        else if (ch==4)
        { 
            break;
        }
        else
            printf("\nINVALID CHOICE!\n");
    }
}