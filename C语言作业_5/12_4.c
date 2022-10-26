#include<stdio.h>
struct candidate
{
    char name[10];
    int num;
};

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
    struct candidate Can1 = {"zhang",0};
    struct candidate Can2 = {"li",0};
    struct candidate Can3 = {"wang",0};
    int i;
    char votename[10];
    int unvote = 0;
    for ( i = 0; i < 10; i++)
    {
        scanf("%s",votename);
        if (MyStrlen(votename,Can1.name)==0)
        {
            Can1.num++;
        }else if (MyStrlen(votename,Can2.name)==0)
        {
            Can2.num++;
        }else if (MyStrlen(votename,Can3.name)==0)
        {
            Can3.num++;
        }else unvote++;
    }
    printf("%s 得票 %d\n",Can1.name,Can1.num);
    printf("%s 得票 %d\n",Can2.name,Can2.num);
    printf("%s 得票 %d\n",Can3.name,Can3.num);
    printf("废票为%d张",unvote);
    
}