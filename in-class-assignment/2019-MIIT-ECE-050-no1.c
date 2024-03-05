#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

void bubbleSort(int[], int);
void insertionSort(int[], int);
void selectionSort(int[], int);

void bubbleSortChar(char[], int);
void insertionSortChar(char[], int);
void selectionSortChar(char[], int);

void swap(int *a, int *b);
void swapChar(char *a, char *b);

void display(int[], int);
void displayChar(char[], int);

int main()
{
    char input1[] = {'2', '1', '8', '4A', '6', '7', '9', '4B'};
    int input2[] = {3, 5, 8, 4, 1, 9, -2};
    int input3[] = {54, 26, 93, 17, 77, 31, 44, 55, 20};
    char input4[] = {'K', 'Y', 'S', 'D', 'M', 'E'};
    char input5[] = {'Z', 'Y', 'M', 'O', 'K', 'W', 'E', 'A'};

    // Uncomment each line below to run one sorting method at a time for each problem.

    // printf("\n-----------------------(a)-------------------------\n");
    // int len1 = sizeof(input1) / sizeof(input1[0]);
    // bubbleSortChar(input1, len1);
    // insertionSortChar(input1, len1);
    // selectionSortChar(input1, len1);

    // printf("\n------------------------(b)-------------------------\n");
    // int len2 = sizeof(input2) / sizeof(input2[0]);
    // bubbleSort(input2, len2);
    // insertionSort(input2, len2);
    // selectionSort(input2, len2);

    // printf("\n-----------------------(c)-------------------------\n");
    // int len3 = sizeof(input3) / sizeof(input3[0]);
    // bubbleSort(input3, len3);
    // insertionSort(input3, len3);
    // selectionSort(input3, len3);

    // printf("\n-----------------------(d)-------------------------\n");
    // int len4 = sizeof(input4) / sizeof(input4[0]);
    // bubbleSortChar(input4, len4);
    // insertionSortChar(input4, len4);
    // selectionSortChar(input4, len4);

    // printf("\n-----------------------(e)-------------------------\n");
    // int len5 = sizeof(input5) / sizeof(input5[0]);
    // bubbleSortChar(input5, len5);
    // insertionSortChar(input5, len5);
    // selectionSortChar(input5, len5);

    return 0;
}

/* ----------------------------------------- */
// integers array

void bubbleSort(int arr[], int len)
{
    printf("\tBubble Sort\n");
    for (int i = 0; i < len; i++)
    {
        int temp = 0;
        printf("\nStep : %d => ", i + 1);
        for (int j = 0; j < len - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
        display(arr, len);
    }
    printf("\n");
}

void insertionSort(int arr[], int len)
{
    int key, j;
    key = j = 0;
    printf("\tInsertion Sort\n");
    for (int i = 1; i < len; i++)
    {
        key = arr[i];
        j = i - 1;
        printf("\nStep : %d => ", i);

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
        display(arr, len);
    }
    printf("\n");
}

void selectionSort(int arr[], int len)
{
    int min;
    printf("\tSelection Sort\n");
    for (int i = 0; i < len - 1; i++)
    {
        min = i;
        printf("\nStep : %d => ", i);
        for (int j = i + 1; j < len; j++)
        {
            if (arr[j] < arr[min])
                min = j;
        }
        swap(&arr[min], &arr[i]);
        display(arr, len);
    }
    printf("\n");
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

/* ----------------------------------------- */
// characters array

void bubbleSortChar(char arr[], int len)
{
    printf("\tBubble Sort\n");
    for (int i = 0; i < len; i++)
    {
        int temp = 0;
        printf("\nStep : %d => ", i + 1);
        for (int j = 0; j < len - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
        displayChar(arr, len);
    }
    printf("\n");
}

void insertionSortChar(char arr[], int len)
{
    int key, j;
    key = j = 0;
    printf("\tInsertion Sort\n");
    for (int i = 1; i < len; i++)
    {
        key = arr[i];
        j = i - 1;
        printf("\nStep : %d => ", i);

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
        displayChar(arr, len);
    }
    printf("\n");
}

void selectionSortChar(char arr[], int len)
{
    int min;
    printf("\tSelection Sort\n");
    for (int i = 0; i < len - 1; i++)
    {
        min = i;
        printf("\nStep : %d => ", i);
        for (int j = i + 1; j < len; j++)
        {
            if (arr[j] < arr[min])
                min = j;
        }
        swapChar(&arr[min], &arr[i]);
        displayChar(arr, len);
    }
    printf("\n");
}

void swapChar(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

void displayChar(char arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        if (i == 0)
            printf("[");
        else
            printf(", ");

        printf("%c", arr[i]);

        if (i == len - 1)
            printf("]\n");
    }
}