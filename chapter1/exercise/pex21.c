#include <stdio.h>

int main()
{

    int m, n;

    printf("Enter the Min number: ");
    scanf("%d", &m);
    printf("\nEnter Max number: ");
    scanf("%d", &n);

    printf("\n Odd numbers: \n");

    while(m <= n)
    {
        if(m % 2 != 0)
        {
            printf("%d, ", m);
        }
        m++;
    }

    return 0;
}
