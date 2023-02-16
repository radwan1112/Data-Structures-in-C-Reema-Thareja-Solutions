#include <stdio.h>
#include <string.h>
#include <ctype.h>

int cmpstr(char str1[], char str2[], int n)
{
    int i = 0;

    while(i < n)
    {
        if(str1[i] == '\0' || str2[i] == '\0')
        {
            if(str1[i] == '\0' && str2[i] != '\0')
            {
                return 0 - tolower(str2[i]);
            }
            else if(str2[i] == '\0' && str1[i] != '\0')
            {
                return tolower(str1[i]) - 0;
            }
            else
            {
                break;
            }
        }
        else
        {
            if(tolower(str1[i]) != tolower(str2[i]))
            {
                return tolower(str1[i]) - tolower(str2[i]);
            }
        }
        i++;
    }




    return 0;

}



int main()
{

    char str[100];
    char str2[100];

    printf("Enter the first string : ");
    fgets(str, 100, stdin);
    str[strcspn(str, "\n")] = '\0';

    printf("Enter the second string : ");
    fgets(str2, 100, stdin);
    str2[strcspn(str2, "\n")] = '\0';

    int n;
    printf("Enter the number of characters to compare: ");
    scanf("%d", &n);

    if(cmpstr(str, str2, n) > 0)
    {
        printf("String 1 is greater than string 2: %s > %s", str, str2);
    }
    else if(cmpstr(str, str2, n) < 0)
    {
        printf("String 2 is greater than string 1: %s > %s", str2, str);
    }
    else
    {
        printf("String 1 and 2 are equal: %s = %s", str, str2);
    }

    return 0;
}
