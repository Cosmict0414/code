#include <stdio.h>
#include <string.h>

int main()
{
    int i;
    char str[80],max[80];
    printf("Input 5 strings:\n");
    scanf("%s",str);
    strcpy(max,str); 
    for(i=1;i<5;i++)
    {
        scanf("%s",str);
        if(*max<*str)   
            strcpy(max,str);
    }
    printf("Max is %s \n",max);
    return 0;
}
