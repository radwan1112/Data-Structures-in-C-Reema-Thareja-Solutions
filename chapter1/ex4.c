#include <stdio.h>
#include <ctype.h>

int main(){
    char alphabit;
    printf("Enter a character: ");
    scanf("%c", &alphabit);

    switch(alphabit)
    {
        case 'A':
        case 'a':
            printf("%c is a vowel", alphabit);
            break;
        case 'O':
        case 'o':
            printf("%c is a vowel", alphabit);
            break;
        case 'I':
        case 'i':
            printf("%c is a vowel", alphabit);
            break;
        case 'E':
        case 'e':
            printf("%c is a vowel", alphabit);
            break;
        case 'U':
        case 'u':
            printf("%c is a vowel", alphabit);
            break;
        default:
            if(isalpha(alphabit)){
                printf("%c is not  a vowel", alphabit);
            }
            else{
                printf("Please Enter an English Alphabit");
            }
    }

    return 0;
}
