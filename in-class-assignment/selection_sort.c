#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

void selectionSort(int[], int);
void swap(int *a, int *b);
void display(int[], int);

int main()
{
    int arr[SIZE];
    int len;

    printf("Enter number of elements : ");
    scanf("%d", &len);

    printf("\nEnter entries : \n");

    for (int i = 0; i < len; i++)
        scanf("%d", &arr[i]);

    printf("\nOriginal array : ");
    display(arr, len);

    selectionSort(arr, len);

    printf("\nSorted array : ");
    display(arr, len);

    return 0;
}

void selectionSort(int arr[], int len)
{
    int min;
    for (int i = 0; i < len - 1; i++)
    {
        min = i;
        for (int j = i + 1; j < len; j++)
        {
            if (arr[j] < arr[min])
                min = j;
        }
        swap(&arr[min], &arr[i]);
    }
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void display(int arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        if (i == 0)
            printf("[");
        else
            printf(", ");

        printf("%d", arr[i]);

        if (i == len - 1)
            printf("]\n");
    }
}