 
#include <stdio.h>
#include <stdlib.h>
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


int search(struct node *h,int key)
{
  struct node *ptr;
  ptr = h->next;
  while (ptr!=NULL)
    {
      if (ptr->data == key)
        return key;
      ptr=ptr->next;
    }
  return -1;

}

int length(struct node *h)
{
  struct node *ptr;
  ptr = h->next;
  int len=0;
  while (ptr != NULL)
    {
      len+=1;
      ptr=ptr->next;
    }
  return len;
}

void findMiddleElt(struct node *h)
{
  struct node *ptr;
  ptr = h->next;
  int len = length(h);
  int k=0;
  if (len%2==0)
  {
    while (ptr !=NULL)
      {
        k=k+1;
        if (k==len/2 || k==len/2+1)
        {
          printf("%d ",ptr->data);
        }
       
        ptr=ptr->next;
       
      }
  }
  else
  {
    while (ptr !=NULL)
      {
        k=k+1;
        if (k==(len+1)/2)
        {
          printf("%d ",ptr->data);
        }
       
        ptr=ptr->next;
       
      }
  }
}
void reverseList(struct node *h)
{
  struct node *ptr,*temp;
  ptr = h->next;
  while (ptr->next!=NULL)
    {
      temp=h->next;
      h->next=ptr->next;
      ptr->next = (h->next)->next;
      (h->next)->next = temp;
    }
 
}

void deleteElt(struct node *h,int ele)
{ struct node *ptr;
  struct node *prev;
  int res = search(h,ele);
  if (res != -1)
  { ptr=h;
  prev=h->next;
   int k =0;
  while (ptr!=NULL)
    {
      if (ptr->data == ele)
      {
        if (k==0)
        {
          //h->next=ptr->next;
          break;
        }
        else
        {
       prev->next=ptr->next;
       break;
        }
      }
      else
      {
        k++;
        prev=ptr;
        ptr=ptr->next;
      }
     }
  }
  else
  {
    printf("Element doesnt exist!");
  }
}


void tocorrupt(struct node *h,int k)
{
    struct node *ptr,*end,*prev;
    int k1=0;
    ptr=h->next;
    while(ptr!=NULL)
    {
        k1++;
        if (k1==k)
            {
                end=ptr;
            }
        else
           { 
            prev=ptr;
           ptr=ptr->next;
           }
    }
    prev->next = end;
}

int corrupt(struct node *h)
{
    struct node *ptr;
    ptr=h->next;
    struct node *arr[100];
    int i=0;
    while(ptr!=NULL)
    {
        if (i==0)
            {arr[i]=ptr;
            i++;
            ptr=ptr->next;
            }
        else
        {
            int count = 0;
            for (int j=0;j<i;j++)
            {
                if (ptr==arr[j])
                    count+=1;

                if (count>0)
                    return 1;
            }
            i++;
            ptr=ptr->next;
        }
        
    }
    return 0;
}

