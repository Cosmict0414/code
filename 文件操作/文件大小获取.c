#include<stdio.h>
#include<stdlib.h>

long fsize(FILE *fp){
    long n;
    fpos_t fpos;//当前位置
    fgetpos(fp,&fpos);//获取当前位置
    fseek(fp,0,SEEK_END);
    n = ftell(fp);
    fsetpos(fp,&fpos);//恢复之前的位置
    return n;
}

int main(){
    long size = 0;
    FILE *fp = NULL;
    char filename[30];
    printf("Input the file'sname you want to know");
    scanf("%s",filename);
    if ((fp = fopen(filename,"rb")) == NULL)
    {
        printf("Cannot open the file");
        exit(1);
    }
    printf("%ld\n",fsize(fp)); 
    return 0;
}