#include <stdio.h>

int main() {
    int pages[50], frames[10], time[10];
    int n, f, i, j, k;
    int page_faults = 0, counter = 0;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter page reference string:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("Enter number of frames (min 3): ");
    scanf("%d", &f);

    // Initialize frames
    for(i = 0; i < f; i++) {
        frames[i] = -1;
        time[i] = 0;
    }

    for(i = 0; i < n; i++) {
        int found = 0;

        // Check HIT
        for(j = 0; j < f; j++) {
            if(frames[j] == pages[i]) {
                counter++;
                time[j] = counter;  // update recent use
                found = 1;
                break;
            }
        }

        // PAGE FAULT
        if(!found) {
            int min = time[0], pos = 0;

            // Find least recently used
            for(j = 1; j < f; j++) {
                if(time[j] < min) {
                    min = time[j];
                    pos = j;
                }
            }

            frames[pos] = pages[i];
            counter++;
            time[pos] = counter;
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
