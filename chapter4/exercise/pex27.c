#include <stdio.h>
#include <string.h>

int main()
{

    printf("--Enter some text--\n\n");
    char text[10000];
    int i = 0;
    int l = 0;
    printf("%d  ", l);
    int line[1000];
    line[l] = i;
    text[i] = getchar();
    while(text[i] != '*')
    {
        i++;
        text[i] = getchar();
        if(text[i] == '\n')
        {
            l++;
            line[l] = i;
            printf("%d  ", l);

        }
    }
    l++;
    line[l] = i;
    text[i] = '\0';

    printf("Enter the number of lines to display: ");
    int lines;
    scanf("%d", &lines);
    int start;
    printf("Enter the starting line number: ");
    scanf("%d", &start);

    printf("\n\nprinting section...\n\n");

    i = line[start];
    int e = line[start + lines];
    int j = start;
    while(i <= e)
    {
        if(text[i] == '\n')
        {
            printf("%c", text[i]);
            printf("%d  ", j);
            i++;
            j++;
        }
        else
        {
            if(i == line[start])
            {
                printf("%d  ", j);
                printf("%c", text[i]);
                i++;
                j++;
            }
            else
            {
                printf("%c", text[i]);
                i++;
            }

        }
    }

    return 0;
}
