#include <stdio.h>

#define MAX 10

typedef struct {
    int id;
    int period;
    int execution;
    int remaining;
    int next_arrival;
} Process;

// Function to calculate GCD
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}


int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

int main() {
    int n, time = 0, hyperperiod = 0;

    Process p[MAX];

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        p[i].id = i + 1;
        printf("Enter period and execution time for P%d: ", p[i].id);
        scanf("%d %d", &p[i].period, &p[i].execution);

        p[i].remaining = 0;
        p[i].next_arrival = 0;
    }

    // Calculate hyperperiod (LCM of all periods)
    hyperperiod = p[0].period;
    for (int i = 1; i < n; i++) {
        hyperperiod = lcm(hyperperiod, p[i].period);
    }

    printf("\nTime\tRunning Process\n");

    for (time = 0; time < hyperperiod; time++) {

        // Check arrivals
        for (int i = 0; i < n; i++) {
            if (time == p[i].next_arrival) {
                p[i].remaining = p[i].execution;
                p[i].next_arrival += p[i].period;
            }
        }

        int selected = -1;
        int min_period = 9999;

        for (int i = 0; i < n; i++) {
            if (p[i].remaining > 0 && p[i].period < min_period) {
                min_period = p[i].period;
                selected = i;
            }
        }

        if (selected != -1) {
            printf("%d\tP%d\n", time, p[selected].id);
            p[selected].remaining--;
        } else {
            printf("%d\tIdle\n", time);
        }
    }

    return 0;
}
