#include <stdio.h>

int main()
{

    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    // Fill the array
    for(int i = 0; i < n; i++)
    {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }

    int small = arr[0], position[n];
    int j = 0, l = 0;

    while(l < n )
    {
        if(arr[l] < small)
        {
            j = 0;
            small = arr[l];
            position[j] = l;
        }
        else if(arr[l] == small)
        {
            if(l == 0)
            {
                position[j] = l;
            }
            else
            {
                j++;
                position[j] = l;
            }
        }
        l++;
    }

    if(j > 0)
    {
        printf("The smallest element in the array is: %d", small);
        printf("\nRepeated in index number: ");
        for(int k = 0; k <= j; k++)
        {
            if(k == j)
            {
                printf("%d", position[k]);

            }
            else
            {
                printf("%d, ", position[k]);

            }
        }
    }
    else
    {
        printf("The smallest element in the array is: %d", small);
        printf("\nPositioned in index number %d: ", position[0]);
    }

    return 0;
}
