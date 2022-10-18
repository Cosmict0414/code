#include<stdio.h>
#include<math.h>
int main(){
    int a=0,b=0,i=30,num;
    int find=0;
    num = 1000*a+100*a+10*b+b;
    for ( a = 0; a < 10; a++)
    {
        for ( b = 0; b < 10; b++)
        {
            num = 1000*a+100*a+10*b+b;
            for ( i = 30; i < 100; i++)
            {
                if (num==pow(i,2))
                {
                    printf("车牌号为%d\n",num);
                }
                
            }
            
            
        }
        
    }
    
    

}