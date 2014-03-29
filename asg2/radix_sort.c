#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void print(long *a,int n)
{
        int i;
        for(i=0;i<n;i++)
        printf("%lx\n",*(a+i));
}

long* read(FILE *p)
{
	int n;
	fscanf(p,"%d",&n);
//	printf("%d\n",n);
	long *v;
	v = malloc((n+1)*sizeof(long));
	*v = n;
//	printf("%d\n",*v);
	int i=1;
	while(i != n+1)
	{
		fscanf(p,"%lx",(v+i));
//		printf("%x\n",*(v+i));
		i++;
	}
	return v;
}
void swap(long *a,long *b)
{
	long temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
void radix_sort(long *a,int n)
{
	int i;
	for(i=0;i<10;i++)
	{
		int p = pow(10,(i+1));
        	int k,j;
        	for(k=0;k<n;k++)
        	{
                	for(j=k;j!=0;j--)
                	{
                        	if(((*(a+j)) % p) < ((*(a+j-1)) % p))
                        	swap((a+j-1),(a+j));
                        	else
                        	break;
                	}
        	}


	}
}
void main()
{
	clock_t start = clock();
	printf("enter the file name\n");
	char *a;
	a = malloc(10*sizeof(char));
	scanf("%s",a);
	FILE *p;
	p = fopen(a,"r+");
	if(p == NULL)
	{
		printf("invalid file name\n");
		exit(1);
	}
	long *b;
	b = read(p);
	int n;
	n = *b;
//	printf("%d",n);
	b++;
	radix_sort(b,n);
	print(b,n);
	clock_t end = clock();
	double time = (end-start)/CLOCKS_PER_SEC;
	printf("running time is %d\n",time);
}
