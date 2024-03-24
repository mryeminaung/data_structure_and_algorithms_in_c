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

// Function to count external nodes (leaf nodes) in a BST
int totalExternalNodes(struct Node *root)
{
    if (root == NULL)
    { // Base case (empty tree)
        return 0;
    }
    else if (root->left == NULL && root->right == NULL)
    { // Leaf node
        return 1;
    }
    else
    {                                           // Internal node
        return totalExternalNodes(root->left) + // Count external nodes in left subtree
               totalExternalNodes(root->right); // Count external nodes in right subtree
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

    int externalNodes = totalExternalNodes(root);
    printf("Number of external nodes (leaf nodes): %d\n", externalNodes);

    return 0;
}
