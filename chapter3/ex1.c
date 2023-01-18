#include <stdio.h>

int main()
{

    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int array[n];

    for(int i = 0; i < n; i++)
    {
        printf("Enter a number: ");
        scanf("%d", &array[i]);
    }
    printf("The array elements are: [");

    for(int l = 0; l < sizeof(array) / sizeof(*array); l++)
    {
        if(l == n-1)
        {
            printf("%d", array[l]);

        }
        else
        {
            printf("%d, ", array[l]);

        }
    }

    printf("]");

    return 0;
}
