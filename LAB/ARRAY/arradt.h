#include <stdio.h>
struct array {
  int size;
  int arr[100];
};

void create(struct array *a, int s, int arr[]) {
  a->size = s;
  for (int i = 0; i < a->size; i++) {
    a->arr[i] = arr[i];
  }
}

void peak(struct array *a)
{  int arr1[a->size];
  int k=0;
  for (int i=0;i<a->size;i++)
    {
      if (i==0)
      {
        if (a->arr[i+1]<a->arr[i])
        {
          arr1[k]=a->arr[i];
          k++;
        }
       }
        else if (i>0 && i<=a->size-2)
        {
        if ((a->arr[i-1]<a->arr[i])&& (a->arr[i+1]<a->arr[i]))
        {
          arr1[k]=a->arr[i];
          k++;
        }
      }
      else if (i==a->size-1)
        {
          if (a->arr[i-1]<a->arr[i])
          {
            arr1[k]=a->arr[i-1];
            k++;
          }
        }} create(a,k,arr1);}

void display(struct array *a) {
  for (int i = 0; i < a->size; i++) {
    printf("%d ", a->arr[i]);
  }
  printf("\n");
}

void insertfront(struct array *a, int front) {

  for (int i = a->size - 1; i >= 0; i--) {
    int temp = a->arr[i];
    a->arr[i + 1] = temp;
  }
  a->arr[0] = front;
  a->size = a->size + 1;
}

void insertmiddle(struct array *a, int middle, int ind) {
  for (int i = a->size - 1; i >= ind; i--) {
    int temp = a->arr[i];
    a->arr[i + 1] = temp;
  }
  a->arr[ind] = middle;
  a->size = a->size + 1;
}

void insertend(struct array *a, int end) {
  a->arr[a->size] = end;
  a->size = a->size + 1;
}

void delete (struct array *a, int del) {
  int pos=0;
  for (int i = 0; i < a->size; i++) {
    if (a->arr[i] == del) {
      break;
    } else
    {pos = pos + 1;
  }
  }
      
  for (int i = pos; i < a->size; i++) {
    a->arr[i] = a->arr[i + 1];
  }
  a->size = a->size - 1;
}

int search(struct array *a, int ele) {
  int pos = 1;
  for (int i = 0; i < a->size; i++) {
    if (a->arr[i] == ele) {
      break;
    } else
      pos = pos + 1;
  }
  if (pos == a->size + 1)
    return -1;
  else
    return pos;
}

void insertevery(struct array *a,int ele)
{
 for (int i=a->size;i>=0;i--)
    {
      int temp = a->arr[i];
      a->arr[(i*2)+1]=temp;
    }
  a->size = a->size*2;
  for (int i=0;i<a->size;i=i+2)
    {
      a->arr[i]=ele;
    }
}