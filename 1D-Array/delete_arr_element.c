#include <stdio.h>
#include <stdbool.h>

#define SIZE 100

int main()
{
    int arr[SIZE];
    int num = 0;
    int isFound = false;
    int delete_key = 0;
    int delete_key_index = 0;

    printf("Enter number of elements : ");
    scanf("%d", &num);

    printf("\nEnter entries : \n");
    for (int i = 0; i < num; i++)
        scanf("%d", &arr[i]);

    printf("\nEnter the number you wanna delete : ");
    scanf("%d", &delete_key);

    for (int i = 0; i < num; i++)
    {
        if (arr[i] == delete_key)
        {
            isFound = true;
            delete_key_index = i;
            break;
        }
    }

    if (isFound)
    {
        printf("Found\n");
        for (int i = delete_key_index; i < num; i++)
            arr[i] = arr[i + 1];
        num -= 1;

        printf("After deleting...\n");
        for (int i = 0; i < num; i++)
            printf("%d\n", arr[i]);
    }
    else
        printf("Not Found\n");

    return 0;
}