#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int * read(FILE *p)
{
        int j =1,i=0;
        int c;
        char *b;
        b = malloc(5*sizeof(char));
        while((c = fgetc(p)) != '\n')
        {
                *(b+i) = c;
                i++;
        }
        int e = atoi(b);
        //printf("%d\n",e);
        int *a = malloc(e*sizeof(int));
        *a = e; 
        while((c = fgetc(p)) != EOF)
        {
                char *b;
                b = malloc(5*sizeof(char));
                int i=0;
                while(c != '\n')
                {
                        *(b+i) = c;
                        i++;
                        c = fgetc(p); 
                }
                *(a+j) = atoi(b); 
                j++;
        }
        return a;
}
int binary(int *a,int num,int start,int stop)
{
	int mid = start+stop/2;
	if(stop < start)
	return -1;
	else
	if(*(a+mid) > num)
	binary(a,num,start,mid-1);
	else
	if(*(a+mid) < num)
	binary(a,num,mid+1,stop);
	else
	return mid;
}   
void main()
{
        char *b;
        b = malloc(10*sizeof(char));
	printf("enter file name\n");
        scanf("%s",b);
        FILE *a;
        int *d;
        a = fopen(b,"r");
	if(a == NULL)
	{
		printf("invalid file name\n");
		exit(1);
	}
        d = read(a);
        int n = *d;
        printf("%d\n",n);
        int ser = *(d+n+1);
        printf("%d\n",ser);
        d++;
	clock_t start = clock();
        int res = binary(d,ser,0,n-1);
        clock_t end = clock();
        printf("%d\n",res);
	double time = (end-start)/CLOCKS_PER_SEC;
        printf("the running time is : %f clocks\n",time);
}

