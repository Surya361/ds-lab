#include<stdio.h>
#include<stdlib.h>
int *a ;
int n =10;


void ente()
{
	a = malloc(n*sizeof(int));
	int i;
	for(i=0;i<10;i++)
	  {  *(a+i) = i;
	  }
	  printf("%ld\n",sizeof(a));
}
/*int peak(int *b, int n)
{
	int n = n-1;
if(*(n/2) < *(n/2 - 1))
	peak(sub (b,0,(n/2 - 1)));
else
	if(*(n/2) < *(n/2 + 1))
		peak(sub(b,(n/2+1),n));
	else
		return n/2;
}
int* sub(int *e,int start,int stop)
{

}*/
void main()
{
ente();
int i;
printf("%ld\n",sizeof(a));
printf("%ld\n",sizeof(int));

}