#include <stdio.h>

int main(){

    char str[100] = "";
    printf("Enter a String: ");
    fgets(str, 100, stdin);

    int i, j = strlen(str) - 1;
    char temp;

    for(i = 0; i < j; i++){
        temp = str[j];
        str[j] = str[i];
        str[i] = temp;
        j--;
    }

    printf("Reversing String...\n\n");
    printf("%s", str);

    return 0;
}
