#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <ctype.h>

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
void searching_node();
void add_start();
void add_end();
void delete_start();
void delete_end();
void delete_entire_list();

int main()
{
    while (true)
    {
        menu();
        int option = 0;
        char ans;

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
            searching_node();
            break;
        case 5:
            add_start();
            break;
        case 6:
            add_end();
            break;
        case 7:
            delete_start();
            break;
        case 8:
            delete_end();
            break;
        case 9:
            delete_entire_list();
            break;
        case 10:
            printf("\nHappy Coding!\n\n");
            exit(0);
        default:
            printf("\nInvalid Option!\n");
        }
        // getchar();

        // do
        // {
        //     printf("\nPress \'ENTER\' to continue the program...");
        //     ans = getchar();
        //     if (ans == '\n')
        //         break;
        //     getchar();
        // } while (!(ans == '\n'));
        // ans = ' ';

        // system("clear");
    }
    return 0;
}

void menu()
{
    printf("\n*****MAIN MENU*****\n\n");
    printf("1. Create a list\n");
    printf("2. Display the list\n");
    printf("3. Display the list in reverse order\n");
    printf("4. Searching a given node\n");
    printf("5. Add a node at the beginning\n");
    printf("6. Add a node at the end\n");
    printf("7. Delete a node from the beginning\n");
    printf("8. Delete a node from the end\n");
    printf("9. Delete the entire list\n");
    printf("10. EXIT\n");
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

void searching_node()
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
        int node = 0;

        printf("\nEnter the element : ");
        scanf("%d", &node);

        while (ptr != NULL)
        {
            if (ptr->data == node)
            {
                printf("\nFound\n");
                return;
            }
            ptr = ptr->next;
        }
        printf("\nNot Found\n");
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