#include <stdio.h>

int main(){


    float num1, num2, num3, total;
    printf("Enter three floating numbers\n");
    printf("Enter Number 1: ");
    scanf("%f", &num1);
    printf("Enter Number 2: ");
    scanf("%f", &num2);
    printf("Enter Number 3: ");
    scanf("%f", &num3);

    total = num1 + num2 + num3;

    printf("%f + %f + %f = %.2f", num1, num2, num3, total);

    return 0;

}
