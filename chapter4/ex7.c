#include <stdio.h>


int main()
{

    int i = 0, j = 0, k = 0;
    int pos = 9;
    char mainstr[] = "Hello Mr   Nice to meet you";
    char name[100];
    printf("Enter your name: ");
    if (fgets(name, sizeof(name), stdin) == NULL)
    {
        printf("Fail to read the input stream");
    }
    else
    {
        name[strcspn(name, "\n")] = '\0';
    }

    char newstr[100];

    while(mainstr[i] != '\0')
    {
        if(i == pos)
        {
            while(name[j] != '\0')
            {
                newstr[k] = name[j];
                k++;
                j++;
            }
        }
        else
        {
            newstr[k] = mainstr[i];
            k++;
        }
        i++;
    }
    newstr[k] = '\0';
    printf("%s", newstr);

    return 0;
}
