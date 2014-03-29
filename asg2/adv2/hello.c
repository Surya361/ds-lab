#include<stdio.h>
#include<stdlib.h>
void generate_file(char *a)
{
	FILE *p;
	p = fopen(a,"w");
	int i,j;
	for(i=0;i<64;i++)
	for(j=0;j<1024;j++)
	for(k=0;k<1024;k++)
	{
		int k = rand();
		fprintf(p,"%d",)
	}
	fclose()
	
}
void swap(long *a,long *b)
{
        long temp;
        temp = *a;
        *a = *b;
        *b = temp;
}
long partition(long *a,long p,long r)
{
        long j;
        long x = *(a+r);
        long i = p-1;
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
void quick_sort(long *a,int p,int r)
{
        if(p<r)
        {
                long q = partition(a,p,r);
                quick_sort(a,p,q-1);
                quick_sort(a,q+1,r);
        }
}
char * gen_filename(long l,long i)
{
	char b[10];
	
	
}

void part_64(char *a)
{
	long *l;
	FILE *p;
	p = fopen(a,"r+");
	long i, c = 1024*1024;
	l = malloc(c*sizeof(long));
	for(i=0;i<c;i++)
	fscanf(p,"%l",*(l+i));
	quick_sort(l,0,c-1);
	for(i=0;i<c;i++)
	
}
void main()
{
	printf("enter the name of the file to be created\n");
	char *a;
	a = malloc(10*sizeof(cahr));
	scanf("%s",a);
	generate_file(a);
	part_64(a);	
}
