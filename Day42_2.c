#include <stdio.h>

// Function to sort array (Bubble Sort - easy for beginners)
void sort(int arr[], int n) {
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

// Function to find median
float findMedian(int arr[], int n) {
    sort(arr, n);  // Step 1: sort

    if(n % 2 == 1) {
        // Odd case
        return arr[n/2];
    } else {
        // Even case
        return (arr[n/2] + arr[n/2 - 1]) / 2.0;
    }
}

int main() {
    int arr[] = {5, 2, 1, 3, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    float median = findMedian(arr, n);

    printf("Median = %.2f\n", median);

    return 0;
}