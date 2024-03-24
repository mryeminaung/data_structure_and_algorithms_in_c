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

// Function to count internal nodes in a BST
int totalInternalNodes(struct Node *root)
{
    if (root == NULL)
    { // Base case (empty tree)
        return 0;
    }
    else if (root->left == NULL && root->right == NULL)
    { // Leaf node
        return 0;
    }
    else
    {                                            // Internal node
        return totalInternalNodes(root->left) +  // Count internal nodes in left subtree
               totalInternalNodes(root->right) + // Count internal nodes in right subtree
               1;                                // Add 1 for the current internal node
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

    int internalNodes = totalInternalNodes(root);
    printf("Number of internal nodes: %d\n", internalNodes);

    return 0;
}
