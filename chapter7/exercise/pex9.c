#include <stdio.h>

int func(int m, int n)
{
    if(m == 0 || (m >= n && n >= 1))
    {
        return 1;
    }
    else
    {
        return func(m - 1, n) + func(m - 1, n - 1);
    }
}

int main()
{
    int m, n;
    int result;

    printf("\n Enter value for m: ");
    scanf(" %d", &m);
    printf("\n Enter value for n: ");
    scanf(" %d", &n);

    result = func(m, n);
    printf("\n F(%d, %d) = %d", m, n, result);

    return 0;
}
