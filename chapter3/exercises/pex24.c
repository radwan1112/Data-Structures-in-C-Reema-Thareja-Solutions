#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

void auto_fill(int arr[], int len)
{

    int i;
    for(i = 0; i < len; i++)
    {
        arr[i] = rand() % 10;
    }
}

void fill_array(int arr[], int len)
{

    int i;
    for(i = 0; i < len; i++)
    {
        printf("Array[%d]: ", i);
        scanf(" %d", &arr[i]);
    }
}

void print_array(int arr[], int len)
{
    int i;

    printf("   {");
    for(i = 0; i < len; i++)
    {
        if(i == len - 1)
        {
            printf("%d}\n", arr[i]);
        }
        else
        {
            printf("%d, ", arr[i]);
        }
    }
}

int del_dup(int arr[], int len)
{
    int i, j;
    int k;

    for(i = 0; i < len; i++)
    {
        for(j = 0; j < len; j++)
        {
            if(i != j && arr[i] == arr[j])
            {
                for(k = j; k <= len - 1 ; k++)
                {
                    arr[k] = arr[k+1];
                }
                len--;
                i--;
                j--;
            }
        }
    }
    return len;
}

int main()
{

    srand(time(NULL));
    int len;
    printf("Enter the length of the array: ");
    scanf(" %d", &len);
    int arr[len];

    int answer;
    printf("\n--Choose how to fill the matrix--\n");
    printf("\n1. Automatically Generate Matrix\n");
    printf("2. Manually Enter Matrix Elements\n\n");
    printf("Enter: ");
    scanf(" %d", &answer);

    if(answer == 1)
    {
        auto_fill(arr, len);
    }
    else
    {
        fill_array(arr, len);
    }
    printf("\nPrinting array... \n\n");
    print_array(arr, len);

    printf("\nRemoving repeated elements from the array... \n\n");
    int new_len = del_dup(arr, len);
    print_array(arr, new_len);


    return 0;
}
