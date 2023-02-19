#include <stdio.h>
#include <string.h>

int main()
{

    printf("--Story Writer--\n\n");
    char story[10000];
    int i = 0;
    story[i] = getchar();
    while(story[i] != '*')
    {
        i++;
        story[i] = getchar();
    }
    story[i] = '\0';

    printf("\n\nPrinting story...\n\n%s", story);

    printf("\n\n printing story with line number...\n\n");

    int newline = 1;
    i = 0;
    while(story[i] != '\0')
    {
        if(story[i] == '\n')
        {
            printf("%c", story[i]);
            printf("%d  ", newline);
            newline++;
        }
        else
        {
            if(i == 0)
            {
                printf("%d  ", newline);
                printf("%c", story[i]);
                newline++;
            }
            else
            {
                printf("%c", story[i]);
            }
        }
        i++;
    }
    printf("\n\n");


    return 0;
}
