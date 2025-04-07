#include <stdio.h>
#include <stdlib.h>
struct poly
{
	int coeff;
	int exp;
	struct poly *next;
};


void insert(struct poly *h,int c,int e)
{
  struct poly *ptr;
  ptr = h->next;
  if (ptr == NULL)
  {
     struct poly *temp;
  temp=(struct poly*)malloc(sizeof(struct poly));
  temp->coeff = c;
  temp->exp = e;
    temp->next = h->next;
    h->next = temp;
  }
  else
  {
     struct poly *temp;
    temp=(struct poly*)malloc(sizeof(struct poly));
    temp->coeff = c;
    temp->exp = e;
    struct poly *prev;
    prev = h->next;
    while (ptr!=NULL)
      {
        prev = ptr;
        ptr = ptr->next;
      }
    temp->next = prev->next;
    prev->next = temp;
  }
  
}

void display(struct poly *h)
{
	struct poly *ptr;
	ptr = h->next;
	while (ptr!=NULL)
		{
			printf("%d x^%d + ",ptr->coeff,ptr->exp);
			ptr=ptr->next;
		}
}

void add(struct poly *h1,struct poly *h2)
{
  struct poly *p1,*p2;
  p1 = h1->next;
  p2 = h2->next;
  struct poly *sum;
  sum=(struct poly*)malloc(sizeof(struct poly));
  sum->next = NULL;
  while ((p1!=NULL) && (p2!=NULL))
    {
      if (p1->exp == p2->exp)
      {
        insert(sum,p1->coeff+p2->coeff,p1->exp);
        p1=p1->next;
        p2=p2->next;
      }
      else if (p1->exp > p2->exp)
      {
        insert(sum,p1->coeff,p1->exp);
        p1=p1->next;
      }
      else if(p1->exp < p2->exp)
      {
        insert(sum,p2->exp,p2->exp);
        p2=p2->next;
      }
    }
  
  while (p1!=NULL)
    {
      insert(sum,p1->coeff,p1->exp);
      p1=p1->next;
    }
  while (p2!=NULL)
    {
      insert(sum,p2->coeff,p2->exp);
      p2=p2->next;
    }
  display(sum);
}

