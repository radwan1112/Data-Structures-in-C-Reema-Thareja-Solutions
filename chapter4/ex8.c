#include <stdio.h>

int main()
{
    printf("---Delete substring from a text---\n\n");
    printf("Enter some text: ");
    char text[100];
    gets(text);

    printf("Enter the substring you wish to delete: ");
    char str[100];
    gets(str);

    int i = 0, j = 0, k = 0, n = 0;
    char new_text[100];
    int copy = 0;

    while(text[i] != NULL)
    {
        j = i;
        k = 0;
        while(text[j] == str[k] && str[k] != '\0')
        {
            j++;
            k++;
        }

        if(str[k] == '\0')
        {
            copy = j;
        }

        new_text[n] = text[copy];
        i++;
        n++;
        copy++;

    }
    new_text[j] = NULL;

    printf("Modifying text...\n\n");
    printf(" %s", new_text);

    return 0;
}
