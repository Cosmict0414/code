#include<stdio.h>
#include<stdlib.h>
void InputArray(int *p,int m ,int n){
    int i,j;
    for ( i = 0; i < m; i++)
    {
        for ( j = 0; j < n; j++)
        {
            printf("Input a number\n");
            scanf("%d",&p[i*n+j]);
        }
    }
}
int FindMax(int *p,int m,int n,int *prow,int *pcol){
    int max = p[0];
    int i,j;
    for ( i = 0; i < m; i++)
    {
        for ( j = 0; j < n; j++)
        {
            if (max<p[i*n+j])
            {
                max = p[i*n+j];
                *prow = i+1;
                *pcol = j+1;
            }
        }
    }
    return max;
}
int main(){
    int p[100] = {1};
    int m, n;
    int c,d;
    int *pRow = &c;
    int *pCol = &d;
    int max;
    printf("输入班级数和每班的人数\n");
    scanf("%d %d",&m,&n);
    InputArray(p,m,n);
    max = FindMax(p,m,n,pRow,pCol);
    printf("最高分为：%d,是第%d班的第%d同学\n",max,*pRow,*pCol);

}