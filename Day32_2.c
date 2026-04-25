#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

// MinStack structure
struct MinStack {
    int stack[MAX];
    int minStack[MAX];
    int top;
};

// Initialize stack
void init(struct MinStack* obj) {
    obj->top = -1;
}

// Push
void push(struct MinStack* obj, int val) {
    obj->top++;
    obj->stack[obj->top] = val;

    // Handle min stack
    if (obj->top == 0) {
        obj->minStack[obj->top] = val;
    } else {
        int currentMin = obj->minStack[obj->top - 1];
        obj->minStack[obj->top] = (val < currentMin) ? val : currentMin;
    }
}

// Pop
void pop(struct MinStack* obj) {
    if (obj->top >= 0)
        obj->top--;
}

// Top element
int top(struct MinStack* obj) {
    if (obj->top >= 0)
        return obj->stack[obj->top];
    return -1;
}

// Get minimum
int getMin(struct MinStack* obj) {
    if (obj->top >= 0)
        return obj->minStack[obj->top];
    return -1;
}

int main() {
    struct MinStack obj;
    init(&obj);

    push(&obj, -2);
    push(&obj, 0);
    push(&obj, -3);

    printf("Minimum: %d\n", getMin(&obj)); // -3

    pop(&obj);

    printf("Top: %d\n", top(&obj));       // 0
    printf("Minimum: %d\n", getMin(&obj)); // -2

    return 0;
}