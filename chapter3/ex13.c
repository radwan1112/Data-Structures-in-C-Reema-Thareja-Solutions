#include <stdio.h>
#include <stdlib.h>


void sort_array(int *arr[], int n)
{

    int i, h, temp;

    //Sort the array
    for(i = 0; i < n; i++)
    {

        for(h = 0; h < n; h++)
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
}

void print_array(int arr[], int n)
{
    int i;

    for(i = 0; i < n; i++)
    {
        printf("arr[%d] = %d\n", i, arr[i]);
    }
}

void fill_array(int *arr[], int n)
{
    int i;
    int upper = 100, lower = 0;


    for(i = 0 ; i < n ; i++ )
    {
        arr[i] = (rand() % (upper - lower + 1)) + lower;
    }
}

void find_smallest(int arr[], int n)
{

    int i, smallest = arr[0];

    for(i = 0; i < n; i++)
    {
        if(arr[i] < smallest){
            smallest = arr[i];
        }
    }

    printf("\nThe smallest number of the array is: %d", smallest);

}

int main()
{
    int n, i;
    srand((unsigned)time(0));
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int arr[n];
    fill_array(&arr, n);

    printf("\nGenerating Array... \n\n");
    print_array(arr, n);

    find_smallest(arr, n);


    return 0;
}
