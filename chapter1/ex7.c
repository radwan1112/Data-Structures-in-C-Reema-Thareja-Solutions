#include <stdio.h>

int main()
{

    int number;
    printf("Enter a number: ");
    scanf("%d", &number);
    int factors = 0;

    int i;
    for(i = 1; i <= number; i++){

        if(number % i == 0){
            factors++;
        }
    }

    if(factors > 2 || number == 2){
        printf("This is a composite number");
    }
    else{
        printf("This is a prime number");
    }
}
