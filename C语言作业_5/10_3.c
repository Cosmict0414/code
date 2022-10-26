#include<stdio.h>
unsigned int MyStrlen_1(char *p){
    unsigned int len;
    len = 0;
    for ( ; *p!='\0'; p++)
    {
        len++;
    }
    return len;
}

unsigned int MyStrlen_2(char s[]){
    char *p = s;
    while (*p!='\0')
    {
        p++;
    }
    return &(*p)-&(*s);
}

int MyStrlen_3(char *p1,char *p2){
    for(;*p1 == *p2;p1++,p2++){
        if (*p1=='\0')
        {
            return 0;
        }
    }
    return *p1-*p2;
}

int MyStrlen_4(char s[],char t[]){
    int i;
    for ( i = 0;s[i]==t[i]; i++)
    {
        if (s[i]=='\0') 
        {
            return 0;
        }
    }
    return s[i]-t[i];
}
int main(){
    char password[7] = "secret";
    char userInput [81];
    printf("%d\t%d\n",MyStrlen_1(password),MyStrlen_2(password));
    printf("Input Password:");
    
    scanf("%s",userInput);
    if (MyStrlen_3(password,userInput)==0)
    {
        printf("Correct passwird! Welcome to the system\n");
    }
    else if (MyStrlen_4(password,userInput)<0)
    {
        printf("Invalid passsword! userinput <password\n");
    }else printf("Invalid passsword! userinput >password\n");
    return 0;
}