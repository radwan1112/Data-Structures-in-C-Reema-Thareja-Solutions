#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool validation(int arr[], int number, int n)
{


    for(int i = 0; i < n; i++)
    {
        if(arr[i] == number)
        {
            return true;
        }
    }

    return false;

}

int modify_array(int *arr[], int n, int number)
{


    for(int i = 0; i < n; i++)
    {
        if(arr[i] == number)
        {
            for(int k = i; k < n - 1; k++)
            {
                arr[k] = arr[k + 1];
            }
            n--;
            break;
        }
    }

    return n;


}


int main()
{

    int n, i;
    printf("Enter the number of elements in array: ");
    scanf("%d", &n);

    int upper = 100, lower = 0;
    int arr[n];
    srand(time(0));
    int temp, number, pos;
    bool isvalid;


    //fill the array with random numbers
    for(i = 0 ; i < n ; i++ )
    {
        arr[i] = (rand() % (upper - lower + 1)) + lower;
    }

    //Sort the array
    for(i = 0; i < n; i++)
    {

        for(int h = 0; h < n; h++)
        {
            if(arr[i] == arr[h])
            {
                continue;
            }
            else if(arr[i] < arr[h])
            {
                temp = arr[i];
                arr[i] = arr[h];
                arr[h] = temp;
            }
            else
            {
                continue;
            }
        }
    }

    printf("\nGenerating array...\n\n");
    for(i = 0; i < n; i++)
    {
        printf("arr[%d] = %d\n", i, arr[i]);
    }

    printf("Enter the number you wish to delete: ");
    scanf("%d", &number);
    isvalid = validation(arr, number, n);

    if(isvalid)
    {
        n = modify_array(&arr, n, number);
    }

    else
    {
        while(!isvalid)
        {
            printf("Enter a valid number: ");
            scanf(" %d", &number);
            isvalid = validation(arr, number, n);
        }
        n = modify_array(&arr, n, number);
    }



    printf("\nDeleting number from array...\n\n");
    for(i = 0; i < n; i++)
    {
        printf("arr[%d] = %d\n", i, arr[i]);
    }


    return 0;
}
