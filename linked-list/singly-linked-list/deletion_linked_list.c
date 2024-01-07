#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void menu();
void create_list();
void display_list();
void delete_start();
void delete_end();
void delete_given_node();
void delete_after();
void delete_list();

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

int main()
{
    int option;

    while (true)
    {
        menu();
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
            delete_start();
            break;
        case 4:
            delete_end();
            break;
        case 5:
            delete_given_node();
            break;
        case 6:
            delete_after();
            break;
        case 7:
            delete_list();
            break;
        case 8:
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
    printf("\n*****MAIN MENU*****\n");
    printf("1. Create a list\n");
    printf("2. Display the list\n");
    printf("3. Delete a node from the beginning\n");
    printf("4. Delete a node from the end\n");
    printf("5. Delete a given node\n");
    printf("6. Delete a node after a given node\n");
    printf("7. Delete the entire list\n");
    printf("8. EXIT\n");
}

void create_list()
{
    struct node *ptr, *newNode;
    int num;

    printf("\nEnter -1 to end\n");

    while (true)
    {
        printf("\nEnter the data : ");
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

        printf("\nLinked List : ");
        while (ptr != NULL)
        {
            printf("\t%d", ptr->data);
            ptr = ptr->next;
        }
        printf("\n");
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
        struct node *ptr;
        ptr = head;
        head = ptr->next;
        free(ptr);
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
        struct node *ptr, *preptr;
        ptr = head;
        preptr = ptr;

        if (ptr->next == NULL)
        {
            free(ptr);
            head = NULL;
        }
        else
        {
            while (ptr->next != NULL)
            {
                preptr = ptr;
                ptr = ptr->next;
            }
            preptr->next = NULL;

            free(ptr);
        }
    }
}

void delete_given_node()
{
}

void delete_after()
{
}

void delete_list()
{
    if (head == NULL)
    {
        printf("\nLinked List is empty!\n");
        return;
    }
    else
    {
        struct node *ptr, *preptr;
        ptr = head;
        preptr = ptr;

        while (ptr != NULL)
        {
            preptr = ptr;
            head = preptr;
            ptr = ptr->next;
            free(preptr);
        }
        head = NULL;
        printf("\nLinked List is deleted!\n");
    }
}