#include<stdio.h>
#include<stdlib.h>

void swap(char *b,char *a)
{
        char temp;
        temp = *b;
        *b = *a;
        *a = temp;
}

int length(char *a)
{
        int i=0;
        while(*(a+i) != '\0')
        i++;
        return i;
}


void reverse(char *a,int st, int n )
{
	if(st >= n)
	return;
	else
	swap(a+st,a+n);
	reverse(a,st+1,n-1);
}

void main()
{
	char *a;
	a = malloc(20*sizeof(int));
	printf("Enter the string\n");
	scanf("%s",a);
	int n = length(a);
	reverse(a,0,n-1);
	printf("%s\n",a);
}
