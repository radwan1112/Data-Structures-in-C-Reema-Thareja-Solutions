#include <stdio.h>

int main(){

    printf("Enter a string: ");
    char str[100];
    gets(str);

    printf("Enter the character to test for: ");
    char c;
    scanf(" %c", &c);
    int i = 0, count = 0;
    while(str[i] != '\0'){
        if(str[i] == c){
            count++;
        }
        i++;
    }
    printf("The character %c is repeated %d times inside the below string\n%s", c, count, str);
    return 0;
}
