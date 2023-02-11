#include <stdio.h>

int main()
{

    char str[] = "";
    printf("Enter a String: ");
    gets(str);

    printf("\nConverting string to upper case...\n\n");
    int i = 0;
    while(str[i] != '\0')
    {

        if(str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] = str[i] - 32;
        }
        i++;
    }

    printf("'%s'\n", str);


    return 0;
}
