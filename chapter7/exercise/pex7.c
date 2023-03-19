#include <stdio.h>

int func(int n, int r)
{
    if(r == 0 || r == n)
    {
        return 1;
    }
    else
    {
        return func(n-1, r) + func(n-1, r-1);
    }
}

int main()
{
    printf("\n Enter value of n: ");
    int n;
    scanf(" %d", &n);
    printf("\n Enter value of r: ");
    int r;
    scanf(" %d", &r);

    int result = func(n, r);
    printf("\n F(%d, %d) = %d", n, r, result);


    return 0;
}
