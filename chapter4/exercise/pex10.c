#include <stdio.h>
#include <string.h>

int main()
{

    printf("Enter a string: ");
    char str[1000];
    gets(str);

    printf("Enter a substring to detect its last occurrence: ");
    char substr[1000];
    gets(substr);

    int index;
    int i = 0, j = 0, k = 0;

    while(str[i] != '\0')
    {

        k = 0;
        j = i;
        while(substr[k] != '\0')
        {
            if(str[j] == substr[k])
            {
                k++;
                j++;
            }
            else
            {
                break;
            }
        }
        if(k == strlen(substr))
        {
            index = i;
        }
        i++;
    }

    printf("The last occurrence of \"%s\" is in position index %d in the below string\n", substr, index);

    return 0;
}

