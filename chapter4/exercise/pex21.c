#include <stdio.h>
#include <string.h>

int main()
{

    printf("Enter a string: ");
    char str[1000];
    int i = 0;
    str[i] = getchar();
    while(str[i] != '*')
    {
        i++;
        str[i] = getchar();
    }
    str[i] = '\0';

    i = 0;
    int j = 0;

    while(str[i] != '\0')
    {
        if(str[i] != ',')
        {
            str[j] = str[i];
            j++;
        }
        i++;
    }
    str[j] = '\0';

    printf("\n\ndeleting all semi colons...\n\n");
    printf("|%s|", str);

    i = 0;
    j = 0;

    char *ptr = strchr(str, '.');
    while (ptr != NULL)
    {
        *ptr = ',';
        ptr = strchr(ptr + 1, '.');
    }
    printf("\n\nReplacing all fullstops with semicolons... \n\n");
    printf("|%s|\n", str);

    return 0;
}
