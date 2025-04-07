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

void inorder(struct tree *t)
{
	if (t->left!=NULL)
		inorder(t->left);
	printf("%d ",t->data);
	if (t->right!=NULL)
		inorder(t->right);
}

void preorder(struct tree *t){
printf("%d ",t->data);
if(t->left!=NULL)
    preorder(t->left);
if(t->right!=NULL)
    preorder(t->right);

}

void postorder(struct tree *t){
if(t->left!=NULL)
    postorder(t->left);
if(t->right!=NULL)
    postorder(t->right);
printf("%d ",t->data);
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


struct tree* findmin(struct tree *t)
{
	if (t->left==NULL)
		return t;
	else
		findmin(t->left);
}

int search(struct tree *t,int key)
{
    if (t!=NULL)
    {
        if (key==t->data)
            return 1;
        else if(key<t->data)
            search(t->left,key);
        else if (key>t->data)
            search(t->right,key);
        
    }
    else
        return 0;
}


struct tree *delete(struct tree *t,int x)
{
	struct tree *tmp;
	if (x<t->data)
		t->left=delete(t->left,x);
	else if (x>t->data)
		t->right=delete(t->right,x);
	else if (t->left &&t->right)
	{
		tmp=findmin(t->right);
		t->data=tmp->data;
		t->right=delete(t->right,tmp->data);
	}
	else
	{
		tmp=t;
		if (t->right==NULL)
			t=t->left;
		else if (t->left==NULL)
			t=t->right;
		free(tmp);
	}
	return t;
}
int node(struct tree *t)
{
    static int n=0;
    if (t->left!=NULL)
        node(t->left);
    n+=1;
    if (t->right!=NULL)
        node(t->right);
    return n;
}

int nodecheck(struct tree *t,struct tree *t1)
{
    int n = node(t);
    printf("NODE OF TREE 1 : %d\n",n);
    int n1 = node(t1)-n;
    printf("NODE OF TREE 2 : %d\n",n1);
}
//QUES2
int check(struct tree *t,struct tree *t1)
{
   if (t->left!=NULL && t1->left!=NULL)
		check(t->left,t1->left);
	if (t->data !=  t1->data)
        return 1;
	if (t->right!=NULL && t1->right!=NULL)
		check(t->right,t1->right);
    
}

//QUES3
int num(struct tree *t,int l,int h)
{
	static int n=0;
    if (t==NULL)
        return n;
    else
    {
        if (t->data>=l && t->data<=h)
        {   
			n+=1;
			printf("%dst NODE :",n);
            printf(" %d\n",t->data);
			
            num(t->left,l,h);
           num(t->right,l,h);
            
        }
    	 if (t->data<l)
        {
            num(t->right,l,h);
        }
        if (t->data>h)
        {
            num(t->left,l,h);
        }
    }
}

//QUES 5 check is bst
int maxinleft(struct tree *t)
{
	while(t->right!=NULL)
		t=t->right;
	return t->data;
}

int mininright(struct tree *t)
{
	while(t->left!=NULL)
		t=t->left;
	return t->data;
}

int checkbst(struct tree *t)
{
		if (t==NULL)
			return 1;
		if (t->right==NULL && t->left==NULL)
			return 1;
		int lmax,rmin;
		if (t->left!=NULL)
			lmax=maxinleft(t->left);
		else
			lmax=0;
		
		if (t->right!=NULL)
			rmin=mininright(t->right);
		else
			rmin=t->data;
		
		if (lmax>t->data || t->data > rmin)
			{	
				return 0;
			}
		int a,b;
		a=checkbst(t->left);
		b=checkbst(t->right);
		if (a==1 && b==1)
			return 1;
		else
			return 0;
	
}

//sum of k min

int sum(struct tree *t,int k)
{
	static int s=0;static int n=0;
	if (t->left!=NULL)
		sum(t->left,k);
	if (n!=k)
		{
		s+=t->data;
		n++;}
	if (n==k)
		return s;
	if (t->right!=NULL)
		sum(t->right,k);
}

