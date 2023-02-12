#include <stdio.h>

int main()
{

    printf("Enter the main string: ");
    char str[100];
    fgets(str, 100, stdin);
    printf("Enter the index of the first character of the substring: ");
    int pos;
    scanf("%d", &pos);
    printf("Enter the length of the substring: ");
    int len;
    scanf("%d", &len);
    char substring[len];
    int i = pos, j;

    for(j = 0; j < len; j++){
        substring[j] = str[i];
        i++;
    }
    substring[j] = '\0';

    printf("\nSubstring : %s", substring);

    return 0;
}
