#include<stdio.h>
#include<stdlib.h>
//int top = 0;
int read(FILE *p)
{
	int n;
	fscanf(p,"%d",&n);
	return n;
}
int empty(int *top)
{
	if(top == NULL)
	return 1;
	else
	return 0;
}
int * push(int *top,int ins,int *btm)
{
	if(top == NULL)
	{
		top = btm;
		*top = ins;
		printf("\n");
	}
	else
	{
		*(top+1) = ins;
		top = top+1;
		printf("\n");
	}
	return top;
}
int * pop(int *top,int *btm)
{
	if(empty(top))
	printf("EMPTY\n");
	else
	{
		if(top == btm)
		{
			printf("%d\n",*top);
			top = NULL;
		}
		else
		{
			printf("%d\n",*top);
			top = top-1;
		}
	}
	return top;
}
void peek(int *top)
{
	if(empty(top))
	printf("EMPTY\n");
	else
	printf("%d\n",*top);
}
void print_stack(int *top,int *btm)
{
	if(empty(top))
	printf("EMPTY\n");
	else
	{
		int i=0;
		while((btm+i) != top)
		{
			printf("%d ",*(top-i));
			i++;
		}
		printf("%d\n",*(top-i));
		
	}
}
void do_it(FILE *p,int *btm,int cap)
{
	int *top;
	int count = 0;
	top = NULL;
	int mode = read(p);
	while(mode != 0)
	{
		if(mode == 1)
		{
			if(count >= cap)
			printf("STACK OWERFOLW\n");
			else
			{
				int ins = read(p);
				top = push(top,ins,btm);
				count++;
			}
		}
		if(mode == 2)
		{
			top = pop(top,btm);
			count--;
		}
		if(mode == 3)
		peek(top);
		if(mode == 4)
		print_stack(top,btm);
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
	int *btm = malloc(n*sizeof(int));
	do_it(p,btm,n);
}
