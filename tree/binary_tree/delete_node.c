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

// Function to find the minimum node in a subtree
struct Node *minValueNode(struct Node *node)
{
    struct Node *current = node;
    while (current->left != NULL)
    {
        current = current->left;
    }
    return current;
}

// Function to delete a node with the given key from BST
struct Node *deleteNode(struct Node *root, int key)
{
    if (root == NULL)
    {
        return root;
    }

    // Recursively descend the tree
    if (key < root->data)
    {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = deleteNode(root->right, key);
    }
    else
    {
        // Node found with the key - handle deletion based on children
        if (root->left == NULL)
        {
            // Case 1: Node with no children (leaf node)
            struct Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            // Case 2: Node with one child (left child)
            struct Node *temp = root->left;
            free(root);
            return temp;
        }
        else
        {
            // Case 3: Node with two children
            // Find inorder successor (smallest node in the right subtree)
            struct Node *temp = minValueNode(root->right);

            // Copy the inorder successor's data to the current node
            root->data = temp->data;

            // Recursively delete the inorder successor
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}

int findLargest(struct Node *root)
{
    if (root == NULL)
    {
        return -1; // Handle error or indicate no largest element
    }
    while (root->right != NULL)
    {
        root = root->right;
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

    printf("BST before deletion:\n");
    // ... (implement a function to display the BST)

    // Delete a node (replace with an example key)
    root = deleteNode(root, 80); // Example deletion

    printf("BST after deletion:\n");
    // ... (same function to display the BST)

    int largest = findLargest(root);
    if (largest != -1)
    {
        printf("Largest node: %d\n", largest);
    }
    else
    {
        printf("Error: Empty tree\n");
    }

    return 0;
}
