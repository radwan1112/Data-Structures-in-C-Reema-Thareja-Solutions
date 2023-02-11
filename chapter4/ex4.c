#include <stdio.h>
#include <string.h>

int main()
{


    char str1[100] = "";
    char str2[100] = "";
    int i = 0;

    printf("Enter the first string: ");
    fgets(str1, 100, stdin);
    printf("Enter the second string: ");
    fgets(str2, 100, stdin);

    if(strlen(str1) != strlen(str2))
    {
        printf("Strings are not Equal in Length");
    }
    else
    {
        while(i < strlen(str1))
        {
            if(str1[i] == str2[i])
            {
                i++;
            }
            else
            {
                break;
            }
        }

        if(i == strlen(str1))
        {
            printf("Both strings are identicala\n\n");
        }
        else
        {
            if(str1[i] > str2[i])
            {
                printf("string 1 is greater than string 2");
            }
            else
            {
                printf("string 2 is greater than string 1");
            }
        }

    }


    return 0;
}
