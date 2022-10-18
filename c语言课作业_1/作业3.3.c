#include<stdio.h>
int main(){
    double rate = 0.0225;
    int n,i;
    int deposit,capital=100;
    printf("请输入你的存款年数");
    scanf("%d",&n);
    for ( i = 0; i < n; i++)
    {   
        capital=capital+capital*rate;
        deposit=capital;
    }
    printf("%d\n",deposit);
}