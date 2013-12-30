#include<stdio.h>
#include<stdlib.h>

int main()
{
	long a,b,i,j,k=0;
	scanf("%ld %ld",&a,&b);
	for(i=0;i<a;i++)
	{
		scanf("%ld",&j);
		if(j%b == 0)
			k++;

	}
	printf("%ld\n",k );
	return 0;
}