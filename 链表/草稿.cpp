#include<cstdio>
#include<iostream>
typedef struct linked_list{
    struct linked_list *front;//头部指针，指向前一个单元
    char choose;
    union{
        int elem;
        char ch;

    }ic;
    struct linked_list *next;//尾部指针指向后一个单元
}link;
link *(creatlist)(int n){
    link *head , *node ,*con,*last;
    head = (link*)malloc(sizeof(link));
    head->front = NULL;
    con = head;
    int i;
    int a;
    for ( i = 0; i < n; i++)
    {
        fflush(stdin);
        node = (link*)malloc(sizeof(link));
        printf("Please choose the type you want to input\n");
        scanf("%c",&node->choose);
        fflush(stdin);
        if (node->choose=='i')
        {
            printf("Please input a number\n");
            scanf("%d",&node->ic.elem);
            printf("%d\n",node->ic.elem);
        }else{
            printf("Please input a character\n");
            scanf("%c",&node->ic.ch);
            fflush(stdin);
            printf("%d\n",node->ic.ch);
        }
        con->next = node;
        node->front = con;//首尾相连
        con = node;
        
    }
    con->next = NULL;
    return head;
}
int main(){
    link *head,*temp,*end;
    head = creatlist(2);
    temp = head;
    temp = temp->next;
    printf("%d\n",temp->ic.elem);

}