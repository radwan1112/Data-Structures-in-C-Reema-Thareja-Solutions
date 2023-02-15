#include <stdio.h>

void print_string(char *str){

    printf("%s", str);
}


int main(){

    printf("Enter a string: ");
    char str[20];
    gets(str);
    print_string(str);

    return 0;
}
