#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

bool validate(int arr[], int size, int num)
{

    int i;
    bool valid = true;

    for(i = 0; i < size; i++)
    {
        if(arr[i] == num)
        {
            valid = false;
            break;
        }
    }

    return valid;
}

void fill_array(int arr[], int size)
{
    int i, number;
    printf("Generating Array... \n\n");
    printf("   {");
    for(i = 0; i < size; i++)
    {
        number = rand() % 10;
        if(validate(arr, size, number))
        {
            arr[i] = number;
            (i == size-1)?printf("%d}\n\n", arr[i]):printf("%d, ", arr[i]);
        }
        else
        {
            i--;
            continue;
        }
    }
}

void interchange(int arr[], int size)
{
    int i, temp;
    int biggest = INT_MIN, smallest = INT_MAX;
    int second_biggest = INT_MIN, second_smallest = INT_MAX;
    printf("Interchanging the second biggest number with the second smallest number... \n\n");
    printf("   {");

    for(i = 0; i < size; i++)
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

    int big2_index, small2_index;

    for(i = 0; i < size; i++)
    {
        if(arr[i] < biggest && arr[i] > second_biggest)
        {
            second_biggest = arr[i];
            big2_index = i;
        }
        if(arr[i] > smallest && arr[i] < second_smallest)
        {
            second_smallest = arr[i];
            small2_index = i;
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
    int *ptr = arr;
    fill_array(ptr, len);
    interchange(ptr, len);
}
