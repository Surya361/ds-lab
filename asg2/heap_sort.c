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
int left(int i)
{
	return (2*(i+1)-1);
}
int right(int i)
{
	return (2*(i+1));
}
void swap(int *a,int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
void max_heapify(int *a,int i,int heap)
{
	int largest;
	int l = left(i);
	int r = right(i);
	if(r <= heap && *(a+r) > *(a+i))
		largest = r;
	else
		largest = i;
	if(l <= heap && *(a+l) > *(a+largest))
		largest = l;
	if(largest != i)
	{
		swap((a+i),(a+largest));
		max_heapify(a,largest,heap);
	}
}
void build_maxheap(int *a,int n)
{
	int i;
	for(i=n/2;i>=0;i--)
	max_heapify(a,i,n-1);
}
void print(int *a,int n)
{
	int i;
	for(i=0;i<n;i++)
	printf("%d\n",*(a+i));
}
int * heap_srt(int *a,int n)
{
	build_maxheap(a,n);
	int i, he = n-1;
	for(i=n-1;i>0;i--)
	{
		swap((a),(a+i));
		he = he -1;
		max_heapify(a,0,he);
	}
	return a;
}

void main()
{
	char *a;
	a = malloc(20*sizeof(char));
	printf("enter the input file name\n");
	scanf("%s",a);
	FILE *p;
	p = fopen(a,"r+");
	if(p == NULL)
	{
		printf("invalid file name\n");
		exit(1);
	}
	int *b;
	b = read(p);
	int n = *b;
	b++;
	clock_t start = clock();
	heap_srt(b,n);
	clock_t end = clock();
	print(b,n);
	double time = (end-start)/CLOCKS_PER_SEC;
	printf("running time %f\n",time);
}
