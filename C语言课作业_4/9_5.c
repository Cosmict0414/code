#include<stdio.h>
int DayofYear(int year, int month, int day){
    int rn[12] ={31,29,31,30,31,30,31,31,30,31,30,31};
    int pn[12] ={31,28,31,30,31,30,31,31,30,31,30,31};
    int sum = 0;
    int i;
    if (year%4==0&&year%100!=0||year%400==0)
    {
        for ( i = 0; i < month-1; i++)
        {
            sum+=rn[i];
        }
        
    }else {
        for(i = 0;i<month-1;i++)
        {
            sum+=pn[i];
        }
    
    }
    sum+=day;
    return sum;
}
void MonthDay(int year, int yearDay,int *pMonth,int *pDay){
    int rn[12] ={31,29,31,30,31,30,31,31,30,31,30,31};
    int pn[12] ={31,28,31,30,31,30,31,31,30,31,30,31};
    int month = 0;
    int i =0;
    if (year%4==0&&year%100!=0||year%400==0)
    {
        while(yearDay-rn[month]>0){
            yearDay-=rn[month];
            month++;
        }
        
    }else {
        while(yearDay-pn[month]>0){
            yearDay-=rn[month];
            month++;
        }

    }
    *pMonth = month+1;
    *pDay = yearDay;
}
int main(){
    printf("1.year/month/day->yearday\n");
    printf("2.yearDay->year/month->day\n");
    printf("3.Exit\n");
    printf("Please enter your choice:\n");
    int a,b,c;
    int choice;
    int Month,Day;
    scanf("%d",&choice);
    int result;
    int *pMonth = &Month;
    int *pDay = &Day;
    switch (choice)
    {
    case 1:
        scanf("%d %d %d",&a,&b,&c);
        result = DayofYear(a,b,c);
        printf("是第%d天\n",result);
        break;
    
    case 2:
        scanf("%d %d",&a,&b);
        MonthDay(a,b,pMonth,pDay);
        printf("是第%d月第%d天\n",*pMonth,*pDay);
        break;
    case 3:
    break;
    }
}