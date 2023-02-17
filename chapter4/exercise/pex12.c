#include <stdio.h>
#include <string.h>

int main()
{

    printf("Enter a string: ");
    char str[100];
    gets(str);
    char revstr[100];

    int j, k = 0;
    int i = strlen(str) - 1;

    while(i >= 0)
    {
        if(str[i] == ' ' || i == 0)
        {
            j = (i == 0)? i : i + 1;
            k++;
            revstr[k] = ' ';
            while(str[j] != ' ' && str[j] != '\0')
            {
                k++;
                revstr[k] = str[j];
                j++;
            }
        }
        i--;
    }
    k++;
    revstr[k] = '\0';
    strcat(str, revstr);
    printf("\"%s\"", str);

    return 0;
}
