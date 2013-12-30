#include<stdio.h>
#include<stdlib.h>

int zer(int a)
{
	int b,k=0;
	
	while(a%5 == 0)
			{
				a = a/5;
				k++;
			}

	
	return k;
}

int main()
{
	int a,i,b,j,k;
	a = readuint();
	int *l;
	l = malloc(a*sizeof(int));
	for(i=0;i<a;i++)
	{	
		k = 0;
		b = readuint();
		for(j=5;j<=b;j=j+5)
		{
			k = zer(j) + k;
		}
		*(l+i) = k;
		printf("%d\n",k );
	}
	//for(i=0;i<a;i++)
		//printf("%d\n",*(l+i) );
	return 0;
	
}