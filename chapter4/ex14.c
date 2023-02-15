#include <stdio.h>
#include <string.h>

int main()
{

    printf("Enter the first string: ");
    char str[100];
    gets(str);

    printf("Enter the second string: ");
    char str2[100];
    gets(str2);
    char str3[200];

    char *ptrc, *ptrc2, *ptrc3;
    ptrc = str;
    ptrc2 = str2;
    ptrc3 = str3;

    while(*ptrc != '\0')
    {
        *ptrc3 = *ptrc;
        ptrc++;
        ptrc3++;
    }

    while(*ptrc2 != '\0')
    {
        *ptrc3 = *ptrc2;
        ptrc2++;
        ptrc3++;
    }
    *ptrc3 = '\0';
    printf("%s", str3);


    return 0;
}
