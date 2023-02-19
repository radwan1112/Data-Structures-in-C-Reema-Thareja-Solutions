#include <stdio.h>
#include <string.h>

int main()
{

    char str[30] = "Oxford Press";
    char ins[] = "University ";
    char len = strlen(str);

    int i = 0;
    int index = 6;
    int j = len;
    while(ins[i] != '\0')
    {
        j = len;
        while(j > index)
        {
            str[j + 1] = str[j];
            j--;
        }
        str[j + 1] = ins[i];
        len++;
        index++;
        i++;
    }
    printf("|%s|", str);


    return 0;
}
