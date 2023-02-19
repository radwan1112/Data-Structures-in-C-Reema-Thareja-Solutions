#include <stdio.h>

int main(){

    printf("Enter a line of text press return to end\n\n");
    char str[1000];
    gets(str);

    printf("\nYOU have entered the following: \n\n%s", str);

    return 0;
}
