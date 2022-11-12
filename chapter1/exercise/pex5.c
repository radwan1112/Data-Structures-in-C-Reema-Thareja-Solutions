#include <stdio.h>

int main(){

    float num1, num2;
    int total;

    printf("Enter the first decimal number: \n");
    scanf("%f", &num1);

    printf("Enter the second decimal number: \n");
    scanf("%f", &num2);

    total = num1 + num2;
    printf("Results:\n\t num1 = %f \n\t num2 = %f \n\t total = %d", num1, num2, total);

    return 0;

}
