#include <stdio.h>
#include <stdlib.h>
#include "hashing.h"

int main()
{
    struct hash *h;
    h = (struct hash *)malloc(sizeof(struct hash));
    int size, ch, element, key, x=1;

    printf("Enter the size of the hash table: ");
    scanf("%d", &size);
    create(h, size);

    while(x)
    {
        printf("\n1.Insert \n2.Search \n3. Display\n4. Exit \n");
        printf("enter your choice : ");
        scanf("%d", &ch);
        if(ch==1)
        {
            for(int i=0; i<size; i++)
            {
                printf("Enter the element to insert: ");
                scanf("%d", &element);
                insert(h, element);
            }
        }
        
        else if(ch==2)
        {
            printf("Enter the element to search: ");
            scanf("%d", &key);
            if (searchElement(h, key) == 1)
                printf("Element found in the hash table.\n");
            else
                printf("Element not found in the hash table.\n");
        }
        
        else if(ch==3)
        {
            printf("Hash Table Contents:\n");
            displayHT(h);
        }
        
        else
        {
            x=0; 
            break;
        }
    }
}
