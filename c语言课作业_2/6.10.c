#include<stdio.h>
#include<math.h>
int main(){
    int i,sxhs;
    int a,b,c;
    for ( i = 0; i < 1000; i++)
    {
        a=i-(i%100);
        a=a/100;
        b=i-a*100-(i%10);
        b=b/10;
        c=i-a*100-b*10;
        if (i==pow(a,3)+pow(b,3)+pow(c,3))
        {
            printf("%d  ",i);
        }
        
    }
    return 0;
}