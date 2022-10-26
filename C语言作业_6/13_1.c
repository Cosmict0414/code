#include<stdio.h>
#include<string.h>
#include<stdlib.h>

 void type(FILE *fp){
    char p[100];
    fread(p,sizeof(char),10,fp);
    int  i;
    for ( i = 0; i < 10; i++)
    {
        printf("%d\t",(int)p[i]);
    }
    
 }


int main(){
    FILE *fp;
    char command[10] = {'\0'};
    scanf("%s",command);
    char *rc = "type";
    char file[10];
    scanf("%s",file);
    if ((fp = fopen(file,"r")) == NULL)
    {
        printf("Fail to open yhe file\n");
        exit(0);
    }
    if (strcmp(command,rc) == 0)
    {
        type(fp);
    }else printf("Wrong command\n");
    
    fclose(fp);
}