#include <stdio.h>
#define size 50000
 
int main (void){
    long unsigned int n=0,k,t;
    char buff[size];
    unsigned int divisible=0;
    int block_read=0;
    int j;
    t=0;
    scanf("%lu %lu\n",&t,&k);
    printf("%lu\n",t );
    while(t){
        block_read =fread(buff,1,size,stdin);
        for(j=0;j<block_read;j++){
            if(buff[j]=='\n'){
                t--;
                if(n%k==0){
                divisible++;
                }
                n=0;
            }
 
            else{
                n = n*10 + (buff[j] - '0');
            }
        }
    }
    printf("%d",divisible);
    return 0;
}