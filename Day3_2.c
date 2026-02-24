#include <stdio.h>

int findMissingNumber(int arr[], int n) {
    int expectedSum = (int)n * (n + 1) / 2;
    int actualSum = 0;
    for (int i = 0; i < n - 1; i++) {
        actualSum += arr[i];
    }
    
        return (int)(expectedSum - actualSum);
}

int main() {
    int arr[] = {1, 2, 4, 5};
    int n = 5; 
    
    int missing = findMissingNumber(arr, n);
    printf("The missing number is: %d\n", missing);
    
    return 0;
}