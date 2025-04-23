#include <stdio.h>
#include <stdlib.h>

#define MAX 20

// FIFO Page Replacement
int fifo(int pages[], int n, int frames) {
    int mem[MAX], i, j, k = 0, faults = 0, hits = 0;
    
    for (i = 0; i < frames; i++)
        mem[i] = -1;

    printf("\nFIFO Process:\n");

    for (i = 0; i < n; i++) {
        int found = 0;

        // Check if page already in memory
        for (j = 0; j < frames; j++) {
            if (mem[j] == pages[i]) {
                found = 1;
                hits++;
                break;
            }
        }

        // Page fault occurs
        if (!found) {
            mem[k] = pages[i];
            k = (k + 1) % frames;
            faults++;

            // Show memory state
            printf("Page %d -> ", pages[i]);
            for (j = 0; j < frames; j++)
                if (mem[j] == -1) printf("- ");
                else printf("%d ", mem[j]);
            printf("\n");
        }
    }

    printf("FIFO Page Hits: %d, Page Faults: %d\n", hits, faults);
    return faults;
}

// LRU Page Replacement
int lru(int pages[], int n, int frames) {
    int mem[MAX], recent[MAX], i, j, faults = 0, hits = 0;

    for (i = 0; i < frames; i++) {
        mem[i] = -1;
        recent[i] = -1;
    }

    printf("\nLRU Process:\n");

    for (i = 0; i < n; i++) {
        int found = 0;

        // Check if page exists
        for (j = 0; j < frames; j++) {
            if (mem[j] == pages[i]) {
                found = 1;
                hits++;
                recent[j] = i; // Update most recent use
                break;
            }
        }

        // Page fault
        if (!found) {
            int replace = 0;

            // Find empty slot or least recently used
            for (j = 0; j < frames; j++) {
                if (mem[j] == -1) {
                    replace = j;
                    break;
                }
                if (recent[j] < recent[replace])
                    replace = j;
            }

            mem[replace] = pages[i];
            recent[replace] = i;
            faults++;

            // Show memory state
            printf("Page %d -> ", pages[i]);
            for (j = 0; j < frames; j++)
                if (mem[j] == -1) printf("- ");
                else printf("%d ", mem[j]);
            printf("\n");
        }
    }

    printf("LRU Page Hits: %d, Page Faults: %d\n", hits, faults);
    return faults;
}

int main() {
    int pages[MAX], n, frames, ch;

    printf("Enter number of frames: ");
    scanf("%d", &frames);

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter the pages: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("\nChoose Algorithm:\n1. FIFO\n2. LRU\nChoice: ");
    scanf("%d", &ch);

    if (ch == 1)
        fifo(pages, n, frames);
    else if (ch == 2)
        lru(pages, n, frames);
    else
        printf("Invalid choice.\n");

    return 0;
}
