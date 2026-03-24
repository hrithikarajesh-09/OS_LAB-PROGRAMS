#include<stdio.h>
typedef struct {
int pid;
int at;
int bt;
int type;
int ct;
int tat;
int wt;
int start;
}Process;
void sortbyArrival(Process p[], int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(p[i].at>p[j].at)
            {
                int temp =p[i].at;
                p[i].at =  p[j].at;
                p[j].at = temp;
            }
        }
    }
}
void executeFCFS(Process p[], int n, int *time) {
    for (int i = 0; i < n; i++) {
        if (*time < p[i].at) {
            *time = p[i].at;
        }
        p[i].start = *time;
        *time += p[i].bt;
        p[i].ct = *time;
        p[i].tat = p[i].ct - p[i].at;
        p[i].wt = p[i].tat - p[i].bt;
    }
}
int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    Process all[n], sys[n], user[n];
    int sysCount = 0, userCount = 0;


    for (int i = 0; i < n; i++) {
        printf("\nEnter details for Process %d\n", i+1);
        printf("PID: ");
        scanf("%d", &all[i].pid);
        printf("Arrival Time: ");
        scanf("%d", &all[i].at);
        printf("Burst Time: ");
        scanf("%d", &all[i].bt);
        printf("Type (0=System, 1=User): ");
        scanf("%d", &all[i].type);

        if (all[i].type == 0) {
            sys[sysCount++] = all[i];
        } else {
            user[userCount++] = all[i];
        }
    }

    sortbyArrival(sys, sysCount);
    sortbyArrival(user, userCount);

    int time = 0;

    executeFCFS(sys, sysCount, &time);

    executeFCFS(user, userCount, &time);

    for (int i = 0; i < sysCount; i++) {
        for (int j = 0; j < n; j++) {
            if (all[j].pid == sys[i].pid) {
                all[j] = sys[i];
            }
        }
    }
    for (int i = 0; i < userCount; i++) {
        for (int j = 0; j < n; j++) {
            if (all[j].pid == user[i].pid) {
                all[j] = user[i];
            }
        }
    }


    printf("\nPID\tAT\tBT\tTYPE\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%s\t%d\t%d\t%d\n",
               all[i].pid, all[i].at, all[i].bt,
               (all[i].type==0 ? "System" : "User"),
               all[i].ct, all[i].tat, all[i].wt);
    }

    return 0;
}
