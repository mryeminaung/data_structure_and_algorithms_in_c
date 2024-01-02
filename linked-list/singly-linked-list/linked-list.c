#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void main_menu();
void create_list();
void display_list();
void print_number_of_node();
void add_start();
void add_end();
void add_before();
void add_after();

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
        } while (!(option >= 1 && option <= 9));

        switch (option)
        {
        case 1:
            create_list();
            break;
        case 2:
            display_list();
            break;
        case 3:
            print_number_of_node();
            break;
        case 4:
            add_start();
            break;
        case 5:
            add_end();
            break;
        case 6:
            add_before();
            break;
        case 7:
            add_after();
            break;
        case 8:
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
    printf("1: Create a list\n");
    printf("2: Display the list\n");
    printf("3: Print the number of node in the linked list\n");
    printf("4: Add a node at the beginning\n");
    printf("5: Add a node at the end\n");
    printf("6: Add a node before a given node\n");
    printf("7: Add a node after a given node\n");
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
    struct Node *ptr;
    ptr = head;

    while (ptr != NULL)
    {
        printf("%d\t", ptr->data);
        ptr = ptr->next;
    }

    printf("NULL\n\n");
}

void print_number_of_node()
{
}

void add_start()
{
}

void add_end()
{
}

void add_before()
{
}

void add_after()
{
}