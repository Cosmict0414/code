#include<stdio.h>
#include<stdlib.h>
typedef struct link//"typedef"意为重命名，可以简化之后的定义结构体的步骤
{
    int elem;
    struct link *next;//定义一个结构体指针，可以指向一个结构体
}link;//定义一个结构体包含一个数据区域与一个指针区域

link *creaatlink(int n){
    link *head ,*node, *end;//分为头，身体，尾部三个结构体，*end相当于一根绳子仅用来连接上下两个单元
    int i,a;
    head = (link*)malloc(sizeof(link));//分配一个区域给头部；
    end  = head;//绳头位于head
    for ( i = 0; i <n-1; i++)
    {
        node = (link*)malloc(sizeof(link));//分配一个区域给身体
        printf("please input a number");
        scanf("%d",&a);
        node->elem = a;//赋值给数据部分
        end->next = node;//绳尾位于node单元
        end = node;//将绳头放置在node，以便继续连接下一个单元
    }
    end->next = NULL;
    return head;//返回头部指针，即一窜通过指针相连的单元
}

//链表插入,在n个单元后加
link *insertlink(link *list,int n){
    link *temp = list;
    printf("Input the position you want to insert ");
    int i;
    scanf("%d",&n);
    for ( i = 0; i < n; i++)
    {
        if (temp == NULL)
        {
            printf("position error");
        }
        temp = temp->next; //将temp单元移至要插入的位置前
    }
    link *insert;
    insert = (link*)malloc(sizeof(link));
    printf("请输入插入单元的数据");
    scanf("%d",&insert->elem);
    insert->next =temp->next; //使插入的单元的指向与上一单元相同,就是指向插入后的后一单元
    temp->next =insert; //使上一单元指向插入的单元
    return list;
}

//链表删除，删除第n个单元
link *dellink(link *list,int n){
    printf("Input the position you want to delete");
    int i;
    link *temp = list;
    for ( i = 0; i < n-1; i++)
    {
        if (temp == NULL)
        {
            printf("position error");
        }
        temp = temp->next;//将temp1移至要删除的单元的前一个单元
    }
    link *del = temp->next;
    temp->next = temp->next->next;//使temp直接跳过要删除的单元直接指向下下一单元
    free(del); //释放要删除单元的内存；
    return list;
}