#include<stdio.h>
int main(){
    int a,b;
    int i;
    printf("请输入两个正整数");
    scanf("%d %d",&a,&b);
    if (a<b)
    {
        for ( i = a; i >0; i--)
        {
            if (a%i==0&&b%i==0) break;
            
        }
        
    }else{
        for ( i = b; i >0; i--)
        {
            if (a%i==0&&b%i==0) break;
        }
        
    }
    printf("这两个数的最小公因数是%d\n",i);

}