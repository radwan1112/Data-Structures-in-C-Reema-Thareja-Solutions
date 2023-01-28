#include <stdio.h>

int main()
{

    int m[3][3];
    int i, j;

    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 3; j++)
        {
            printf("Enter value of m[%d][%d]: ", i, j);
            scanf(" %d", &m[i][j]);
        }
    }

    //Printing the Matrix
    printf("Generating the matrix... \n");
    for(i = 0; i < 3; i++)
    {
        printf("|");
        for(j = 0; j < 3; j++)
        {
            printf(" %d", m[i][j]);
        }
        printf(" |\n");

    }


    return 0;
}
