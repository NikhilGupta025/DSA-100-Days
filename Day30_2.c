#include <stdio.h>
#include <stdlib.h>

// Node structure
struct ListNode {
    int val;
    struct ListNode* next;
};

// Stack node
struct Stack {
    int val;
    struct Stack* next;
};

// Push to stack
void push(struct Stack** top, int val) {
    struct Stack* node = (struct Stack*)malloc(sizeof(struct Stack));
    node->val = val;
    node->next = *top;
    *top = node;
}

// Pop from stack
int pop(struct Stack** top) {
    if (*top == NULL) return 0;
    struct Stack* temp = *top;
    int val = temp->val;
    *top = temp->next;
    free(temp);
    return val;
}

// Check if stack empty
int isEmpty(struct Stack* top) {
    return top == NULL;
}

// Create node
struct ListNode* createNode(int val) {
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

// Add two numbers (forward order)
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct Stack *s1 = NULL, *s2 = NULL;

    // Push elements into stacks
    while (l1 != NULL) {
        push(&s1, l1->val);
        l1 = l1->next;
    }

    while (l2 != NULL) {
        push(&s2, l2->val);
        l2 = l2->next;
    }

    int carry = 0;
    struct ListNode* result = NULL;

    // Process stacks
    while (!isEmpty(s1) || !isEmpty(s2) || carry) {
        int sum = carry;

        if (!isEmpty(s1)) sum += pop(&s1);
        if (!isEmpty(s2)) sum += pop(&s2);

        carry = sum / 10;

        struct ListNode* node = createNode(sum % 10);
        node->next = result;  // insert at front
        result = node;
    }

    return result;
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
    // Example: 7243
    struct ListNode* l1 = createNode(7);
    l1->next = createNode(2);
    l1->next->next = createNode(4);
    l1->next->next->next = createNode(3);

    // Example: 564
    struct ListNode* l2 = createNode(5);
    l2->next = createNode(6);
    l2->next->next = createNode(4);

    struct ListNode* result = addTwoNumbers(l1, l2);

    printf("Result:\n");
    printList(result);

    return 0;
}