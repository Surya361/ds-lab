#include<stdio.h>
#include<stdlib.h>

void swap(int *a, int *b)
{
	int temp  = *a;
	*a = *b;
	*b = temp;
}

void sort(int *a,int n)
{
	int i;
	for(i=1;i<n;i++)
	{
		int j=i;
		while(j != 0 && *(a+j) < *(a+j-1))
		{
			swap((a+j),(a+j-1));
			j--;
		}
	}
}
void print(int *a,int n)
{
	int i;
	for(i=0;i<n;i++)
	printf("%d\t",*(a+i));
	
	printf("\n");
}

void main()
{
	printf("enter the size of the array");
	int size,i,*a;
	scanf("%d",&size);
	a = malloc(size * sizeof(int));
	for(i=0;i<size;i++)
	scanf("%d",a+i);
	sort(a,size);
	print(a,size);
}
