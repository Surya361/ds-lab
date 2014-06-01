#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
int exist(char *c,int n)
{
	int i;
	for(i=0;i<n && *(c+i) != '\0';i++);
	if(i == n)
	return 1;
	else
	return 0;
}
int length(char *a)
{
        int b = 0;
        while((*(a+b)) != '\0')
        ++b;

        return b;
}

int find(char *a,char *c)
{
        int i,j,k=0 ;
        int len = length(a);
        for(i=0;exist(c+i,len);)
        {
		int yes = 0;
		for(j=0;*(a+j) != '\0' && isalpha(*(c+len)) == 0 ;j++)
		{
                	if(*(a+j) == *(c+i+j))
                	{
				yes = 1;
			}
                	else
                	{
				yes = 0;
				break;
                	}

            	}
		if(yes)
		{
			c = c+len;
			i=0;
			k++;
		}
		else
		{
			while(isalpha(*c) && *(c+1) != '\0')
			c++;
			while(isalpha(*c) == 0 && *(c+i) != '\0')
			c++;
			i=0;
		}
        }
	return k;

}

void main()
{
        char *a,*c;
	printf("Enter the paragraph\n");
        c = malloc(5000*sizeof(char));
	int i;
	gets(c);
	printf("Enter the string to be searched\n");
	a = malloc(20*sizeof(char));
	gets(a);
	int b = find(a,c);
	printf("Number of occurrences : %d\n",b);
}

