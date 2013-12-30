#include<stdio.h>
#include<stdlib.h>
#define ARRAY_SIZE( array ) sizeof( array ) / sizeof( array[0] )
	

	/*int peak(int a[])
	{
	int b = (ARRAY_SIZE(a) - 1);
	if(a[b/2] <= a[b/2 - 1] )
		peak(sub(a,0,(b/2 - 1)));
		else
		if(a[b/2] <= a[b/2 + 1])
			peak(sub(a,(b/2 +1),b));
		else
		return a[b/2];	
	}*/
	

	int* sub(int *a, int start, int stop) //start and stop are the indices
	{
		int i;
		int *c;
		int b = stop - start + 1;
		c = malloc(b*sizeof(int));
		for(i=0;i < b;i++)
			*(c+i) = *(a+i+start);
		return c;

	}
	int peak(int *a,int n)
	{
		if(*(a + n/2) <= *(a + n/2 - 1))
			peak(sub(a,0,(n/2 - 1)),(n/2 - 1));
		else
			if(*(a + n/2) <= *(a + n/2 + 1))
				peak(sub(a,(n/2 +1),n),(n - n/2 - 1));
			else
				return *(a+n/2);

	}
	void main()
	{
		

		int a[5] = {1, 3, 2, 1, 0};
		int *d = &a[0];
		int *c = sub(a,0,1);
		int e = peak(d,5);
		printf("%d\n",e);
		
	}