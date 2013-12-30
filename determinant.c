#include<stdio.h>
#include<stdlib.h>
int order;
printf("enter the oder of the matrix\n");
scanf("%d",&order);

int *[(sizetype)(order)]  sub(int order,int a[order][order],  int r)
{
	int b[order-1][order-1];
	int i,j,p,q;
	for(p=0;p<order;p++)
		for(q=0;q<order;q++)
	{
		if(p != r && q!= r)
		{		
			for(i=0;i<order-1;i++)
			for(j=0;j<order-1;j++)
				b[i][j] = a[p][q];
	}
	return b;
}

}
int determinant(int order,int a[order][order] )
{	
	int j=0;
	if(order == 2)
	{
		return (a[0][0] * a[1][1]) - (a[0][1] * a[1][0]);
	}
	else
		{
			int i;
			for(i=0;i<order;i++)
			{
				j = j + a[0][i] *[determinant(sub(a,order,i),order-1);
			}
		}
		return j;
}
void main()
{
	int i,j;
	int m[order][order];
	printf("enter the values");
	for(i=0;i<order;i++)
	for(j=0;j<order;j++)
	{
		printf("enter the value of %d%d :",i,j);
		scanf("%d",&m[i][j]);
	}

	int det = determinant(order,m);
}