#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int **  sub(int or,int i, int mat[or][or])
{
	int b[or-1][or-1];
	int p ,q;
	for(p=1;p<or;p++)
	{
		for(q=0;q<or;q++)
		{
			while(q != i )
			{
				if(q < i)
				b[p-1][q] = mat[p][q];
				else
				b[p-1][q-1] = mat[p][q];
			}
		}
	}
return b;
}

int determin(int or, int mat[or][or])
{
	int rest = 0;
	if(or == 2)
	return (mat[0][0] * mat[1][1]) - (mat[0][1] * mat[1][0]);
	else
	{	int i;
		for(i=0;i<or;i++)
		{
			rest = rest + pow(-1,i) * (mat[0][i]) * determin(or-1, sub(or,i,mat));
		}
	}
	return rest;
}

void main()
{
	int or;
	printf("enter the order\n");
	scanf("%d",&or);
	int ma[or][or];
	int i,j;
	for(i=0;i<or;i++)
	{
		for(j=0;j<or;j++)
		{
			printf("enter element %d%d\n",i,j);
			scanf("%d",&ma[i][j]);
		}
	}
	//int res = determin(or,ma);
	//printf("the determinant is %d\n",res);
}
