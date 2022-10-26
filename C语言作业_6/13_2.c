#include<stdio.h>
#include<stdlib.h>

struct Stu{
    char name[10];
    int math;
    int English;
    int chemistry;
    int physics;;
    double ave;
}sta[10],*pa;

int main(){
    FILE *fp;
    pa = sta;
    if ((fp = fopen("Infomation.txt","wt")) == NULL)
    {
        printf("Fail to open the file");
        exit(0);
    }

    
    int num;
    printf("Please input the number of students\n");
    scanf("%d",&num);
    printf("Please input the name and scores of four subjests\n");
    for ( int i = 0; i < num; i++,pa++)
    {
        scanf("%s %d %d %d %d",pa->name,&pa->math,&pa->English,&pa->chemistry,&pa->physics);
        sta[i].ave = (pa->math+pa->English+pa->chemistry+pa->physics)/4;
    }

    pa = sta;
    for ( int i = 0; i < num; i++,pa++)
    {
        fprintf(fp,"Name : %8s \tMath : %7d\tEnglish : %7d\tChemistry : %7d\tPhysics : %7d\tAverage Score: %lf\n",pa->name,pa->math,pa->English,pa->chemistry,pa->physics,pa->ave);
    }
    
    printf("Mission Complete\n");
    fclose(fp);
}