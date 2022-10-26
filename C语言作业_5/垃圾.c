#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
typedef struct node{
    int Type;
    union{
        int ival ;
        double dval ;
    }dat;
    struct node *next ;
}Stack;

Stack *push(Stack *top,int judge,int num,double num_2){
    Stack *p;
    p = (Stack*)malloc(sizeof(Stack));
    //0为int,1为double

    if (judge==0)
    {
        p->dat.ival = num;
        p->Type = 0;
        p->dat.dval = 0.0;
    }else {
        p->dat.dval = num_2; 
        p->Type = 1;
        p->dat.ival = 0;
    }
    p->next = top;
    top = p;
    return top;
}

Stack *Pop(Stack *top){
    Stack*p;
    if (top==NULL)
    {
        return NULL;
    }
    else{
        p = top;
        top = top->next;
        free(p);
    }
    return top;
}


int Opint(int d1,int d2,int op){
    int res;
    switch (op)
    {
    case '+':
        res = d1+d2;
        break;
    
    case '-':
        res = d1-d2;
        break;

    case '*':
        res = d1*d2;
        break;

    case '/':
        res = d1/d2;
        break; 
    default:
        break;
    }
    return res;
}

double Opint_2(double d1,double d2,int op){
    double res;
    switch (op)
    {
    case '+':
        res = d1+d2;
        break;
    
    case '-':
        res = d1-d2;
        break;

    case '*':
        res = d1*d2;
        break;

    case '/':
        res = d1/d2;
        break; 
    default:
        break;
    }
    return res;
}

int intordouble(char a[20]){
    int flag = 0;//是否为浮点数
	for (int i = 0; i < strlen(a)-1; i++) {
		if (a[i] == '.') {//若有小数形式
			flag = 1;//为真
			break;
		}
		else if ((a[i] == 'e' || a[i] == 'E') && a[i + 1] == '-') {//若指数形式
			flag = 1;
			break;
		}
        
	}
    return flag;
}

int main(){
    char word ;
    char str[20];
    Stack *top = NULL;
    int flag = 0;//0为int,1为double
    int num1,num2;
    int num_1,num_2;
    int result_1;
    double result_2;
    int i = 0;
    while (word!='#')
    {
        
   scanf("%c",&word);
	while( isdigit(word) || word=='.'||word==32) {
		str[i++]=word;
		str[i] = '0';
		scanf("%c",&word);

		if(word== 32) {
            
			num_1=atof(str);
            if (num_1-(int)num_1==0)
                {
                    num1 = num_1/10;
                    top = push(top,0,num1,0);
       
                }else  top = push(top,1,num_1,0);
			i=0;
			
		}
	} 
                
                if (top->Type ==0&&top->next->Type==0)
                {
                    num1 = top->dat.ival; 
                    top = Pop(top);
                    num2 = top->dat.ival;
                    top = Pop(top);
                    result_1 = Opint(num1,num2,word);
                    top = push(top,0,result_1,0.0);
                }else if (top->Type ==1&&top->next->Type==1)
                {
                    num_1 = top->dat.dval;
                    top = Pop(top);
                    num_2 = top->dat.dval;
                    top = Pop(top);
                    result_2 = Opint_2(num_1,num_2,word); 
                    top = push(top,1,0,result_2);
                }else if (top->Type ==0&&top->next->Type==1) 
                {
                    num1 = top->dat.ival; 
                    top = Pop(top);
                    num_2 = top->dat.dval;
                    top = Pop(top);
                    result_2 = Opint_2(num1,num_2,word);
                    top = push(top,1,0,result_2);
                }else if (top->Type ==1&&top->next->Type==0) 
                {
                    num_1 = top->dat.dval;
                    top = Pop(top);
                    num2 = top->dat.ival;
                    top = Pop(top);
                    result_2 = Opint_2(num_1,num2,word);
                    top = push(top,1,0,result_2);
                }
            
        }
    
    if (top->dat.ival!=0)
    {
        printf("%d",top->dat.ival);
    }else printf("%lf",top->dat.dval);
    
}