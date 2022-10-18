#include <stdio.h>
#include <stdlib.h>
int a[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int b[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};
int year,month;
int Judge(int a){
    if(a%4==0 && a%400!=0){
        return 1;
    }else{
        return 0;
    }
}
int Origin(int x,int y){
    int day=0;
    for(int i=1900;i<x;i++){
        if(Judge(i)){
            day+=366;
        }else{
            day+=365;
        }
    }
    if(Judge(x)){
        for(int i=1;i<y;i++){
            day+=b[i];
        }
    }else{
        for(int i=1;i<y;i++){
            day+=a[i];
        }
    }
    return day%7;
}
int main()
{
    scanf("%d %d",&year,&month);
    int origin=Origin(year,month);
    printf("Sun\tMon\tTue\tWed\tThu\tFri\tSat\n");
    for(int i=0;i<origin;i++){
         printf("\t");
    }
    if(Judge(year)){
        for(int i=1;i<=b[month];i++){
            origin++;
            if(origin==7){
                printf("%d\t\n",i);
                origin=0;
            }else{
                printf("%d\t",i);
            }
        }
    }else{
        for(int i=1;i<=a[month];i++){
            origin++;
            if(origin==7){
                printf("%d\t\n",i);
                origin=0;
            }else{
                printf("%d\t",i);
            }
        }
    }
    return 0;
}