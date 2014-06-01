#include<stdio.h>
#include<stdlib.h>

struct node
{
	struct node *p;
	int key;
	struct node *left;
	struct node *right;
};

typedef struct node element;
typedef element *link;

int is_leaf(link a)
{
	return(((a->left)==NULL) &&((a->right) == NULL));
}
int read(FILE *p)
{
	int k;
	fscanf(p,"%d",&k);
	return k;
}
link tree_search(link x,int k)
{
	while(x != NULL && (x->key) != k)
	{
		if(k < (x->key))
		x = x->left;
		else
		x = x->right;
	}
	return x;
}
link find_min(link x)
{
	if(x == NULL)
	return x;
	while((x->left) != NULL)
	x = x->left;
	return x;
}

link find_max(link x)
{
	if(x == NULL)
	return x;
	while((x->right) != NULL)
	x = x->right;
	return x;
}
int successor(link t,int k)
{
	link x = tree_search(t,k);
	if(x == NULL)
	{
		printf("NOT FOUND\n");
		return 0;
	}
	if((x->right) != NULL)
	{
	 	link a = find_min((x->right));
		if(a == NULL)
		printf("NIL\n");
		else
		printf("%d\n",(a->key));
		return 0;
	}
	link y = x->p;
	while(y != NULL &&(x == (y->right)))
	{
		x = y;
		y = y->p;
	}
	if(y == NULL)
	printf("NIL\n");
	else
	printf("%d\n",(y->key));
	return 0;
	
}
int predecessor(link t,int k)
{
	link x = tree_search(t,k);
	if(x == NULL)
	{
		printf("NOT FOUND\n");
		return 0;
	}
	if((x->left) != NULL)
	{
		link a = find_max((x->left));
		if(a == NULL)
		printf("NIL\n");
		else
		printf("%d\n",(a->key));
		return 0;
	}
	link y = x->p;
	while(y != NULL && (x == (y->left)))
	{
		x = y;
		y = y->p;
	}
	if(y == NULL)
	printf("NIL\n");
	else
	printf("%d\n",(y->key));
	return 0;
}
int inorder(link x)
{
	if(x == NULL)
	{
		printf("NIL\n");
		return 0;
	}
	if((x->left) != NULL)
	inorder(x->left);
	printf("%d ",(x->key));
	if((x->right) != NULL)
	inorder(x->right);
	
}
int preorder(link x)
{
	if(x == NULL)
	{
		printf("NIL\n");
		return 0;
	}
	printf("%d ",(x->key));
	if((x->left) != NULL)
	preorder(x->left);
	if((x->right) != NULL)
	preorder(x->right);
}
int postorder(link x)
{
	if(x == NULL)
	{
		printf("NIL\n");
		return 0;
	}
	if((x->left) != NULL)
	postorder(x->left);
	if((x->right) != NULL)
	postorder(x->right);
	printf("%d ",(x->key));
}
link insert(link k,link a)
{
	link temp = k;
	link tem;
	if(k == NULL)
	return a;
	while(temp != NULL)
	{
		tem = temp;
		if((temp->key) < (a->key))
		temp = temp->right;
		else
		temp = temp->left;
	}
	(a->p) = tem;
	if((tem->key) < (a->key))
	tem->right = a;
	else
	tem->left = a;
	return k;
		
}
void transplant(link u,link v)
{
	if(u->p == NULL)
	u = v;
	else
	if(u == (u->p)->left)
		((u->p)->left) = v;
	else
		((u->p)->right) = v;
	if(v != NULL)
	v->p = u->p;
	
}
link delete(link k,link z)
{
	if(k == z && is_leaf(z))
	{
//		printf("entered special\n");
		return NULL;
	}

	if(z->left == NULL)
	{
		if(z == k)
		{
//			printf("s\n");
			k = (z->right);
			k->p = NULL;
			return k;
		}
		else
		transplant(z,z->right);
	}
	else
	if(z->right == NULL)
	{
		if(z == k)
		{
//			printf("y\n");
			k = (z->left);
			k->p = NULL;
			return k;
		}
		else
		transplant(z,z->right);
	}
	else
	{	
		link y = find_min(z->right);
		if(y->p != z)
		{
			transplant(y,y->right);
			y->right = z->right;
			(y->right)->p = y;
		}
		if(z->p == NULL)
		{
			k = y;
			k->p = NULL;
		}
		else
		transplant(z,y);
//		printf("%d\n",y->key);
		y->left = z->left;
		(y->left)->p = y;
	}
	return k;
//	printf("done\n");	
}
do_it(FILE *p)
{
	link tree = NULL;
	int mode = read(p);
	while(mode)
	{
		if(mode == 1)
		{
			int d = read(p);
			link k = malloc(sizeof(element));
			k->key = d;
			tree = insert(tree,k);
			printf("\n");
		}
		if(mode == 2)
		{
			int d = read(p);
			link k = tree_search(tree,d);
			if(k == NULL)
			printf("NOT FOUND\n");
			else
			printf("FOUND\n");
		}
		if(mode == 3)
		{
			link k = find_min(tree);
			if(k == NULL)
			printf("NIL\n");
			else
			printf("%d\n",(k->key));
		}
		if(mode == 4)
		{
			link k = find_max(tree);
			if(k == NULL)
			printf("NIL\n");
			else
			printf("%d\n",(k->key));
		}
		if(mode == 5)
		{
			int d = read(p);
			predecessor(tree,d);	
		}
		if(mode == 6)
		{
			int d = read(p);
			successor(tree,d);
		}
		if(mode == 7)
		{
			int d = read(p);
			link k = tree_search(tree,d);
			tree = delete(tree,k);
			printf("\n");
		}
		if(mode == 8)
		{
			inorder(tree);
			printf("\n");
		}
		if(mode == 9)
		{
			preorder(tree);
			printf("\n");
		}
		if(mode == 10)
		{
			postorder(tree);
			printf("\n");
		}
//		printf("---------\n");
		mode = read(p);
	}
}
void main()
{
	char *a;
	printf("enter file name: ");
	a = malloc(30*sizeof(char));
	scanf("%s",a);
	FILE *p;
	p = fopen(a,"r+");
	do_it(p);
}
