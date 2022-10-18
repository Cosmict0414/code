#include<stdio.h>
int print(int *arr,int count){
    int i;
    for ( i = 0; i < count; i++)
    {
        printf("%d\t",arr[i]);
    }
    return 0;
}
int main (){
    int arr[100];
    int i = 0;//表示元素个数
    int j = 0;
    int n;
    int a = 0;
    int temp;
    printf("请输入一个升序数组\n");
    do
    {
        printf("输入一个数字\t");
        scanf("%d",&arr[i]);
        i++;
    } while (getchar() !=',');//输入逗号表示停止输入
    i--;
    printf("请输入一个数\n");
    fflush(stdin);
    scanf("%d",&a);
    if (arr[0]>a)
    {
        printf("%d",a);
        print(arr,i);
    }else if(arr[i-1]<a){
        arr[i] = a;
        print(arr,i+1);
    }else
    {
    
        for ( j = 1; j < i; j++)
        {
            if (arr[j]>a)
            {
                temp = arr[i];
                for ( n = i; n >j; n--)
                {
                    arr[n] = arr[n-1];
                }
                arr[j] = a;
                print(arr,i+1);
                break;
            }      
        }
    }
}