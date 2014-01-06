#include<stdio.h>
#include<stdlib.h>

void read(char **a)
{
	int c=1,i=0,j=0;
	while(c != '\n' && (c = getchar()) != '\n')
	{
		while(c  != ' ' && c != '\n')
		{
			*(*(a+i)+j) = c;
			//printf("%c",c);
			j++;
			c = getchar();
		}
		j=0;
		i++;
	}
}
int length(char *a)
{
	int i=0;
	while(*(a+i) != '\0')
	{
		i++;
	}
	return i;
}

int cmpr(char *a,char *b)
{
	int yes = 0;
	if(length(a) == length(b))
	{
		int i=0,j=0;
		while(i<length(a))
		{
			if(*(a+i) == *(b+i))
			yes = 1;
			else
			if(j<2)
			{
				j++;
				yes = 1;
			}
			else
			{
				yes = 0;
				break;
			}
			i++;
		}
	}
	else
	yes=0;
	
	return yes;
}
int len(char **a)
{
	int i=0;
	while(*(*(a+i)) != '\0')
	{
		i++;
	}
	return i;
}

void main()
{
	int i;
	char **a,**b;
	a = malloc(50*sizeof(char *));
	b = malloc(50*sizeof(char *));
	for(i=0;i<50;i++)
	{
		*(a+i) = malloc(8*sizeof(char));
		*(b+i) = malloc(8*sizeof(char));
	}
	read(a);
	read(b);
	if(len(a) == len(b))
	{
		int i,j;
		for(i=0;i<len(a);i++)
		printf("%d ",cmpr(*(a+i),*(b+i)));
	}
	else
	printf("input length dosent match\n");
	printf("\n");
	
}
