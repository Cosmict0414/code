#include<stdio.h>
int main(){
    int a = 1;
    int n;
    int i;
    printf("Input a number");
    scanf("%d",&n);
    for ( i = 1; i <=n; i++)
    {
        a*=i;
    }
    printf("%d\n",a);
}