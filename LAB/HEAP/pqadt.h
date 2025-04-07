struct employee
{
	char id;
	long int salary;
};

struct pq
{
	struct employee arr[100];
	int size;

};

void init(struct pq *p)
{
	p->size=0;
	p->arr[0].salary=1000000;
}

void insert(struct pq *p,struct employee *e)
{
	int i;
	for (i=++p->size;p->arr[i/2].salary<e->salary;i=i/2)
	{
		p->arr[i].id=p->arr[i/2].id;
		p->arr[i].salary=p->arr[i/2].salary;
	}
	p->arr[i].id=e->id;
	p->arr[i].salary=e->salary;

}

void display(struct pq *p)
{
	for (int i = 1;i<=p->size;i++)
	{
		printf("(%c,%ld) ",p->arr[i].id,p->arr[i].salary );
	}
}

char delete(struct pq *p)
{
	int i,child;
    char mec,lec;
    mec=p->arr[1].id;
    lec=p->arr[p->size].id;
	long int les;
	les=p->arr[p->size--].salary;
	
	for (i=1;(2*i)<=p->size;i=child)
	{
		child = i*2;
		if (p->arr[child+1].salary>p->arr[child].salary)
			child++;
		if (les<p->arr[child].salary)
		{	p->arr[i].id=p->arr[child].id;
            p->arr[i].salary=p->arr[child].salary;
        }
		else
			break;
	}
	p->arr[i].salary=les;
	p->arr[i].id=lec;
	return mec;

}