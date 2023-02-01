#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void fill_array(int arr[], int size)
{
    int i;
    printf("Generating Array... \n\n");
    printf("   {");
    for(i = 0; i < size; i++)
    {
        arr[i] = rand() % 10;
        (i == size-1)?printf("%d}\n\n", arr[i]):printf("%d, ", arr[i]);
    }
}

void interchange(int arr[], int size)
{
    int i, j, temp;
    int biggest = arr[0], smallest = arr[0], second_biggest = arr[0], second_smallest = arr[0];
    int big_index = 0, big2_index = 0, small_index = 0, small2_index = 0;
    printf("Interchanging the second biggest number with the second smallest number... \n\n");
    printf("   {");

    for(i = 1; i < size; i++)
    {
        if(arr[i] > biggest)
        {
            biggest = arr[i];
        }
        if(arr[i] < smallest)
        {
            smallest = arr[i];
        }
    }


    for(i = 0; i < size; i++)
    {
        if(arr[i] > smallest && arr[i] <= second_smallest)
        {
            second_smallest = arr[i];
            small2_index = i;
        }
        if(arr[i] < biggest && arr[i] >= second_biggest)
        {
            second_biggest = arr[i];
            big2_index = i;
        }
    }

    temp = arr[big2_index];
    arr[big2_index] = arr[small2_index];
    arr[small2_index] = temp;

    for(i = 0; i < size; i++)
    {
        (i == size-1)? printf("%d}\n\n", arr[i]):printf("%d, ", arr[i]);
    }
}


int main()
{
    srand(time(NULL));
    int lowest = 4;
    int highest = 8;
    int len = lowest + rand() % (highest - lowest + 1);
    int arr[len];
    fill_array(arr, len);
    interchange(arr, len);
}
