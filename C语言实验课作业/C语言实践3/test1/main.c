#include <stdio.h>
#include <stdlib.h>
int judge(int n){
    int i;
    int flag = 0;
    for(i=2; i<=n/2; ++i)
    {
        // 符合该条件不是素数
        if(n%i==0)
        {
            flag=1;
            break;
        }
    }
    if (flag==0)
        return n;
    else
        return 0;
    }
int sum(int *c,int len){
    int i,sum = 0;
    for(i = 0;i<len;i++){
        sum += judge(*(c+i));
    }
    return sum;
}
int main()
{
    int i,j,num;
    scanf("%d",&num);
    int b[100]; 
    for(i = 0;i<num;i++)
        {
        int len = 0;
        scanf("%d",&len);
        int a[len];
        int *c = a;
        printf("input arr");
        for(j = 0;j<len;j++){
        scanf("%d",&a[j]);
        }
        *(b+i) = sum(c,len);
    }
    printf("%d %d %d \n",b[0],b[1],b[2]);
}
