#include <stdio.h>
#include <stdlib.h>

int main() {
    int req[50], visited[50] = {0};
    int n, head, i, total_seek = 0;

    printf("Enter number of requests: ");
    scanf("%d", &n);

    printf("Enter request queue:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &req[i]);

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("\nSeek Sequence: %d", head);

    for(int count = 0; count < n; count++) {
        int min = 100000, index = -1;

        for(i = 0; i < n; i++) {
            if(!visited[i]) {
                int dist = abs(head - req[i]);
                if(dist < min) {
                    min = dist;
                    index = i;
                }
            }
        }

        visited[index] = 1;
        total_seek += min;
        head = req[index];

        printf(" -> %d", head);
    }

    printf("\nTotal Seek Time = %d\n", total_seek);

    return 0;
}