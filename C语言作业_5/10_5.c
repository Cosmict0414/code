#include<stdio.h>
int num = 0;
void del_1(char p[],int len){
    int i;
    for ( i = 0; i < len; i++)
    {
        if (p[i]==p[i+1])
        {
            p[i] = '\0';
            num++;
        }
        
    }
    
}
void del_2(char *p,int len){
    int i;
    for ( i = 0; i < len; i++)
    {
        if (p[i]==p[i+1])
        {
            p[i] = '\0';
            num++;
        }
        
    }
    
}
int main(){
    char p[100];
    scanf("%s",p);
    int i;
    int len = 0;
    for ( i = 0; i < 100; i++)
    {
        if (p[i]<=122&&p[i]>=97)
        {
            len++;
        }
        
    }
    del_1(p,len);
    for ( i = 0; i < len-num; i++)
    {
        printf("%c",p[i]);
    }
    printf("\n");
}