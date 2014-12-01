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
/*
int getmin(vector <int> antler1, vector <int> antler2, int capacity)
{
    int n = antler1.size();
    // Let us build the canCycle[subset] array, using bitmasks to generate the subsets:
    bool canCycle[1<<n];
    memset(canCycle, 0, sizeof(canCycle));
    for (int mask = 0; mask < (1<<n); mask++) {
        int t = 0;
        // Save the antlers of the moose in the set in an array.
        int ant[32];
        for (int i = 0; i < n; i++) {
            if (mask & (1<<i)) {
                ant[t++] = antler1[i];
                ant[t++] = antler2[i];
            }
        }
        // sort the natlers:
        sort(ant, ant + t);
        canCycle[mask] = true; //assume the set is valid
        for (int i = 0; i<t; i += 2) {
            if ( abs(ant[i] - ant[i+1]) > capacity ) {
                // These two consecutive antlers make an invalid match. If this
                // happens even when sorted, it is impossible to make a cycle
                // with this set of moose.
                canCycle[mask] = false;
            }
        }
    }
    
    // Dynamic programming to count the maximum number of components (since the components
    // will be cycles or loops, the maximum number of non-overlapping cycles:)
    int maxCycles[1<<n];
    // When a subset can't be split in valid cycles, maxCycles[i] will be 0.
    // Except for the empty subset, in which 0 is a valid result.
    memset(maxCycles, 0, sizeof(maxCycles));
    for (int mask = 1; mask < (1<<n); mask++) {
        for (int sub = mask; sub > 0; sub = ( (sub - 1) & mask ) ) {
            if (canCycle[sub] && ( (sub==mask) || (maxCycles[mask-sub] > 0) ) ) {
                maxCycles[mask] = std::max(maxCycles[mask], 1 + maxCycles[mask-sub]);
            }
        }
    }
    // The maximum number of components is c:
    int c = maxCycles[ (1<<n) - 1];
    return (c > 0) ? (n - c) : -1;
}*/
