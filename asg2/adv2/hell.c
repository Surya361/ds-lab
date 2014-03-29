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
	
}
void main()
{
	printf("enter the name of the file to be created\n");
	char *a;
	a = malloc(10*sizeof(cahr));
	scanf("%s",a);
	generate_file(a);
}
