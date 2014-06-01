#include<stdio.h>
#include<stdlib.h>

void main()
{
	typedef struct 
	{
		int data;
		int *next;
	}sample;

	sample s1,s2,s3;
	s1.data = 1;
	s2.data = 2;
	s3.data = 3;
	s1.next = &(s2.data);
	s2.next = &(s3.data);
	s3.next = NULL;
	printf("%d\n",*(s2.next));	
}
