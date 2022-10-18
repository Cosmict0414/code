#include<stdio.h>
int main(){
    double F = 0,C = 0;
    for ( F = 0; F <=300; F+=10)
    {
        C = 5.0/9.0*(F-32);
        printf("%.2lf华摄氏度=%.2lf摄氏度\t",F,C);
    }
    
}
