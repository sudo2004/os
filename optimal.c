#include <stdio.h>

int main() {
    int pages[50], frames[10];
    int n, f, i, j, k;
    int page_faults = 0;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter page reference string:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("Enter number of frames (min 3): ");
    scanf("%d", &f);

    // Initialize frames
    for(i = 0; i < f; i++)
        frames[i] = -1;

    for(i = 0; i < n; i++) {
        int found = 0;

        // Check HIT
        for(j = 0; j < f; j++) {
            if(frames[j] == pages[i]) {
                found = 1;
                break;
            }
        }

        // PAGE FAULT
        if(!found) {
            int pos = -1, farthest = i + 1;

            for(j = 0; j < f; j++) {
                int k;
                for(k = i + 1; k < n; k++) {
                    if(frames[j] == pages[k])
                        break;
                }

                // If page not used in future
                if(k == n) {
                    pos = j;
                    break;
                }

                // Choose farthest used page
                if(k > farthest) {
                    farthest = k;
                    pos = j;
                }
            }

            // If no farthest found, replace first
            if(pos == -1)
                pos = 0;

            frames[pos] = pages[i];
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