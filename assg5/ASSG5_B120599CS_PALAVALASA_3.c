#include<stdio.h>
#include<stdlib.h>

struct pque
{
	int data;
	int pri;
};
typedef struct pque prq;
//typedef prq *link;
int heapsize = -1;

int read(FILE *p)
{
	int n;
	fscanf(p,"%d",&n);
	return n;
}
int left(int i)
{
	return (2*(i+1)-1);
}
int right(int i)
{
	return (2*(i+1));
}
int parent(int i)
{
	return(((i+1)/2)-1);
}
prq * min_heapify(prq *a,int i)
{
	int smallest;
	int l = left(i);
	int r = right(i);
	if(r <= heapsize && ((a+r)->pri) < ((a+i)->pri))
		smallest = r;
	else
		smallest = i;
	if(l <= heapsize && ((a+l)->pri) < ((a+smallest)->pri))
		smallest = l;
	if(smallest != i)
	{
		prq *temp;
		temp = malloc(1*sizeof(prq));
		temp->data = (a+i)->data;
		temp->pri = (a+i)->pri;
		(a+i)->data = (a+smallest)->data;
		(a+i)->pri = (a+smallest)->pri;
		(a+smallest)->data = temp->data;
		(a+smallest)->pri = temp->pri;
		min_heapify(a,smallest);
	}
	return a;
}
prq * removee(prq *pq)
{
	if (heapsize < 0)
	printf("EMPTY\n");
	else
	{
	//	printf("%d(%d)\n",(pq->data),(pq->pri));
		(pq)->data = (pq+heapsize)->data;
		pq->pri = (pq+heapsize)->pri;
		heapsize--;
		pq = min_heapify(pq,0);
	}
	return pq;
}
int search(prq *p,int dat)
{
	int i=0;
	while(i<=heapsize)
	{
		if ((p+i)->data == dat)
		return i;
		i++;
	}
	return -1;
}
prq * increase_pri(prq *pq,int dat,int pr)
{
	int i = search(pq,dat);
	if(i != -1)
	{
		(pq+i)->pri = pr;
		while(i>0 && (((pq+(parent(i)))->pri) > (pq+i)->pri))
		{
			prq *temp;
			temp = malloc(1*sizeof(prq));
			temp->data = (pq+i)->data;
			temp->pri = (pq+i)->pri;
			(pq+i)->data = (pq+parent(i))->data;
			(pq+i)->pri = (pq+parent(i))->pri;
			(pq+parent(i))->pri = temp->pri;
			(pq+parent(i))->data = temp->data;
			i = parent(i);
		}
	}
//	printf("\n");
	return pq;	
}
prq * insert(prq *pq,int key,int da)
{
	heapsize = heapsize+1;
	(pq+heapsize)->data = da;
	(pq+heapsize)->pri = 1000000;
	pq = increase_pri(pq,da,key);
//	printf("\n");
	return pq;
}

void make(int edg,int **adj,FILE *p)
{
	while(edg)
	{
		int one = read(p);
		int two = read(p);
		int w = read(p);
		*(*(adj + one)+two) = w;
		*(*(adj + two)+one) = w;
		edg--;
	}
}

void dj(int **adj,int ver,int edg,int s)
{
	int *d = malloc(ver*sizeof(int));
	int *pi = malloc(ver*sizeof(int));
	int v;
	for(v=0;v<ver;v++)
	{
		*(d+v) = 999999;
		*(pi+v) = -1;
	}
	*(d+s) = 0;
	prq *q = malloc(edg*sizeof(prq));
	for(v = 0;v<ver;v++)
	{
		insert(q,*(d+v),v);
	}
	while(heapsize >= 0)
	{
//		printf("enter\n");
		int u = q->data;
		int pri = q->pri;
		removee(q);
		for(v=0;v<ver;v++)
		{
			if(*(*(adj+v)+u) != 0)
			{
				if(*(d+v) > *(d+u) + *(*(adj+u)+v))
				{
//					printf("enter1\n");
					*(d+v) = *(u+d) + *(*(adj+u)+v);
					*(v+pi) = u;
					increase_pri(q,v,*(d+v));
				}
			}
		}
	}
	for(v=0;v<ver;v++)
	{
		printf("%d  ",*(d+v));
	}
}

void main()
{
	char *a;
	a = malloc(20*sizeof(char));
	printf("enter the input file name: ");
	scanf("%s",a);
	FILE *p;
	p = fopen(a,"r+");
	int ver = read(p);
	int edg = read(p);
	int **adj;
	adj = malloc(ver*sizeof(int *));
	int i;
	for(i=0;i<ver;i++)
	*(adj + i) = malloc(ver*sizeof(int));
	make(edg,adj,p);
	int s;
	printf("enter the source: ");
	scanf("%d",&s);
	dj(adj,ver,edg,s);
}
