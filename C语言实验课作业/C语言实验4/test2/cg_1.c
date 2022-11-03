#include<stdio.h>
int pell(n){
    int a[31];
    a[0] = 0;
    int i;
    int result;
    if(n==1){
        a[1]=1;
        result = a[1];
    }else if(n==2)
    {
        a[2] = 2;
        result = a[2];
    }
        else{

        result = pell(n-1)*2+pell(n-2);
    }
    return result;
}
int main()
{
    int result;
    result =pell(3);
    printf("%d",result);
    return 0;
}