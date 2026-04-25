#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX 1000

// Stack structure
struct Stack {
    char arr[MAX];
    int top;
};

// Initialize stack
void init(struct Stack* s) {
    s->top = -1;
}

// Push
void push(struct Stack* s, char c) {
    s->arr[++(s->top)] = c;
}

// Pop
char pop(struct Stack* s) {
    if (s->top == -1) return '\0';
    return s->arr[(s->top)--];
}

// Peek
char peek(struct Stack* s) {
    if (s->top == -1) return '\0';
    return s->arr[s->top];
}

// Check valid parentheses
bool isValid(char* s) {
    struct Stack stack;
    init(&stack);

    for (int i = 0; i < strlen(s); i++) {
        char c = s[i];

        // Opening brackets
        if (c == '(' || c == '{' || c == '[') {
            push(&stack, c);
        }
        // Closing brackets
        else {
            if (stack.top == -1)
                return false;

            char top = pop(&stack);

            if ((c == ')' && top != '(') ||
                (c == '}' && top != '{') ||
                (c == ']' && top != '[')) {
                return false;
            }
        }
    }

    return stack.top == -1;
}

int main() {
    char s[1000];

    printf("Enter string: ");
    scanf("%s", s);

    if (isValid(s))
        printf("Valid\n");
    else
        printf("Invalid\n");

    return 0;
}