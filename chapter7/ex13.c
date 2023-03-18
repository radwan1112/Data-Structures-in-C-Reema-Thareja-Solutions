#include <stdio.h>

int fib(int n)
{
    if(n == 0)
    {
        return 0;
    }
    else if(n == 1)
    {
        return 1;
    }
    else
    {
        return fib(n - 1) + fib(n - 2);
    }
}

int main()
{

    printf("\n Printing Fibonacci series\n");
    int n;
    printf("\n Enter the number of terms in the Fibonacci series: ");
    scanf(" %d", &n);
    int result;
    result = fib(n);
    int i = 0;
    printf("\n\t");
    for(i = 0; i < n; i++)
    {
        result = fib(i);
        printf("%d ", result);
    }
    printf("\n\n the %d term in the Fibonacci series is %d\n", n, result);

    return 0;
}
