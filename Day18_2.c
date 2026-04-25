#include <stdio.h>

void productExceptSelf(int nums[], int n, int answer[]) {
    // Step 1: Fill prefix products
    answer[0] = 1;
    for (int i = 1; i < n; i++) {
        answer[i] = answer[i - 1] * nums[i - 1];
    }

    // Step 2: Multiply with suffix products
    int suffix = 1;
    for (int i = n - 1; i >= 0; i--) {
        answer[i] = answer[i] * suffix;
        suffix *= nums[i];
    }
}

int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int nums[n], answer[n];

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    productExceptSelf(nums, n, answer);

    printf("Product array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", answer[i]);
    }

    return 0;
}