#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int val;
    struct Node* next;
};

// Linked List structure
struct MyLinkedList {
    struct Node* head;
    int size;
};

// Create linked list
struct MyLinkedList* createLinkedList() {
    struct MyLinkedList* list = (struct MyLinkedList*)malloc(sizeof(struct MyLinkedList));
    
    // Dummy head
    list->head = (struct Node*)malloc(sizeof(struct Node));
    list->head->next = NULL;
    
    list->size = 0;
    return list;
}

// Get value at index
int get(struct MyLinkedList* obj, int index) {
    if (index < 0 || index >= obj->size)
        return -1;

    struct Node* curr = obj->head->next;

    for (int i = 0; i < index; i++) {
        curr = curr->next;
    }

    return curr->val;
}

// Add at head
void addAtHead(struct MyLinkedList* obj, int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->val = val;

    node->next = obj->head->next;
    obj->head->next = node;

    obj->size++;
}

// Add at tail
void addAtTail(struct MyLinkedList* obj, int val) {
    struct Node* curr = obj->head;

    while (curr->next != NULL) {
        curr = curr->next;
    }

    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->val = val;
    node->next = NULL;

    curr->next = node;
    obj->size++;
}

// Add at index
void addAtIndex(struct MyLinkedList* obj, int index, int val) {
    if (index < 0 || index > obj->size)
        return;

    struct Node* curr = obj->head;

    for (int i = 0; i < index; i++) {
        curr = curr->next;
    }

    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->val = val;

    node->next = curr->next;
    curr->next = node;

    obj->size++;
}

// Delete at index
void deleteAtIndex(struct MyLinkedList* obj, int index) {
    if (index < 0 || index >= obj->size)
        return;

    struct Node* curr = obj->head;

    for (int i = 0; i < index; i++) {
        curr = curr->next;
    }

    struct Node* temp = curr->next;
    curr->next = temp->next;

    free(temp);
    obj->size--;
}

// Print list (for testing)
void printList(struct MyLinkedList* obj) {
    struct Node* curr = obj->head->next;
    while (curr != NULL) {
        printf("%d -> ", curr->val);
        curr = curr->next;
    }
    printf("NULL\n");
}

// Main function
int main() {
    struct MyLinkedList* list = createLinkedList();

    addAtHead(list, 1);
    addAtTail(list, 3);
    addAtIndex(list, 1, 2);  // 1->2->3

    printList(list);

    printf("Value at index 1: %d\n", get(list, 1)); // 2

    deleteAtIndex(list, 1); // 1->3
    printList(list);

    return 0;
}