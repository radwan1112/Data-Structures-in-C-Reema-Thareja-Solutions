#include <stdio.h>
#include <string.h>

int main(){

    char str1[] = "I am String number 1 and ";
    char str2[] = "I am String number 2";

    int len = strlen(str1);

    int i = len;
    int j = 0;

    while(str2[j] != NULL){
        str1[i] = str2[j];
        j++;
        i++;
    }
    str1[i] = NULL;

    printf("Joining strings 1 and 2...\n\n");
    printf("%s\n", str1);


}
