#include <stdio.h>

int gcd(int a, int b)
{
    if(a % b == 0)
    {
        return b;
    }
    else
    {
        return gcd(b, (a%b));
    }
}

int main()
{
    printf("\n *****Calculate the GCD of two numbers*****\n");

    printf("\n Enter a number: ");
    int num1, num2, temp;
    scanf(" %d", &num1);
    printf("\n Enter a second number: ");
    scanf(" %d", &num2);
    if(num2 > num1)
    {
        temp = num2;
        num2 = num1;
        num1 = temp;
    }

    int result;
    result = gcd(num1, num2);
    printf("\n The GCD of %d and %d is %d\n", num1, num2, result);

    return 0;
}
