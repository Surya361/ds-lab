#include<stdio.h>
#include<stdlib.h>

struct node
{
	struct node *prev;
	int data;
	int pri;
	struct node *next;
};
typedef struct node element;
typedef element *link;

int read(FILE *p)
{
	int n;
	fscanf(p,"%d",&n);
	return n;
}

link insert(link a,int ins,int p)
{
	link temp;
	temp = a;
	if(a == NULL)
	{
		a = malloc(sizeof(element));
		a->data = ins;
		a->pri = p;
		a->next = NULL;
		a->prev = NULL;
	}
	else
	{
		if(temp->pri > p)
		{
			temp->prev = malloc(sizeof(element));
			(temp->prev)->next = temp;
			temp = temp->prev;
			temp->data = ins;
			temp->pri = p;
			temp->prev = NULL;
			a = temp;
			printf("\n");
			return a;
		}
		while( temp->next != NULL && (temp->pri) < p)
		{
			temp = temp->next;
		}
		if(temp->prev != NULL)
		temp = temp->prev;
		link tem = temp->next;
		temp->next = malloc(sizeof(element));
		(temp->next)->next = tem;
		(temp->next)->prev = temp;
		temp = temp->next;
		if(temp->next != NULL)
		(temp->next)->prev = temp;
		temp-> data = ins;
		temp->pri = p;

	}
	printf("\n");
	return a;
}
void peek(link a)
{
	if(a == NULL)
	printf("EMPTY\n");
	else
	printf("%d(%d)\n",(a->data),(a->pri));
}
link removee(link a)
{
	if(a == NULL)
	printf("EMPTY\n");
	else
	{
		printf("%d(%d)\n",(a->data),(a->pri));
		if(a->next == NULL)
		return NULL;
		a = a->next;
		if(a->next != NULL)
		a->prev = NULL;
	}
	return a;
}
link delete(link a,int dat)
{
	link temp = a;
	while(temp->data != dat && temp != NULL)
	temp = temp->next;
	if(temp->prev == NULL)
	{
		a = temp->next;
		a->prev = NULL;
		return a;
	}
	(temp->prev)->next = temp->next;
	if(temp->next != NULL)
	(temp->next)->prev = temp->prev;
	return a;
}
link inc_pri(link a,int ins,int np)
{
	a = delete(a,ins);
	a = insert(a,ins,np);
	return a;
}
void do_it(FILE *p)
{
	int mode = read(p);
	link pq = NULL;
	while(mode != 0)
	{
		if(mode == 1)
		{
			int daat = read(p);
			int prri = read(p);
			pq = insert(pq,daat,prri);
		}
		if(mode ==2)
		pq = removee(pq);
		if(mode == 3)
		peek(pq);
		if(mode == 4)
		{
			int daat = read(p);
			int np = read(p);
			pq = inc_pri(pq,daat,np);
		}
		mode = read(p);
	}
}
void main()
{
	char *input;
	input = malloc(30*sizeof(char));
	printf("enter file name : ");
	scanf("%s",input);
	FILE *p;
	p = fopen(input,"r+");
	if(p != NULL)
	do_it(p);
}
