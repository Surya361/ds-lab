#include<stdio.h>
#include<stdlib.h>
int prime(int n)
{
	int i,yes=1;
	for(i=2;i<=n/2;i++)
	{
		if(n%i != 0)
		yes =1;
		else
		{
			yes = 0;
			break;
		}
	}
	return yes;
}
void primef(int n)
{
	int i;
	for(i=2;i<n;i++)
	{
		if(prime(i) && n%i == 0)
		printf("%d ",i);
	}
}


void main()
{
	int n;
	printf("Enter n :");
	scanf("%d",&n);
	primef(n);
}
