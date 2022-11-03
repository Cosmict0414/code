#include<stdio.h>
#include<stdlib.h>

int num = 0;
double ave_in;
double ave_ex;

struct user{
    int ID;
    char name[10] ;
    int income;
    int expenses;

}users[10],temp[1],*pa,*p;


void fun1(struct user *users,struct user *pa,int num){
    int i;
     while(num<1||num>10){
            printf("Input the total of people:");
            scanf("%d",&num);
            if (num>10)
            {
                printf("The system can only store the information of 10 people at most.Please re-enter");
            }
            
            if (num>0&&num<=10)
            {
                printf("Please input user's ID, name, income and expenses: (format as:10001 Cindy 6000 1500)\n");
                    for ( i = 0; i < num; i++,pa++)
                {
                    scanf("%d %s %d %d\n",&pa->ID,pa->name,&pa->income,&pa->expenses);
                    
                    break;
                }
            }
        }
}


void fun2(struct user *users,struct user *temp,int len){
    int i,j;
    struct user *p;
    for ( i = 0; i < len; i++)
    {
        for ( j = 0; j < len-i; j++)
        {
            if (users[j].name[1]>users[j+1].name[1])
            {
                continue;
            }
            else if (users[j].name[1]<users[j+1].name[1]){
                temp[1] = users[j];
                users[j] = users[j+1];
                users[j+1] = temp[1];
            }if (users[j].name[1]==users[j+1].name[1])
            {
                if (users[j].name[2]<users[j].name[2])
                {
                    temp[1] = users[j];
                    users[j] = users[j+1];
                    users[j+1] = temp[1];
                }else continue;
                
            }
            
            
        }
        
    }

    p = users;
    for ( i = 0; i < len; i++,p++)
    {
        printf("%8d %8s %8d %8d",p->ID,p->name,p->income,p->expenses);
    }
    

}

int main(){
    pa = users;
    p = users;
    int i;
    fun1(users,pa,num);
    for ( i = 0; i < num; i++,p++)
    {
        printf("%8d %8s %8d %8d",p->ID,p->name,p->income,p->expenses);
    }
    fun2(users,temp,num);

}