#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int * read(FILE *p)
{
	int j =1,i=0;
	int c;
	char *b;
	b = malloc(5*sizeof(char));
	while((c = fgetc(p)) != '\n')
	{
		*(b+i) = c;
		i++;
	}
	int e = atoi(b);
	int *a = malloc(e*sizeof(int));
	*a = e; 
	while((c = fgetc(p)) != EOF)
	{
		char *b;
		b = malloc(5*sizeof(char));
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
int linear(int *a,int num,int len)
{
	int i;
	for(i=0;i<len;i++)
	{
		if(*(a+i) == num)
		return i;
	}
	return -1;
}

void main()
{
	clock_t start = clock();
	char *b;
	b = malloc(10*sizeof(char));
	printf("enter the file name\n");
	scanf("%s",b);
	FILE *a;
	int *d;
	a = fopen(b,"r");
	if(a == NULL)
	{
		printf("invalid file name\n");
		exit(1);
	}
	d = read(a);
	int n = *d;
	//printf("%d\n",n);
	int ser = *(d+n+1);
	//printf("%d\n",ser);
	d++;
	int res = linear(d,ser,n);
	clock_t end = clock();
	double time = (end-start)/CLOCKS_PER_SEC;
	printf("%d\n",res);
	printf("the running time is : %f clocks\n",time);
}

