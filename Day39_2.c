#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

// Pair structure
struct Pair {
    int val;
    int freq;
};

// Min Heap
struct Pair heap[MAX];
int size = 0;

// Swap
void swap(struct Pair *a, struct Pair *b) {
    struct Pair temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify up
void heapifyUp(int i) {
    while (i > 0) {
        int parent = (i - 1) / 2;
        if (heap[parent].freq > heap[i].freq) {
            swap(&heap[parent], &heap[i]);
            i = parent;
        } else break;
    }
}

// Heapify down
void heapifyDown(int i) {
    while (1) {
        int left = 2*i + 1, right = 2*i + 2;
        int smallest = i;

        if (left < size && heap[left].freq < heap[smallest].freq)
            smallest = left;
        if (right < size && heap[right].freq < heap[smallest].freq)
            smallest = right;

        if (smallest != i) {
            swap(&heap[i], &heap[smallest]);
            i = smallest;
        } else break;
    }
}

// Insert into heap
void push(struct Pair p, int k) {
    heap[size++] = p;
    heapifyUp(size - 1);

    if (size > k) {
        heap[0] = heap[size - 1];
        size--;
        heapifyDown(0);
    }
}

// Frequency map (simple version)
int freqMap[MAX][2]; // [value, frequency]
int mapSize = 0;

// Find or insert
void addFreq(int val) {
    for (int i = 0; i < mapSize; i++) {
        if (freqMap[i][0] == val) {
            freqMap[i][1]++;
            return;
        }
    }
    freqMap[mapSize][0] = val;
    freqMap[mapSize][1] = 1;
    mapSize++;
}

// Main function
void topKFrequent(int nums[], int n, int k) {

    // Build frequency map
    for (int i = 0; i < n; i++) {
        addFreq(nums[i]);
    }

    // Build heap
    for (int i = 0; i < mapSize; i++) {
        struct Pair p;
        p.val = freqMap[i][0];
        p.freq = freqMap[i][1];
        push(p, k);
    }

    // Output result
    printf("Top %d frequent elements:\n", k);
    for (int i = 0; i < size; i++) {
        printf("%d ", heap[i].val);
    }
}

// Driver
int main() {
    int nums[] = {1,1,1,2,2,3};
    int n = 6, k = 2;

    topKFrequent(nums, n, k);

    return 0;
}