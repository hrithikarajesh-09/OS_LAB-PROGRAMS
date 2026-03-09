#include<stdio.h>
void main()
{
    int n,i,j;
    printf("Enter the number of processes: ");
    scanf("%d",&n);
    int P[n],AT[n],BT[n],CT[n],TAT[n],WT[n];
    for(i=0;i<n;i++)
    {
        printf("Enter Process_ID, Arrival Time and Burst Time :\n");
        scanf("%d%d%d",&P[i],&AT[i],&BT[i]);
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(AT[j]>AT[j+1])
            {
                int temp = AT[j];
                AT[j]=AT[j+1];
                AT[j+1] = temp;

                 temp = BT[j];
                BT[j]=BT[j+1];
                BT[j+1] = temp;

                temp = P[j];
                P[j]=P[j+1];
                P[j+1] = temp;


            }
        }
    }
    CT[0]=AT[0]+BT[0];
    for(i=1;i<n;i++)
    {
        if(CT[i-1]<AT[i])
        {
            CT[i]=AT[i]+BT[i];
        }
        else{
            CT[i]=CT[i-1]+BT[i];
        }
    }
    for(i=0;i<n;i++)
    {
        TAT[i]=CT[i]-AT[i];
        WT[i]=TAT[i]-BT[i];
    }
    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",P[i],AT[i],BT[i],CT[i],TAT[i],WT[i]);
    }
}
