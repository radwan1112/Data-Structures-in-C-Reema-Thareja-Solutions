#include <stdio.h>
#include <string.h>

int trim(char str[])
{

    int i = 0;
    int len = 0;
    while(str[len] != '\0')
    {
        len++;
    }
    i = len - 1;

    while(str[i] == ' ')
    {
        str[i] = '\0';
        i--;
        len--;
    }

    while(str[0] == ' ')
    {
        i = 0;
        while(str[i] != '\0')
        {
            str[i] = str[i + 1];
            i++;
        }
        len--;
    }
    str[len] = '\0';
    return len;
}


int main()
{

    printf("Enter a string: ");
    char str[200];
    fgets(str, 200, stdin);
    str[strcspn(str, "\n")] = '\0';


    int c = trim(str);

    printf("Trimming String... \n\n");
    printf("{%s} consist of %d characters", str, c);

    return 0;
}
