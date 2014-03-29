#include<stdio.h>
#include<stdlib.h>
#include<time.h>

float * read(FILE *p)
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
        float *a = malloc(e*sizeof(float));
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
                *(a+j) = atof(b);
                j++;
        }
        return a;
}
void swap(float *a,float *b)
{
	float temp;
	temp = *a ;
	*a = *b;
	*b = temp;
}
void print(float *a,int n)
{
        int i;
        for(i=0;i<n;i++)
        printf("%f\n",*(a+i));
}

void insert_sort(float *a,int n)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=i;j!=0;j--)
		{
			if(*(a+j) < *(a+j-1))
			swap((a+j-1),(a+j));
			else
			break;
		}
	}
}

void main()
{
	char *a;
	a = malloc(10*sizeof(char));
	printf("enter the fle name\n");
	scanf("%s",a);
	FILE *p;
	p = fopen(a,"r+");
	if(p == NULL)
	{
		printf("invvalid file name\n");
		exit(1);
	}
	float *b;
	b = read(p);
	fclose(p);
	int n = *b;
	b++;
	clock_t start = clock();
	insert_sort(b,n);
	print(b,n);
	clock_t end = clock();
	double time = (end-start)/CLOCKS_PER_SEC;
	printf("running time is: %f ",time);
}
