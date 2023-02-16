#include <stdio.h>

int main(){


    char str[100];
    printf("Enter a string: ");
    gets(str);
    int digit = 0, l_case = 0, u_case = 0, s_char = 0;
    int i = 0;
    while(str[i] != '\0'){

        if(str[i] >= 65 && str[i] <= 90){
            u_case++;
        }
        else if(str[i] >= 97 && str[i] <= 122){
            l_case++;
        }
        else if(str[i] >= 48 && str[i] <= 57){
            digit++;
        }
        else{
            s_char++;
        }
        i++;
    }
    printf("Uppercase characters: %d\n", u_case);
    printf("Lowercase characters: %d\n", l_case);
    printf("Digit characters: %d\n", digit);
    printf("Special characters: %d\n", s_char);

    return 0;
}
