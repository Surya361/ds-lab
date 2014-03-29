#include<stdio.h>
#include<stdlib.h>

void main()
{
	int i;
	int **a;
	a = malloc(10*sizeof(int *));
//	for(i=0;i<10;i++)
//	*(a+i) =  malloc(1*sizeof(int));
//	**a = 10;

	if(*a == NULL)
	printf("hello");
}
