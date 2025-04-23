#include <stdio.h>

#define MAX_BLOCKS 10
#define MAX_PROCESSES 10

void firstFit(int blockSize[], int processSize[], int numBlocks, int numProcesses) {
    int allocation[MAX_PROCESSES];
    int i, j;

    for (i = 0; i < numProcesses; i++) {
        allocation[i] = -1;  // Initially, no block is allocated
        for (j = 0; j < numBlocks; j++) {
            if (blockSize[j] >= processSize[i]) {
                allocation[i] = j;
                blockSize[j] -= processSize[i];  // Reduce block size after allocation
                break;
            }
        }
    }

    printf("\nFirst Fit Allocation:\n");
    for (i = 0; i < numProcesses; i++) {
        if (allocation[i] != -1)
            printf("Process %d -> Block %d\n", i + 1, allocation[i] + 1);
        else
            printf("Process %d -> Not Allocated\n", i + 1);
    }
}

void bestFit(int blockSize[], int processSize[], int numBlocks, int numProcesses) {
    int allocation[MAX_PROCESSES];
    int i, j, bestIdx;

    for (i = 0; i < numProcesses; i++) {
        bestIdx = -1;
        allocation[i] = -1;  // Initially, no block is allocated
        for (j = 0; j < numBlocks; j++) {
            if (blockSize[j] >= processSize[i]) {
                if (bestIdx == -1 || blockSize[j] < blockSize[bestIdx])
                    bestIdx = j;
            }
        }
        if (bestIdx != -1) {
            allocation[i] = bestIdx;
            blockSize[bestIdx] -= processSize[i];  // Reduce block size after allocation
        }
    }

    printf("\nBest Fit Allocation:\n");
    for (i = 0; i < numProcesses; i++) {
        if (allocation[i] != -1)
            printf("Process %d -> Block %d\n", i + 1, allocation[i] + 1);
        else
            printf("Process %d -> Not Allocated\n", i + 1);
    }
}

void worstFit(int blockSize[], int processSize[], int numBlocks, int numProcesses) {
    int allocation[MAX_PROCESSES];
    int i, j, worstIdx;

    for (i = 0; i < numProcesses; i++) {
        worstIdx = -1;
        allocation[i] = -1;  // Initially, no block is allocated
        for (j = 0; j < numBlocks; j++) {
            if (blockSize[j] >= processSize[i]) {
                if (worstIdx == -1 || blockSize[j] > blockSize[worstIdx])
                    worstIdx = j;
            }
        }
        if (worstIdx != -1) {
            allocation[i] = worstIdx;
            blockSize[worstIdx] -= processSize[i];  // Reduce block size after allocation
        }
    }

    printf("\nWorst Fit Allocation:\n");
    for (i = 0; i < numProcesses; i++) {
        if (allocation[i] != -1)
            printf("Process %d -> Block %d\n", i + 1, allocation[i] + 1);
        else
            printf("Process %d -> Not Allocated\n", i + 1);
    }
}

int main() {
    int blockSize[MAX_BLOCKS], processSize[MAX_PROCESSES];
    int numBlocks, numProcesses, choice;
    int i;

    // Input the number of blocks and processes
    printf("Enter number of memory blocks: ");
    scanf("%d", &numBlocks);
    printf("Enter number of processes: ");
    scanf("%d", &numProcesses);

    // Input the sizes of the blocks
    printf("\nEnter sizes of %d blocks:\n", numBlocks);
    for (i = 0; i < numBlocks; i++) {
        printf("Block %d size: ", i + 1);
        scanf("%d", &blockSize[i]);
    }

    // Input the sizes of the processes
    printf("\nEnter sizes of %d processes:\n", numProcesses);
    for (i = 0; i < numProcesses; i++) {
        printf("Process %d size: ", i + 1);
        scanf("%d", &processSize[i]);
    }

    // Menu for choosing allocation strategy
    printf("\nChoose the memory allocation strategy:\n");
    printf("1. First Fit\n");
    printf("2. Best Fit\n");
    printf("3. Worst Fit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    // Call the respective allocation strategy
    switch (choice) {
        case 1:
            firstFit(blockSize, processSize, numBlocks, numProcesses);
            break;
        case 2:
            bestFit(blockSize, processSize, numBlocks, numProcesses);
            break;
        case 3:
            worstFit(blockSize, processSize, numBlocks, numProcesses);
            break;
        default:
            printf("Invalid choice!\n");
            break;
    }

    return 0;
}
