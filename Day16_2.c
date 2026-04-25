#include <stdio.h>

// Function to reverse part of the array
void reverse(int nums[], int start, int end) {
    while (start < end) {
        int temp = nums[start];
        nums[start] = nums[end];
        nums[end] = temp;
        start++;
        end--;
    }
}

// Function to rotate array to the right by k steps
void rotate(int nums[], int n, int k) {
    if (n == 0) return;

    k = k % n;  // Handle cases where k > n

    // Step 1: Reverse entire array
    reverse(nums, 0, n - 1);

    // Step 2: Reverse first k elements
    reverse(nums, 0, k - 1);

    // Step 3: Reverse remaining elements
    reverse(nums, k, n - 1);
}

int main() {
    int n, k;

    // Input size
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int nums[n];

    // Input array
    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    // Input k
    printf("Enter k: ");
    scanf("%d", &k);

    // Rotate array
    rotate(nums, n, k);

    // Output result
    printf("Rotated array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", nums[i]);
    }

    return 0;
}