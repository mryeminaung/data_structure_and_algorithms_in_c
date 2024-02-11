#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define SIZE 5

void menu();

void push(int);
void pop();
void peek();
void display();
int isFull();
int isEmpty();

int top = -1;
int arr[SIZE];

int main()
{
    int option, num;

    while (true)
    {
        menu();
        do
        {
            printf("\nEnter your choice : ");
            scanf("%d", &option);
        } while (!(option >= 1 && option <= 7));

        switch (option)
        {
        case 1:
            printf("Enter the number to insert into stack : ");
            scanf("%d", &num);
            push(num);
            break;
        case 2:
            pop();
            break;
        case 3:
            isFull() && printf("\nStack is full!\n");
            break;
        case 4:
            isEmpty() && printf("\nStack is empty!\n");
            break;
        case 5:
            peek();
            break;
        case 6:
            display();
            break;
        case 7:
            printf("\nHappy Coding!\n");
            exit(0);
        default:
            printf("\nInvalid Option\n");
            break;
        }
        num = 0;
    }
    return 0;
}

void menu()
{
    printf("\n1. Push\n2. Pop\n3. IsFull\n4. IsEmpty\n5. Peek\n6. Display\n7. END\n");
}

void push(int item)
{
    if (isFull())
        printf("\nThe stack is full\n");

    else
    {
        top += 1;
        arr[top] = item;
        printf("\n%d is inserted into stack\n", item);
    }
}

void pop()
{
    if (isEmpty())
        printf("\nThe stack is empty!\n");
    else
    {
        printf("\n%d is deleted into stack\n", arr[top]);
        top -= 1;
    }
}

void peek()
{
    printf("The top element : %d\n", arr[top]);
}

void display()
{
    printf("\nStack Elements : ");

    for (int item = 0; item <= top; item++)
    {
        printf(" %d", arr[item]);
        if (item < top)
            printf(" ->");
    }
    printf("\n");
}

int isEmpty()
{
    return top == -1;
}

int isFull()
{
    return top == SIZE - 1;
}