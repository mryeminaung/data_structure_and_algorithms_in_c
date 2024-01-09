#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void menu();
void create_list();
void display_list();
void even_odd();

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

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
            even_odd();
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
    printf("3. Count Even and Odd nodes\n");
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
        }
        printf("\n");
    }
}

void even_odd()
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
        int even = 0, odd = 0;

        while (ptr != NULL)
        {
            if ((ptr->data % 2) == 0)
                even += 1;
            else
                odd += 1;

            ptr = ptr->next;
        }
        printf("\nNumber of even nodes in the linked list = %d\n", even);
        printf("Number of odd nodes in the linked list = %d\n", odd);
    }
}
