#include<stdio.h>
int a[10][10] = {0};
void swap(int *pa1,int *pa2){
    int temp;
    temp = *pa1;
    *pa1 = *pa2;
    *pa2 = temp;
}
void Transpose1(int b[][10],int n,int m){
    int i;
    int j;
    int *(pa)[10][10];
    for ( i = 0; i < 10; i++)
    {
        for ( j = 0; j < 10; j++)
        {
            pa[i][j] = &a[i][j];
        }
        
    }
    
    for (i = 0; i < m; i++)
    {
        for ( j = 0; j < n; j++)
        {
            printf("%d\t",*pa[j][i]);
        }
        printf("\n");
    }
}


int main(){
    int i,j;
    int flag = 1;
    int n;
    for ( i = 0; i < 3; i++)
    {
        for ( j = 0; j < 4; j++)
        {
            a[i][j] = flag;
            flag++;
        }    
    }
    for ( i = 0; i < 3; i++)
    {
        for ( j = 0; j < 4; j++)
        {
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }
    Transpose1(a,3,4);
    
}