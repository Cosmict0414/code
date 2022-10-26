#include<stdio.h>
void FastCollat(int *p,int left ,int right){
    if (left>=right)//要写为 >= 否则会把栈爆掉
    {
        return;
    }
    
    int pivot = p[left];//设定起始左侧值为标准值
    int i = left;
    int j = right;
    while (i<j)
    {
        while (i<j&&p[j]>=pivot)
            j--;
            p[i] = p[j];

        while (i<j&&p[i]<pivot)
            i++;
            p[j] = p[i];
        
    }
    p[i] = pivot;
    
    FastCollat(p,left,i-1);
    FastCollat(p,i+1,right);
}

int main(){
    int arr[20] = {17,22,14,61,23,53,31,45,33,59,71,96,85,52,26,54,75,40,92,55};
    FastCollat(arr,0,19);
    int i;
    for ( i = 0; i < 20; i++)
    {
        printf("%d,",arr[i]);
    }
    
}