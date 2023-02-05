#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
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

void transpose_pro()
{
    int rows, cols;
    int i, j;
    printf("\n--Matrix Dimensions--\n\n");
    printf("Enter Matrix number of rows: ");
    scanf(" %d", &rows);
    printf("Enter Matrix number of columns: ");
    scanf(" %d", &cols);
    int matrix[rows][cols];
    int matrix_r[cols][rows];
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
        printf("Enter First matrix elements\n\n");
        fill_matrix(matrix, rows, cols);
    }


    printf("\nTranspose of Matrix = \n\n");
    print_mat(matrix, rows, cols);
    printf("\n   =\n\n");

    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < cols; j++)
        {
            matrix_r[j][i] = matrix[i][j];
        }
    }

    print_mat(matrix_r, cols, rows);


}

void product_pro()
{

    int rows, cols;
    int cols2;
    int i, j, k;
    printf("\n--Matrix Dimensions--\n\n");
    printf("\nFirst Matrix number of rows: ");
    scanf(" %d", &rows);
    printf("First Matrix number of columns: ");
    scanf(" %d", &cols);
    printf("\nSecond Matrix number of columns: ");
    scanf(" %d", &cols2);
    int rows2 = cols;
    int rows3 = rows, cols3 = cols2;
    int matrix_1[rows][cols];
    int matrix_2[rows2][cols2];
    int matrix_r[rows3][cols3];

    int answer;
    printf("\n--Choose how to fill the matrix--\n");
    printf("\n1. Automatically Generate Matrix\n");
    printf("2. Manually Enter Matrix Elements\n\n");
    printf("Enter: ");
    scanf(" %d", &answer);

    if(answer == 1)
    {
        auto_fill(matrix_1, rows, cols);
        auto_fill(matrix_2, rows2, cols2);
    }
    else
    {
        printf("Enter First matrix elements\n\n");
        fill_matrix(matrix_1, rows, cols);
        printf("Enter Second matrix elements\n\n");
        fill_matrix(matrix_2, rows2, cols2);
    }

    printf("\nMatrix 1 x Matrix 2 = \n\n");
    print_mat(matrix_1, rows, cols);
    printf("\n   x\n\n");
    print_mat(matrix_2, rows2, cols2);
    printf("\n   =\n\n");

    for(i = 0; i < rows3; i++)
    {
        for(j = 0; j < cols3; j++)
        {
            matrix_r[i][j] = 0;
            for(k = 0; k < cols; k++)
            {
                matrix_r[i][j] += matrix_1[i][k] * matrix_2[k][j];
            }
        }
    }

    print_mat(matrix_r, rows3, cols3);

}

void addition_pro()
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

bool repeat()
{
    char answer;
    printf("\nDo you wish to continue? Enter 'Y' to continue and 'N' to exit the program: ");
    scanf(" %c", &answer);
    if(answer == 'y' || answer == 'Y')
    {
        return true;
    }
    else
    {
        printf("\n   Have a Nice Day! \n");
        return false;
    }
}

int validate(int isread, int operation)
{
    if(isread != 0 && operation >= 1 && operation <=3)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int choose_operation()
{
    int operation;
    int valid = 0;
    int isread = 0;

    printf("\n--Choose the matrix operation you wish to preform--\n\n");
    while(!valid)
    {
        printf("1. Sum\n2. Product\n3. Transpose\n\n");
        printf("Enter the operation number: ");
        isread = scanf("%d", &operation);
        valid = validate(isread, operation);

        if(valid)
        {
            return operation;
        }
        else
        {
            printf("\n\nError: Invalid Input, try again\n\n");
            fflush(stdin);
        }
    }

}

int main()
{
    srand(time(NULL));
    int operation;
    printf("\n--- Matrix Calculator ---\n\n");

    do
    {
        operation = choose_operation();
        if(operation == 1)
        {
            addition_pro();
        }
        else if(operation == 2)
        {
            product_pro();
        }
        else
        {
            transpose_pro();
        }
    }
    while(repeat());


    return 0;
}
