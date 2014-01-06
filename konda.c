#include<stdio.h>
#include<stdlib.h>
void main()
{
	int **a;
	int i,j,n;
	scanf("%d",&n);
	a = malloc(n*sizeof(int *));
	for(i=0;i<n;i++)
	{
		*(a+i) = malloc(n*sizeof(int));
	}
	
	for(i=0;i<n;i++)
	for(j=0;j<n;j++)
	scanf("%d",(*(a+i)+j));
}
