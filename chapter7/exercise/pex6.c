#include <stdio.h>

int func(int x, int y)
{
    if(x < y)
    {
        return 0;
    }
    else
    {
        return func(x-y, y) + 1;
    }
}


int main()
{
    int x, y;
    printf("\n Enter value of x: ");
    scanf(" %d", &x);
    printf("\n Enter value of y: ");
    scanf(" %d", &y);

    int result = func(x, y);
    printf("\n F(%d, %d) = %d", x, y, result);

    return 0;
}
