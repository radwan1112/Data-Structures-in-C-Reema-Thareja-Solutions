#include <stdio.h>


void read(int *arr, int size)
{

    int i, j;
    for(i = 0; i < size; i++)
    {
        for(j = 0; j < size; j++)
        {
            printf("arr[%d][%d] = ", i, j);
        }
    }
}

void display(int *arr, int size)
{
    int i, j;
    for(i = 0; i < size; i++)
    {
        for(j = 0; j < size; j++)
        {
            printf("%d ", arr[i * size + j]);
        }
        printf("\n");
    }
}

int main()
{
    int size;
    printf("Enter the size of the square: ");
    scanf("%d", &size);
    int square[size][size];

    read(square, size);
    display(square, size);

    return 0;
}
