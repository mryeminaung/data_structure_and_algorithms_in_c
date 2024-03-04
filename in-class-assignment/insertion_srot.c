#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

void insertionSort(int[], int);
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

    insertionSort(arr, len);

    printf("\nSorted array : ");
    display(arr, len);

    return 0;
}

void insertionSort(int arr[], int len)
{
    int key, j;
    key = j = 0;

    for (int i = 1; i < len; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
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