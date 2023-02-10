#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

void auto_fill(float arr[], int len)
{

    int i;
    for(i = 0; i < len; i++)
    {
        arr[i] = (float)rand() / RAND_MAX * 100;
    }
}

void fill_array(float arr[], int len)
{
    int i;
    for(i = 0; i < len; i++)
    {
        printf("Array[%d]: ", i);
        scanf(" %f", &arr[i]);
    }
}

void print_array(float arr[], int len)
{
    int i;

    printf("   {");
    for(i = 0; i < len; i++)
    {
        if(i == len - 1)
        {
            printf("%2.5f}\n", arr[i]);
        }
        else
        {
            printf("%2.5f, ", arr[i]);
        }
    }
}

float *insert_element(float *arr, int len)
{
    int pos;
    float new_element;
    int new_len = len + 1;

    printf("Enter the new element you wish to insert: ");
    scanf(" %f", &new_element);

    printf("Choose an index between (0 ~ %d): ", new_len - 1);
    int ret = scanf(" %d", &pos);
    while(ret == 0 || pos < 0 || pos > new_len - 1)
    {
        printf("Choose an index between (0 ~ %d): ", new_len - 1);
        scanf(" %d", &pos);
    }

    arr = realloc(arr, new_len * sizeof(float));

    int i, j;

    //shift the array elements
    for(i = len; i >= pos; i--)
    {
        if(i == pos)
        {
            arr[i] = new_element;
        }
        else
        {
            arr[i] = arr[i - 1];
        }
    }

}

int main()
{

    srand(time(NULL));
    printf("Enter the Length of the array: ");
    int len;
    scanf(" %d", &len);
    float *arr = (float*)malloc(len * sizeof(float));

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

    int pos;
    int number;
    char reply;
    do
    {
        printf("Do you want to insert a new Element? Type 'Y' or 'N' ");
        scanf(" %c", &reply);
        if(reply == 'y' || reply == 'Y')
        {
            insert_element(arr, len);
            len++;
            print_array(arr, len);
        }
        else
        {
            printf("\nHere is your final array Have a good day\n");
            print_array(arr, len);
        }
    }
    while(reply == 'y' || reply == 'Y');
    free(arr);


    return 0;
}
