#include <stdio.h>

#define MAX 1000

void dailyTemperatures(int temps[], int n) {
    int stack[MAX];  // stores indices
    int top = -1;

    int ans[MAX];

    for (int i = 0; i < n; i++) {
        ans[i] = 0;  // default
    }

    for (int i = 0; i < n; i++) {

        // Resolve previous colder days
        while (top != -1 && temps[i] > temps[stack[top]]) {
            int idx = stack[top--];
            ans[idx] = i - idx;
        }

        // Push current index
        stack[++top] = i;
    }

    // Print result
    printf("Result:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", ans[i]);
    }
}

int main() {
    int temps[] = {73,74,75,71,69,72,76,73};
    int n = 8;

    dailyTemperatures(temps, n);

    return 0;
}