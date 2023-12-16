#include <stdio.h>
#include <stdbool.h>

#define SIZE 100

int main()
{
    int arr[SIZE];
    int num = 0;
    int isFound = false;
    int search_key = 0;

    printf("Enter number of elements : ");
    scanf("%d", &num);

    printf("\nEnter entries : \n");

    for (int i = 0; i < num; i++)
        scanf("%d", &arr[i]);

    printf("\nEnter the number you wanna search : ");
    scanf("%d", &search_key);

    for (int i = 0; i < num; i++)
    {
        if (arr[i] == search_key)
        {
            isFound = true;
            break;
        }
    }

    if (isFound)
        printf("Found\n");
    else
        printf("Not Found\n");

    return 0;
}