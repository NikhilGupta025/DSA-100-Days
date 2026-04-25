#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

// Stack
struct Stack {
    int arr[MAX];
    int top;
};

// Initialize
void init(struct Stack* s) {
    s->top = -1;
}

// Push
void push(struct Stack* s, int val) {
    s->arr[++(s->top)] = val;
}

// Pop
int pop(struct Stack* s) {
    return s->arr[(s->top)--];
}

// Check if operator
int isOperator(char* token) {
    return (strcmp(token, "+") == 0 ||
            strcmp(token, "-") == 0 ||
            strcmp(token, "*") == 0 ||
            strcmp(token, "/") == 0);
}

// Evaluate RPN
int evalRPN(char* tokens[], int n) {
    struct Stack s;
    init(&s);

    for (int i = 0; i < n; i++) {

        if (!isOperator(tokens[i])) {
            // number
            push(&s, atoi(tokens[i]));
        } else {
            int b = pop(&s);
            int a = pop(&s);

            if (strcmp(tokens[i], "+") == 0)
                push(&s, a + b);
            else if (strcmp(tokens[i], "-") == 0)
                push(&s, a - b);
            else if (strcmp(tokens[i], "*") == 0)
                push(&s, a * b);
            else if (strcmp(tokens[i], "/") == 0)
                push(&s, a / b);  // integer division
        }
    }

    return pop(&s);
}

int main() {
    char* tokens[] = {"2", "1", "+", "3", "*"};
    int n = 5;

    int result = evalRPN(tokens, n);

    printf("Result: %d\n", result);

    return 0;
}