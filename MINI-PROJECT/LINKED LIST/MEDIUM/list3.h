#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct node
{
    int data;
    struct node *next;
};

void insertfront(struct node *h,int ele)
{
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data = ele;
    struct node *ptr;
    ptr = h->next;
    if (ptr==NULL)
    {
        temp->next = h->next;
        h->next = temp;
    }
    else
    {
        temp->next = h->next;
        h->next = temp;
    }
}

void display(struct node *h)
{
    struct node *ptr;
    ptr=h->next;
    while(ptr!=NULL)
    {
        printf("%d  ",ptr->data);
        ptr=ptr->next;
    }
}
void insertAtEnd(struct node *h,int ele)
{
  struct node *ptr,*prev;
  ptr = h->next;
  while (ptr != NULL)
    {
      prev = ptr;
      ptr = ptr->next;
    }
  struct node *temp;
  temp = (struct node *)malloc(sizeof(struct node ));
  temp->data = ele;
  temp->next = prev->next;
  prev->next = temp;
}

void oddeven(struct node *h)
{
    struct node *odd,*even,*q;
    odd=h->next;
    even=h->next->next;
    q=h->next->next;

    while(odd->next!=NULL && even->next!=NULL)
    {
        odd->next = even->next;
        odd=odd->next;
        even->next = odd->next;
        even=even->next;
    }
    odd->next = q;
    display(h);
}

