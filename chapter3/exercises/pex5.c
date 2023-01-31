#include <stdio.h>

int main()
{
    int i, j;
    int sum = 0;
    int mean = 0;
    int arr[3][3] = {{1, 1, 3}, {3, 4, 2}, {1, 3, 2}};

    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 3; j++)
        {
            printf("arr[%d][%d] = %d\n", i, j, arr[i][j]);
            sum += arr[i][j];
        }
    }

    mean = sum / 9;
    printf("Sum total is equal %d\n", sum);
    printf("Average mean is equal %d\n", mean);

    return 0;
}
