#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void fcfs(int arr[], int n, int start) {
    int i, distance, total_time = 0;

    printf("\nFCFS Disk Scheduling:\n");
    printf("Disk Access Sequence:\n");

    for (i = 0; i < n; i++) {
        distance = abs(arr[i] - start);
        total_time += distance;
        printf("Move from %d to %d (Distance: %d)\n", start, arr[i], distance);
        start = arr[i];
    }

    printf("\nTotal Seek Time: %d\n", total_time);
    printf("Average Seek Time: %d\n", total_time / n);
}

void scan(int arr[], int n, int start, int end) {
    int i, j, distance, total_time = 0;
    int temp, pos;

    // Sort the array (simple bubble sort)
    for (i = 0; i < n-1; i++) {
        for (j = i+1; j < n; j++) {
            if (arr[i] > arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    printf("\nSCAN Disk Scheduling:\n");
    printf("Disk Access Sequence:\n");

    // Find the first element greater than start
    pos = 0;
    while (pos < n && arr[pos] < start) {
        pos++;
    }

    // Move right (towards end)
    for (i = pos; i < n; i++) {
        distance = abs(arr[i] - start);
        total_time += distance;
        printf("Move from %d to %d (Distance: %d)\n", start, arr[i], distance);
        start = arr[i];
    }

    // Move to disk end if needed
    if (start != end) {
        distance = abs(end - start);
        total_time += distance;
        printf("Move from %d to %d (Distance: %d)\n", start, end, distance);
        start = end;
    }

    // Reverse and move left
    for (i = pos - 1; i >= 0; i--) {
        distance = abs(arr[i] - start);
        total_time += distance;
        printf("Move from %d to %d (Distance: %d)\n", start, arr[i], distance);
        start = arr[i];
    }

    printf("\nTotal Seek Time: %d\n", total_time);
    printf("Average Seek Time: %d\n", total_time / n);
}

void main() {
    int arr[100], n, i, start, end, choice;

    clrscr();

    printf("Enter the number of disk requests: ");
    scanf("%d", &n);

    printf("Enter the disk requests (track numbers): ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the starting position of the disk arm: ");
    scanf("%d", &start);

    printf("\nChoose Disk Scheduling Algorithm:\n");
    printf("1. FCFS (First-Come, First-Served)\n");
    printf("2. SCAN\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            fcfs(arr, n, start);
            break;
        case 2:
            printf("Enter the end position of the disk (maximum track number): ");
            scanf("%d", &end);
            scan(arr, n, start, end);
            break;
        default:
            printf("Invalid choice!\n");
    }

    getch();
}
