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

void merge_sorted_arr(int *arr3[], int arr1[], int arr2[], int n3, int n1, int n2)
{

    int i;
    int j = 0, h = 0;;


    for(i = 0; i < n3; i++)
    {
        if(arr1[j] <= arr2[h] && j < n1)
        {
            arr3[i] = arr1[j];
            j++;
        }
        else if(arr1[j] > arr2[h] && h < n2)
        {
            arr3[i] = arr2[h];
            h++;
        }
        else
        {
            continue;
        }

    }
}

int main()
{

    int n1, n2, i;
    printf("Enter the number of elements in the first array: ");
    scanf("%d", &n1);
    printf("Enter the number of elements in the second array: ");
    scanf("%d", &n2);
    srand((unsigned)time(0));

    int n3 = n1 + n2;
    int arr1[n1];
    int arr2[n2];
    int arr3[n3];

    fill_array(&arr1, n1);
    fill_array(&arr2, n2);

    printf("\nGenerating first array... \n");
    print_array(arr1, n1);

    printf("\nGenerating second array... \n");
    print_array(arr2, n2);


    sort_array(&arr1, n1);
    sort_array(&arr2, n2);

    printf("\nGenerating first sorted array... \n");
    print_array(arr1, n1);
    printf("\nGenerating second sorted array... \n");
    print_array(arr2, n2);

    merge_sorted_arr(&arr3, arr1, arr2, n3, n1, n2);

    printf("\nGenerating merged sorted array... \n");
    print_array(arr3, n3);

    return 0;
}
