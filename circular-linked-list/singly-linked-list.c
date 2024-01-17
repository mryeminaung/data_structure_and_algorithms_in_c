#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void main_menu();
void create_list();
void display_list();
void add_start();
void add_end();
void delete_start();
void delete_end();
void delete_entire_list();

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
            add_start();
            break;
        case 4:
            add_end();
            break;
        case 5:
            delete_start();
            break;
        case 6:
            delete_end();
            break;
        case 7:
            delete_entire_list();
            break;
        case 8:
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
    printf("3: Add a node at the beginning\n");
    printf("4: Add a node at the end\n");
    printf("5: Delete a node from the beginning\n");
    printf("6: Delete a node from the end\n");
    printf("7: Delete the entire list\n");
    printf("8: EXIT\n");
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

void delete_start()
{
    if (head == NULL)
    {
        printf("\nLinked list is empty!\n");
        return;
    }
    else
    {
        struct Node *ptr;
        ptr = head;

        if (ptr->next == head)
        {
            free(ptr);
            head = NULL;
            tail = NULL;
        }
        else
        {
            head = ptr->next;
            tail->next = ptr->next;
            free(ptr);
        }
    }
}

void delete_end()
{
    if (head == NULL)
    {
        printf("\nLinked list is empty!\n");
        return;
    }
    else
    {
        struct Node *ptr, *preptr;
        ptr = head;
        preptr = ptr;

        if (ptr->next == head)
        {
            free(ptr);
            head = NULL;
            tail = NULL;
        }
        else
        {
            while (ptr->next != head)
            {
                preptr = ptr;
                ptr = ptr->next;
            }
            preptr->next = ptr->next;
            tail = preptr;
            ptr->next = NULL;
            free(ptr);
        }
    }
}

void delete_entire_list()
{
    if (head == NULL)
    {
        printf("\nLinked list is empty!\n");
        return;
    }
    else
    {
        struct Node *ptr, *temp;
        ptr = head;

        do
        {
            temp = ptr->next;
            printf("\nNode %d is deleted.", ptr->data);
            free(ptr);
            ptr = temp;
        } while (ptr != head);

        head = NULL;

        printf("\n\nEntire Circular SLL is deleted!\n");
    }
}
