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
void insert_before();
void insert_after();
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
        char ans;

        do
        {
            printf("\nEnter your option : ");
            scanf("%d", &option);
        } while (!(option >= 1 && option <= 15));

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
            insert_before();
            break;
        case 8:
            insert_after();
            break;
        case 9:
            delete_start();
            break;
        case 10:
            delete_end();
            break;
        case 11:
            delete_before();
            break;
        case 12:
            delete_after();
            break;
        case 13:
            delete_given_node();
            break;
        case 14:
            delete_entire_list();
            break;
        case 15:
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
    printf("7. Add a node before a given node\n");
    printf("8. Add a node after a given node\n");
    printf("9. Delete a node from the beginning\n");
    printf("10. Delete a node from the end\n");
    printf("11. Delete a node before a given node\n");
    printf("12. Delete a node after a given node\n");
    printf("13. Delete a given node\n");
    printf("14. Delete the entire list\n");
    printf("15. EXIT\n");
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

void insert_before()
{
    if (head == NULL)
    {
        printf("\nLinked list is empty!\n");
        return;
    }
    else
    {
        struct node *ptr, *newNode;
        ptr = head;
        int node, num;

        printf("\nEnter a node to insert before it : ");
        scanf("%d", &node);

        if (ptr->data == node)
        {
            add_start();
        }
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

            printf("\nEnter the data : ");
            scanf("%d", &num);
            newNode = (struct node *)malloc(sizeof(struct node));

            newNode->data = num;
            newNode->next = ptr;
            newNode->pre = ptr->pre;
            ptr->pre->next = newNode;
            ptr->pre = newNode;
        }
    }
}

void insert_after()
{
    if (head == NULL)
    {
        printf("\nLinked list is empty!\n");
        return;
    }
    else
    {
        struct node *ptr, *newNode;
        ptr = head;
        int node, num;

        printf("\nEnter a node to insert after it : ");
        scanf("%d", &node);

        if (tail->data == node)
            add_end();
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

            printf("\nEnter the data : ");
            scanf("%d", &num);

            newNode = (struct node *)malloc(sizeof(struct node));

            newNode->data = num;
            newNode->next = ptr->next;
            newNode->pre = ptr;
            ptr->next = newNode;
            newNode->next->pre = newNode;
        }
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
        printf("\n\nEntire list is deleted!\n");
    }
}