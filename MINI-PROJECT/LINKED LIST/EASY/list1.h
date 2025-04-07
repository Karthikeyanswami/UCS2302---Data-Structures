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
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
}

void insertend(struct node *h,int ele)
{
  struct node *ptr,*prev;
  ptr = h->next;
  struct node *temp;
  temp = (struct node *)malloc(sizeof(struct node));
  temp->data = ele;
  temp->next=NULL;
  if (ptr==NULL)
  {
    h->next=temp;
  }
  else
  { while (ptr != NULL)
    {
      prev = ptr;
      ptr = ptr->next;
    }
  prev->next = temp;
  }
 
}

void add(struct node *h1,struct node *h2)
{
    struct node *sum;
    sum=(struct node *)malloc(sizeof(struct node));
    sum->next = NULL;
    struct node *p1,*p2;
    p1=h1->next;
    int len1=0;
    p2=h2->next;
    int len2=0;
    int n1=0,n2=0;
    while(p1!=NULL)
    {
        n1+=(p1->data)*pow(10,len1);
        len1+=1;
        p1=p1->next;
    }
    printf("NUMBER 1 %d \n",n1);
    while(p2!=NULL)
    {
        n2+=(p2->data)*pow(10,len2);
        len2+=1;
        p2=p2->next;
    }
    printf("NUMBER 2 %d \n",n2);
    int add=n1+n2;
    printf("ADDITION %d \n",add);
    int temp = add;
    //printf("%d ",temp);
    struct node *addition;
    addition=(struct node *)malloc(sizeof(struct node));
    addition->next=NULL;
    while(temp>0)
    {
        insertend(addition,temp%10);
        temp=temp/10;
    }
    display(addition);



}