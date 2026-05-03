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

// Find LCA in BST
struct Node* findLCA(struct Node* root, int p, int q) {
    if (root == NULL)
        return NULL;

    // If both values are smaller → go left
    if (p < root->data && q < root->data)
        return findLCA(root->left, p, q);

    // If both values are greater → go right
    if (p > root->data && q > root->data)
        return findLCA(root->right, p, q);

    // Otherwise, this is the LCA
    return root;
}

int main() {
    int n;
    scanf("%d", &n);

    struct Node* root = NULL;

    // Input BST
    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        root = insert(root, val);
    }

    int p, q;
    scanf("%d %d", &p, &q);

    struct Node* lca = findLCA(root, p, q);

    if (lca != NULL)
        printf("%d\n", lca->data);

    return 0;
}