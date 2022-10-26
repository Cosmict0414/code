#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define BufferLen 1024*24
int copyFile(char *fileRead, char *fileWrite){
    FILE *fpRead;
    FILE *fpWrite;
    char *buffer = (char*)malloc(BufferLen);//二进制读取的数据的储存区
    int readCount;

    if ((fpRead=fopen(fileRead,"rb"))==NULL||(fpWrite=fopen(fileWrite,"wb"))==NULL)//记得括号的规范，只有二进制形式的打开方式，才能正常复制非文本类文件
    {
        printf("Cannot open the file,press any key to exit.");
        getchar();//getch无法在C99上运行
        exit(1);
    }
    else{
        while ((readCount = fread(buffer,1,BufferLen,fpRead)) >0)//fread没有返回读取了几次，但却返回了每次读取的大小，读取缓存区允许的最大数据大小
        {
            printf("%d",readCount);
            fwrite(buffer,readCount,1,fpWrite);//将读取到的值写在预设文件中
        }
        free(buffer);
        fclose(fpRead);
        fclose(fpWrite);
    }
    return 1;
}
int main(){
    char fileRead[100];//要复制的文件名
    char fileWrite[100];//复制后的文件
    printf("Input the file you want to copy.");
    scanf("%s",fileRead);
    printf("The destination is ");
    scanf("%s",fileWrite);

    if (copyFile(fileRead,fileWrite))
    {
        printf("Copy complete!");
    }else printf("Fail to copy!");
    
}