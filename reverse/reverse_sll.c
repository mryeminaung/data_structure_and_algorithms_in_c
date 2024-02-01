#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void create_list();
void display_list();
void reverse();

void main()
{
    create_list();
    display_list();
    reverse();
    display_list();
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
    if (head == NULL)
    {
        printf("\n\nLinked List is empty!\n\n");
        return;
    }
    else
    {
        struct Node *ptr = head;
        printf("\n\nLinked List : ");
        while (ptr != NULL)
        {
            printf("\t%d", ptr->data);
            ptr = ptr->next;
        }
        printf("\n\n");
    }
}

void reverse()
{
    struct Node *ptr, *prev = NULL, *nextNode;
    ptr = head;

    while (ptr != NULL)
    {
        nextNode = ptr->next;
        ptr->next = prev;
        prev = ptr;
        ptr = nextNode;
    }
    head = prev;
} 