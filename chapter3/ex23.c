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

    int rows, cols, rows_2, cols_2, rows_3, cols_3;
    printf("Enter the dimension of the first matrix: \n");
    printf("Number of rows: ");
    scanf(" %d", &rows);
    printf("Number of columns: ");
    scanf(" %d", &cols);
    rows_2 = cols;
    printf("Enter the dimensions of the second matrix: \n");
    printf("Number of rows = %d\n", rows_2);
    printf("Enter number of columns: ");
    scanf(" %d", &cols_2);
    rows_3 = rows;
    cols_3 = cols_2;

    int matrix[rows][cols];
    int matrix_2[rows_2][cols_2];
    int matrix_3[rows_3][cols_3];

    printf("\n\n");
    printf("Enter the elements of the first array: \n");
    fillArray(matrix, rows, cols);
    printf("Enter the elements of the second array: \n");
    fillArray(matrix_2, rows_2, cols_2);
    printf("\n\n");
    print_matrix(matrix, rows, cols);
    printf("   *   \n\n");
    print_matrix(matrix_2, rows_2, cols_2);
    printf("   =   \n\n");


    int i, j, k, total;

    for(i = 0; i < rows_3; i++)
    {
        for(j = 0; j < cols_3; j++)
        {
            total = 0;
            for(k = 0; k < cols; k++)
            {
                total += matrix[i][k] * matrix_2[k][j];
            }
            matrix_3[i][j] = total;
        }
    }


    print_matrix(matrix_3, rows_3, cols_3);


    return 0;
}
