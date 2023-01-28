#include <stdio.h>
#include <stdlib.h>

void auto_fill_array(int arr[][3], int r, int k)
{
    int i, j;
    int upper = 9, lower = 0;

    for(i = 0 ; i < r ; i++ )
    {
        for(j = 0; j < k; j++)
        {
            arr[i][j] = (rand() % (upper - lower + 1)) + lower;
        }
    }
}

void fill_array(int arr[][3], int r, int k)
{
    int i, j = 0;
    int upper = 9, lower = 0;
    int num;

    printf("Enter a number between %d and %d \n", lower, upper);

    for(i = 0 ; i < r ; i++ )
    {
        j = 0;
        while(j < k)
        {
            printf("arr[%d][%d] = ", i, j);
            scanf(" %d", &num);
            if(num >= lower && num <= upper)
            {
                arr[i][j] = num;
                j++;
            }
            else
            {
                printf("Invalid number!\n");
                printf("Enter a number between %d and %d \n", lower, upper);
            }
        }
    }
}

void transpose_matrix(int arr[][3], int r, int k)
{
    int temp;

    for(int i = 0; i < k; i++)
    {
        for(int j = i + 1; j < r; j++)
        {
            temp =  arr[i][j];
            arr[i][j] = arr[j][i];
            arr[j][i] = temp;
        }
    }
}

void print_2D_arr(int arr[][3], int r, int k)
{

    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < k; j++)
        {
            printf("| %d ", arr[i][j]);
        }
        printf("|\n");
    }

}

int main()
{

    int rows = 3, cols = 3;
    char answer;
    srand((unsigned)time(0));

    printf("Matrix dimensions are as follow: %d * %d\n\n", rows, cols);

    int matrix[rows][cols];

    printf("do you wish to fill the matrix automatically: ");
    scanf(" %c", &answer);

    if(answer == 'y' || answer == 'Y')
    {
        auto_fill_array(matrix, rows, cols);
    }
    else
    {
        fill_array(matrix, rows, cols);
    }

    printf("Original matrix... \n");
    print_2D_arr(matrix, rows, cols);

    printf("Transposed matrix... \n");

    transpose_matrix(matrix, rows, cols);
    print_2D_arr(matrix, rows, cols);


    return 0;
}
