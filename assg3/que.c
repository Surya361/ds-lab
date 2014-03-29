#include<stdio.h>
#include<stdlib.h>
int head = 0,tail = 0;
int read(FILE *p)
{
	int n;
	fscanf(p,"%d",&n);
	return n;
}

void enque(int *a,int ins,int cap)
{
	if(head == (tail+1)%cap)
	printf("QUEOVERFLOW\n");
	else
	{
		*(a+tail) = ins;
		tail = ((tail + 1) % cap);
		printf("\n");
	}
}
void deque(int *a,int cap)
{
	if(head == tail)
	printf("EMPTY\n");
	else
	{
		printf("%d\n",*(a+head));
		head = ((head+1) % cap);
	}
}
void peek(int *a)
{
	if(head == tail)
	printf("EMPTY\n");
	else
	printf("%d\n",*(a+head));
}
void show(int *a,int cap)
{
	if(head == tail)
	printf("EMPTY\n");
	int h = head;
	int t = tail;
	while( h != t)
	{
		printf("%d ",*(a+h));
		h = ((h+1) % cap) ;
	}
	printf("\n");
}
void do_it(FILE *p,int cap)
{
	int *q = malloc(cap*sizeof(int));
	int mode = read(p);
	while(mode != 0)
	{
		if(mode == 1)
		{
			int ins = read(p);
			enque(q,ins,cap);
		}
		if(mode == 2)
		deque(q,cap);
		if(mode == 3)
		peek(q);
		if(mode == 4)
		show(q,cap);

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
	int n = read(p);
	do_it(p,n);
}
