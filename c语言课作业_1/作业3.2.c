#include<stdio.h>
int main(){
    int n,a,b,c;
    scanf("%d",&n);
    a=(n-(n%100))/100;
    b=(n-a*100-((b-a*100)%10))/10;
    c=n-a*100-b*10;
    printf("%d%d%d\n",c,b,a);
}