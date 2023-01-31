#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void sum_num(int *matrix, int rows, int cols)
{
    int i, j;
    int sum = 0;

    printf("\nThe sum of elements on the diagonal of the matrix is: \n");
    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < cols; j++)
        {
            if(i == j)
            {
                sum += matrix[i * cols + j];
                if(i == rows - 1)
                {
                    printf("%d = ", matrix[i * cols + j]);
                }
                else
                {
                    printf("%d + ", matrix[i * cols + j]);
                }
            }
        }
    }
    printf("%d\n", sum);
}

void fill_array(int *matrix, int rows, int cols)
{

    int i, j;

    printf("\n\n  ");
    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < cols; j++)
        {
            matrix[i * cols + j] = rand() % 11;
            printf("%2d ", matrix[i * cols + j]);
        }
        printf("\n  ");
    }
}

int main()
{

    int rows, cols;
    srand(time(NULL));
    printf("Enter number of rows and columns: ");
    scanf(" %d", &rows);
    cols = rows;
    int matrix[rows][cols];

    fill_array(matrix, rows, cols);
    sum_num(matrix, rows, cols);


    return 0;
}
