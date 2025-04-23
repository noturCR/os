#include <stdio.h>
#include <conio.h>
#include <dos.h>

#define BUFFER_SIZE 5

int buffer[BUFFER_SIZE];
int in = 0, out = 0;
int count = 0;

void produce() {
    int item;
    if (count == BUFFER_SIZE) {
        printf("Buffer is full! Cannot produce.\n");
        return;
    }

    item = rand() % 100;
    buffer[in] = item;
    in = (in + 1) % BUFFER_SIZE;
    count++;
    printf("Produced: %d\n", item);
}

void consume() {
    int item;
    if (count == 0) {
        printf("Buffer is empty! Cannot consume.\n");
        return;
    }

    item = buffer[out];
    out = (out + 1) % BUFFER_SIZE;
    count--;
    printf("Consumed: %d\n", item);
}

int main() {
    int choice;

    clrscr();
    while (1) {
        printf("\n1. Produce\n2. Consume\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            produce();
            break;
        case 2:
            consume();
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid choice!\n");
        }

        delay(1000); // Sleep for 1 second
    }

    return 0;
}
