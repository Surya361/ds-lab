#include<stdio.h>
#include<stdlib.h>

void read(int *a,int n)
{
	int i;
	for(i=0;i<n;i++)
	scanf("%d",a+i);
}
void write(int *a,int n)
{
        int i;
        for(i=0;i<n;i++)
        printf("%d ",*(a+i));
}
void swap(int *b,int *a)
{
        int temp;
        temp = *b;
        *b = *a;
        *a = temp;
}

void reverse(int *a,int st, int n )
{
	if(st >= n)
	return;
	else
	swap(a+st,a+n);
	reverse(a,st+1,n-1);
}

void main()
{
	int *a,n;
	printf("Enter the value for n\n");
	scanf("%d",&n);
	a = malloc(n*sizeof(int));
	printf("Enter the elements of array\n");
	read(a,n);
	write(a,n);
	printf("\n");
	reverse(a,0,n-1);
	write(a,n);
	printf("\n");
}
