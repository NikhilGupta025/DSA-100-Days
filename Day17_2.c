#include <stdio.h>
#include <limits.h>

int maxSubArray(int nums[], int n) {
    int current_sum = 0;
    int max_sum = INT_MIN;

    for (int i = 0; i < n; i++) {
        current_sum += nums[i];

        if (current_sum > max_sum) {
            max_sum = current_sum;
        }

        // Reset if sum becomes negative
        if (current_sum < 0) {
            current_sum = 0;
        }
    }

    return max_sum;
}

int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int nums[n];

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    int result = maxSubArray(nums, n);

    printf("Maximum subarray sum: %d\n", result);

    return 0;
}