#include <stdio.h>
#include <stdlib.h>

struct tree
{
	int data;
	struct tree *left,*right;
};


struct tree *insert(struct tree *t,int x)
{
	if (t==NULL)
	{
		t=(struct tree *)malloc(sizeof(struct tree));
		t->data=x;
		t->left=t->right=NULL;	
	}
	else if (x>t->data)
	{
		t->right=insert(t->right,x);
		
	}
	else if (x<t->data)
	{
		t->left=insert(t->left,x);
	}
	return t;
}


void printname(struct tree *t,int x)
{
	for (int i = 0;i<x;i++)
	{
		printf("\t");
	}
	printf("%d\n",t->data);

}

void levelorder(struct tree *t,int x)
{
	printname(t,x);
	if (t->left!=NULL)
		levelorder(t->left,x+1);
	if (t->right!=NULL)
		levelorder(t->right,x+1);
}

int *inorder(struct tree *t,int p[])
{
    static int i =0;
    if (t->left!=NULL)
        inorder(t->left,p);
    p[i]=t->data;
	i++;
    if (t->right!=NULL)
        inorder(t->right,p);
	return p;
}

int *inorder1(struct tree *t,int p[])
{
    static int j =0;
    if (t->left!=NULL)
        inorder1(t->left,p);
    p[j]=t->data;
	j++;
    if (t->right!=NULL)
        inorder1(t->right,p);
	return p;
}

int *sort(int root1[],int root2[],int res[],int n1,int n2)
{
	int i=0,j=0,k=0;
	while(i<n1 && j<n2)
	{
		if (root1[i]<root2[j])
		{
			res[k]=root1[i];
			i++;
			k++;
		}
		else
		{
			res[k]=root2[j];
			j++;
			k++;
		}
	}
	while (i<n1)
	{
		res[k]=root1[i];
		k+=1;i+=1;
	}
	while (j<n2)
	{
		res[k]=root2[j];
		k++;j++;
	}
	return res;
}