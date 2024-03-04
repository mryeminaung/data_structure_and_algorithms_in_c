#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

void bubbleSort(int[], int);
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

    bubbleSort(arr, len);

    printf("\nSorted array : ");
    display(arr, len);

    return 0;
}

void bubbleSort(int arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        int temp = 0;

        for (int j = 0; j < len - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
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