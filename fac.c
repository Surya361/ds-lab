#include<stdio.h>
#include<stdlib.h>

int main()
{
	int c;
	char a[9];
	//a = malloc(9*sizeof(int));
	int d = fread(a,2,3,stdin);
	int i;
	for(i=0;i<9;i++)
		printf("%c\n", a[i] );
	
}
