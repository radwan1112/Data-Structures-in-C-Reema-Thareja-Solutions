#include <stdio.h>
#include <string.h>

int pattern(char str[], char pat[], int *index)
{
    int i = 0, k = 0;
    int max = strlen(str) - strlen(pat) + 1;
    int match = 0;
    int found = 0;

    while(i < max)
    {
        for(k = 0; k < strlen(pat); k++)
        {
            if(pat[k] != str[i + k])
            {
                break;
            }
            else
            {
                match++;
            }
        }

        if(match == strlen(pat))
        {
            *index = i;
            found = 1;
            break;
        }
        else
        {
            match = 0;
            i++;
        }
    }
    return found;
}

int main()
{

    //pattern detector
    printf("--Pattern detecting algorithm--\n\n");
    printf("Enter a string: ");
    char str[100];
    if(fgets(str, 100, stdin) == '\0')
    {
        printf("failed to read input stream");
    }
    else
    {
        str[strcspn(str, "\n")] = '\0';
    }

    printf("Enter a random pattern to test the pattern algorithm: ");
    char pat[100];
    if(fgets(pat, 100, stdin) == '\0')
    {
        printf("failed to read input stream");

    }
    else
    {
        pat[strcspn(pat, "\n")] = '\0';
    }

    int index;
    int isdetected = pattern(str, pat, &index);

    if(isdetected)
    {
        printf("Pattern \"%s\" was detected at the following index position %d in the main string: \"%s\"", pat, index, str);
    }
    else
    {
        printf("Pattern \"%s\" was not detected in the main string: \"%s\"", pat, str);
    }
    return 0;
}
