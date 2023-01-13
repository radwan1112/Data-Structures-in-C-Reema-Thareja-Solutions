#include <stdio.h>

char check(char c)
{

    if(c >= 'A' && c <= 'Z' )
    {
        return 'u';
    }
    else if(c >= 'a' && c <= 'z')
    {
        return 'l';
    }
    else
    {
        return 0;
    }


}

int main()
{
    char c;

    while(c != '*')
    {
        printf("\nEnter a character: ");
        scanf(" %c", &c);
        printf("\n You entered: %c", c);
        printf("\n The ASCII value of this character is: %d", c);
        if(check(c) == 'u')
        {
            printf("\n The lowercase of this character is: %c", (c + 32));
        }
        else if(check(c) == 'l')
        {
            printf("\n The uppercase of this character is: %c", (c - 32));

        }
        else
        {
            printf("\n This character has no uppercase or lowercase");
        }
    }


    return 0;
}
