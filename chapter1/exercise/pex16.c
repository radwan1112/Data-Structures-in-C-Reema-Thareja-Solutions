#include <stdio.h>

int main(){

    char message[] = "Programming in C is Fun";
    char *ptr;

    ptr = message;

    while(*ptr != '\0'){
        printf("%c", *ptr++);
    }

    return 0;
}
