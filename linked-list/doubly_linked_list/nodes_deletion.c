#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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
void delete_start();
void delete_end();
void delete_before();
void delete_after();
void delete_given_node();
void delete_entire_list();

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
            delete_start();
            break;
        case 4:
            delete_end();
            break;
        case 5:
            delete_before();
            break;
        case 6:
            delete_after();
            break;
        case 7:
            delete_given_node();
            break;
        case 8:
            delete_entire_list();
            break;
        case 9:
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
    printf("3. Delete a node from the beginning\n");
    printf("4. Delete a node from the end\n");
    printf("5. Delete a node before a given node\n");
    printf("6. Delete a node after a given node\n");
    printf("7. Delete a given node\n");
    printf("8. Delete the entire list\n");
    printf("9. EXIT\n");
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

        if (head->next == NULL)
        {
            head = NULL;
            tail = NULL;
        }
        else
        {
            head = ptr->next;
            head->pre = NULL;
            free(ptr);
        }
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

void delete_before()
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
        int node;

        printf("\nEnter a node to delete before it : ");
        scanf("%d", &node);

        while (ptr->data != node)
        {
            if (ptr->next == NULL)
            {
                printf("\n%d is not in the list!!!\n", node);
                return;
            }
            ptr = ptr->next;
        }

        if (ptr->data == head->data)
        {
            printf("\nThere is no node to delete before a given node!!!\n");
        }
        else if (ptr->pre->data == head->data)
            delete_start();
        else
        {
            temp = ptr->pre;
            ptr->pre = temp->pre;
            temp->pre->next = ptr;
            free(temp);
        }
    }
}

void delete_after()
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
        int node;

        printf("\nEnter a node to delete after it : ");
        scanf("%d", &node);

        while (ptr->data != node)
        {
            if (ptr->next == NULL)
            {
                printf("\n%d is not in the list!!!\n", node);
                return;
            }
            ptr = ptr->next;
        }

        if (ptr->next == NULL)
            printf("\nThere is no node to delete after a given node!!!\n");
        else if (ptr->next->data == tail->data)
            delete_end();
        else
        {
            temp = ptr->next;
            ptr->next = temp->next;
            temp->next->pre = ptr;
            free(temp);
        }
    }
}

void delete_given_node()
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
        int node;

        printf("\nEnter a node to delete it : ");
        scanf("%d", &node);

        if (ptr->next == NULL)
        {
            head = NULL;
            tail = NULL;
            free(ptr);
        }
        else if (head->data == node)
            delete_start();
        else if (tail->data == node)
            delete_end();
        else
        {
            while (ptr->data != node)
            {
                if (ptr->next == NULL)
                {
                    printf("\n%d is not in the list!!!\n", node);
                    return;
                }
                ptr = ptr->next;
            }
            ptr->next->pre = ptr->pre;
            ptr->pre->next = ptr->next;
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
        struct node *ptr, *temp;
        ptr = head;

        while (ptr != NULL)
        {
            printf("\nNode %d is deleted.", ptr->data);
            temp = ptr->next;
            free(ptr);
            ptr = temp;
        }
        head = NULL;
        printf("\nEntire list is deleted!\n");
    }
}