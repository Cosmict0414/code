#include<stdio.h>
int main(){
    int a[100][100]={0};
    int n;
    int raw,col,i,j;
    int b = 0,c = 0;
    printf("输入方阵行数");
    scanf("%d",&n);
    for ( raw = 0; raw < n; raw++)
{
        printf("请输入第%d行的数字",raw+1);
    for ( col = 0; col < n; col++)
    {
        scanf("%d",&a[raw][col]);
    }
    printf("\n");
    
}
    for ( i = 0; i < n; i++)
    {
        b+=a[i][i]; 
        c+= a[n-i-1][n-i-1];
    }
    printf("%d\t%d",b,c);
    return 0;
    
}