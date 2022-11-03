#include <stdio.h>
#include <stdlib.h>
int cal(int year){
    int n;
    if(year<=1904)
    { n = 0;}
    else{ n = (year-1900-1)/4;}
    int m = year-1900-n;
    int sum = 366*n+365*m;
    return sum;
}
int main()
{
    int year;
    int month;
    scanf("%d %d",&year,&month);
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
    printf("Sun\tMon\tTue\tWed\tThu\tFri\tSat\n");
    int num_t = sum%7;//周一后几天
    int day = 1;
    if(flag==1){
    if(num_t==6){
        for(i=0;i<5&&day<=rn[month-1];i++){

            for(j=0;j<7&&day<=rn[month-1];j++){
                printf("%d\t",day);
                day++;
            }
            printf("\n");
        }
    }else{
        for(i=0;i<num_t+1;i++){
            printf("\t");}
            for(i=0;i<7-(num_t+1);i++){
                printf("%d\t",day);
                day++;
            }
            for(i=0;i<6&&day<=rn[month-1];i++){
            printf("\n");

            for(j=0;j<7&&day<=rn[month-1];j++){
                printf("%d\t",day);
                day++;
            }
        }
    }
    }else//计算平年{
        if(num_t==6){
        for(i=0;i<5&&day<=pn[month-1];i++){

            for(j=0;j<7&&day<=pn[month-1];j++){
                printf("%d\t",day);
                day++;
            }
            printf("\n");
        }
    }else{
        for(i=0;i<num_t+1;i++){
            printf("\t");}
            for(i=0;i<7-(num_t+1);i++){
                printf("%d\t",day);
                day++;
            }
            for(i=0;i<6&&day<=pn[month-1];i++){
            printf("\n");

            for(j=0;j<7&&day<=pn[month-1];j++){
                printf("%d\t",day);
                day++;
            }
        }
    }
    
    
    return 0;
}
