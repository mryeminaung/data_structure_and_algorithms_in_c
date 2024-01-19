#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void main_menu();
void create_list();
void display_list();
void insert_before();
void insert_after();

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;
struct Node *tail = NULL;

int main()
{
    int option;

    while (true)
    {
        main_menu();
        do
        {
            printf("\nEnter your option : ");
            scanf("%d", &option);
        } while (!(option >= 1 && option <= 8));

        switch (option)
        {
        case 1:
            create_list();
            break;
        case 2:
            display_list();
            break;
        case 3:
            insert_before();
            break;
        case 4:
            insert_after();
            break;
        case 5:
            printf("\nHappy Coding!\n\n");
            exit(0);
        default:
            printf("\nInvalid Option!\n");
        }
    }

    return 0;
}

void main_menu()
{
    printf("\n***** MAIN MENU *****\n");
    printf("1: Create a new list\n");
    printf("2: Display the list\n");
    printf("3: Add a node before a given node\n");
    printf("4: Add a node after a given node\n");
    printf("5: EXIT\n");
}

void create_list()
{
    struct Node *ptr, *newNode;
    int num = 0;

    printf("\nEnter -1 to end\n");
    while (true)
    {
        printf("\nEnter the data : ");
        scanf("%d", &num);

        if (num == -1)
            break;

        newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = num;

        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
            newNode->next = head;
            newNode->next = tail;
        }
        else
        {
            ptr = head;
            while (ptr->next != head)
            {
                ptr = ptr->next;
            }
            ptr->next = newNode;
            newNode->next = head;
            tail = newNode;
        }
    }
    printf("\nCircular Singly Linked List Created\n");
}

void display_list()
{
    if (head == NULL)
    {
        printf("\nLinked List is empty!\n");
        return;
    }
    else
    {
        struct Node *ptr = head;

        printf("\nCircular SLL : ");
        do
        {
            printf("%d", ptr->data);
            if (ptr->next != head)
                printf(" -> ");
            ptr = ptr->next;
        } while (ptr != tail->next);

        // printf("\n\nFirst Node : %p", head);
        // printf("\nLast node : %p", tail);
        // printf("\nLast node->next : %p", tail->next);

        printf("\n");
    }
}

void add_start()
{
    if (head == NULL)
    {
        printf("\nLinked List is empty!\n");
        return;
    }
    else
    {
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        int num = 0;

        printf("\nEnter the data : ");
        scanf("%d", &num);

        newNode->data = num;
        newNode->next = head;
        head = newNode;
        tail->next = head;
    }
}

void add_end()
{
    if (head == NULL)
    {
        printf("\nLinked List is empty!\n");
        return;
    }
    else
    {
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        int num = 0;

        printf("\nEnter the data : ");
        scanf("%d", &num);

        tail->next = newNode;
        newNode->data = num;
        newNode->next = head;
        tail = newNode;
    }
}

void insert_before()
{
    if (head == NULL)
    {
        printf("\n\nLinked List is empty!\n\n");
        return;
    }
    else
    {
        struct Node *ptr, *preptr, *newNode;
        ptr = head;
        preptr = ptr;
        int node, num;

        printf("\nEnter a node to insert before it : ");
        scanf("%d", &node);

        if (ptr->data == node)
        {
            add_start();
        }
        else
        {
            do
            {
                if (ptr->next == NULL)
                {
                    printf("\n%d is not in the list!!!\n", node);
                    return;
                }
                preptr = ptr;
                ptr = ptr->next;
            } while (ptr->data != node);

            printf("\nEnter the data : ");
            scanf("%d", &num);

            newNode = (struct Node *)malloc(sizeof(struct Node));
            newNode->data = num;

            newNode->next = ptr;
            preptr->next = newNode;
        }
    }
}

void insert_after()
{
    if (head == NULL)
    {
        printf("\n\nLinked List is empty!\n\n");
        return;
    }
    else
    {
        struct Node *ptr, *preptr, *newNode;
        ptr = head;
        preptr = ptr;
        int node, num;

        printf("\nEnter a node to insert after it : ");
        scanf("%d", &node);

        if (tail->data == node)
            add_end();
        else
        {
            do
            {
                preptr = ptr;
                ptr = ptr->next;
                if (ptr->next == NULL)
                {
                    printf("\n%d is not in the list!!!\n", node);
                    return;
                }
            } while (preptr->data != node);

            printf("\nEnter the data : ");
            scanf("%d", &num);

            newNode = (struct Node *)malloc(sizeof(struct Node));
            newNode->data = num;

            preptr->next = newNode;
            newNode->next = ptr;
        }
    }
}