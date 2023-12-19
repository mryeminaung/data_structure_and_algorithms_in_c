#include <stdio.h>

#define SIZE 100

int main()
{
    int arr[SIZE];
    int num = 0, temp = 0;

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

    int j = num - 1;

    for (int i = 0; i < (num / 2); i++)
    {
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        j--;
    }

    printf("\nReversed array : ");
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