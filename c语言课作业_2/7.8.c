#include<stdio.h>
int flag = 5;
int fun(double a){
    int result;
    if (flag>=0)
    {
        flag--;
        result = a = (a-1)*(4/5);
        fun(a);
    }else{
        return result;
    }

}
int main(){
    double i;
    for ( i = 1; i < 1000000.0; i++)
    {   
        flag = 5 ;
        if (fun(i)>0&&fun(i)%1==0)
        {
            break ;
        }
        
    }
    printf("椰子数最少为%.0f\n",i);
    return 0;
}