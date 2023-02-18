#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main()
{


    char str[] = "GOOD MORNING";
    int i = 0;
    char newstr[strlen(str)];

    while(str[i] != '\0')
    {
        str[i] = tolower(str[i]);
        i++;
    }
    printf("%s", str);

    return 0;
}
