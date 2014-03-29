#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};
typedef struct node element;
typedef element *link;

link make(char *a)
{
	int i;
	FILE *p;
	p = fopen(a,"rb");
	link head,temp;
	int n = fread(&i,sizeof(int),1,p);
	if(n==0)
	{
		return NULL;
		fclose(p);
	}
	else
	{
		head = malloc(sizeof(element));
		head->data = i;
		head->next = NULL;
		n = fread(&i,sizeof(int),1,p);
	}
	temp = head;
	while(n)
	{
		temp->next = malloc(sizeof(element));
		(temp->next)->data = i;
		temp = temp->next;
		temp->next = NULL;
		n = fread(&i,sizeof(int),1,p);
	}
	temp->next = head;
	fclose(p);
	return head;
}
link mg(link a,link b)
{
	if(a == NULL)
	return b;
	if(b == NULL)
	return a;
	link tempa,tempb,temp;
	tempa = a;
	tempb = b;
	while(tempa->next != a && tempb->next != b)
	{
		temp = tempa->next;
		tempa->next = tempb;
		tempb = tempb->next;
		tempa = tempa->next;
		tempa->next = temp;
		if(tempa->next != NULL)
		tempa = tempa->next;

	}
	if(tempa->next == a && tempb->next != b)
	{
		tempa->next = tempb;
		tempa = temp->next;
		link t;
		t = tempa;
		while(t->next != b)
		t = t->next;
		t->next = a;
	}
	if(tempa->next != a && tempb->next == b)
	{
		link t = tempa->next;
		tempa->next = tempb;
		temp->next = t;
	}
	if(tempa->next == a && tempb->next == b)
	{
		tempa->next = tempb;
		tempb->next = a;
	}
	return a;
}

int create(char *a,link b)
{
	FILE *p;
	p = fopen(a,"wb");
	link temp;
	temp = b;
	int i;
	if(temp == NULL)
	{
		fclose(p);
		return 0;
	}
	while(temp != NULL && temp->next != b)
	{
		i = temp->data;	
		fwrite(&i,sizeof(int),1,p);
		temp = temp->next;
	}
	i = temp->data;
	fwrite(&i,sizeof(int),1,p);
	fclose(p);
}
void cre(char *a,char *d)
{
	FILE *b,*c;
	b = fopen(a,"rb");
	c = fopen(d,"w");
	int i,n =1;
	while(n)
	{
		n = fread(&i,sizeof(int),1,b);
		if(n != 0)
		fprintf(c,"%d\n",i);
	}
	fclose(b);
	fclose(c);
}
void main()
{
	char *input1,*input2,*res;
	input1 = malloc(30*sizeof(char));
	input2 = malloc(30*sizeof(char));
	res = malloc(30*sizeof(char));
	printf("enter input file name: ");
	scanf("%s",input1);
	printf("enter input file name: ");
	scanf("%s",input2);
	printf("output file name: ");
	scanf("%s",res);
	link head = make(input1);
	link tail = make(input2);
	head = mg(head,tail);
	create("thirdstring.temp",head);
	link vis = make("thirdstring.temp");
	cre("thirdstring.temp",res);
	
}
