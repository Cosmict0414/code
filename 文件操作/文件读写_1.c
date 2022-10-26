#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
    FILE *fp = fopen("file.txt","a");
    /*
    "r"  以“只读”方式打开文件。只允许读取，不允许写入。文件必须存在，否则打开失败。
    "w"	 以“写入”方式打开文件。如果文件不存在，那么创建一个新文件；如果文件存在，那么清空文件内容（相当于删除原文件，再创建一个新文件）。
    "a"	 以“追加”方式打开文件。如果文件不存在，那么创建一个新文件；如果文件存在，那么将写入的数据追加到文件的末尾（文件原有的内容保留）。
    "r+" 以“读写”方式打开文件。既可以读取也可以写入，也就是随意更新文件。文件必须存在，否则打开失败。
    "w+" 以“写入/更新”方式打开文件，相当于w和r+叠加的效果。既可以读取也可以写入，也就是随意更新文件。如果文件不存在，那么创建一个新文件；如果文件存在，那么清空文件内容（相当于删除原文件，再创建一个新文件）。
    "a+" 以“追加/更新”方式打开文件，相当于a和r+叠加的效果。既可以读取也可以写入，也就是随意更新文件。如果文件不存在，那么创建一个新文件；如果文件存在，那么将写入的数据追加到文件的末尾（文件原有的内容保留）。
    */
    if (fp == NULL)
    {
        printf("Fail to open the file");
        exit(0);
    }
    // char ch;
    // while((ch = fgetc(fp))!= EOF){
    //     printf("%c\n",ch);//读取数值包括换行符
    // }
    // putchar('\n');
    

    // char str[200];
    // while(fgets(str,200,fp)!=NULL){
    //     printf("%s\n",str);
    // }

    char tempstr[200];
    char front[400] = "\nyour inputed string:";
    char finish[300];
    printf("Please input a string:");
    scanf("%s",tempstr);
    strcat (front,tempstr);
    strcat(front,"\n");
    fputs(front,fp);//会从开头插入
    // fputs(fp,tempstr);
    




    fclose(fp);//把文件关闭，释放相关资源，避免数据丢失
    return 0;
}