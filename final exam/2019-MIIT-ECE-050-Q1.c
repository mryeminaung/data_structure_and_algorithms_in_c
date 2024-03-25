#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

int num = 0;
int count = 0;
int smallest_element = 0;

struct Node *newNode(int data);
struct Node *insertNode(struct Node *root, int data);
void inOrder(struct Node *root);
int countNodes(struct Node *root);

int main()
{
    struct Node *root = NULL;

    root = insertNode(root, 20);
    insertNode(root, 8);
    insertNode(root, 22);
    insertNode(root, 4);
    insertNode(root, 12);
    insertNode(root, 10);
    insertNode(root, 14);

    printf("\nEnter the element : ");
    scanf("%d", &num);

    if (num > countNodes(root))
    {
        printf("\nInput is greater than the number of nodes in BST.\n");
    }
    else
    {
        printf("\nIn-order traversal: ");
        inOrder(root);
        printf("\n\nThe Kth smallest element in BST : %d\n", smallest_element);
    }
    return 0;
}

struct Node *newNode(int data)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

struct Node *insertNode(struct Node *root, int data)
{
    if (root == NULL)
    {
        return newNode(data);
    }
    if (data < root->data)
    {
        root->left = insertNode(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = insertNode(root->right, data);
    }
    return root;
}

void inOrder(struct Node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d ", root->data);
        count += 1;
        if (count == num)
            smallest_element = root->data;
        inOrder(root->right);
    }
}

int countNodes(struct Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return countNodes(root->left) + countNodes(root->right) + 1;
}
