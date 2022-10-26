#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>

#define STACK_INIT_SIZE 200
#define STACKINCREMENT 100

typedef double Elemtype;
typedef struct {
	Elemtype *base;
	Elemtype *top;
	int stackSize;
	
}sqStack;

void InitStack (sqStack *s) {
	s->base =(Elemtype *)malloc (STACK_INIT_SIZE * sizeof(Elemtype));//构建一定容量的栈
	s->top =s->base ;//指向栈顶的指针
	s->stackSize =STACK_INIT_SIZE;
	
}//初始化栈

void Push (sqStack *s, Elemtype e) {
	if(s->top -s->base  >=s->stackSize )  {
		s->base = (Elemtype *)realloc (s->base ,(s->stackSize +STACKINCREMENT* sizeof(Elemtype)));//栈大小不够，再一次分配内存
	}
	
	*(s->top )=e;//对栈的该位置赋值
	s->top ++;//指向下一个栈的位置,即top指向的位置没有值
	
}

void Pop(sqStack *s,Elemtype *e) {
	if(s->top ==s->base ) return ;
	*e= *--(s->top) ;//弹出栈顶元素
	
}

int StackLen (sqStack s) {
	return (s.top - s.base );
	
}

int main() {
	sqStack s;
	char c;
	double d,e;
	char str[STACKINCREMENT];
	int i=0;
	
 	InitStack (&s);
	printf("请按逆波兰表达式输入计算数据,用空格隔开,以“#”结束\n");
	scanf("%c",&c);
	while(c!='#') {
		while( isdigit(c) || c=='.') {
			str[i++]=c;
			str[i]='\0';
			
			scanf("%c",&c);
			if(c==' ') {
				d=atof(str);
				Push(&s,d);
				i=0;
				break;
			}
		} 
		switch (c) {
			case '+':
   				    Pop(&s,&e);
					Pop(&s,&d);
					Push(&s,d+e);
					break;
			case'-':
				    Pop(&s,&e);
				    Pop(&s,&d);
				    Push(&s,d-e);
				    break;
            case'*':
            	Pop(&s,&e);
            	Pop(&s,&d);
            	Push(&s,d *e);
            	break;
           	case'/':
           		Pop(&s,&e);
            	Pop(&s,&d);
            	if(e!=0) {
            		Push(&s,d/e);
				}
            	else {
            		printf("除数是0!\n");
            		return -1;
            		
				}
				break;	 
		}
		scanf("%c",&c);
		
	}
	Pop(&s,&d);
	
	printf("最终结果为 %f\n",d);

}
