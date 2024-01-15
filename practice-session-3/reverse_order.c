#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void menu();
void create_list();
void display_list();
void reverse_order();

struct node
{
    struct node *pre;
    int data;
    struct node *next;
};

struct node *head = NULL;
struct node *tail = NULL;

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
            reverse_order();
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
    printf("2. Display the list\n");
    printf("3. Display the listin reverse order\n");
    printf("4. EXIT\n");
}

void create_list()
{
    struct node *ptr, *newNode;
    int num, node, count = 0;

    printf("\nInput the number of nodes : ");
    scanf("%d", &node);

    while (count < node)
    {
        printf("\nInput data for node %d: ", count + 1);
        scanf("%d", &num);

        newNode = (struct node *)(malloc(sizeof(struct node)));
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
        count += 1;
        node_count += 1;
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
        int node = 0;

        printf("\nData entered in the list are : \n");
        while (ptr != NULL)
        {
            printf("node %d : %d\n", (node + 1), ptr->data);
            ptr = ptr->next;
            node += 1;
        }
    }
}

void reverse_order()
{
    if (head == NULL)
    {
        printf("\nLinked List is empty!\n");
        return;
    }
    else
    {
        printf("\nData entered in the list are : \n");
        int temp = node_count;

        if (head->next == NULL)
        {
            printf("\nData 1 : %d\n", head->data);
        }
        else
        {
            struct node *ptr;
            ptr = tail;

            while (ptr != NULL)
            {
                printf("Data %d: %d\n", (temp), ptr->data);
                ptr = ptr->pre;
                temp -= 1;
            }
            printf("\n");
        }
    }
}
