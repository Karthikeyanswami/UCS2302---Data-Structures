//asteroid problem

#include <stdio.h>
#include <stdlib.h>
struct stack
{
    int arr[1000];
    int top;

};

void create(struct stack *s)
{
    s->top=-1;

}

void push(struct stack *s,int ele)
{
    s->arr[++s->top]=ele;
}

int isempty(struct stack *s)
{
    if (s->top==-1)
        return 1;
    else
        return 0;
}

void pop(struct stack *s)
{
    if (isempty(s))
        printf(" ");
    else
    {
        s->top--;
    }
}

int peek(struct stack *s)
{
    if (isempty(s))
        return 0;
    else
        return s->arr[s->top];
}

void display(struct stack *s)
{
    if (isempty(s))
        printf(" ");
    else
    {
        printf("%d ",s->arr[s->top]);
        s->top--;
    }
}

int sum(struct stack *s)
{
    
}

void main()
{
    struct stack *s;
    s=(struct stack *)malloc(sizeof(struct stack));
    create(s);
    printf("enter the asteroid array \n");
    printf("enter length:");
    int n;
    scanf("%d",&n);
    int arr[n];
    for (int i = 0;i<n;i++)
    {
        printf("enter the element :");
        int a;scanf("%d",&a);
        arr[i]=a;
    }
    for (int i =0;i<n;i++)
    {
        if (peek(s)==0)
            push(s,arr[i]);
        else
        {
            if ((peek(s)>0 && arr[i]>0)|| (peek(s)<0 && arr[i]<0))
                push(s,arr[i]);
            else if( peek(s)*arr[i]<0)
            {
                printf("inside main\n");
                if (peek(s)+arr[i]<0)
                {
                    pop(s);
                    push(s,arr[i]);
                }
                if (peek(s)+arr[i]>0)
                {
                    continue;
                }
                if (peek(s)+arr[i]==0)
                {
                    pop(s);
                    push(s,0);
                }
            

            }
        }
    }

    

    printf("--FINAL COLLISION--\n");
    while (!isempty(s))
    {
        display(s);
    }

}