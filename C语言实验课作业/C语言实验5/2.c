#include<stdio.h>
int Mean(int *a,int len){
    int sum = 0;
    int result = 0;
    int i;
    for ( i = 0; i < 40; i++)
    {
        sum+=a[i];
    }
    result =sum/len;
    return result;
}


int main(){
    int a[40] = {0};
    int len;
    scanf("%d",&len);
    int i;
    int j;
    int temp;
    for ( i = 0; i < len; i++)
    {
        scanf("%d",&a[i]);
    }
    for ( i = 0; i < len; i++)
    {
        for ( j = 0; j < len; j++)
        {
            if (a[j]>a[j+1])
            {
                temp=a[j+1];
                a[j+1]=a[j];
                a[j]=temp;
            }
        }
    }
    int ave = Mean(a,len);
    int mid;
    if (len%2!=0)
    {
        mid = a[1+len/2];
    }else{
        mid = (a[len/2]+a[1+len/2])/2;
    }
    int max[40] = {0};
    int num[40] = {0};
    int flag = 0;
     for ( i = 0; i < len; i++)
     {
        if (a[i] == a[i+1])
        {
            max[flag]++;
            num[flag] = a[i];
        }if (a[i]!=a[i+1])
        {
            flag++;
        }
     }
     int max1;
     int num1 = num[0];

     for ( i = 0; i < 20; i++)
     {
        if (max[i]<max[i+1])
        {
            num1 = num[i+1];
        }
        
     }
     printf("Mean=%d\n",ave);
     printf("Median=%d\n",mid);
     printf("Mode=%d",num1);
     
}