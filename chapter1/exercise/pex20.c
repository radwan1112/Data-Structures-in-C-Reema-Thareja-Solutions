#include <stdio.h>

int main(){

    float n, sum = 0, average = 0;

    printf("Enter the ending number: ");
    scanf("%f", &n);

    for(int i = 1; i <= n; i++){
        sum += i;
    }

    average = sum / n;

    printf("The Sum of numbers from 1 to %.2f is = %.2f", n, sum);
    printf("\n And their Average is =  %.2f", average);

    return 0;
}
