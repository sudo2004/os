#include <stdio.h>
#include <stdlib.h>

int main() {
    int req[50], temp, n, head, size;
    int total_seek = 0, i, j;

    printf("Enter number of requests: ");
    scanf("%d", &n);

    printf("Enter request queue:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &req[i]);

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("Enter disk size: ");
    scanf("%d", &size);

    // Sort requests
    for(i = 0; i < n - 1; i++) {
        for(j = i + 1; j < n; j++) {
            if(req[i] > req[j]) {
                temp = req[i];
                req[i] = req[j];
                req[j] = temp;
            }
        }
    }

    // Find head position index
    int index;
    for(i = 0; i < n; i++) {
        if(req[i] >= head) {
            index = i;
            break;
        }
    }

    printf("\nSeek Sequence: %d", head);

    // Move RIGHT (away from spindle)
    for(i = index; i < n; i++) {
        total_seek += abs(head - req[i]);
        head = req[i];
        printf(" -> %d", head);
    }

    // Go to end of disk
    total_seek += abs(head - (size - 1));
    head = size - 1;
    printf(" -> %d", head);

    // Reverse direction (LEFT)
    for(i = index - 1; i >= 0; i--) {
        total_seek += abs(head - req[i]);
        head = req[i];
        printf(" -> %d", head);
    }

    printf("\nTotal Seek Time = %d\n", total_seek);

    return 0;
}