#include <stdio.h>
#include <stdlib.h>

// Node structure
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

// Function to check leaf
int isLeaf(struct Node* node) {
    if (node == NULL)
        return 0;
    return (node->left == NULL && node->right == NULL);
}

// Function to find sum of left leaves
int sumOfLeftLeaves(struct Node* root) {
    if (root == NULL)
        return 0;

    int sum = 0;

    // Check left child
    if (root->left != NULL) {
        if (isLeaf(root->left))
            sum += root->left->data;
        else
            sum += sumOfLeftLeaves(root->left);
    }

    // Always check right subtree
    sum += sumOfLeftLeaves(root->right);

    return sum;
}

int main() {
    // Create tree
    struct Node* root = createNode(3);
    root->left = createNode(9);
    root->right = createNode(20);
    root->right->left = createNode(15);
    root->right->right = createNode(7);

    int result = sumOfLeftLeaves(root);

    printf("Sum of left leaves = %d\n", result);

    return 0;
}