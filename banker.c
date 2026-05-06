// Banker's Algorithm (Deadlock Avoidance)
#include <stdio.h>

int main() {
    int n = 5, m = 3;

    int alloc[5][3] = {
        {0,1,0},
        {2,0,0},
        {3,0,2},
        {2,1,1},
        {0,0,2}
    };

    int max[5][3] = {
        {7,5,3},
        {3,2,2},
        {9,0,2},
        {2,2,2},
        {4,3,3}
    };

    int avail[3] = {3,3,2};

    int need[5][3];
    int finish[5] = {0};
    int safeSeq[5];

    // Calculate Need matrix
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            need[i][j] = max[i][j] - alloc[i][j];

    int count = 0;

    while(count < n) {
        for(int i = 0; i < n; i++) {
            if(!finish[i]) {
                int possible = 1;

                for(int j = 0; j < m; j++) {
                    if(need[i][j] > avail[j]) {
                        possible = 0;
                        break;
                    }
                }

                if(possible) {
                    safeSeq[count++] = i;
                    for(int j = 0; j < m; j++)
                        avail[j] += alloc[i][j];

                    finish[i] = 1;
                }
            }
        }
    }

    printf("Safe Sequence:\n");
    for(int i = 0; i < n; i++)
        printf("P%d ", safeSeq[i]);

    return 0;
}