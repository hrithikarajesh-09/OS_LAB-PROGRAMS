#include<stdio.h>
void main(){
int n,i,completed=0,time=0;
printf("Enter the number of processes: ");
scanf("%d",&n);
int P[n],AT[n],BT[n],CT[n],TAT[n],WT[n],vis[n];
for(i=0;i<n;i++){
vis[i]=0;
}
for(i=0;i<n;i++)
{
printf("Enter the Process_Id, Arrival Time and Burst time :\n");
scanf("%d%d%d",&P[i],&AT[i],&BT[i]);
}
while(completed<n)
{
    int smallest=-1;
    for(i=0;i<n;i++)
    {
        if(AT[i]<=time && vis[i]==0)
        {
            if(smallest==-1||BT[i]<BT[smallest])
            {
                smallest =i;
            }
        }
    }
    if(smallest==-1)
    {
        time++;
    }
    else{
    time+=BT[smallest];
    CT[smallest]=time;
    TAT[smallest]=CT[smallest]-AT[smallest];
    WT[smallest]=TAT[smallest]-BT[smallest];
    completed++;
    vis[smallest]=1;
    }
}
printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
for(i=0;i<n;i++)
{
    printf("%d\t%d\t%d\t%d\t%d\t%d\n",P[i],AT[i],BT[i],CT[i],TAT[i],WT[i]);
}

}
