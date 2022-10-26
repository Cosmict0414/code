#include<stdio.h>
int MyStrlen(char *p1,char *p2){
    for(;*p1 == *p2;p1++,p2++){
        if (*p1=='\0')
        {
            return 0;
        }
    }
    return *p1-*p2;
}
int main(){
    char *Mon = "Monday";
    char *Tue = "Tuesday";
    char *Wed = "Wednesday";
    char *Thu = "Thursday";
    char *Fri = "Friday";
    char *Sat = "Saturday";
    char *Sun = "Sunday";
    char Input[10];
    scanf("%s",Input);

    if (MyStrlen(Input,Mon)==0)
    {
        printf("1\n");
    }else if (MyStrlen(Input,Tue)==0)
    {
        printf("2\n");
    }else if (MyStrlen(Input,Wed)==0)
    {
        printf("3\n");
    }else if (MyStrlen(Input,Thu)==0)
    {
        printf("4\n");
    }else if (MyStrlen(Input,Fri)==0)
    {
        printf("5\n");
    }else if (MyStrlen(Input,Sat)==0)
    {
        printf("6\n");
    }else if (MyStrlen(Input,Sun)==0)
    {
        printf("7\n");
    }else printf("Error");

}