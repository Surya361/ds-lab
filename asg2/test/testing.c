#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void main()
{
	int a,b;
	FILE *f;
	f = fopen("input.txt","r+");
	fscanf(f,"%x",&a);
	fscanf(f,"%x",&a);
	printf("%d",a);
}
