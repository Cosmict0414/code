#include <stdio.h>
#include <stdlib.h>

int sum1(int b,int c){
    int sum;
    int i;
    int a[12] = {31,29,31,30,31,30,31,31,30,31,30,31};
    for(i = 0;i<b;i++){
        sum+=a[i-1];
    }
    sum+=c;
    return sum;

}
int sum2(int b,int c){
    int sum;
    int i;
    int a[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    for(i = 0;i<b;i++){
        sum+=a[i-1];
    }
    sum+=c;
    return sum;
}
int main()
{
    int a,b,c;
    printf("请输入日期（年，月，日\n");
    scanf("%d,%d,%d",&a,&b,&c);
    if(a%4==0){
        printf("%d月%d日是%d年的第%d天",b,c,a,sum1(b,c));
    }else{
        printf("%d月%d日是%d年的第%d天",b,c,a,sum2(b,c));
    }


}
