#include <stdio.h>
#include <limits.h>

// Standard Kadane (max subarray sum)
int kadaneMax(int nums[], int n) {
    int current = nums[0];
    int maxSum = nums[0];

    for (int i = 1; i < n; i++) {
        if (current + nums[i] > nums[i])
            current = current + nums[i];
        else
            current = nums[i];

        if (current > maxSum)
            maxSum = current;
    }

    return maxSum;
}

// Kadane for minimum subarray sum
int kadaneMin(int nums[], int n) {
    int current = nums[0];
    int minSum = nums[0];

    for (int i = 1; i < n; i++) {
        if (current + nums[i] < nums[i])
            current = current + nums[i];
        else
            current = nums[i];

        if (current < minSum)
            minSum = current;
    }

    return minSum;
}

int maxSubarraySumCircular(int nums[], int n) {
    int total = 0;

    for (int i = 0; i < n; i++) {
        total += nums[i];
    }

    int max_kadane = kadaneMax(nums, n);
    int min_kadane = kadaneMin(nums, n);

    // Edge case: all elements negative
    if (total == min_kadane)
        return max_kadane;

    // Return maximum of two cases
    if (max_kadane > (total - min_kadane))
        return max_kadane;
    else
        return (total - min_kadane);
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

    int result = maxSubarraySumCircular(nums, n);

    printf("Maximum circular subarray sum: %d\n", result);

    return 0;
}