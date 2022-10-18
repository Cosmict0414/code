#include<stdio.h>
#define N 40
int Readscore(int score[],long num[]);
void Datasort(int score[],long num[],int n);
void Printscore(int score[],long num[],int n);
int main(void){
    int score[N],n;
    long num[N];
    n = Readscore(score,num);
    printf("Total students are %dd\n",n);
    Datasort(score,num,n);
    printf("Sorted scores:\n");
    Printscore(score,num,n);
    return 0;
    }
int Readscore(int score[],long num[]){
    int i = -1;
    do
    {
        i++;
        printf("Input student's ID and score:");
        scanf("%ld%d",&num[i],&score[i]);
    } while (num[i]>0&&score[i]>=0);
    return i;

} 
void Datasort(int score[],long num[],int n){
    int i,j;
    int temp1,temp2;
    for ( i = 0; i < n-1; i++)
    {
        for ( j = 0; j < n-i-1; j++)
        {
            if (score[j]>score[j+1])
            {
                temp1 = score[j+1];
                temp2 = num[j+1];
                score[j+1] = score[j];
                num[j+1] = num[j];
                score[j] = temp1;
                num[j] = temp2;
            }
            
        }
        
    }
    
}
void Printscore(int score[],long num[],int n){
    int i;
    for ( i = n-1; i >=0; i--)
    {
        printf("%10ld%4d\n",num[i],score[i]);
    }
    
}