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

  printf("--ADDITION--\n");
  printf("enter the number to be added :");
  int num;
  scanf("%d", &num);
  int res1 = add(header, num);

  printf("\n---PALINDROME---\n");
  int res = palindrome(header,res1);
  if (res==1)
    printf("YES!\n");
  else
    printf("NO!\n");
}