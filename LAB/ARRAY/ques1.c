#include "arradt.h"
#include <stdio.h>
#include <stdlib.h>

void main() {
  struct array *a;
  a = (struct array *)malloc(sizeof(struct array));
  printf("enter the size :");
  int n;
  scanf("%d", &n);
  int arr[n];
  for (int i = 0; i < n; i++) {
    printf("enter the element : ");
    int ele;
    scanf("%d", &ele);
    arr[i] = ele;
  }
  create(a, n, arr);
  printf("\n---DISPLAYING---\n");
  display(a);
 
 
   printf("\n---INSERT BEFORE EVERY ELEMENT --\n");
  printf("enter the element :");
  int elt;
  scanf("%d", &elt);
  insertevery(a, elt);
  display(a);
  /*printf("Enter the element to be inserted at the front \n");
  int front;
  scanf("%d", &front);
  insertfront(a, front);
  printf("array after insertion at first place\n");
  display(a);
  printf("\n");*/
  /*printf("enter the element to be inserted in the middle position");
  printf("element : ");
  int middle;
  scanf("%d", &middle);
  printf("enter the index :");
  int ind;
  scanf("%d", &ind);
  insertmiddle(a, middle, ind);
  printf("array after insertion of the element \n");
  display(a);
  printf("\n");
  printf("enter the element to be inserted at the end : ");
  int end;
  scanf("%d", &end);
  insertend(a, end);
  printf("array after insertion at the end : \n");
  display(a);*/
  printf("\n");
  printf("enter the element to be deleted :");
  int del;
  scanf("%d", &del);
  delete (a, del);
  printf("\n");
  printf("array after deletion :\n");
  display(a);
  printf("\n");
  printf("enter the element to be searched : ");
  int ele;
  scanf("%d", &ele);
  int res = search(a, ele);
  if (res == -1)
    printf("element not found!");
  else
    printf("element found at position %d", res);
printf("\n---PEAK--\n");
peak(a);
display(a);
}