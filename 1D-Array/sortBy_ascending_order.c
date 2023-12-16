#include <stdio.h>

#define SIZE 100

int main()
{
    int arr[SIZE];
    int num = 5, temp = 0;

    printf("Enter number of elements : ");
    scanf("%d", &num);

    printf("\nEnter entries : \n");

    for (int i = 0; i < num; i++)
        scanf("%d", &arr[i]);

    printf("\nOriginal array : ");
    for (int i = 0; i < num; i++)
    {
        if (i == 0)
            printf("[");
        else
            printf(", ");

        printf("%d", arr[i]);

        if (i == num - 1)
            printf("]\n");
    }

    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num - 1; j++)
        {   
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    printf("\nSorting By Ascending Order : ");
    for (int i = 0; i < num; i++)
    {
        if (i == 0)
            printf("[");
        else
            printf(", ");

        printf("%d", arr[i]);

        if (i == num - 1)
            printf("]\n");
    }

    return 0;
}