#include<stdio.h>
#include<stdlib.h>

struct node
{
	struct node *left;
	int data;
	int pri;
	struct node *right;
	struct node *parent;
};
typedef node element;
typedef element *link;

int read(FILE *p)
{
	int n;
	fscanf(p,"%d",&n);
	return n;
}
link left(link a)
{
	return a->left;
}
link right(link a)
{
	return a->right;
}
link parent(link a)
{
	return a->parent;
}
link min_heapify(link a,link i)
{
	link smallest;
	link l = left(a);
	link r = right(a);
	if((r != NULL) && ((r->pri) < (i->pri)))
	smallest = r;
	else
	smallest = i;
	if((l != NULL) && ((l->pri) < (smallest->pri)))
	smallest = l;
	if(smallest != i)
	{
		link temp;
		temp = mallco(sizeof(element));
		temp->data = i->data;
		temp->pri = i->pri;
		i->data = smallest->pri;
		i->pri = smallest->pri;
		smallest->data = temp->data;
		smallest->pri = temp->pri;
		min_heapify(a,smallest);
	}
	return a; 
}
void peek(link a)
{
	if(a == NULL)
	printf("EMPTY\n");
	else
	printf("%d(%d)\n",(a->data),(a->pri));
}
link removee(link pq)
{
	if(pq == NULL)
	printf("EMPTY\n");
	else
	{
		printf("%d(%d)\n",(pq->data),(pq->pri));
		pq->data = 
	}
}
link parent
link insert()
void main()
{
	char *input;
	input = malloc(30*sizeof(char));
	printf("enter file name");
	scanf("%s",input);
	FILE *p;
	p = fopen(input,"r+");
}
