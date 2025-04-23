#include <stdio.h>
#include <conio.h>

int search(int frame[], int n, int key) {
    int i;
    for (i = 0; i < n; i++)
        if (frame[i] == key)
            return i;
    return -1;
}

void main() {
    int refLen, frames, i, j, pos, counter = 0, pageFaults = 0;
    int ref[100], frame[10], time[10];

    clrscr();

    printf("Enter the length of reference string: ");
    scanf("%d", &refLen);

    printf("Enter the reference string:\n");
    for (i = 0; i < refLen; i++)
        scanf("%d", &ref[i]);

    printf("Enter the number of frames: ");
    scanf("%d", &frames);

    for (i = 0; i < frames; i++) {
        frame[i] = -1;
        time[i] = 0;
    }

    printf("\nPage Replacement Process:\n");

    for (i = 0; i < refLen; i++) {
        pos = search(frame, frames, ref[i]);
        if (pos == -1) {
            int lru = 0;
            for (j = 1; j < frames; j++)
                if (time[j] < time[lru])
                    lru = j;

            frame[lru] = ref[i];
            time[lru] = counter++;
            pageFaults++;
        } else {
            time[pos] = counter++;
        }

        for (j = 0; j < frames; j++) {
            if (frame[j] != -1)
                printf("%d ", frame[j]);
            else
                printf("- ");
        }
        printf("\n");
    }

    printf("\nTotal Page Faults = %d\n", pageFaults);

    getch();
}
