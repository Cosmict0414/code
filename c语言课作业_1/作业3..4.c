#include<stdio.h>
#include<math.h>
int main(){
    float a,b,c,s;
    float x0=0,x1;
    printf("请输入三个数字");
    scanf("%f %f %f",&a,&b,&c);
    s=sqrt(b*b-4*a*c);
    if (b*b-4*a*c<=0)
    {
        printf("该方程没有两个不同的实数解\n");
    }else{
        x0=(-b+s)/(2*a);
        x1=(-b-s)/(2*a);
        printf("%f %f\n",x0,x1);

    }
}