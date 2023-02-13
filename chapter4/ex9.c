#include <stdio.h>
#include <string.h>




int main()
{

    char text[] = "The replacement operation is used to replace the pattern P1 by another pattern P2.";

    printf("--Modifying text--\n\n");
    printf("%s\n", text);
    printf("Which part you wish to replace: ");
    char replace[100];
    gets(replace);
    printf("Enter the replacement string: ");
    char new_str[100];
    gets(new_str);
    char new_text[100];
    int i = 0;
    int j = 0, k = 0;
    int copy = 0;
    int t = 0, n = 0;

    while(text[i] != NULL)
    {
        j = i;
        k = 0;
        while(text[j] == replace[k] && replace[k] != '\0')
        {
            j++;
            k++;
        }
        if(replace[k] == '\0')
        {
            while(t < strlen(new_str))
            {
                new_text[n] = new_str[t];
                n++;
                t++;
            }
            i += strlen(replace);
        }

        new_text[n] = text[i];
        n++;
        i++;
    }
    new_text[n] = '\0';
    printf("\n The new string is:\n%s", new_text);

    return 0;
}
