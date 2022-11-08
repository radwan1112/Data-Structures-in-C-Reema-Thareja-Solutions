#include <stdio.h>

int main()
{

    int n, sum = 0;
    printf("Enter a number: ");
    scanf("%d", &n);

    int i = 0;
    do
    {
        sum += i;
        i++;
    }
    while(i <= n);

    printf("The sum of numbers under %d is: %d", n, sum);

    float average = (float)sum/n;

    printf("\nThe average of the first %d numbers is: %.2f", n, average);

    return 0;
}
