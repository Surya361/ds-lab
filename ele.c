#include<stdio.h>
#include<stdlib.h>

void swap(int *a,int *b)
{
	int temp = *b;
	*b = *a;
	*a = temp;
}

void sort(int *a, int n)
{
	int i,j;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-1-i;j++)
		{
			if(*(a+j) > *(a+j+1))
				swap((a+j),(a+j+1));
		}
			
	}
}

void main()
{
	printf("enter the size of the array\n" );
	int a,i;
	scanf("%d",&a);
	int *arr;
	arr = malloc(a*sizeof(int));
	for(i=0;i<a;i++)
	{
		printf("enter the number \n");
		scanf("%d",arr+i);
	}
	sort(arr,i);
	printf("%d\n",arr[a/2]);
}
