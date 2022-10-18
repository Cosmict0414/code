#include<stdio.h>
int main(){
    const double PI = 3.1415926;
    double r;
    scanf("%lf",&r);
    printf("%lf %lf\n",(4/3)*PI*r*r*r,4*PI*r*r);
}