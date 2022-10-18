#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<string.h>
int main(){
    char *input1,*input3;
    char input2;
    char str[2] = {3,0};
    printf("请玩家输入");
    scanf("%s",input1);
    scanf("%c",&input2);
    scanf("%s",input3);
    if (strcmp(input1,str)==0)
    {
        printf("好");
    }else{
        printf("坏");
    }

    
    
    
            
}