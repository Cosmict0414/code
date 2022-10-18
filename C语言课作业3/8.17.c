#include<stdio.h>
 int cal(int num[],int n){
    int a;//进位多少
    int i;
    int j;
    for ( i = 1; i <=n; i++)
    {
        for ( j = 0; j <50; j++)
        {
            num[j]*=i;//每个数都乘以i
        }
        for ( j = 0; j < 50; j++)
        {
            if (num[j]<10)
            {
                continue;
            }else if(num[j]>=10)
            {
                a = (num[j]-(num[j]%10))/10;
                num[j+1]+=a;
                num[j] =  num[j] - a*10;
            }
        }
        
    }
    for ( j = 49; j >=0; j--)
    {
        printf("%d",num[j]);
    }
    printf("\n");
    return 0;
}
int main(){
    int num[50] = {0};
    int re[50] = {0};
    num[0] = 1;
    int i,j;
    for ( i = 1; i < 41; i++)
    {
        cal(num,i);
        for ( j = 0; j < 50; j++)
        {
            num[j] = 0;
        }
        num[0] = 1;
    }
    
}