#include <stdio.h>

int main()
{

    int i;

    int number;
    printf("Enter a number: ");
    scanf(" %d", &number);
    int n;
    printf("How many digit you wish to break %d into: ", number);
    scanf(" %d", &n);
    int arr[n];

    printf("Number %d has been broken down to %d digits in total as follow: \n", number, n);
    for(i = 0; i < n; i++)
    {
        if(i == n - 1)
        {
            arr[i] = number;
        }
        else
        {
            arr[i] = number % 10;
            number /= 10;
        }
        printf("digit %d = %d\n", i + 1, arr[i]);
    }


    return 0;
}
