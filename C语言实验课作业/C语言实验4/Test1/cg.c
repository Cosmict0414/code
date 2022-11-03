#include <stdio.h>
#include <stdlib.h>
int cal(int year){
    int n = (year-1900)/4;
    int m = year-1900-n;
    int sum = 366*n+365*m;
    return sum;
}

int main()
{
    int year = 2020;
    int month = 2;
    int rn[12] = {31,29,31,30,31,30,31,31,30,31,30,31};
    int pn[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int sum = cal(year);
    int i;
    int flag;
    if(year%4==0&&year%100!=0){
        for(i=0;i<month-1;i++){
            sum+=rn[i];
            flag = 1;
        }
    }else{
        for(i=0;i<month-1;i++)
        sum+=pn[i];
        flag = 0;
    }
    int j;
    printf("SUN\tMON\tTUE\tWED\tTHU\tFRI\tSAT\t\n");
    int num_t = sum%7;
    int day = 1;
    if(num_t==6){
        for(i=0;i<5&&day<=rn[month-1];i++){
            printf("\n");

            for(j=0;j<7&&day<rn[month-1];j++){
                printf("%d\t",day);
                day++;
            }
        }
    }else{
        for(i=0;i<num_t-1;i++){
            printf("\t");}
            for(i=0;i<7-num_t;i++){
                printf("%d\t",day);
                day++;
            }
            for(i=0;i<5&&day<=rn[month-1];i++){
            printf("\n");

            for(j=0;j<7&&day<=rn[month-1];j++){
                printf("%d\t",day);
                day++;
            }

        }

    }

    return 0;
}
