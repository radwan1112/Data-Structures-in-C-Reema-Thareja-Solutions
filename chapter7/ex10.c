#include <stdio.h>

int factorial(int n)
{
    if(n == 1)
    {
        return 1;
    }
    else
    {
        return n * factorial(n - 1);
    }
}

int main()
{
    printf("\n *****Factorial Calculator****\n");
    printf("\n Enter a number: ");
    int num;
    scanf("\n %d", &num);

    int result = factorial(num);
    printf("\n Factorial of %d is %d\n", num, result);

    return 0;
}
