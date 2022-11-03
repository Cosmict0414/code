#include<stdio.h>
#include<string.h>
#include<stdlib.h>

double ave_in;
double ave_ex;

/*
*     定义结构体
*/
struct user{
    int ID;
    char name[10] ;
    int income;
    int expenses;

}users[10],temp[1],*pa;

/******************************************************************************************************************************************************************************************************************************************************************************/

/*
*     定义函数
*/

/**
 * @brief 录入用户ID，用户名，收入，支出（收入和支出均为整数）
 * 
 * @param pa 指针，复制到栈区，防止移位
 * @param num 输出个体数量
 * @return int 以整型输出
 */
int fun1(struct user *p,int num){
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
                    for ( i = 0; i < num; i++,p++)
                {
                    scanf("%d %s %d %d",&p->ID,p->name,&p->income,&p->expenses);
                    
                }
            }
        }

    printf("Press any key to continue");
    fflush(stdin);
    getchar();
    return num;
}

/**
 * @brief 按用户名的字典序逆序排列后输出用户记账信息
 * 
 * @param num 人数
 */
void fun2(int num){
    int i,j;
    printf("%d\n",num);
    struct user *p;
    for ( i = 0; i < num; i++)
    {
        for ( j = 0; j < num-i; j++)
        {
            if (users[j].name[0]>users[j+1].name[0]){
                continue;
            }
            else if (users[j].name[0]<users[j+1].name[0]){
                temp[0] = users[j];
                users[j] = users[j+1];
                users[j+1] = temp[0];
            }if (users[j].name[0]==users[j+1].name[0]){

                if (users[j].name[1]<users[j].name[1]){

                    temp[0] = users[j];
                    users[j] = users[j+1];
                    users[j+1] = temp[0];
                }else continue;
                
            }
            
        }
    
    }

    p = users;
    for ( i = 0; i < num; i++,p++)
    {
        printf("%d %8s %8d %8d\n",p->ID,p->name,p->income,p->expenses);
    }

    printf("Press any key to continue");
    fflush(stdin);
    getchar();
}

/**
 * @brief 使用用户名查找特定用户的记账信息
 * 
 * @param seekname 目标名字
 * @param pa 复制到栈区，防止移位
 * @param num 人数
 */
void fun3(char *seekname,struct user *pa,int num){
    int i;
    for ( i = 0; i < num; i++,pa++)
    {
        if (strcmp(seekname,pa->name) == 0)
        {
           printf("%8d %8s %8d %8d\n",pa->ID,pa->name,pa->income,pa->expenses);
        }
        
    }
    
    printf("Press any key to continue");
    fflush(stdin);
    getchar();
}

/**
 * @brief 计算并输出所有用户的人均收入和人均支出（人均收入=总收入/用户人数）
 *
 * @param num 人数
 */
void fun4(int num){
    double sum1 = 0,sum2 = 0;
    int i;
    for ( i = 0; i < num; i++)
    {
        sum1+=users[i].income;
        sum2+=users[i].expenses;
    }
    ave_in = (float)sum1/num;
    ave_ex = (float)sum2/num;
    printf("Per capita income:%.2f\nPer capita expenses:%.2f\n",ave_in,ave_ex);

    printf("Press any key to continue");
    fflush(stdin);
    getchar();

}

/**
 * @brief 输出所有支出大于平均支出的用户记账信息
 * 
 * @param num 人数
 */
void fun5(int num){
    struct user *p;
    p = users;
    int i;
    double sum1 = 0,sum2 = 0;
    for ( i = 0; i < num; i++)
    {
        sum1+=users[i].income;
        sum2+=users[i].expenses;
    }
    ave_in = sum1/num;
    ave_ex = sum2/num;
    for ( i = 0; i < num; i++,p++)
    {
        if (p->expenses>ave_ex)
        {
            printf("%8d %8s %8d %8d\n",p->ID,p->name,p->income,p->expenses);
        }
        
    }
    
    printf("Press any key to continue");
    fflush(stdin);
    getchar();

}

/**
 * @brief 输出系统中所有的记账信息（按ID升序输出）
 * 
 * @param num 人数
 */
