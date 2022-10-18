#include<stdio.h>
#include<math.h>
int cal(double a){
    int flag;
    for ( flag = 0; flag < 4; flag++)
    {
        a = (a-1.0)*(4.0/5.0);
        
    }
    if ( floor(a+0.999999)==(int)a)
        {
            return a;
        }else{
            return 0;
        }
}
int main(){
    double result,i;
    for ( i = 0; i < 100000000.0; i++)
    {
        result = cal(i);
        if (result>0&&((int)result-1)%5==0) break;
    }
    printf("椰子的最少个数为%.0lf\n",i);
    
}