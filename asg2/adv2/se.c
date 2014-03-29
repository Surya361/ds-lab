#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
int getnumber(FILE *p)
{
	int i = 0;
	char *b;
	int c;
	 b = malloc(6*sizeof(char));
        while((c = fgetc(p)) != '\n')
        {
                *(b+i) = c;
                i++;
        }
        int n = atoi(b);
	return n;
}
void print(char **a,int n)
{
        int i;
        for(i=0;i<n;i++)
        printf("%s\n",*(a+i));
}

char** read(FILE *p)
{
	char **s;
	int j,c,i = 0;
	char *b;
	int f=0,d=0;
	s = malloc(100000*sizeof(char *));
	for(j=0;j<100000;j++)
	*(s+j) = malloc(7*sizeof(char));
	char **q;
	q = s;
	*s++;
	while ((c = fgetc(p)) != EOF)
	{
		while(c != '\n' && c != ' ')
		{
			if(d > 6)
			{
				printf("invalid input length\n");
				exit(1);
			}
			*(*(s+f)+d) = c;
			c = fgetc(p);
			d++;
		}
		*(*(s+f)+d) = '\0';
		d = 0;
		f++;
	}
	**q = f;
	return q;
	
}
int partition(char **a,int p,int r)
{
        int j;
        char *x = *(a+r);
        int i = p-1;
        for(j=p;j<r;j++)
        {
                //if(*(a+j) <= x)
		if((strcmp(*(a+j),x) >= 0))
                {
                        i = i+1;
			char *temp;
			temp = *(a+i);
			*(a+i) = *(a+j);
			*(a+j) = temp;
                  //      swap((a+i),(a+j));
                }
        }
      //  swap((a+i+1),(a+r));
	char *temp;
	temp = *(a+i);
	*(a+i) = *(a+r);
	*(a+r) = temp;
        return i+1;


}
char* randomized(char **a,int p,int r,int i)
{
        if(p == r)
        return *(a+p);
        //int q = partition(a,p,r);
	int j1;
	char *x1; 
	x1 = *(a+r);
	int i1 = p-1;
	for(j1=p;j1<r;j1++)
	{
		printf("%s\n",*(a+j1));
		printf("%s\n",x1);
		printf("%d\n",strcmp(*(a+j1),x1));
		if(strcmp(*(a+j1),x1) <= 0)
		{
			i1 = i1 + 1;
			char *temp;
			temp = *(a+i1);
			*(a+i1) = *(a+j1);
			*(a+j1) = temp;
		//	print(a,5);
			
		}
		print(a,5);
		printf("\n");
	}
	char *temp;
	temp = *(a+i1+1);
	*(a+i1+1) = *(a+r);
	*(a+r) = temp;
	int q = i1+1;
	print(a,5);
	printf("%d\n",q);
//	print(a,5);
        int k = q-p+1;
        if(i == k)
        return *(a+q);
        else
        if(i<k)
        return randomized(a,p,q-1,i);
        else
        return randomized(a,q+1,r,i-k);
}

void selection_sort(char **s,int n,int sm)
{
	char **a;
	//a = s;
	int i,j;
	for(j=0;j<sm;j++)
	{
		int smallest = j;
		for(i=j;i<n;i++)
		{
			if((strcmp(*(s+smallest),*(s+i)) > 0))
			smallest = i;
		}
		//printf("%s\n",*(s+smallest));
		char *temp;
		temp = *(s+j);
		*(s+j) = *(s+smallest);
		*(s+smallest) = temp;
		//*s++;
		
	}
	printf("%s\n",*(s+sm-1));
	//s = a;
//	print(s,n);
	
}
void main()
{
	char *a;
	a = malloc(7*sizeof(char));
	printf("enter the file name : \n");
	scanf("%s",a);
	FILE *p;
	p = fopen(a,"r+");
	if(p == NULL)
	{
		printf("invalid file name\n");
		exit(1);
	}
	int sm = getnumber(p);
	printf("%d\n",sm);
	char **zo;
	zo = read(p);
	int n = **zo;
	printf("%d\n",n);
	*zo++;
//	selection_sort(zo,n,sm);
	char *ans;
	ans = malloc(10*sizeof(char));
	ans = randomized(zo,0,n-1,sm);
	printf("%s\n",ans);
	
}
