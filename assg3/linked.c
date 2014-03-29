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
	int data;
	struct node *next;
};
typedef struct node ELEMENT;
typedef ELEMENT *LINK;

LINK single_list(int n, FILE *p)
{
	LINK head = NULL, tail;
	if (n != 0)
	{
		int i;
		head = malloc(sizeof(ELEMENT));
		head -> data = read(p);
		tail = head;
		for(i=1;i<n;i++)
		{
			tail -> next = malloc(sizeof(ELEMENT));
			tail = tail -> next;
			tail -> data = read(p);
		}
		tail -> next = NULL;
	}
	return head;
}
int count(LINK h)
{
	int i;
	LINK cmp;
	cmp = h;
	for(i=0;cmp != NULL;)
	{
		if ((cmp -> data) > 10)
		i++;
		cmp = cmp -> next;	
	}
	return i;
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
	printf("%d\n",n); //comment it out after completing
	LINK head = single_list(n,p);
	int cnt = count(head);
	printf("the number is %d\n",cnt);
}
