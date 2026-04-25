#include <stdio.h>
#include <stdbool.h>

#define MAX 1000

// Stack structure
struct Stack {
    int arr[MAX];
    int top;
};

// Initialize stack
void init(struct Stack* s) {
    s->top = -1;
}

// Push
void pushStack(struct Stack* s, int val) {
    s->arr[++(s->top)] = val;
}

// Pop
int popStack(struct Stack* s) {
    return s->arr[(s->top)--];
}

// Check empty
bool isEmptyStack(struct Stack* s) {
    return s->top == -1;
}

// Queue using two stacks
struct MyQueue {
    struct Stack s1, s2;
};

// Initialize queue
void initQueue(struct MyQueue* q) {
    init(&q->s1);
    init(&q->s2);
}

// Push (enqueue)
void push(struct MyQueue* q, int x) {
    pushStack(&q->s1, x);
}

// Move elements from s1 to s2
void transfer(struct MyQueue* q) {
    while (!isEmptyStack(&q->s1)) {
        pushStack(&q->s2, popStack(&q->s1));
    }
}

// Pop (dequeue)
int pop(struct MyQueue* q) {
    if (isEmptyStack(&q->s2)) {
        transfer(q);
    }
    return popStack(&q->s2);
}

// Peek (front)
int peek(struct MyQueue* q) {
    if (isEmptyStack(&q->s2)) {
        transfer(q);
    }
    return q->s2.arr[q->s2.top];
}

// Check empty
bool empty(struct MyQueue* q) {
    return isEmptyStack(&q->s1) && isEmptyStack(&q->s2);
}

int main() {
    struct MyQueue q;
    initQueue(&q);

    push(&q, 1);
    push(&q, 2);
    push(&q, 3);

    printf("Front: %d\n", peek(&q)); // 1
    printf("Pop: %d\n", pop(&q));   // 1
    printf("Front: %d\n", peek(&q)); // 2

    return 0;
}