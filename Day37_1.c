#include <stdio.h>

#define MAX 10

int pq[MAX];
int pr[MAX];
int size = -1;

void enqueue(int data, int priority) {
    if (size == MAX - 1) {
        printf("Queue Overflow! Cannot insert %d\n", data);
        return;
    }

    size++;
    
    int i = size - 1;
    while (i >= 0 && pr[i] < priority) {
        pq[i + 1] = pq[i];
        pr[i + 1] = pr[i];
        i--;
    }

    pq[i + 1] = data;
    pr[i + 1] = priority;
}

void dequeue() {
    if (size == -1) {
        printf("Queue Underflow! No elements to process.\n");
        return;
    }

    printf("Processed Element: %d (Priority: %d)\n", pq[0], pr[0]);

    for (int i = 0; i < size; i++) {
        pq[i] = pq[i + 1];
        pr[i] = pr[i + 1];
    }
    size--;
}

void display() {
    if (size == -1) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Current Priority Queue: ");
    for (int i = 0; i <= size; i++) {
        printf("[%d, P:%d] ", pq[i], pr[i]);
    }
    printf("\n");
}

int main() {
    enqueue(10, 1);
    enqueue(30, 3);
    enqueue(20, 2);
    enqueue(40, 4);

    display();

    dequeue();
    display();

    return 0;
}