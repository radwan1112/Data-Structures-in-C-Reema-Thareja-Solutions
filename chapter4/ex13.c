#include <stdio.h>

int main()
{

    printf("Enter a string: ");
    char str[100];
    gets(str);
    char *ptrc;
    ptrc = str;
    char str2[100];
    char *ptrc2;
    ptrc2 = str2;

    while(*ptrc != '\0')
    {
        *ptrc2 = *ptrc;
        ptrc2++;
        ptrc++;
    }
    *ptrc2 = '\0';

    printf("\n\nString 1: %s\n", str);
    printf("String 2: %s", str2);




    return 0;
}
