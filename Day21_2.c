#include <stdio.h>
#include <stdlib.h>

// Definition of linked list node
struct ListNode {
    int val;
    struct ListNode* next;
};

// Function to create a new node
struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

// Function to find middle node
struct ListNode* middleNode(struct ListNode* head) {
    struct ListNode* slow = head;
    struct ListNode* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;        // move 1 step
        fast = fast->next->next;  // move 2 steps
    }

    return slow;
}

// Function to print list from a given node
void printList(struct ListNode* head) {
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

int main() {
    int n, x;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    struct ListNode *head = NULL, *temp = NULL;

    printf("Enter values:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        struct ListNode* newNode = createNode(x);

        if (head == NULL) {
            head = newNode;
            temp = head;
        } else {
            temp->next = newNode;
            temp = temp->next;
        }
    }

    struct ListNode* mid = middleNode(head);

    printf("Middle node and onward:\n");
    printList(mid);

    return 0;
}