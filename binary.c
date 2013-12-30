#include<stdio.h>
#include<stdlib.h>

int* sub(int *a, int start, int stop) 
	{
		int i;
		int *c;
		int b = stop - start + 1;
		c = malloc(b*sizeof(int));
		for(i=0;i < b;i++)
			*(c+i) = *(a+i+start);
		return c;

	}
int search(int *a, int b, int n)
{
	if(*(a + n/2) == b)
		return 1;
	else if (*(a + n/2) > b)
		search(sub(a,0,n/2-1),b,n/2);
	else if(*(a+n/2) < b)
		search(sub(a,n/2+1,n),b,n/2 - 1);
	
}


void main()
{
	int b[5] = {1,3,5,6,7};
	int *a = &b[0];
	int c = search(a,6,4);
	printf("%d\n",c );
}
