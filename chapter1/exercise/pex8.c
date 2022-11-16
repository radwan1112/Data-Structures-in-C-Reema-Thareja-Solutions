#include <stdio.h>

int main(){

    float basic_pay, salary;
    const float HRA = 0.1;
    const float TA = 0.05;

    printf("Enter Your Salary: ");
    scanf("%f", &basic_pay);

    salary = basic_pay + (basic_pay * HRA) + (basic_pay * TA);

    printf("%f", salary);

    return 0;
}
