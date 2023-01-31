#include <stdio.h>

void fillArray(int *matrix, int rows, int cols)
{

    int i, j;

    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < cols; j++)
        {
            if(i == j)
            {
                matrix[i * cols + j] = 0;
            }
            else if(i < j)
            {
                matrix[i * cols + j] = -1;
            }
            else
            {
                matrix[i * cols + j] = 1;
            }
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

    printf("Generating a Square matrix...\n\n");
    int rows, cols;
    printf("Enter number of rows and columns: ");
    scanf(" %d", &rows);
    cols = rows;

    int matrix[rows][cols];
    fillArray(matrix, rows, cols);

    print_matrix(matrix, rows, cols);



    return 0;
}
