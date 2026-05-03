#include <stdio.h>
#include <stdlib.h>

// Define structure of a node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to find maximum depth
int maxDepth(struct Node* root) {
    // Base case
    if (root == NULL)
        return 0;

    // Find left and right depth
    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);

    // Return max + 1
    if (leftDepth > rightDepth)
        return leftDepth + 1;
    else
        return rightDepth + 1;
}

int main() {
    // Creating tree manually
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);

    int depth = maxDepth(root);

    printf("Maximum Depth = %d\n", depth);

    return 0;
}