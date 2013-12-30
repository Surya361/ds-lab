#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void arrmul(int *a,int n)
{
   int temp = 0,i ;
   
   for(i=0;i < 100; i++)
   {
      int res = (temp + (n * (*(a+i))));
      *(a+i) = res % 10;
      temp = res/10;

   }
   
}
long ftrl(long n)
{  
   int j;
   if(n <= 1)
      return 1;
   else
   j = n  * ftrl(n-1);

return j;
}
long ftr(long n)
{
   long i,j = 1;
   for(i=2;i <= n;i++)
      j = j * i;
   return j;
}
void print(int *a)
{
   int i;
   for(i=0;i<=100;i++)
      printf("%d",*(a+100-i) );
}
void fa(int *a,int n)
{
   int i;
   for(i=1;i<=n;i++)
      arrmul(a,i);
}

void main()
{
   //int a;
   //scanf("%d",&a);
   int *b,n;
   b = calloc(100,sizeof(int));
   *b = 1;
   scanf("%d",&n);
   fa(b,n);
   print(b);

}