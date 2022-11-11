#include <stdio.h>

int main()
{

    char text[100];
    int vowel = 0;

    printf("Enter Some text: ");
    gets(text);

    int i = 0;
    while(text[i] != NULL)
    {

        switch(text[i])
        {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            vowel++;
            break;
        default:
            break;
        }

        i++;
    }

    printf("The number of vowels in the entered text is: %d", vowel);



    return 0;

}
