#include <stdio.h>
#include <time.h>

int main()
{

    srand(time(NULL));
    int i, j;
    int rows, cols;
    printf("Enter the number of rows: ");
    scanf(" %d", &rows);
    printf("Enter the number of columns: ");
    scanf(" %d", &cols);
    int arr[rows][cols];
    int odd_arr[rows * cols];
    int even_arr[rows * cols];
    int even = 0;
    int odd = 0;
    printf("Generating array... \n\n");

    printf("   {");
    //fill the array
    for(i = 0; i < rows; i++)
    {
        printf("\n     {");
        for(j = 0; j < cols; j++)
        {
            arr[i][j] = rand() % 1000;
            if(arr[i][j] % 2 == 0)
            {
                even_arr[even] = arr[i][j];
                even++;
            }
            else
            {
                odd_arr[odd] = arr[i][j];
                odd++;
            }
            if(j == cols - 1)
            {
                printf("%3d},\n", arr[i][j]);
            }
            else
            {
                printf("%3d, ", arr[i][j]);
            }
        }
    }
    printf("   }\n");

    printf("\nArray of even numbers: \n\n");
    printf("   {");
    if(even == 0)
    {
        printf("Empty }");
    }
    for(i = 0; i < even; i++)
    {
        if(i == even - 1)
        {
            printf("%3d}\n", even_arr[i]);
        }
        else
        {
            printf("%3d, ", even_arr[i]);
        }
    }

    printf("\nArray of odd numbers: \n\n");
    printf("   {");
    if(odd == 0)
    {
        printf("Empty }");
    }
    for(i = 0; i < odd; i++)
    {
        if(i == odd - 1)
        {
            printf("%3d}\n", odd_arr[i]);
        }
        else
        {
            printf("%3d, ", odd_arr[i]);
        }
    }

}

