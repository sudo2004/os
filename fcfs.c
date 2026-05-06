#include <stdio.h>

int main() {
    int pages[50], frames[10];
    int n, f, i, j, k, flag, page_faults = 0, index = 0;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter page reference string:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("Enter number of frames (min 3): ");
    scanf("%d", &f);

    // Initialize frames as empty
    for(i = 0; i < f; i++)
        frames[i] = -1;

    for(i = 0; i < n; i++) {
        flag = 0;

        // Check if page already in frame (HIT)
        for(j = 0; j < f; j++) {
            if(frames[j] == pages[i]) {
                flag = 1;
                break;
            }
        }

        // If not found → PAGE FAULT
        if(flag == 0) {
            frames[index] = pages[i];
            index = (index + 1) % f;
            page_faults++;
        }

        // Display frames
        printf("\nFrames: ");
        for(k = 0; k < f; k++) {
            if(frames[k] != -1)
                printf("%d ", frames[k]);
            else
                printf("- ");
        }
    }

    printf("\n\nTotal Page Faults = %d\n", page_faults);
    return 0;
}