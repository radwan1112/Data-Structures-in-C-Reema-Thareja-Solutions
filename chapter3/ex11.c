#include <stdio.h>
#include <stdlib.h>

int main()
{

    int n1, n2, i;
    printf("Enter the number of elements in the first array: ");
    scanf("%d", &n1);
    printf("Enter the number of elements in the second array: ");
    scanf("%d", &n2);

    int n3 = n1 + n2;
    int upper = 100, lower = 0;
    int arr1[n1];
    int arr2[n2];
    int arr3[n3];
    srand(time(0));

    printf("\nGenerating first array... \n");
    //fill the first array with random numbers
    for(i = 0 ; i < n1 ; i++ )
    {
        arr1[i] = (rand() % (upper - lower + 1)) + lower;
        printf("arr1[%d] = %d \n", i, arr1[i]);
    }

    printf("\nGenerating second array... \n");
    //fill the second array with random numbers
    for(i = 0 ; i < n2 ; i++ )
    {
        arr2[i] = (rand() % (upper - lower + 1)) + lower;
        printf("arr2[%d] = %d \n", i, arr2[i]);

    }

    int j = 0;
    for(i = 0; i < n3; i++)
    {
        if(i < n1)
        {
            arr3[i] = arr1[i];
        }
        else
        {
            arr3[i] = arr2[j];
            j++;
        }
    }

    printf("\nGenerating merged array... \n");

    for(i = 0; i < n3; i++)
    {
        printf("arr3[%d] = %d \n", i, arr3[i]);
    }

    return 0;
}
