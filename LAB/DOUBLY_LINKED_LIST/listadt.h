#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct node
{
  int data;
  struct node *left;
  struct node *right;
};
struct node* search(struct node *h,int ele)
{
  struct node *ptr;
  ptr = h->right;
  while (ptr!=NULL)
    {
      if (ptr->data == ele)
          return ptr;
      ptr = ptr->right;
    }
  return NULL;
}

void insertfront(struct node *h,int ele)
{
  struct node *temp;
  temp=(struct node *)malloc(sizeof(struct node));
  temp->data = ele;
  if (h->right == NULL)
  {
    temp->right = h->right;
    h->right = temp;
    temp->left = h;
  }
  else
  {
    struct node *ptr;
    ptr=h->right;
    temp->left=h;
    temp->right = ptr;
    ptr->left = temp;
    h->right = temp;
  }
}

void insertend(struct node *h, int ele) {

  struct node *ptr, *prev;
  ptr = h->right;
  if (ptr == NULL) {
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = ele;
    temp->right = h->right;
    temp->left = h;
    h->right = temp;
  } else {
    while (ptr != NULL) {
      prev = ptr;
      ptr = ptr->right;
    }
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = ele;
    temp->right = prev->right;
    prev->right = temp;
    temp->left = prev;
  }
}

void insertmiddle(struct node *h,int key,int ele)
{
  struct node *ptr;
  ptr = search(h,key);
  if (ptr==NULL)
    printf("Key not found!!\n");
  else if (ptr->right != NULL)
  {
    struct node *temp,*next;
    next = ptr->right;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->data = ele;
    temp->right = ptr->right;
    temp->left = next->left;
    next->left = temp;
    ptr->right = temp;
  }
  else
  {
    struct node *temp,*next;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->data = ele;
    temp->right = ptr->right;
    ptr->right = temp;
    temp->left=ptr;
  }
}

void display(struct node *h)
{
  struct node *ptr,*prev;
  ptr=h->right;
  printf("FORWARD :");
  while(ptr!=NULL)
    {
      printf("%d ",ptr->data);
      prev=ptr;
      ptr=ptr->right;
    }
  printf("\n");
  printf("BACKWARD:");
  while (prev->left!=NULL)
    {
      printf("%d ",prev->data);
      prev=prev->left;
    }
}




void delete(struct node *h,int ele)
  {
  struct node *res;
  res=search(h,ele);
  if (res==NULL)
    printf("Key not found!!\n");
  else if (res->right!=NULL)
  {
    struct node *p1,*p2;
    p1=res->left;
    p2=res->right;
    p1->right=p2;
    p2->left=p1;
  }
  else
  {
    struct node *p1;
    p1=res->left;
    p1->right=NULL;
  }
  }
int duplicate(struct node *h)
{
  struct node *ptr,*pt;
  int dup;
  ptr = h->right;
  pt = ptr->right;
  while(ptr!=NULL)
    {
      dup=ptr->data;
      while(pt!=NULL)
        {
          if (dup==pt->data)
            return 1;
          else
            pt=pt->right;
        }
      ptr=ptr->right;
    }
  return 0;
}

void evenodd(struct node *h,struct node *h1,struct node *h2)
{
  struct node *ptr;
  ptr=h->right;
  while(ptr!=NULL)
    {
      if ((ptr->data)%2==0)
      {insertfront(h1,ptr->data);
        ptr=ptr->right;}
      else 
      {insertfront(h2,ptr->data);
       ptr=ptr->right;
      }  
    }
}
void posneg(struct node *h,struct node *h1,struct node *h2)
{
  struct node *ptr;
  ptr=h->right;
  while(ptr!=NULL)
    {
      if ((ptr->data>0))
      {insertfront(h1,ptr->data);
        ptr=ptr->right;}
      else 
      {insertfront(h2,ptr->data);
       ptr=ptr->right;
      }  
    }
}

void add(struct node *h, struct node *h1) {
  struct node  *pt;
  int len = 10;
 
  //printf("%d \n", len);
  int n = 0;
  pt = h->right;
  while (pt != NULL) {
    len = len - 1;
    n += ((pt->data) * ((int)pow(10, len)));
    pt = pt->right;
  }
  struct node  *pt1;
  int len1 = 10;
  
  //printf("%d \n", len);
  int n1 = 0;
  pt1 = h1->right;
  while (pt1 != NULL) {
    len1 = len1 - 1;
    printf("%d ",pt1->data);
    n1 += ((pt1->data) * ((int)pow(10, len1)));
    pt1 = pt1->right;
  }
  printf("%d %d \n",n1,n);
  int sum = n1+n;
  int temp=sum;

  struct node *h2;
  h2=(struct node *)malloc(sizeof(struct node));
  h2->left=h2->right=NULL;
  while (sum > 0) 
  {
    insertfront(h2, sum % 10);
    sum = sum / 10;
  }
  display(h2);
}

int palindrome(struct node *h, int num) {
  int temp = num;
  int rev = 0;
  int i = 0;

  while (temp > 0) {
    rev = (rev * 10) + (temp % 10);
    temp = temp / 10;
    i = i + 1;
  }
  if (rev==num)
    return 1;
  else
    return 0;
}

int findmiss(struct node *h,int k)
{
	struct node *ptr;
	ptr=h->right;
	int k1=0;
	for (int i=1;i<25;i++)
	{
		if (ptr->right!=NULL)
		{
			if ((i!=ptr->data)&&(i<ptr->data))
			{
				k1++;
				if (k1==k)
					return i;
			}
			else
			{
				ptr=ptr->right;
			}
		}
		else
		{
			if (k1==k)
				return i;
			else
				k1+=1;
      }
		}
  }

  int divisor(struct node *h)
{
	struct node *ptr;
	int i=1;
	int k =1;
	while(k=1)
	{
		int sum=0;
    ptr=h->right;
		while(ptr!=NULL)
		{
			sum+=ceil((ptr->data)/i);
			ptr=ptr->right;
		}
		if (sum<=8)
		{
			break;
		}
		else
			{i+=1;}
	}
	return i;
}
