#include <stdio.h>
#include <stdio.h>
#include <string.h>

#define SIZE 100

void ascending_str(char str[SIZE]);
void display_str(char str[SIZE]);

int main()
{
    char str1[SIZE], str2[SIZE];

    printf("Enter str1 : ");
    scanf("%[^\n]s", str1);

    getchar();

    printf("Enter str2 : ");
    scanf("%[^\n]s", str2);

    ascending_str(str1);
    ascending_str(str2);
    printf("\nSorting Ascending Order\n");

    printf("str1 : ");
    display_str(str1);
    printf("str2 : ");
    display_str(str2);

    if (strcmp(str1, str2) == 0)
        printf("\nAnagram\n");
    else
        printf("\nNot anagram\n");

    return 0;
}

void ascending_str(char str[SIZE])
{
    int len = strlen(str);
    char temp;

    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len - 1; j++)
        {
            if (str[j] > str[j + 1])
            {
                temp = str[j];
                str[j] = str[j + 1];
                str[j + 1] = temp;
            }
        }
    }
}

void display_str(char str[SIZE])
{
    int len = strlen(str);

    for (int i = 0; i < len; i++)
    {
        printf("%c ", str[i]);
    }
    printf("\n");
}