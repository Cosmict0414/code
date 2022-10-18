#include<stdio.h>
int main(){
    int capital, n;
    printf("请输入存款金额和存放年限");
    scanf("%d %d",&capital,&n);
        switch (n)
        {
        case 1:
            capital=capital*(1+0.0225);
            break;
         case 2:
            capital=capital*(1+0.0243*2);
            break;
         case 3:
            capital=capital*(1+0.0270*3);
            break;
         case 4:
            capital=capital*(1+0.0270*4);
            break;
         case 5:
            capital=capital*(1+0.0288*5);
            break;
         case 6:
            capital=capital*(1+0.0288*6);
            break;
         case 7:
            capital=capital*(1+0.0288*7); 
            break;
         case 8:
            capital=capital*(1+0.03*8);
            break;
        default:
            break;
        
    }
    printf("你的本息加利息为%d\n",capital);
    
    }