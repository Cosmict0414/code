#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
struct Cards{
    char suit[10];
    char face[10];

}card[52] = {
    {"Spades","A"},{"Spades","2"},{"Spades","3"},{"Spades","4"},{"Spades","5"},{"Spades","6"},{"Spades","7"},{"Spades","8"},{"Spades","9"},{"Spades","10"},{"Spades","Jack"},{"Spades","Queen"},{"Spades","King"},
    {"Hearts","A"},{"Hearts","2"},{"Hearts","3"},{"Hearts","4"},{"Hearts","5"},{"Hearts","6"},{"Hearts","7"},{"Hearts","8"},{"Hearts","9"},{"Hearts","10"},{"Hearts","Jack"},{"Hearts","Queen"},{"Hearts","King"},
    {"Clubs","A"},{"Clubs","2"},{"Clubs","3"},{"Clubs","4"},{"Clubs","5"},{"Clubs","6"},{"Clubs","7"},{"Clubs","8"},{"Clubs","9"},{"Clubs","10"},{"Clubs","Jack"},{"Clubs","Queen"},{"Clubs","King"},
    {"Diamonds","A"},{"Diamonds","2"},{"Diamonds","3"},{"Diamonds","4"},{"Diamonds","5"},{"Diamonds","6"},{"Diamonds","7"},{"Diamonds","8"},{"Diamonds","9"},{"Diamonds","10"},{"Diamonds","Jack"},{"Diamonds","Queen"},{"Diamonds","King"},
};
int judge(int *p,int num,int place){
    int i;
    for ( i = 0; i < 52; i++)
    {
        if (i == place)
        {
            continue;
        }else if (p[i]==num)
        {
            return 0; break;
        }
    }
    return 1;
}

int main(){
    srand((unsigned)time(NULL));
    int URN[52] = {0};
    URN[0] = rand()%53;
    int sum = 1;
    int i;
    int temp;
    int flag = 0;//1表示没有重复
    for ( i = 1; i < 52; i++)
    {
        URN[i] = rand()%53;
        if (judge(URN,URN[i],i)==0)
        {
            i--;
        }else {continue;};
    }
    // for ( i = 0; i < 52; i++)
    // {
    //     printf("%d\n",URN[i]);
    // }
    
    for ( i = 0; i < 17; i++)
    {
        printf("(%8s%5s)\t",card[URN[i]].suit,card[URN[i]].face);
    }
    printf("\n");
    for ( ; i < 34; i++)
    {
        printf("[%8s%5s\t]",card[URN[i]].suit,card[URN[i]].face);
    }
    printf("\n");
    for (; i < 52; i++)
    {
        printf("{%8s%5s\t}",card[URN[i]].suit,card[URN[i]].face);
    }
    printf("\n");
}