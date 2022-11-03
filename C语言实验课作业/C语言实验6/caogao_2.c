#include <stdio.h>
int main()
{
    int a[6][6],i,j,m,n,sum;
    printf("Enter m,n:");
    scanf("%d,%d",&m,&n);
    printf("Enter array:\n");
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)   
            scanf("%d",&a[i][j]);
    sum=0;     
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++){
            sum=sum+a[i][j];
        }
        printf("sum of row %d is %d\n",i,sum);
        sum = 0;
    }
    return 0;
}
