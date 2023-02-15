#include <stdio.h>
#include <string.h>

int main()
{

    char text[2000];
    int i = 0;
    printf("Enter your Text: ");
    scanf("%c", &text[i]);
    while(text[i] != '*')
    {
        i++;
        scanf("%c", &text[i]);
    }
    text[i] = '\0';

    int num_of_char = strlen(text);

    int words  = 1;
    int newline = 0;
    for(i = 0; i < num_of_char; i++){
        if(text[i] == ' ' || text[i] == '\t' || text[i] == '\n'){
            words++;
            if(text[i] == '\n'){
                newline++;
            }
        }
    }

    printf("\n\nThis Text has %d characters, %d words, and %d lines of text\n\n", num_of_char, words, newline);
    printf(" %s", text);


    return 0;
}
