#include<stdio.h>
#include<stdlib.h>

int sub(int,int);
int add(int,int);
void main()
{
	int (*art)(int,int);
	int a,b,choice;
	printf("enter the two numbers");
	scanf("%d%d",&a,&b);
	printf("NOTE: 1 for addition, 2 for subtraction\n enter the choice :");
	scanf("%d",&choice);
	if(choice == 1)
	{
		art = add;
		printf("the sum is %d\n",(*art)(a,b));
	}
	else
	if(choice == 2)
	{
		art = sub;
		printf("the difference id %d\n",(*art)(a,b));
	}
}
int add(int a,int b)
{
	return a+b;
}

int sub(int a,int b)
{
	return a-b;
}
