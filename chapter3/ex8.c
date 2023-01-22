#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>

int main()
{


    int n;
    printf("Enter the number of elements in array: ");
    scanf("%d", &n);

    int upper = 100, lower = 0;
    int arr[n+1];
    srand(time(0));
    int temp, number, pos;


    //fill the array with random numbers
    for(int i = 0 ; i < n ; i++ )
    {
        arr[i] = (rand() % (upper - lower + 1)) + lower;
    }

    //Sort the array
    for(int k = 0; k < n; k++)
    {

        for(int h = 0; h < n; h++)
        {
            if(arr[k] == arr[h])
            {
                continue;
            }
            else if(arr[k] < arr[h])
            {
                temp = arr[k];
                arr[k] = arr[h];
                arr[h] = temp;
            }
            else
            {
                continue;
            }
        }
    }

    printf("\nGenerating sorted array...\n\n");
    for(int r = 0; r < n; r++)
    {
        printf("arr[%d] = %d\n", r, arr[r]);
    }

    printf("\nPlease enter the number you wish to insert in the above array: ");
    scanf("%d", &number);

    // find the suitable index position for the number
    for(int j = 0; j < n; j++)
    {
        if(number < arr[j])
        {
            pos = j;
            break;
        }
        else if(number >= arr[n - 1])
        {
            pos = n;
            break;
        }
        else
        {
            continue;
        }
    }

    //Insert number to its position
    if(pos < n)
    {
        for(int e = n; e >= pos; e--)
        {
            arr[e + 1] = arr[e];
        }
    }
    n++;
    arr[pos] = number;

    for(int t = 0; t < n; t++)
    {
        printf("arr[%d] = %d\n", t, arr[t]);
    }
    printf("\nNumber has been inserted in position: arr[%d]\n\n", pos);


}
