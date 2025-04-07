#include <stdio.h>
#include <stdlib.h>
#include "arradt.h"

void main()
{
    struct array *a;
    a=(struct array*)malloc(sizeof(struct array));
    printf("enter the size of the array : ");
    int n;scanf("%d",&n);
    init(a,n);
    int arr[n];
    for (int i=0;i<n;i++)
    {
        printf("enter the element : ");
        int ele;
        scanf("%d",&ele);
        arr[i]=ele;
    }
    insertElements(a,arr);
    printf("\nDISPLAY\n");
    display(a);
    printf("\n\nINSERTION SORT\n");
    inssort(a);
    display(a);
    insertElements(a,arr);
    printf("\n\nSHELL SORT\n");
    printf("\n");
    shellsort(a);
    display(a);
    printf("\nElement that appears Once\n");
    printf("enter the element : ");
    int elt;scanf("%d",&elt);
    int s1=first(a,elt);
    int e1=last(a,elt);
    if (s1==e1)
        printf("YES\n");
    else
        printf("NO\n");
    printf("\nFIND OCCURANCES\n");
    printf("enter the element :");
    int f;scanf("%d",&f);
    int s=first(a,f);
    
    int e=last(a,f);
    printf("NUMBER OF OCCURANCES : %d",(e-s+1));
}