#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
int getnumber(FILE *p)
{
	int i = 0;
	char *b;
	int c;
	 b = malloc(6*sizeof(char));
        while((c = fgetc(p)) != '\n')
        {
                *(b+i) = c;
                i++;
        }
        int n = atoi(b);
	return n;
}
char** read(FILE *p,int n)
{
	char **s;
	int j,c,i = 0;
	char *b;
	int f=0,d=0;
	s = malloc(n*sizeof(char *));
	for(j=0;j<n;j++)
	*(s+j) = malloc(10*sizeof(char));
	while ((c = fgetc(p)) != EOF)
	{
		while(c != '\n')
		{
			*(*(s+f)+d) = c;
			c = fgetc(p);
			d++;
		}
		*(*(s+f)+d) = '\0';
		d = 0;
		f++;
	}
	return s;
	
}
void print(char **a,int n)
{
	int i;
	for(i=0;i<n;i++)
	printf("%s\n",*(a+i));
}
void selection_sort(char **s,int n)
{
	char **a;
	//a = s;
	int i,j;
	for(j=0;j<n;j++)
	{
		int smallest = j;
		for(i=j;i<n;i++)
		{
			if((strcmp(*(s+smallest),*(s+i)) > 0))
			smallest = i;
		}
		//printf("%s\n",*(s+smallest));
		char *temp;
		temp = *(s+j);
		*(s+j) = *(s+smallest);
		*(s+smallest) = temp;
		//*s++;
		
	}
	//s = a;
//	print(s,n);
	
}
void main()
{
	char *a;
	a = malloc(7*sizeof(char));
	printf("enter the file name : \n");
	scanf("%s",a);
	FILE *p;
	p = fopen(a,"r+");
	if(p == NULL)
	{
		printf("invalid file name\n");
		exit(1);
	}
	int n = getnumber(p);
	char **zo;
	zo = read(p,n);
	clock_t start = clock();
	selection_sort(zo,n);
	clock_t end = clock();
	double time = (end-start)/CLOCKS_PER_SEC;
	print(zo,n);
	printf("running time is: %f",time);
	
}
