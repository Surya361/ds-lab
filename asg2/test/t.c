#include<stdio.h>
#include<stdlib.h>

void main()
{
	FILE *a;
	a = fopen("test","w");
	long i,j,k;
	
	for(j=0;j<64;j++)
	for(i=0;i<1024;i++)
	for(k=0;k<1024;k++)
	{
		int b = rand();
		fprintf(a,"%d\n",b);
	}
}
