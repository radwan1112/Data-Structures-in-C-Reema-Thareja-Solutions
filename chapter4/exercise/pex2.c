#include <stdio.h>


int strjoin(char mainstr[], char str2[], int n)
{

    int i = 0;

    while(mainstr[i] != '\0')
    {
        i++;
    }

    int j = 0;
    while(j < n)
    {
        mainstr[i] = str2[j];
        j++;
        i++;
    }
    mainstr[i] = '\0';

    return mainstr;

}



int main()
{
    printf("Enter the first string: ");
    char mainstr[200];
    gets(mainstr);

    printf("Enter the second string: ");
    char str2[100];
    gets(str2);

    printf("Enter the number of characters to concat: ");
    int n;
    scanf(" %d", &n);

    strjoin(mainstr, str2, n);
    printf("%s", mainstr);

    return 0;
}
