#include <stdio.h>
#include <string.h>

int main(){

    printf("Enter a string: ");
    char str[100];
    fgets(str, 100, stdin);
    str[strcspn(str, "\n")] = '\0';
    printf("Enter the character you want to replace: ");
    char c;
    scanf(" %c", &c);
    printf("Enter the character you want to replace with: ");
    char new_char;
    scanf(" %c", &new_char);

    int i = 0;
    while(str[i] != '\0'){

        if(str[i] == c){
            str[i] = new_char;
        }
        i++;
    }
    printf("Modifying string... \n");
    printf("%s", str);
    return 0;
}
