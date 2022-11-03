#include <stdio.h>
#include <stdlib.h>
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
    int n;
    int i;
    int a[10];
    int result;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++){
        printf("%d\n",pell(a[i])%32767);
    }
    return 0;
}
