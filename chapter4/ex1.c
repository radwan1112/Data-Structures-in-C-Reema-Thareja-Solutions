#include <stdio.h>

int main()
{

    printf("Enter a String: ");
    char str[] = "";
    gets(str);


    int i = 0;
    while(str[i] != NULL)
    {
        i++;
    }

    printf("\n\nString '%s' has a total of %d characters\n", str, i);

    return 0;
}
