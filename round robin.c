#include <stdio.h>

int main() {
    int n, tq;
    int at[10], bt[10], rt[10];
    int time = 0, completed = 0;

    float total_wt = 0, total_tat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter Arrival Time and Burst Time for P%d: ", i + 1);
        scanf("%d %d", &at[i], &bt[i]);
        rt[i] = bt[i]; // remaining time
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &tq);

    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");

    while (completed < n) {
        int executed = 0;

        for (int i = 0; i < n; i++) {
            if (at[i] <= time && rt[i] > 0) {
                executed = 1;

                if (rt[i] > tq) {
                    time += tq;
                    rt[i] -= tq;
                } else {
                    time += rt[i];

                    int ct = time;
                    int tat = ct - at[i];
                    int wt = tat - bt[i];

                    total_tat += tat;
                    total_wt += wt;

                    printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
                           i + 1, at[i], bt[i], ct, tat, wt);

                    rt[i] = 0;
                    completed++;
                }
            }
        }

        // If no process was executed, move time forward
        if (!executed) {
            time++;
        }
    }

    printf("\nAverage Waiting Time = %.2f", total_wt / n);
    printf("\nAverage Turnaround Time = %.2f\n", total_tat / n);

    return 0;
}
