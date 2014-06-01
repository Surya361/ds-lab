#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *parent;
	int rank;
};
typedef struct node element;
typedef element *link;

struct hell
{
	int n1;
	int n2;
	int weight;
};
typedef struct hell edge;
typedef edge *edgel;

int read(FILE *p)
{
	int k;
	fscanf(p,"%d",&k);
	return k;
}

void make_set(link a,int d)
{
	a->parent = a;
	a->data = d;
	a->rank = 0;
}

link find_set(link a)
{
	link temp;
	temp = a;
	while(temp->parent != temp)
	temp = temp->parent;
	while(a->parent != a)
	{
		a->parent = temp;
		a = a->parent;
	}
	return a;
}

int unio(link x,link y)
{
        link rootx = find_set(x);
        link rooty = find_set(y);
        if (rootx == rooty)
        return 0;
        if(rootx->rank < rooty->rank)
                rootx->parent = rooty;
        else
        if((rootx->rank) > (rooty->rank))
                rooty->parent = rootx;
        else
        {
                rooty->parent = rootx;
                rootx->rank = rootx->rank + 1;
        }
}


link search(link a,int max,int dat)
{
	int i=0;
	for(i=0;i<max;i++)
	{
		if((a+i)->data == dat)
		return (a+i);
	}
	return NULL;
}

void mak(int ver,int edg,FILE *p,edgel a)
{
	int i;
	i = 0;
	while(edg)
	{
		int one = read(p);
		int two = read(p);
		int w = read(p);
		(a+i)->n1 = one;
		(a+i)->n2 = two;
		(a+i)->weight = w;
		--edg;
		i++;
	}
}
void sort(edgel h,int edg)
{
//	printf("%d ",edg);
	int i,j;
	int k;
	for(i=0;i<edg;i++)
	{
		k = i;
		for(j=i;j<edg;j++)
		{
			if((h+j)->weight < (h+k)->weight)
			k = j;
		}
		int a = (h+k)->n1 ;
		int b = (h+k)->n2 ;
		int w = (h+k)->weight ;
		(h+k)->n1 = (h+i)->n1;
		(h+k)->n2 = (h+i)->n2;
		(h+k)->weight = (h+i)->weight;
		(h+i)->n1 = a;
		(h+i)->n2 = b;
		(h+i)->weight = w;
	}
}
void print(int **a,int ver)
{
	int i,j;
	for(i=0;i<ver;i++)
	{
		for(j=0;j<ver;j++)
		printf("%d ",(*(*(a+i)+j)));
		printf("\n");
	}
}
edgel mst(edgel h,int ver,int edg)
{
	link set;
	set = malloc(ver*sizeof(element));
	int res[ver][ver];
	int dot,fo;
	for(dot=0;dot<ver;dot++)
	for(fo=0;fo<ver;fo++)
	res[dot][fo] = 0;
	int i;
	for(i = 0;i<ver;i++)
	{
		make_set((set+i),i);
	}
	int total = 0;

	sort(h,edg);
	int off = 0;
	for(off=0;off<edg;off++)
	{
		int u = (h+off)->n1;
		int v = (h+off)->n2;
		int w = (h+off)->weight;
		if(find_set(set+u) != find_set(set+v))
		{
			total = total+w;
			res[u][v] = w;
			res[v][u] = w;
			unio((set+u),(set+v));
		}
	}
	printf("%d\n",total);
	int z,y;
	for(z =0;z<ver;z++)
	{
		for(y=0;y<ver;y++)
		printf("%d ",res[z][y]);
		printf("\n");
	}
}
void main()
{
	char *a;
	a = malloc(30*sizeof(char));
	printf("enter file name: ");
	scanf("%s",a);
	FILE *p;
	p = fopen(a,"r+");
	int ver = read(p);
	int edg = read(p);
	edgel h = malloc(edg*sizeof(edge));
	mak(ver,edg,p,h);
	mst(h,ver,edg);
	
}
