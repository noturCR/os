#include <stdio.h>
#include <stdlib.h>

void fcfs(int a[], int n, int start) {
    int t = 0;
    for (int i = 0; i < n; i++) {
        t += abs(a[i] - start);
        printf("%d -> %d\n", start, a[i]);
        start = a[i];
    }
    printf("Total Seek: %d\nAvg: %.2f\n", t, (float)t / n);
}

void scan(int a[], int n, int start, int end) {
    int t = 0, i, j;
    for (i = 0; i < n - 1; i++)
        for (j = i + 1; j < n; j++)
            if (a[i] > a[j]) { int tmp = a[i]; a[i] = a[j]; a[j] = tmp; }

    for (i = 0; i < n && a[i] < start; i++);

    for (j = i; j < n; j++) {
        t += abs(start - a[j]);
        printf("%d -> %d\n", start, a[j]);
        start = a[j];
    }
    if (start < end) {
        t += abs(end - start);
        printf("%d -> %d\n", start, end);
        start = end;
    }
    for (j = i - 1; j >= 0; j--) {
        t += abs(start - a[j]);
        printf("%d -> %d\n", start, a[j]);
        start = a[j];
    }
    printf("Total Seek: %d\nAvg: %.2f\n", t, (float)t / n);
}

int main() {
    int n, a[100], start, end, ch;
    printf("No. of requests: "); scanf("%d", &n);
    printf("Requests: "); for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    printf("Start pos: "); scanf("%d", &start);
    printf("1.FCFS  2.SCAN: "); scanf("%d", &ch);
    if (ch == 1) fcfs(a, n, start);
    else {
        printf("End track: "); scanf("%d", &end);
        scan(a, n, start, end);
    }
    return 0;
}
