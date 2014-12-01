#include<stdio.h>
#include<stdlib.h>
void swap(int *a,int *b)
{
        int temp;
        temp = *a ;
        *a = *b;
        *b = temp;
}
void sort(int *a,int n)
{
        int i,j;
        for(i=0;i<n;i++)
        {
                for(j=i;j!=0;j--)
                {
                        if(*(a+j) < *(a+j-1))
                        swap((a+j-1),(a+j));
                        else
                        break;
                }
        }
}


void main()
{
	int deer;
	printf("enter the number of deer:");
	scanf("%d",&deer);
	int antler1[deer];
	int antler2[deer];
	int z;
	printf("enter antler1: ");
	for(z=0;z<deer;z++)
	{
		scanf("%d",&antler1[z]);
	}
	printf("enter antler2: ");
	for(z=0;z<deer;z++)
	scanf("%d",&antler2[z]);
	int can[1<<deer];
	for(z=0;z<(1<<deer);z++)
	can[z] = 0;
	int capacity;
	printf("enter capacity: ");
	scanf("%d",&capacity);
	int start;
	for(start = 0;start < (1<<deer);start++)
	{
		int temp = 0;
		int komm[32];
		for(z=0;z<deer;z++)
		{
			if(start & (1<<z))
			{
				komm[temp++] = antler1[z];
				komm[temp++] = antler2[z];
			}
		}
		sort(&komm[0],temp);
		can[start] = 1;
		for( z=0;z<temp;z=z+2)
		{
			if((komm[z+1] - komm[z]) > capacity)
			can[start] = 0;
		}
//		printf("%d",can[start]);
	}
	int max[1<<deer];
	for(z=0;z<(1<<deer);z++)
	max[z]=0;
	for(start=1;start< (1<<deer);start++)
	{
		for(z=start;z>0;z=((z-1) & start))
		{
			if(can[z] && (z==start || (max[start-z] > 0)))
			{
				if(max[start] > 1+max[start-z])
				max[start] = max[start];
				else
				max[start] = 1 + max[start-z];
			}
		}
	}
	int c = max[(1<<deer)-1];
	if(c > 0)
	printf("%d",(deer-c));
	else
	printf("-1\n");
	
	
	
}

