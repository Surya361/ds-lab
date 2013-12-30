#include<stdio.h>
#include<stdlib.h>

int gcd(int n1, int n2)
{
	if (n2%n1 == 0)
	{ 
		return n1;
	}	
	else
	{
		gcd(n2%n1,n1);
	}	
	
}

int lcm(int n1, int n2)
{
	return (n1*n2)/gcd(n1,n2);
}

void main()
{
	int num1, num2;
	printf("enter two numbers\n");
	scanf("%d",&num1);
	scanf("%d",&num2);
	int gc = gcd(num1,num2);
	int lc = lcm(num1,num2);
	printf("the gcd is : %d\nthe lcm is : %d\n",gc,lc); 
}