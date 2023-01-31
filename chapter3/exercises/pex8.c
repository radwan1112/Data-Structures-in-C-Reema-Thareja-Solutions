#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define size 3

void fill_array(int *matrix)
{
    int i, j;
    printf("Generating A 3*3 Matrix: \n\n");
    printf("  ");
    for(i = 0; i < size; i++)
    {
        for(j = 0; j < size; j++)
        {
            matrix[i * size + j] = rand() % 11;
            printf("%2d ", matrix[i * size + j]);
        }
        printf("\n  ");
    }
    printf("\n");
}

void add(int *matrix, int *matrix_2)
{

    int i, j;
    int result[size][size] = {0,0,0,0,0,0,0,0,0};

    for(i = 0; i < size; i++)
    {
        for(j = 0; j < size; j++)
        {
            result[i][j] = matrix[i * size + j] + matrix_2[i * size + j];
        }
    }

    printf("\n\n  ");

    for(i = 0; i < size; i++)
    {
        for(j = 0; j < size; j++)
        {
            printf("%2d ", matrix[i * size + j]);
        }
        if(i == 1)
        {
            printf("   +   ");
        }
        else
        {
            printf("       ");

        }
        for(j = 0; j < size; j++)
        {
            printf("%2d ", matrix_2[i * size + j]);
        }
        if(i == 1)
        {
            printf("   =   ");
        }
        else
        {
            printf("       ");

        }
        for(j = 0; j < size; j++)
        {
            printf("%2d ", result[i][j]);
        }
        printf("\n  ");
    }
}


int main()
{

    srand(time(NULL));

    int matrix[size][size];
    int matrix_2[size][size];

    fill_array(matrix);
    fill_array(matrix_2);
    add(matrix, matrix_2);

    return 0;
}
