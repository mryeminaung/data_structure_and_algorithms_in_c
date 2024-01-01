#include <stdio.h>

#define SIZE 100

int main()
{
    int arr[SIZE];
    int num = 0, min = 0, min_count = 0;

    printf("No of elements = ");
    scanf("%d", &num);

    for (int i = 0; i < num; i++)
        scanf("%d", &arr[i]);

    min = arr[0];

    for (int i = 0; i < num; i++)
    {
        if (arr[i] < min)
            min = arr[i];
    }

    printf("Min element is %d\n", min);

    for (int i = 0; i < num; i++)
    {
        if (min == arr[i])
            min_count += 1;
    }

    printf("Min element count = %d\n", min_count);

    if (min_count % 2 == 0)
        printf("Unlucky\n");
    else
        printf("Lucky\n");

    return 0;
}