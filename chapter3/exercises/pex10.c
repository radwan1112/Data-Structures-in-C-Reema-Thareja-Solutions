#include <stdio.h>
#include <time.h>
#include <stdlib.h>


int main()
{

    srand(time(NULL));
    int rows, cols;
    printf("Enter the number of rows: ");
    scanf(" %d", &rows);
    printf("Enter the number of columns: ");
    scanf(" %d", &cols);
    int matrix[rows][cols];
    int zero = 0;
    int non_zero = 0;

    //Fill the array with random numbers
    int i, j;
    printf("Generating Matrix... \n\n");
    for(i = 0; i < rows; i++)
    {
        printf("   ");
        for(j = 0; j < cols; j++)
        {
            matrix[rows][cols] = rand() % 10;
            printf("%d  ", matrix[rows][cols]);
            if(matrix[rows][cols] == 0)
            {
                zero++;
            }
            else
            {
                non_zero++;
            }
        }
        printf("\n");
    }

    printf("\n\n");
    printf("The number of zero elements is:  %d\n", zero);
    printf("The number of non-zero elements is:  %d\n", non_zero);





}
