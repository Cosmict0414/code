#include<stdio.h>
#include<math.h>
float a = 0.0,b = 1.0;
float c = 0.0,d = 3.0;
float Fun1(float a,float b){
    float result;
    result = (b+pow(b,3)/3)-(a+pow(a,3)/3);
    return result;
}
float Fun2(float c,float d){
    float result;
    result = (log(1+d*d)/2-log(1+c*c)/2);
    return result;
}
float Intergral(float(*f)(float,float),float a,float b){
    float result ;
    result = f(a,b);
    return result;
}
int main(){
    float y_1,y_2;
    y_1 = Intergral(Fun1,0,1);
    y_2 = Intergral(Fun2,0,3);
    printf("y_1 = %f\n",y_1);
    printf("y_2 = %f\n",y_2);
}