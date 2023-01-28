#include <stdio.h>

void fillArray(int *matrix, int rows, int cols)
{

    int i, j;

    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < cols; j++)
        {
            printf("arr[%d][%d] = ", i, j);
            scanf(" %d", &matrix[i * cols + j]);
        }
    }
}

void print_matrix(int *matrix, int rows, int cols)
{

    int i, j;

    for(i = 0; i < rows; i++)
    {
        printf("| ");
        for(j = 0; j < cols; j++)
        {
            printf(" %3d ", matrix[i * cols + j]);
        }
        printf(" |\n");
    }


}

int main()
{

    int rows, cols;
    printf("Enter the number of rows: ");
    scanf(" %d", &rows);
    printf("Enter the number of cols: ");
    scanf(" %d", &cols);
    int matrix[rows][cols];
    int matrix_2[rows][cols];
    int matrix_3[rows][cols];

    printf("Fill the Matrix no. 1: \n");
    fillArray(matrix, rows, cols);
    printf("Fill the Matrix no. 2: \n");
    fillArray(matrix_2, rows, cols);


    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            matrix_3[i][j] = matrix[i][j] + matrix_2[i][j];
        }
    }

    printf("Results\n");
    print_matrix(matrix, rows, cols);
    printf("  +   \n");
    print_matrix(matrix_2, rows, cols);
    printf("  =   \n");
    print_matrix(matrix_3, rows, cols);



    return 0;
}
