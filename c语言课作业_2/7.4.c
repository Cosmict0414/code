#include<stdio.h>
int cal(int a,int b){
    int i;
    if (a>b)
    {
        for ( i = b; i <=a*b ; i++)
        {
            if (i%a==0&&i%b==0) break; 
        }
        
    }else{
        for ( i = a; i <=a*b; i++)
        {
            if (i%a==0&&i%b==0) break;
        }  
    }
    return i;
}
int main(){
    int a,b;
    int result;
    printf("请输入两个正整数");
    scanf("%d %d",&a,&b);
    result = cal(a,b);
    printf("这两个数的最小公倍数为%d\n",result);
    return 0;
}