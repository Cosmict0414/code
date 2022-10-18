#include<stdio.h>
#define N  40;
int readscore(int score[],int P){
    int i = -1;
    int j;
    int sum = 0,count = 0;
    int average;
    do
    {
        i++;
        printf("Input score:");
        scanf("%d",&score[i]);
        sum+=score[i];
    } while (score[i]>=0);
    average = (sum-score[i])/i;
    for ( j = 0; j < i; j++)
    {
        if (score[j]>average)
        {
            count++;
        }
        
    }
    return count;
}
int main(){
    int P;
    int score[40];
    P = readscore(score,P);
    printf("高于平均分的人数为%d\n",P);
}