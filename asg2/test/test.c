#include<stdio.h>
#include<stdlib.h>
void swap(char *a,char *b)
{
	char *temp;
	temp = a;
	a = b;
	b = temp;
}
void main()
{
	int i;
	char **a;
	a = malloc(2*sizeof(char *));
	for(i=0;i<2;i++)
	*(a+i) = malloc(10*sizeof(char));
	*(a) = "hello";
	*(a+1) = "world";
	//swap(*(a),*(a+1));
	char *temp;
//	char *temp1
//	temp1 = *(a+1)
	temp = *a;
	*a = *(a+1);
	*(a+1) = temp;
	printf("%s\n",*(a));
	printf("%s\n",*(a+1));
}
