#include<iostream>
#include<cstdio>
using namespace std;

typedef struct LinkedList//"typedef"意为重命名，可以简化之后的定义结构体的步骤
{   
    char select;
    struct LinkedList *next;//定义一个结构体指针，可以指向一个结构体
    union{
    int elem;
    char ch;//多类型输入
    }ic;
}link;//定义一个结构体包含一个数据区域与一个指针区域

link *creatlink(int n){
    link *linked_list ,*node, *end;
    int i,a;
    linked_list = (link*)malloc(sizeof(link));
    linked_list->ic.elem = 1;
    end  = linked_list;
    for ( i = 0; i <n-1; i++)
    {
        fflush(stdin);
        node = (link*)malloc(sizeof(link));
        printf("please choose the type you want to input\n");
        scanf("%c",&node->select);
        if (node->select =='i')
        {

            printf("Input a number\n");
            scanf("%d",&node->ic.elem);
        }else{

            printf("Input a character\n");
            scanf("%c",&node->ic.ch);//构建链表时的输入类型选择
        }
        end->next = node;
        end = node;
    }
    end->next = NULL;
    return linked_list;
}

link* push(link *linked_list,int n){
    link *insert;
    insert = (link*)malloc(sizeof(link));
    insert->ic.elem = n;
    insert->next = linked_list;
    return insert;

}
link* pop(link *linked_list){
    link *del = linked_list;
    linked_list = linked_list->next;
    free(del);
    return linked_list;
}
int size(link *linked_list){
    link *temp = linked_list;
    int count = 1;
    int i;
    do
    {
        count++;
        temp = temp->next;
    } while (temp->next != NULL);  
    return count;
}
int main(){
    link *head = creatlink(6);
    link *temp = head;
    int i;
    temp = head;
    printf("%d\n",temp->ic.elem);
    printf("%d\n",size(temp));
    temp = pop(temp);
    printf("%d\n",temp->ic.elem);
    printf("%d\n",size(temp));
    temp = push(temp,1);
    printf("%d\n",temp->ic.elem);
    printf("%d\n",size(temp));
}