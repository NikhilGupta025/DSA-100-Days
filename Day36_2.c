#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// Circular Deque structure
struct MyCircularDeque {
    int *arr;
    int front, rear, size, capacity;
};

// Initialize deque
struct MyCircularDeque* createDeque(int k) {
    struct MyCircularDeque* dq = (struct MyCircularDeque*)malloc(sizeof(struct MyCircularDeque));
    dq->capacity = k;
    dq->arr = (int*)malloc(sizeof(int) * k);
    dq->front = -1;
    dq->rear = -1;
    dq->size = 0;
    return dq;
}

// Check empty
bool isEmpty(struct MyCircularDeque* dq) {
    return dq->size == 0;
}

// Check full
bool isFull(struct MyCircularDeque* dq) {
    return dq->size == dq->capacity;
}

// Insert at front
bool insertFront(struct MyCircularDeque* dq, int value) {
    if (isFull(dq)) return false;

    if (isEmpty(dq)) {
        dq->front = dq->rear = 0;
    } else {
        dq->front = (dq->front - 1 + dq->capacity) % dq->capacity;
    }

    dq->arr[dq->front] = value;
    dq->size++;
    return true;
}

// Insert at rear
bool insertLast(struct MyCircularDeque* dq, int value) {
    if (isFull(dq)) return false;

    if (isEmpty(dq)) {
        dq->front = dq->rear = 0;
    } else {
        dq->rear = (dq->rear + 1) % dq->capacity;
    }

    dq->arr[dq->rear] = value;
    dq->size++;
    return true;
}

// Delete front
bool deleteFront(struct MyCircularDeque* dq) {
    if (isEmpty(dq)) return false;

    if (dq->front == dq->rear) {
        dq->front = dq->rear = -1;
    } else {
        dq->front = (dq->front + 1) % dq->capacity;
    }

    dq->size--;
    return true;
}

// Delete rear
bool deleteLast(struct MyCircularDeque* dq) {
    if (isEmpty(dq)) return false;

    if (dq->front == dq->rear) {
        dq->front = dq->rear = -1;
    } else {
        dq->rear = (dq->rear - 1 + dq->capacity) % dq->capacity;
    }

    dq->size--;
    return true;
}

// Get front
int getFront(struct MyCircularDeque* dq) {
    if (isEmpty(dq)) return -1;
    return dq->arr[dq->front];
}

// Get rear
int getRear(struct MyCircularDeque* dq) {
    if (isEmpty(dq)) return -1;
    return dq->arr[dq->rear];
}

// Main for testing
int main() {
    struct MyCircularDeque* dq = createDeque(3);

    insertLast(dq, 1);
    insertLast(dq, 2);
    insertFront(dq, 3);
    insertFront(dq, 4); // should fail

    printf("Rear: %d\n", getRear(dq));   // 2
    printf("Is Full: %d\n", isFull(dq)); // 1

    deleteLast(dq);
    insertFront(dq, 4);

    printf("Front: %d\n", getFront(dq)); // 4

    return 0;
}