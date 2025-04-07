#include <stdio.h>

void main()
{
    printf("enter the vertex : ");
    int n;
    scanf("%d",&n);
    int sum=0;
    int temp=n;
    while (temp>0)
    {
        sum+=temp;
        temp=temp/2;
    }
    printf("SUM : %d",sum);
}