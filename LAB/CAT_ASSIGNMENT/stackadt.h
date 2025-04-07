#include <stdio.h>
#include <stdlib.h>

struct stack
{   int size;
    int top;
    char arr[100];
    int curr;
};

void create(struct stack *s)
{
    s->size=0;
    s->top=-1;
    s->curr=-1;
}


void push(struct stack *s,int ele)
{
    s->top+=1;
    s->arr[s->top]=ele;
    ++s->size;  
}

int isempty(struct stack *s)
{
    if (s->top==-1)
        return 1;
    else
        return 0;
}


int getpos(struct stack *s,int ele)         ////returns the position of a url
{
    int c=0;
        for (int i=0;i<s->size;i++)
        {
            if (ele==s->arr[i])
            {
                return c;
            }
            c++;
        }
}

char forward(struct stack *s,int ele)
{
    if (s->curr==-1)        ////if cursor not set,sets the cursor
    {
        int k=getpos(s,ele);
        s->curr=k;
        if (k+1==s->size)   ////ensure that cursor doesnt grow beyond size
            return '-';
        
        else
        {
            s->curr=k+1;   ////cursor updated
            return s->arr[s->curr];
        }
    }
    else                    ////cursor already set
    {
        if (s->curr+1==s->size)  ////ensure that cursor doesnt grow beyond size
            return '-';
        else                     ////update cursor and return fwd url
        {    s->curr++;
            return s->arr[s->curr];
        }
    }
}

char backward(struct stack *s,int ele)
{
    if (s->curr==-1)             ////if cursor hasnt been set
    {
        int k=getpos(s,ele);
        s->curr=k;              ////update cursor
        if (s->curr-1<0)           
            return '-';
        else
        {
            s->curr=k-1;
            return s->arr[s->curr];
        }
    }
    else                       ////if cursor has been already set
    {
        if (s->curr-1<0)
            return '-';
        else
        {
            s->curr--;
            return s->arr[s->curr];
        }
    }
}

char print(struct stack *s)
{
    for (int i=0;i<s->size;i++)
    {
        printf("%c ",s->arr[i]);
    }
}


