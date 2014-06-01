#include<stdio.h>
#include<stdlib.h>

typedef struct
{
	int data;
	int *next;
}list;

list * read(FILE *p)
{
	int n,i;
	fscanf(p,"%d",&n);
	list let[n];
	for(i=0;i<n;i++)
	{
		int temp;
		fscanf(p,"%d",&temp);
		let[i].data = temp;
		if(i != 0)
		let[i-1].next = &(let[i].data);
	}
	return &let[0];	
}

void main()
{
	char *a;
	a = malloc(20*sizeof(char));
	FILE *p;
	printf("enter file name\n");
	scanf("%s",a);
	p = fopen(a,"r+");
	if(p == NULL)
	{
		printf("file dosent exists\n");
		exit(1);
	}
	list *l;
	l = read(p);
	int j =0;
	while(((l+j)->next) != NULL)
	{
	//	printf("%d\n",j);
		printf("%d\n",(l+j)->data);
		j++;
	}
}
