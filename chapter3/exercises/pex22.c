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

int main()
{

    srand(time(NULL));
    int i, j;
    int rows = (rand() % 10) + 1;
    int cols = (rand() % 10) + 1;
    int matrix[rows][cols];

    int answer;
    printf("\n--Choose how to fill the matrix--\n");
    printf("\n1. Automatically Generate Matrix\n");
    printf("2. Manually Enter Matrix Elements\n\n");
    printf("Enter: ");
    scanf(" %d", &answer);

    if(answer == 1)
    {
        auto_fill(matrix, rows, cols);
    }
    else
    {
        printf("Enter the matrix elements\n\n");
        fill_matrix(matrix, rows, cols);
    }
    print_mat(matrix, rows, cols);

    int (*ptr)[cols];
    ptr = matrix;
    printf("\nPrinting matrix using a pointer instead\n\n");

    for(i = 0; i < rows; i++)
    {
        printf("   ");
        for(j = 0; j < cols; j++)
        {
            printf("%3d ", *(*(ptr + i) + j));
        }
        printf("\n");
    }


    return 0;
}
