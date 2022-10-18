#include<stdio.h>
int main(){
    char a,b;
    printf("请输入字符");
    a=getchar();
    b = a;
    if (b>=97&&b<=122)
    {   b-=32;
        printf("%c\n",b);
    }else if (b>=65&&b<=90)
    {   b+=32;
        printf("%c\n",b);;
    }else{
        printf("%d\n",b);
    }
    return 0;
    
}