#include <stdio.h>
#include <stdlib.h>

struct node
{
    char data;
    struct node *next,*prev;
};

void insert(struct node *h,char ele)      ////Insert At End
{
    struct node *ptr=h;
    if (ptr->next==NULL)    
    {
        struct node *temp=(struct node*)malloc(sizeof(struct node));
        temp->next=NULL;
        temp->data=ele;
        ptr->next=temp;
        temp->prev=ptr;
    }
    else
    {
        struct node *temp=(struct node*)malloc(sizeof(struct node));
        temp->next=temp->prev=NULL;
        temp->data=ele;
        while (ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next=temp;
        temp->prev=ptr;
    }

}

void print(struct node *h)
{
    struct node *ptr=h->next;
    while (ptr!=NULL)
    {
        printf("%c ",ptr->data);
        ptr=ptr->next;
    }
}

char forward(struct node *h,struct node *curr[],char ele)
{
    if (curr[0]==NULL)       ///if no cursor has been set,current url will be null
    {
        struct node *ptr=h->next;
        while(ptr!=NULL)
        {
            if (ptr->data==ele)
            {
                break;
            }
            ptr=ptr->next;

        }
        if (ptr->next!=NULL)        ////ensuring if there exists a forward url
        {   curr[0]=ptr->next;
            return curr[0]->data;
        }
        else                        ////else return -
          return '-';
    }
    else                            ////cursor has been set already
    {
        if (curr[0]->next==NULL)      ////if cursor next is null
            return '-';
        
            
        else                         ////else update cursor and return next url
            {
                curr[0]=curr[0]->next;   
                return curr[0]->data;
            }
    }
}

char backward(struct node *h,struct node *curr[],char ele)
{
    if (curr[0]==NULL)            ////check if the cursor has been set
    {
        struct node *ptr=h->next;
        while (ptr!=NULL)
        {
            if (ptr->data==ele)
                break;
            ptr=ptr->next;
        }
        curr[0]=ptr;
        if (curr[0]->prev!=h)               ////check if a previour url to cursor exists
        {    curr[0]=curr[0]->prev;         ////if yes update cursor and return the prev url
             return curr[0]->data;
        }
        else                                ////else return -
         return '-';     
    }
    else                                     ////cursor has been set already
    {
        if (curr[0]->prev==h)                ////if there is no prev url to cursor,return -
            return '-';
        
        else                                ////if yes,update cursor and return prev url
        {
            curr[0]=curr[0]->prev;
            return curr[0]->data;
        }
    }
}