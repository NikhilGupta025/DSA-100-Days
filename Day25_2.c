#include <stdio.h>
#include <stdlib.h>

// Node structure
struct ListNode {
    int val;
    struct ListNode* next;
};

// Create node
struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

// Function to detect cycle start
struct ListNode *detectCycle(struct ListNode *head) {
    struct ListNode *slow = head;
    struct ListNode *fast = head;

    // Step 1: Detect cycle
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            // Step 2: Find start of cycle
            struct ListNode *entry = head;

            while (entry != slow) {
                entry = entry->next;
                slow = slow->next;
            }

            return entry;  // cycle start
        }
    }

    return NULL;  // no cycle
}

int main() {
    // Create example list
    struct ListNode* head = createNode(3);
    head->next = createNode(2);
    head->next->next = createNode(0);
    head->next->next->next = createNode(-4);

    // Create cycle (tail connects to node with value 2)
    head->next->next->next->next = head->next;

    struct ListNode* cycleStart = detectCycle(head);

    if (cycleStart != NULL)
        printf("Cycle starts at node with value: %d\n", cycleStart->val);
    else
        printf("No cycle\n");

    return 0;
}