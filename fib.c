#include<stdio.h>
#include<stdlib.h>

void fib(long n)
{	
	long i , a=0,b=1,c;
	for(i=0;i<n;i++)
	{	
		if(i<=1)
		{
			c  = i;
			printf("%ld\n",c);
		}	
		else
		{
			c = a+b;
			a = b;
			b = c;
			printf("%ld\n",c);
		}

	}

}



void main()
{
	printf("enter the number\n");
	long i;
	scanf("%ld",&i);
	if(i<= 93)
	fib(i);
	else
		fib(93);
	printf("maximum storage limit exeeded\n");
}