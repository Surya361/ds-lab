#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int * read(FILE *p)
{
        int j =1,i=0;
        int c;
        char *b;
        b = malloc(10*sizeof(char));
        while((c = fgetc(p)) != '\n')
        {
                *(b+i) = c;
                i++;
        }
        int e = atoi(b);
        //printf("%d\n",e);
        int *a = malloc(e*sizeof(int));
        *a = e;
        while((c = fgetc(p)) != EOF)
        {
                char *b;
                b = malloc(10*sizeof(char));
                int i=0;
                while(c != '\n')
                {
                        *(b+i) = c;
                        i++;
                        c = fgetc(p);
                }
                *(a+j) = atoi(b);
                j++;
        }
        return a;
}
void print(int *a,int n)
{
	int i;
	for(i=0;i<n;i++)
	printf("%d\n",*(a+i));
}
void swap(int *a,int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
int partition(int *a,int p,int r)
{
	int j;
	int x = *(a+r);
	int i = p-1;
	for(j=p;j<r;j++)
	{
		if(*(a+j) <= x)
		{
			i = i+1;
			swap((a+i),(a+j));
		}
	}
	swap((a+i+1),(a+r));
	return i+1;
	
	
}
void quick_sort(int *a,int p,int r)
{
	if(p<r)
	{
		int q = partition(a,p,r);
		quick_sort(a,p,q-1);
		quick_sort(a,q+1,r);
	}
}
void main()
{
	char *a;
	a = malloc(10*sizeof(char));
	printf("enter the file name\n");
	scanf("%s",a);
	FILE *p;
	p = fopen(a,"r+");
	if(p == NULL)
	{
		printf("invlaid file name\n");
		exit(1);
	}
	int *b;
	b = read(p);
	int n = *b;
	b++;
	clock_t start = clock();
	quick_sort(b,0,n-1);
	clock_t end = clock();
	print(b,n);
	double time = (end-start)/CLOCKS_PER_SEC;
	printf("running time %f \n",time);
}

