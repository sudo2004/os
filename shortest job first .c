#include <stdio.h>

int main() {
    int n, i, time = 0, count = 0, smallest;
    int at[10], bt[10], rt[10];
    float wt = 0, tat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("Enter Arrival Time and Burst Time for P%d: ", i+1);
        scanf("%d %d", &at[i], &bt[i]);
        rt[i] = bt[i];   // remaining time
    }

    rt[n] = 9999;  // dummy large value

    printf("\nProcess Execution Order:\n");

    for(time = 0; count != n; time++) {
        smallest = n;

        for(i = 0; i < n; i++) {
            if(at[i] <= time && rt[i] < rt[smallest] && rt[i] > 0) {
                smallest = i;
            }
        }

        rt[smallest]--;

        if(rt[smallest] == 0) {
            count++;
            int end = time + 1;

            wt += end - at[smallest] - bt[smallest];
            tat += end - at[smallest];

            printf("P%d finished at time %d\n", smallest + 1, end);
        }
    }

    printf("\nAverage Waiting Time = %.2f", wt / n);
    printf("\nAverage Turnaround Time = %.2f\n", tat / n);

    return 0;
}
