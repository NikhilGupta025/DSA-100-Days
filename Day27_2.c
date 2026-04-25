#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Node structure
struct Node {
    int val;
    struct Node* next;
};

// Create node
struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

// Function to remove cycle
bool removeCycle(struct Node* head) {
    if (head == NULL) return false;

    struct Node *slow = head, *fast = head;

    // Step 1: Detect cycle
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            // Step 2: Find start of cycle
            struct Node* entry = head;

            while (entry != slow) {
                entry = entry->next;
                slow = slow->next;
            }

            // Step 3: Find last node in cycle
            struct Node* temp = entry;
            while (temp->next != entry) {
                temp = temp->next;
            }

            // Step 4: Break cycle
            temp->next = NULL;

            return true;  // cycle removed
        }
    }

    return false;  // no cycle
}

// Print list (safe after cycle removal)
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->val);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    // Create list
    struct Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);

    // Create cycle (4 → 2)
    head->next->next->next->next = head->next;

    if (removeCycle(head))
        printf("Cycle removed\n");
    else
        printf("No cycle found\n");

    // Print list after removal
    printList(head);

    return 0;
}