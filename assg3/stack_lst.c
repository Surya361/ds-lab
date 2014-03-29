#include<stdio.h>
#include<stdlib.h>

int read(FILE *p)
{
	int n;
	fscanf(p,"%d",&n);
	return n;
}
struct node
{
	struct node *prev;
	int key;
	struct node *next;
};
typedef struct node ELEMENT;
typedef ELEMENT *LINK;

int empty(LINK head)
{
	if(head == NULL)
	return 1;
	return 0;
}
LINK push(LINK head,int ins)
{
	LINK temp;
	if(empty(head))
	{
		temp = malloc(sizeof(ELEMENT));
		temp->key = ins;
		temp->next = NULL;
		temp->prev = NULL;
	}
	else
	{
		head->prev = malloc(sizeof(ELEMENT));
		temp = head->prev;
		temp->key = ins;
		temp->next = head;
		temp->prev = NULL;
	}
	printf("\n");
	return temp;
}
LINK pop(LINK head)
{
	LINK temp;
	temp = NULL;
	if(empty(head))
	printf("EMPTY\n");
	else
	{
		printf("%d\n",(head->key));
		temp = head->next;
		//temp->prev = NULL;
	}
	return temp;
}

void seek(LINK head)
{
	if(empty(head))
	printf("EMPTY\n");
	else
	printf("%d\n",head->key);
}
void print_stack(LINK head)
{
	LINK temp;
	temp = head;
	if(empty(head))
	printf("EMPTY\n");
	else
	{
		while(temp->next != NULL)
		{
			printf("%d ",temp->key);
			temp = temp->next;
		}
		printf("%d",temp->key);
	}
	printf("\n");
}
void do_it(FILE *p)
{
	int mode = read(p);
	LINK head = NULL;
	while(mode != 0)
	{
		if(mode == 1)
		{
			int ins = read(p);
			head = push(head,ins);
		}
		if(mode == 2)
		head = pop(head);
		if(mode == 3)
		seek(head);
		if(mode == 4)
		print_stack(head);
		
		mode = read(p);
	}
}

void main()
{
	char *input;
	input = malloc(30*sizeof(char));
	printf("enter file name: ");
	scanf("%s",input);
	FILE *p;
	p = fopen(input,"r+");
	do_it(p);
}
