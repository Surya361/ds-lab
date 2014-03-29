#include<stdio.h>
#include<stdlib.h>
//int has[100];

int read(FILE *p)
{
	int n;
	fscanf(p,"%d",&n);
	return n;
}
int hashfun(int n,int mod)
{
	return n%mod;
}

int * insert(int *a,int ins,int max)
{
	int i,n;
	for(i=0;i<max;i++)
	{
		n = hashfun(ins,max);
		n = n+i;
		n = hashfun(n,max);
		if(*(a+n) == 0)
		{
			printf("%d\n",n);
			*(a+n) = ins;
			return a;
		}
		printf("%d ",n);
		
	}
	printf("HASH FULL\n");
}

int search(int *a,int ser,int max)
{
	int i,n;
	for(i=0;i<max;i++)
	{
		n = hashfun(ser,max);
		n = n+i;
		n = hashfun(n,max);
		if(*(a+n) == ser)
		{
			printf("%d FOUND\n",n);
			return 0;
		}
		if(*(a+n) == 0)
		{
			printf("%d NOTFOUND\n",n);
			return 0;
		}
		printf("%d ",n);
	}
	printf("NOT FOUND\n");
	return 0;
}

void do_it(FILE *p)
{
	int max = read(p);
	int mode = read(p);
	int *hash;
	hash = malloc(max*sizeof(int));
	while(mode != 0)
	{
		if(mode == 1)
		{
			int ins = read(p);
			hash = insert(hash,ins,max);
		}
		if(mode == 2)
		{
			int ser = read(p);
			search(hash,ser,max);
		}
		mode = read(p);
	}
}
void main()
{
	char *input;
	input = malloc(30*sizeof(char));
	printf("enter the file name: ");
	scanf("%s",input);
	FILE *p;
	p = fopen(input,"r+");
	if(p!=NULL)
	do_it(p);
	else
	printf("invalid file name\n");
}
