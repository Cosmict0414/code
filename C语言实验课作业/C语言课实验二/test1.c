#include<stdio.h>
#include<math.h>
int main(){
    float temp;
    float a[3];
    float s,p;
    int i,j;
    scanf("%f %f %f",&a[0],&a[1],&a[2]);
    for ( i = 0; i <2; i++)
    {
        for ( j = 0; j < 2-i; j++)
        {
            if (a[j]>a[j+1])
            {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
            
        }
        
    }
    p = (a[0]+a[1]+a[2])/2;
    s = sqrtf(p*(p-a[0])*(p-a[1])*(p-a[2]));
    if (a[0]+a[1]<=a[2])
    {
        printf("这不是三角形\n");
    }else if (a[0]==a[1]&&a[1]==a[2])
    {
        printf("等边三角形\n");
        printf("S=%.2f",s);
    }else if (a[0]==a[1]&&a[1]!=a[2]&&sqrtf(pow(a[0],2)+pow(a[1],2))-a[2]<0.001&&sqrtf(pow(a[0],2)+pow(a[1],2))-a[2]>0)
    {
        printf("等腰直角三角形\n");
        printf("S=%.2f",s);
    }else if (a[0]!=a[1]&&a[1]!=a[2]&&pow(a[0],2)+pow(a[1],2)-pow(a[2],2)<0.001)
    {
        printf("直角三角形\n");
        printf("S=%.2f",s);
    }else if (a[0]==a[1]&&a[1]!=a[2])
    {
        printf("等腰三角形\n");
        printf("S=%.2f",s);
    }else if (a[0]!=a[1]&&a[1]!=a[2]&&a[0]+a[1]>a[2])
    {
        printf("一般三角形\n");
        printf("S=%.2f",s);
    }
    return 0; 
    
}