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

// Pre-order traversal (visit root, then left subtree, then right subtree)
void preOrder(struct Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data); // Visit root
        preOrder(root->left);      // Traverse left subtree
        preOrder(root->right);     // Traverse right subtree
    }
}

// In-order traversal (visit left subtree, then root, then right subtree)
void inOrder(struct Node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);       // Traverse left subtree
        printf("%d ", root->data); // Visit root
        inOrder(root->right);      // Traverse right subtree
    }
}

// Post-order traversal (visit left subtree, then right subtree, then root)
void postOrder(struct Node *root)
{
    if (root != NULL)
    {
        postOrder(root->left);     // Traverse left subtree
        postOrder(root->right);    // Traverse right subtree
        printf("%d ", root->data); // Visit root
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

    printf("Pre-order traversal: ");
    preOrder(root);
    printf("\n");

    printf("In-order traversal: ");
    inOrder(root);
    printf("\n");

    printf("Post-order traversal: ");
    postOrder(root);
    printf("\n");

    return 0;
}

