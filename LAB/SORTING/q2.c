#include <stdio.h>
#include <stdlib.h>
#include "q2.h"

int main()
{
    struct hash *hashQuad, *hashDouble;
    hashQuad = (struct hash *)malloc(sizeof(struct hash));
    hashDouble = (struct hash *)malloc(sizeof(struct hash));
    
    int n, x=1,elt, ch,q,d,y=1;
    printf("Enter the size of the hash table: ");
    scanf("%d", &n);
    create(hashQuad, n);
    create(hashDouble, n);

    while(x)
    {
        printf("1.Quadratic Probing\n2.Double Hashing\n3.Exit:\n");
        printf("enter your choice : ");
        scanf("%d", &ch);
        
        if(ch==1)
        {
            printf("No of elements to be inserted : ");
            scanf("%d", &q);
            for(int i=0; i<q; i++)
            {
                printf("Enter element : ");
                scanf("%d", &elt);
                insertQuad(hashQuad,elt);
            }
            printf("Quadratic Probing Hash Table:\n");
            displayHT(hashQuad);
        }

        else if(ch==2)
        {
            printf("No of elements to be inserted : ");
            scanf("%d", &d);
            for(int i=0; i<d; i++)
            {
                printf("Enter element : ");
                scanf("%d", &elt);
                insertDouble(hashDouble,elt);
            }
            printf("Double Hashing Hash Table:\n");
            displayHT(hashDouble);
        }

        else
        {
            x=0; break;
        }
    }
}

