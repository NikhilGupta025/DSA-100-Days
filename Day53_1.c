#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};


struct QNode {
    struct Node* node;
    int hd;
};

// Create node
struct Node* createNode(int val) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = val;
    temp->left = temp->right = NULL;
    return temp;
}

// Build tree from level order
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1)
        return NULL;

    struct Node* nodes[100];

    for (int i = 0; i < n; i++) {
        if (arr[i] != -1)
            nodes[i] = createNode(arr[i]);
        else
            nodes[i] = NULL;
    }

    for (int i = 0; i < n; i++) {
        if (nodes[i]) {
            int left = 2*i + 1;
            int right = 2*i + 2;

            if (left < n)
                nodes[i]->left = nodes[left];
            if (right < n)
                nodes[i]->right = nodes[right];
        }
    }

    return nodes[0];
}

// Vertical Order Traversal
void verticalOrder(struct Node* root) {
    if (root == NULL) return;

    struct QNode queue[100];
    int front = 0, rear = 0;

    // Store result using simple array
    int result[200][100];   // HD shifted by +100
    int count[200] = {0};

    // Enqueue root
    queue[rear++] = (struct QNode){root, 0};

    int minHD = 0, maxHD = 0;

    while (front < rear) {
        struct QNode temp = queue[front++];
        struct Node* node = temp.node;
        int hd = temp.hd;

        // Shift index by +100 to avoid negative index
        int index = hd + 100;

        result[index][count[index]++] = node->data;

        if (hd < minHD) minHD = hd;
        if (hd > maxHD) maxHD = hd;

        if (node->left)
            queue[rear++] = (struct QNode){node->left, hd - 1};
        if (node->right)
            queue[rear++] = (struct QNode){node->right, hd + 1};
    }

    // Print result
    for (int i = minHD; i <= maxHD; i++) {
        int index = i + 100;
        for (int j = 0; j < count[index]; j++) {
            printf("%d ", result[index][j]);
        }
        printf("\n");
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[100];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n);

    verticalOrder(root);

    return 0;
}