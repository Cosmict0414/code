#include<stdio.h>
#include<stdlib.h>

int main(){
    char word;
    char str[10];
    scanf("%c",&word);
    int i = 0;
    int j;
    int num;
    int flag = 1;
    for(flag = 0;flag<5;flag++){
     while (word>96&&word<123)
        {
            scanf("%c",&word);
        }
    while (word >47&&word<58)
    {
        str[i++] = word;
        scanf("%c",&word);
      
    } 
        num = atoi(str);
        if (num!=0)
        {
           printf("%10d\n",num);
        }
        
        for ( j = 0; j < 10; j++)
        {
            str[j] = 32;
        }
        while (word>96&&word<123)
        {
            scanf("%c",&word);
        }
    }
    return 0;
}