#include <stdio.h>

float add(float* ptr1, float* ptr2){

    return *ptr1 + *ptr2;


}

int main(){

    float num1, num2;
    printf("Enter num1: ");
    scanf("%f", &num1);
    printf("Enter num2: ");
    scanf("%f", &num2);

    printf("%f + %f = %f", num1, num2, add(&num1, &num2));


    return 0;
}
