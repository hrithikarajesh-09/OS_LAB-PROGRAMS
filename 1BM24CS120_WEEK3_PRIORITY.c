#include<stdio.h>

int main() {
    int n, i, j, completed = 0, time = 0;

    int AT[10], BT[10], CT[10], Pr[10], Vis[10] = {0}, TAT[10], WT[10];

    printf("Enter number of processes (max 10): ");
    scanf("%d", &n);

    for(i=0; i<n; i++) {
        printf("Enter the Arrival Time, Burst Time and Priority for process %d: ", i+1);
        scanf("%d%d%d", &AT[i], &BT[i], &Pr[i]);
        Vis[i] = 0;
    }

    printf("\nProcess scheduling started...\n");

    while(completed < n) {
        int highestPri = 9999;
        int idx = -1;


        for(i=0; i<n; i++) {
            if(AT[i] <= time && Vis[i] == 0) {
                if(Pr[i] < highestPri) {
                    highestPri = Pr[i];
                    idx = i;
                } else if(Pr[i] == highestPri) {

                    if(idx == -1 || AT[i] < AT[idx]) {
                         idx = i;
                    }
                }
            }
        }

        if(idx != -1) {

            Vis[idx] = 1;
            completed++;
            time += BT[idx];
            CT[idx] = time;
        } else {
            time++;
        }
    }


    for(i=0; i<n; i++) {
        TAT[i] = CT[i] - AT[i];
        WT[i] = TAT[i] - BT[i];
    }

    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    for(i=0; i<n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", i+1, AT[i], BT[i], CT[i], TAT[i], WT[i]);
    }

    return 0;
}
