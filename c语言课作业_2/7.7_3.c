#include<stdio.h>
int gcd(int a,int b){
    int result;
    if (a<b)
    {   b=b-a;
        result = gcd(a,b);
    }else if(a>b){
        a = a-b;
        result = gcd(a,b);
    }else{
        result = a=b;
    }
    return result;
}
int main(){
    int a,b;
    int result;
    printf("请输入两个正整数");
    scanf("%d %d",&a,&b);
    result = gcd(a,b);
    printf("这两个正整数的最大公约数为%d\n",result);
    return 0;
}