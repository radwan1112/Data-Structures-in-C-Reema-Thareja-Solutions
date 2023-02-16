#include <stdio.h>
#include <string.h>

int main()
{

    printf("--Display array of strings in reverse order--\n\n");
    printf("Enter the number of words: ");
    int num;
    scanf("%d", &num);
    getchar();
    char str[num][100];

    int i;

    for(i = 0; i < num; i++)
    {
        printf("Enter string %d: ", i+1);
        gets(str[i]);
    }

    int j = num - 1;
    i = 0;
    char temp[100];
    while(i < j)
    {
        strcpy(temp, str[i]);
        strcpy(str[i], str[j]);
        strcpy(str[j], temp);
        i++;
        j--;
    }

    printf("\nReversing the string...\n\n");
    for(i = 0; i < num; i++)
    {
        if(i == num -1)
        {
            printf("%s.\n", str[i]);
        }
        else
        {
            printf("%s ", str[i]);
        }
    }

    return 0;
}
