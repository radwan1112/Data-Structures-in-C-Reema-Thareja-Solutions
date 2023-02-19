#include <stdio.h>
#include <string.h>

int main()
{

    char str[] = "Good Morning";
    char substr[5];

    strncpy(substr, str + 2, 5);
    substr[5] = '\0';
    printf("|%s|", substr);

    return 0;

}
