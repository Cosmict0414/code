#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
typedef struct node{
    int Type;
    union{
        int ival[1] ;
        double dval[1] ;
    }dat;
    struct node *next ;
}Stack;

Stack *push(Stack *top,int judge,int num,double num_2){
    Stack *p;
    p = (Stack*)malloc(sizeof(Stack));
    //0为int,1为double

    if (judge==0)
    {
        p->dat.ival[0] = num;
        p->Type = 0;
        p->dat.dval[0] = 0.0;
    }else {
        p->dat.dval[0] = num_2; 
        p->Type = 1;
        p->dat.ival[0] = 0;
    }
    p->next = top;
    top = p;
    return top;
}

int main(){
    Stack *top = (Stack*)malloc(sizeof(Stack*));
    top = push(top,0,1,1);
    printf("%d ",top->dat.ival[0]);
}