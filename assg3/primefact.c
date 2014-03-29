#include<stdio.h>
void main()
{
int a,b,c[30],i=0,j,k,f=0;
printf("enter the number\n");
scanf("%d",&a);
printf("the factors are:\n");
for(b=a;b>0;b--)
{
if(a%b==0)
{
c[i]=b;
i++;
printf("%d\n",c[i-1]);

}
}
}

/*for(j=0;j<=i-2;j++)
{
for(k=1;k<=i-1;k++)
{
 f=c[j]%c[k];
if(f==0)
break;
else
f=1;
}
if(f==1)
printf("%d\n",f);
}
}*/


