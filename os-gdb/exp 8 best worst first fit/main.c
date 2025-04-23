#include <stdio.h>
#define MAX 10

void copyArray(int src[], int dest[], int n) {
    for (int i = 0; i < n; i++)
        dest[i] = src[i];
}

void displayResult(const char* strategy, int allocation[], int numProcesses) {
    printf("\n%s Allocation:\n", strategy);
    for (int i = 0; i < numProcesses; i++) {
        if (allocation[i] != -1)
            printf("Process %d -> Block %d\n", i + 1, allocation[i] + 1);
        else
            printf("Process %d -> Not Allocated\n", i + 1);
    }
}

void firstFit(int blocks[], int processes[], int nb, int np) {
    int allocation[MAX], memory[MAX];
    copyArray(blocks, memory, nb);

    for (int i = 0; i < np; i++) {
        allocation[i] = -1;
        for (int j = 0; j < nb; j++) {
            if (memory[j] >= processes[i]) {
                allocation[i] = j;
                memory[j] -= processes[i];
                break;
            }
        }
    }
    displayResult("First Fit", allocation, np);
}

void bestFit(int blocks[], int processes[], int nb, int np) {
    int allocation[MAX], memory[MAX];
    copyArray(blocks, memory, nb);

    for (int i = 0; i < np; i++) {
        int best = -1;
        allocation[i] = -1;

        for (int j = 0; j < nb; j++) {
            if (memory[j] >= processes[i]) {
                if (best == -1 || memory[j] < memory[best])
                    best = j;
            }
        }

        if (best != -1) {
            allocation[i] = best;
            memory[best] -= processes[i];
        }
    }
    displayResult("Best Fit", allocation, np);
}

void worstFit(int blocks[], int processes[], int nb, int np) {
    int allocation[MAX], memory[MAX];
    copyArray(blocks, memory, nb);

    for (int i = 0; i < np; i++) {
        int worst = -1;
        allocation[i] = -1;

        for (int j = 0; j < nb; j++) {
            if (memory[j] >= processes[i]) {
                if (worst == -1 || memory[j] > memory[worst])
                    worst = j;
            }
        }

        if (worst != -1) {
            allocation[i] = worst;
            memory[worst] -= processes[i];
        }
    }
    displayResult("Worst Fit", allocation, np);
}

int main() {
    int blocks[MAX], processes[MAX], numBlocks, numProcesses, choice;

    printf("Enter number of memory blocks: ");
    scanf("%d", &numBlocks);

    printf("Enter sizes of %d blocks:\n", numBlocks);
    for (int i = 0; i < numBlocks; i++) {
        printf("Block %d: ", i + 1);
        scanf("%d", &blocks[i]);
    }

    printf("\nEnter number of processes: ");
    scanf("%d", &numProcesses);

    printf("Enter sizes of %d processes:\n", numProcesses);
    for (int i = 0; i < numProcesses; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &processes[i]);
    }

    printf("\nChoose Allocation Strategy:\n");
    printf("1. First Fit\n2. Best Fit\n3. Worst Fit\nChoice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            firstFit(blocks, processes, numBlocks, numProcesses);
            break;
        case 2:
            bestFit(blocks, processes, numBlocks, numProcesses);
            break;
        case 3:
            worstFit(blocks, processes, numBlocks, numProcesses);
            break;
        default:
            printf("Invalid choice!\n");
    }

    return 0;
}
