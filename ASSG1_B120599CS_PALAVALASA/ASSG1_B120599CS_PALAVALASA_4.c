#include<stdio.h>
#include<stdlib.h>

char * concat(char *a,char*b)
{
	while(*a)
	++a;
	while(*a++ = *b++ );
	return a;

}
void read(char *a)
{
        scanf("%s",a);

}
void print(char *a)
{
	while(*a)
	{
		printf("%c",*a);
		a++;
	}
}

void main()
{
	char *a,*b;
	a = malloc(200*sizeof(char));
	b = malloc(100*sizeof(char));
	printf("Enter first string :");
	read(a);
	printf("Enter second string :");
	read(b);
	concat(a,b);
	printf("Concatenated String : ");
	print(a);
	printf("\n");
}

