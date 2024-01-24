#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;

void create_list();
void display_list();
void rearrange_list();

int main()
{
    create_list();

    printf("\nOriginal List : ");
    display_list();

    rearrange_list();

    printf("\nRearrange List : ");
    display_list();
}

void create_list()
{
    int num = 0;
    printf("\nEnter -999 to end\n");

    while (true)
    {
        printf("\nEnter the data : ");
        scanf("%d", &num);

        if (num == -999)
            break;

        struct node *newNode = (struct node *)malloc(sizeof(struct node));
        newNode->prev = NULL;
        newNode->data = num;
        newNode->next = NULL;

        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            struct node *ptr;
            ptr = head;

            while (ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            newNode->prev = ptr;
            ptr->next = newNode;
        }
    }
    printf("\nDoubly Linked List is created!\n");
}

void display_list()
{
    if (head == NULL)
    {
        printf("\nDoubly Linked List is empty!\n");
        return;
    }
    else
    {
        struct node *ptr;
        ptr = head;

        while (ptr != NULL)
        {
            printf("%d", ptr->data);
            if (ptr->next != NULL)
                printf(" <=> ");
            ptr = ptr->next;
        }
        printf("\n");
    }
}

void rearrange_list()
{
    if (head == NULL)
    {
        printf("\nDoubly Linked List is empty!\n");
        return;
    }
    else
    {
        struct node *ptr, *prePtr, *temp;
        ptr = head;
        prePtr = ptr;

        while (ptr->next != NULL)
        {
            prePtr = ptr;
            ptr = ptr->next;
        }

        temp = ptr;
        prePtr->next = NULL;

        temp->next = head->next;
        head->next->prev = temp;

        temp->prev = head;
        head->next = temp;
        free(temp);
    }
}