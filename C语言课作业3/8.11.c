#include<stdio.h>
int main(){
    int i,j;
    int a[8][8] = {0};
    a[1][1] = 0;
    int count = 1;
    for (i = 1; i < 8; i++)
    {
        count ++;
        for ( j = 1; j < count; j++)
        {
            a[i][j] = a[i-1][j-1]+a[i-1][j];
            a[1][1] = 1;
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }
    
}