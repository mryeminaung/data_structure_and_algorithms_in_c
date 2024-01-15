#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void menu();
void create_list();
void display_list();
void min_max();

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
            min_max();
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
    printf("3. Find Min and Max nodes\n");
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
        count += 1;
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

void min_max()
{
    if (head == NULL)
    {
        printf("\nLinked list is empty!\n");
        return;
    }
    else
    {
        int min_node, max_node;
        struct node *ptr;
        ptr = head;
        min_node = max_node = ptr->data;

        while (ptr != NULL)
        {
            if (ptr->data > max_node)
                max_node = ptr->data;
            else if (ptr->data <= min_node)
                min_node = ptr->data;

            ptr = ptr->next;
        }

        printf("\nThe Minimum Value in the Linked List : %d\n", min_node);
        printf("\nThe Maximum Value in the Linked List : %d\n", max_node);
    }
}
