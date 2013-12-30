#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int** sub(int **m,int ord,int i)
{
        int **b,j;
	b = malloc((ord-1)*sizeof(int *));
        for(j=0;j<ord-1;j++)
     {
        *(b+j) = malloc((ord-1)*sizeof(int));
	}
        int p,q;
        for(p=1;p<ord;p++)
        {
                for(q=0;q<ord;q++)
                {
                        
                        if(q != i)
                       {
                            if(q < i)
                        (*(*(b + p -1) + q)) = (*(*(m + p) + q));
                        else
                        (*(*(b + p -1) + q-1)) = (*(*(m + p) + q));
                         
                       }     
                        
                        
                }
        }
        return b; 
}

int deter(int **mat , int order)
{
        int rest = 0;
        if(order == 2)
        return ((**mat) * (*(*(mat+1)+1))) - ((*((*mat) + 1)) * (*(*(mat+1))));
        else
        {
                int i;
                for(i=0;i<order;i++)
                {
                        int a = pow(-1,i);
                        rest = rest + a * (*((*mat) + i)) * deter(sub(mat,order,i),order-1);
                }
        }
        return rest; 
}
void print(int **m,int a)
{
	int i,j;
	for(i=0;i<a;i++)
	{
		for(j=0;j<a;j++)
		printf("%d", (*(*(m + i) + j)));
	}
}

void main()
{
        printf("enter the order of determinant");
        int order;
        scanf("%d",&order);
        int **a,i,j;
        a = malloc(order*sizeof(int *));
        for(i=0;i<order;i++)
     {
        *(a+i) = malloc(order*sizeof(int));
        for(j=0;j<order;j++)
        {
                printf("enter the number %d%d ",i,j);
                scanf("%d", *(a+i) + j);
        }
     }
        int res = deter(a,order);
        printf("the determinant is %d",res);
    //int **b = sub(a,order,0);
    //print(b,(order-1));
}

