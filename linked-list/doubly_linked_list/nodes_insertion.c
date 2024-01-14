#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
    struct node *pre;
    int data;
    struct node *next;
};

struct node *head = NULL;
struct node *tail = NULL;

void menu();
void create_list();
void display_list();
void add_start();
void add_end();
void insert_before();
void insert_after();

int main()
{
    while (true)
    {
        menu();
        int option = 0;

        do
        {
            printf("\nEnter your option : ");
            scanf("%d", &option);
        } while (!(option >= 1 && option <= 7));

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
            insert_before();
            break;
        case 6:
            insert_after();
            break;
        case 7:
            printf("\nHappy Coding!\n\n");
            exit(0);
        default:
            printf("\nInvalid Option!\n");
        }
    }
    return 0;
}

void menu()
{
    printf("\n*****MAIN MENU*****\n\n");
    printf("1. Create a list\n");
    printf("2. Display the list\n");
    printf("3. Add a node at the beginning\n");
    printf("4. Add a node at the end\n");
    printf("5. Add a node before a given node\n");
    printf("6. Add a node after a given node\n");
    printf("7. EXIT\n");
}

void create_list()
{
    int num = 0;
    printf("\nEnter -1 to end\n");
    while (true)
    {
        printf("\nEnter the data : ");
        scanf("%d", &num);

        if (num == -1)
            break;

        struct node *newNode = (struct node *)malloc(sizeof(struct node));
        newNode->pre = NULL;
        newNode->data = num;
        newNode->next = NULL;

        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            struct node *ptr;
            ptr = head;

            while (ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            newNode->pre = ptr;
            ptr->next = newNode;
            tail = newNode;
        }
    }
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
        struct node *ptr;
        ptr = head;

        printf("\nLinked List : ");
        while (ptr != NULL)
        {
            printf("\t%d", ptr->data);
            ptr = ptr->next;
        }
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
        struct node *ptr, *newNode;
        ptr = head;
        int num;

        printf("\nEnter the data : ");
        scanf("%d", &num);

        newNode = (struct node *)malloc(sizeof(struct node));

        newNode->pre = NULL;
        newNode->data = num;
        ptr->pre = newNode;
        newNode->next = ptr;
        head = newNode;
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
        struct node *ptr, *newNode;
        ptr = tail;
        int num = 0;

        newNode = (struct node *)malloc(sizeof(struct node));

        printf("\nEnter the data : ");
        scanf("%d", &num);

        ptr->next = newNode;
        newNode->pre = ptr;
        newNode->data = num;
        newNode->next = NULL;
        tail = newNode;
    }
}

void insert_before()
{
    if (head == NULL)
    {
        printf("\nLinked list is empty!\n");
        return;
    }
    else
    {
        struct node *ptr, *newNode;
        ptr = head;
        int node, num;

        printf("\nEnter a node to insert before it : ");
        scanf("%d", &node);

        if (ptr->data == node)
        {
            add_start();
        }
        else
        {
            while (ptr->data != node)
            {
                if (ptr->next == NULL)
                {
                    printf("\n%d is not in the list!!!\n", node);
                    return;
                }
                ptr = ptr->next;
            }

            printf("\nEnter the data : ");
            scanf("%d", &num);
            newNode = (struct node *)malloc(sizeof(struct node));

            newNode->data = num;
            newNode->next = ptr;
            newNode->pre = ptr->pre;
            ptr->pre->next = newNode;
            ptr->pre = newNode;
        }
    }
}

void insert_after()
{
    if (head == NULL)
    {
        printf("\nLinked list is empty!\n");
        return;
    }
    else
    {
        struct node *ptr, *newNode;
        ptr = head;
        int node, num;

        printf("\nEnter a node to insert after it : ");
        scanf("%d", &node);

        if (tail->data == node)
            add_end();
        else
        {
            while (ptr->data != node)
            {
                if (ptr->next == NULL)
                {
                    printf("\n%d is not in the list!!!\n", node);
                    return;
                }
                ptr = ptr->next;
            }

            printf("\nEnter the data : ");
            scanf("%d", &num);

            newNode = (struct node *)malloc(sizeof(struct node));

            newNode->data = num;
            newNode->next = ptr->next;
            newNode->pre = ptr;
            ptr->next = newNode;
            newNode->next->pre = newNode;
        }
    }
}