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
//构建双向链表
link *(creatlist)(int n){
    link *head , *node ,*con,*last;
    head = (link*)malloc(sizeof(link));
    head->ic.elem = 1;
    head->front = NULL;
    con = head;
    int i;
    int a;
    for ( i = 0; i < n-1; i++)
    {
        fflush(stdin);
        node = (link*)malloc(sizeof(link));
        printf("Please choose the type you want to input\n");
        scanf("%c",&node->choose);
        fflush(stdin);
        if (node->choose=='i')//多数据类型输入
        {
            printf("Please input a number\n");
            scanf("%d",&node->ic.elem);
        }else{
            printf("Please input a character\n");
            scanf("%c",&node->ic.ch);
            fflush(stdin);
        }
        con->next = node;
        node->front = con;//首尾相连
        con = node;
        
    }
    con->next = NULL;
    return head;
}

//head函数
link *head(link*linked_list){
    link *head = linked_list;
    while(head->front != NULL){
        head = head->front;
    }
    return head;
}

link *tail(link*linked_list){
    link *tail;
    tail = linked_list;
    do
    {
        tail = tail->next;
    } while (tail->next !=NULL );
    return tail;
}

//size函数
int size(link*linked_list){
    int count=1;
    link *temp = head(linked_list);
    do
    {
        count++;
        temp = temp->next;
    } while (temp->next != NULL);
    return count;
}

//find函数
link *find(link*linked_list,int index){
    link*temp = head(linked_list);
    int i;
    if (index<size(linked_list)/2)
    {
        for ( i = 0; i < index-1; i++)
        {
            temp = temp->next;
        }
    }else{
        temp = tail(linked_list);
        for ( i = 0; i < size(linked_list)-index; i++)
        {
            temp = temp->front;
        }
    }
    return temp;
}

//insert函数
link *insert(link*linked_list,int index){
    link *insert;
    insert = (link*)malloc(sizeof(link));
    link *fronttemp = find(linked_list,index);
    link *lasttemp = find(linked_list,index+1);
    link *re;
    fflush(stdin);
    printf("Please input the number you want to insert");
    scanf("%d",&insert->ic.elem);
    fronttemp->next = insert;
    insert->front = fronttemp;
    insert->next = lasttemp;
    lasttemp->front = insert;
    re = head(linked_list);
    return re;
}

//delete函数
link *del(link* linked_list,int index){
    link *del = head(linked_list);
    link *re;
    link *fronttemp;
    link *lasttemp;
    if (index==1)
    {
        link *fronttemp = find(linked_list,index);
        link *lasttemp = find(linked_list,index+1);
        lasttemp->front = NULL;
        fronttemp->next =NULL;
        re = lasttemp;
        free(fronttemp);
    }else if (index == size(linked_list))
    {
        link *fronttemp = find(linked_list,index-1);
        link *lasttemp = find(linked_list,index);
        fronttemp->next = NULL;
        lasttemp->front = NULL;
        re = head(fronttemp);
    }else{
        del = find(linked_list,index);
        link *fronttemp = find(linked_list,index-1);
        link *lasttemp = find(linked_list,index+1);
        fronttemp->next = fronttemp->next->next;
        lasttemp->front = lasttemp->front->front;
        free(del);
        re = head(fronttemp);
    }
    return re;
    
}
int main(){
    link*list = creatlist(4);
    link*st;
    st = list;
    printf("%d\n",st->ic.elem);
    st = st->next;
    printf("%d\n",st->ic.elem);
    st = head(list);
    printf("%d\n",st->ic.elem);
    printf("%d\n",size(list));
    st = head(st);
    link*third;
    third = find(st,3);
    printf("%d\n",third->ic.elem);
    st = del(st,2);
    printf("%d\n",size(st));
    st = insert(st,2);
    printf("%d\n",size(st));
    printf("%d\n",find(st,3)->ic.elem);

}