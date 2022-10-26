#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define bufferlen  1024*4
char *FILENAME;

/*
    len:要复制的长度，小于0时为全部复制
    offsetsource:复制的起始位置
    offsetTarget:粘贴的其实位置
*/
long fcopy(FILE *fsource,long offsetsource,int len,FILE *ftarget,long offsetTarget){
    char *buffer = (char*)malloc(bufferlen);
    int readcount;
    long nBytes = 0;
    int n = 0;
    int i = 0;
    fseek(fsource,offsetsource,SEEK_SET);
    fseek(ftarget,offsetTarget,SEEK_SET);
    if(len<0){
        while ((readcount = fread(buffer,1,bufferlen,fsource))>0)
        {
            fwrite(buffer,1,bufferlen,ftarget);
            nBytes+=readcount;
        }
        }else{
            int Bufferlen = 1024*4;
            n = (int)ceil((double)((double)len/bufferlen));
            for ( i = 0; i < n; i++)
            {
            
            if (len-nBytes<Bufferlen) 
            {
                Bufferlen = len - nBytes;
            }
            readcount = fread(buffer,1,Bufferlen,fsource);
            fwrite(buffer,1,Bufferlen,ftarget);
            nBytes +=readcount;
        }
        }
        fflush(ftarget);
        free(buffer);
        return nBytes;
}//完成定点，定长度的复制


long fsize(FILE *fp){
    long n;
    fpos_t fpos;//当前位置
    fgetpos(fp,&fpos);//获取当前位置
    fseek(fp,0,SEEK_END);
    n = ftell(fp);
    fsetpos(fp,&fpos);//恢复之前的位置，防止之后的操作出现问题
    return n;
}//获取文件大小

/* 
    offset:插入的起始位置的偏移量
    len:插入数据的大小
    buffer:插入数据的内容
    fp:输出的文件地址
*/
int finsert(FILE *fp, long offset, void *buffer, int len){
    long fileSize = fsize(fp);
    FILE *fpTemp;  //临时文件

    if(offset>fileSize || offset<0 || len<0){  //插入错误
        return -1;
    }

    if(offset == fileSize){  //在文件末尾插入
        fseek(fp, offset, SEEK_SET);
        if(!fwrite(buffer, len, 1, fp)){
            return -1;
        }
    }
    if(offset < fileSize){  //从开头或者中间位置插入
        fpTemp = tmpfile();
        fcopy(fp, 0, offset, fpTemp, 0);//将插入前的内容复制到临时文件中
        fwrite(buffer, len, 1, fpTemp);//将插入的内容写入到临时文件中
        fcopy(fp, offset, -1, fpTemp, offset+len);//将源文件的剩余部分复制到临时文件中
        freopen(FILENAME, "wb+", fp );//表示重新分配文件指针
        fcopy(fpTemp, 0, -1, fp, 0);//将临时文件中的所有内容复制到目标文件，完成插入
        fclose(fpTemp);
    }
   
    return 0;
}//从文件某一位置插入


int fdelete(FILE *fp, long offset, int len){
    long fileSize = fsize(fp);
    FILE *fpTemp;

    if(offset>fileSize || offset<0 || len<0){  //错误
        return -1;
    }

    fpTemp = tmpfile();
    fcopy(fp, 0, offset, fpTemp, 0);  //将前offset字节的数据复制到临时文件
    fcopy(fp, offset+len, -1, fpTemp, offset);  //将offset+len之后的所有内容都复制到临时文件
    freopen(FILENAME, "wb+", fp );  //重新打开文件
    fcopy(fpTemp, 0, -1, fp, 0);//全部复制到目标文件中

    fclose(fpTemp);
    return 0;
}//删除文件某一位置的内容

int main(){
    printf("Input the name of file you want to change");
    scanf("%s",FILENAME);
    
}