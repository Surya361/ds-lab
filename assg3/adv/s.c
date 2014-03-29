#include<stdio.h>
#include<stdlib.h>

void main()
{
//	char *i;
//	i = malloc(30*sizeof(char));
//	scanf("%s",input);
	FILE *p;
	p = fopen("teja","rb");
	int *a;
	a = malloc(20*sizeof(int));
	int i=0,n = 1;
	while(n)
	{
		n = fread((a+i),sizeof(int),1,p);
		if(n != 0)
		printf("%d ",*(a+i));
		i++;
	}
}
