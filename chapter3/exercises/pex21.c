#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void auto_fill(int *matrix, int r, int k)
{

    int i, j;
    for(i = 0; i < r; i++)
    {
        for(j = 0; j < k; j++)
        {
            matrix[i * k + j] = rand() % 25;
        }
    }
}

void fill_matrix(int *matrix, int r, int k)
{

    int i, j;
    for(i = 0; i < r; i++)
    {
        for(j = 0; j < k; j++)
        {
            printf("Matrix[%d][%d]: ", i, j);
            scanf(" %d", &matrix[i * k + j]);
        }
    }
}

void print_mat(int *matrix, int rows, int cols)
{
    int i, j;
    for(i = 0; i < rows; i++)
    {
        printf("   ");
        for(j = 0; j < cols; j++)
        {
            printf("%3d ", matrix[i * cols + j]);
        }
        printf("\n");
    }
}

void scaler_multi(int *arr, int rows, int cols, int num)
{

    int i, j;

    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < cols; j++)
        {
            arr[i * cols + j] = num * arr[i * cols + j];
        }
    }
}

void addition_pro(int x, int y)
{
    int rows, cols;
    int i, j;
    printf("\n--Matrix Dimensions--\n\n");
    printf("Enter the number of rows: ");
    scanf(" %d", &rows);
    printf("Enter the number of columns: ");
    scanf(" %d", &cols);
    int matrix_1[rows][cols];
    int matrix_2[rows][cols];
    int matrix_r[rows][cols];
    int answer;
    printf("\n--Choose how to fill the matrix--\n");
    printf("\n1. Automatically Generate Matrix\n");
    printf("2. Manually Enter Matrix Elements\n\n");
    printf("Enter: ");
    scanf(" %d", &answer);

    if(answer == 1)
    {
        auto_fill(matrix_1, rows, cols);
        auto_fill(matrix_2, rows, cols);
    }
    else
    {
        printf("Enter First matrix elements\n\n");
        fill_matrix(matrix_1, rows, cols);
        printf("Enter Second matrix elements\n\n");
        fill_matrix(matrix_2, rows, cols);
    }

    printf("\n  X(Matrix 1) + Y(Matrix 2) = \n\n");
    printf("  %d", x);
    printf("   x\n\n");
    print_mat(matrix_1, rows, cols);
    printf("\n   +\n\n");
    printf("  %d", y);
    printf("   x\n\n");
    print_mat(matrix_2, rows, cols);
    printf("\n   =\n\n");

    scaler_multi(matrix_1, rows, cols, x);
    scaler_multi(matrix_2, rows, cols, y);


    printf("\nMatrix 1 + Matrix 2 = \n\n");
    print_mat(matrix_1, rows, cols);
    printf("\n   +\n\n");
    print_mat(matrix_2, rows, cols);
    printf("\n   =\n\n");

    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < cols; j++)
        {
            matrix_r[i][j] = matrix_1[i][j] + matrix_2[i][j];
        }
    }

    print_mat(matrix_r, rows, cols);

}

int main()
{

    srand(time(NULL));
    int x = 2, y = 3;
    addition_pro(x, y);

    return 0;
}
