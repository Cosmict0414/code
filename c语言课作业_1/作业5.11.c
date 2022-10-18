#include<stdio.h>
#include<unistd.h>
int main(){
    int faHeight , moHeight , sports , sex , diet , h;
    printf("请输入父亲和母亲的身高");
    scanf("%d %d",&faHeight,&moHeight);
    fflush(stdin);
    printf("\n请回答孩子的性别:F或是M  ");
    sex = getchar();
    if (sex==77)
    {
        h = (faHeight + moHeight)*0.54;
    }else{
        h = (faHeight*0.932+moHeight)/2;
    }
    fflush(stdin);
    printf("\n请回答孩子是否爱运动:Y或是N  ");
    sports = getchar();
    if (sports==89)
    {
        h = h*(1+0.02);
    }
    fflush(stdin);
    printf("\n请回答孩子是否有良好的饮食习惯:Y或是N  ");
    diet = getchar();
    if(diet==89)
    {
        h = h*(1+0.015);
    } 
    printf("\n孩子的身高预估是%d\n",h);
    return 0 ;

}