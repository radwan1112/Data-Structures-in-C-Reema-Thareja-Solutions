#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool is_divisible(int number)
{
    return (number % 2 == 0) ? true : false;
}

int main()
{
    int number;
    printf("Enter a number: ");
    scanf("%d", &number);

    if(is_divisible(number))
    {
        printf("\nNumber %d is divisible by 2", number);
    }
    else
    {
        printf("\nNumber %d is not divisible by 2", number);
    }
    return 0;
}
