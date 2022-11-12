#include <stdio.h>

int main(){

    float number;
    int x;

    printf("Enter a float number: ");
    scanf("%f", &number);

    x = (int)number;
    printf("The last digit is: %d", (x%10));

    return 0;
}
