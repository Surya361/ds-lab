#include<stdio.h>
#include<stdlib.h>

struct node
{
	struct node *prev;
	int data;
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
int search(int ser,int cap,link *b)
{
	int i = ser%cap;
	printf("%d ",i);
	link a = *(b+i);
	link temp = *(b+i);
	if(a == NULL)
	printf("NOT FOUND\n");
	else
	{
		while(temp != NULL)
		{
			if(temp->data == ser)
			{
			printf("FOUND\n");
			return 0;
			}
			temp = temp->next;
		}
		printf("NOT FOUND\n");
	}
}
link *  insert(int ins,int cap,link *b)
{
	int i = ins%cap;
	if(*(b+i) == NULL)
	{
		printf("%d\n",i);
		*(b+i) = malloc(sizeof(element));
		(*(b+i))->data = ins;
		(*(b+i))->next = NULL;
		(*(b+i))->prev = NULL;
	}
	else
	{
		link temp = *(b+i);
		*(b+i) = malloc(sizeof(element));
		(*(b+i))->data = ins;
		(*(b+i))->next = temp;
		printf("%d\n",i);
	}
	return b;
	
}
void do_it(FILE *p,int n)
{
	int mode = read(p);
	link *a;
	a = malloc(n*sizeof(link));
	while(mode != 0)
	{
		if(mode == 1)
		{
			int ins = read(p);
			int i = ins%n;
			a = insert(ins,n,a);
		}
		if(mode == 2)
		{
			int ser = read(p);
			search(ser,n,a);
		}
		mode = read(p);
	}
}

void main()
{
	char *input;
	input = malloc(30*sizeof(char));
	printf("enter the file name : ");
	scanf("%s",input);
	FILE *p;
	p = fopen(input,"r+");
	if(p != NULL )
	{
	int n = read(p);
	do_it(p,n);
	}
}
