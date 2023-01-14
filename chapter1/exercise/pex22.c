#include <stdio.h>
#include <stdbool.h>

int main()
{

    int m, n;
    bool isPrime;

    printf("Enter Min value: ");
    scanf("%d", &m);

    printf("Enter Max value: ");
    scanf("%d", &n);

    printf("\n All Prime numbers between %d and %d: ", m, n);

    while(m <= n)
    {

        for(int i = 2; i < m; i++)
        {
            if(m % i == 0 && m != 2)
            {
                isPrime = false;
                break;
            }
            else if(m == 1)
            {
                isPrime = false;
                break;
            }
            else if(m == 2){
                isPrime = true;
            }
            else
            {
                isPrime = true;
            }
        }

        if(isPrime)
        {
            printf("%d ", m);
        }
        m++;
    }

    return 0;
}
