#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void main_menu();
void create_list();
void display_list();
void count_node();
void append_list();
void add_start();
void add_end();
void insert_before();
void insert_after();
void searching_node();

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

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
        } while (!(option >= 1 && option <= 10));

        switch (option)
        {
        case 1:
            create_list();
            break;
        case 2:
            display_list();
            break;
        case 3:
            append_list();
            break;
        case 4:
            count_node();
            break;
        case 5:
            add_start();
            break;
        case 6:
            add_end();
            break;
        case 7:
            insert_before();
            break;
        case 8:
            insert_after();
            break;
        case 9:
            searching_node();
            break;
        case 10:
            printf("\nHappy Coding!\n\n");
            exit(0);
            break;
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
    printf("3: Append to the previous list\n");
    printf("4: Number of nodes\n");
    printf("5: Add a node at the beginning\n");
    printf("6: Add a node at the end\n");
    printf("7: Add a node before a given node\n");
    printf("8: Add a node after a given node\n");
    printf("9: Searching a node\n");
    printf("10: EXIT\n");
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
        newNode->next = NULL;

        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            ptr = head;
            while (ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            ptr->next = newNode;
        }
    }
    printf("\n\nLINKED LIST CREATED\n\n");
}

void display_list()
{
    if (head == NULL)
    {
        printf("\n\nLinked List is empty!\n\n");
        return;
    }
    else
    {
        struct Node *ptr = head;
        printf("\n\nLinked List : ");
        while (ptr != NULL)
        {
            printf("\t%d", ptr->data);
            ptr = ptr->next;
        }
        printf("\n\n");
    }
}

void append_list()
{
    if (head == NULL)
    {
        printf("\n\nLinked List is empty!\n\n");
        return;
    }
    else
    {
    }
}

void count_node()
{
    if (head == NULL)
    {
        printf("\n\nLinked List is empty!\n\n");
        return;
    }
    else
    {
        int count = 0;
        struct Node *ptr = head;

        while (ptr != NULL)
        {
            count += 1;
            ptr = ptr->next;
        }

        printf("\nTotal number of nodes : %d\n\n", count);
    }
}

void add_start()
{
    if (head == NULL)
    {
        printf("\n\nLinked List is empty!\n\n");
        return;
    }
    else
    {
        struct Node *newNode;
        int num;

        printf("\nEnter the data : ");
        scanf("%d", &num);

        newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = num;
        newNode->next = head;
        head = newNode;
    }
}

void add_end()
{
    if (head == NULL)
    {
        printf("\n\nLinked List is empty!\n\n");
        return;
    }
    else
    {
        struct Node *ptr, *newNode;
        int num;

        printf("\nEnter the data : ");
        scanf("%d", &num);

        newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = num;
        newNode->next = NULL;

        ptr = head;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = newNode;
    }
}

void insert_before()
{
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
        int node, num;

        printf("\nEnter a node to insert after it : ");
        scanf("%d", &node);
        printf("\nEnter the data : ");
        scanf("%d", &num);

        ptr = head;
        preptr = ptr;

        newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = num;

        while (preptr->data != node)
        {
            preptr = ptr;
            ptr = ptr->next;
        }

        newNode->next = ptr;
        preptr->next = newNode;
    }
}

void searching_node()
{
    if (head == NULL)
    {
        printf("\n\nLinked List is empty!\n\n");
        return;
    }
    else
    {
        struct Node *ptr = head;
        int num;

        printf("\nEnter the data : ");
        scanf("%d", &num);

        while (ptr != NULL)
        {
            if (ptr->data == num)
            {
                printf("\n\nFound\n\n");
                return;
            }
            else
                ptr = ptr->next;
        }
        printf("\n\nNot Found\n\n");
    }
}