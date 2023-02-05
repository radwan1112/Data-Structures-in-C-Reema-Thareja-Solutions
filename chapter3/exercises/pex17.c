#include <stdio.h>

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

int sum_below_diagonal(int *matrix, int rows, int cols)
{
    int i, j;
    int sum = 0;

    printf("\n   ");
    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < cols; j++)
        {
            if(i > j)
            {
                if(j == cols - 1 && i == rows - 2)
                {
                    printf("%d = ", matrix[i * cols + j]);
                }
                else
                {
                    printf("%d + ", matrix[i * cols + j]);
                }
                sum += matrix[i * cols + j];
            }
        }
    }
    printf(" %d\n", sum);
    return sum;
}


int main()
{

    printf("-- Sum of Elements below the main diagonal of a matrix  --\n\n");
    int size;
    printf("Enter the size of the matrix: ");
    scanf(" %d", &size);
    int matrix[size][size];

    int answer;
    printf("\n--Choose how to fill the matrix--\n");
    printf("\n1. Automatically Generate Matrix\n");
    printf("2. Manually Enter Matrix Elements\n\n");
    printf("Enter: \n");
    scanf(" %d", &answer);

    if(answer == 1)
    {
        auto_fill(matrix, size, size);
    }
    else
    {
        printf("Enter First matrix elements\n\n");
        fill_matrix(matrix, size, size);
    }
    print_mat(matrix, size, size);

    int sum = sum_below_diagonal(matrix, size, size);



    return 0;
}
