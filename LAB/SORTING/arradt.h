#include <stdio.h>
#include <stdlib.h>

struct array
{
    int size;
    int arr[100];
};

void init(struct array *a,int s)
{
    a->size=s;
}

void insertElements(struct array *a,int a1[])
{
    a->arr[0]=-999;
    for (int i=0;i<a->size;i++)
    {
        a->arr[i+1]=a1[i];
    }
}

void display(struct array *a)
{
    
    for (int i=1;i<=a->size;i++)
    {
        printf("%d ",a->arr[i]);
    }
}



void inssort(struct array *a)
{
    int i,j;
    for (int i=2;i<=a->size;i++)
    {
        j=i;
        while (a->arr[j-1]>a->arr[j])
        {
            int temp=a->arr[j-1];
            a->arr[j-1]=a->arr[j];
            a->arr[j]=temp;
            j=j-1;
        }
    }
    
}

void shellsort(struct array *a)
{
    int j;
    int incr=a->size/2;
    while (incr>0)
    {
        for (int i=incr+1;i<=a->size;i++)
        {
            j=i-incr;
            while (j>0)
            {
                if (a->arr[j]>a->arr[j+incr])
                {
                    int temp=a->arr[j];
                    a->arr[j]=a->arr[j+incr];
                    a->arr[j+incr]=temp;
                    j=j-incr;
                }
                else
                    j=0;
            }
            
        }
        incr=incr/2;
    }
}


int first(struct array *a,int ele)
{
    int low=0;
    int high=a->size;
    //printf("\n%d ",high);
    int mid;
    while (high>low)
    {
       mid=low+(high-low)/2;
        if (a->arr[mid]==ele)
        {
          if (mid==0 || a->arr[mid-1]!=ele)
            return mid;
          else
            high=mid;
            
        }
        else if (a->arr[mid]>ele)
            low=mid+1;
        else
            high=mid-1;
    }
    
   
}

int last(struct array *a,int ele)
{
    int low=0;
    int high=a->size;
    //printf("\n%d ",high);
    int mid;
    while (high>low)
    {
       mid=low+(high-low)/2;
        if (a->arr[mid]==ele)
        {
          if (mid==a->size || a->arr[mid+1]!=ele)
            return mid;
          else
            low=mid+1;
            
        }
        else if (a->arr[mid]>ele)
            low=mid+1;
        else
            high=mid-1;
    }
    
   
}


