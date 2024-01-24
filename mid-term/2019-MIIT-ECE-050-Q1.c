#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;
struct Node *head2 = NULL;
struct Node *mergeHead = NULL;

void create_list();
void display_list();
struct Node *mergeLinkedList();
void sortByDescendingOrder();
void swap(struct Node *a, struct Node *b);

int main()
{
    create_list();
    printf("\nTwo Lists Before Sorting : \n\n");
    display_list();

    sortByDescendingOrder();

    printf("\nTwo Lists After Sorting : \n\n");
    display_list();

    mergeHead = mergeLinkedList();

    if (mergeHead != NULL)
    {
        struct Node *mergePtr, *mergeTail;
        mergePtr = mergeHead;
        mergeTail = NULL;

        int sort_merge = false;

        do
        {
            sort_merge = false;
            mergePtr = mergeHead;

            while (mergePtr->next != mergeTail)
            {
                if (mergePtr->data < mergePtr->next->data)
                {
                    swap(mergePtr, mergePtr->next);
                    sort_merge = true;
                }
                mergePtr = mergePtr->next;
            }
            mergeTail = mergePtr;

        } while (sort_merge);

        if (!sort_merge)
        {
            printf("\nMerged List is sorted!\n");

            struct Node *mergePtr2 = mergeHead;
            mergePtr2 = mergeHead;

            printf("\nResult after Merging: ");

            while (mergePtr2 != NULL)
            {
                printf("%d", mergePtr2->data);
                if (mergePtr2->next != NULL)
                    printf(" => ");
                mergePtr2 = mergePtr2->next;
            }
            printf("\n\nHappy Coding!\n");
        }
    }

    return 0;
}

void create_list()
{
    struct Node *ptr, *newNode;
    int num = 0;

    printf("\nList A:\n");
    printf("\nEnter -999 to end\n");

    while (true)
    {
        printf("\nEnter the data : ");
        scanf("%d", &num);

        if (num == -999)
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
    mergeHead = head;

    printf("\n************************************\n\n");

    printf("List B:\n");
    printf("\nEnter -999 to end\n");

    while (true)
    {
        printf("\nEnter the data : ");
        scanf("%d", &num);

        if (num == -999)
            break;

        newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = num;
        newNode->next = NULL;

        if (head2 == NULL)
        {
            head2 = newNode;
        }
        else
        {
            ptr = head2;
            while (ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            ptr->next = newNode;
        }
    }
    printf("\nTwo Linked Lists are created\n");
}

void display_list()
{
    if (head == NULL || head2 == NULL)
    {
        printf("\nOne of the linked list is empty!\n");
        return;
    }
    else
    {
        struct Node *ptr, *ptr2;
        ptr = head;
        ptr2 = head2;

        printf("A : ");
        while (ptr != NULL)
        {
            printf("%d", ptr->data);
            if (ptr->next != NULL)
                printf(" => ");
            ptr = ptr->next;
        }
        printf("\n");

        printf("B : ");
        while (ptr2 != NULL)
        {
            printf("%d", ptr2->data);
            if (ptr2->next != NULL)
                printf(" => ");
            ptr2 = ptr2->next;
        }
        printf("\n");
    }
}

struct Node *mergeLinkedList()
{
    if (head == NULL || head2 == NULL)
    {
        printf("\nOne of the linked list is empty!\n");
        return mergeHead;
    }
    else
    {
        struct Node *ptr, *lastNode;
        mergeHead = head;
        ptr = head;
        lastNode = NULL;

        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        lastNode = ptr;
        lastNode->next = head2;
        return mergeHead;
    }
}

void sortByDescendingOrder()
{
    if (head == NULL || head2 == NULL)
    {
        printf("\nOne of the linked list is empty!\n");
        return;
    }
    else
    {
        struct Node *ptr, *ptr2, *tail, *tail2;
        ptr = head;
        ptr2 = head2;

        tail = NULL;
        tail2 = NULL;

        int swapped_A = false;
        int swapped_B = false;

        do
        {
            swapped_A = false;
            ptr = head;
            while (ptr->next != tail)
            {
                if (ptr->data < ptr->next->data)
                {
                    swap(ptr, ptr->next);
                    swapped_A = true;
                }
                ptr = ptr->next;
            }
            tail = ptr;

        } while (swapped_A);

        if (!swapped_A)
            printf("\nList A is sorted!\n");

        do
        {
            swapped_B = false;
            ptr2 = head2;

            while (ptr2->next != tail2)
            {
                if (ptr2->data < ptr2->next->data)
                {
                    swap(ptr2, ptr2->next);
                    swapped_B = true;
                }
                ptr2 = ptr2->next;
            }
            tail2 = ptr2;

        } while (swapped_B);

        if (!swapped_B)
            printf("\nList B is sorted!\n");
    }
}

void swap(struct Node *a, struct Node *b)
{
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}