#include<stdio.h>
#include<stdlib.h>
void search(int p, int *q, int r)
{
	int i,j;
	for(i=0;i<r;i++)
	{
		if(p == *(q+i))
		{
			j = i;
			break;
		}	
		else
			j = -1;

	}
	printf("%d\n",j );
	

}
void main()
{
	int i,b,c,d;
	int *a;
	printf("enter the size of array\n");
	scanf("%d",&i);
	a = malloc(i*sizeof(int));
	printf("enter the numbers ");
	for(b=0;b<i;b++)
	{
		scanf("%d",(a+b));
		
	}
	
	printf("enter the value to be searched\n");
	scanf("%d",&c);
	search(c,a,i);
}