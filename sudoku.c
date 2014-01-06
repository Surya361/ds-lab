#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void read(int **a,int n)
{
	int i,j;
	for(i=0;i<n;i++)
	for(j=0;j<n;j++)
	scanf("%d",(*(a+i)+j));
}
int readv(int **a,int **b,int n)
{
	int i,j,k;
	for(i=0;i<n;i++)
	for(j=0;j<n;j++)
	{
		scanf("%d",&k);
		if(k <= n && k > 0 && (*(*(a+i)+j) == k || *(*(a+i)+j) == 0))
		*(*(b+i)+j) = k;
		else
		{
			printf("no, solution inconsistent with sudoku, row-%d column-%d\n",i+1,j+1);
			return 0;
		}
	}
}

int fqcy(int *a,int n)
{
	int i,j=0,k=0;
	for(i=1;i<=n;i++)
	{
		k = 0;
		for(j=0;j<n;j++)
		{
			if(*(a+j) == i)
			k++;
		}
	if(k > 1)
	{
		printf("repeating %d ",i);
		return 0;
	}
	}
	return 1;
}
int fqcyrow(int **a,int n)
{
	int i,k;
	for(i=0;i<n;i++)
	{
		k = fqcy(*(a+i),n);
		if(k)
		;
		else
		{
			printf("in row %d\n",i+1);
			return 0;
		}
	}
	return 1;
}
int fqcyclm(int **a,int n)
{
	int i,k,*b;
	b = malloc(n*sizeof(int));
	for(i=0;i<n;i++)
	{
		for(k=0;k<n;k++)
		{
			*(b+k) = *(*(a+k)+i);
		}
		if(fqcy(b,n))
		;
		else
		{
			printf("in column %d\n",i+1);
			return 0;
		}
	}
	return 1;
}

int checkblk(int **a,int n)
{
	int i,j,k,l,z=0;
	int in = sqrt(n);
	int *b;
	b = malloc(n*sizeof(int));
	for(i=0;i<=n-in;i=i+in)
	{
		for(j=0;j<=n-in;j=j+in)
		{
			int z=0;
			for(k=0;k<in;k++)
			{
				for(l=0;l<in;l++)
				{
					*(b+z) = *(*(a+i+k)+j+l);
					z++;
				}
			}
			if(fqcy(b,n))
			;
			else
			{
				printf("in block %d%d\n",i/in,j/in);
				return 0;
			
			}
			
		}
	}
	return 1;
}

void main()
{
	printf("Input : ");
	int n,i;
	scanf("%d",&n);
	int **a;
	a = malloc(n*sizeof(int *));
	for(i=0;i<n;i++)
	*(a+i) = malloc(n*sizeof(int));
	int **b;
        b = malloc(n*sizeof(int *));
        for(i=0;i<n;i++)
        *(b+i) = malloc(n*sizeof(int));
	printf("Sudoku : \n");
	read(a,n);
	printf("Candidate solution : \n");
	if(readv(a,b,n) == 0)
	exit(1);
	if(fqcyrow(b,n) == 0)
	exit(1);
	if(fqcyclm(b,n) == 0)
	exit(1);
	if(checkblk(b,n) == 0)
	exit(1);
	printf("Yes\n");
}
