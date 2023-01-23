#include <stdio.h>
#include <stdlib.h>

void fill_array(int *arr[], int n)
{
    int i;
    int upper = 100, lower = 0;


    for(i = 0 ; i < n ; i++ )
    {
        arr[i] = (rand() % (upper - lower + 1)) + lower;
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

void swap(int *arr[], int n)
{

    int i, smallest = arr[0];
    int largest = arr[0];
    int pos_small, pos_large, temp;

    for(i = 0; i < n; i++)
    {
        if(arr[i] <= smallest)
        {
            smallest = arr[i];
            pos_small = i;
        }
        if(arr[i] >= largest)
        {
            largest = arr[i];
            pos_large = i;
        }
    }

    printf("Largest number %d has been swapped with smallest number %d", largest, smallest);

    temp = arr[pos_large];
    arr[pos_large] = arr[pos_small];
    arr[pos_small] = temp;

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

    swap(&arr, n);
    printf("\nGenerating Array after swapping ... \n\n");
    print_array(arr, n);

    return 0;
}
