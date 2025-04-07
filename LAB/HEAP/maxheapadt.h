//max heap

struct pq
{
	int arr[1000];
	int size;

};

void init(struct pq *p)
{
	p->size=0;
	p->arr[0]=1000;
}

void insert(struct pq *p,int ele)
{
	int i;
	for (i=++p->size;p->arr[i/2]<ele;i=i/2)
	{
		p->arr[i]=p->arr[i/2];
	}
	p->arr[i]=ele;



}

void display(struct pq *p)
{
	for (int i = 1;i<=p->size;i++)
	{
		printf("%d ",p->arr[i]);
	}
}

int delete(struct pq *p)
{
	int i,child;
	int me,le;
	me=p->arr[1];
	le=p->arr[p->size--];
	
	for (i=1;(2*i)<=p->size;i=child)
	{
		child = i*2;
		if (p->arr[child+1]>p->arr[child])
			child++;
		if (le<p->arr[child])
			p->arr[i]=p->arr[child];
		else
			break;
	}
	
	p->arr[i]=le;
	return me;

}