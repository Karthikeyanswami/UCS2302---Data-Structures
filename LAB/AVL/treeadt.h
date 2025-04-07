#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct tree
{
    int data,height;
    struct tree *left,*right;
};

int max(int a,int b)
{
    if (a>b)
        return a;
    else
        return b;
}

int height(struct tree *t)
{
    if (t==NULL)
        return -1;
    else
        return t->height;
}

struct tree *sll(struct tree *k2)
{
    struct tree *k1;
    k1=k2->left;
    k2->left=k1->right;
    k1->right=k2;
    k2->height= max(height(k2->left),height(k2->right))+1;
    k1->height = max(height(k1->left),height(k1->right))+1;
    return k1;

}

struct tree *srr(struct tree *k1)
{
    struct tree *k2;
    k2=k1->right;
    k1->right = k2->left;
    k2->left=k1;
    k1->height = max(height(k1->left),height(k1->right))+1;
    k2->height=  max(height(k2->left),height(k2->right))+1;
    return k2;
}

struct tree *dlr(struct tree *k1)  //left subtree right child
{
    k1->right = sll(k1->right);
    return srr(k1);
}

struct tree *drl(struct tree *k1) //right subtree of left child
{
    k1->left = srr(k1->left);
    return sll(k1);
}


struct tree *insert(struct tree *t,int x)
{
    if (t==NULL)
    {
        t=(struct tree *)malloc(sizeof(struct tree));
        t->data = x;
        t->height = 0;
        t->left=t->right=NULL;
    }
    else if (x<t->data)
    {
        t->left = insert(t->left,x);
        if (height(t->left)-height(t->right)==2)
        {
            if (x<t->left->data)
                t=sll(t);
            else 
                t=drl(t);
        }
    }
    else if (x>t->data)
    {
        t->right=insert(t->right,x);
        if (height(t->right)-height(t->left)==2)
        {
            if (x>t->right->data)
                t=srr(t);
            else
                t=dlr(t);
        }
    }
    t->height = max(height(t->left),height(t->right))+1;
    return t;
}

void inorder(struct tree *t)
{
    if (t->left!=NULL)
        inorder(t->left);
    printf("%d ",t->data);
    if (t->right!=NULL)
        inorder(t->right);
}

void print(int e,int x)
{
    for (int i =0;i<x;i++)
    {
        printf("\t");
    }
    printf("%d\n",e);
}


void levelorder(struct tree *t,int x)
{
    if (t!=NULL)
    {
    print(t->data,x);
    if (t->left!=NULL)
        levelorder(t->left,x+1);
    if (t->right!=NULL)
        levelorder(t->right,x+1);
    }
}

int findparent(struct tree *t,int k)
{
    if (t!=NULL)
    {
        if (t->left->data ==k || t->right->data==k)
            return t->data;
        else if (k<t->data)
            findparent(t->left,k);
        else if (k>t->data) 
            findparent(t->right,k);
    }
    
}