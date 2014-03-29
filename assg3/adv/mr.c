#include<stdio.h>
#include<stdlib.h>
void print(link);
struct node
{
	//struct node *prev;
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
		//head->prev = NULL;
		head->next = NULL;
		n = fread(&i,sizeof(int),1,p);
	}
	temp = head;
	while(n)
	{
		temp->next = malloc(sizeof(element));
		//(temp->next)->prev = temp;
		(temp->next)->data = i;
		temp = temp->next;
		temp->next = NULL;
		n = fread(&i,sizeof(int),1,p);
	}
	temp->next = head;
	//head->prev = temp;
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
//	link tempae = tempa->prev;
//	printf("  %d\n",(tempb->prev)->data);
//	link tempbe = tempb->prev;
//	(tempa->prev)->next = NULL;
//	tempa->prev = NULL;
//	(tempb->prev)->next = NULL;
  //      tempb->prev = NULL;
//	printf("---- %d---------",(tempb->data));
	while(tempa->next != a && tempb->next != b)
	{
		printf("entered while\n");
		temp = tempa->next;
		tempa->next = tempb;
		tempb = tempb->next;
		//if(tempb != NULL)
		//tempb->prev = NULL;
		//(tempa->next)->prev = tempa;
		tempa = tempa->next;
		tempa->next = temp;
		if(tempa->next != NULL)
		tempa = tempa->next;

	}
	if(tempa->next == a && tempb->next != b)
	{
		printf("entered cond1\n");
		tempa->next = tempb;
		printf("removed chain\n");
		tempa = temp->next;
		printf("%d\n",(tempa->next)->data);
		//(tempa->next)->prev = tempa;
		link t;
		t = tempa;
		while(t->next != b)
		{
			printf("entered cond1 while\n");	
			t = t->next;
		}
		t->next = a;
	}
	if(tempa->next != a && tempb->next == b)
	{
		 printf("entered cond2\n");
		link t = tempa->next;
		tempa->next = tempb;
		temp->next = t;
	}
	if(tempa->next == a && tempb->next == b)
	{
		 printf("entered cond3\n");
		tempa->next = tempb;
		tempb->next = a;
	}
	print(a);
	return a;
}

void print(link a)
{
	link temp;
	temp = a;
	if(a == NULL)
	printf("empty\n");
	else
	{
		while(temp->next != a)
		{
			printf("%d\n",temp->data);
			temp = temp->next;
		}
		printf("%d\n",temp->data);		
	}
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
	printf("enter file1 name: ");
	scanf("%s",input1);
	printf("enter file2 name: ");
	scanf("%s",input2);
	printf("enter the output file name : ");
	scanf("%s",res);
	printf("------------------------------------------\n");
	link head = make(input1);
	print(head);
	link tail = make(input2);
	printf("------------------------------------------\n");
	print(tail);
	head = mg(head,tail);
	printf("------------------------------------------\n");
	print(head);
	create("thirdstring.temp",head);
	link vis = make("thirdstring.temp");
	cre("thirdstring.temp",res);
	
}
