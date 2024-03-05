#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int);
struct Node *insert(struct Node *, int);
void displayLeafNodes(struct Node *, int, int);
void displayInternalNodes(struct Node *, int, int);
void preorder(struct Node *root);

int main()
{
    struct Node *root = NULL;
    int lowLeafNode, highLeafNode, lowInternalNode, highInternalNode;
    int num;

    printf("Enter numbers to insert into the BST\n");
    printf("\nEnter -1 to stop\n");

    while (true)
    {
        printf("Enter the element : ");
        scanf("%d", &num);

        if (num == -1)
            break;

        root = insert(root, num);
    }

    printf("\nEnter the low number for leaf node: ");
    scanf("%d", &lowLeafNode);
    printf("\n");
    printf("Enter the high number for leaf node: ");
    scanf("%d", &highLeafNode);
    printf("\n");
    printf("Enter the low number for internal node: ");
    scanf("%d", &lowInternalNode);
    printf("\n");
    printf("Enter the high number for internal node: ");
    scanf("%d", &highInternalNode);

    printf("\nLeaf nodes between  %d and %d (exclusive) are : \n", lowLeafNode, highLeafNode);
    displayLeafNodes(root, lowLeafNode, highLeafNode);

    printf("\nInternal nodes between %d and %d (exclusive) are: \n", lowInternalNode, highInternalNode);
    displayInternalNodes(root, lowInternalNode, highInternalNode);

    return 0;
}

struct Node *createNode(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node *insert(struct Node *root, int value)
{
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

void displayLeafNodes(struct Node *root, int low, int high)
{
    if (root == NULL)
        return;

    if (root->left == NULL && root->right == NULL && root->data > low && root->data < high)
        printf("Node -> %d\n", root->data);

    displayLeafNodes(root->left, low, high);
    displayLeafNodes(root->right, low, high);
}

void displayInternalNodes(struct Node *root, int low, int high)
{
    if (root == NULL)
        return;

    if (root->data > low && root->data < high && (root->left != NULL || root->right != NULL))
        printf("Node -> %d\n", root->data);

    displayInternalNodes(root->left, low, high);
    displayInternalNodes(root->right, low, high);
}

void preorder(struct Node *root)
{
    if (root == NULL)
        return;

    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}