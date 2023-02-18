#include <stdio.h>
#include <string.h>

int main()
{
    printf("-- Write some text---\n\n");
    char par[100][10000];

    int i, j;
    i = 0;
    j = 0;
    int h = 0;
    int newline = 0;

    while(par[i][j] != '*')
    {
        par[i][j] = getchar();
        if(par[i][j] == '*')
        {
            break;
        }
        j++;
        if(par[i][j-1] == '\n')
        {
            newline++;
            par[i][j] = getchar();
            j++;
            if(par[i][j-1] == '\n')
            {
                par[i][j] = '\0';
                i++;
                j = 0;
            }
        }
    }
    par[i][j] = '\0';
    i++;

    int k;
    printf("generating text...\n\n");
    for(k = 0; k < i; k++)
    {
        printf("Paragraph number %d: \n\n%s\n", k+1, par[k]);
    }

    return 0;
}
