#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

// Min Heap structure
struct KthLargest {
    int heap[MAX];
    int size;
    int k;
};

// Swap
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify up
void heapifyUp(struct KthLargest* obj, int i) {
    while (i > 0) {
        int parent = (i - 1) / 2;
        if (obj->heap[parent] > obj->heap[i]) {
            swap(&obj->heap[parent], &obj->heap[i]);
            i = parent;
        } else break;
    }
}

// Heapify down
void heapifyDown(struct KthLargest* obj, int i) {
    while (1) {
        int left = 2*i + 1;
        int right = 2*i + 2;
        int smallest = i;

        if (left < obj->size && obj->heap[left] < obj->heap[smallest])
            smallest = left;

        if (right < obj->size && obj->heap[right] < obj->heap[smallest])
            smallest = right;

        if (smallest != i) {
            swap(&obj->heap[i], &obj->heap[smallest]);
            i = smallest;
        } else break;
    }
}

// Create object
struct KthLargest* createKthLargest(int k, int nums[], int numsSize) {
    struct KthLargest* obj = (struct KthLargest*)malloc(sizeof(struct KthLargest));
    obj->size = 0;
    obj->k = k;

    // Add initial elements
    for (int i = 0; i < numsSize; i++) {
        // reuse add logic
        if (obj->size < k) {
            obj->heap[obj->size++] = nums[i];
            heapifyUp(obj, obj->size - 1);
        } else if (nums[i] > obj->heap[0]) {
            obj->heap[0] = nums[i];
            heapifyDown(obj, 0);
        }
    }

    return obj;
}

// Add element
int add(struct KthLargest* obj, int val) {
    if (obj->size < obj->k) {
        obj->heap[obj->size++] = val;
        heapifyUp(obj, obj->size - 1);
    } else if (val > obj->heap[0]) {
        obj->heap[0] = val;
        heapifyDown(obj, 0);
    }

    return obj->heap[0];  // kth largest
}

// Main
int main() {
    int nums[] = {4, 5, 8, 2};
    int k = 3;

    struct KthLargest* obj = createKthLargest(k, nums, 4);

    printf("%d\n", add(obj, 3));  // 4
    printf("%d\n", add(obj, 5));  // 5
    printf("%d\n", add(obj, 10)); // 5
    printf("%d\n", add(obj, 9));  // 8
    printf("%d\n", add(obj, 4));  // 8

    return 0;
}