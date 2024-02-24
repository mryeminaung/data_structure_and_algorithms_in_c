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
void inorder(struct node *);
void preorder(struct node *);
void postorder(struct node *);

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

    printf("Inorder traversal of the BST: \n");
    inorder(root);
    printf("\n\n");

    printf("Preorder traversal of the BST: \n");
    preorder(root);
    printf("\n\n");

    printf("Postorder traversal of the BST: \n");
    postorder(root);
    printf("\n\n");

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

void inorder(struct node *root)
{
    if (root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void preorder(struct node *root)
{
    if (root == NULL)
        return;

    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct node *root)
{
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}