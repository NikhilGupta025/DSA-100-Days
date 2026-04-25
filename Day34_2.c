#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 1000

int calculate(char* s) {
    int stack[MAX];
    int top = -1;

    int num = 0;
    char sign = '+';

    for (int i = 0; i <= strlen(s); i++) {

        if (isdigit(s[i])) {
            num = num * 10 + (s[i] - '0');
        }

        // If operator or end of string
        if ((!isdigit(s[i]) && s[i] != ' ') || s[i] == '\0') {

            if (sign == '+') {
                stack[++top] = num;
            }
            else if (sign == '-') {
                stack[++top] = -num;
            }
            else if (sign == '*') {
                stack[top] = stack[top] * num;
            }
            else if (sign == '/') {
                stack[top] = stack[top] / num;  // truncate toward 0
            }

            sign = s[i];
            num = 0;
        }
    }

    // Sum stack
    int result = 0;
    for (int i = 0; i <= top; i++) {
        result += stack[i];
    }

    return result;
}

int main() {
    char s[1000];

    printf("Enter expression: ");
    fgets(s, sizeof(s), stdin);

    int result = calculate(s);

    printf("Result: %d\n", result);

    return 0;
}