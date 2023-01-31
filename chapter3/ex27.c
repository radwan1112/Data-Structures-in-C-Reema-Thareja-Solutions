#include <stdio.h>

void fill_array(int (*arr)[2][2], int rows, int rows2, int cols)
{

    int i, j, k;

    for(i = 0; i < rows; i++)
    {

        for(j = 0; j < rows2; j++)
        {
            for(k = 0; k < cols; k++)
            {
                printf("arr[%d][%d][%d] = ", i, j, k);
                scanf(" %d", &*(*(*(arr + i) + j)) + k);
            }

        }
    }
}

void display_array(int (*arr)[2][2], int rows, int rows2, int cols)
{

    int i, j, k;

    printf("{\n");
    for(i = 0; i < rows; i++)
    {
        printf("  {\n");
        for(j = 0; j < cols; j++)
        {
            printf("    {");
            for(k = 0; k < cols; k++)
            {
                if(k == cols - 1)
                {
                    printf("%d},\n", *(*(*(arr + i) + j)) + k);

                }
                else
                {
                    printf("%d, ", *(*(*(arr + i) + j)) + k);

                }
            }
        }
        printf("  },\n");
    }
    printf("}");



}

int main()
{

    printf("Printing 2 x 2 x 2 Matrices\n");
    int matrix[2][2][2];
    int rows = 2;
    int rows2 = rows;
    int cols = rows;
    printf("Enter the Elements of the array: \n\n");
    fill_array(matrix, rows, rows2, cols);
    display_array(matrix, rows, rows2, cols);



    return 0;
}
