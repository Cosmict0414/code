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

int main(){
    int a;
    a = judge(5);
    printf("%d\n",a);
}