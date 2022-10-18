#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<string.h>
//该程序输入两个数时，必须以回车间隔，要不然会有bug
//有时候需要多按一次回车
int main() {
    int a,i;
    int cout = 0;
    char input1,input2,input3,input4;
    int input_1;
    srand((unsigned)time(NULL));
    a = rand()%2;//0为计算机输入，1为人输入
    if (a==0)
    {
        printf("计算机先输入\n");
        for ( cout = 1; cout <30; cout=cout+0)
        {   
            if ((31-cout)%3==0)
            {
                srand((unsigned)time(NULL));
                a = rand()%2 + 1;
                if (a==1)
                {
                    printf("%d\n",cout);
                    if (cout==30)
                    {
                        printf("电脑胜利");
                         break ;
                    }
                    
                    cout++;
 
                }else if(a==2){
                    printf("%d %d\n",cout,cout+1);
                    if (cout==30||(cout+1)==30)
                    {
                        printf("电脑胜利");
                        break;
                    }
                    cout+=2;
                    }  
            }
            else if ((31-cout)%3==1)
            {
                printf("%d\n",cout);
                if (cout==30)
                {
                    printf("电脑胜利");
                    break ;
                }
                cout++;
            }
            else if ((31-cout)%3==2)
            {
                printf("%d %d\n",cout,cout+1);
                if (cout==30||(cout+1)==30)
                {
                    printf("电脑胜利");
                    break;
                }
                cout+=2;
            }
            printf("请玩家输入"); 
            if (cout<10)
            {              
            scanf("%c",&input1);
            scanf("%c",&input2);//可能为回车或是空格
            scanf("%c",&input3);//判断是否输入两个数
            if (input3=='\n')//玩家输入了一个数
            {
                cout++;
            }else{
                cout+=2;
            }
            //玩家输入了两个数
            }else//大于10后的输入格式
            {
            scanf("%d",&input_1);
            scanf("%c",&input2);//可能为回车或是空格
            scanf("%c",&input3);//判断是否输入两个数
            if (input_1==30||input3=='3')
            {
                printf("玩家胜利");
                break;
            }
            //判断玩家是否胜利
            
            if (input3=='\n')//玩家输入了一个数
            {
                cout++;
            }else{
                scanf("%c",&input4);
                cout+=2;
            }
            //玩家输入了两个数
            }
        }
    }else{
        printf("玩家先输入\n");
        for (cout = 1; cout <30; cout=cout+0)
        {   if(cout<10)
        {
            printf("请玩家输入");
            scanf("%c",&input1);
            scanf("%c",&input2);//可能为回车或是空格
            scanf("%c",&input3);//判断是否输入两个数
            if (input3=='\n')//玩家输入了一个数
            {
                cout++;
            }else{
                cout+=2;
            }
            //玩家输入了两个数
        }else//cout>10的情况
        {
            scanf("%d",&input_1);
            scanf("%c",&input2);//可能为回车或是空格
            scanf("%c",&input3);//判断是否输入两个数
            if (input_1==30||input3=='3')
            {
                printf("玩家胜利");
                break;
            }
            //判断玩家是否胜利
            
            if (input3=='\n')//玩家输入了一个数
            {
                cout++;
            }else{
                scanf("%c",&input4);
                cout+=2;
            }
            //玩家输入了两个数
        }
            if ((31-cout)%3==0)
            {
                srand((unsigned)time(NULL));
                a = rand()%2 + 1;
                if (a==1)
                {
                    printf("%d\n",cout);
                    if (cout==30)
                    {
                        printf("电脑胜利");
                         break ;
                    }
                    
                    cout++;
 
                }else{
                    printf("%d %d\n",cout,cout+1);
                    if (cout==30||(cout+1)==30)
                    {
                        printf("电脑胜利");
                        break;
                    }
                    cout+=2;
                    }  
            }
            else if ((31-cout)%3==1)
            {
                printf("%d\n",cout);
                if (cout==30)
                {
                    printf("电脑胜利");
                    break ;
                }
                cout++;
            }
            else if ((31-cout)%3==2)
            {
                printf("%d %d\n",cout,cout+1);
                if (cout==30||(cout+1)==30)
                {
                    printf("电脑胜利");
                    break;
                }
                cout+=2;
            }
            printf("请玩家输入");
        }
        
    }
    return 0;
}