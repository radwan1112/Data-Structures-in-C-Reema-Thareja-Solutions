#include <stdio.h>

int lambda(int n)
{
    if(n == 1)
    {
        return 0;
    }
    else
    {
        return lambda(n / 2) + 1;
    }
}

int main()
{
    int n;
    printf("\n Enter the value of n: ");
    scanf(" %d", &n);
    int result;

    for(int i = 1; i <= n; i++)
    {
        result = lambda(i);
        printf("\n Lambda(%d) = %d", i, result);
    }
}
