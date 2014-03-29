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
void merge(int *b,int p,int q,int r)
{
	int i,j,k;
	int n1 = q-p+1;
	int n2 = r-q;
	int *ne1 = malloc(n1*sizeof(int));
	int *ne2 = malloc(n2*sizeof(int));
	for(i=0;i<n1;i++)
	*(ne1+i) = *(b+p+i);
	for(i=0;i<n2;i++)
	*(ne2+i) = *(b+q+i+1);
	i=0;
	j=0;
	for(k=p;k<=r;k++)
	{
		if(i == n1)
		{
			while(j != n2)
			{
				*(b+k) = *(ne2+j);
				j++;
				k++;
			}
			break;
		}
		if(j == n2)
		{
			while(i != n1)
			{
				*(b+k) = *(ne1+i);
				i++;
				k++;
			}
			break;
		}
		//printf("comparing %d %d\n",*(ne1+i),*(ne2+i));
		
		if (*(ne1+i) <= *(ne2+j))
		{
			*(b+k) = *(ne1+i);
			//printf("in loop1 %d\n",*(b+k));
			i++;
		}
		else
		{
			*(b+k) = *(ne2+j);
			 //printf("%d\n",*(b+k));
			j++;
		}
	}

	
}
void merge_sort(int *b,int p,int r)
{
	if(p<r)
	{
		int q = (p+r)/2;
		merge_sort(b,p,q);
		merge_sort(b,q+1,r);
		merge(b,p,q,r);
	}
}
void print(int *a,int n)
{
	int i;
	for(i=0;i<n;i++)
	printf("%d\n",*(a+i));
}

void main()
{
	char *a;
	a = malloc(10*sizeof(char));
	printf("enter the input file name\n");
	scanf("%s",a);
	FILE *p;
	p = fopen(a,"r+");
	if(p == NULL)
	{
		printf("invalid file name\n");
		exit(1);
	}
	int *b = read(p);
	int n = *b;
	b++;
	clock_t start = clock();
	merge_sort(b,0,n-1);
	print(b,n);
	clock_t end = clock();
	double time = (end-start)/CLOCKS_PER_SEC;
	printf("running time %f\n",time);
}
