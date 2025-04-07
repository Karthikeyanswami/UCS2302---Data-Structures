#include "listadt.h"
#include <stdio.h>
#include <stdlib.h>

void main() {
  struct node *header;
  header = (struct node *)malloc(sizeof(struct node));
  header->left = NULL;
  header->right = NULL;
  printf("----INSERT END---\n");
  printf("enter the number of elements :");
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    printf("ELEMENT : %d\n", (i + 1));
    printf("enter the element :");
    int a;
    scanf("%d", &a);
    insertend(header, a);
  }
  printf("---DISPLAY---\n");
  display(header);
  printf("\n");

  struct node *header1;
  header1 = (struct node *)malloc(sizeof(struct node));
  header1->left = NULL;
  header1->right = NULL;
  printf("----INSERT END---\n");
  printf("enter the number of elements :");
  int n1;
  scanf("%d", &n1);
  for (int i = 0; i < n1; i++) {
    printf("ELEMENT : %d\n", (i + 1));
    printf("enter the element :");
    int a;
    scanf("%d", &a);
    insertend(header1, a);
  }
  display(header1);
  printf("\n");
  add(header,header1);
}