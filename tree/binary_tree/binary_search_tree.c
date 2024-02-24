#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *left;
    int data;
    struct node *right;
};

struct node *createNode(int value);
struct node *insertNode(struct node *, int value);
struct node *searchNode(struct node *, int value);
int findLargestNode(struct node *);

int main()
{
    struct node *root = NULL;

    root = insertNode(root, 50);
    insertNode(root, 30);
    insertNode(root, 20);
    insertNode(root, 40);
    insertNode(root, 70);
    insertNode(root, 60);
    insertNode(root, 80);

    int largest = findLargestNode(root);
    printf("The largest element in the BST is: %d\n", largest);

    return 0;
}

struct node *createNode(int value)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
}

struct node *insertNode(struct node *root, int value)
{
    if (root == NULL)
    {
        return createNode(value);
    }
    if (value < root->data)
    {
        root->left = insertNode(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = insertNode(root->right, value);
    }
    return root;
}

struct node *searchNode(struct node *root, int value)
{
    if (root == NULL || root->data == value)
        return root;
    else if (root->data > value)
        return searchNode(root->left, value);
    else
        return searchNode(root->right, value);
}

int findLargestNode(struct node *root)
{
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root->data;
}
