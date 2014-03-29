#include<stdio.h>
#include<stdlib.h>
struct node
{
	struct node *prev;
	int key;
	struct node *next;
};

typedef struct node ELEMENT;
typedef ELEMENT *LINK;

int empty_que(LINK head)
{
	return (head == NULL);
}

LINK enque(LINK tail,int ins)
{
//	printf("entered enque\n");
	LINK temp;
	temp = tail;
	if (tail == NULL)
	{
//		printf("entered null");
		tail = malloc(sizeof(ELEMENT));
		tail->key = ins;
		tail->next = NULL;
		tail->prev = NULL;
		printf("\n");
        	return tail;
	}
	else
	{
		tail->prev = malloc(sizeof(ELEMENT));
		temp = tail->prev;
		temp->key = ins;
		temp->next = tail;
		temp->prev = NULL;
	}
	printf("\n");
	return temp;
}
LINK deque(LINK head)
{
	LINK temp = head;
	if(temp == NULL)
	printf("EMPTY\n");
	else
	{
		printf("%d\n",head->key);
		temp = head->prev;
		if(temp != NULL)
		temp->next = NULL;
	}
	return temp;
}
void seek(LINK head)
{
	if(head == NULL)
	printf("EMPTY\n");
	else
	printf("%d\n",head->key);
}
void show(LINK head)
{
	if(head == NULL)
	printf("EMPTY\n");
	else
	{
		LINK temp = head;
		while(temp->prev != NULL)
		{
			printf("%d ",temp->key);
			temp = temp->prev;
		}
		printf("%d",temp->key);
	}
	printf("\n");
}
int read(FILE *p)
{
	int n;
	fscanf(p,"%d",&n);
	return n;
}

void do_it(FILE *p)
{
//	printf("entered do_it\n");
	int mode = read(p);
	LINK head = NULL,tail = NULL;
	while(mode != 0)
	{
		if(mode == 1)
		{
			int ins = read(p);
			tail = enque(tail,ins);
			if(head == NULL)
			head = tail;
		}
		if(mode == 2)
		{
			head = deque(head);
			if(head == NULL)
			tail = NULL;
		}
		if(mode == 3)
		seek(head);
		if(mode == 4)
		show(head);

		mode = read(p);
	}
}

void main()
{
	char *input;
	input = malloc(30*sizeof(char));
	printf("enter the file name: ");
	scanf("%s",input);
	FILE *p;
	p = fopen(input,"r+");
	do_it(p);
}
