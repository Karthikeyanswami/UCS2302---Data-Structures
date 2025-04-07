#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int arr[100];
    int f,r;
    int size;
};


struct queue1
{
    int data;
    struct queue1 *next;
};

void init(struct queue *h)
{
    h->size=100;
   h->f=h->r=-1;
}

int isfull(struct queue *h)
{
    if (h->r==h->size-1)
        return 1;
    else
        return 0;
}

void enqueue(struct queue *h,int ele)
{
    h->r+=1;
    h->arr[h->r]=ele;
    
}
int isempty(struct queue *h)
{
    if (h->f==h->r)
        return 1;
    else
        return 0;
}
void dequeue(struct queue *h)
{
    h->f+=1;
    //printf("%d ",h->arr[h->f]);
    
}

void reverse_queue(struct queue *q,struct queue *q1)
{
    while (!isempty(q1))
    {
        dequeue(q1);
    }
    q1->f=-1;
    q1->r=-1;
    int x=q->r;
    while (x>-1)
    {
        enqueue(q1,q->arr[x]);
        x--;
    }
}

void show_status(struct queue *q,struct queue *q1)
{
    for (int i=q->f+1;i<=q->r;i++)
        printf("%d ",q->arr[i]);
    printf("\n");
    for (int i=q1->f+1;i<=q1->r;i++)
        printf("%d ",q1->arr[i]);
}

void print_res(int res[],int n)
{
    for (int i=0;i<n;i++)
        printf("%d ",res[i]);
}

int front(struct queue *q1)
{
    return q1->arr[0];
}

void find_visible(struct queue *q,int heights[],int n)
{
    struct queue *q1;
    q1=(struct queue*)malloc(sizeof(struct queue));
    init(q1);
    int height;
    int res[n];
    for (int i=n-1;i>=0;i--)
    {
        printf("\nITERATION %d\n",i+1);
        height=heights[i];
        printf("height : %d\n",height);
        int visible=0;
        while (!isempty(q) && height>front(q1))
        {
            printf("inside dequeue if\n");
            visible+=1;
            dequeue(q);
        }
        if (!isempty(q))
        {
            printf("inside non empty\n");
            visible+=1;
        }
        res[i]=visible;
        printf("visible : %d\n",visible);
        enqueue(q,height);
        reverse_queue(q,q1);
        show_status(q,q1);
    }
    printf("\n");
    print_res(res,n);
}
