#include <stdio.h>
#include <conio.h>

#define MAX_FRAMES 10
#define MAX_PAGES 20

// FIFO Page Replacement Algorithm
int fifoPageFaults(int pages[], int n, int frames) {
    int memory[MAX_FRAMES];
    int pageFaultCount = 0;
    int pageHits = 0;

    // Initialize memory to -1 to represent empty slots
    for (int i = 0; i < frames; i++) {
        memory[i] = -1;
    }

    int front = 0; // Pointer to the front of the FIFO queue

    printf("FIFO Page Replacement Process:\n");

    for (int i = 0; i < n; i++) {
        int page = pages[i];
        int found = 0;

        // Check if the page is already in memory
        for (int j = 0; j < frames; j++) {
            if (memory[j] == page) {
                found = 1;
                pageHits++;
                break;
            }
        }

        // If page is not found, it's a page fault
        if (!found) {
            memory[front] = page; // Replace the page at the front of the queue
            front = (front + 1) % frames; // Circular increment
            pageFaultCount++;

            // Display the current state of memory (after replacement)
            printf("Page replaced: %d -> Memory: ", page);
            for (int j = 0; j < frames; j++) {
                if (memory[j] == -1) printf("- ");
                else printf("%d ", memory[j]);
            }
            printf("\n");
        }
    }

    printf("FIFO: Page Hits = %d, Page Faults = %d\n", pageHits, pageFaultCount);
    return pageFaultCount;
}

// LRU Page Replacement Algorithm
int lruPageFaults(int pages[], int n, int frames) {
    int memory[MAX_FRAMES];
    int pageFaultCount = 0;
    int pageHits = 0;

    // Initialize memory to -1 to represent empty slots
    for (int i = 0; i < frames; i++) {
        memory[i] = -1;
    }

    printf("LRU Page Replacement Process:\n");

    // Keep track of the order of usage with an array
    for (int i = 0; i < n; i++) {
        int page = pages[i];
        int found = 0;

        // Check if the page is already in memory
        for (int j = 0; j < frames; j++) {
            if (memory[j] == page) {
                found = 1;
                pageHits++;
                // Move the page to the front (most recently used)
                for (int k = j; k > 0; k--) {
                    memory[k] = memory[k - 1];
                }
                memory[0] = page;
                break;
            }
        }

        // If page is not found, it's a page fault
        if (!found) {
            // Shift pages to make space for the new one
            for (int j = frames - 1; j > 0; j--) {
                memory[j] = memory[j - 1];
            }
            memory[0] = page; // Insert new page at the front (most recently used)
            pageFaultCount++;

            // Display the current state of memory (after replacement)
            printf("Page replaced: %d -> Memory: ", page);
            for (int j = 0; j < frames; j++) {
                if (memory[j] == -1) printf("- ");
                else printf("%d ", memory[j]);
            }
            printf("\n");
        }
    }

    printf("LRU: Page Hits = %d, Page Faults = %d\n", pageHits, pageFaultCount);
    return pageFaultCount;
}

void main() {
    int pages[MAX_PAGES], n, frames, choice;

    clrscr(); // Clears the screen for Turbo C environment

    // User input for number of frames
    printf("Enter number of frames: ");
    scanf("%d", &frames);

    // User input for pages
    printf("Enter number of pages: ");
    scanf("%d", &n);
    printf("Enter the pages:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }

    // Ask the user to select the page replacement algorithm
    printf("Choose page replacement algorithm:\n");
    printf("1. FIFO\n");
    printf("2. LRU\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);

    if (choice == 1) {
        fifoPageFaults(pages, n, frames); // FIFO
    } else if (choice == 2) {
        lruPageFaults(pages, n, frames); // LRU
    } else {
        printf("Invalid choice\n");
    }

    getch(); // Wait for user input before closing the program
}
