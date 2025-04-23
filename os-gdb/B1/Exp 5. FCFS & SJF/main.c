#include <stdio.h>

void fcfs(int n, int bt[]) {
    int wt[n], tat[n];
    float total_wt = 0, total_tat = 0;

    wt[0] = 0;
    for (int i = 1; i < n; i++)
        wt[i] = bt[i - 1] + wt[i - 1];

    for (int i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
        total_wt += wt[i];
        total_tat += tat[i];
    }

    printf("\n--- FCFS Scheduling ---\n");
    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++)
        printf("P%d\t%d\t\t%d\t\t%d\n", i + 1, bt[i], wt[i], tat[i]);

    printf("Average Waiting Time = %.2f\n", total_wt / n);
    printf("Average Turnaround Time = %.2f\n", total_tat / n);
}

void sjf(int n, int bt[]) {
    int p[n], wt[n], tat[n];
    int bt_sorted[n];
    float total_wt = 0, total_tat = 0;

    // Initialize process IDs and copy burst times
    for (int i = 0; i < n; i++) {
        p[i] = i;
        bt_sorted[i] = bt[i];
    }

    // Sort by burst time (SJF)
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (bt_sorted[i] > bt_sorted[j]) {
                int temp = bt_sorted[i]; bt_sorted[i] = bt_sorted[j]; bt_sorted[j] = temp;
                int t = p[i]; p[i] = p[j]; p[j] = t;
            }

    wt[0] = 0;
    for (int i = 1; i < n; i++)
        wt[i] = wt[i - 1] + bt_sorted[i - 1];

    for (int i = 0; i < n; i++) {
        tat[i] = bt_sorted[i] + wt[i];
        total_wt += wt[i];
        total_tat += tat[i];
    }

    printf("\n--- SJF Scheduling ---\n");
    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++)
        printf("P%d\t%d\t\t%d\t\t%d\n", p[i] + 1, bt_sorted[i], wt[i], tat[i]);

    printf("Average Waiting Time = %.2f\n", total_wt / n);
    printf("Average Turnaround Time = %.2f\n", total_tat / n);
}

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int bt[n];
    printf("Enter burst time for each process:\n");
    for (int i = 0; i < n; i++) {
        printf("P%d: ", i + 1);
        scanf("%d", &bt[i]);
    }

    fcfs(n, bt);
    sjf(n, bt);

    return 0;
}
