#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void menu();
void create_list();
void display_list();
void rotate_list();
void rotate(int rotation);

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;
int node_count = 0;

int main()
{
    while (true)
    {
        menu();
        int option;
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
            rotate_list();
            break;
        case 4:
            printf("\nHappy Coding!\n");
            exit(0);
        default:
            break;
        }
    }
    return 0;
}

void menu()
{
    printf("\n*****MENU OPTION*****\n");
    printf("1. Create a list\n");
    printf("2. Display a list\n");
    printf("3. Rotating the list with n times\n");
    printf("4. EXIT\n");
}

void create_list()
{
    struct node *ptr, *newNode;
    int num;

    printf("\nEnter -1 to end\n");

    while (true)
    {
        printf("\nEnter the element : ");
        scanf("%d", &num);

        if (num == -1)
            break;

        newNode = (struct node *)(malloc(sizeof(struct node)));
        newNode->data = num;
        newNode->next = NULL;

        if (head == NULL)
            head = newNode;
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
        printf("\nLinked list is empty!\n");
        return;
    }
    else
    {
        struct node *ptr;
        ptr = head;

        printf("\nThe nodes in the linked list : ");

        while (ptr != NULL)
        {
            printf("\t%d", ptr->data);
            if (ptr->next != NULL)
                printf("  ->");
            ptr = ptr->next;
            node_count += 1;
        }
        printf("\n");
    }
}

void rotate_list()
{
    if (head == NULL)
    {
        printf("\nLinked list is empty!\n");
        return;
    }
    else
    {
        int rotation = 0;

        printf("\nEnter Rotate Times : ");
        scanf("%d", &rotation);

        printf("\nBefore Rotation : ");
        display_list();

        printf("\nAfter Rotation %d times : ", rotation);
        if (rotation == node_count)
            display_list();
        else
        {
            rotate(rotation);
            display_list();
        }
    }
}

void rotate(int rotation)
{
    if (head == NULL)
    {
        printf("\nLinked list is empty!\n");
        return;
    }
    else
    {
        for (int count = 0; count < rotation; count++)
        {
            struct node *ptr, *preptr;
            ptr = head;
            preptr = ptr;
            while (ptr->next != NULL)
            {
                preptr = ptr;
                ptr = ptr->next;
            }
            preptr->next = NULL;
            ptr->next = head;
            head = ptr;
        }
    }
}