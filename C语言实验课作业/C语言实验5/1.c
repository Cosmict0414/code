#include<stdio.h>
#include<stdlib.h>
int main(){
    int num = 0;
    int a[100] = {0};
    scanf("%d",&num);
    int flag = num;
    int i;
    int j;
    int temp;
    for ( i = 0; i < num; i++)
    {
        scanf("%d",&a[i]);
        // system(Pause);
        // wait(20,msec);
    }
     for ( i = 0; i < num-1; i++)
    {
        for ( j = 0; j < num-1-i; j++)
        {
            if (a[j]>a[j+1])
            {
                temp=a[j+1];
                a[j+1]=a[j];
                a[j]=temp;
            }
            
        }
    }
    for ( i = 0; i < num; i++)
    {
        if(a[i] == a[i+1]){

        flag--;
        a[i] = -1;
        }
    }
    
    printf("%d\n",flag);
    for ( i = 0; i < num; i++)
    {
        if (a[i]>0)
        {
            printf("%d ",a[i]);
        }
        
    }
    
    

}