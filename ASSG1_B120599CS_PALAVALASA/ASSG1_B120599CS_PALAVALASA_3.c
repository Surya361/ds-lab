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

char* replace(char *a,char *b,char *c)
{
        int i ,j=0,k ;
	int len = length(a);
	char *d;
	d = malloc(1000*sizeof(char));
	char *wow = d;
        for(i=0;exist(c,len);)
        {
		int yes = 0;
                for(j=0;*(a+j) != '\0' && isalpha(*(c+len)) == 0;j++)
		{
			if(*(a+j) == *(c+i+j))
			yes = 1;
			else
			{
				yes =0;
				break;
			}
		}
		if(yes)
		{
			for(k=0; *(b+k) != '\0';k++)
			*(d+k) = *(b+k);
			c = c+len;
			d = d +length(b); 
		}
		else
		{
			while(isalpha(*c) && *(c+1) != '\0')
                        {
				*d++ = *c++;
			}
			while(isalpha(*c) == 0 && *(c+1) != '\0')
				*d++ = *c++;
		}
        }
	for(i=0;*c != '\0';)
	*d++ = *c++;
	return wow;
}
int length(char *a)
{
	int i=0;
	while(*(a+i) != '\0')
	i++;
	return i;
}
void print(char *a)
{
	int i=0;
	while(*(a+i) != '\0')
	printf("%c",*(a+i));
}
void main()
{
	FILE *a;
	char *b,*c,*e;
	b = malloc(20*sizeof(char));
	c = malloc(1000*sizeof(char));
	e = malloc(1000*sizeof(char));
	printf("Enter file name :");
	scanf("%s",b);
	a = fopen(b,"rw");
	fgets(c,1000,a);
	fclose(a);
	a = fopen(b,"w");
	char *find, *replac;
	find = malloc(10*sizeof(char));
	replac = malloc(10*sizeof(char));
	printf("Enter two strings : ");
	scanf("%s",find);
	scanf("%s",replac);
	e  = replace(find,replac,c);
	fprintf(a,"%s",e);
	fclose(a);
}
