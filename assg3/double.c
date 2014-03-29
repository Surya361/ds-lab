#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
	struct node *prev;
};
typedef struct node ELEMENT;
typedef ELEMENT *LINK;

int read(FILE *p)
{
	int n;
	fscanf(p,"%d",&n);
	return n;
}

LINK double_link(int n,FILE *p)
{
	LINK tail1,tail2, head = NULL;
	if(n != 0)
	{
		head = malloc(sizeof(ELEMENT));
		head -> data = read(p);
		head -> prev = NULL;
		tail1 = head;
		tail2 = head;
		int i;
		for(i=1;i<n;i++)
		{
			tail1 -> next = malloc(sizeof(ELEMENT));
			tail1 = tail1 -> next;
			tail1 -> prev = tail2;
			tail2 = tail1;
			tail1 -> data = read(p);
		}
		tail1 -> next = NULL;
	}
	return head;
}
void delete(LINK h)
{
	if(h -> next != NULL && h -> prev != NULL )
	{
		((h -> prev) -> next) = h -> next;
		((h -> next) -> prev) = h -> prev;
	}
	if(h -> next == NULL && h -> prev != NULL)
	((h -> prev) -> next) = NULL;
	else
	((h -> next) -> prev) = NULL;
		
}
void delete_al(LINK he)
{
	LINK temp;
	temp = he;
	while(temp -> next != NULL)
	{
		delete(temp -> next);
		if(temp -> next == NULL)
		break;
		temp = temp -> next;
		
	}
}
void print(LINK hea)
{
	LINK temp;
	printf("%d\n",(hea -> data));
	temp = hea;
	while(temp -> next != NULL)
	{
		temp = temp -> next;
		printf("%d\n",(temp -> data));
	}
}

void main()
{
	char *input;
	input = malloc(30*sizeof(char));
	printf("enter file name\n");
	scanf("%s",input);
	FILE *p;
	p = fopen(input,"r+");
	int n = read(p);
	LINK head = double_link(n,p);
	delete_al(head);
	print(head);
}
