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

void delete(struct node *h)
{
    h->next=h->next->next;
}



void gcd(struct node *h)
{
    struct node *ptr;
    struct node *h1;
    h1=(struct node *)malloc(sizeof(struct node));
    h1->next = NULL;
    ptr=h->next;
    if (ptr->next==NULL)
    {
        display(h);
    }
    else
    {
        int i = 0;
        while(ptr->next!=NULL)
        {
            struct node *p;
            p=ptr->next;
            if (p==NULL)
                break;
            else
            {
            int n1=ptr->data;
            if (i!=0)
                delete(h1);
            i++;
            insertfront(h1,n1);
            int n2 = p->data;
            int a,b;
            if (n2>n1)
            {
                a =n2;
                b = n1;
            }
            else if (n1==n2)
            {
                a=n1;
                b=n2;
            }
            else
            {
                a =n1;
                b = n2;
            }
            int k =b;
            while(k>0)
            {
                if ((a%k==0)&&(b%k==0))
                   {
                    insertfront(h1,k);
                    break;
                    } 
                else
                    k=k-1;
            }
            insertfront(h1,n2);
            ptr=ptr->next;
            }
        }
       display(h1); 
    }
}

