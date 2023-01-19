#include <stdio.h>

int find_largest_num(int arr[], int n)
{

    int largest_n = arr[0];
    int l = 0;
    while(l < n)
    {
        if(arr[l] > largest_n)
        {
            largest_n = arr[l];
        }
        l++;
    }
    return largest_n;
}

int main()
{

    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    // Fill the array
    for(int i = 0; i < n; i++)
    {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }

    int largest_num = find_largest_num(arr, n);
    int sec_larg_num = 0;

    int l = 0;
    while(l < n)
    {
        if(arr[l] < largest_num)
        {
            if(l == 0 || arr[l] > sec_larg_num)
            {
                sec_larg_num = arr[l];
            }
        }
        l++;
    }

    printf("\nThe Largest Number of the array is: %d", largest_num);
    printf("\nThe Second Largest number of the array is: %d", sec_larg_num);


    return 0;
}
