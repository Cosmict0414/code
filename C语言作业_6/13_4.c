#include<stdio.h>
#include<string.h>

int main(){
    FILE *fp;
    char file[10] = {"1.txt"};
    printf("Input the file's name\n");
    // scanf("%s",file);
    if ((fp = fopen(file,"rt")) == NULL)
    {
        printf("Fail to open the file\n");
    }

    char p1[20];
    fscanf(fp,"%s",p1);
    char Des[20] = {"1copy.txt"};
    FILE *fp2;
    printf("Input the name of the destination\n");
    // scanf("%s",Des);
    if ((fp2 = fopen(Des,"wt")) == NULL)
    {
        printf("Fail to open the file\n");
    }
    fprintf(fp2,"%s",p1);

    fclose(fp);
    fclose(fp2); 
}