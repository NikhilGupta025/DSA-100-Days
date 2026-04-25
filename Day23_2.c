#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

// Function to detect cycle
bool hasCycle(struct ListNode* head) {
    struct ListNode* slow = head;
    struct ListNode* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;           // 1 step
        fast = fast->next->next;     // 2 steps

        if (slow == fast) {
            return true;  // cycle detected
        }
    }

    return false;  // no cycle
}

int main() {
    // Example: manually creating a cycle
    struct ListNode* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);

    // Creating cycle: last node points to node with value 2
    head->next->next->next->next = head->next;

    if (hasCycle(head))
        printf("Cycle detected\n");
    else
        printf("No cycle\n");

    return 0;
}