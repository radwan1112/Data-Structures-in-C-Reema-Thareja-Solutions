#include <stdio.h>
#include <time.h>

void merge_array(int arr[], int arr2[], int arr3[], int size)
{
    int i, j = 0;
    for(i = 0; i < size; i++)
    {
        arr3[i] = arr[i];
    }
    for(i = size; i < size * 2; i++)
    {
        arr3[i] = arr2[j];
        j++;
    }
    printf("   {");
    for(i = 0; i < size * 2; i++)
    {
        (i == size*2 - 1)? printf("%d}\n\n", arr3[i]):printf("%d, ", arr3[i]);
    }

}

void reverse_arr(int arr[], int len)
{
    int i, temp;
    int j = len - 1;
    for(i = 0; i < len; i++)
    {
        if(j > i)
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
        else
        {
            break;
        }
        j--;
    }
    printf("   {");

    for(i = 0; i < len; i++)
    {
        (i == len - 1)? printf("%d}\n\n", arr[i]):printf("%d, ", arr[i]);
    }

}

void fill_array(int arr[], int size)
{
    int i;
    printf("   {");
    for(i = 0; i < size; i++)
    {
        arr[i] = rand() % 10;
        (i == size - 1)? printf("%d}\n\n", arr[i]):printf("%d, ", arr[i]);
    }
}


int main()
{
    srand(time(NULL));
    int size = 10;
    float array[size];
    float array_2[size];
    float array_3[size * 2];

    int i, j;
    printf("Generating Array 1... \n\n");
    fill_array(array, size);
    printf("Generating Array 2... \n\n");
    fill_array(array_2, size);
    printf("Merging Array 1 with Array 2... \n\n");
    merge_array(array, array_2, array_3, size);
    printf("Reversing the resultant array... \n\n");
    reverse_arr(array_3, size*2);
}
