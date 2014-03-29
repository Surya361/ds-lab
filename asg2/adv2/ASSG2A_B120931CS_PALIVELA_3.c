#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

int randomized_select(int a[],int p,int r,int i)
{
	int k,q;
	if(p==r)
		return a[p];
		q=partition(a,p,r);
		k=q-p+1;
		if(i==k)
			return a[q];
		else if(i<k)
			return randomized_select(a,p,q-1,i);
		else
			return randomized_select(a,q+1,r,i-k);
}

void swap (int a[], int i, int j)
{
 int temp;
 temp=a[i];
 a[i]=a[j];
 a[j]=temp;
}
 

int partition( int a[], int p, int r )
{
	int i, j;
	int x;
	int pivot = i = p;
	x = a[p];
	j = r;
	while ( i < j )
	{
		while( a[i] <= x )
  		i++;
  		while( a[j] > x )
  		j--;
 		if ( i < j )
  			swap(a,i,j);
	}
	a[p] = a[j];
	a[j] = x;
	return j;
}

/*int partition(int *a,int p,int r)
{
	int j;
	int x = a[r];
	int i = p-1;
	for(j=p;j<r;j++)
	{
		if(a[j] <= x)
		{
			i = i+1;
			swap(a,i,j);
		}
	}
	swap(a,i+1,r);
	return i+1;
	
	
}*/


void main()
 {
	clock_t begin, end;
	double time_spent;
	begin = clock();
	FILE *fp;
	char filename[50];
	printf("ENTER THE FILENAME:");
	scanf("%s", filename);
	fp=fopen(filename,"r");
	if (fp == NULL) 
	{
		printf("no such file exists");
		exit (1);
	}
	else
	{	
		int n,j=0;
		char c[50];
		fgets(c,50,fp);
		n=atoi(c);
		int *a,q;
		a=malloc(n*sizeof(int));
		float p;
		while(j<n)
		{	
			fgets(c,50,fp);
			a[j]=atoi(c);
			j++;
		}	
		fclose(fp);
		if(n%2==1)
		{
			q=n/2;
			p=randomized_select(a,0,n-1,q+1);
		}
		else
		{
			q=n/2;
			p=randomized_select(a,0,n-1,q+1);
			//printf("%f",p);
			p=p+randomized_select(a,0,n-1,q);
			//printf("%f",p);
			p=p/2;
		}		
			printf("%f\n",p); 
		end = clock();
		time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
		printf("\ntime spent:%fsecs",time_spent);
		free (a);
	}
 }

