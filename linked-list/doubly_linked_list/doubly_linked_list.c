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
void reverse_list();
void delete_start();
void delete_end();
void delete_entire_list();

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
            reverse_list();
            break;
        case 4:
            delete_start();
            break;
        case 5:
            delete_end();
            break;
        case 6:
            delete_entire_list();
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
    printf("3. Display the list in reverse order\n");
    printf("4. Delete a node at start\n");
    printf("5. Delete a node at end\n");
    printf("6. Delete the entire list\n");
    printf("7. EXIT\n");
}

void create_list()
{
    int num = 0;
    printf("\nEnter -1 to end\n");
    while (true)
    {
        printf("Enter the data : ");
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

void reverse_list()
{
    if (head == NULL)
    {
        printf("\nLinked List is empty!\n");
        return;
    }
    else
    {
        if (head->next == NULL)
        {
            printf("\nReversed List : %d\n", head->data);
        }
        else
        {
            struct node *ptr;
            ptr = tail;

            printf("\nReversed List : ");
            while (ptr != NULL)
            {
                printf("%d\t", ptr->data);
                ptr = ptr->pre;
            }
            printf("\n");
        }
    }
}

void delete_start()
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

        head = ptr->next;
        head->pre = NULL;
        free(ptr);
    }
}

void delete_end()
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

        if (ptr->next == NULL)
        {
            free(ptr);
            head = NULL;
        }
        else
        {
            while (ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            tail = ptr->pre;
            tail->next = NULL;
            free(ptr);
        }
    }
}

void delete_entire_list()
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

        while (ptr != NULL)
        {
            head = ptr->pre;
            ptr = ptr->next;
            free(ptr);
        }
        head = NULL;
        tail = NULL;
    }
    printf("\nEntire list is deleted!\n");
}