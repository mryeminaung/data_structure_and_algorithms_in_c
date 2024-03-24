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

int findSmallest(struct Node *root)
{
    if (root == NULL)
    {
        return -1; // Handle error or indicate no smallest element
    }
    while (root->left != NULL)
    {
        root = root->left;
        printf("%d -> ", root->data);
    }
    return root->data;
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

    int smallest = findSmallest(root);
    if (smallest != -1)
    {
        printf("Smallest node: %d\n", smallest);
    }
    else
    {
        printf("Error: Empty tree\n");
    }
    return 0;
}
