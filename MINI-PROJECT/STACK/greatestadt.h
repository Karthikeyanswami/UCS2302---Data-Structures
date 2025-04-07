#include <stdio.h>

struct stack
{
    int arr[100];
    int top;
};

void init(struct stack *s)
{
    s->top=-1;
}

int peek(struct stack *s)
{
    return s->arr[s->top];
}

int isempty(struct stack *s)
{
    if (s->top==-1)
        return 1;
    else   
        return 0;
}

int pop(struct stack *s)
{
    if (isempty(s))
        return 0;
    else
    {
        int d = s->arr[s->top];
        s->top-=1;
        return d;
    }
    
}

void check_greatest(struct stack *s,int ele)
{
    
    if (s->top==-1)
    {
        s->arr[++s->top]=ele;
        
    }
    else
    {
        if (ele<peek(s))
        {
            s->arr[++s->top]=ele;
           
        }
        else
        {
            while (!isempty(s))
            {
                if (peek(s)<ele)
                  {
                     printf("\n%d has greater element %d",peek(s),ele);
                    pop(s);
                    }  
                else
                    {break;}
            }
            s->arr[++s->top]=ele;
        }
       
    }
    
}