#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{

    char str[1000];
    char word[] = "the";
    printf("Enter some text: ");
    gets(str);

    int count = 0;
    int i = 0;
    int j;
    int k;

    while(str[i] != '\0')
    {
        j = i;
        k = 0;
        while(word[k] != '\0')
        {
            if(tolower(str[j]) == word[k])
            {
                j++;
                k++;
            }
            else
            {
                break;
            }
        }
        if(k == strlen(word))
        {
            if(str[j] == ' ' || str[j] == '.' || str[j] == ',')
            {
                if(str[i-1] == ' ' || i == 0)
                {
                    count++;
                }
            }
        }
        i++;
    }


    printf("The word %s has appeared %d time in the below text\n%s", word, count, str);



    return 0;
}
