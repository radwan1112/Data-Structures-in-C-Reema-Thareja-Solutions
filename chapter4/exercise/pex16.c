#include <stdio.h>
#include <string.h>

int main()
{
    char str[] = "Good Morning ";
    char str2[] = "World";
    char str3[(strlen(str) - 1) + strlen(str2)];

    strcpy(str3, str);
    strcat(str3, str2);

    printf("|%s|", str3);

    return 0;
}
