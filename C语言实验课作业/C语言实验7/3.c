#include <stdio.h>
int main()
{
    printf("Input the total number of the students(n<40):\n");
    printf("Input student's ID and score as: MT  EN  PH:\n");
    int n;
    scanf("%d",&n);
    char id[n][10];
    int i,j;

    int p[n][3];
    for(i=0;i<n;i++)
    {
        scanf("%s  %d  %d  %d",&id[i][0],&p[i][0],&p[i][1],&p[i][2]);

    }
    printf("Counting Result:\n");
    printf("Student's ID\t  MT \t  EN \t  PH \t SUM \t AVER\n");
    int sum[n];
    float average[n];
    for(i=0;i<n;i++)
    {
        sum[i]=0;
        sum[i]=p[i][0]+p[i][1]+p[i][2];
        average[i]=1.0*sum[i]/3;
    }
    int soc[3];
    float aoc[3];
    for(i=0;i<3;i++)
    {
        soc[i]=0;
        for(j=0;j<n;j++)
        {
           soc[i]+=p[j][i];

        }
        aoc[i]=1.0*soc[i]/n;
    }
    for(i=0;i<n;i++)
    {
        printf("%12s\t%4d\t%4d\t%4d\t%4d\t%5.1f\n",id[i],p[i][0],p[i][1],p[i][2],sum[i],average[i]);
    }
    printf("SumofCourse \t");
    printf("%4d\t",soc[0]);
    printf("%4d\t",soc[1]);
    printf("%4d\t",soc[2]);
    printf("\nAverofCourse\t");
    printf("%4.1f\t",aoc[0]);
    printf("%4.1f\t",aoc[1]);
    printf("%4.1f\t",aoc[2]);


    return 0;
}

