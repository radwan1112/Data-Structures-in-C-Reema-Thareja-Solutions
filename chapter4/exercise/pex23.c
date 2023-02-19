#include <stdio.h>
#include <string.h>

int main(){

    char str[] = "Good Morning";
    char str2[] = "Evening";
    int i = 5, j = 0;
    while(str[i] != '\0'){
        str[i] = str2[j];
        i++;
        j++;
    }
    printf("|%s|", str);

    return 0;
}
