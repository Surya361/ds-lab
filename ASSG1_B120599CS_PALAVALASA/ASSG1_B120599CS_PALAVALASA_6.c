#include<stdio.h>
#include<stdlib.h>

void main()
{
	char c;
	printf("Enter the gender :");
	scanf("%c",&c);
	union details
	{
		int height;
		int age;
	};
	union details a;
	if(c == 'm' || c == 'M')
	{
		printf("Enter age : ");
		scanf("%d",&(a.age));
	}
	else
	if(c == 'f' || c == 'F')
	{
		printf("Enter height :");
		scanf("%d",&(a.height));
	}
	printf("Height = %d\n",a.height);
	printf("Age = %d\n",a.age);
}
