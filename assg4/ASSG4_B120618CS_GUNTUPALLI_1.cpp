#include<iostream>
#include<fstream>
#include<stdlib.h>
using namespace std;
class root
{
	public:
		int key;
		root *left;
		root *right;
		root *parent;
};
int flag1 = 1;
int flag2 = 1;
root *rooot = NULL;
class bst
{
	public:
		void preorder(root*);
		void inorder(root*);
		void postorder(root*);
		root* search(root*,int);
		void insert(root*,root*);
		root* findmin(root*);
		root* findmax(root*);
		root* predecessor(root*,int);
		root* successor(root*,int);
		void del(root*,root*);
		void transplant(root*,root*,root*);
		void print(root*);
};
void bst:: preorder(root *x)
{
	if(x == NULL)
		return;
	else
	{
		cout<<x->key<<" ";
		preorder(x->left);
		preorder(x->right);
	}
}
void bst:: inorder(root *x)
{
	if(x==NULL)
		return;
	else
	{
		inorder(x->left);
		cout<<x->key<<" ";
		inorder(x->right);
	}
}
void bst:: postorder(root *x)
{
	if(x==NULL)
		return;
	else
	{
		postorder(x->left);
		postorder(x->right);
		cout<<x->key<<" ";
	}
}
root* bst:: findmax(root *x)
{
	if((x==NULL)||(x->right==NULL))
		return x;
	else
	{
		while(x->right!=NULL)
			x = x->right;
		return x;
	}
}
root* bst:: findmin(root *x)
{
	if((x==NULL)||(x->left==NULL))
		return x;
	else
	{
		while(x->left!=NULL)
			x = x->left;
		return x;
	}
}
root* bst:: search(root* x,int k)
{
	if((x==NULL)||(x->key==k))
		return x;
	else
	{
		if(k<(x->key))
			return(search(x->left,k));
		else
			return(search(x->right,k));
	}
}
root* bst:: successor(root *z,int k)
{
	root *x = search(z,k);
	root *y;
	if(x==NULL)
	{
		cout<<"Not Found"<<endl;
		flag1 = 0;
		return x;
	}
	if(x->right!=NULL)
		return (findmin(x->right));
	else
	{
		y = x->parent;
		while((y!=NULL)&&(y->right==x))
		{
			x=y;
			y=y->parent;
		}
		return y;
	}
}
root* bst:: predecessor(root *z,int k)
{
	root *x = search(z,k);
	root *y;
	if(x==NULL)
	{
		cout<<"Not Found"<<endl;
		flag2 = 0;
		return x;
	}
	if(x->left!=NULL)
		return (findmax(x->left));
	else
	{
		y = x->parent;
		while((y!=NULL)&&(y->left == x))
		{
			x=y;
			y=y->parent;
		}
		return y;
	}
}
void bst:: insert(root *t, root *i)
{
	root *y, *x;
	y = new root;
	x = new root;
	y= NULL;
	x = t;
	while(x != NULL)
	{
		y=x;
		if(i->key < x->key)
			x = x->left;
		else
			x =x->right;
	}
	i->parent = y;
	if(y==NULL)
		t = i;
	else if(y->key>i->key)
		y->left = i;
	else if(y->key<i->key)
		y->right = i;
    else
        return ;
}
void bst:: transplant(root *t,root *u,root *v)
{
    if(u->parent == NULL)
    {
        rooot = v;
        if(v!= NULL)
            rooot->parent = NULL;
        else
            rooot = NULL;
    }
    else if(u == u->parent->left)
        u->parent->left = v;
    else
        u->parent->right = v;
    if(v!=NULL)
        v->parent = u->parent;
}
void bst:: del(root *x,root* y)
{
	root *m,*n;
	m = y;
	if(y->left == NULL)
        transplant(x,y,y->right);
    else if(y->right == NULL)
        transplant(x,y,y->left);
    else
    {
        n = findmin(y->right);
        if(n->parent != y)
        {
            transplant(x,n,n->right);
            n->right = y->right;
            n->right->parent = n;
        }
        transplant(x,y,n);
        n->left = y->left;
        n->left->parent = n;
    }
}
void bst:: print(root *x)
{
	cout<<x->key<<endl;
}
int main()
{
	char s[20];
	int n,size,p,i = 0;;
	cout<<"Enter the filename"<<endl;
	cin>>s;
	bst b;
	fstream myfile;
	myfile.open(s,ios::in);
	if(myfile.is_open ())
	{
		while(1)
		{
			myfile>>n;
			if(n==0)
                break;
			if(n==1)
            		{
				myfile>>n;
				root *re = new root;
				re->key = n;
				re->left = NULL;
				re->right = NULL;
				re->parent = NULL;
				if(rooot==NULL)
				{
					rooot = re;
				}
				else
					b.insert(rooot,re);
                cout<<endl;
			}
			if(n==2)
			{
				myfile>>n;
				root *j = b.search(rooot,n);
				if(j)
					cout<<"Found"<<endl;
				else
					cout<<"Not Found"<<endl;
			}
			if(n==3)
			{
				root *j = b.findmin(rooot);
				if(j)
					b.print(j);
				else
					cout<<"Nil"<<endl;
			}
			if(n==4)
			{
				root *j = b.findmax(rooot);
				if(j)
					b.print(j);
				else
					cout<<"Nil"<<endl;
			}
			if(n==5)
			{
				myfile>>n;
				root *j = b.predecessor(rooot,n);
				if(j!=NULL)
					b.print(j);
				if(flag2&&(j==NULL))
					cout<<"Nil"<<endl;
				if(flag2==0)
					flag2=1;
			}
			if(n==6)
			{
				myfile>>n;
				root *j = b.successor(rooot,n);
				if(j)
					b.print(j);
				if(flag1&&(j==NULL))
					cout<<"Nil"<<endl;
				if(flag1==0)
					flag1=1;
			}
			if(n==7)
			{
				myfile>>n;
                root *j = b.search(rooot,n);
				b.del(rooot,j);
			}
			if(n==8)
			{
				b.inorder(rooot);
				cout<<endl;
			}
			if(n==9)
			{
				b.preorder(rooot);
				cout<<endl;
			}
			if(n==10)
			{
				b.postorder(rooot);
				cout<<endl;
			}
		}
	}
}

