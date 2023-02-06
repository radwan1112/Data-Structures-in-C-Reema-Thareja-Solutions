#include <stdio.h>

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
        printf("\n   ");
        for(j = 0; j < cols; j++)
        {
            printf("%3d ", matrix[i * cols + j]);
        }
        printf("\n");
    }
}


int isSymmetric(int *arr, int size)
{
    int arrT[size][size];
    int i, j;
    int flag;

    for(i = 0; i < size; i++){
        for(j = 0; j < size; j++){
            arrT[i][j] = arr[j * size + i];
            if(arrT[i][j] == arr[i * size + j]){
                flag = 1;
            }
            else{
                flag = 0;
            }
        }
        if(flag == 0){
            break;
        }
    }
    return flag;

}

int main()
{

    printf("-- Symmetric matrix Detector --\n\n");
    int size;
    printf("\nEnter the size of the matrix rows x columns: ");
    scanf(" %d", &size);
    int matrix[size][size];
    printf("Enter matrix elements\n\n");
    fill_matrix(matrix, size, size);
    print_mat(matrix, size, size);

    if(isSymmetric(matrix, size)){
        printf("\n\nMatrix is Symmetric");
    }
    else{
        printf("\n\nMatrix is not Symmetric");
    }


    return 0;
}
