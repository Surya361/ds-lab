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
char** read(FILE *p)
{
	char **s;
	int j,c,i = 0;
	char *b;
	int f=0,d=0;
	s = malloc(100000*sizeof(char *));
	for(j=0;j<100000;j++)
	*(s+j) = malloc(7*sizeof(char));
	char **q;
	q = s;
	*s++;
	while ((c = fgetc(p)) != EOF)
	{
		while(c != '\n' && c != ' ')
		{
			if(d > 6)
			{
				printf("invalid input length\n");
				exit(1);
			}
			*(*(s+f)+d) = c;
			c = fgetc(p);
			d++;
		}
		*(*(s+f)+d) = '\0';
		d = 0;
		f++;
	}
	**q = f;
	return q;
	
}
void print(char **a,int n)
{
	int i;
	for(i=0;i<n;i++)
	printf("%s\n",*(a+i));
}
void selection_sort(char **s,int n,int sm)
{
	char **a;
	//a = s;
	int i,j;
	for(j=0;j<sm;j++)
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
	printf("%s\n",*(s+sm-1));
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
	int sm = getnumber(p);
	printf("%d\n",sm);
	char **zo;
	zo = read(p);
	int n = **zo;
	printf("%d\n",n);
	*zo++;
	selection_sort(zo,n,sm);
	
}
