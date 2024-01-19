#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;
struct node *tail = NULL;

void menu();
void create_list();
void display_list();
void show_pair();

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
        } while (!(option >= 1 && option <= 4));

        switch (option)
        {
        case 1:
            create_list();
            break;
        case 2:
            display_list();
            break;
        case 3:
            show_pair();
            break;
        case 4:
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
    printf("3. Display the pair\n");
    printf("4. EXIT\n");
}

void create_list()
{
    struct node *ptr, *newNode;
    int num = 0;

    printf("\nEnter -999 to end\n");
    while (true)
    {
        printf("\nEnter the data : ");
        scanf("%d", &num);

        if (num == -999)
            break;

        newNode = (struct node *)malloc(sizeof(struct node));
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
            newNode->next = NULL;
        }
    }
    printf("\nSingly Linked List Created\n");
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
        struct node *ptr = head;

        printf("\nLinked List ");
        do
        {
            printf("%d", ptr->data);
            if (ptr->next != NULL)
                printf(" => ");
            ptr = ptr->next;
        } while (ptr != NULL);
        printf("\n");
    }
}

void show_pair()
{
    if (head == NULL)
    {
        printf("\nLinked List is empty!\n");
        return;
    }
    else
    {
        struct node *ptr, *temp;
        ptr = head;
        int pair = 0;
        int isFound = false;

        printf("\nEnter the value to find a pair : ");
        scanf("%d", &pair);

        while (ptr != NULL)
        {
            temp = ptr->next;

            while (temp != NULL)
            {
                if (ptr->data + temp->data == pair)
                {
                    printf("(%d,%d)  ", ptr->data, temp->data);
                    isFound = true;
                }
                temp = temp->next;
            }
            ptr = ptr->next;
        }
        printf("\n");

        if (!isFound)
        {
            printf("\nNo pair found\n");
        }
    }
}
