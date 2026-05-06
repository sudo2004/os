#include <stdio.h>
#include <stdlib.h>

int main() {
    int req[50], n, head, i, j, temp;
    int total_seek = 0;

    printf("Enter number of requests: ");
    scanf("%d", &n);

    printf("Enter request queue:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &req[i]);

    printf("Enter initial head position: ");
    scanf("%d", &head);

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

    // Find index where head fits
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

    // Jump to lowest request (circular)
    if(index > 0) {
        total_seek += abs(head - req[0]);
        head = req[0];
        printf(" -> %d", head);
    }

    // Continue from lowest up to just before index
    for(i = 0; i < index; i++) {
        total_seek += abs(head - req[i]);
        head = req[i];
        printf(" -> %d", head);
    }

    printf("\nTotal Seek Time = %d\n", total_seek);

    return 0;
}