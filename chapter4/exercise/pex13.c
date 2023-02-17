#include <stdio.h>
#include <string.h>

int main()
{

    printf("Enter an essay: \n\n");
    char essay[10000];
    int i = 0;
    essay[i] = getchar();
    while(essay[i] != '*')
    {
        i++;
        essay[i] = getchar();
    }
    essay[i] = '\0';

    char revessay[10000];

    int j = 0, k = 0;

    i = strlen(essay);
    while(i >= 0)
    {
        if(i == 0 || (essay[i] == '\n' && essay[i - 1] == '\n'))
        {
            j = (i == 0)? i : i + 2;
            while(essay[j] != '\n' && essay[j] != '\0')
            {
                revessay[k] = essay[j];
                k++;
                j++;
            }
            revessay[k] = '\n';
            k++;
            revessay[k] = '\n';
            k++;
        }
        i--;
    }
    revessay[k] = '\0';

    printf("Interchanging paragraphs... \n\n");
    printf("%s", revessay);


    return 0;
}
