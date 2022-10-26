#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 2

//在程序中新创建的文件不能马上用文件指针去指
struct stu{
    char name[10];
    int num;
    int age;
    float score;
} boya[N], boyb[N], boyc[N],*pa, *pb, *pc,boy1,boy2;

int main(){
    FILE *fp;
    int i;
    pa=boya;
    pb=boyb;
    pc=boyc;
    if( (fp=fopen("visualtxt.txt","wt+")) == NULL ){
        puts("Fail to open file!");
        exit(0);
    }

    //从键盘读入数据，保存到boya
    printf("Input data:\n");
    for(i=0; i<N; i++,pa++){
        scanf("%s %d %d %f", pa->name, &pa->num, &pa->age, &pa->score);   
    }
    pa = boya;
    //将boya中的数据写入到文件
    for(i=0; i<N; i++,pa++){
        fprintf(fp,"%s %d %d %f\n", pa->name, pa->num, pa->age, pa->score);   
    }
    //重置文件指针
    rewind(fp);
    // 从文件中读取数据，保存到boyb
    for(i=0; i<N; i++,pb++){
        fscanf(fp, "%s %d %d %f\n", pb->name, &pb->num, &pb->age, &pb->score);
    }//pb在尾端
    // fread(boyb,sizeof(struct stu),2,fp);
    pb=(boyb-2);
    //将boyb中的数据输出到显示器
    for(i=0; i<N; i++,pb++){
        printf("%s  %d  %d  %f\n", pb->name, pb->num, pb->age, pb->score);
    }


    FILE *fp2;
    if( (fp2=fopen("visualtxt.txt","rt")) == NULL ){
        puts("Fail to open file!");
        exit(0);
    }
    // fseek(fp2,sizeof(struct stu),SEEK_SET);//SEEK_SET或0为文件开头，SEEK_CUR或1为当前位置，SEEK_END或2为文件末尾,SEEK_SET慎用，END可以使用,CUR定位很不准
    rewind(fp);
                                                                    // printf("Input data:\n");
                                                                    // for(i=0; i<N; i++,pc++){
                                                                    //     scanf("%s %d %d %f", pc->name, &pc->num, &pc->age, &pc->score);   
                                                                    // }
                                                                    // pc = boyc;
                                                                    // for(i=0; i<N; i++,pc++){
                                                                    //     fprintf(fp,"%s %d %d %f\n", pc->name, pc->num, pc->age, pc->score);   
                                                                    // }
    fread(&boyc,sizeof(struct stu),2,fp2);//一般读二进制文件,记得”&“，输出的文件指针在文末
    // boy2 = (boy1-1);
    pc = boyc;
    fscanf(fp2, "%s %d %d %f\n", pc->name, &pc->num, &pc->age, &pc->score);
    pc = boyc;
    printf("%s %d %d %f\n",pc->name,pc->num,pc->age,pc->score);
    rewind(fp2);
    fscanf(fp2, "%s %d %d %f\n", pc->name, &pc->num, &pc->age, &pc->score);
    printf("%s %d %d %f\n",pc->name,pc->num,pc->age,pc->score);
    rewind(fp2);//确实是有效的,在“rt"的打开方式中有用
    fscanf(fp2, "%s %d %d %f\n", pc->name, &pc->num, &pc->age, &pc->score);
    printf("%s %d %d %f\n",pc->name,pc->num,pc->age,pc->score);
    fclose(fp);
    fclose(fp2);
    return 0;
}
