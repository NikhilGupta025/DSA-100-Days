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

// Insert into BST
struct Node* insert(struct Node* root, int val) {
    if (root == NULL)
        return createNode(val);

    if (val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}

// LCA function
struct Node* lowestCommonAncestor(struct Node* root, int p, int q) {
    if (root == NULL)
        return NULL;

    // If both values are smaller → go left
    if (p < root->data && q < root->data)
        return lowestCommonAncestor(root->left, p, q);

    // If both values are greater → go right
    if (p > root->data && q > root->data)
        return lowestCommonAncestor(root->right, p, q);

    // Otherwise, this node is LCA
    return root;
}

int main() {
    struct Node* root = NULL;

    // Example BST
    int values[] = {6, 2, 8, 0, 4, 7, 9, 3, 5};
    int n = 9;

    for (int i = 0; i < n; i++)
        root = insert(root, values[i]);

    int p = 2, q = 8;

    struct Node* lca = lowestCommonAncestor(root, p, q);

    if (lca != NULL)
        printf("LCA = %d\n", lca->data);

    return 0;
}