#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int concat(int full, int digit)
{

    char s_full[20];
    char s_digit[20];

    sprintf(s_full, "%d", full);
    sprintf(s_digit, "%d", digit);

    strcat(s_full, s_digit);

    int n = atoi(s_full);

    return n;

}

int main()
{

    int n;

    printf("Enter number of digits: ");
    scanf("%d", &n);

    int arr[n];
    int full_n;

    // Fill the array
    for(int i = 0; i < n; i++)
    {
        printf("Enter number at pos[%d]: ", i+1);
        scanf("%d", &arr[(n-1) - i]);
    }

    for(int k = 0; k < n; k++)
    {
        if(k == 0)
        {
            full_n = arr[k];

        }
        else
        {
            full_n = concat(full_n, arr[k]);
        }
    }

    printf("Full number is: %d", full_n);



    return 0;
}
