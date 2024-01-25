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
void swap(struct Node *a, struct Node *b);
void sort_asc();
void sort_desc();

void main()
{
    create_list();
    printf("\nOriginal list : \n");
    display_list();

    sort_asc();
    printf("\nSort in asc : \n");
    display_list();

    sort_desc();
    printf("\nSort in desc : \n");
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

void sort_asc()
{
    struct Node *ptr, *tail;
    ptr = head;
    tail = NULL;
    int swapped = false;

    do
    {
        swapped = false;
        ptr = head;

        while (ptr->next != tail)
        {
            if (ptr->data > ptr->next->data)
            {
                swap(ptr, ptr->next);
                swapped = true;
            }
            ptr = ptr->next;
        }
        tail = ptr;

    } while (swapped);
}

void sort_desc()
{
    struct Node *ptr, *tail;
    ptr = head;
    tail = NULL;
    int swapped = false;

    do
    {
        swapped = false;
        ptr = head;

        while (ptr->next != tail)
        {
            if (ptr->data < ptr->next->data)
            {
                swap(ptr, ptr->next);
                swapped = true;
            }
            ptr = ptr->next;
        }
        tail = ptr;

    } while (swapped);
}

void swap(struct Node *a, struct Node *b)
{
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}