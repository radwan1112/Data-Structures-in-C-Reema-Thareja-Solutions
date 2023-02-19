#include <stdio.h>

int  main(){

    char str[] = "hello world";
    char revstr[strlen(str)];
    int i = 0;
    int j = strlen(str) - 1;
    while(str[i] != '\0'){
        revstr[j] = str[i];
        i++;
        j--;
    }
    revstr[i] = '\0';
    printf("%s", revstr);

    return 0;
}
