#include<stdio.h>
#include<stdlib.h>

// Node structure
struct node
{
    int data;
    struct node *left;
    struct node *right;
};

// create tree recursively
struct node* create()
{
    int x;

    printf("Enter value (-1 for no node): ");
    scanf("%d", &x);

    // base case
    if(x == -1)
        return NULL;

    // create node
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = x;

    // create left subtree
    printf("Enter left child of %d\n", x);
    newNode->left = create();

    // create right subtree
    printf("Enter right child of %d\n", x);
    newNode->right = create();

    return newNode;
}

// inorder traversal
void inorder(struct node* root)
{
    if(root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}




int main()
{
    struct node* root;

    root = create();

    printf("\nInorder Traversal: ");
    inorder(root);

    // printf("\nPreorder Traversal: ");
    // preorder(root);

    // printf("\nPostorder Traversal: ");
    // postorder(root);

    return 0;
}