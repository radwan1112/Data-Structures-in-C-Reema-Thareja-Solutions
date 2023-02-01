#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{

    srand(time(NULL));
    int i, j;
    int size;
    printf("Enter the number of rows and columns of the square matrix: ");
    scanf(" %d", &size);
    int square_matrix[size][size];
    int product = 1;
    int elements[size-1];
    int k = 0;
    printf("\nGenerating matrix... \n\n");

    //fill array with random numbers
    for(i = 0; i < size; i++)
    {
        printf("    ");
        for(j = 0; j < size; j++)
        {
            square_matrix[i][j] = rand() % 10;
            printf("%d  ", square_matrix[i][j]);
            if(i + 1 == j)
            {
                product *= square_matrix[i][j];
                elements[k] = square_matrix[i][j];
                k++;
            }
        }
        printf("\n");
    }

    printf("\nProduct of elements that are stored on the diagonal above the main diagonal: \n\n");
    printf("    ");
    for(i = 0; i < k; i++)
    {
        if(i == k - 1)
        {
            printf("%d = %d", elements[i], product);

        }
        else
        {
            printf("%d x ", elements[i]);
        }
    }
    printf("\n");

    return 0;
}
