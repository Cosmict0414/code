#include<stdio.h>
int hour,minute,second;
void update(){
    second++;
    if (second==60)
    {
        second =0;
        minute++;
    }
    if (minute ==60)
    {
        minute =0;
        hour++;
    }
    if (hour ==24)
    {
        hour = 0;
    }
}
void display()
    {
        printf("%d %d %d\n",hour,minute,second);
    }
void delay(){
    int t;
    for ( t = 0; t < 1000000000; t++);
}
int main(){
    int i;
    second =0;
    for ( i = 0; i < 10000; i++)
    {
        update();
        display();
        delay();
    }
    return 0;
}