#include <stdio.h>
#include <stdbool.h>

bool isPowerOfTwo(int n) {
    return n > 0 && (n & (n - 1)) == 0;
}

int main() {
    int n;

    printf("Enter an integer: ");
    scanf("%d", &n);

    if (isPowerOfTwo(n)) {
        printf("True");
    } else {
        printf("False");
    }

    return 0;
}