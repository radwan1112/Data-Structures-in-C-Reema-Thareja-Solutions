#include <stdio.h>
#include <string.h>

int main(){

    printf("Enter a string: ");
    char str[100];
    gets(str);

    int num;
    printf("Number of characters to copy: ");
    scanf("%d", &num);

    int len = strlen(str);
    char new_str[num];

    int i;
    int j = 0;

    for(i = len - num; i < len; i++){
        new_str[j] = str[i];
        j++;
    }
    new_str[j] = '\0';
    printf("|%s|", new_str);


    return 0;
}
