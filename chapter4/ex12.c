#include <stdio.h>
#include <string.h>

int main()
{


    printf("Enter a word: ");
    char word[100];
    char reverse[100];
    fgets(word, 100, stdin);
    word[strcspn(word, "\n")] = '\0';
    int j = 0;
    int i = strlen(word) - 1;
    while(i >= 0)
    {
        reverse[j] = word[i];
        i--;
        j++;
    }
    reverse[j] = '\0';

    //check if strings are equal
    if(strcasecmp(word, reverse))
    {
        printf("%s is not a palindrome", word);
    }
    else
    {
        printf("%s is a palindrome", word);
    }


    return 0;
}
