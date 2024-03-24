#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *newNode(int data)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

struct Node *insert(struct Node *node, int data)
{
    if (node == NULL)
    {
        return newNode(data);
    }
    if (data < node->data)
    {
        node->left = insert(node->left, data);
    }
    else if (data > node->data)
    {
        node->right = insert(node->right, data);
    }
    return node;
}

// Function to delete the entire BST
void deleteTree(struct Node *root)
{
    if (root != NULL)
    {
        deleteTree(root->left);  // Delete left subtree
        deleteTree(root->right); // Delete right subtree
        free(root);              // Free memory for current node
    }
}

int main()
{
    struct Node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    printf("BST before deletion:\n");
    // ... (implement a function to display the BST)

    // Delete the entire BST
    deleteTree(root);
    root = NULL; // Set root to NULL to indicate empty tree

    printf("BST after deletion:\n");
    // ... (same function to display the BST - should show empty tree)

    return 0;
}
