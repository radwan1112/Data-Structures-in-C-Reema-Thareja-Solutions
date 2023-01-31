#include <stdio.h>

void fill_array(int (*arr)[3], int rows, int cols)
{

    int i, j;

    for(i = 0; i < rows; i++)
    {

        for(j = 0; j < cols; j++)
        {
            printf("arr[%d][%d] = ", i, j);
            scanf(" %d", &*(*(arr + i) + j));
        }
    }
}


void display_array(int (*arr)[3], int rows, int cols)
{

    int i, j;

    for(i = 0; i < rows; i++)
    {
        printf("| ");
        for(j = 0; j < cols; j++)
        {
            printf(" %3d ", *(*(arr + i) + j));
        }
        printf(" |\n");
    }



}

int main()
{

    printf("Printing 3 x 3 Matrices\n");
    int matrix[3][3];
    int rows = 3;
    int cols = rows;
    printf("Enter the Elements of the array: \n\n");
    fill_array(matrix, rows, cols);
    display_array(matrix, rows, cols);



    return 0;
}
