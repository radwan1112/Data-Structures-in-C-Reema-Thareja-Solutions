#include <stdio.h>

int add(int *num1, int *num2, int *total){

    *total = *num1 + *num2;

    return *total;


}

int main(){

    printf("Adding two numbers.");
    int *ptr1, *ptr2;
    int num1, num2;
    int total = 0;

    printf("Please enter the first number: ");
    scanf("%d", &num1);

    printf("Please enter the second number: ");
    scanf("%d", &num2);

    ptr1 = &num1;
    ptr2 = &num2;

    printf("The total is: %d", add(ptr1, ptr2, &total));

}
