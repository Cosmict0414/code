#include<stdio.h>
int fun_1(a){
    int age;
    if (a ==1)
    {
        age = 10;
    }else{
        age = fun_1(a-1);
        age+=2;
    }
    return age;
}
int main(){
    int age;
    int a;
    printf("请输入你想求的人物序号");
    scanf("%d",&a);
    age = fun_1(a);
    printf("该人物的年龄为%d\n",age);
    return 0;

}