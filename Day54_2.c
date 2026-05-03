#include <stdio.h>
#include <stdlib.h>

// Tree Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create node
struct Node* createNode(int val) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = val;
    temp->left = temp->right = NULL;
    return temp;
}

// Queue
struct Queue {
    struct Node* arr[100];
    int front, rear;
};

void initQueue(struct Queue* q) {
    q->front = q->rear = -1;
}

int isEmpty(struct Queue* q) {
    return q->front == -1;
}

int size(struct Queue* q) {
    if (isEmpty(q)) return 0;
    return q->rear - q->front + 1;
}

void enqueue(struct Queue* q, struct Node* node) {
    if (q->rear == 99) return;
    if (q->front == -1) q->front = 0;
    q->arr[++q->rear] = node;
}

struct Node* dequeue(struct Queue* q) {
    if (isEmpty(q)) return NULL;
    struct Node* temp = q->arr[q->front];
    if (q->front == q->rear)
        q->front = q->rear = -1;
    else
        q->front++;
    return temp;
}

// Zigzag traversal
void zigzagLevelOrder(struct Node* root) {
    if (root == NULL) return;

    struct Queue q;
    initQueue(&q);
    enqueue(&q, root);

    int leftToRight = 1;

    while (!isEmpty(&q)) {
        int levelSize = size(&q);
        int temp[100];

        // Collect current level
        for (int i = 0; i < levelSize; i++) {
            struct Node* curr = dequeue(&q);
            temp[i] = curr->data;

            if (curr->left)
                enqueue(&q, curr->left);
            if (curr->right)
                enqueue(&q, curr->right);
        }

        // Print based on direction
        if (leftToRight) {
            for (int i = 0; i < levelSize; i++)
                printf("%d ", temp[i]);
        } else {
            for (int i = levelSize - 1; i >= 0; i--)
                printf("%d ", temp[i]);
        }

        printf("\n");
        leftToRight = !leftToRight;
    }
}

int main() {
    // Example tree
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    zigzagLevelOrder(root);

    return 0;
}