void fun6(int num){
    struct user *p;
    int i,j;
    p = users;
    for ( i = 0; i < num; i++)
    {
        for ( j = 0; j < num-i-1; j++)
        {
            if (users[j].name[0]<users[j+1].name[0])
            {
                continue;
            }
            else if (users[j].ID>users[j+1].ID){
                temp[0] = users[j];
                users[j] = users[j+1];
                users[j+1] = temp[0];
            }
        }   
    }   
    printf("ID\tUserName\tIncome\tExpenses\n");
    for ( i = 0; i < num; i++,p++)
    {
        printf("%8d %8s %8d %8d\n",p->ID,p->name,p->income,p->expenses);
    }

    printf("Press any key to continue");
    fflush(stdin);
    getchar();
}

/**
 * @brief 将每个用户的记账信息写入文件
 * 
 * @param p 结构体指针
 * @param num 人数
 */
void fun7(struct user *p,int num){

    FILE *fp;
    int i;
    char name[20];
    printf("PLease input the file name:");
    fflush(stdin);
    scanf("%s",name);
    fp = fopen(name,"at+");
    if (fp == NULL)
    {
        printf("Fail to open the file.Press any key to exit");
        getchar();
        exit(0);
    }

    for(i=0; i<num; i++,p++){
        fprintf(fp,"%d %s %d %d\n", p->ID, p->name, p->income, p->expenses);   
    }
    printf("Save successfully press any key to exit\n");
    fflush(stdin);
    getchar();

    fclose(fp);

}

/**
 * @brief 读取文件中的记账信息并显示
 * 
 * @return int 信息个数
 */
int fun8(){

    FILE *fp;
    struct user *pb;
    pb =users;
    int i;
    int num = 0;
    char name[20];
    printf("PLease input the file name:");
    fflush(stdin);
    scanf("%s",name);
    fp = fopen(name,"rb");
    if (fp == NULL)
    {
        printf("Fail to open the file.Press any key to exit");
        getchar();
        return 0;
    }

    for(i=0; i<10; i++,pb++){
        fscanf(fp, "%d %s %d %d\n", &pb->ID, pb->name, &pb->income, &pb->expenses);
    }
    pb = users;
    printf("ID\tUserName\tIncome\tExpenses\n");
    for(i = 0;i<10;i++,pb++){
        if(pb->ID ==0) break;
        printf("%8d %8s %8d %8d\n",pb->ID,pb->name,pb->income,pb->expenses);
        num++;
    }

    fclose(fp);
    return num;
}


/*******************************************************************************************************************************************************************************************************************************************************************************/

/*
*     主函数部分
*/
int main(){
    int choice = 1;
    int num;
    int i,j;

    pa = users;
    char seekname[10];

    while(choice!=0){
        printf("1.Input record\n2.Sort and list records in reverse order by user name\n3.Search records by user name\n4.Calculate and list per capita income and expenses\n5.List records whiceh have more expenses than per capita expenses\n6.List all records\n");
        printf("7.Write to file\n8.Read from file\n0.Exit\n");
        printf("Please enter your choice:");
        fflush(stdin);
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            num = fun1(pa,num);
    
            break;

        case 2:
            if (num <=0)
            {
                printf("There is no Data yet.Please choose 1 or 8 to input data first");
            }else{
                printf("ID\tUserName\tIncome\tExpenses");
                fun2(num);
            }
    
            break;

        case 3:
            if (num <=0)
            {
                printf("There is no Data yet.Please choose 1 or 8 to input data first");
                continue;
            }
            printf("Please input the user name:");
            scanf("%s",seekname);
            fun3(seekname,pa,num);
        
            break;

        case 4:
            if (num <=0)
            {
                printf("There is no Data yet.Please choose 1 or 8 to input data first");
                continue;
            }
            fun4(num);

            break;

        case 5:
            if (num <=0)
            {
                printf("There is no Data yet.Please choose 1 or 8 to input data first");
                continue;
            }
            fun5(num);
     
            break;
        
        case 6:
            if (num <=0)
            {
                printf("There is no Data yet.Please choose 1 or 8 to input data first");
                continue;
            }
            fun6(num);

            break;

        case 7:
            if (num <=0)
            {
                printf("There is no Data yet.Please choose 1 or 8 to input data first");
                continue;
            }

            fun7(pa,num);
            break;

        case 8:

            num = fun8();
            break;
        }


    }

}
