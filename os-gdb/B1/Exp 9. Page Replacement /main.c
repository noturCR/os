#include <stdio.h>

int search(int frame[], int n, int key) {
    for (int i = 0; i < n; i++)
        if (frame[i] == key)
            return i;
    return -1;
}

int main() {
    int refLen, frames;
    printf("Enter the length of reference string: ");
    scanf("%d", &refLen);

    int ref[100];
    printf("Enter the reference string:\n");
    for (int i = 0; i < refLen; i++)
        scanf("%d", &ref[i]);

    printf("Enter the number of frames: ");
    scanf("%d", &frames);

    int frame[10];
    int time[10];
    int pageFaults = 0, counter = 0;

    for (int i = 0; i < frames; i++) {
        frame[i] = -1;
        time[i] = 0;
    }

    printf("\nPage Replacement Process:\n");

    for (int i = 0; i < refLen; i++) {
        int pos = search(frame, frames, ref[i]);
        if (pos == -1) {
            // Page Fault
            int lru = 0;
            for (int j = 1; j < frames; j++)
                if (time[j] < time[lru])
                    lru = j;

            frame[lru] = ref[i];
            time[lru] = counter++;
            pageFaults++;
        } else {
            time[pos] = counter++;
        }

        for (int k = 0; k < frames; k++) {
            if (frame[k] != -1)
                printf("%d ", frame[k]);
            else
                printf("- ");
        }
        printf("\n");
    }

    printf("\nTotal Page Faults = %d\n", pageFaults);
    return 0;
}
