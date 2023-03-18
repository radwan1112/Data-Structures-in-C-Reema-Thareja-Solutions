#include <stdio.h>

int exp(int x, int y)
{
    if(y == 0)
    {
        return 1;
    }
    else
    {
        return x * exp(x, (y-1));
    }
}

int main()
{
    int x, y, result;

    printf("\n *****Finding Exponents*****\n");
    printf("\n Enter the number: ");
    scanf(" %d", &x);
    printf("\n Enter the power: ");
    scanf(" %d", &y);
    result = exp(x, y);
    printf("\n %d^%d = %d\n", x, y, result);

    return 0;
}
