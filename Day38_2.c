#include <stdio.h>

#define MAX 1000

// Function to find sliding window maximum
void maxSlidingWindow(int nums[], int n, int k) {
    int deque[MAX];  // stores indices
    int front = 0, rear = -1;

    for (int i = 0; i < n; i++) {

        // Remove indices out of window
        if (front <= rear && deque[front] < i - k + 1) {
            front++;
        }

        // Remove smaller elements from rear
        while (front <= rear && nums[deque[rear]] < nums[i]) {
            rear--;
        }

        // Add current index
        deque[++rear] = i;

        // Print max when window is ready
        if (i >= k - 1) {
            printf("%d ", nums[deque[front]]);
        }
    }
}

int main() {
    int nums[] = {1,3,-1,-3,5,3,6,7};
    int n = 8;
    int k = 3;

    printf("Sliding window maximums:\n");
    maxSlidingWindow(nums, n, k);

    return 0;
}