#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct hash
{
    int size;
    struct node *list[100];
};

void create(struct hash *h, int size)
{
    h->size = size;
    for (int i = 0; i < h->size; i++)
    {
        h->list[i] = (struct node *)malloc(sizeof(struct node));
        h->list[i]->next = NULL;
    }
}

void insert(struct hash *h, int x)
{
    int index = x % h->size;
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->next = NULL;
    temp->data = x;

    struct node *ptr;
    ptr = h->list[index];
    while (ptr->next != NULL)
        ptr = ptr->next;
    ptr->next = temp;
}

int searchElement(struct hash *h, int key)
{
    int index = key % h->size;
    struct node *ptr = h->list[index]->next; 
    while (ptr != NULL)
    {
        if (ptr->data == key)
            return 1; 
        ptr = ptr->next;
    }
    return -1;
}

void displayHT(struct hash *h)
{
    struct node *ptr;
    for (int i = 0; i < h->size; i++)
    {
        printf("%d -> ",i);
        ptr = h->list[i]->next; 
        while (ptr != NULL)
        {
            printf("%d ", ptr->data);
            ptr = ptr->next;
        }
        printf("\n");
    }
}
