#include <stdio.h>

int main()
{

    char c;

    printf("Input anything you want: ");
    scanf("%c", &c);


    if(c >= 'A' && c <= 'z' )
    {
        printf("\nThe input is a character %c", c);
        printf("\n ASCII of %c is: %d", c, c);
        if(c >= 'A' && c <= 'Z')
        {
            printf("\n Character '%c' is Uppercase", c);
        }
        else
        {
            printf("\n Character '%c' is Lowercase", c);
        }
    }
    else if(c >= '0' && c <= '9')
    {
        printf("\nThe input is a number %c", c);
        printf("\n ASCII of %c is: %d", c, c);
        printf("\n Numbers has no uppercase or lowercase");
    }
    else
    {
        printf("\n Input %c is a special character", c);
        printf("\n ASCII of %c is: %d", c, c);
        printf("\n Special Characters has no uppercase or lowercase");
    }

    return 0;
}
