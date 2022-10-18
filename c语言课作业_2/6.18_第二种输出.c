#include<stdio.h>
int main(){
    int i,j;
    for ( i = 1; i < 20; i++)
    {
        if (i<10)
        {
           printf("%d   ",i);
        }else if (i==10)
        {
            printf("\n");
        }else
        {
           printf("_   ");
        }
    }
    printf("\n");
    for ( i = 1; i < 10; i++)
    {
        for ( j = 1; j <=i; j++)
        {
            if (i*j>=10)
            {
                printf("%d  ",i*j);
            }else{
                printf("%d   ",i*j);
            }         
        }
        printf("\n");
    }
    
}