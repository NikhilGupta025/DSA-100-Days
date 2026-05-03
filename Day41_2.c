#include <stdio.h>

int leastInterval(char tasks[], int size, int n) {
    int freq[26] = {0};

    // Step 1: Count frequency of each task
    for (int i = 0; i < size; i++) {
        freq[tasks[i] - 'A']++;
    }

    // Step 2: Find max frequency
    int maxFreq = 0;
    for (int i = 0; i < 26; i++) {
        if (freq[i] > maxFreq) {
            maxFreq = freq[i];
        }
    }

    // Step 3: Count how many tasks have max frequency
    int countMax = 0;
    for (int i = 0; i < 26; i++) {
        if (freq[i] == maxFreq) {
            countMax++;
        }
    }

    // Step 4: Apply formula
    int part = (maxFreq - 1) * (n + 1) + countMax;

    // Step 5: Return maximum of total tasks and calculated value
    if (part > size)
        return part;
    else
        return size;
}

int main() {
    char tasks[] = {'A','A','A','B','B','B'};
    int n = 2;
    int size = sizeof(tasks) / sizeof(tasks[0]);

    int result = leastInterval(tasks, size, n);
    printf("Minimum CPU intervals: %d\n", result);

    return 0;
}