#include<stdio.h>
#include<stdlib.h>

void main()
{
	char *input;
	input = malloc(30*sizeof(char));
	printf("enter the file to be created: ");
	scanf("%s",input);
	FILE *p;
	p = fopen(input,"wb");
	printf("enter the number of elements in the file: ");
	int num;
	scanf("%d",&num);
	int i,j;
	for(i=0;i<num;i++)
	{
		scanf("%d",&j);
		fwrite(&j,sizeof(int),1,p);
	}
	fclose(p);
}
