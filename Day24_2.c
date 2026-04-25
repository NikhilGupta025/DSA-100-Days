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

// Remove elements function
struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode dummy;
    dummy.next = head;

    struct ListNode* curr = &dummy;

    while (curr->next != NULL) {
        if (curr->next->val == val) {
            struct ListNode* temp = curr->next;
            curr->next = curr->next->next;
            free(temp);  // optional (good practice)
        } else {
            curr = curr->next;
        }
    }

    return dummy.next;
}

// Print list
void printList(struct ListNode* head) {
    while (head != NULL) {
        printf("%d -> ", head->val);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    int n, x, val;

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

    printf("Enter value to remove: ");
    scanf("%d", &val);

    head = removeElements(head, val);

    printf("Updated List:\n");
    printList(head);

    return 0;
}